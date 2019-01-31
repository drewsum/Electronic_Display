
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
#include "error_handler.h"
#include "cause_of_reset.h"


// Text attribute enums
text_attribute_t attribute;
text_color_t foreground_color;
text_color_t background_color;

volatile uint32_t usb_uart_TxHead = 0;
volatile uint32_t usb_uart_TxTail = 0;
volatile uint32_t usb_uart_TxBuffer[USB_UART_TX_BUFFER_SIZE];
volatile uint32_t usb_uart_TxBufferRemaining;

volatile uint32_t usb_uart_RxHead = 0;
volatile uint32_t usb_uart_RxTail = 0;
volatile uint32_t usb_uart_RxBuffer[USB_UART_RX_BUFFER_SIZE];
volatile uint32_t usb_uart_RxCount;

volatile uint8_t usb_uart_RxStringReady = 0;

// Printable Variables from other header files
extern uint32_t device_on_time_counter;
extern reset_cause_t reset_cause;



// This function initializes UART 6 for USB debugging
void USB_UART_Initialize(void) {
 
    // Disable UART 3 interrupts
//    disableInterrupt(UART3_Receive_Done);
//    disableInterrupt(UART3_Transfer_Done);
//    disableInterrupt(UART3_Fault);
    
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
    setInterruptPriority(UART3_Transfer_Done, 3);
    setInterruptPriority(UART3_Fault, 1);
    
    // Set interrupt subpriorities
    setInterruptSubpriority(UART3_Receive_Done, 2);
    setInterruptSubpriority(UART3_Transfer_Done, 2);
    setInterruptSubpriority(UART3_Fault, 1);
    
    // Clear all UART 3 Interrupts
    clearInterruptFlag(UART3_Receive_Done);
    clearInterruptFlag(UART3_Transfer_Done);
    clearInterruptFlag(UART3_Fault);
    
    // Enable receive and error interrupts
    // Transfer interrupt is set in write function
    enableInterrupt(UART3_Receive_Done);
    enableInterrupt(UART3_Fault);
        
    // Enable UART 3
    U3MODEbits.ON = 1;
    
    // Clear the terminal
    USB_UART_clearTerminal();
    USB_UART_setCursorHome();
    
}

// This is the USB UART receive interrupt service routine
void __ISR(_UART3_RX_VECTOR, ipl2AUTO) USB_UART_Receive_ISR(void) {
    
    // Do receive tasks
    USB_UART_Receive_Handler();
    
    // Clear receive interrupt flag
    clearInterruptFlag(UART3_Receive_Done);
    
}

// This is the USB UART transfer interrupt service routine
void __ISR(_UART3_TX_VECTOR, ipl3AUTO) USB_UART_Transfer_ISR(void) {
    
    // Do transfer tasks
    USB_UART_Transmit_Handler();
    
    // Clear interrupt flag
    clearInterruptFlag(UART3_Transfer_Done);
    
}

// This is the UAB UART fault interrupt service routine
void __ISR(_UART3_FAULT_VECTOR, ipl1AUTO) USB_UART_Fault_ISR(void) {
    
    // TO-DO: Fault tasks
    error_handler.USB_error_flag = 1;
    
    // Clear fault interrupt flag
    clearInterruptFlag(UART3_Fault);
    
}

// This function pulls a byte from the RX ring buffer
uint8_t USB_UART_Read_Byte(void) {
 
    uint8_t readValue  = 0;
    
    // This state should never be entered
    while(0 == usb_uart_RxCount)
    {
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
void USB_UART_putchar(uint8_t txData) {
 
     while(0 == usb_uart_TxBufferRemaining)
    {
    }

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
void USB_UART_Transmit_Handler(void) {
 
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
void USB_UART_Receive_Handler(void) {
            
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
    
    // Empty hardware FIFO
//    int dummy;
//    while(U3STAbits.URXDA) {
//                 
//        dummy = U3RXREG;
//                    
//    }
    
    
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
        USB_UART_print("\033[K");
        
        if(usb_uart_RxHead != usb_uart_RxTail) {
        
            usb_uart_RxBuffer[usb_uart_RxHead - 1] = '\0';
            usb_uart_RxHead--;

        }
        
    }
    
}

// This function prints strings on the terminal 
void USB_UART_print(char charArray[]) {
    
    int i;
    for (i = 0; i <= strlen(charArray); i++) {
     
        USB_UART_putchar(charArray[i]);
        
    }
    
}

// This function redirects stdout to USB_UART output, allowing printf functionality
void _mon_putc(char c) {
 
    USB_UART_putchar(c);
    
}


// This function pulls data out of the RX ring buffer
void USB_UART_ringBufferPull(void) {

    int charNumber = usb_uart_RxCount;
            
    // Clear line buffer
    uint16_t index;
    for (index = 0; index < USB_UART_RX_BUFFER_SIZE; index++) {

        USB_UART_line[index] = '\0';

    }

    // Fill line from ring buffer
    index = 0;
    for(index = 0; index < charNumber; index++){

        USB_UART_line[index] = USB_UART_Read_Byte();

    }

    // Reset ring buffer
    usb_uart_RxTail = usb_uart_RxHead;

    // Try to kill off ending returns/newlines
    while((USB_UART_line[strlen(USB_UART_line) - 1] == (int) '\n') ||
          (USB_UART_line[strlen(USB_UART_line) - 1] == (int) '\r')) {
     
        // NULL
        USB_UART_line[strlen(USB_UART_line) - 1] = '\0';
        
    }
    

    // Clear ready flag
    usb_uart_RxStringReady = 0;

    // Check to see if line matches a command
    USB_UART_ringBufferLUT(USB_UART_line);

    
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
void USB_UART_ringBufferLUT(char * line_in) {
 
    // THIS IS WHERE WE DO THE ACTUAL PARSING OF RECEIVED STRING AND
    // ACT ON IT

    if (strcmp(line_in, "Reset") == 0) {

        deviceReset();
        
    }
    
    else if (strcmp(line_in, "Clear") == 0) {
     
        USB_UART_clearTerminal();
        USB_UART_setCursorHome();
        
    }
    
    else if (strcmp(line_in, "*IDN?") == 0) {
     
        // USB_UART_putchar(2);
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(GREEN, BLACK, NORMAL);
        USB_UART_print("E44 Electronic Display Logic Board\n\r");
        USB_UART_textAttributesReset();
        
    }
    
    else if (strcmp(line_in, "Device On Time?") == 0) {
     
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(GREEN, BLACK, NORMAL);
        USB_UART_print("On time since last device reset: ");
        USB_UART_print(getStringSecondsAsTime(device_on_time_counter));
        USB_UART_printNewline();
        USB_UART_textAttributesReset();
        
    }
    
    else if (strcmp(line_in, "PMD Status?") == 0) {
     
        USB_UART_textAttributesReset();
        printPMDStatus();
        USB_UART_textAttributesReset();
        USB_UART_printNewline();
        
    }
    
    else if (strcmp(line_in, "WDT Status?") == 0) {
     
        USB_UART_textAttributesReset();
        printWatchdogStatus();
        USB_UART_textAttributesReset();
        USB_UART_printNewline();
        
    }
    
    else if (strcmp(line_in, "DMT Status?") == 0) {
     
        USB_UART_textAttributesReset();
        printDeadmanStatus();
        USB_UART_textAttributesReset();
        USB_UART_printNewline();

    }
    
    else if (strcmp(line_in, "Interrupt Status?") == 0) {
     
        USB_UART_textAttributesReset();
        printInterruptStatus();
        USB_UART_textAttributesReset();
        USB_UART_printNewline();
        
    }
    
    else if (strcmp(line_in, "Cause of Reset?") == 0) {
     
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(GREEN, BLACK, NORMAL);
        USB_UART_print("Cause of the most recent device reset: ");
        USB_UART_print(getResetCauseString(reset_cause));
        USB_UART_printNewline();
        USB_UART_textAttributesReset();
        USB_UART_printNewline();
        
    }
    
    else if (strcmp(line_in, "Print Test Message") == 0) {
        
        USB_UART_printTestMessage();
        
    }
    
    else if (strcmp(line_in, "Credits") == 0) {
     
        USB_UART_printNewline();
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(YELLOW, BLUE, BOLD);
        USB_UART_print("Marquette Senior Design 2018-2019\n\r");
        USB_UART_textAttributesReset();
        USB_UART_printNewline();
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(YELLOW, BLUE, BOLD);
        USB_UART_print("Team E44: Electronic Display Display\n\r");
        USB_UART_textAttributesReset();
        USB_UART_printNewline();
        USB_UART_textAttributes(BLACK, WHITE, NORMAL);
        USB_UART_print("Hardware Design/Embedded Firmware:\n\r");
        USB_UART_textAttributes(CYAN, BLACK, NORMAL);
        USB_UART_print("Logan Wedel\n\r");
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(YELLOW, BLACK, NORMAL);
        USB_UART_print("Caroline Gilger\n\r");
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(RED, BLACK, NORMAL);
        USB_UART_print("Drew Maatman\n\r");
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(BLACK, WHITE, NORMAL);
        USB_UART_print("App Design/Integration:\n\r");
        USB_UART_textAttributes(GREEN, BLACK, NORMAL);
        USB_UART_print("Kevin Etta\n\r");
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(MAGENTA, BLACK, NORMAL);
        USB_UART_print("Tuoxuan Ren\n\r");
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(BLACK, WHITE, NORMAL);
        USB_UART_print("Mentor:\n\r");
        USB_UART_textAttributesReset();
        USB_UART_print("Cris Ababei\n\r");
        USB_UART_printNewline();
        
    }
    
    else if (strcmp(line_in, "Help") == 0) {
    
        USB_UART_printHelpMessage();
        
    }
    
    else if (strcmp(line_in, "POS5 Enable") == 0) {
     
        POS5_RUN_PIN = 1;
        
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(GREEN, BLACK, NORMAL);
        USB_UART_print("POS5 RUN Asserted\n\r");
        USB_UART_textAttributesReset();
        
    }
    
    else if (strcmp(line_in, "POS5 Disable") == 0) {
     
        POS5_RUN_PIN = 0;
        
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(RED, BLACK, NORMAL);
        USB_UART_print("POS5 RUN Deasserted\n\r");
        USB_UART_textAttributesReset();
        
    }
    
    else if (strcmp(line_in, "POS5P Enable") == 0) {
     
        POS5P_RUN_PIN = 1;
        
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(GREEN, BLACK, NORMAL);
        USB_UART_print("POS5P RUN Asserted\n\r");
        USB_UART_textAttributesReset();
        
    }
    
    else if (strcmp(line_in, "POS5P Disable") == 0) {
     
        POS5P_RUN_PIN = 0;
        
        USB_UART_textAttributesReset();
        USB_UART_textAttributes(RED, BLACK, NORMAL);
        USB_UART_print("POS5P RUN Deasserted\n\r");
        USB_UART_textAttributesReset();
        
    }
    
    
}

// This function clears the terminal
void USB_UART_clearTerminal(void) {
    USB_UART_print("\033[2J");
}

// This function moves the terminal cursor to top left corner
void USB_UART_setCursorHome(void) {
    USB_UART_print("\033[H");
}

// This function clears the line the cursor is currently at on the terminal
void USB_UART_clearLine(void) {
    USB_UART_print("\033[K");
}

// This function saves the current cursor position on the terminal
void USB_UART_saveCursor(void) {
    USB_UART_print("\033[s");
}

// This function returns the cursor to saved position on terminal
void USB_UART_returnCursor(void) {
    USB_UART_print("\033[u");
}

// Text attributes function
// See attributes enums in "USB_UART.h"
// Call like so:
/*

    USB_UART_textAttributes(<TEXT COLOR (ALL CAPS)>, 
                            <BACKGROUND COLOR (ALL CAPS)>, 
                            <TEXT EFFECT (ALL CAPS)>);

*/

void USB_UART_textAttributes(text_color_t foreground_color,
        text_color_t background_color,
        text_attribute_t input_attribute) {
    
    strncpy(output_buff, "\033[", sizeof(output_buff));
    
    switch (input_attribute) {
     
        case NORMAL:
            strcat(output_buff,"0"); 
            break;
        case BOLD:
            strcat(output_buff,"1");
            break;
        case UNDERSCORE:
            strcat(output_buff,"4");
            break;
        case BLINK:
            strcat(output_buff,"5");
            break;
        case REVERSE:
            strcat(output_buff,"7");
            break;
        case CONCEALED:
            strcat(output_buff,"8");
            break;

        default:
            strcat(output_buff,"0");
            break;
    }
    
    strcat(output_buff,";");
    
    switch (foreground_color) {
     
        case BLACK:
            strcat(output_buff,"30");
            break;
        case RED:
            strcat(output_buff,"31");
            break;
        case GREEN:
            strcat(output_buff,"32");
            break;
        case YELLOW:
            strcat(output_buff,"33");
            break;
        case BLUE:
            strcat(output_buff,"34");
            break;
        case MAGENTA:
            strcat(output_buff,"35");
            break;
        case CYAN:
            strcat(output_buff,"36");
            break;
        case WHITE:
            strcat(output_buff,"37");
            break;
            
        default:
            strcat(output_buff,"37");
            break;
    }
    
    strcat(output_buff,";");
    
    switch (background_color) {
     
        case BLACK:
            strcat(output_buff,"40");
            break;
        case RED:
            strcat(output_buff,"41");
            break;
        case GREEN:
            strcat(output_buff,"42");
            break;
        case YELLOW:
            strcat(output_buff,"43");
            break;
        case BLUE:
            strcat(output_buff,"44");
            break;
        case MAGENTA:
            strcat(output_buff,"45");
            break;
        case CYAN:
            strcat(output_buff,"46");
            break;
        case WHITE:
            strcat(output_buff,"47");
            break;
            
        default:
            strcat(output_buff,"47");
            break;
    }
    
    strcat(output_buff,"m");
    
    USB_UART_print(output_buff);
}

// Reset text attributes to white text, black background, no effects
void USB_UART_textAttributesReset(void) {
 
    USB_UART_textAttributes(WHITE, BLACK, NORMAL);
    
}

// Print newline on terminal
void USB_UART_printNewline(void) {

    USB_UART_print("\n\r");
    
}

// Print help message, used in a command above
void USB_UART_printHelpMessage(void) {
 
    usb_uart_TxHead = 0;
    usb_uart_TxTail = 0;   

    
    USB_UART_textAttributesReset();
    USB_UART_textAttributes(YELLOW, BLACK, NORMAL);
    USB_UART_print("Supported Commands:\n\r");
    USB_UART_print("    Reset: Software Reset\n\r");
    USB_UART_print("    Clear: Clears the terminal\n\r");
    USB_UART_print("    Cause of Reset?: Prints the cause of the most recent device reset\n\r");
    USB_UART_print("    *IDN?: Prints identification string\n\r");
    USB_UART_print("    Device On Time?: Returns the device on time since last reset\n\r");
    USB_UART_print("    PMD Status?: Prints the state of Peripheral Module Disable settings\n\r");
    USB_UART_print("    WDT Status?: Prints the state of the watchdog timer\n\r");
    USB_UART_print("    DMT Status?: Prints the state of the deadman timer\n\r");
    USB_UART_print("    Interrupt Status?L Prints information on interrupt settings\n\r");
    USB_UART_print("    POS5 Enable: Turns on the on board +5V Power Supply for level shifters\n\r");
    USB_UART_print("    POS5 Disable: Turns off the on board +5V Power Supply for level shifters\n\r");
    USB_UART_print("    POS5P Enable: Turns on the external +5V Power Supply for LED panels\n\r");
    USB_UART_print("    POS5P Disable: Turns off the external +5V Power Supply for LED panels\n\r");
//     USB_UART_print("    Enable Muxing: enables the multiplexing timer \n\r");
//     USB_UART_print("    Disable Muxing: disable the multiplexing timer \n\r");

    USB_UART_print("    Print Test Message: Print out terminal test data\n\r");
    USB_UART_print("    Credits: Displays creators\n\r");
    USB_UART_print("    Help: This Command\n\r");
//    USB_UART_print("    Set Red: Sets panels red\n\r");
//    USB_UART_print("    Set White: Sets panels white\n\r");    
//    USB_UART_print("    Set Blue: Sets panels blue\n\r");
//    USB_UART_print("    Set Yellow: Sets panels yellow\n\r");
//    USB_UART_print("    Set Cyan: Sets panels cyan\n\r");    
//    USB_UART_print("    Set Green: Sets panels green\n\r");    
//    USB_UART_print("    Set Magenta: Sets panels magenta\n\r");    
//    USB_UART_print("    Set MU Logo: Sets panel as MU Logo static image\n\r");
//    USB_UART_print("    Set Rand: Sets panel to random data\n\r");
//    USB_UART_print("    Set Every Other Red: Fills ram buffer with stripes of red\n\r");
//    USB_UART_print("    Set Every Other Blue: Fills ram buffer with stripes of blue\n\r");
//    USB_UART_print("    Set Every Other Green: Fills ram buffer with stripes of green\n\r");
//    USB_UART_print("    Set Christmas Stripes: Fills ram buffer with christmas stripes\n\r");
//    USB_UART_print("    Set RGB Stripes: Fills ram buffer with stripes of rgb\n\r");
//    USB_UART_print("    Set Red Rows: Fills ram buffer with red rows\n\r");
//    USB_UART_print("    Slow Muxing Speed: Slows down multiplexing\n\r");
//    USB_UART_print("    Slowest Muxing Speed: Slows down muxing speed extremely\n\r");
//    USB_UART_print("    Reset Muxing Speed: Resets to faster multiplexing speed\n\r");
    
     
    USB_UART_print("Help messages and neutral responses appear in yellow\n\r");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    USB_UART_print("System parameters and affirmative responses appear in green\n\r");
    USB_UART_textAttributes(CYAN, BLACK, NORMAL);
    USB_UART_print("Measurement responses appear in cyan\n\r");
    USB_UART_textAttributes(RED, BLACK, NORMAL);
    USB_UART_print("Errors and negative responses appear in red\n\r");
    USB_UART_textAttributesReset();
    USB_UART_print("User input appears in white\n\r");
        
    // Get some space on terminal
    USB_UART_printNewline();
     
}

// tests all the function written for this example
void USB_UART_printTestMessage(void) {
    
    // Set starting text color white, background black, no fancy stuff
    // Print COM port settings
    USB_UART_textAttributesReset();
    USB_UART_clearTerminal();
    USB_UART_setCursorHome();
    USB_UART_print("USB UART Test\n\r");
    USB_UART_printNewline();
    USB_UART_print("COM Port Settings:\n\r");
    USB_UART_print("    Baud Rate: ");
    USB_UART_print(USB_UART_BAUD_RATE_STR);
    USB_UART_printNewline();
    USB_UART_print("    Data Length: ");
    USB_UART_print(USB_UART_DATA_LENGTH_STR);
    USB_UART_printNewline();
    USB_UART_print("    Parity: ");
    USB_UART_print(USB_UART_PARITY_STR);
    USB_UART_printNewline();
    USB_UART_print("    Stop Bits: ");
    USB_UART_print(USB_UART_STOP_BITS_STR);
    USB_UART_printNewline();
    USB_UART_print("    Flow Control: ");
    USB_UART_print(USB_UART_FLOW_CONTROL_STR);
    USB_UART_printNewline();
        
    // Test text attributes
    USB_UART_printNewline();
    USB_UART_print("Testing text attributes:\n\r");

    // Print some black text
    USB_UART_textAttributesReset();
    USB_UART_textAttributes(BLACK, WHITE, NORMAL);
    USB_UART_print("This text is black\n\r");

    USB_UART_textAttributesReset();
    USB_UART_textAttributes(RED, BLACK, NORMAL);
    USB_UART_print("This text is red\n\r");

    USB_UART_textAttributesReset();
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    USB_UART_print("This text is green\n\r");

    USB_UART_textAttributesReset();
    USB_UART_textAttributes(YELLOW, BLACK, NORMAL);
    USB_UART_print("This text is yellow\n\r");

    USB_UART_textAttributesReset();
    USB_UART_textAttributes(BLUE, WHITE, NORMAL);
    USB_UART_print("This text is blue\n\r");

    USB_UART_textAttributesReset();
    USB_UART_textAttributes(MAGENTA, BLACK, NORMAL);
    USB_UART_print("This text is magenta\n\r");

    USB_UART_textAttributesReset();
    USB_UART_textAttributes(CYAN, BLACK, NORMAL);
    USB_UART_print("This text is cyan\n\r");
    
    USB_UART_textAttributesReset();
    USB_UART_textAttributes(WHITE, BLACK, NORMAL);
    USB_UART_print("This text has a black background\n\r");
    
    USB_UART_textAttributesReset();
    USB_UART_textAttributes(BLACK, RED, NORMAL);
    USB_UART_print("This text has a red background\n\r");

    USB_UART_textAttributesReset();
    USB_UART_textAttributes(BLACK, GREEN, NORMAL);
    USB_UART_print("This text has a green background\n\r");
    
    USB_UART_textAttributesReset();
    USB_UART_textAttributes(BLACK, YELLOW, NORMAL);
    USB_UART_print("This text has a yellow background\n\r");
    
    USB_UART_textAttributesReset();
    USB_UART_textAttributes(WHITE, BLUE, NORMAL);
    USB_UART_print("This text has a blue background\n\r");
    
    USB_UART_textAttributesReset();
    USB_UART_textAttributes(BLACK, MAGENTA, NORMAL);
    USB_UART_print("This text has a magenta background\n\r");
    
    USB_UART_textAttributesReset();
    USB_UART_textAttributes(BLACK, CYAN, NORMAL);
    USB_UART_print("This text has a cyan background\n\r");
    
    USB_UART_textAttributesReset();
    USB_UART_textAttributes(BLACK, WHITE, NORMAL);
    USB_UART_print("This text has a white background\n\r");
    
    USB_UART_textAttributesReset();
    USB_UART_textAttributes(WHITE, BLACK, BOLD);
    USB_UART_print("This text is bold\n\r");

    USB_UART_textAttributesReset();
    USB_UART_textAttributes(WHITE, BLACK, UNDERSCORE);
    USB_UART_print("This text is underscored\n\r");

    USB_UART_textAttributesReset();
    USB_UART_textAttributes(WHITE, BLACK, BLINK);
    USB_UART_print("This text is blinking\n\r");

    USB_UART_textAttributesReset();
    USB_UART_textAttributes(WHITE, BLACK, REVERSE);
    USB_UART_print("This text is reversed\n\r");

    USB_UART_textAttributesReset();
    USB_UART_print("This text is normal\n\r");
    
    USB_UART_printNewline();
    
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    USB_UART_print("Finished test message, type 'Help' for list of commands\n\r");
    USB_UART_textAttributesReset();
    
    USB_UART_printNewline();
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
