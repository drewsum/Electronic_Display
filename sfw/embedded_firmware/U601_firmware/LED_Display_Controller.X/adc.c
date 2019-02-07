
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
    
    // Block ADC triggers for startup
    ADCCON3bits.TRGSUSP = 1;
    
    /* initialize ADC calibration setting */
    ADC7CFG = DEVADC7;

    /* Configure ADCCON1 */
    ADCCON1 = 0;
    ADCCON1bits.TRBEN = 0;     // Disable Turbo Mode
    if (ADCCON1bits.TRBERR) error_handler.ADC_configuration_error_flag = 1;     // Verify turbo mode disabled
    ADCCON1bits.SIDL = 1;   // Stop ADC in idle mode
 
    /* Configure ADCCON2 */
    ADCCON2 = 0;
    ADCCON2bits.SAMC = 0b0000000001;       // Set ADC7 sample time
    ADCCON2bits.ADCDIV = 0b0000001;         // Set clock divider

    /* Initialize warm up time register */
    ADCANCON = 0;
    ADCANCONbits.WKUPCLKCNT = 0b1111; // Set for longest wakeup time to be safe
    
    /* Clock setting */
    ADCCON3 = 0;
    ADCCON3bits.ADCSEL = 0; // Select input clock source
    ADCCON3bits.CONCLKDIV = 1; // Control clock frequency is half of input clock
    ADCCON3bits.VREFSEL = 0; // Select AVDD and AVSS as reference source
    
    /* Select ADC sample time and conversion clock */
    ADCCON2bits.ADCDIV = 1;
    ADCCON2bits.SAMC = 5;
    ADCCON1bits.SELRES = 3;
    
    /* Select ADC input mode */
    ADCIMCON3bits.SIGN38 = 0; // unsigned data format
    ADCIMCON3bits.DIFF38 = 0; // Single ended mode
    ADCIMCON3bits.SIGN39 = 0; // unsigned data format
    ADCIMCON3bits.DIFF39 = 0; // Single ended mode
    ADCIMCON3bits.SIGN40 = 0; // unsigned data format
    ADCIMCON3bits.DIFF40 = 0; // Single ended mode
    ADCIMCON3bits.SIGN41 = 0; // unsigned data format
    ADCIMCON3bits.DIFF41 = 0; // Single ended mode
    ADCIMCON3bits.SIGN42 = 0; // unsigned data format
    ADCIMCON3bits.DIFF42 = 0; // Single ended mode
    
    /* Configure ADCGIRQENx */
    ADCGIRQEN1 = 0; // No interrupts are used
    ADCGIRQEN2 = 0;
    
    /* Configure ADCCSSx */
    ADCCSS1 = 0; // No scanning is used
    ADCCSS2 = 0;
    
    /* Configure ADCCMPCONx */
    ADCCMPCON1 = 0; // No digital comparators are used. Setting the ADCCMPCONx
    ADCCMPCON2 = 0; // register to '0' ensures that the comparator is disabled.
    ADCCMPCON3 = 0; // Other registers are ?don't care?.
    ADCCMPCON4 = 0;
    ADCCMPCON5 = 0;
    
   /* Configure ADCFLTRx */
    ADCFLTR1 = 0; // No oversampling filters are used.
    ADCFLTR2 = 0;
    ADCFLTR3 = 0;
    ADCFLTR4 = 0;
    ADCFLTR5 = 0;
    ADCFLTR6 = 0;
    
    /* Set up the trigger sources */
    ADCCON1bits.STRGLVL = 0;            // Edge trigger mode
    ADCCON1bits.STRGSRC = 0b00001;      // Trigger source is GSWTRG         // FIX MEEEEEEEEEEEEEEEEEEE
    
    /* Early interrupt */
    ADCEIEN1 = 0; // No early interrupts used
    ADCEIEN2 = 0;
    
    /* Turn the ADC on */
    ADCCON1bits.ON = 1;
    
    /* Wait for voltage reference to be stable */
    while(!ADCCON2bits.BGVRRDY); // Wait until the reference voltage is ready
    if (ADCCON2bits.REFFLT) error_handler.ADC_configuration_error_flag = 1;     // Record error if reference fails
    
    /* Enable clock to analog circuit */
    ADCANCONbits.ANEN7 = 1; // Enable the clock to analog bias
    
    /* Wait for ADC to be ready */
    while(!ADCANCONbits.WKRDY7); // Wait until ADC7 is ready
    
    /* Enable the ADC module */
    ADCCON3bits.DIGEN7 = 1; // Enable ADC7
    
    // Unblock triggers
    ADCCON3bits.TRGSUSP = 0;
       
}
