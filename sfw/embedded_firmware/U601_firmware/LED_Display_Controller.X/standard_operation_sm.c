/* ************************************************************************** */
/* State Machine for panel in normal operation */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "panel_control.h"
#include "standard_operation_sm.h"
#include "spi_flash.h"
#include "terminal_control.h"
#include "panel_control.h"
#include "device_control.h"
#include "32mz_interrupt_control.h"
#include "usb_uart.h"

// Initialize state machine 
void standardOpSMInit(void) {
    
    //if(readFrameNumber() >= 2 && readFrameNumber() <= 8) {
        
        fillRamBufferSplashScreen();
        panelMultiplexingTimerStart();
    
        // set various start up flags and variables
        flash_chip = 1;
        autopilot = 1;
        continue_autopilot = 1;
        SM_Timer_Done = 1;
        image_num = readFrameNVM();
        state = sm_first_load;
        
    //}
    
}

// Function to move to next flash chip
void nextFlashData(void){
    
    // if statement to check if next chip to contain data
    if (flash_chip > image_num) {
        
        flash_chip = 1;
    }
    
    // clear flash read flag before we begin a new read
    SPI_Read_Finished_Flag = 0;
    
    // bring flash chip data to ebi
    SPI_FLASH_beginRead(flash_chip);
        
}

// Function to exit state machine
void exitSM(void) {
    
    // set various ending flags and variables
    autopilot = 0; 
    T6CONbits.ON = 0;
    flash_chip = 1;
    
    disableInterrupt(SPI3_Transfer_Done);
    disableInterrupt(SPI3_Receive_Done);
    
    spi_flash_state = idle;
    spiFlashGPIOReset();
}
 
void __ISR(_TIMER_7_VECTOR, ipl1SRS) stateMachineTimerISR(void) {
    
    // Turn off Timer 6
    T6CONbits.ON = 0;
    
    // Tell main we are done with our countdown timer
    SM_Timer_Done = 1;
    
    // Clear interrupt flag
    clearInterruptFlag(Timer7);
    disableInterrupt(Timer7);
    
}
    

// This function initializes the Delay Timer (Timer 4)
void stateMachineTimerInit(void) {
    
    // Disable Timer6 interrupt
    disableInterrupt(Timer7);
    setInterruptPriority(Timer7, 1);
    setInterruptSubpriority(Timer7, 1);
    clearInterruptFlag(Timer7);
    
    // Stop timer 6
    T6CONbits.ON = 0;
    // T7CONbits.ON = 0;
    
    // Stop timer 6 in idle
    T6CONbits.SIDL = 1;
    // T7CONbits.SIDL = 1;
    
    // Disable gated time accumulation
    T6CONbits.TGATE = 0;
    // T7CONbits.TGATE = 0;
    
    // Set timer 6 prescalar to 256
    T6CONbits.TCKPS = 0b111;
    
    // Set timers 6/7 to 32 bit timer mode
    T6CONbits.T32 = 1;
    
    // Set timer clock input as PBCLK3
    T6CONbits.TCS = 0;
    
    // Clear timer 6
    TMR6 = 0x0000;
    TMR7 = 0x0000;
    
    // This variable is the number of seconds each frame is displayed during
    // standard operation state machine execution
    // Starts at 5 for now
    // set_timer_val = 5;
    
}
 

// This function sets the period of the timer and starts it
void stateMachineTimerStart(uint32_t timer_period_seconds) {
    
    // Set Timer 6 period to passed value
    PR6 = 0xF053;
    PR7 = (uint16_t) timer_period_seconds;
    
    // Clear the Timer
    TMR6 = 0;
    TMR7 = 0;
    
    // clear the timer flag
    clearInterruptFlag(Timer7);
    
    // Enable timer4 interrupt
    enableInterrupt(Timer7);
    
    // Turn Timer 6/7 ON
    T6CONbits.ON = 1;
    
}
// This function will read from the program flash memory and determine number of images to display
uint8_t readFrameNVM(void){
        
    uint32_t frame_num_ret = *((uint32_t *)(0xBD1FFFF0));
    
    return (uint8_t) frame_num_ret;
    
}

// This function will read from the program flash memory and determine image on time
uint32_t readDelayNVM(void) {
    
    uint32_t delay_val_ret = *((uint32_t *)(0xBD1FFFF4));
    
    return (uint8_t) delay_val_ret;
    
}

// This function will write to the program flash memory to tell how many images should be displayed
void writeNVMVariables(uint8_t frame_num, uint32_t delay_value) {
    
    PRECONbits.PREFEN = 0;
    
    disableGlobalInterrupts();
    
    // Page Erase
    NVMADDR = 0x1D1FC000;
    NVMCONbits.NVMOP = 0x4;

    // NVM Write Enable
    NVMCONbits.WREN = 1;
    
    // Start operation
    NVMInitOperation();
    
    // Wait for operation to complete
    while(NVMCONbits.WR != 0);
    NVMCONbits.WREN = 0;
    
    // set address and data reg
    NVMADDR = 0x1D1FFFF0;
    NVMDATA0 = (uint32_t) frame_num;
    NVMDATA1 = delay_value;
    NVMDATA2 = 0x00000000;
    NVMDATA3 = 0x00000000;
    
    NVMCONbits.NVMOP = 0x2;
    NVMCONbits.WREN = 1;
    
    // Start operation
    NVMInitOperation();
    
    while(NVMCONbits.WR != 0);
    NVMCONbits.WREN = 0;
    
    if (NVMCON && 0x3000) {
        
        // error flag
        
    }
    
    // Lock NVM
    NVMKEY = 0x0;
    
    enableGlobalInterrupts();
    
    PRECONbits.PREFEN = 1;
    
}

// This function is required for writing to and erasing internal PIC Flash memory
void NVMInitOperation(void) {
    
    NVMKEY = 0x0;
    NVMKEY = 0xAA996655; 
    NVMKEY = 0x556699AA; 
    NVMCONSET = 1 << 15;// must be an atomic instruction 
    
    
}

// This function will be called from main for autopilot mode
void autopilotMode(void) {
//    
//    // state machine switch statement
//    if(continue_autopilot) {

        switch(state) {
            // sm_start state initializes state machine
            case(sm_start):
                standardOpSMInit();
                break;
            // sm_first_load pulls in first flash chip data
            case(sm_first_load):
                state = sm_display;
                First_Load = 1;
                nextFlashData();
                break;
            // sm_next_load pulls in next flash chip data while muxing
            case(sm_next_load):
                state = sm_display;
                nextFlashData();
                stateMachineTimerStart(readDelayNVM());
                break;
            // sm_display puts ebi data to buffer    
            case(sm_display):
                // only if the last timer has finished and we finished reading from flash chip
                if (SPI_Read_Finished_Flag && SM_Timer_Done) {

                    state = sm_next_load;
                    SM_Timer_Done = 0;
                    SPI_Read_Finished_Flag = 0;
                    
                    movePanelDataFromEBISRAM();

                    if (usb_in_use_flag) {
                    
                        terminalTextAttributesReset();
                        terminalTextAttributes(GREEN, BLACK, NORMAL);
                        printf("Displaying Frame Number %u\n\r", flash_chip);
                        terminalTextAttributesReset(); 
                     
                    }
                    
                    else {
                     
                        softwareDelay(200);
                        
                    }  
                    
                    flash_chip++;
                    
                    // if it's the first image, start muxing
                    if (First_Load) {

                        panelMultiplexingTimerStart();
                        First_Load = 0;

                    }

                }

                break;      

            default:
                break;

        }
//
//    } else {
//
//        exitSM();
//
//    }
}