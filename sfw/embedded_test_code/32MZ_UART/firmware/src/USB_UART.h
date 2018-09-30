
#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H

#include "app.h"

#include <xc.h>
#include <stdio.h>

// Output character buffer
char buff[64];

// Enumeration holding attributes data for setting text fanciness
typedef enum {
    
    NORMAL,
    BOLD,
    UNDERSCORE,
    BLINK,
    REVERSE,
    CONCEALED
            
} text_attribute_t;

// Enumeration for setting text color attributes
typedef enum {
    
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
            
} text_color_t;



// Basic text output function, feed it a string, everything is built off of this
void USB_UART_Print(char charArray[]);

// Terminal manipulation functions
void USB_UART_clearTerminal(void);  // clears the whole terminal
void USB_UART_setCursorHome(void);  // Sets cursor to home position
void USB_UART_clearLine(void);      // clears the current line where the cursor appears
void USB_UART_saveCursor(void);     // Saves the current position of the cursor
void USB_UART_returnCursor(void);   // Returns the cursor to saved position

// Text attributes function
void USB_UART_textAttributes(text_color_t foreground_color,
        text_color_t background_color,
        text_attribute_t input_attribute);

// Reset to white foreground, black background, no fancy stuff
void USB_UART_textAttributesReset(void);


#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
