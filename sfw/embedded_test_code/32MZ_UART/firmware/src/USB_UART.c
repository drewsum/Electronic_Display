
#include "USB_UART.h"

#include <xc.h>
#include <string.h>

text_attribute_t attribute;
text_color_t foreground_color;
text_color_t background_color;


#define USB_UART_TX_BUFFER_SIZE 64
#define USB_UART_RX_BUFFER_SIZE 64

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

volatile uint8_t usb_uart_RxStringReady = 0;



void USB_UART_Initialize(void) {
 
     PLIB_INT_SourceDisable(INT_ID_0,INT_SOURCE_USART_1_RECEIVE);
     PLIB_INT_SourceDisable(INT_ID_0,INT_SOURCE_USART_1_TRANSMIT);
    
    // initializing the driver state
    usb_uart_TxHead = 0;
    usb_uart_TxTail = 0;
    usb_uart_TxBufferRemaining = sizeof(usb_uart_TxBuffer);

    usb_uart_RxHead = 0;
    usb_uart_RxTail = 0;
    usb_uart_RxCount = 0;
    
    PLIB_INT_SourceEnable(INT_ID_0,INT_SOURCE_USART_1_RECEIVE);
    
    
}

uint8_t USB_UART_Read_Byte(void) {
 
    uint8_t readValue  = 0;
    
    while(0 == usb_uart_RxCount)
    {
    }

    readValue = usb_uart_RxBuffer[usb_uart_RxTail++];
    if(sizeof(usb_uart_RxBuffer) <= usb_uart_RxTail)
    {
        usb_uart_RxTail = 0;
    }
    
    // PIE3bits.RC1IE = 0;
    PLIB_INT_SourceDisable(INT_ID_0,INT_SOURCE_USART_1_RECEIVE);
    usb_uart_RxCount--;
    // PIE3bits.RC1IE = 1;
    PLIB_INT_SourceEnable(INT_ID_0,INT_SOURCE_USART_1_RECEIVE);

    return readValue;
    
}

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
        // PIE3bits.TX1IE = 0;
        PLIB_INT_SourceDisable(INT_ID_0,INT_SOURCE_USART_1_TRANSMIT);
        usb_uart_TxBuffer[usb_uart_TxHead++] = txData;
        if(sizeof(usb_uart_TxBuffer) <= usb_uart_TxHead)
        {
            usb_uart_TxHead = 0;
        }
        usb_uart_TxBufferRemaining--;
        Nop();
    }

    // PIE3bits.TX1IE = 1;
    PLIB_INT_SourceEnable(INT_ID_0,INT_SOURCE_USART_1_TRANSMIT);
    
}

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

void USB_UART_Receive_Handler(void) {
 
    if(1 == U1STAbits.OERR)
    {
        // EUSART1 error - restart

        U1MODEbits.ON = 0;
        U1MODEbits.ON = 1;
    }

    // buffer overruns are ignored
    usb_uart_RxBuffer[usb_uart_RxHead++] = U1RXREG;
    if(sizeof(usb_uart_RxBuffer) <= usb_uart_RxHead)
    {
        usb_uart_RxHead = 0;
    }
    usb_uart_RxCount++;
    
    // This next chunk is not generated by MCC, and must remain here
    // It tells main() or whatever is pulling from the ring buffer that
    // data is ready to be read, since the terminal sent a newline or 
    // carriage return
    if((U1RXREG == (int) '\n') || (U1RXREG == (int) '\r')) {
        
        usb_uart_RxStringReady = 1;
        
        // Clear the stuff leftover in receive register, probably not needed
        U1RXREG = 0;
        
    }
    
    else {
        
        usb_uart_RxStringReady = 0;
        
    }
   
    // If we've received a backspace
    if((U1RXREG == (int) '\b')) {
     
        usb_uart_RxBuffer[usb_uart_RxHead] = '\0';
        usb_uart_RxHead--;
 
        // Erase the "backspaced" character
        USB_UART_Print("\033[K");
        
        if(usb_uart_RxHead != usb_uart_RxTail) {
        
            usb_uart_RxBuffer[usb_uart_RxHead] = '\0';
            usb_uart_RxHead--;

        }
        
        U1RXREG = 0;
        
    }
    
}



void USB_UART_Print(char charArray[]) {
    //strncpy(output_buff, charArray, sizeof(output_buff));
    //DRV_USART0_Write(output_buff, sizeof(output_buff));   
    
    int i;
    for (i = 0; i < strlen(charArray); i++) {
     
        USB_UART_Write_Byte(charArray[i]);
        
    }
    
    Nop();
    
}

void USB_UART_clearTerminal(void) {
    USB_UART_Print("\033[2J");
}

void USB_UART_setCursorHome(void) {
    USB_UART_Print("\033[H");
}

void USB_UART_clearLine(void) {
    USB_UART_Print("\033[K");
}

void USB_UART_saveCursor(void) {
    USB_UART_Print("\033[s");
}

void USB_UART_returnCursor(void) {
    USB_UART_Print("\033[u");
}

// Text Foreground Color Function
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

void USB_UART_textAttributesReset(void) {
 
    USB_UART_textAttributes(WHITE, BLACK, NORMAL);
    
}

