/* ************************************************************************** */
/** Delay Timer

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    delay_timer.h

  @Summary
 The best timer ever made

 */
/* ************************************************************************** */

#ifndef _DELAY_TIMER_H    /* Guard against multiple inclusion */
#define _DELAY_TIMER_H

#include <xc.h>
// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>

// define Timer tasks
typedef enum {
    esp8266Delay1,
    esp8266Delay2,
    esp8266Delay3,
    esp8266_tcp_response_delay1,
    esp8266_tcp_response_delay2,
    esp8266_tcp_response_delay3,
    state_machine_resume_delay
} timer_task_t;

// Global task type for the timer
timer_task_t timer_task;

// This is the Delay Timer Interrupt Service Routine
void __ISR(_TIMER_4_VECTOR, ipl1SRS) delayTimerISR(void);

// This function initializes the Delay Timer (Timer 4)
void delayTimerInitialize(void);

// This function sets the period of the timer and starts it
void delayTimerStart(uint16_t delay_value, timer_task_t input_task);

#endif /* _DELAY_TIMER_H */

/* *****************************************************************************
 End of File
 */