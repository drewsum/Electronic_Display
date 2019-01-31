
#include <xc.h>
#include <stdio.h>
#include <string.h>

#include "power_saving.h"
#include "usb_uart.h"

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


// This function prints the status of PMD settings
void printPMDStatus(void) {
     
    USB_UART_textAttributes(GREEN, BLACK, UNDERSCORE);
    printf("Peripheral Module Disable Status:\n\r");
    
    // ADC
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   ADC Enabled:                              %s\n\r", PMD1bits.ADCMD ? "False" : " True");
    
    // CVREF
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Comparator Voltage Reference Enabled:     %s\n\r", PMD1bits.CVRMD ? "False" : " True");
    
    // Comparators
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Comparator 1 Enabled:                     %s\n\r", PMD2bits.CMP1MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Comparator 2 Enabled:                     %s\n\r", PMD2bits.CMP2MD ? "False" : " True");
    
    // Input Capture Modules:
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Input Capture 1 Enabled:                  %s\n\r", PMD3bits.IC1MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Input Capture 2 Enabled:                  %s\n\r", PMD3bits.IC2MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Input Capture 3 Enabled:                  %s\n\r", PMD3bits.IC3MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Input Capture 4 Enabled:                  %s\n\r", PMD3bits.IC4MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Input Capture 5 Enabled:                  %s\n\r", PMD3bits.IC5MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Input Capture 6 Enabled:                  %s\n\r", PMD3bits.IC6MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Input Capture 7 Enabled:                  %s\n\r", PMD3bits.IC7MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Input Capture 8 Enabled:                  %s\n\r", PMD3bits.IC8MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Input Capture 9 Enabled:                  %s\n\r", PMD3bits.IC9MD ? "False" : " True");
    
    // Output Compare Modules
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Output Compare 1 Enabled:                 %s\n\r", PMD3bits.OC1MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Output Compare 2 Enabled:                 %s\n\r", PMD3bits.OC2MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Output Compare 3 Enabled:                 %s\n\r", PMD3bits.OC3MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Output Compare 4 Enabled:                 %s\n\r", PMD3bits.OC4MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Output Compare 5 Enabled:                 %s\n\r", PMD3bits.OC5MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Output Compare 6 Enabled:                 %s\n\r", PMD3bits.OC6MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Output Compare 7 Enabled:                 %s\n\r", PMD3bits.OC7MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Output Compare 8 Enabled:                 %s\n\r", PMD3bits.OC8MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Output Compare 9 Enabled:                 %s\n\r", PMD3bits.OC9MD ? "False" : " True");
    
    // Timers
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Timer 1 Enabled:                          %s\n\r", PMD4bits.T1MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Timer 2 Enabled:                          %s\n\r", PMD4bits.T2MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Timer 3 Enabled:                          %s\n\r", PMD4bits.T3MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Timer 4 Enabled:                          %s\n\r", PMD4bits.T4MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Timer 5 Enabled:                          %s\n\r", PMD4bits.T5MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Timer 6 Enabled:                          %s\n\r", PMD4bits.T6MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Timer 7 Enabled:                          %s\n\r", PMD4bits.T7MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Timer 8 Enabled:                          %s\n\r", PMD4bits.T8MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Timer 9 Enabled:                          %s\n\r", PMD4bits.T9MD ? "False" : " True");
    
    // UART Modules
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   UART 1 Enabled:                           %s\n\r", PMD5bits.U1MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   UART 2 Enabled:                           %s\n\r", PMD5bits.U2MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   UART 3 Enabled:                           %s\n\r", PMD5bits.U3MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   UART 4 Enabled:                           %s\n\r", PMD5bits.U4MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   UART 5 Enabled:                           %s\n\r", PMD5bits.U5MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   UART 6 Enabled:                           %s\n\r", PMD5bits.U6MD ? "False" : " True");
    
    // SPI Modules
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   SPI 1 Enabled:                            %s\n\r", PMD5bits.SPI1MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   SPI 2 Enabled:                            %s\n\r", PMD5bits.SPI2MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   SPI 3 Enabled:                            %s\n\r", PMD5bits.SPI3MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   SPI 4 Enabled:                            %s\n\r", PMD5bits.SPI4MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   SPI 5 Enabled:                            %s\n\r", PMD5bits.SPI5MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   SPI 6 Enabled:                            %s\n\r", PMD5bits.SPI6MD ? "False" : " True");
    
    // I2C Modules
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   I2C 1 Enabled:                            %s\n\r", PMD5bits.I2C1MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   I2C 2 Enabled:                            %s\n\r", PMD5bits.I2C2MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   I2C 3 Enabled:                            %s\n\r", PMD5bits.I2C3MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   I2C 4 Enabled:                            %s\n\r", PMD5bits.I2C4MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   I2C 5 Enabled:                            %s\n\r", PMD5bits.I2C5MD ? "False" : " True");
    
    // USB Module
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   USB Enabled:                              %s\n\r", PMD5bits.USBMD ? "False" : " True");
    
    // CAN Modules
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   CAN 1 Enabled:                            %s\n\r", PMD5bits.CAN1MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   CAN 2 Enabled:                            %s\n\r", PMD5bits.CAN2MD ? "False" : " True");
    
    // RTCC
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Real Time Clock Enabled:                  %s\n\r", PMD6bits.RTCCMD ? "False" : " True");
    
    // REFCLKS
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Reference Clock 1 Enabled:                %s\n\r", PMD6bits.REFO1MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Reference Clock 2 Enabled:                %s\n\r", PMD6bits.REFO2MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Reference Clock 3 Enabled:                %s\n\r", PMD6bits.REFO3MD ? "False" : " True");
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Reference Clock 4 Enabled:                %s\n\r", PMD6bits.REFO4MD ? "False" : " True");
    
    // PMP
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Parallel Master Port Enabled:             %s\n\r", PMD6bits.PMPMD ? "False" : " True");
    
    // EBI
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   External Bus Interface Enabled:           %s\n\r", PMD6bits.EBIMD ? "False" : " True");
    
    // SQI
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Serial Quad Interface Enabled:            %s\n\r", PMD6bits.SQI1MD ? "False" : " True");
    
    // Ethernet
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Ethernet Enabled:                         %s\n\r", PMD6bits.ETHMD ? "False" : " True");
    
    // DMA
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   Direct Memory Access Enabled:             %s\n\r", PMD7bits.DMAMD ? "False" : " True");
    
    // Random Number Generator
    USB_UART_textAttributes(GREEN, BLACK, BLINK);
    printf("   Random Number Generator Enabled:          %s\n\r", PMD7bits.RNGMD ? "False" : " True");
    
    // PMD Locked?
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("   PMD Locked:                               %s\n\r", CFGCONbits.PMDLOCK ? " True" : "False");
    
}