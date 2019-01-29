
#include <xc.h>

#include "heartbeat_timer.h"

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
    setInterruptPriority(Timer1, 1);
    
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
void __ISR(_TIMER_1_VECTOR, ipl1AUTO) hearbeatTimerISR(void) {

    // Disable timer 1 interrupt
    disableInterrupt(Timer1);
    
    // TO-DO: Do we need to copy RIPL bits into IPL bits?
    // This is from section 8.7.1 of micro reference manual (interrupt group priority levels)
    // Apparently this is how you block lower level interrupts during a higher order
    // ISR. If this is needed it should be done at beginning on EVERY ISR
    // The compiler may actually do this for us in the background
    // That could be what the ipl<priority> keyword does in above __ISR() macro
    // Leave AUTO keyword in there, that handles context saving in ISRs
    // Seeing how the device macros header file does not include any references to RIPL
    // and IPL or CPU registers Cause and Status, most likely we're not responsible for this
    // Definitely look deeper into this though, because if this is our problem
    // and we miss this, interrupts will not be prioritized
    
    // Toggle heartbeat LED
    HEARTBEAT_LED_PIN = !(HEARTBEAT_LED_PIN);
    
    // Increment on time counter
    device_on_time_counter++;
    
    // Clear the watchdog timer
    kickTheDog();
    
    // Clear the deadman timer
    // holdThumbTighter();
    
    // TO-DO: If we're going to keep track of display on time with a counter, increment it here too
    
    // Clear interrupt flag
    clearInterruptFlag(Timer1);
    
    // Re-enable interrupt
    enableInterrupt(Timer1);
    

}