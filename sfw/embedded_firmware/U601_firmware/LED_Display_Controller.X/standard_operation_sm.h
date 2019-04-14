/* ************************************************************************** */
/** State machine for normal panel operation
 */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>

#include <sys/attribs.h>

#ifndef STANDARD_OPERATION_SM_H     /* Guard against multiple inclusion */
#define STANDARD_OPERATION_SM_H

enum states_t{
    
    sm_undefined,
    sm_start,
    sm_first_load,
    sm_next_load,
    sm_display,
    sm_end
            
} state;

volatile uint8_t flash_chip;
volatile uint8_t autopilot;
volatile uint8_t continue_autopilot = 0;
volatile uint8_t image_num;
volatile uint8_t SM_Timer_Done;
volatile uint8_t First_Load;
volatile uint8_t sm_previous;
volatile uint8_t eventually_continue_flag;
volatile uint32_t set_timer_val;

// Initialize state machine 
void standardOpSMInit(void);

// Function to exit state machine
void exitSM(void);

// Function to move to next flash chip
void nextFlashData(void);

// Function to display current sram data
void showSRAMData(void);

// This is the Delay Timer Interrupt Service Routine
void __ISR(_TIMER_7_VECTOR, ipl1SRS) stateMachineTimerISR(void);

// This function initializes the Delay Timer (Timer 6)
void stateMachineTimerInit(void);

// This function sets the period of the timer and starts it
void stateMachineTimerStart(uint32_t timer_period_seconds);

// This function will read from the program flash memory and determine number of images to display
uint8_t readFrameNVM(void);

// This function will read from the program flash memory and determine image on time
uint32_t readDelayNVM(void);

// This function will write to the program flash memory to tell how many images should be displayed
void writeNVMVariables(uint8_t frame_num, uint32_t delay_value);

// This function is required for writing to and erasing internal PIC Flash memory
void NVMInitOperation(void);

// This function will be called from main for autopilot mode
void autopilotMode(void);

#endif /* STANDARD_OPERATION_SM_H */