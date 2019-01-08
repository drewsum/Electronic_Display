
#include <xc.h>
#include <proc/p32mz2048efh144.h>

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

// This function initializes the deadman timer
void deadmanTimerInitialize(void) {
 
    // Start DMT at first
    DMTCONbits.ON = 1;
    
}

// This function starts the deadman timer
void startDeadmanTimer(void) {
 
    // Start DMT
    DMTCONbits.ON = 1;
    
}

// This function stops the deadman timer
void stopDeadmanTimer(void) {
 
    // Stop deadman timer
    DMTCONbits.ON = 0;
    
}

// This function clears the deadman timer
void holdThumbTighter(void) {
 
    // First write 0x40 into STEP1 bits within DMTPRECLR register
    DMTPRECLRbits.STEP1 = 0x40;
    
    // Second, write 0x08 into STEP2 of DMTCLR register
    DMTCLRbits.STEP2 = 0x08;
    
    // Verify DMT was cleared properly
    verifyThumbTightEnough();
    
}

// This function verifies the DMT has been cleared properly
void verifyThumbTightEnough(void) {
 
    // If we've had a DMT error, set the DMT error flag
    if (DMTSTATbits.BAD1 || DMTSTATbits.BAD2 || DMTSTATbits.DMTEVENT) {
     
        error_handler.DMT_error_flag = 1;
        
    }
    
}
