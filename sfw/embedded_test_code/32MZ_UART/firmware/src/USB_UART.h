/*  READ THIS:
 * 
 * USB_UART Custom Driver
 * 
 * Interfaces with a virtual com port through a UART/USB Bridge, and prints data
 * to a terminal application such as tera term
 * 
 * This driver is built off of default MHC drivers for ease of use
 * Because of this, the following settings MUST be configured in MHC
 * This driver assumes UART1 is used as UART_INSTANCE_0
 * Code can be changed if a different UART module is used
 * 
 * Following settings in MHC required:
 *      USART Driver must be enabled
 *          Driver Implementation: STATIC
 *          Interrupt Mode Checked
 *          Byte Model Support Checked
 *              Use Blocking Operation Unchecked
 *              Use Callback Operation Unchecked
 *      USART Driver Instance 0:
 *          USART_MODULE_ID: USART_ID_1 (can be changed, but requires driver alteration)
 *          Baud Rate: Match to terminal application
 *          Transmit Interrupt Priority: INT_PRIORITY_3
 *          Transmit_Interrupt_Sub-priority: INT_SUBPRIORITY_LEVEL1
 *          Receive Interrupt Priority: INT_PRIORITY_2
 *          Receive Interrupt Sub-priority: INT_SUBPRIORITY_LEVEL0
 *          Operation Mode: DRV_USART_OPERATIONAL_MODE_NORMAL
 *          Wake on Start Unchecked
 *          Auto Baud Unchecked
 *          Stop in Idle Unchecked
 *          Line Control: DRV_USART_LINE_CONTROL_8NONE1
 *          Handshake Mode: DRV_USART_HANDSHAKE_NONE
 * 
 * Failure to generate MHC APIs with these settings will result in bad, bad things
 * 
 * Also, ensure the following within system_interrupt.c:
 *  In the UART RX ISR, remove MHC code and call:
 *      USB_UART_Receive_Handler();
 *      PLIB_INT_SourceFlagClear(INT_ID_0,INT_SOURCE_USART_1_RECEIVE);
 * 
 * In the UART TX ISR, remove the MHC code and call:
 *      USB_UART_Transmit_Handler();
 *      PLIB_INT_SourceFlagClear(INT_ID_0,INT_SOURCE_USART_1_TRANSMIT);
 * 
 * Remove the UART Error ISR
 * 
 * 
 ******************************************************************** 
 * WHAT TO ALTER IN MHC GENERATED FILES:
 * ******************************************************************
 * 
 * The entire UART ISR section should look like this:
 * 
 * 
    void __ISR(_UART1_TX_VECTOR, ipl3AUTO) _IntHandlerDrvUsartTransmitInstance0(void)
    {
        //DRV_USART_TasksTransmit(sysObj.drvUsart0);
        USB_UART_Transmit_Handler();
        PLIB_INT_SourceFlagClear(INT_ID_0,INT_SOURCE_USART_1_TRANSMIT);
    }

    void __ISR(_UART1_RX_VECTOR, ipl2AUTO) _IntHandlerDrvUsartReceiveInstance0(void)
    {
        //DRV_USART_TasksReceive(sysObj.drvUsart0);
        USB_UART_Receive_Handler();
        PLIB_INT_SourceFlagClear(INT_ID_0,INT_SOURCE_USART_1_RECEIVE);
    }

 * 
 * Finally, within app.c, add this to the APP_STATE_INIT case:
        USB_UART_Initialize();
 * 
 * Add this as an external variable, below file inclusions:
    extern volatile uint8_t usb_uart_RxStringReady;
 * 
 * Add this to APP_SERVICE_TASKS case:
    if(usb_uart_RxStringReady) {

        USB_UART_ringBufferPull();

    }
            
 * 
 * 
 * 
 * */


#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H

#include "app.h"

#include <xc.h>
#include <stdarg.h>

// Sizes of TX and RX ring buffers
#define USB_UART_TX_BUFFER_SIZE 64
#define USB_UART_RX_BUFFER_SIZE 64

// Output character buffer
char output_buff[USB_UART_TX_BUFFER_SIZE];


// Received String from EUSART rx ring buffer, this is what we actually compare
// against command strings
char USB_UART_line[USB_UART_RX_BUFFER_SIZE];

// ring buffer counters
extern volatile uint8_t usb_uart_TxBufferRemaining;
extern volatile uint8_t usb_uart_RxCount;


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

// Function Prototypes
void USB_UART_Initialize(void);
uint8_t USB_UART_Read_Byte(void);
void USB_UART_putchar(uint8_t txData);
void USB_UART_Transmit_Handler(void);
void USB_UART_Receive_Handler(void);

// Basic text output function, feed it a string, everything is built off of this
void USB_UART_print(char charArray[]);
void USB_UART_printf(char *, ...);
char* convert(unsigned int, int);

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
#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
