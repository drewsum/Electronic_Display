
#include <xc.h>

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

