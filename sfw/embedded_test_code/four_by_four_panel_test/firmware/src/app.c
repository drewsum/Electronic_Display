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
#include <stdlib.h>
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

extern volatile uint8_t usb_uart_RxStringReady;     // USB UART RX ready flag

unsigned long device_on_time = 0;                   // Device on time in seconds

// Display update variables
uint8_t current_shift_clock;
uint8_t current_row;
uint8_t current_PWM_frame;

uint32_t current_shift_clock_index;
uint32_t current_row_index;
uint32_t current_PWM_frame_index;

// gnarly internal RAM buffer for display
uint8_t ram_buffer[49152];


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************


// Panel shift output callback function
void updateRowCallback(void) {
    
    // Stop on time timer and reset to 0
    DRV_TMR1_Stop();
    DRV_TMR1_CounterValueSet(0x00);
    
    // Disable output
    panelnOE = 1;
    
    // Set latch low
    panelLAT = 0;
    
    // Set clock low
    panelCLK = 0;
    
    // loop through 64 shift clock cycles
    for (current_shift_clock = 0; current_shift_clock <= 63; current_shift_clock++) {
     
        // Poor man's delay
        uint8_t delay_index = 10;
        while (delay_index > 0) {
            delay_index--;
        };
        
        // Set red pins from RAM buffer
        current_shift_clock_index = 3 * current_shift_clock;
        uint8_t redData = ram_buffer[current_shift_clock_index + current_row_index + current_PWM_frame_index + 0];
        setPanelRedBus(redData);
        // Set green pins from RAM buffer
        uint8_t greenData = ram_buffer[current_shift_clock_index + current_row_index + current_PWM_frame_index + 1];
        setPanelGreenBus(greenData);
        // Set blue pins from RAM buffer
        uint8_t blueData = ram_buffer[current_shift_clock_index + current_row_index + current_PWM_frame_index + 2];
        setPanelBlueBus(blueData);

        // Poor man's delay
        delay_index = 10;
        while (delay_index > 0) {
            delay_index--;
        };
        
        // Clock data into panel
        panelCLK = 1;
        
        // Poor man's delay
        delay_index = 10;
        while (delay_index > 0) {
            delay_index--;
        };
        
        // clear clock signal
        panelCLK = 0;
        
    }
    
    // update row bus signals
    setPanelRowBus(current_row);
    
    
    // Latch shifter data into shift registers
    panelLAT = 1;
    
    // Enable pixel output
    panelnOE = 0;
    
    // Next function call, update the next row
    current_row++;
    
    // Reset current_row counter
    if (current_row >= 32) {
     
        current_row = 0;
        current_PWM_frame++;
        
    }
    
    // Update row index variable
    current_row_index = 192 * current_row;
    
    // Reset current_PWM_frame counter
    if (current_PWM_frame >= 8) {
     
        current_PWM_frame = 0;
        
    }
    
    // Update PWM index variable
    current_PWM_frame_index = 6144 * current_PWM_frame;
    
    // Restart on time timer
    DRV_TMR1_Start();
    
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

// fill ram buffer with all white pixels
void fillRamBufferWhite(void) {
 
    unsigned int address_index;
    
    for (address_index = 0; address_index < 49152; address_index++) {
     
        ram_buffer[address_index] = 0xFF;
        
    }
    
}

// fill ram buffer with random data
void fillRamBufferRand(void) {
 
    unsigned int address_index;
    
    srand(10);
    
    for (address_index = 0; address_index < 49152; address_index++) {
     
        ram_buffer[address_index] = (uint8_t) rand() % 50;
        
    }
    
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
            
            // Set RE3/RE4 as an output
            TRISECLR = (1 << 3);
            TRISECLR = (1 << 4);
            
            
            // Setup USB UART
            USB_UART_Initialize();
            USB_UART_clearTerminal();
            USB_UART_setCursorHome();
            
            // Initialize ram buffer with data
            fillRamBufferRand();
            
            // Setup timer 1 interrupt for counting
            PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_TIMER_1);
            
            // Setup timer 2 interrupt for data shifting
            PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_TIMER_2);
            
            
            // Start timer 1, which blinks LED and increments an integer 'count'
            DRV_TMR0_Start();
            
            // Start timer 2 (data shifting timer)
            DRV_TMR1_Start();
            
            // Setup output pins for panel, and start pins in idle state
            panelPinInit();
            
            // Enable panel display
            panelnOE = 0;
            
            bool appInitialized = true;
       
        
            if (appInitialized)
            {
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            
        
            // Terrible hard-coded for loop implementation:
            
//            int currentRow = 0;
//            for (currentRow = 0; currentRow <= 32; currentRow++) {
//                setPanelRowBus(currentRow);
//                panelLAT = 0;
//                panelCLK = 0;
//                panelnOE = 1;
//
//                // Shift some garbage into the first row and 33rd row
//                int clk_index;
//                for(clk_index = 0; clk_index <= 64; clk_index++) {
//                    panelCLK = 0;
//                    setPanelRedBus(0x03);
//                    setPanelGreenBus(0x01);
//                    setPanelBlueBus(0x01);
//                    // crude delay
//                    int i = 100;
//                    while(i > 0) {
//                        i--;   
//                    }
//                    panelCLK = 1;
//                    // another crude delay
//                    i = 100;
//                    while(i > 0) {
//                        i--;
//                    }
//                }
//
//                panelLAT = 1;
//                panelCLK = 0;
//                panelnOE = 0;
//
//                int i = 2000;
//                while(i > 0) {
//                    i--;
//                }
//            }
//            
         
            if(usb_uart_RxStringReady) {

                USB_UART_ringBufferPull();

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
