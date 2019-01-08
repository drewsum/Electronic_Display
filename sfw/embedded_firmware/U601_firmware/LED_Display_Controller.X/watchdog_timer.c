
#include <xc.h>

#include "watchdog_timer.h"

// This function initializes the watchdog timer for a timeout period of 
// 2 seconds, and no window (window always open)
void watchdogTimerInitialize(void) {
 
    // Disable watchdog during setup
    WDTCONbits.ON = 0;
    
    // Disable WDT window (window always open)
    WDTCONbits.WDTWINEN = 0;
    
    // Modify configuration words to set WDT postscaler to 1:2048
    // This yields a timeout period of 2.048 seconds
    DEVCFG1bits.WDTPS = 0b01011;
    
    // Verify WDTPS change actually occurred
    if (DEVCFG1bits.WDTPS != 0b01011) {
     
        error_handler.configuration_error_flsg = 1;
        
    }
    
    // Start the watchdog timer
    WDTCONbits.ON = 1;
    
}

// This function starts the watchdog timer
void startWatchdogTimer(void) {
 
    WDTCONbits.ON = 1;
    
}

// This function stops the watchdog timer
void stopWatchdogTimer(void) {
 
    WDTCONbits.ON = 0;
    
}

// This function clears the watchdog timer
void kickTheDog(void) {
 
    WDTCONbits.WDTCLRKEY = 0x5743;
    
}