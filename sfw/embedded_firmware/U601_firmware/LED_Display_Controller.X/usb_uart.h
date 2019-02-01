/* ************************************************************************** */
/** USB UART

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    usb_uart.h

  @Summary
 Allows USB debugging over UART6 to a USB virtual COM port

 */
/* ************************************************************************** */

#ifndef _USB_UART_H    /* Guard against multiple inclusion */
#define _USB_UART_H

// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>

// Sizes of TX and RX ring buffers
#define USB_UART_TX_BUFFER_SIZE 16384
#define USB_UART_RX_BUFFER_SIZE 128

// Hardcoded COM Port Descriptor Strings
#define USB_UART_BAUD_RATE_STR          "115.2 kbs"
#define USB_UART_DATA_LENGTH_STR        "8 bits"
#define USB_UART_PARITY_STR             "None"
#define USB_UART_STOP_BITS_STR          "1"
#define USB_UART_FLOW_CONTROL_STR       "None"


// Output character buffer
char output_buff[USB_UART_TX_BUFFER_SIZE];


// Received String from EUSART rx ring buffer, this is what we actually compare
// against command strings
char USB_UART_line[USB_UART_RX_BUFFER_SIZE];

// ring buffer counters
extern volatile uint32_t usb_uart_TxBufferRemaining;
extern volatile uint32_t usb_uart_RxCount;

extern volatile uint32_t usb_uart_TxHead;
extern volatile uint32_t usb_uart_TxTail;
extern volatile uint32_t usb_uart_TxBufferRemaining;



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


// This function initializes UART 6 for USB debugging
void USB_UART_Initialize(void);

// These are the USB UART Interrupt Service Routines
void __ISR(_UART3_RX_VECTOR, ipl2AUTO) USB_UART_Receive_ISR(void);
void __ISR(_UART3_TX_VECTOR, ipl3AUTO) USB_UART_Transfer_ISR(void);
void __ISR(_UART3_FAULT_VECTOR, ipl1AUTO) USB_UART_Fault_ISR(void);

// This function allows reading of a byre from UART6
uint8_t USB_UART_Read_Byte(void);

// This function places a character into the output stream of UART6
void USB_UART_putchar(uint8_t txData);

// These are the UART6 interrupt handlers
void USB_UART_Transmit_Handler(void);
void USB_UART_Receive_Handler(void);

// Basic text output function, feed it a string, everything is built off of this
void USB_UART_print(char charArray[]);

// Ring buffer interface functions
void USB_UART_ringBufferPull(void);
void USB_UART_ringBufferLUT(char * USB_UART_line);

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

// Misc functions
void USB_UART_printNewline(void);
void USB_UART_printHelpMessage(void);
void USB_UART_printTestMessage(void);


// This function returns a string of a large number of seconds in a human readable format
char * getStringSecondsAsTime(uint32_t input_seconds);

#endif /* _USB_UART_H */

/* *****************************************************************************
 End of File
 */
