
#include "USB_UART.h"

#include <xc.h>
#include <string.h>

// Text attribute enums
text_attribute_t attribute;
text_color_t foreground_color;
text_color_t background_color;


/**
  Section: Global Variables
*/
volatile uint8_t usb_uart_TxHead = 0;
volatile uint8_t usb_uart_TxTail = 0;
volatile uint8_t usb_uart_TxBuffer[USB_UART_TX_BUFFER_SIZE];
volatile uint8_t usb_uart_TxBufferRemaining;

volatile uint8_t usb_uart_RxHead = 0;
volatile uint8_t usb_uart_RxTail = 0;
volatile uint8_t usb_uart_RxBuffer[USB_UART_RX_BUFFER_SIZE];
volatile uint8_t usb_uart_RxCount;

volatile uint8_t usb_uart_RxStringReady = false;

// This can be removed when moving files, only used for this example
extern volatile int count;


void USB_UART_Initialize(void) {
 
    // Disable UART interrupts
     PLIB_INT_SourceDisable(INT_ID_0,INT_SOURCE_USART_1_RECEIVE);
     PLIB_INT_SourceDisable(INT_ID_0,INT_SOURCE_USART_1_TRANSMIT);
    
    // initializing the driver state
    usb_uart_TxHead = 0;
    usb_uart_TxTail = 0;
    usb_uart_TxBufferRemaining = sizeof(usb_uart_TxBuffer);

    usb_uart_RxHead = 0;
    usb_uart_RxTail = 0;
    usb_uart_RxCount = 0;
    
    // Set hardware FIFO interrupt behavior
    U1STAbits.URXISEL = 0b00;
    U1STAbits.UTXISEL = 0b00;
    
    // Enable receiver interrupts
    PLIB_INT_SourceEnable(INT_ID_0,INT_SOURCE_USART_1_RECEIVE);
    
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
    
    PLIB_INT_SourceDisable(INT_ID_0,INT_SOURCE_USART_1_RECEIVE);
    usb_uart_RxCount--;
    PLIB_INT_SourceEnable(INT_ID_0,INT_SOURCE_USART_1_RECEIVE);

    return readValue;
    
}


// This function adds a byte to the TX ring buffer
void USB_UART_Write_Byte(uint8_t txData) {
 
    while(0 == usb_uart_TxBufferRemaining)
    {
    }

    if(!PLIB_INT_SourceIsEnabled(INT_ID_0,INT_SOURCE_USART_1_TRANSMIT))
    {
        U1TXREG = txData;
    }
    else
    {
        
        PLIB_INT_SourceDisable(INT_ID_0,INT_SOURCE_USART_1_TRANSMIT);
        usb_uart_TxBuffer[usb_uart_TxHead++] = txData;
        
        if(sizeof(usb_uart_TxBuffer) <= usb_uart_TxHead)
        {
            usb_uart_TxHead = 0;
        }
        
        usb_uart_TxBufferRemaining--;

    }

    PLIB_INT_SourceEnable(INT_ID_0,INT_SOURCE_USART_1_TRANSMIT);
    
}

// This serves as the TX interrupt handler and is called by the TX ISR
void USB_UART_Transmit_Handler(void) {
 
    // add your EUSART1 interrupt custom code
    if(sizeof(usb_uart_TxBuffer) > usb_uart_TxBufferRemaining)
    {
        U1TXREG = usb_uart_TxBuffer[usb_uart_TxTail++];
        if(sizeof(usb_uart_TxBuffer) <= usb_uart_TxTail)
        {
            usb_uart_TxTail = 0;
        }
        usb_uart_TxBufferRemaining++;
    }
    else
    {
        // PIE3bits.TX1IE = 0;
        PLIB_INT_SourceDisable(INT_ID_0,INT_SOURCE_USART_1_TRANSMIT);
        
    }
    
    
}

// This serves as the RX handler and is called by the RX ISR
void USB_UART_Receive_Handler(void) {
 
    if(1 == U1STAbits.OERR)
    {
        // EUSART1 error - restart
        U1MODEbits.ON = 0;
        U1MODEbits.ON = 1;
    }
    
    while(U1STAbits.URXDA) {
    
        usb_uart_RxBuffer[usb_uart_RxHead++] = U1RXREG;
        
        if(sizeof(usb_uart_RxBuffer) <= usb_uart_RxHead)
        {
            usb_uart_RxHead = 0;
        }
        usb_uart_RxCount++;
        
    }
    
    // Empty hardware FIFO
    int dummy;
    while(U1STAbits.URXDA) {
                 
        dummy = U1RXREG;
                    
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
    if((usb_uart_RxBuffer[usb_uart_RxHead -1] == (int) '\b')) {
     
        usb_uart_RxBuffer[usb_uart_RxHead - 1] = '\0';
        usb_uart_RxHead--;
 
        // Erase the "backspaced" character on terminal
        USB_UART_Print("\033[K");
        
        if(usb_uart_RxHead != usb_uart_RxTail) {
        
            usb_uart_RxBuffer[usb_uart_RxHead] = '\0';
            usb_uart_RxHead--;

        }
        
    }
    
}

// This function prints strings on the terminal 
void USB_UART_Print(char charArray[]) {
    
    int i;
    for (i = 0; i <= strlen(charArray); i++) {
     
        USB_UART_Write_Byte(charArray[i]);
        
    }
    
}

// This function pulls data out of the RX ring buffer
void ringBufferPull(void) {

    int charNumber = usb_uart_RxCount;
            
    // Clear line buffer
    uint8_t index;
    for (index = 0; index < USB_UART_RX_BUFFER_SIZE; index++) {

        line[index] = '\0';

    }

    // Fill line from ring buffer
    index = 0;
    for(index = 0; index < charNumber; index++){

        line[index] = USB_UART_Read_Byte();

    }

    // Reset ring buffer
    usb_uart_RxTail = usb_uart_RxHead;

    // Try to kill off ending returns/newlines
    while((line[strlen(line) - 1] == (int) '\n') ||
          (line[strlen(line) - 1] == (int) '\r')) {
     
        // NULL
        line[strlen(line) - 1] = '\0';
        
    }
    

    // Clear ready flag
    usb_uart_RxStringReady = false;

    // Check to see if line matches a command
    ringBufferLUT(line);

    
}

// This function parses the data pulled from the RX ring buffer
// This is the function that actually makes stuff happen based on commands
// Enter the command you'd like to set up within the if statements as
// an argument to the "strstr" functions
/*
 
    if (strstr(line_in, "<INSERT COMMAND HERE>") != NULL) {

        <ACTIONS OF COMMAND>;
    }
 
 * 
 *  * */
void ringBufferLUT(char * line_in) {
 
    // THIS IS WHERE WE DO THE ACTUAL PARSING OF RECEIVED STRING AND
    // ACT ON IT

    // If we receive the string 'LED On'
    if (strstr(line_in, "LED On") != NULL) {
    
        // Set RD0
        LATESET = (1 << 3);
                
    }
    

    // Else if we've received LED Off
    else if(strstr(line_in, "LED Off") != NULL) {

        // Clear RD0
        LATECLR = (1 << 3);
        
    }    
    
    // Print Timer 1 ISR counter
    else if(strstr(line_in, "Timer 1 ISR Count?") != NULL) {
     
        USB_UART_textAttributesReset();
        USB_UART_Print("Timer 1 ISR has executed ");
        
        char buff[10];
        itoa(buff, count, 10);
        USB_UART_Print(buff);
        USB_UART_Print(" times since device reset\n\r");
        
    }
    
    else if(strstr(line_in, "Print Test Message") != NULL) {
        
        USB_UART_printNewline();
        USB_UART_textAttributesReset();
        USB_UART_printTestMessage();
        USB_UART_printNewline();
            
    }

    // Clear Screen, reset
    else if(strstr(line_in, "Reset") != NULL) {
        
        // Reset
        SYS_INT_Disable();
        /* perform a system unlock sequence ,starting critical sequence*/
        SYSKEY = 0x00000000; //write invalid key to force lock
        SYSKEY = 0xAA996655; //write key1 to SYSKEY
        SYSKEY = 0x556699AA; //write key2 to SYSKEY
        /* set SWRST bit to arm reset */
        RSWRSTSET = 1;
        /* read RSWRST register to trigger reset */
        unsigned int dummy;
        dummy = RSWRST;

    }
    
    // Clear the terminal command
    else if(strstr(line_in, "Clear") != NULL) {
     
        USB_UART_clearTerminal();
        USB_UART_setCursorHome();
        
    }
    
    // Identification command
    else if(strstr(line_in, "*IDN?") != NULL) {
     
        USB_UART_Print("PIC32MZ2048EFH100 USB UART Test\n\r");
        
    }
    
    // Stop Timer
    else if(strstr(line_in, "Timer 1 Stop") != NULL) {
        
        DRV_TMR0_Stop();
        
    }
    
    // Start Timer
    else if(strstr(line_in, "Timer 1 Start") != NULL) {
        
        DRV_TMR0_Start();
        
    }
    
    // Help message
    else if(strstr(line_in, "Help") != NULL) {
     
        USB_UART_printHelpMessage();
    
    }
    
    
}

// This function clears the terminal
void USB_UART_clearTerminal(void) {
    USB_UART_Print("\033[2J");
}

// This function moves the terminal cursor to top left corner
void USB_UART_setCursorHome(void) {
    USB_UART_Print("\033[H");
}

// This function clears the line the cursor is currently at on the terminal
void USB_UART_clearLine(void) {
    USB_UART_Print("\033[K");
}

// This function saves the current cursor position on the terminal
void USB_UART_saveCursor(void) {
    USB_UART_Print("\033[s");
}

// This function returns the cursor to saved position on terminal
void USB_UART_returnCursor(void) {
    USB_UART_Print("\033[u");
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
    
    USB_UART_Print(output_buff);
}

// Reset text attributes to white text, black background, no effects
void USB_UART_textAttributesReset(void) {
 
    USB_UART_textAttributes(WHITE, BLACK, NORMAL);
    
}

// Print newline on terminal
void USB_UART_printNewline(void) {

    USB_UART_Print("\n\r");
    
}

// Print help message, used in a command above
void USB_UART_printHelpMessage(void) {
 
    USB_UART_textAttributesReset();
    USB_UART_Print("Supported Commands:\n\r");
    USB_UART_Print("    LED On: Sets RE3\n\r");
    USB_UART_Print("    LED Off: Clears RE3\n\r");
    USB_UART_Print("    Reset: Software Reset\n\r");
    USB_UART_Print("    Clear: Clears the terminal\n\r");
    USB_UART_Print("    *IDN?: Returns identification string\n\r");
    USB_UART_Print("    Timer 1 Start: Start Timer 1 blinking LED and counting\n\r");
    USB_UART_Print("    Timer 1 Stop: Stop Timer 1\n\r");
    USB_UART_Print("    Timer 1 ISR Count?: Returns the number of Timer 1 ISR executions since reset\n\r");
    USB_UART_Print("    Print Test Message: Print out terminal test data\n\r");
    USB_UART_Print("    Help: This Command\n\r");
    
}

// tests all the function written for this example
void USB_UART_printTestMessage(void) {
    
    // Set starting text color white, background black, no fancy stuff
    USB_UART_textAttributesReset();
    USB_UART_Print("Hello, World!\n\r");
    USB_UART_Print("PIC32MZ UART1 USB Test\n\r");
    USB_UART_Print("COM Port Settings:\n\r");
    USB_UART_Print("    Baud Rate: 921600 bps\n\r");
    USB_UART_Print("    Data: 8 bits\n\r");
    USB_UART_Print("    Parity: None\n\r");
    USB_UART_Print("    Stop: 1 bit\n\r");
    USB_UART_Print("    Flow Control: None\n\r");
    USB_UART_Print("Testing text attributes:\n\r");

    // Print some black text
    USB_UART_textAttributes(BLACK, WHITE, NORMAL);
    USB_UART_Print("This text is black\n\r");

    USB_UART_textAttributes(RED, BLACK, NORMAL);
    USB_UART_Print("This text is red\n\r");

    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    USB_UART_Print("This text is green\n\r");

    USB_UART_textAttributes(YELLOW, BLACK, NORMAL);
    USB_UART_Print("This text is yellow\n\r");

    USB_UART_textAttributes(BLUE, WHITE, NORMAL);
    USB_UART_Print("This text is blue\n\r");

    USB_UART_textAttributes(MAGENTA, BLACK, NORMAL);
    USB_UART_Print("This text is magenta\n\r");

    USB_UART_textAttributes(CYAN, BLACK, NORMAL);
    USB_UART_Print("This text is cyan\n\r");
    
    USB_UART_textAttributes(WHITE, BLACK, NORMAL);
    USB_UART_Print("This text has a black background\n\r");
    
    USB_UART_textAttributes(BLACK, RED, NORMAL);
    USB_UART_Print("This text has a red background\n\r");

    USB_UART_textAttributes(BLACK, GREEN, NORMAL);
    USB_UART_Print("This text has a green background\n\r");
    
    USB_UART_textAttributes(BLACK, YELLOW, NORMAL);
    USB_UART_Print("This text has a yellow background\n\r");
    
    USB_UART_textAttributes(WHITE, BLUE, NORMAL);
    USB_UART_Print("This text has a blue background\n\r");
    
    USB_UART_textAttributes(BLACK, MAGENTA, NORMAL);
    USB_UART_Print("This text has a magenta background\n\r");
    
    USB_UART_textAttributes(BLACK, CYAN, NORMAL);
    USB_UART_Print("This text has a cyan background\n\r");
    
    USB_UART_textAttributes(BLACK, WHITE, NORMAL);
    USB_UART_Print("This text has a white background\n\r");
    
    USB_UART_textAttributes(WHITE, BLACK, BOLD);
    USB_UART_Print("This text is bold\n\r");

    USB_UART_textAttributesReset();
    USB_UART_textAttributes(WHITE, BLACK, UNDERSCORE);
    USB_UART_Print("This text is underscored\n\r");

    USB_UART_textAttributesReset();
    USB_UART_textAttributes(WHITE, BLACK, BLINK);
    USB_UART_Print("This text is blinking\n\r");

    USB_UART_textAttributesReset();
    USB_UART_textAttributes(WHITE, BLACK, REVERSE);
    USB_UART_Print("This text is reversed\n\r");

    USB_UART_textAttributesReset();
    USB_UART_Print("This text is normal\n\r");
    
    USB_UART_Print("\n\r");
}