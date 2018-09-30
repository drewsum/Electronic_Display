
#include "USB_UART.h"

text_attribute_t attribute;
text_color_t foreground_color;
text_color_t background_color;

void USB_UART_Print(char charArray[]) {
    strncpy(buff, charArray, sizeof(buff));
    DRV_USART0_Write(buff, sizeof(buff));   
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
    
    strncpy(buff, "\033[", sizeof(buff));
    
    switch (input_attribute) {
     
        case NORMAL:
            strcat(buff,"0"); 
            break;
        case BOLD:
            strcat(buff,"1");
            break;
        case UNDERSCORE:
            strcat(buff,"4");
            break;
        case BLINK:
            strcat(buff,"5");
            break;
        case REVERSE:
            strcat(buff,"7");
            break;
        case CONCEALED:
            strcat(buff,"8");
            break;

        default:
            strcat(buff,"0");
            break;
    }
    
    strcat(buff,";");
    
    switch (foreground_color) {
     
        case BLACK:
            strcat(buff,"30");
            break;
        case RED:
            strcat(buff,"31");
            break;
        case GREEN:
            strcat(buff,"32");
            break;
        case YELLOW:
            strcat(buff,"33");
            break;
        case BLUE:
            strcat(buff,"34");
            break;
        case MAGENTA:
            strcat(buff,"35");
            break;
        case CYAN:
            strcat(buff,"36");
            break;
        case WHITE:
            strcat(buff,"37");
            break;
            
        default:
            strcat(buff,"37");
            break;
    }
    
    strcat(buff,";");
    
    switch (background_color) {
     
        case BLACK:
            strcat(buff,"40");
            break;
        case RED:
            strcat(buff,"41");
            break;
        case GREEN:
            strcat(buff,"42");
            break;
        case YELLOW:
            strcat(buff,"43");
            break;
        case BLUE:
            strcat(buff,"44");
            break;
        case MAGENTA:
            strcat(buff,"45");
            break;
        case CYAN:
            strcat(buff,"46");
            break;
        case WHITE:
            strcat(buff,"47");
            break;
            
        default:
            strcat(buff,"47");
            break;
    }
    
    strcat(buff,"m");
    
    USB_UART_Print(buff);
}

void USB_UART_textAttributesReset(void) {
 
    USB_UART_textAttributes(WHITE, BLACK, NORMAL);
    
}

