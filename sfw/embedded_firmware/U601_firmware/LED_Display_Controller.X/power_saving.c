
#include <xc.h>
#include <stdio.h>
#include <string.h>

#include "power_saving.h"

// This function disables unused peripherals on startup for power savings
// THIS FUNCTION CAN ONLY BE CALLED ONCE DUE TO PMD LOCKOUT AFTER ONE WRITE SESSION
void PMDInitialize(void) {

    // Unlock PMD
    PMDUnlock();
    
    /* If a PMD bit is set (1), that peripheral is disabled */
    
    // Disable ADC
    // TO-DO: This will change
    PMD1bits.ADCMD = 1;
 
    // Disable comparator voltage reference
    PMD1bits.CVRMD = 1;
    
    // Disable both comparators
    PMD2bits.CMP1MD = 1;
    PMD2bits.CMP2MD = 1;
    
    // Disable all input capture modules
    PMD3bits.IC1MD = 1;
    PMD3bits.IC2MD = 1;
    PMD3bits.IC3MD = 1;
    PMD3bits.IC4MD = 1;
    PMD3bits.IC5MD = 1;
    PMD3bits.IC6MD = 1;
    PMD3bits.IC7MD = 1;
    PMD3bits.IC8MD = 1;
    PMD3bits.IC9MD = 1;
    
    // Disable all output compare modules besides OC9
    PMD3bits.OC1MD = 1;
    PMD3bits.OC2MD = 1;
    PMD3bits.OC3MD = 1;
    PMD3bits.OC4MD = 1;
    PMD3bits.OC5MD = 1;
    PMD3bits.OC6MD = 1;
    PMD3bits.OC7MD = 1;
    PMD3bits.OC8MD = 1;
    PMD3bits.OC9MD = 0;
    
    // Enable all hardware timers
    // TO-DO: This may change
    PMD4bits.T1MD = 0;
    PMD4bits.T2MD = 0;
    PMD4bits.T3MD = 0;
    PMD4bits.T4MD = 0;
    PMD4bits.T5MD = 0;
    PMD4bits.T6MD = 0;
    PMD4bits.T7MD = 0;
    PMD4bits.T8MD = 0;
    PMD4bits.T9MD = 0;
    
    // Enable UART1, 3, disable others
    PMD5bits.U1MD = 0;
    PMD5bits.U2MD = 1;
    PMD5bits.U3MD = 0;
    PMD5bits.U4MD = 1;
    PMD5bits.U5MD = 1;
    PMD5bits.U6MD = 1;
    
    // Enable SPI3, disable others
    PMD5bits.SPI1MD = 1;
    PMD5bits.SPI2MD = 1;
    PMD5bits.SPI3MD = 0;
    PMD5bits.SPI4MD = 1;
    PMD5bits.SPI5MD = 1;
    PMD5bits.SPI6MD = 1;
    
    // Disable all I2C Modules
    PMD5bits.I2C1MD = 1;
    PMD5bits.I2C2MD = 1;
    PMD5bits.I2C3MD = 1;
    PMD5bits.I2C4MD = 1;
    PMD5bits.I2C5MD = 1;
    
    // Disable USB Module (UART 6 is used for USB debug)
    PMD5bits.USBMD = 1;
    
    // Disable CAN modules
    PMD5bits.CAN1MD = 1;
    PMD5bits.CAN2MD = 1;
    
    // Disable real time clock/calendar
    // TO-DO: This may change
    PMD6bits.RTCCMD = 1;
    
    // Disable all reference clocks
    // TO-DO: This may change
    PMD6bits.REFO1MD = 1;
    PMD6bits.REFO2MD = 1;
    PMD6bits.REFO3MD = 1;
    PMD6bits.REFO4MD = 1;
    
    // Disable peripheral master port
    PMD6bits.PMPMD = 1;
    
    // Enable external bus interface (EBI)
    PMD6bits.EBIMD = 0;
    
    // Disable serial quad interface
    PMD6bits.SQI1MD = 1;
    
    // Disable ethernet module
    PMD6bits.ETHMD = 1;
    
    // Disable DMA
    // TO-DO: This may change
    PMD7bits.DMAMD = 1;
    
    // Disable random number generator
    // TO-DO: This may change
    PMD7bits.RNGMD = 1;
    
    // Lock PMD
    PMDLock();
    
}


// This function returns a strong with the status of PMD settings
char * getStringPMDStatus(void) {
 
    static char return_string[1024];
    
    // clear return string
    int i;
    for (i = 0; i < strlen(return_string); i++) {
     
        return_string[i] = '\0';
        
    }
    
    char buff[64];
    
    // ADC
    sprintf(buff, "   ADC Enabled: %s\n\r", PMD1bits.ADCMD ? "False" : "True");
    strcat(return_string, buff);
    
    // CVREF
    sprintf(buff, "   Comparator Voltage Reference Enabled: %s\n\r", PMD1bits.CVRMD ? "False" : "True");
    strcat(return_string, buff);
    
    // Comparators
    sprintf(buff, "   Comparator 1 Enabled: %s\n\r", PMD2bits.CMP1MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Comparator 2 Enabled: %s\n\r", PMD2bits.CMP2MD ? "False" : "True");
    strcat(return_string, buff);
    
    // Input Capture Modules:
    sprintf(buff, "   Input Capture 1 Enabled: %s\n\r", PMD3bits.IC1MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Input Capture 2 Enabled: %s\n\r", PMD3bits.IC2MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Input Capture 3 Enabled: %s\n\r", PMD3bits.IC3MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Input Capture 4 Enabled: %s\n\r", PMD3bits.IC4MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Input Capture 5 Enabled: %s\n\r", PMD3bits.IC5MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Input Capture 6 Enabled: %s\n\r", PMD3bits.IC6MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Input Capture 7 Enabled: %s\n\r", PMD3bits.IC7MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Input Capture 8 Enabled: %s\n\r", PMD3bits.IC8MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Input Capture 9 Enabled: %s\n\r", PMD3bits.IC9MD ? "False" : "True");
    strcat(return_string, buff);
    
    // Output Compare Modules
    sprintf(buff, "   Output Compare 1 Enabled: %s\n\r", PMD3bits.OC1MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Output Compare 2 Enabled: %s\n\r", PMD3bits.OC2MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Output Compare 3 Enabled: %s\n\r", PMD3bits.OC3MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Output Compare 4 Enabled: %s\n\r", PMD3bits.OC4MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Output Compare 5 Enabled: %s\n\r", PMD3bits.OC5MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Output Compare 6 Enabled: %s\n\r", PMD3bits.OC6MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Output Compare 7 Enabled: %s\n\r", PMD3bits.OC7MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Output Compare 8 Enabled: %s\n\r", PMD3bits.OC8MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Output Compare 9 Enabled: %s\n\r", PMD3bits.OC9MD ? "False" : "True");
    strcat(return_string, buff);
    
    // Timers
    sprintf(buff, "   Timer 1 Enabled: %s\n\r", PMD4bits.T1MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Timer 2 Enabled: %s\n\r", PMD4bits.T2MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Timer 3 Enabled: %s\n\r", PMD4bits.T3MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Timer 4 Enabled: %s\n\r", PMD4bits.T4MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Timer 5 Enabled: %s\n\r", PMD4bits.T5MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Timer 6 Enabled: %s\n\r", PMD4bits.T6MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Timer 7 Enabled: %s\n\r", PMD4bits.T7MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Timer 8 Enabled: %s\n\r", PMD4bits.T8MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Timer 9 Enabled: %s\n\r", PMD4bits.T9MD ? "False" : "True");
    strcat(return_string, buff);
    
    // UART Modules
    sprintf(buff, "   UART 1 Enabled: %s\n\r", PMD5bits.U1MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   UART 2 Enabled: %s\n\r", PMD5bits.U2MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   UART 3 Enabled: %s\n\r", PMD5bits.U3MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   UART 4 Enabled: %s\n\r", PMD5bits.U4MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   UART 5 Enabled: %s\n\r", PMD5bits.U5MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   UART 6 Enabled: %s\n\r", PMD5bits.U6MD ? "False" : "True");
    strcat(return_string, buff);
    
    // SPI Modules
    sprintf(buff, "   SPI 1 Enabled: %s\n\r", PMD5bits.SPI1MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   SPI 2 Enabled: %s\n\r", PMD5bits.SPI2MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   SPI 3 Enabled: %s\n\r", PMD5bits.SPI3MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   SPI 4 Enabled: %s\n\r", PMD5bits.SPI4MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   SPI 5 Enabled: %s\n\r", PMD5bits.SPI5MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   SPI 6 Enabled: %s\n\r", PMD5bits.SPI6MD ? "False" : "True");
    strcat(return_string, buff);
    
    // I2C Modules
    sprintf(buff, "   I2C 1 Enabled: %s\n\r", PMD5bits.I2C1MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   I2C 2 Enabled: %s\n\r", PMD5bits.I2C2MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   I2C 3 Enabled: %s\n\r", PMD5bits.I2C3MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   I2C 4 Enabled: %s\n\r", PMD5bits.I2C4MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   I2C 5 Enabled: %s\n\r", PMD5bits.I2C5MD ? "False" : "True");
    strcat(return_string, buff);
    
    // USB Module
    sprintf(buff, "   USB Enabled: %s\n\r", PMD5bits.USBMD ? "False" : "True");
    strcat(return_string, buff);
    
    // CAN Modules
    sprintf(buff, "   CAN 1 Enabled: %s\n\r", PMD5bits.CAN1MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   CAN 2 Enabled: %s\n\r", PMD5bits.CAN2MD ? "False" : "True");
    strcat(return_string, buff);
    
    // RTCC
    sprintf(buff, "   Real Time Clock Enabled: %s\n\r", PMD6bits.RTCCMD ? "False" : "True");
    strcat(return_string, buff);
    
    // REFCLKS
    sprintf(buff, "   Reference Clock 1 Enabled: %s\n\r", PMD6bits.REFO1MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Reference Clock 2 Enabled: %s\n\r", PMD6bits.REFO2MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Reference Clock 3 Enabled: %s\n\r", PMD6bits.REFO3MD ? "False" : "True");
    strcat(return_string, buff);
    sprintf(buff, "   Reference Clock 4 Enabled: %s\n\r", PMD6bits.REFO4MD ? "False" : "True");
    strcat(return_string, buff);
    
    // PMP
    sprintf(buff, "   Parallel Master Port Enabled: %s\n\r", PMD6bits.PMPMD ? "False" : "True");
    strcat(return_string, buff);
    
    // EBI
    sprintf(buff, "   External Bus Interface Enabled: %s\n\r", PMD6bits.EBIMD ? "False" : "True");
    strcat(return_string, buff);
    
    // SQI
    sprintf(buff, "   Serial Quad Interface Enabled: %s\n\r", PMD6bits.SQI1MD ? "False" : "True");
    strcat(return_string, buff);
    
    // Ethernet
    sprintf(buff, "   Ethernet Enabled: %s\n\r", PMD6bits.ETHMD ? "False" : "True");
    strcat(return_string, buff);
    
    // DMA
    sprintf(buff, "   Direct Memory Access Enabled: %s\n\r", PMD7bits.DMAMD ? "False" : "True");
    strcat(return_string, buff);
    
    // Random Number Generator
    sprintf(buff, "   Random Number Generator Enabled: %s\n\r", PMD7bits.RNGMD ? "False" : "True");
    strcat(return_string, buff);
    
    // PMD Locked?
    sprintf(buff, "   PMD Locked: %s\n\r", CFGCONbits.PMDLOCK ? "True" : "False");
    strcat(return_string, buff);
    
    return return_string;
    
}