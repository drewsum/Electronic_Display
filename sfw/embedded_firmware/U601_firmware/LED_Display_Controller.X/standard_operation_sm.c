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

// Initialize state machine 
void standardOpSMInit(void) {
    
    if (readFrameNumber() >= 2 && readFrameNumber() <= 8) {
        
        flash_chip = 1;
        continue_autopilot = 1;
        state = sm_start;
        image_num = readFrameNumber();
        // nextState(begin);
        
        // Read what's in SPI Flash 1
        SPI_FLASH_beginRead(1);
        
        
    }
    
}

// Function to transition to next state
//void nextState(enum events event) {
//    switch(state) {
//        
//        case start:
//            switch(event) {
//                
//                case begin:
//                    // next state will be to load the first set of data
//                    state = load;
//                    nextState(loop);
//                    break;
//                
//                default:
//                    // exit state machine
//                    exitSM();
//                    break;
//            }       
//            break;
//            
//        case load:
//            switch(event) {
//                
//                case loop:
//                    // next state will be to display sram data
//                    state = display;
//                    
//                    // if statement to determine if we want to continue
//                    if (continue_autopilot){
//                        // load new data from next flash chip and loop to display
//                        // nextFlashData();
//                        nextState(loop);
//                    } else {
//                        // start stopping sequence
//                        nextState(stop);
//                    }
//                    break;
//                
//                case stop:
//                    // next state will be to end
//                    state = end;
//                    break;
//                
//                default:
//                    // exit state machine
//                    exitSM();
//                    break;
//            }
//            break;
//        
//        case display:
//            switch(event) {
//                
//                case loop:
//                    // next state will be to load new data
//                    state = load;
//                    
//                    // if statement to determine if we want to continue
//                    if (continue_autopilot){
//                        // display data and loop to load
//                        showSRAMData();
//                        nextState(loop);
//                    } else {
//                        // start stopping sequence
//                        nextState(stop);
//                    }
//                    break;
//                
//                case stop:
//                    // next state will be to end
//                    state = end;
//                    break;
//                
//                default:
//                    // exit state machine
//                    exitSM();
//                    break;
//            }
//            break;
//        
//        case end:
//            // exit state machine
//            exitSM();
//            break;
//            
//    }
//    
//}

// Function to move to next flash chip
//void nextFlashData(void){
//    
//    // if statement to check if next chip to contain data
//    if (SPI_FLASH_dataCheck(flash_chip)) {
//        
//        // bring flash chip data to ebi
//        SPI_FLASH_beginRead(flash_chip);
//        
//        // wait until reading is complete
//        while(flash_read_done == 0);
//        
//        // print out we are done reading 
//        terminalTextAttributesReset();
//        terminalTextAttributes(GREEN, BLACK, NORMAL);
//        printf("Data moved from Flash to EBI...\n\r");
//        terminalTextAttributesReset();
//        
//        // increment flash chip
//        if (flash_chip < 8) {
//            
//            flash_chip++;
//            
//        } else {
//            
//            flash_chip = 1;
//            
//        }
//        
//    } else {
//        
//        flash_chip = 1;
//        nextFlashData();
//        
//    }
//        
//}

// Function to display current sram data
void showSRAMData(void){
    
    // disable muxing
    panelMultiplexingSuspend();
    //muxing_state = 0;
    
    // transfer data from ebi to buffer
    movePanelDataFromEBISRAM();
    
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("Data moved from EBI to SRAM...\n\r");
    terminalTextAttributesReset();
    
    // enable muxing
    panelMultiplexingTimerStart();
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("Displaying...\n\r");
    terminalTextAttributesReset();
    
    //muxing_state = 1;
    
    // use countdown timer for display time
    // will be customized later
//    uint8_t i;
//    for (i = 0; i < 100000; i++) {
//        
//        countdown_val = 0xFFFF;
//        // 0xF053 equates to a ~1 second timer countdown
//        countdownTimerStart();
//        
//    }
    
}

// Function to exit state machine
void exitSM(void) {
    
    autopilot = 0;
    
    T6CONbits.ON = 0;
    
    flash_chip = 1;
    
}
 
void __ISR(_TIMER_7_VECTOR, ipl1SRS) countdownTimerISR(void) {
    
    // Turn off Timer 6
    T6CONbits.ON = 0;
    
    // Write over frame buffer with what is in EBI SRAM
    movePanelDataFromEBISRAM();
    
    // Move the next frame needed
    flash_chip++;
    if (flash_chip >= readFrameNumber()) flash_chip = 1;
    
    // Clear interrupt flag
    clearInterruptFlag(Timer7);
    disableInterrupt(Timer7);
    
    SPI_FLASH_beginRead(flash_chip);
    
}
    

// This function initializes the countdown timer
// Uses timer 6 and timer 7 in 32 bit mode
void countdownTimerInit(void) {
    
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
    
}
 

// This function sets the period of the timer and starts it
void countdownTimerStart(uint32_t timer_period_seconds) {
    
    // Set Timer 6 period to passed value
    PR6 = 0xFFFF;
    PR7 = timer_period_seconds;
    
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
uint8_t readFrameNumber(void){
    
    // set address and data reg
    //NVMADDR = 0xBD000000;
    
    uint32_t frame_num_ret = *((uint32_t *)(0xBD1FFFF0));
    
    return (uint8_t) frame_num_ret;
    
}

// This function will write to the program flash memory to tell how many images should be displayed
void writeFrameNumber(uint8_t frame_num){
    
    // set address and data reg
    NVMADDR = 0x1D1FFFF0;
    NVMDATA0 = (uint32_t) frame_num;
    
    NVMCONbits.NVMOP = 0x1;
    NVMCONbits.WREN = 1;
    
    int int_status; // storage for current Interrupt Enable state ]
    
    // Disable Interrupts 
    int_status = getGlobalInterruptsState();
    disableGlobalInterrupts();
    
    NVMKEY = 0x0;
    NVMKEY = 0xAA996655; 
    NVMKEY = 0x556699AA; 
    NVMCONSET = 1 << 15;// must be an atomic instruction 
    
    // Restore Interrupts
    if (int_status && 0x00000001) {
        
        enableGlobalInterrupts();
        
    }
    
    while(NVMCONbits.WR);
    
    NVMCONbits.WREN = 0;
    
    if (NVMCON & 0x3000) {
        
        // error flag
        
    }
    
    // Lock NVM
    NVMKEY = 0x0;
}
