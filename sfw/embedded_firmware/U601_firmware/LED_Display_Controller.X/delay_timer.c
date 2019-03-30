#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "32mz_interrupt_control.h"
#include "delay_timer.h"
#include "esp8266.h"
#include "error_handler.h"
#include "terminal_control.h"

void __ISR(_TIMER_4_VECTOR, ipl1SRS) delayTimerISR(void)
{
    // Turn off Timer 4
    T4CONbits.ON = 0;
    
    // Clear interrupt flag
    clearInterruptFlag(Timer4);
    disableInterrupt(Timer4);
    
    char response_message[40];
    
    // Handle the task
    switch(timer_task)
    {
        case esp8266Delay1:
            esp8266Putstring("AT+CWMODE_CUR=2\r\n");
            delayTimerStart(0x5FFF, esp8266Delay2);
            //esp8266Configure();
            break;
        case esp8266Delay2:
            esp8266Putstring("AT+CIPMUX=1\r\n");
            delayTimerStart(0x5FFF, esp8266Delay3);
            break;
        case esp8266Delay3:
            esp8266Putstring("AT+CIPSERVER=1,80\r\n");
            // Clear startup WIFI error
            error_handler.WIFI_error_flag = 0;
            break;
            
        case esp8266_http_response_delay1:
//            memset(response_message, 0, sizeof(response_message));
//            strcpy(response_message, "Message%20Received");
//            sendHTTPResponse((uint8_t) current_connection_id, response_message, strlen(response_message));
//            memset(response_message, 0, sizeof(response_message));
            memset(response_message, 0, sizeof(response_message));
            sprintf(response_message, "AT+CIPSEND=%u, %u\r\n", current_connection_id, 5);
            esp8266Putstring(response_message);
            delayTimerStart(0xFFFF, esp8266_http_response_delay2);
            break;
            
        case esp8266_http_response_delay2:
            memset(response_message, 0, sizeof(response_message));
            sprintf(response_message, "ABCDE\r\n");
            esp8266Putstring(response_message);
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
    
    // Set timer 4 prescalar to 8
    T4CONbits.TCKPS = 0b111;
    
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
    
    clearInterruptFlag(Timer4);
    
    // Enable timer4 interrupt
    enableInterrupt(Timer4);
    
    // Turn Timer 4 ON
    T4CONbits.ON = 1;
    
}