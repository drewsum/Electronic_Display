
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
    
    // Setup ADC7 warm interrupt
    disableInterrupt(ADC7_Warm_Interrupt);
    setInterruptPriority(ADC7_Warm_Interrupt, 4);
    setInterruptSubpriority(ADC7_Warm_Interrupt, 2);
    clearInterruptFlag(ADC7_Warm_Interrupt);
    
    // Setup ADC Data 38 data ready interrupt
    disableInterrupt(ADC_Data_38);
    setInterruptPriority(ADC_Data_38, 1);
    setInterruptSubpriority(ADC_Data_38, 1);
    clearInterruptFlag(ADC_Data_38);
    
    // Setup ADC Data 39 data ready interrupt
    disableInterrupt(ADC_Data_39);
    setInterruptPriority(ADC_Data_39, 1);
    setInterruptSubpriority(ADC_Data_39, 1);
    clearInterruptFlag(ADC_Data_39);
    
    // Setup ADC Data 40 data ready interrupt
    disableInterrupt(ADC_Data_40);
    setInterruptPriority(ADC_Data_40, 1);
    setInterruptSubpriority(ADC_Data_40, 1);
    clearInterruptFlag(ADC_Data_40);
    
    // Setup ADC Data 41 data ready interrupt
    disableInterrupt(ADC_Data_41);
    setInterruptPriority(ADC_Data_41, 1);
    setInterruptSubpriority(ADC_Data_41, 1);
    clearInterruptFlag(ADC_Data_41);
    
    // Setup ADC Data 42 data ready interrupt
    disableInterrupt(ADC_Data_42);
    setInterruptPriority(ADC_Data_42, 1);
    setInterruptSubpriority(ADC_Data_42, 1);
    clearInterruptFlag(ADC_Data_42);
    
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
    ADCGIRQEN1 = 0;
    ADCGIRQEN2 = 0;
    ADCANCONbits.WKIEN7 = 1;    // Enable ADC7 warm up interrupt
    ADCGIRQEN2bits.AGIEN38 = 1;     // Enable Data 38 ready interrupt
    ADCGIRQEN2bits.AGIEN39 = 1;     // Enable Data 39 ready interrupt
    ADCGIRQEN2bits.AGIEN40 = 1;     // Enable Data 40 ready interrupt
    ADCGIRQEN2bits.AGIEN41 = 1;     // Enable Data 41 ready interrupt
    ADCGIRQEN2bits.AGIEN42 = 1;     // Enable Data 42 ready interrupt
    
    /* Configure ADCCSSx */
    ADCCSS1 = 0;
    ADCCSS2 = 0;
    ADCCSS2bits.CSS38 = 1;          // Enable Channel 38 for common scan
    ADCCSS2bits.CSS39 = 1;          // Enable Channel 39 for common scan
    ADCCSS2bits.CSS40 = 1;          // Enable Channel 40 for common scan
    ADCCSS2bits.CSS41 = 1;          // Enable Channel 41 for common scan
    ADCCSS2bits.CSS42 = 1;          // Enable Channel 42 for common scan
    
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
    ADCCON1bits.STRGSRC = 0b00110;      // Trigger source is Timer3
    
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
    
    // Wait for ADC7 warm interrupt to IRQ
    enableInterrupt(ADC7_Warm_Interrupt);
    
}

// This function initializes Timer3 as the ADC trigger timer
void ADCTriggerTimerInitialize(void) {
 
    // Stop timer 3
    T3CONbits.ON = 0;
    
    // Stop timer 3 in idle
    T3CONbits.SIDL = 1;
    
    // Disable gated time accumulation
    T3CONbits.TGATE = 0;
    
    // Set timer 3 prescalar to 4
    T3CONbits.TCKPS = 0b010;
    
    // Set timer clock input as PBCLK3
    T3CONbits.TCS = 0;
    
    // Clear timer 3
    TMR3 = 0x0000;
    
    // Set timer 3 period match to 16000
    // This should get us a Timer3 period of 1600uS, or a Timer3 frequency of 625Hz
    PR3 = 16000;
    
    // Start timer 3
    T3CONbits.ON = 1;
    
}

// This is the interrupt service routine for ADC7 warm up
void __ISR(_ADC7_WARM_VECTOR, IPL4SRS) ADC7WarmISR(void) {
    
    /* Enable the ADC module */
    ADCCON3bits.DIGEN7 = 1; // Enable ADC7 digital circuits
    
    // Unblock triggers
    ADCCON3bits.TRGSUSP = 0;
    
    ADCANCONbits.WKIEN7 = 0;    // Disable ADC7 warm up interrupt
    
    // Setup ADC Trigger Timer
    ADCTriggerTimerInitialize();

    // Disable interrupt source until next time we're initializing ADC7
    disableInterrupt(ADC7_Warm_Interrupt);
    
    // Enable ADC Data interrupts
    enableInterrupt(ADC_Data_38);
    enableInterrupt(ADC_Data_39);
    enableInterrupt(ADC_Data_40);
    enableInterrupt(ADC_Data_41);
    enableInterrupt(ADC_Data_42);
    
    // Clear IRQ
    clearInterruptFlag(ADC7_Warm_Interrupt);
    
}

// This is the POS3P3_ADC Interrupt Service Routine
void __ISR(_ADC_DATA38_VECTOR, IPL1SRS) POS3P3ADCISR(void) {

    // Check if data is actually ready
    if (ADCDSTAT2bits.ARDY38) {
     
        // Copy conversion result into results structure
        adc_results.POS3P3_adc_raw = ADCDATA38;
        
    }
    
    // Clear IRQ
    clearInterruptFlag(ADC_Data_38);
    
}

// This is the POS12_ADC Interrupt Service Routine
void __ISR(_ADC_DATA39_VECTOR, IPL1SRS) POS12ADCISR(void) {
    
    // Check if data is actually ready
    if (ADCDSTAT2bits.ARDY39) {
     
        // Copy conversion result into results structure
        adc_results.POS12_adc_raw = ADCDATA39;
        
    }
    
    // Clear IRQ
    clearInterruptFlag(ADC_Data_39);
    
}

// This is the POS5_ADC Interrupt Service Routine
void __ISR(_ADC_DATA40_VECTOR, IPL1SRS) POS5ADCISR(void) {
 
    // Check if data is actually ready
    if (ADCDSTAT2bits.ARDY40) {
     
        // Copy conversion result into results structure
        adc_results.POS5_adc_raw = ADCDATA40;
        
    }

    // Clear IRQ
    clearInterruptFlag(ADC_Data_40);
    
}

// This is the POS5P5_ADC Interrupt Service Routine
void __ISR(_ADC_DATA41_VECTOR, IPL1SRS) POS5P5ADCISR(void) {
 
    // Check if data is actually ready
    if (ADCDSTAT2bits.ARDY41) {
     
        // Copy conversion result into results structure
        adc_results.POS5P5_adc_raw = ADCDATA41;
        
    }

    // Clear IRQ
    clearInterruptFlag(ADC_Data_41);
    
}

// This is the POS5P_ADC Interrupt Service Routine
void __ISR(_ADC_DATA42_VECTOR, IPL1SRS) POS5PADCISR(void) {
    
    // Check if data is actually ready
    if (ADCDSTAT2bits.ARDY42) {
     
        // Copy conversion result into results structure
        adc_results.POS5P_adc_raw = ADCDATA42;
        
    }

    // Clear IRQ
    clearInterruptFlag(ADC_Data_42);
    
}
