
#include <xc.h>
#include <string.h>
#include <stdio.h>

#include "watchdog_timer.h"
#include "usb_uart.h"
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

    USB_UART_textAttributes(GREEN, BLACK, UNDERSCORE);
    printf("Watchdog Timer Status:\n\r");

    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
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
    
    printf("\n\r    WDT Enabled: ");
    
    if (WDTCONbits.ON) {
     
        printf("True\n\r");
        
    }
    
    else {
     
        printf("False\n\r");
        
    }

}

// This function prints information on the deadman timer
void printDeadmanStatus(void) {

    USB_UART_textAttributes(GREEN, BLACK, UNDERSCORE);
    printf("Deadman Timer Status:\n\r");

    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    
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
    
    printf("   DMT Enabled: ");
    
    if (DMTCONbits.ON) {
     
        printf("True\n\r");
        
    }
    
    else {
     
        printf("False\n\r");
        
    }
       
}

// This function sets up the core timer, which resets the WDT and deadman timer
void coreTimerInitialize(void) {
    
    // Set up core timer interrupt
    disableInterrupt(Core_Timer_Interrupt);
    setInterruptPriority(Core_Timer_Interrupt, 7);
    setInterruptSubpriority(Core_Timer_Interrupt, 0);
    clearInterruptFlag(Core_Timer_Interrupt);
    
    // Set the compare value for core timer
    _CP0_SET_COMPARE(0x7000000);
    
    // Enable core timer interrupt
    enableInterrupt(Core_Timer_Interrupt);
    
}

// This is the core timer interrupt service routine
void __ISR(_CORE_TIMER_VECTOR, ipl7AUTO) coreTimerISR(void) {
     
    disableInterrupt(Core_Timer_Interrupt);
        
    // Clear the watchdog timer
    kickTheDog();
    
    // Clear the deadman timer
    holdThumbTighter();
    
    // Check to see if DMT actually cleared
    verifyThumbTightEnough();
    
    // Clear core timer
    _CP0_SET_COUNT(0x00000000);
    _CP0_SET_COMPARE(0x7000000);
    
    // Clear core timer interrupt flag
    clearInterruptFlag(Core_Timer_Interrupt);
    
    enableInterrupt(Core_Timer_Interrupt);
    
}