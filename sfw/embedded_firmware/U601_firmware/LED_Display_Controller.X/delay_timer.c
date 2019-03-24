#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "32mz_interrupt_control.h"
#include "delay_timer.h"
#include "esp8266.h"

void __ISR(_TIMER_4_VECTOR, ipl1SRS) delayTimerISR(void)
{
    // Turn off Timer 4
    T4CONbits.ON = 0;
    
    // Clear interrupt flag
    clearInterruptFlag(Timer4);
    disableInterrupt(Timer4);
    
    // Handle the task
    switch(timer_task)
    {
        case esp8266Delay:
            esp8266Configure();
            break;
        default:
            break;
    }
}

void delayTimerInitialize(void)
{
    
    // Disable Timer5 interrupt
    disableInterrupt(Timer4);
    setInterruptPriority(Timer4, 1);
    setInterruptSubpriority(Timer4, 1);
    clearInterruptFlag(Timer4);
    
    // Stop timer 4
    T4CONbits.ON = 0;
    
    // Stop timer 4 in idle
    T4CONbits.SIDL = 1;
    
    // Disable gated time accumulation
    T4CONbits.TGATE = 0;
    
    // Set timer 4 prescalar to 4
    T4CONbits.TCKPS = 0b010;
    
    // Set timer clock input as PBCLK3
    T4CONbits.TCS = 0;
    
    // Clear timer 5
    TMR4 = 0x0000;
    
    
}

void delayTimerStart(uint16_t delay_value, timer_task_t input_task)
{
    // Set Timer 4 period to passed value
    PR4 = delay_value;
    
    // Set the input task
    timer_task = input_task;
    
    // Clear the Timer
    TMR4 = 0;
    
    // Enable timer4 interrupt
    enableInterrupt(Timer4);
    
    // Turn Timer 4 ON
    T4CONbits.ON = 1;
    
}