
#include <xc.h>
#include <string.h>
#include <stdio.h>

#include "watchdog_timer.h"
#include "terminal_control.h"
#include "pin_macros.h"

// This function initializes the watchdog timer for a timeout period of 
// 2 seconds, and no window (window always open)
void watchdogTimerInitialize(void) {
 
    // Disable watchdog during setup
    WDTCONbits.ON = 0;
    
    // Disable WDT window (window always open)
    WDTCONbits.WDTWINEN = 0;
    
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

// This function prints information on the watchdog timer
void printWatchdogStatus(void) {

    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, UNDERSCORE);
    printf("Watchdog Timer Status:\n\r");

    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    Postscalar: ");
    
    switch (DEVCFG1bits.WDTPS) {
     
        case 0b00000:
            printf("1:1");
            break;
            
        case 0b00001:
            printf("1:2");
            break;
            
        case 0b00010:
            printf("1:4");
            break;
            
        case 0b00011:
            printf("1:8");
            break;
            
        case 0b00100:
            printf("1:16");
            break;
            
        case 0b00101:
            printf("1:32");
            break;
            
        case 0b00110:
            printf("1:64");
            break;
            
        case 0b00111:
            printf("1:128");
            break;
            
        case 0b01000:
            printf("1:256");
            break;
            
        case 0b01001:
            printf("1:512");
            break;
            
        case 0b01010:
            printf("1:1024");
            break;
            
        case 0b01011:
            printf("1:2048");
            break;
            
        case 0b01100:
            printf("1:4096");
            break;
            
        case 0b01101:
            printf("1:8192");
            break;
            
        case 0b01110:
            printf("1:16384");
            break;
            
        case 0b01111:
            printf("1:32768");
            break;
            
        case 0b10000:
            printf("1:65536");
            break;
            
        case 0b10001:
            printf("1:131072");
            break;
            
        case 0b10010:
            printf("1:262144");
            break;
            
        case 0b10011:
            printf("1:524288");
            break;
            
        case 0b10100:
            printf("1:1048576");
            break;
        
    }
    
    printf("\n\r    Window Enable: ");
    
    if (WDTCONbits.WDTWINEN) {
     
        printf("True");
        
    }
    
    else {
     
        printf("False");
        
    }
    
    printf("\n\r    Window Size: ");
    
    switch (DEVCFG1bits.FWDTWINSZ) {
     
        case 0b00:
            printf("75%%");
            break;
            
        case 0b01:
            printf("50%%");
            break;
            
        case 0b10:
            printf("37.5%%");
            break;
    
        case 0b11:
            printf("25%%");
            break;
            
    }
    
    // Print if WDT is enabled
    if (WDTCONbits.ON) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("\n\r    WDT Enabled: %c\n\r",
            WDTCONbits.ON ? 'T' : 'F');
    
    terminalTextAttributesReset();

}

// This function prints information on the deadman timer
void printDeadmanStatus(void) {

    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, UNDERSCORE);
    printf("Deadman Timer Status:\n\r");

    terminalTextAttributes(GREEN, BLACK, NORMAL);
    
    printf("   Instruction Fetch Count Limit: ");
    
    uint32_t deadmanCountLimit = (DEVCFG1bits.DMTCNT + 1) * 256;
    
    printf("%d instructions\n\r", deadmanCountLimit);
    
    printf("   Count Window Interval: ");
    
    switch (DEVCFG1bits.DMTINTV) {
     
        case 0b000:
            printf("Window/Interval value is zero\n\r");
            break;
            
        case 0b001:
            printf("Window/Interval value is 1/2 counter value\n\r");
            break;
        
        case 0b010:
            printf("Window/Interval value is 3/4 counter value\n\r");
            break;
        
        case 0b011:
            printf("Window/Interval value is 7/8 counter value\n\r");
            break;
        
        case 0b100:
            printf("Window/Interval value is 15/16 counter value\n\r");
            break;
        
        case 0b101:
            printf("Window/Interval value is 31/32 counter value\n\r");
            break;
        
        case 0b110:
            printf("Window/Interval value is 63/64 counter value\n\r");
            break;
        
        case 0b111:
            printf("Window/Interval value is 127/128 counter value\n\r");
            break;
            
    }
    
    // Print if DMT is enabled
    if (DMTCONbits.ON) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("   DMT Enabled: %c\n\r",
            DMTCONbits.ON ? 'T' : 'F');
    
    
    terminalTextAttributesReset();
       
}
