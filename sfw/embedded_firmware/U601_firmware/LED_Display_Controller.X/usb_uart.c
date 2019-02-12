
#include <xc.h>
#include <string.h>
#include <stdio.h>


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

#include "nfl_logo.h"

volatile uint64_t usb_uart_TxHead = 0;
volatile uint64_t usb_uart_TxTail = 0;
volatile uint8_t usb_uart_TxBuffer[USB_UART_TX_BUFFER_SIZE];
volatile uint64_t usb_uart_TxBufferRemaining;

volatile uint32_t usb_uart_RxHead = 0;
volatile uint32_t usb_uart_RxTail = 0;
volatile uint32_t usb_uart_RxBuffer[USB_UART_RX_BUFFER_SIZE];
volatile uint32_t usb_uart_RxCount;

volatile uint8_t usb_uart_RxStringReady = 0;

// Printable Variables from other header files
extern uint32_t device_on_time_counter;
extern reset_cause_t reset_cause;



// This function initializes UART 6 for USB debugging
void usbUartInitialize(void) {
 
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
    setInterruptPriority(UART3_Transfer_Done, 7);
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
            
    // Enable receive and error interrupts
    // Transfer interrupt is set in write function
    enableInterrupt(UART3_Receive_Done);
    enableInterrupt(UART3_Fault);
    
}

// This is the USB UART receive interrupt service routine
void __ISR(_UART3_RX_VECTOR, ipl2SRS) usbUartReceiveISR(void) {
    
    // Do receive tasks
    usbUartReceiveHandler();
    
    // Clear receive interrupt flag
    clearInterruptFlag(UART3_Receive_Done);
    
}

// This is the USB UART transfer interrupt service routine
void __ISR(_UART3_TX_VECTOR, ipl7SRS) usbUartTransferISR(void) {
    
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
        
    }
    
    
}


// This serves as the RX handler and is called by the RX ISR
void usbUartReceiveHandler(void) {
            
    if(1 == U3STAbits.OERR)
    {
        U3MODEbits.ON = 0;
        error_handler.USB_error_flag = 1;
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
    
    else if (strcmp(line_in, "WDT Status?") == 0) {
     
        printWatchdogStatus();
        
    }
    
    else if (strcmp(line_in, "DMT Status?") == 0) {
     
        printDeadmanStatus();

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
    
    else if (strcmp(line_in, "Prefetch Status?") == 0) {
     
        printPrefetchStatus();

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
        printf("Clearing EBI SRAM\n\r");
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "Print EBI SRAM Contents") == 0) {
     
        terminalTextAttributesReset();
        ebiPrintSRAM();
        terminalTextAttributesReset();
        
    }
    
    // Identification command
    else if(strcmp(line_in, "Enable Muxing") == 0) {
     
        // Disable multiplexing timer
        panelMultiplexingTimerStart();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Panel multiplexing Enabled\n\r");
        terminalTextAttributesReset();
        
    }
    
    // disable multiplexing
    else if(strcmp(line_in, "Disable Muxing") == 0) {
    
        // Suspend panel multiplexing, clear all panel IO signals
        panelMultiplexingSuspend();
        
        
        terminalTextAttributesReset();
        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("Panel multiplexing Disabled\n\r");
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
    
    // set ram buffer every other red
    else if(strcmp(line_in, "Set Every Other Red") == 0) {
     
        fillRamBufferEveryOtherRed();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with stripes of red\n\r");
        terminalTextAttributesReset();
        
    }     
    
    
    // set ram buffer every other blue
    else if(strcmp(line_in, "Set Every Other Blue") == 0) {
     
        fillRamBufferEveryOtherBlue();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with stripes of blue\n\r");
        terminalTextAttributesReset();
        
    }
    
    // set ram buffer every other green
    else if(strcmp(line_in, "Set Every Other Green") == 0) {
     
        fillRamBufferEveryOtherGreen();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with stripes of green\n\r");
        terminalTextAttributesReset();
        
    }
    
    // set ram buffer to christmas stripes
    else if(strcmp(line_in, "Set Christmas Stripes") == 0) {
     
        fillRamBufferChristmas();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with christmas stripes\n\r");
        terminalTextAttributesReset();
        
    }    
    
    
    // set ram buffer to RGB pattern
    else if(strcmp(line_in, "Set RGB Stripes") == 0) {
     
        fillRamBufferRGBStripes();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with rgb stripes\n\r");
        terminalTextAttributesReset();
        
    }  

    // set ram buffer to red rows
    else if(strcmp(line_in, "Set Red Rows") == 0) {
     
        fillRamBufferRedRow();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with red rows\n\r");
        terminalTextAttributesReset();
        
    }
    
    // set ram buffer to red rows
    else if(strcmp(line_in, "Set NFL Logo") == 0) {
     
        fillRamBufferNFL();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Ram buffer filled with NFL logo\n\r");
        terminalTextAttributesReset();
        
    }
    
    // slow down multiplexing command
    else if(strcmp(line_in, "Slow Muxing Speed") == 0) {
     
        PR5 = 65535;                      
        T5CONbits.TCKPS = 0b001;        // set prescale to 2
        
        terminalTextAttributesReset();
        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("Slowed down the multiplexing speed\n\r");
        terminalTextAttributesReset();
        
    }
    
    // slow down multiplexing command
    else if(strcmp(line_in, "Slowest Muxing Speed") == 0) {
     
        PR5 = 65535;                      
        T5CONbits.TCKPS = 0b100;        // set prescale to 16

        terminalTextAttributesReset();
        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("Slowed down the multiplexing speed extreme\n\r");
        terminalTextAttributesReset();
        
    }
    
    // reset multiplexing command
    else if(strcmp(line_in, "Reset Muxing Speed") == 0) {
     
        PR5 = 250;                      
        T5CONbits.TCKPS = 0b000;        // set prescale to 1
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Reset multiplexing speed\n\r");
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
    
    else if (strcmp(line_in, "Serial Number?") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("PIC32MZ Serial Number retrieved from Flash: %s\n\r",
                getStringSerialNumber());
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "Device ID?") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Device ID retrieved from Flash: %s (0x%X)\n\r", 
                getDeviceIDString(getDeviceID()), 
                getDeviceID());
        terminalTextAttributesReset();        
                
    }
    
    else if (strcmp(line_in, "Revision ID?") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Revision ID retrieved from Flash: %s (0x%X)\n\r", 
                getRevisionIDString(getRevisionID()), 
                getRevisionID());
        terminalTextAttributesReset();        
        
        
    }
    
    else if (strcmp(line_in, "Print Test Message") == 0) {
        
        terminalPrintTestMessage();
        
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
    
    else if (strcmp(line_in, "ADC Raw Data?") == 0) {
    
        terminalTextAttributesReset();
        terminalTextAttributes(CYAN, BLACK, NORMAL);
        printf("Most recent raw 12 bit ADC conversions:\n\r");
        printf("    +3.3V Raw ADC Conversion Result: 0x%08X\n\r", adc_results.POS3P3_adc_raw);
        printf("    +12V Raw ADC Conversion Result: 0x%08X\n\r", adc_results.POS12_adc_raw);
        printf("    +5.5V Raw ADC Conversion Result: 0x%08X\n\r", adc_results.POS5P5_adc_raw);
        printf("    +5V Raw ADC Conversion Result: 0x%08X\n\r", adc_results.POS5_adc_raw);
        printf("    +5VP Raw ADC Conversion Result: 0x%08X\n\r", adc_results.POS5P_adc_raw);
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "ADC Results?") == 0) {
     
        if (error_handler.ADC_configuration_error_flag) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(BLACK, BLACK, NORMAL);
            printf("ADC Configuration Error\n\r");
            terminalTextAttributesReset();
            
        }
        
        else {

            terminalTextAttributesReset();
            terminalTextAttributes(CYAN, BLACK, NORMAL);
            printf("Most recent ADC conversion results:\n\r");
            printf("    +12V Input Voltage Measurement: %0.3f V\n\r", adc_results.POS12_adc);
            printf("    +3.3V Power Supply Measurement: %0.3f V\n\r", adc_results.POS3P3_adc);
            printf("    +5V Power Supply Measurement: %0.3f V\n\r", adc_results.POS5_adc);
            printf("    +5.5V Linear Regulator Measurement: %0.3f V\n\r", adc_results.POS5P5_adc);
            printf("    +5VP LED Power Supply Measurement: %0.3f V\n\r", adc_results.POS5P_adc);
            terminalTextAttributesReset();

        }
            
    }
    
    else if (strcmp(line_in, "ADC Max Results?") == 0) {
     
        if (error_handler.ADC_configuration_error_flag) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(BLACK, BLACK, NORMAL);
            printf("ADC Configuration Error\n\r");
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
            terminalTextAttributesReset();

        }
            
    }
    
    else if (strcmp(line_in, "ADC Min Results?") == 0) {
     
        if (error_handler.ADC_configuration_error_flag) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(BLACK, BLACK, NORMAL);
            printf("ADC Configuration Error\n\r");
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
            terminalTextAttributesReset();

        }
            
    }
    
    else if (strcmp(line_in, "ADC Status?") == 0) {
     
        printADCStatus();
        
    }
    
    else if (strcmp(line_in, "Help") == 0) {
    
        usbUartPrintHelpMessage();
        
    }
    
    else if (strcmp(line_in, "POS5 Enable") == 0) {
     
        POS5_RUN_PIN = 1;
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("POS5 RUN Asserted\n\r");
        terminalTextAttributesReset();
              
    }
    
    else if (strcmp(line_in, "POS5 Disable") == 0) {
     
        POS5_RUN_PIN = 0;
        
        terminalTextAttributesReset();
        terminalTextAttributes(RED, BLACK, NORMAL);
        printf("POS5 RUN Deasserted\n\r");
        terminalTextAttributesReset();
        
    }
    
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
    printf("    Device On Time?: Returns the device on time since last reset\n\r");
    printf("    PMD Status?: Prints the state of Peripheral Module Disable settings\n\r");
    printf("    WDT Status?: Prints the state of the watchdog timer\n\r");
    printf("    DMT Status?: Prints the state of the deadman timer\n\r");
    printf("    Prefetch Status?: Prints the status of the predictive prefetch module\n\r");
    printf("    EBI Status?: Prints status of EBI configuration\r\n");
    printf("    Test EBI SRAM: Tests writing to and reading from external EBI SRAM\n\r");
    printf("    Print EBI SRAM Contents: Prints the data saved in EBI SRAM\n\r");
    printf("    Clear EBI SRAM: Resets all bytes within EBI SRAM to 0x00\n\r");
    printf("    SPI Status?: Prints the SPI configuration bits\n\r");
    printf("    Interrupt Status? Prints information on interrupt settings\n\r");
    printf("    Clock Status?: Prints system clock settings\n\r");
    printf("    Error Status?: Prints the state of system error flags\n\r");
    printf("    Clear Errors: Clears all error handler flags\n\r");
    printf("    Serial Number?: Prints device serial number\n\r");
    printf("    Device ID?: Returns part number and PIC32MZ Device ID\n\r");
    printf("    Revision ID?: Prints silicon die revision ID\n\r");
    printf("    ADC Results?: Prints results of the most recent ADC conversions for system power supplies\n\r");
    printf("    ADC Max Results?: prints the maximum recorded value for each ADC channel\n\r");
    printf("    ADC Min Results?: prints the minimum recorded value for each ADC channel\n\r");
    printf("    ADC Raw Data?: Prints the raw 12 bit results of the ADC conversions\n\r");
    printf("    ADC Status?: Prints information about analog to digital converter settings\n\r");
    printf("    POS5 Enable: Turns on the on board +5V Power Supply for level shifters\n\r");
    printf("    POS5 Disable: Turns off the on board +5V Power Supply for level shifters\n\r");
    printf("    POS5P Enable: Turns on the external +5V Power Supply for LED panels\n\r");
    printf("    POS5P Disable: Turns off the external +5V Power Supply for LED panels\n\r");
    printf("    Enable Muxing: enables the multiplexing timer \n\r");
    printf("    Disable Muxing: disable the multiplexing timer \n\r");
    printf("    Print Test Message: Print out terminal test data\n\r");
    printf("    Credits: Displays creators\n\r");
    printf("    Help: This Command\n\r");
    printf("    Set Red: Sets all pixels in display red\n\r");
    printf("    Set White: Sets all pixels in display white\n\r");    
    printf("    Set Blue: Sets all pixels in display blue\n\r");
    printf("    Set Yellow: Sets all pixels in display yellow\n\r");
    printf("    Set Cyan: Sets all pixels in display cyan\n\r");    
    printf("    Set Green: Sets all pixels in display green\n\r");    
    printf("    Set Magenta: Sets all pixels in display magenta\n\r");    
//    printf("    Set MU Logo: Sets panel as MU Logo static image\n\r");
    printf("    Set NFL Logo: Loads EBI SRAM with data for the NFL logo\n\r");
    printf("    Set Rand: Sets pixels to display random data\n\r");
    printf("    Set Every Other Red: Fills ram buffer with stripes of red\n\r");
    printf("    Set Every Other Blue: Fills ram buffer with stripes of blue\n\r");
    printf("    Set Every Other Green: Fills ram buffer with stripes of green\n\r");
    printf("    Set Christmas Stripes: Fills ram buffer with christmas stripes\n\r");
    printf("    Set RGB Stripes: Fills ram buffer with stripes of rgb\n\r");
    printf("    Set Red Rows: Fills ram buffer with red rows\n\r");
    printf("    Slow Muxing Speed: Slows down multiplexing\n\r");
    printf("    Slowest Muxing Speed: Slows down muxing speed extremely\n\r");
    printf("    Reset Muxing Speed: Resets to faster multiplexing speed\n\r");
    
    
    printf("\n\rUSB Debug messages may appear broken when panel multiplexing is enabled\n\r");
    printf("Help messages and neutral responses appear in yellow\n\r");
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("System parameters and affirmative responses appear in green\n\r");
    terminalTextAttributes(CYAN, BLACK, NORMAL);
    printf("Measurement responses appear in cyan\n\r");
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
