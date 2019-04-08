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
    
    sm_idle,
	sm_start,
    sm_load,
    sm_display,
    sm_end
            
} state;

//enum events {
//    
//    begin,
//    loop,
//    stop,
//    
//};

uint8_t flash_chip;
uint8_t autopilot;
uint8_t continue_autopilot;
uint32_t countdown_val;
uint8_t image_num;

// Initialize state machine 
void standardOpSMInit(void);

// Function to transition to next state
// void nextState(enum events event);

// Function to exit state machine
void exitSM(void);

// Function to move to next flash chip
void nextFlashData(void);

// Function to display current sram data
void showSRAMData(void);

// This is the Delay Timer Interrupt Service Routine
void __ISR(_TIMER_7_VECTOR, ipl1SRS) countdownTimerISR(void);

// This function initializes the Delay Timer (Timer 6)
void countdownTimerInit(void);

// This function sets the period of the timer and starts it
void countdownTimerStart(uint32_t timer_period_seconds);

// This function will read from the program flash memory and determine number of images to display
uint8_t readFrameNumber(void);

// This function will write to the program flash memory to tell how many images should be displayed
void writeFrameNumber(uint8_t frame_num);

#endif /* STANDARD_OPERATION_SM_H */