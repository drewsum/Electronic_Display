
#include <xc.h>

#include "heartbeat_timer.h"
#include "error_handler.h"

// This function initializes the heartbeat timer
void heartbeatTimerInitialize(void) {
    
    // Stop timer 1
    T1CONbits.ON = 0;
    
    // Continue timer 1 in idle (not sure if this will be used)
    T1CONbits.SIDL = 0;
    
    // Disable continuous writes
    T1CONbits.TWDIS = 1;
    
    // Disable gated time accumulation
    T1CONbits.TGATE = 0;
    
    // Set timer 1 prescalar to 256
    T1CONbits.TCKPS = 0b11;
    
    // Set timer clock input as PBCLK3
    T1CONbits.TCS = 0;
    
    // Clear timer 1
    TMR1 = 0x0000;
    
    // Set timer 1 period match to 61523
    // This will give an interrupt rate of 1 Hz
    PR1 = 61523;
    
    // Clear Timer1 Interrupt Flag
    clearInterruptFlag(Timer1);
    
    // Set Timer 1 interrupt priority
    setInterruptPriority(Timer1, 6);
    
    // Clear on time counter
    device_on_time_counter = 0;
    
    // Enable timer 1 interrupt
    enableInterrupt(Timer1);
    
    // Start timer 1
    T1CONbits.ON = 1;

}

// This function starts the heartbeat timer
void heartbeatTimerStart(void) {
    
    // Start timer 1
    T1CONbits.ON = 1;
    
}

// This function stops the heartbeat timer
void heartbeatTimerStop(void) {
 
    // Stop timer 1
    T1CONbits.ON = 0;
    
}

// Heartbeat timer interrupt service routine
void __ISR(_TIMER_1_VECTOR, ipl6SRS) hearbeatTimerISR(void) {

    // Toggle heartbeat LED
    HEARTBEAT_LED_PIN = !(HEARTBEAT_LED_PIN);
    
    // Update error LEDs based on error handler status
    updateErrorLEDs();
    
    // Increment on time counter
    device_on_time_counter++;
    
    // TO-DO: If we're going to keep track of display on time with a counter, increment it here too
    
    // Clear the watchdog timer
    kickTheDog();
    
    // Clear the deadman timer
    holdThumbTighter();
    
    // Check to see if DMT actually cleared
    verifyThumbTightEnough();
    
    // Clear interrupt flag
    clearInterruptFlag(Timer1);
    

}