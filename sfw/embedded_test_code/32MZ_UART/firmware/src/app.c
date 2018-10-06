/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"

#include <xc.h>
#include <stdio.h>
#include "USB_UART.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

extern volatile uint8_t usb_uart_RxStringReady;

extern volatile uint8_t Timer1_Print_Flag;


int count = 0;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/

// This function is called at device reset, tests all the function written for this example
void printTestMessage(void) {
    
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

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    
    
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            
            // Setup custom UART driver
            USB_UART_Initialize();
            
            // Setup terminal for printing
            USB_UART_clearTerminal();
            USB_UART_setCursorHome();
            
            // Dump a bunch of stuff to term
            printTestMessage();
            
            // Setup RE4 as output pin
            TRISECLR = 0x10;
            
            // Set RE3 as output pin as well
            TRISECLR = (1 << 3);
            
            // Setup timer 1 interrupt for counting
            PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_TIMER_1);
            
            // Start timer 1
            DRV_TMR0_Start();
                        
            bool appInitialized = true;
       
        
            if (appInitialized)
            {
            
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            
            if(usb_uart_RxStringReady) {
             
                ringBufferPull();
                
            }
            
            break;
        }

        /* TODO: implement your application state machine.*/
        

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

 

/*******************************************************************************
 End of File
 */
