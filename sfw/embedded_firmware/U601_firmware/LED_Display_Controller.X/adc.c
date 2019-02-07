
#include <xc.h>

#include <stdio.h>

// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>


#include "adc.h"
#include "32mz_interrupt_control.h"
#include "error_handler.h"
#include "pin_macros.h"

/* Used ADC channels include:
 * 
 * AN38 - POS3P3_ADC
 * AN39 - POS12_ADC
 * AN40 - POS5P5_ADC
 * AN41 - POS5_ADC
 * AN42 - POS5P_ADC
 * 
 * 
 * */


// This function initializes the ADC
void ADCInitialize(void) {
    
    // Set ADC input clock to PBCLK3 (15.75 MHz)
    ADCCON3bits.ADCSEL = 0b00;

    // Clear global triggers
    ADCCON3bits.GLSWTRG = 0;
    ADCCON3bits.GSWTRG = 0;
    
    // Block triggers
    ADCCON3bits.TRGSUSP = 1;
    
    // Copy calibration data
    ADC0CFG = DEVADC0;
    ADC1CFG = DEVADC1;
    ADC2CFG = DEVADC2;
    ADC3CFG = DEVADC3;
    ADC4CFG = DEVADC4;
    ADC7CFG = DEVADC7;
    
    // Set warm up time for analog circuits
    ADCANCONbits.WKUPCLKCNT = 0b1111;           // No idea what to set this to
    
    // Disable ADC module at start
    ADCCON1bits.ON = 0;
        
    // Set as integer data output mode
    ADCCON1bits.FRACT = 0;
    
    // Set automatic trigger to no trigger
    ADCCON1bits.STRGSRC = 0b00000;                                      // CHANGE MEEEEEEE
    
    // Stop ADC in Idle mode
    ADCCON1bits.SIDL = 1;
    
    // Single scan per trigger rising edge
    ADCCON1bits.STRGLVL = 0;
    
    // Set ADC control clock divider
    ADCCON3bits.CONCLKDIV = 0b111111;               // No idea what this does
       
    // Select AVDD and AVSS as voltage references
    ADCCON3bits.VREFSEL = 0b000;
        
    // Set shared ADC clock divider
    ADCCON2bits.ADCDIV = 0b0000000111;                 // I have no idea what to set this to yet
    
    // Set shared ADC sample time
    ADCCON2bits.SAMC = 5;                // I have no idea what to set this to yet
    
    // Set shared ADC resolution as 12 bits
    ADCCON1bits.SELRES = 0b11;
    
    // Set input modes for used channels only
    ADCIMCON3bits.DIFF42 = 0;   // AN42 is single ended
    ADCIMCON3bits.SIGN42 = 0;   // AN42 is unsigned
    ADCIMCON3bits.DIFF41 = 0;   // AN41 is single ended
    ADCIMCON3bits.SIGN41 = 0;   // AN41 is unsigned
    ADCIMCON3bits.DIFF40 = 0;   // AN40 is single ended
    ADCIMCON3bits.SIGN40 = 0;   // AN40 is unsigned
    ADCIMCON3bits.DIFF39 = 0;   // AN39 is single ended
    ADCIMCON3bits.SIGN39 = 0;   // AN39 is unsigned
    ADCIMCON3bits.DIFF38 = 0;   // AN38 is single ended
    ADCIMCON3bits.SIGN38 = 0;   // AN38 is unsigned
    
    
    // Enable global interrupts for used channels
    // Given interrupt will IRQ when data for that channel is ready
    // This is NOT the same as enabling interrupts in the interrupt controller
    ADCGIRQEN2bits.AGIEN42 = 1;
    ADCGIRQEN2bits.AGIEN41 = 1;
    ADCGIRQEN2bits.AGIEN40 = 1;
    ADCGIRQEN2bits.AGIEN39 = 1;
    ADCGIRQEN2bits.AGIEN38 = 1;
    
    // Enable interrupt when reference fails
    ADCCON2bits.REFFLTIEN = 1;
    
    // Disable end of scan interrupt
    ADCCON2bits.EOSIEN = 0;
    
    // Enable ADC7 warm interrupt
    ADCANCONbits.WKIEN7 = 0;                            // CHANGE MEEEEEE
    
    // Disable digital filters
    ADCFLTR1 = 0;
    ADCFLTR2 = 0;
    ADCFLTR3 = 0;
    ADCFLTR4 = 0;
    ADCFLTR5 = 0;
    ADCFLTR6 = 0;

    // Disable ADC digital comparators
    ADCCMPCON1 = 0;
    ADCCMPCON2 = 0;
    ADCCMPCON3 = 0;
    ADCCMPCON4 = 0;
    ADCCMPCON5 = 0;
    ADCCMPCON6 = 0;

    // Disable FIFO
    ADCFSTATbits.FEN = 0;
    
    // Enable ADC module
    ADCCON1bits.ON = 1;
    
    // Wait for ADC bandgap reference to be ready
    while (ADCCON2bits.BGVRRDY == 0);
    
    printf("waiting for SFRs to be unblocked\n\r");
    
    // Wait for SFRs to be ready for writes
    while (!ADCCON3bits.UPDRDY);

    // Block triggers
    ADCCON3bits.TRGSUSP = 1;
    
    // Enable ADC7 analog circuits
    ADCANCONbits.ANEN7 = 1;
        
    printf("waiting for warm up: ADCANCONbits.WKRDY7 = 0x%02X\n\r", ADCANCONbits.WKRDY7);
    
    // Switch this to interrupt driven
    // wait for analog circuits to be ready
    while (ADCANCONbits.WKRDY7 == 0) {
     
        Nop();
        
    }
    
    // Make sure bandgap reference is solid
    if (ADCCON2bits.REFFLT) error_handler.ADC_configuration_error_flag = 1;
    
    // Enable ADC7 only
    ADCCON3bits.DIGEN7 = 1;
    
    // Unblock triggers
    ADCCON3bits.TRGSUSP = 0;
    
    printf("End of init function\n\r");
    
//    
}
