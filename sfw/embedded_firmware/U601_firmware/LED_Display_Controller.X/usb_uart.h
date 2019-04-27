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
#define USB_UART_RX_BUFFER_SIZE 2048

// Hardcoded COM Port Descriptor Strings
#define USB_UART_BAUD_RATE_STR          "115.2 kbs"
#define USB_UART_DATA_LENGTH_STR        "8 bits"
#define USB_UART_PARITY_STR             "None"
#define USB_UART_STOP_BITS_STR          "1"
#define USB_UART_FLOW_CONTROL_STR       "None"

// Received String from EUSART rx ring buffer, this is what we actually compare
// against command strings
char usb_uart_line[USB_UART_RX_BUFFER_SIZE];

// ring buffer counters
extern volatile uint32_t usb_uart_RxBufferRemaining;
extern volatile uint32_t usb_uart_RxCount;

extern volatile uint32_t usb_uart_TxHead;
extern volatile uint32_t usb_uart_TxTail;
extern volatile uint32_t usb_uart_TxBufferRemaining;
extern volatile uint8_t usb_uart_TxBuffer[USB_UART_TX_BUFFER_SIZE];

// This records if multiplexing was occurring before disabling it for printing
uint8_t muxing_state;

// This records if a user is using the USB port
// This variable is deprecated, but still included
uint8_t usb_in_use_flag;

// This function initializes UART 6 for USB debugging
void usbUartInitialize(void);

// These are the USB UART Interrupt Service Routines
void __ISR(_UART3_RX_VECTOR, ipl2SRS) usbUartReceiveISR(void);
void __ISR(_UART3_TX_VECTOR, ipl6SRS) usbUartTransferISR(void);
void __ISR(_UART3_FAULT_VECTOR, ipl1SRS) usbUartFaultISR(void);

// This function allows reading of a byre from UART3
uint8_t usbUartReadByte(void);

// This function places a character into the output stream of UART3
void usbUartPutchar(uint8_t txData);

// These are the UART6 interrupt handlers
void usbUartTransmitHandler(void);
void usbUartReceiveHandler(void);

// Ring buffer interface functions
void usbUartRingBufferPull(void);
void usbUartRingBufferLUT(char * USB_UART_line);

// Misc functions
void usbUartPrintHelpMessage(void);

// This function returns a string of a large number of seconds in a human readable format
char * getStringSecondsAsTime(uint32_t input_seconds);

// This function compares the "needle" string parameter to see if it is the 
// beginning of the "haystack" string variable
// Returns 0 for success, 1 for failure
uint8_t strstart(const char * haystack, const char * needle);

#endif /* _USB_UART_H */

/* *****************************************************************************
 End of File
 */
