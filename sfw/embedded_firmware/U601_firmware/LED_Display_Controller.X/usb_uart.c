
#include <xc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>

#include "32mz_interrupt_control.h"
#include "pin_macros.h"
#include "device_control.h"
#include "power_saving.h"
#include "watchdog_timer.h"
#include "usb_uart.h"
#include "terminal_control.h"
#include "error_handler.h"
#include "cause_of_reset.h"
#include "prefetch.h"
#include "adc.h"
#include "panel_control.h"
#include "test_buffer_fills.h"
#include "spi_flash.h"
#include "esp8266.h"
#include "standard_operation_sm.h"

#include "splash_screen.h"
#include "test_image_1.h"
// #include "test_image_2.h"

volatile uint32_t usb_uart_TxHead = 0;
volatile uint32_t usb_uart_TxTail = 0;
volatile uint8_t usb_uart_TxBuffer[USB_UART_TX_BUFFER_SIZE];
volatile uint32_t usb_uart_TxBufferRemaining;

volatile uint32_t usb_uart_RxHead = 0;
volatile uint32_t usb_uart_RxTail = 0;
volatile uint8_t usb_uart_RxBuffer[USB_UART_RX_BUFFER_SIZE];
volatile uint32_t usb_uart_RxCount;

volatile uint8_t usb_uart_RxStringReady = 0;

// Printable Variables from other header files
extern uint32_t device_on_time_counter;
extern reset_cause_t reset_cause;

// This function initializes UART 6 for USB debugging
void usbUartInitialize(void) {
 
    __XC_UART = 3;
    
    usb_in_use_flag = 1;
    
    // Disable UART 3 interrupts
    disableInterrupt(UART3_Receive_Done);
    disableInterrupt(UART3_Transfer_Done);
    disableInterrupt(UART3_Fault);
    
    // Turn off UART 3 for configuration
    U3MODEbits.ON = 0;
    
    // Enable UART 3 operation in IDLE mode
    U3MODEbits.SIDL = 0;
    
    // Disable IrDA encoding
    U3MODEbits.IREN = 0;
    
    // Disable CTS, RTS signals
    // (No flow control used)
    U3MODEbits.UEN = 0b00;
    
    // Enable wake from sleep
    U3MODEbits.WAKE = 1;
    
    // Disable loopback
    U3MODEbits.LPBACK = 0;
    
    // Disable auto-baud
    U3MODEbits.ABAUD = 0;
    
    // RX idle state is logic high
    U3MODEbits.RXINV = 0;
    
    // High speed baud rate setting
    U3MODEbits.BRGH = 1;
    
    // 8 bit data length and no parity
    U3MODEbits.PDSEL = 0b00;
    
    // 1 stop bit
    U3MODEbits.STSEL = 0;
    
    // Disable addressing
    U3STAbits.ADM_EN = 0;
    
    // Interrupt on every transmitted character
    U3STAbits.UTXISEL = 0b00;
    
    // Idle transmit state is high
    U3STAbits.UTXINV = 0;
    
    // Enable receiver
    U3STAbits.URXEN = 1;
    
    // Disable break
    U3STAbits.UTXBRK = 0;
    
    // Enable transmitter
    U3STAbits.UTXEN = 1;
    
    // Interrupt on every character received
    U3STAbits.URXISEL = 0b00;
    
    // Disable address detection
    U3STAbits.ADDEN = 0;
    
    // Set baud rate to 115200 bps
    // From section 21.3 of PIC32MZ reference manual
    // Input CLK is PBCLK2 (84 MHz)
    // With PBCLK2 = 84 MHz, BRGH = 1, baud rate error is 0.16%
    U3BRG = 181;
    
    // initializing the driver state
    usb_uart_TxHead = 0;
    usb_uart_TxTail = 0;
    usb_uart_TxBufferRemaining = sizeof(usb_uart_TxBuffer);
    usb_uart_RxHead = 0;
    usb_uart_RxTail = 0;
    usb_uart_RxCount = 0;
        
    
    // Set interrupt priorities
    setInterruptPriority(UART3_Receive_Done, 2);
    setInterruptPriority(UART3_Transfer_Done, 6);
    setInterruptPriority(UART3_Fault, 1);
    
    // Set interrupt subpriorities
    setInterruptSubpriority(UART3_Receive_Done, 2);
    setInterruptSubpriority(UART3_Transfer_Done, 2);
    setInterruptSubpriority(UART3_Fault, 1);
    
    // Clear all UART 3 Interrupts
    clearInterruptFlag(UART3_Receive_Done);
    clearInterruptFlag(UART3_Transfer_Done);
    clearInterruptFlag(UART3_Fault);
    
    // Enable UART 3
    U3MODEbits.ON = 1;
    
    // Trick UART into thinking user has pressed enter twice
//    U3MODEbits.LPBACK = 1;
//    U3TXREG = '\n';
//    U3TXREG = '\r';
//    U3TXREG = '\n';
//    U3TXREG = '\r';
//    U3MODEbits.LPBACK = 0;
    
    // Enable receive and error interrupts
    // Transfer interrupt is set in write function
    enableInterrupt(UART3_Receive_Done);
    enableInterrupt(UART3_Fault);
    
}

// This is the USB UART receive interrupt service routine
void __ISR(_UART3_RX_VECTOR, ipl2SRS) usbUartReceiveISR(void) {
    
    usb_in_use_flag = 1;
    
    // Do receive tasks
    usbUartReceiveHandler();
    
    // Clear receive interrupt flag
    clearInterruptFlag(UART3_Receive_Done);
    
}

// This is the USB UART transfer interrupt service routine
void __ISR(_UART3_TX_VECTOR, ipl6SRS) usbUartTransferISR(void) {
    
    // Do transfer tasks
    usbUartTransmitHandler();
    
    // Clear interrupt flag
    clearInterruptFlag(UART3_Transfer_Done);
    
}

// This is the UAB UART fault interrupt service routine
void __ISR(_UART3_FAULT_VECTOR, ipl1SRS) usbUartFaultISR(void) {
    
    // TO-DO: Fault tasks
    error_handler.USB_error_flag = 1;   
    
    // Clear fault interrupt flag
    clearInterruptFlag(UART3_Fault);
    
}

// This function pulls a byte from the RX ring buffer
uint8_t usbUartReadByte(void) {
 
    uint8_t readValue  = 0;
    
    // This state should never be entered
    while(0 == usb_uart_RxCount)
    {
        error_handler.USB_error_flag = 1;
        return 0;
    }

    readValue = usb_uart_RxBuffer[usb_uart_RxTail++];
    if(sizeof(usb_uart_RxBuffer) <= usb_uart_RxTail)
    {
        usb_uart_RxTail = 0;
    }
    
    
    disableInterrupt(UART3_Receive_Done);
    usb_uart_RxCount--;
    enableInterrupt(UART3_Receive_Done);
    return readValue;
    
}


// This function adds a byte to the TX ring buffer
void usbUartPutchar(uint8_t txData) {
 
    // wait for ring buffer to open up
    while(0 == usb_uart_TxBufferRemaining);

    if(0 == getInterruptEnable(UART3_Transfer_Done))
    {
        U3TXREG = txData;
        muxing_state = T5CONbits.ON;
        panelMultiplexingSuspend();
   
    }
    else
    {
        
        disableInterrupt(UART3_Transfer_Done);
        usb_uart_TxBuffer[usb_uart_TxHead++] = txData;
        
        if(sizeof(usb_uart_TxBuffer) <= usb_uart_TxHead)
        {
            usb_uart_TxHead = 0;
        }
        
        usb_uart_TxBufferRemaining--;

    }

     enableInterrupt(UART3_Transfer_Done);
   
    
}

// This serves as the TX interrupt handler and is called by the TX ISR
void usbUartTransmitHandler(void) {
 
    if(sizeof(usb_uart_TxBuffer) > usb_uart_TxBufferRemaining)
    {
        U3TXREG = usb_uart_TxBuffer[usb_uart_TxTail++];
        if(sizeof(usb_uart_TxBuffer) <= usb_uart_TxTail)
        {
            usb_uart_TxTail = 0;
        }
        usb_uart_TxBufferRemaining++;
    }
    
    else
    {
        disableInterrupt(UART3_Transfer_Done);
        if (muxing_state) panelMultiplexingTimerStart();
        
    }
    
    
}


// This serves as the RX handler and is called by the RX ISR
void usbUartReceiveHandler(void) {
            
    if(1 == U3STAbits.OERR)
    {
        U3MODEbits.ON = 0;
        error_handler.USB_error_flag = 1;
        U3STAbits.OERR = 0;
        U3MODEbits.ON = 1;
    }
    
    while(U3STAbits.URXDA) {
    
        usb_uart_RxBuffer[usb_uart_RxHead++] = U3RXREG;
        
        if(sizeof(usb_uart_RxBuffer) <= usb_uart_RxHead)
        {
            usb_uart_RxHead = 0;
        }
        usb_uart_RxCount++;
        
    }    
    
    // This chunk tells main() or whatever is pulling from the ring buffer that
    // data is ready to be read, since the terminal sent a newline or 
    // carriage return
    if((usb_uart_RxBuffer[usb_uart_RxHead - 1] == (int) '\n') || 
       (usb_uart_RxBuffer[usb_uart_RxHead - 1] == (int) '\r')) {

        usb_uart_RxStringReady = 1;
                
    }
    
    else {
        
        usb_uart_RxStringReady = 0;
        
    }
   
    // If we've received a backspace
    if((usb_uart_RxBuffer[usb_uart_RxHead - 1] == (int) '\b')) {
     
        usb_uart_RxBuffer[usb_uart_RxHead - 1] = '\0';
        usb_uart_RxHead--;
 
        // Erase the "backspaced" character on terminal
        printf("\033[K");
        
        if(usb_uart_RxHead != usb_uart_RxTail) {
        
            usb_uart_RxBuffer[usb_uart_RxHead - 1] = '\0';
            usb_uart_RxHead--;

        }
        
    }
    
}

// This function redirects stdout to USB_UART output, allowing printf functionality
void _mon_putc(char c) {
    
    usbUartPutchar(c);
    
}


// This function pulls data out of the RX ring buffer
void usbUartRingBufferPull(void) {

    int charNumber = usb_uart_RxCount;
            
    // Clear line buffer
    uint32_t index;
    for (index = 0; index < sizeof(usb_uart_line); index++) {

        usb_uart_line[index] = '\0';

    }

    // Fill line from ring buffer
    for(index = 0; index < charNumber; index++){

        usb_uart_line[index] = usbUartReadByte();

    }

    // Reset ring buffer
    usb_uart_RxTail = usb_uart_RxHead;

    // Try to kill off ending returns/newlines
    while((usb_uart_line[strlen(usb_uart_line) - 1] == (int) '\n') ||
          (usb_uart_line[strlen(usb_uart_line) - 1] == (int) '\r')) {
     
        // NULL
        usb_uart_line[strlen(usb_uart_line) - 1] = '\0';
        
    }
    

    // Clear ready flag
    usb_uart_RxStringReady = 0;

    // Check to see if line matches a command
    usbUartRingBufferLUT(usb_uart_line);

    
}


// This function parses the data pulled from the RX ring buffer
// This is the function that actually makes stuff happen based on commands
// Enter the command you'd like to set up within the if statements as
// an argument to the "strstr" functions
/*
 
    if (strcmp(line_in, "<INSERT COMMAND HERE>") == 0) {

        <ACTIONS OF COMMAND>;
    }
 
 * 
 *  * */
void usbUartRingBufferLUT(char * line_in) {
 
    // THIS IS WHERE WE DO THE ACTUAL PARSING OF RECEIVED STRING AND
    // ACT ON IT
    
    if (strcmp(line_in, "Reset") == 0) {

         deviceReset();
        
    }
    
    else if (strcmp(line_in, "Clear") == 0) {
     
        terminalClearScreen();
        terminalSetCursorHome();
        
    }
    
    else if (strcmp(line_in, "*IDN?") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("E44 Electronic Display Logic Board\n\r");
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "Device On Time?") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("On time since last device reset: %s\n\r", 
                getStringSecondsAsTime(device_on_time_counter));
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "PMD Status?") == 0) {
     
        usb_uart_TxHead = 0;
        usb_uart_TxTail = 0;
        
        printPMDStatus();
        
    }
    
     else if (strcmp(line_in, "MCU IDs?") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        
        // Print serial number
        printf("    PIC32MZ Serial Number retrieved from Flash: %s\n\r",
                getStringSerialNumber());
        
        // Print device ID
        printf("    Device ID retrieved from Flash: %s (0x%X)\n\r", 
            getDeviceIDString(getDeviceID()), 
            getDeviceID());

        // Print revision ID
        printf("    Revision ID retrieved from Flash: %s (0x%X)\n\r", 
            getRevisionIDString(getRevisionID()), 
            getRevisionID());

        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "MCU Status?") == 0) {
     
        printWatchdogStatus();
        
        printDeadmanStatus();
        
        printPrefetchStatus();
        
        
    }


    else if (strcmp(line_in, "SPI Status?") == 0) {
     
        printSPIFlashStatus(); 
        
    }
    
    else if (strcmp(line_in, "Interrupt Status?") == 0) {
     
        usb_uart_TxHead = 0;
        usb_uart_TxTail = 0;
            
        // Print function from interrupt control module
        printInterruptStatus();
        
    }
    
    else if (strcmp(line_in, "Cause of Reset?") == 0) {
     
        terminalTextAttributesReset();
        
        if (    reset_cause == Undefined ||
                reset_cause == Primary_Config_Registers_Error ||
                reset_cause == Primary_Secondary_Config_Registers_Error ||
                reset_cause == Config_Mismatch ||
                reset_cause == DMT_Reset ||
                reset_cause == WDT_Reset ||
                reset_cause == Software_Reset ||
                reset_cause == External_Reset ||
                reset_cause == BOR_Reset) {

            terminalTextAttributes(RED, BLACK, NORMAL);

        }

        else {

            terminalTextAttributes(GREEN, BLACK, NORMAL);

        }
        
        printf("Cause of the most recent device reset: %s\n\r",
                getResetCauseString(reset_cause));
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "Clock Status?") == 0) {
     
        printClockStatus(SYSCLK_INT);
        
    }
    
    else if (strcmp(line_in, "EBI Status?") == 0) {
        
        printEBIStatus();
        
    }
    
    else if (strcmp(line_in, "Test EBI SRAM") == 0) {
     
        uint8_t test_status = 0;
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Testing writing to and reading from all external SRAM addresses...\n\r");
        
        test_status = testEBISRAM();
        
        terminalTextAttributesReset();
        
        if (test_status == 0) {
         
            error_handler.EBI_error_flag = 1;
            updateErrorLEDs();
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("EBI SRAM Test Failed with exit status %d\n\r", test_status);
        
        }
        
        else {
         
            terminalTextAttributes(GREEN, BLACK, NORMAL);
            printf("EBI SRAM Test Passed with exit status %d\n\r", test_status);
        
        }
        
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "Clear EBI SRAM") == 0) {
     
        clearEBISRAM();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("All EBI SRAM addresses cleared\n\r");
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "Print EBI SRAM Contents") == 0) {
     
        terminalTextAttributesReset();
        ebiPrintSRAM();
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "Print Buffer Contents") == 0) {
        
        terminalTextAttributesReset();
        panelDataBufferPrint();
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "Copy EBI SRAM to Buffer") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Moving EBI SRAM data into internal RAM buffer\n\r");
        
        movePanelDataFromEBISRAM();
        
        printf("Data copy complete\n\r");
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "Copy Buffer to EBI SRAM") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Moving Internal RAM buffer data into EBI SRAM\n\r");
        
        movePanelDataToEBISRAM();
        
        printf("Data copy complete\n\r");
        terminalTextAttributesReset();
        
    }
    
    // Identification command
    else if(strcmp(line_in, "Enable Muxing") == 0) {
     
        // Disable multiplexing timer
        panelMultiplexingTimerStart();
        muxing_state = 1;
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Panel multiplexing Enabled\n\r");
        terminalTextAttributesReset();
        
    }
    
    // disable multiplexing
    else if(strcmp(line_in, "Disable Muxing") == 0) {
    
        // Suspend panel multiplexing, clear all panel IO signals
        panelMultiplexingSuspend();
        muxing_state = 0;
        
        terminalTextAttributesReset();
        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("Panel multiplexing Disabled\n\r");
        terminalTextAttributesReset();
        
    }
    
    // set ram buffer black
    else if(strcmp(line_in, "Set Black") == 0) {
     
        fillRamBufferBlack();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with black data\n\r");
        terminalTextAttributesReset();
        
    }
    
    // set ram buffer white
    else if(strcmp(line_in, "Set White") == 0) {
     
        fillRamBufferWhite();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with white data\n\r");
        terminalTextAttributesReset();
        
    }
    
    // set ram buffer red
    else if(strcmp(line_in, "Set Red") == 0) {
     
        fillRamBufferRed();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with red data\n\r");
        terminalTextAttributesReset();
        
    }
    
    // set ram buffer blue
    else if(strcmp(line_in, "Set Blue") == 0) {
     
        fillRamBufferBlue();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with blue data\n\r");
        terminalTextAttributesReset();
        
    }
    
    // set ram buffer white
    else if(strcmp(line_in, "Set Green") == 0) {
     
        fillRamBufferGreen();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with green data\n\r");
        terminalTextAttributesReset();
        
    }
    
    // set ram buffer Cyan
    else if(strcmp(line_in, "Set Cyan") == 0) {
     
        fillRamBufferCyan();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with cyan data\n\r");
        terminalTextAttributesReset();
        
    }
    
    // set ram buffer random
    else if(strcmp(line_in, "Set Rand") == 0) {
     
        fillRamBufferRand();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with random data\n\r");
        terminalTextAttributesReset();
        
    }
    
    // set ram buffer magenta
    else if(strcmp(line_in, "Set Magenta") == 0) {
     
        fillRamBufferMagenta();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with magenta data\n\r");
        terminalTextAttributesReset();
        
    }
    
    // set ram buffer yellow
    else if(strcmp(line_in, "Set Yellow") == 0) {
     
        fillRamBufferYellow();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with yellow data\n\r");
        terminalTextAttributesReset();
        
    }

    else if(strcmp(line_in, "Set MU Logo") == 0) {
     
        fillRamBufferTestImage1();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with MU Logo Image\n\r");
        terminalTextAttributesReset();
        
    }
    
    else if(strcmp(line_in, "Set Splash Screen") == 0) {
     
        fillRamBufferSplashScreen();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with Splash Screen\n\r");
        terminalTextAttributesReset();
        
    }
    
    // Set panel brightness
    else if (strstart(line_in, "Set Panel Brightness ") == 0) {
    
        // Get which chip we're erasing
        uint32_t set_brightness;
        sscanf(line_in, "Set Panel Brightness %u", &set_brightness);
        
        if (set_brightness > 100 || set_brightness < 0) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("Please enter a brightness between 0%% and 100%%, user entered %u%%\n\r", set_brightness);
            terminalTextAttributesReset();

            
        }
        
        else {

            panelPWMSetBrightness((uint8_t) set_brightness);

            terminalTextAttributesReset();
            terminalTextAttributes(GREEN, BLACK, NORMAL);
            printf("Set Panel Brightness to %u%%\n\r", set_brightness);
            terminalTextAttributesReset();

        }
            
    }
    
    else if (strstart(line_in, "Set Delay Time ") == 0) {
    
        sscanf(received_string, "Set Delay Time %u", &set_timer_val);
            
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Set countdown value = %u\r\n", set_timer_val);
        terminalTextAttributesReset();
        
        // panelMultiplexingSuspend();
        fillRamBufferSplashScreen();
        panelMultiplexingTimerStart();
        muxing_state = 1;
        
        // state machine flags
        continue_autopilot = 1;
        state = sm_start;
            
    }
    
    else if (strcmp(line_in, "Get Delay Time") == 0) {
    
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Countdown value = %u\r\n", set_timer_val);
        terminalTextAttributesReset();
                    
    }
    
    else if (strcmp(line_in, "Error Status?") == 0) {
     
        // Print error handler status
        printErrorHandlerStatus();
        
        // Print help message
        terminalTextAttributes(YELLOW, BLACK, NORMAL);
        printf("\n\rCall 'Clear Errors' command to clear any errors that have been set\n\r");
        terminalTextAttributesReset();
        
        
    }
    
    else if (strcmp(line_in, "Clear Errors") == 0) {
     
        // Zero out all error handler flags
        clearErrorHandler();
        
        // Update error LEDs based on error handler status
        updateErrorLEDs();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Error Handler flags cleared\n\r");
        terminalTextAttributesReset();
        
    }
        
    else if (strstart(line_in, "SPI Flash Chip Read ") == 0) {
    
        // Get which chip we're erasing
        uint32_t chip_to_read;
        sscanf(line_in, "SPI Flash Chip Read %u", &chip_to_read);
        
        if (chip_to_read <= 8 && chip_to_read >= 1) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(GREEN, BLACK, NORMAL);
            printf("Reading chip %d\n\r", chip_to_read);
            terminalTextAttributesReset();

            SPI_FLASH_beginRead(chip_to_read);
            
        }
        
        else {
         
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("Chip %u is not valid\n\r", chip_to_read);
            terminalTextAttributesReset();
        
        }

    }
    
    else if (strstart(line_in, "SPI Flash Chip Write ") == 0) {
        
        uint32_t chip_to_write;
        sscanf(line_in, "SPI Flash Chip Write %u", &chip_to_write);
        
        if (chip_to_write <= 8 && chip_to_write >= 1) {
            
            terminalTextAttributesReset();
            terminalTextAttributes(GREEN, BLACK, NORMAL);
            printf("Writing to chip %u\n\r", chip_to_write);
            terminalTextAttributesReset();
            SPI_FLASH_beginWrite(chip_to_write);

        }
        
        else {
         
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("Chip %u is not valid\n\r", chip_to_write);
            terminalTextAttributesReset();
            
        }
        
        
    }
    
    else if (strstart(line_in, "SPI Flash Chip Erase ") == 0) {
    
        // Get which chip we're erasing
        uint32_t chip_to_erase;
        sscanf(line_in, "SPI Flash Chip Erase %u", &chip_to_erase);
        
        if (chip_to_erase <= 8 && chip_to_erase >= 1) {
            
            SPI_Flash_writeEnable((uint8_t) chip_to_erase);
            SPI_Flash_blockProtectionDisable((uint8_t) chip_to_erase);
            SPI_Flash_writeEnable((uint8_t) chip_to_erase);
            SPI_FLASH_chipErase((uint8_t) chip_to_erase);
            terminalTextAttributes(GREEN, BLACK, NORMAL);
            printf("Erased chip %u\n\r", chip_to_erase);
            terminalTextAttributesReset();
        
        }
        
        else {
         
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("Chip %u is not valid\n\r", chip_to_erase);
            terminalTextAttributesReset();
            
        }
            

    }
    
    else if (strcmp(line_in, "Credits") == 0) {
     
        terminalClearScreen();
        terminalSetCursorHome();

        terminalTextAttributesReset();
        terminalTextAttributes(YELLOW, BLUE, BOLD);
        printf("Marquette Senior Design 2018-2019\n\r\n\r");
        terminalTextAttributesReset();
        terminalTextAttributesReset();
        terminalTextAttributes(YELLOW, BLUE, BOLD);
        printf("Team E44: Electronic Display Display\n\r\n\r");
        terminalTextAttributesReset();
        terminalTextAttributes(BLACK, WHITE, NORMAL);
        printf("Hardware Design/Embedded Firmware:\n\r");
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("Logan Wedel\n\r");
        terminalTextAttributesReset();
        terminalTextAttributes(YELLOW, BLACK, NORMAL);
        printf("Caroline Gilger\n\r");
        terminalTextAttributesReset();
        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("Drew Maatman\n\r");
        terminalTextAttributesReset();
        terminalTextAttributes(BLACK, WHITE, NORMAL);
        printf("App Design/Integration:\n\r");
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Kevin Etta\n\r");
        terminalTextAttributesReset();
        terminalTextAttributes(MAGENTA, BLACK, NORMAL);
        printf("Tuoxuan Ren\n\r");
        terminalTextAttributesReset();
        terminalTextAttributes(BLACK, WHITE, NORMAL);
        printf("Mentor:\n\r");
        terminalTextAttributesReset();
        printf("Cris Ababei\n\r\n\r");
        
    }
    
//    else if (strcmp(line_in, "ADC Raw Data?") == 0) {
//    
//        if (error_handler.ADC_configuration_error_flag) {
//         
//            terminalTextAttributesReset();
//            terminalTextAttributes(RED, BLACK, NORMAL);
//            printf("ADC Configuration Error\n\r");
//            terminalTextAttributesReset();
//            
//        }
//        
//        else if (ADCCON3bits.DIGEN7 == 0) {
//         
//            terminalTextAttributesReset();
//            terminalTextAttributes(RED, BLACK, NORMAL);
//            printf("ADC Not Initialized\n\r");
//            terminalTextAttributes(YELLOW, BLACK, NORMAL);
//            printf("Call 'Initialize ADC' to Initialize ADC for measurements\n\r");
//            terminalTextAttributesReset();
//            
//        }
//        
//        else {
//            terminalTextAttributesReset();
//            terminalTextAttributes(CYAN, BLACK, NORMAL);
//            printf("Most recent raw 12 bit ADC conversions:\n\r");
//            printf("    +3.3V Raw ADC Conversion Result: 0x%08X\n\r", adc_results.POS3P3_adc_raw);
//            printf("    +12V Raw ADC Conversion Result: 0x%08X\n\r", adc_results.POS12_adc_raw);
//            printf("    +5.5V Raw ADC Conversion Result: 0x%08X\n\r", adc_results.POS5P5_adc_raw);
//            printf("    +5V Raw ADC Conversion Result: 0x%08X\n\r", adc_results.POS5_adc_raw);
//            printf("    +5VP Raw ADC Conversion Result: 0x%08X\n\r", adc_results.POS5P_adc_raw);
//            printf("    Internal VREF Raw ADC Conversion Result: 0x%08X\n\r", adc_results.vref_adc_raw);
//            printf("    Internal Die Temperature Raw ADC Conversion Result: 0x%08X\n\r", adc_results.die_temp_adc_raw);
//            terminalTextAttributesReset();
//
//      }
//        
//    }
    
    else if (strcmp(line_in, "ADC Results?") == 0) {
     
        if (error_handler.ADC_configuration_error_flag) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("ADC Configuration Error\n\r");
            terminalTextAttributesReset();
            
        }
        
        else if (ADCCON3bits.DIGEN7 == 0) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("ADC Not Initialized\n\r");
            terminalTextAttributes(YELLOW, BLACK, NORMAL);
            printf("Call 'Initialize ADC' to Initialize ADC for measurements\n\r");
            terminalTextAttributesReset();
            
        }
        
        else {

            terminalTextAttributesReset();
            terminalTextAttributes(CYAN, BLACK, NORMAL);
            printf("Most recent ADC conversion results:\n\r");
            printf("    +12V Input Voltage Measurement: %+0.3f V\n\r", adc_results.POS12_adc);
            printf("    +3.3V Power Supply Measurement: %+0.3f V\n\r", adc_results.POS3P3_adc);
            printf("    +5V Power Supply Measurement: %+0.3f V\n\r", adc_results.POS5_adc);
            printf("    +5.5V Linear Regulator Measurement: %+0.3f V\n\r", adc_results.POS5P5_adc);
            printf("    +5VP LED Power Supply Measurement: %+0.3f V\n\r", adc_results.POS5P_adc);
            printf("    Internal VREF ADC Conversion Result: %+0.3f V\n\r", adc_results.vref_adc);
            printf("    Internal Die Temperature ADC Conversion Result: %+0.3f C\n\r", adc_results.die_temp_adc);
            terminalTextAttributesReset();

        }
            
    }
    
    else if (strcmp(line_in, "ADC Max Results?") == 0) {
     
        if (error_handler.ADC_configuration_error_flag) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("ADC Configuration Error\n\r");
            terminalTextAttributesReset();
            
        }
        
        else if (ADCCON3bits.DIGEN7 == 0) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("ADC Not Initialized\n\r");
            terminalTextAttributes(YELLOW, BLACK, NORMAL);
            printf("Call 'Initialize ADC' to Initialize ADC for measurements\n\r");
            terminalTextAttributesReset();
            
        }
        
        else {

            terminalTextAttributesReset();
            terminalTextAttributes(CYAN, BLACK, NORMAL);
            printf("Maximum ADC conversion results:\n\r");
            printf("    Max +12V Input Voltage Measurement: %0.3f V\n\r", adc_results.POS12_adc_max);
            printf("    Max +3.3V Power Supply Measurement: %0.3f V\n\r", adc_results.POS3P3_adc_max);
            printf("    Max +5V Power Supply Measurement: %0.3f V\n\r", adc_results.POS5_adc_max);
            printf("    Max +5.5V Linear Regulator Measurement: %0.3f V\n\r", adc_results.POS5P5_adc_max);
            printf("    Max +5VP LED Power Supply Measurement: %0.3f V\n\r", adc_results.POS5P_adc_max);
            printf("    Max Internal Die Temperature ADC Conversion Result: %+0.3f C\n\r", adc_results.die_temp_adc_max);
            terminalTextAttributesReset();

        }
            
    }
    
    else if (strcmp(line_in, "ADC Min Results?") == 0) {
     
        if (error_handler.ADC_configuration_error_flag) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("ADC Configuration Error\n\r");
            terminalTextAttributesReset();
            
        }
        
        else if (ADCCON3bits.DIGEN7 == 0) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("ADC Not Initialized\n\r");
            terminalTextAttributes(YELLOW, BLACK, NORMAL);
            printf("Call 'Initialize ADC' to Initialize ADC for measurements\n\r");
            terminalTextAttributesReset();
            
        }
        
        else {

            terminalTextAttributesReset();
            terminalTextAttributes(CYAN, BLACK, NORMAL);
            printf("Minimum ADC conversion results:\n\r");
            printf("    Min +12V Input Voltage Measurement: %0.3f V\n\r", adc_results.POS12_adc_min);
            printf("    Min +3.3V Power Supply Measurement: %0.3f V\n\r", adc_results.POS3P3_adc_min);
            printf("    Min +5V Power Supply Measurement: %0.3f V\n\r", adc_results.POS5_adc_min);
            printf("    Min +5.5V Linear Regulator Measurement: %0.3f V\n\r", adc_results.POS5P5_adc_min);
            printf("    Min +5VP LED Power Supply Measurement: %0.3f V\n\r", adc_results.POS5P_adc_min);
            printf("    Min Internal Die Temperature ADC Conversion Result: %+0.3f C\n\r", adc_results.die_temp_adc_min);
            terminalTextAttributesReset();

        }
            
    }
    
    else if (strcmp(line_in, "Initialize ADC") == 0) {
     
        ADCInitialize();
        
    }
    
    else if (strcmp(line_in, "ADC Status?") == 0) {
     
        printADCStatus();
        
    }
    
    else if (strcmp(line_in, "Help") == 0) {
    
        usbUartPrintHelpMessage();
        
    }
    
//    else if (strcmp(line_in, "POS5 Enable") == 0) {
//     
//        POS5_RUN_PIN = 1;
//        
//        terminalTextAttributesReset();
//        terminalTextAttributes(GREEN, BLACK, NORMAL);
//        printf("POS5 RUN Asserted\n\r");
//        terminalTextAttributesReset();
//              
//    }
//    
//    else if (strcmp(line_in, "POS5 Disable") == 0) {
//     
//        POS5_RUN_PIN = 0;
//        
//        terminalTextAttributesReset();
//        terminalTextAttributes(RED, BLACK, NORMAL);
//        printf("POS5 RUN Deasserted\n\r");
//        terminalTextAttributesReset();
//        
//    }
    
    else if (strcmp(line_in, "POS5P Enable") == 0) {
     
        POS5P_RUN_PIN = 1;
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("POS5P RUN Asserted\n\r");
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "POS5P Disable") == 0) {
     
        POS5P_RUN_PIN = 0;
        
        terminalTextAttributesReset();
        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("POS5P RUN Deasserted\n\r");
        terminalTextAttributesReset();
        
    }
    
    else if (strstart(line_in, "WiFi: ") == 0) {
        // print WiFi command to UART1 RX
        // esp8266Putstring(line_in);
        
        char *esp_tx_string = malloc(32);
        memset(esp_tx_string, 0, sizeof(esp_tx_string));
        sscanf(line_in, "WiFi: %31c", esp_tx_string);
        
        strcat(esp_tx_string, "\r\n");
        esp8266Putstring(esp_tx_string);
        
        free(esp_tx_string);
        
    }
    
    else if (strcmp(line_in, "IP Addr?") == 0 || strcmp(line_in, "MAC Addr?") == 0) {
     
        // Set AT command for printing IP address
        esp8266Putstring("AT+CIFSR\r\n");
        
    }
    
    // start state machine
    else if(strcmp(line_in, "Enable State Machine") == 0) {
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Starting State Machine...\n\r");
        terminalTextAttributesReset();
        
        // panelMultiplexingSuspend();
        fillRamBufferSplashScreen();
        panelMultiplexingTimerStart();
        muxing_state = 1;
        
        // state machine flags
        continue_autopilot = 1;
        state = sm_start;
        
    }
    
    // stop state machine
    else if(strcmp(line_in, "Disable State Machine") == 0) {
             
        // Stop state machine
        panelMultiplexingSuspend();
        muxing_state = 0;
        continue_autopilot = 0;
        state = sm_start;
        sm_previous = 0;
        T6CONbits.ON = 0;
        eventually_continue_flag = 0;
        
        terminalTextAttributesReset();
        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("State Machine Disabled\n\r");
        terminalTextAttributesReset();
        
    }
    
    else if (strstart(line_in, "Set Project Vals ") == 0) {
    
        // Get which chip we're erasing
        uint32_t set_frame;
        uint32_t set_delay;
        sscanf(line_in, "Set Project Vals %u, %u", &set_frame, &set_delay);
        
        if (set_frame >= 1 && set_frame <= 8 && set_delay <= 120) {

            writeNVMVariables((uint8_t) set_frame, set_delay);
        
        }
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("NVM Frame Number set to %u, NVM delay value set to %u, wait for reset\n\r", readFrameNVM(), readDelayNVM());
        terminalTextAttributesReset();
        
        softwareDelay(10000000);
        deviceReset();
        
    }
    
    else if (strcmp(line_in, "Get Frame Num") == 0) {  
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("NVM Frame Number read as %u\n\r", readFrameNVM());
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "Get Delay Val") == 0) {  
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("NVM Delay Value read as %u\n\r", readDelayNVM());
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "Easter Egg") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        
        printf( " _    _ _           _   _              ______ _____ _____ ___  \r\n"
                "| |  | | |         | | ( )             | ___ \\_   _/  __ \\__ \\ \r\n"
                "| |  | | |__   __ _| |_|/ ___    __ _  | |_/ / | | | /  \\/  ) |\r\n"
                "| |/\\| | '_ \\ / _` | __| / __|  / _` | |  __/  | | | |     / / \r\n"
                "\\  /\\  / | | | (_| | |_  \\__ \\ | (_| | | |    _| |_| \\__/\\|_|  \r\n"
                " \\/  \\/|_| |_|\\__,_|\\__| |___/  \\__,_| \\_|    \\___/ \\____/(_)  \r\n");

        terminalTextAttributesReset();
        
    }
    
}

// Print help message, used in a command above
void usbUartPrintHelpMessage(void) {
 
    usb_uart_TxHead = 0;
    usb_uart_TxTail = 0;   

    
    terminalTextAttributesReset();
    terminalTextAttributes(YELLOW, BLACK, NORMAL);
    printf("Supported Commands:\n\r");
    printf("    Reset: Software Reset\n\r");
    printf("    Clear: Clears the terminal\n\r");
    printf("    Cause of Reset?: Prints the cause of the most recent device reset\n\r");
    printf("    *IDN?: Prints identification string\n\r");
    printf("    MCU IDs?: Print microcontroller serial number, device ID, and silicon revision ID\r\n");
    printf("    MCU Status?: Prints the status of the watchdog timer, deadman timer and predictive prefetch module\n\r");
    printf("    Device On Time?: Returns the device on time since last reset\n\r");
    printf("    PMD Status?: Prints the state of Peripheral Module Disable settings\n\r");
    printf("    EBI Status?: Prints status of EBI configuration\r\n");
    printf("    Test EBI SRAM: Tests writing to and reading from external EBI SRAM\n\r");
    printf("    Print EBI SRAM Contents: Prints the data saved in EBI SRAM\n\r");
    printf("    Clear EBI SRAM: Resets all bytes within EBI SRAM to 0x00\n\r");
    printf("    Print Buffer Contents: Prints the contents of the first kB of internal RAM buffer holding display data\n\r");
    printf("    Copy Buffer to EBI SRAM: Moves data from Internal Buffer into EBI SRAM\n\r");
    printf("    Copy EBI SRAM to Buffer: Moves data from EBI SRAM into Internal Buffer\n\r");
    printf("    SPI Flash Chip Erase <x>: Erases the entered SPI Flash chip, x = 1:8\n\r");
    printf("    SPI Flash Chip Write <x>: Writes the contents of the EBI SRAM buffer to the given SPI Flash chip, x = 1:8\n\r");
    printf("    SPI Flash Chip Read <x>: Moves data from the given SPI Flash chip into EBI SRAM buffer, x = 1:8\n\r");
    printf("    SPI Status?: Prints the SPI configuration bits\n\r");
    printf("    Interrupt Status? Prints information on interrupt settings\n\r");
    printf("    Clock Status?: Prints system clock settings\n\r");
    printf("    Error Status?: Prints the state of system error flags\n\r");
    printf("    Clear Errors: Clears all error handler flags\n\r");
    printf("    Initialize ADC: Sets up the Analog to Digital Converter for measuring analog signals within the system\n\r");
    printf("    ADC Results?: Prints results of the most recent ADC conversions for analog signals in the system\n\r");
    printf("    ADC Max Results?: prints the maximum recorded value for each ADC channel\n\r");
    printf("    ADC Min Results?: prints the minimum recorded value for each ADC channel\n\r");
//    printf("    ADC Raw Data?: Prints the raw 12 bit results of the ADC conversions\n\r");
    printf("    ADC Status?: Prints information about analog to digital converter settings\n\r");
//    printf("    POS5 Enable: Turns on the on board +5V Power Supply for level shifters\n\r");
//    printf("    POS5 Disable: Turns off the on board +5V Power Supply for level shifters\n\r");
    printf("    POS5P Enable: Turns on the external +5V Power Supply for LED panels\n\r");
    printf("    POS5P Disable: Turns off the external +5V Power Supply for LED panels\n\r");
    printf("    Enable Muxing: enables the multiplexing timer \n\r");
    printf("    Disable Muxing: disable the multiplexing timer \n\r");
//    printf("    Print Test Message: Print out terminal test data\n\r");
    printf("    Credits: Displays creators\n\r");
    printf("    Help: This Command\n\r");
    printf("    Set Red: Sets all pixels in display red\n\r");
    printf("    Set Black: Sets all pixels to display black\n\r");
    printf("    Set White: Sets all pixels in display white\n\r");    
    printf("    Set Blue: Sets all pixels in display blue\n\r");
    printf("    Set Yellow: Sets all pixels in display yellow\n\r");
    printf("    Set Cyan: Sets all pixels in display cyan\n\r");    
    printf("    Set Green: Sets all pixels in display green\n\r");    
    printf("    Set Magenta: Sets all pixels in display magenta\n\r");
    printf("    Set MU Logo: Loads RAM buffer with data for the MU Logo\n\r");
    printf("    Set Splash Screen: Loads RAM buffer with data for the splash screen\n\r");
    printf("    Set Rand: Sets pixels to display random data\n\r");
    printf("    Set Panel Brightness <x>: Sets the panel brightness to x%%, x = 0:100\n\r");
    printf("    WiFi: <s>: Writes a string <s> to the WiFi module\n\r");
    printf("    IP Addr?: Prints the logic board IP Address and MAC Address\r\n");
    printf("    MAC Addr?: Prints the logic board IP Address and MAC Address\r\n");
    printf("    Enable State Machine: Enables the standard operation state machine, or 'Autopilot'\r\n");
    printf("    Disable State Machine: Disables the standard operation state machine, allowing serial interface image selection\r\n");
    printf("    Set Project Vals <x>, <y>: Sets the number of state machine frames <x> and frame delay <y>\r\n");
    printf("    Get Frame Num: Reads how many frames the standard operation state machine is looping through\r\n");
    printf("    Get Delay Val: Reads how long each frame is se tto run\r\n");
    
    printf("Help messages and neutral responses appear in yellow\n\r");
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("System parameters and affirmative responses appear in green\n\r");
    terminalTextAttributes(CYAN, BLACK, NORMAL);
    printf("Measurement responses and WiFi responses appear in cyan\n\r");
    terminalTextAttributes(RED, BLACK, NORMAL);
    printf("Errors and negative responses appear in red\n\r");
    terminalTextAttributesReset();
    printf("User input appears in white\n\r");
         
}

// This function returns a string of a large number of seconds in a human readable format
char * getStringSecondsAsTime(uint32_t input_seconds) {
 
    uint32_t years, days, hours, minutes, seconds, remainder;
    static char return_string[80];
    
    // clear return string
    int i;
    for (i = 0; i < strlen(return_string); i++) {
     
        return_string[i] = '\0';
        
    }
    
    char buff[20];
    
    years = input_seconds / (60 * 60 * 24 * 365);
    input_seconds -= years * (60 * 60 * 24 * 365);
    days = input_seconds / (60 * 60 * 24);
    input_seconds -= days * (60 * 60 * 24);
    hours = input_seconds / (60 * 60);
    input_seconds -= hours * (60 * 60);
    minutes = input_seconds / 60;
    input_seconds -= minutes * 60;
    seconds = input_seconds;
    
    if (years > 0) {
        
        if (years == 1) {
         
            sprintf(buff, "%d year, ", years);
            
        }
        
        else {
         
            sprintf(buff, "%d years, ", years);
            
        }
        
        strcat(return_string, buff);
        
    }
    
    if (days > 0) {
     
        if (days == 1) {
         
            sprintf(buff, "%d day, ", days);
            
        }
        
        else {
         
            sprintf(buff, "%d days, ", days);
            
        }
        
        strcat(return_string, buff);
    }
    
    if (hours > 0) {
     
        if (hours == 1) {
         
            sprintf(buff, "%d hour, ", hours);
            
        }
        
        else {
         
            sprintf(buff, "%d hours, ", hours);
            
        }
        
        strcat(return_string, buff);
        
    }
    
    if (minutes > 0) {
     
        if (minutes == 1) {
         
            sprintf(buff, "%d minute, ", minutes);
            
        }
        
        else {
         
            sprintf(buff, "%d minutes, ", minutes);
            
        }
        
        strcat(return_string, buff);
        
    }
    
    if (seconds > 0) {
     
        if (seconds == 1) {
         
            sprintf(buff, "%d second", seconds);
            
        }
        
        else {
         
            sprintf(buff, "%d seconds", seconds);
            
        }
        
        strcat(return_string, buff);
        
    }
    
    return return_string;
    
}

// This function compares the "needle" string parameter to see if it is the 
// beginning of the "haystack" string variable
// Returns 0 for success, 1 for failure
uint8_t strstart(const char * haystack, const char * needle) {
 
    // First check to see if needle is longer than haystack, if it is 
    // we already know this is not a match
    if (strlen(needle) >= strlen(haystack)) return 1;
    
    // Next loop through each element in needle to see if it matches the 
    // same character in haystack at the same position
    // If the characters do not match, return 1
    // After the loop, return 0 for exit success
    uint8_t char_index;
    for(char_index = 0; char_index < strlen(needle); char_index++) {
        
        // Return a 1 if there is not a match
        if (needle[char_index] != haystack[char_index]) return 1;
        
    }
    
    // return a 0 for exit success
    return 0;
    
}
