
#include <xc.h>
#include <string.h>

// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>

#include "32mz_interrupt_control.h"
#include "pin_macros.h"

#include "usb_uart.h"

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
    // USB_UART_Receive_Handler();
    
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
    
    // Clear fault interrupt flag
    clearInterruptFlag(UART3_Fault);
    
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

// This function prints strings on the terminal 
void USB_UART_print(char charArray[]) {
    
    int i;
    for (i = 0; i <= strlen(charArray); i++) {
     
        USB_UART_putchar(charArray[i]);
        
    }
    
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
 
    USB_UART_textAttributes(YELLOW, BLACK, NORMAL);
    USB_UART_print("Supported Commands:\n\r");
    USB_UART_print("    LED On: Sets RE3\n\r");
    USB_UART_print("    LED Off: Clears RE3\n\r");
    USB_UART_print("    Reset: Software Reset\n\r");
    USB_UART_print("    Clear: Clears the terminal\n\r");
    USB_UART_print("    *IDN?: Returns identification string\n\r");
    USB_UART_print("    Enable Muxing: enables the multiplexing timer \n\r");
    USB_UART_print("    Disable Muxing: disable the multiplexing timer \n\r");
    USB_UART_print("    Device On Time?: Returns the device on time in seconds since last reset\n\r");
    USB_UART_print("    Print Test Message: Print out terminal test data\n\r");
    USB_UART_print("    Credits: Displays creators\n\r");
    USB_UART_print("    Help: This Command\n\r");
    USB_UART_print("    Set Red: Sets panels red\n\r");
    USB_UART_print("    Set White: Sets panels white\n\r");    
    USB_UART_print("    Set Blue: Sets panels blue\n\r");
    USB_UART_print("    Set Yellow: Sets panels yellow\n\r");
    USB_UART_print("    Set Cyan: Sets panels cyan\n\r");    
    USB_UART_print("    Set Green: Sets panels green\n\r");    
    USB_UART_print("    Set Magenta: Sets panels magenta\n\r");    
    USB_UART_print("    Set MU Logo: Sets panel as MU Logo static image\n\r");
    USB_UART_print("    Set Rand: Sets panel to random data\n\r");
    USB_UART_print("    Set Test Image 2: Fills ram buffer with kevin's second test image\n\r");
    USB_UART_print("    Set Every Other Red: Fills ram buffer with stripes of red\n\r");
    USB_UART_print("    Set Every Other Blue: Fills ram buffer with stripes of blue\n\r");
    USB_UART_print("    Set Every Other Green: Fills ram buffer with stripes of green\n\r");
    USB_UART_print("    Set Christmas Stripes: Fills ram buffer with christmas stripes\n\r");
    USB_UART_print("    Set RGB Stripes: Fills ram buffer with stripes of rgb\n\r");
    USB_UART_print("    Set Red Rows: Fills ram buffer with red rows\n\r");
    USB_UART_print("    Set Shocker: Displays an inappropriate test image\n\r");
    USB_UART_print("    Set Drew 2: Displays drews second test image\n\r");
    USB_UART_print("    Slow Muxing Speed: Slows down multiplexing\n\r");
    USB_UART_print("    Slowest Muxing Speed: Slows down muxing speed extremely\n\r");
    USB_UART_print("    Reset Muxing Speed: Resets to faster multiplexing speed\n\r");
    USB_UART_print("    Set TV Test: Fills ram buffer with TV Test image\n\r");
    USB_UART_print("    Set NFL: Fills ram buffer with kevin's NFL image\n\r");
    USB_UART_print("    Set Colors: Fills ram buffer with colors\n\r");
    USB_UART_print("    Set Addidas: Fills ram buffer with addidas image\n\r");
    USB_UART_print("    Set BMW: Fills ram buffer with BMW logo\n\r");
    USB_UART_print("    Set Fire: Fills ram buffer with fire\n\r");
    USB_UART_print("    Set Swirl: Fills ram buffer with swirl image\n\r");
    USB_UART_print("    Set Bosch: Fills ram buffer with bosch image\n\r");
    USB_UART_print("    Set Kevin: Fills ram buffer with kevin image\n\r");
    
    USB_UART_textAttributesReset();

}

// tests all the function written for this example
void USB_UART_printTestMessage(void) {
    
    // Set starting text color white, background black, no fancy stuff
    // Print COM port settings
    USB_UART_textAttributesReset();
    USB_UART_print("Hello, World!\n\r");
    USB_UART_print("PIC32MZ USB UART Test\n\r");
    USB_UART_printNewline();
    USB_UART_print("COM Port Settings:\n\r");
    USB_UART_print("    Baud Rate: 921600 bps\n\r");
    USB_UART_print("    Data: 8 bits\n\r");
    USB_UART_print("    Parity: None\n\r");
    USB_UART_print("    Stop: 1 bit\n\r");
    USB_UART_print("    Flow Control: None\n\r");
    
    // Test text attributes
    USB_UART_printNewline();
    USB_UART_print("Testing text attributes:\n\r");

    // Print some black text
    USB_UART_textAttributes(BLACK, WHITE, NORMAL);
    USB_UART_print("This text is black\n\r");

    USB_UART_textAttributes(RED, BLACK, NORMAL);
    USB_UART_print("This text is red\n\r");

    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    USB_UART_print("This text is green\n\r");

    USB_UART_textAttributes(YELLOW, BLACK, NORMAL);
    USB_UART_print("This text is yellow\n\r");

    USB_UART_textAttributes(BLUE, WHITE, NORMAL);
    USB_UART_print("This text is blue\n\r");

    USB_UART_textAttributes(MAGENTA, BLACK, NORMAL);
    USB_UART_print("This text is magenta\n\r");

    USB_UART_textAttributes(CYAN, BLACK, NORMAL);
    USB_UART_print("This text is cyan\n\r");
    
    USB_UART_textAttributes(WHITE, BLACK, NORMAL);
    USB_UART_print("This text has a black background\n\r");
    
    USB_UART_textAttributes(BLACK, RED, NORMAL);
    USB_UART_print("This text has a red background\n\r");

    USB_UART_textAttributes(BLACK, GREEN, NORMAL);
    USB_UART_print("This text has a green background\n\r");
    
    USB_UART_textAttributes(BLACK, YELLOW, NORMAL);
    USB_UART_print("This text has a yellow background\n\r");
    
    USB_UART_textAttributes(WHITE, BLUE, NORMAL);
    USB_UART_print("This text has a blue background\n\r");
    
    USB_UART_textAttributes(BLACK, MAGENTA, NORMAL);
    USB_UART_print("This text has a magenta background\n\r");
    
    USB_UART_textAttributes(BLACK, CYAN, NORMAL);
    USB_UART_print("This text has a cyan background\n\r");
    
    USB_UART_textAttributes(BLACK, WHITE, NORMAL);
    USB_UART_print("This text has a white background\n\r");
    
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