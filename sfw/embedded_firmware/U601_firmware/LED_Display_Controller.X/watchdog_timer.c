
#include <xc.h>
#include <string.h>
#include <stdio.h>

#include "watchdog_timer.h"

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

// This function returns a string with information on the watchdog timer
char * getStringWatchdogStatus(void) {

    static char return_string[128];
    
    // clear return string
    int i;
    for (i = 0; i < strlen(return_string); i++) {
     
        return_string[i] = '\0';
        
    }
    
    char buff[64];

    strcat(return_string, "    Postscalar: ");
    
    switch (DEVCFG1bits.WDTPS) {
     
        case 0b00000:
            sprintf(buff, "1:1");
            break;
            
        case 0b00001:
            sprintf(buff, "1:2");
            break;
            
        case 0b00010:
            sprintf(buff, "1:4");
            break;
            
        case 0b00011:
            sprintf(buff, "1:8");
            break;
            
        case 0b00100:
            sprintf(buff, "1:16");
            break;
            
        case 0b00101:
            sprintf(buff, "1:32");
            break;
            
        case 0b00110:
            sprintf(buff, "1:64");
            break;
            
        case 0b00111:
            sprintf(buff, "1:128");
            break;
            
        case 0b01000:
            sprintf(buff, "1:256");
            break;
            
        case 0b01001:
            sprintf(buff, "1:512");
            break;
            
        case 0b01010:
            sprintf(buff, "1:1024");
            break;
            
        case 0b01011:
            sprintf(buff, "1:2048");
            break;
            
        case 0b01100:
            sprintf(buff, "1:4096");
            break;
            
        case 0b01101:
            sprintf(buff, "1:8192");
            break;
            
        case 0b01110:
            sprintf(buff, "1:16384");
            break;
            
        case 0b01111:
            sprintf(buff, "1:32768");
            break;
            
        case 0b10000:
            sprintf(buff, "1:65536");
            break;
            
        case 0b10001:
            sprintf(buff, "1:131072");
            break;
            
        case 0b10010:
            sprintf(buff, "1:262144");
            break;
            
        case 0b10011:
            sprintf(buff, "1:524288");
            break;
            
        case 0b10100:
            sprintf(buff, "1:1048576");
            break;
        
    }
    
    strcat(return_string, buff);
    strcat(return_string, "\n\r    Window Enable: ");
    
    if (WDTCONbits.WDTWINEN) {
     
        strcat(return_string, "True");
        
    }
    
    else {
     
        strcat(return_string, "False");
        
    }
    
    strcat(return_string, "\n\r    Window Size: ");
    
    switch (DEVCFG1bits.FWDTWINSZ) {
     
        case 0b00:
            sprintf(buff, "75%%");
            break;
            
        case 0b01:
            sprintf(buff, "50%%");
            break;
            
        case 0b10:
            sprintf(buff, "37.5%%");
            break;
    
        case 0b11:
            sprintf(buff, "25%%");
            break;
            
    }
    
    strcat(return_string, buff);
    strcat(return_string, "\n\r    WDT Enabled: ");
    
    if (WDTCONbits.ON) {
     
        strcat(return_string, "True");
        
    }
    
    else {
     
        strcat(return_string, "False");
        
    }
    
    
    return return_string;

}