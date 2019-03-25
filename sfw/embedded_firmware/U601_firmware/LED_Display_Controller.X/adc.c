
#include <xc.h>

#include <stdio.h>

// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>


#include "adc.h"
#include "32mz_interrupt_control.h"
#include "error_handler.h"
#include "pin_macros.h"
#include "terminal_control.h"

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
    
    // Initialize max and min recorded values for adc results
    // These will be computed in EOS ISR
    adc_results.POS12_adc_max = 0.0;
    adc_results.POS12_adc_min = 30.0;
    adc_results.POS3P3_adc_max = 0.0;
    adc_results.POS3P3_adc_min = 30.0;
    adc_results.POS5P5_adc_max = 0.0;
    adc_results.POS5P5_adc_min = 30.0;
    adc_results.POS5P_adc_max = 0.0;
    adc_results.POS5P_adc_min = 30.0;
    adc_results.POS5_adc_max = 0.0;
    adc_results.POS5_adc_min = 30.0;
    adc_results.die_temp_adc_max = -40.0;
    adc_results.die_temp_adc_min = 160.0;
    
    // Setup ADC Analog Circuits Ready Interrupt
    disableInterrupt(ADC_Analog_Circuits_Ready);
    setInterruptPriority(ADC_Analog_Circuits_Ready, 4);
    setInterruptSubpriority(ADC_Analog_Circuits_Ready, 2);
    clearInterruptFlag(ADC_Analog_Circuits_Ready);
    
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
    
    // Setup ADC Data 43 data ready interrupt
    disableInterrupt(ADC_Data_43);
    setInterruptPriority(ADC_Data_43, 1);
    setInterruptSubpriority(ADC_Data_43, 1);
    clearInterruptFlag(ADC_Data_43);
    
    // Setup ADC Data 44 data ready interrupt
    disableInterrupt(ADC_Data_44);
    setInterruptPriority(ADC_Data_44, 1);
    setInterruptSubpriority(ADC_Data_44, 1);
    clearInterruptFlag(ADC_Data_44);
    
    // Setup ADC end of scan interrupt
    disableInterrupt(ADC_End_Of_Scan_Ready);
    setInterruptPriority(ADC_End_Of_Scan_Ready, 1);
    setInterruptSubpriority(ADC_End_Of_Scan_Ready, 1);
    clearInterruptFlag(ADC_End_Of_Scan_Ready);
    
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
    ADCCON2bits.SAMC = 0b0000001000;       // Set ADC7 sample time
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
    ADCCON2bits.BGVRIEN = 1;        // Enable analog circuits ready interrupt
    ADCANCONbits.WKIEN7 = 1;        // Enable ADC7 warm up interrupt
    ADCGIRQEN2bits.AGIEN38 = 1;     // Enable Data 38 ready interrupt
    ADCGIRQEN2bits.AGIEN39 = 1;     // Enable Data 39 ready interrupt
    ADCGIRQEN2bits.AGIEN40 = 1;     // Enable Data 40 ready interrupt
    ADCGIRQEN2bits.AGIEN41 = 1;     // Enable Data 41 ready interrupt
    ADCGIRQEN2bits.AGIEN42 = 1;     // Enable Data 42 ready interrupt
    ADCGIRQEN2bits.AGIEN43 = 1;     // Enable Data 43 ready interrupt
    ADCGIRQEN2bits.AGIEN44 = 1;     // Enable Data 44 ready interrupt
    ADCCON2bits.EOSIEN = 1;         // Enable interrupt on end of scan
    
    /* Configure ADCCSSx */
    ADCCSS1 = 0;
    ADCCSS2 = 0;
    ADCCSS2bits.CSS38 = 1;          // Enable Channel 38 for common scan
    ADCCSS2bits.CSS39 = 1;          // Enable Channel 39 for common scan
    ADCCSS2bits.CSS40 = 1;          // Enable Channel 40 for common scan
    ADCCSS2bits.CSS41 = 1;          // Enable Channel 41 for common scan
    ADCCSS2bits.CSS42 = 1;          // Enable Channel 42 for common scan
    ADCCSS2bits.CSS43 = 1;          // Enable Channel 43 for common scan
    ADCCSS2bits.CSS44 = 1;          // Enable Channel 44 for common scan
    
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
    
    // Enable analog circuits interrupt and continue initialization in that ISR
    enableInterrupt(ADC_Analog_Circuits_Ready);
    
    /* Wait for voltage reference to be stable */
    // while(!ADCCON2bits.BGVRRDY); // Wait until the reference voltage is ready
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

// This function is the analog circuits ready interrupt service routine
void __ISR(_ADC_ARDY_VECTOR, IPL4SRS) ADCAnalogReadyISR(void) {
    
    if (ADCCON2bits.REFFLT) error_handler.ADC_configuration_error_flag = 1;     // Record error if reference fails
    
    /* Enable clock to analog circuit */
    ADCANCONbits.ANEN7 = 1; // Enable the clock to analog bias
    
    // Wait for ADC7 warm interrupt to IRQ
    enableInterrupt(ADC7_Warm_Interrupt);
    
    // Clear IRQ
    clearInterruptFlag(ADC_Analog_Circuits_Ready);
    
    // Disable interrupt source
    disableInterrupt(ADC_Analog_Circuits_Ready);
    
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
    enableInterrupt(ADC_Data_43);
    enableInterrupt(ADC_Data_44);
    
    // Enable ADC end of scan interrupt
    enableInterrupt(ADC_End_Of_Scan_Ready);
    
    // Clear IRQ
    clearInterruptFlag(ADC7_Warm_Interrupt);
    
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("ADC Warmed Up and Scanning Inputs\n\r");
    terminalTextAttributesReset();
    
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

// This is the VREF_ADC Interrupt Service Routine
void __ISR(_ADC_DATA43_VECTOR, IPL1SRS) VREFADCISR(void) {
    
    // Check if data is actually ready
    if (ADCDSTAT2bits.ARDY43) {
     
        // Copy conversion result into results structure
        adc_results.vref_adc_raw = ADCDATA43;
        
    }

    // Clear IRQ
    clearInterruptFlag(ADC_Data_43);
    
}

// This is the DIE_TEMP_ADC Interrupt service Routine
void __ISR(_ADC_DATA44_VECTOR, IPL1SRS) DieTempADCISR(void) {
 
    // Check if data is actually ready
    if (ADCDSTAT2bits.ARDY44) {
     
        // Copy conversion result into results structure
        adc_results.die_temp_adc_raw = ADCDATA44;
        
    }

    // Clear IRQ
    clearInterruptFlag(ADC_Data_44);
    
}

// This is the ADC end of scan interrupt service routine
void __ISR(_ADC_EOS_VECTOR, IPL1SRS) ADCEndOfScanISR(void) {
 
    // If we read all zeros something went wrong
    if (adc_results.POS3P3_adc_raw == 0) {
     
        error_handler.ADC_configuration_error_flag = 1;
        
    }
    
    // Else, if data is solid
    else {

        // Make sure end of scan is complete
        if (ADCCON2bits.EOSRDY) {

            // Convert each ADC channel to voltage from LSBs
            adc_results.vref_adc    = (double) adc_results.vref_adc_raw * ADC_VOLTS_PER_LSB;
            adc_cal_gain = adc_results.vref_adc / 1.2;
            adc_results.POS3P3_adc  = (double) adc_results.POS3P3_adc_raw * ADC_VOLTS_PER_LSB * POS3P3_ADC_GAIN * POS3P3_ADC_CAL * adc_cal_gain;
            adc_results.POS12_adc   = (double) adc_results.POS12_adc_raw * ADC_VOLTS_PER_LSB * POS12_ADC_GAIN * POS12_ADC_CAL * adc_cal_gain;
            adc_results.POS5_adc    = (double) adc_results.POS5_adc_raw * ADC_VOLTS_PER_LSB * POS5_ADC_GAIN * POS5_ADC_CAL * adc_cal_gain;
            adc_results.POS5P_adc   = (double) adc_results.POS5P_adc_raw * ADC_VOLTS_PER_LSB * POS5P_ADC_GAIN * POS5P_ADC_CAL * adc_cal_gain;
            adc_results.POS5P5_adc  = (double) adc_results.POS5P5_adc_raw * ADC_VOLTS_PER_LSB * POS5P5_ADC_GAIN * POS5P5_ADC_CAL * adc_cal_gain;
            adc_results.die_temp_adc = (double) ((adc_results.die_temp_adc_raw * ADC_VOLTS_PER_LSB * adc_cal_gain) - 0.7) / 0.005;

        }
        
        // Record new maximum
        if (adc_results.POS3P3_adc > adc_results.POS3P3_adc_max) {
         
            adc_results.POS3P3_adc_max = adc_results.POS3P3_adc;
            
        }
        
        // record new minimum
        if (adc_results.POS3P3_adc < adc_results.POS3P3_adc_min) {
         
            adc_results.POS3P3_adc_min = adc_results.POS3P3_adc;
            
        }
        
        // Record new maximum
        if (adc_results.POS12_adc > adc_results.POS12_adc_max) {
         
            adc_results.POS12_adc_max = adc_results.POS12_adc;
            
        }
        
        // record new minimum
        if (adc_results.POS12_adc < adc_results.POS12_adc_min) {
         
            adc_results.POS12_adc_min = adc_results.POS12_adc;
            
        }
        
        // Record new maximum
        if (adc_results.POS5P_adc > adc_results.POS5P_adc_max) {
         
            adc_results.POS5P_adc_max = adc_results.POS5P_adc;
            
        }
        
        // record new minimum
        if (adc_results.POS5P_adc < adc_results.POS5P_adc_min) {
         
            adc_results.POS5P_adc_min = adc_results.POS5P_adc;
            
        }
        
        // Record new maximum
        if (adc_results.POS5P5_adc > adc_results.POS5P5_adc_max) {
         
            adc_results.POS5P5_adc_max = adc_results.POS5P5_adc;
            
        }
        
        // record new minimum
        if (adc_results.POS5P5_adc < adc_results.POS5P5_adc_min) {
         
            adc_results.POS5P5_adc_min = adc_results.POS5P5_adc;
            
        }
        
        // Record new maximum
        if (adc_results.POS5_adc > adc_results.POS5_adc_max) {
         
            adc_results.POS5_adc_max = adc_results.POS5_adc;
            
        }
        
        // record new minimum
        if (adc_results.POS5_adc < adc_results.POS5_adc_min) {
         
            adc_results.POS5_adc_min = adc_results.POS5_adc;
            
        }
        
        // Record new maximum
        if (adc_results.die_temp_adc > adc_results.die_temp_adc_max) {
         
            adc_results.die_temp_adc_max = adc_results.die_temp_adc;
            
        }
        
        // record new minimum
        if (adc_results.die_temp_adc < adc_results.die_temp_adc_min) {
         
            adc_results.die_temp_adc_min = adc_results.die_temp_adc;
            
        }
        
    }
        
    // Clear IRQ
    clearInterruptFlag(ADC_End_Of_Scan_Ready);
    
}

// This function prints the status of the ADC
void printADCStatus(void) {

    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, UNDERSCORE);
    printf("Analog to Digital Converter Status:\n\r");
    
    // Print if ADC is on
    if (ADCCON1bits.ON) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC %s\n\r", ADCCON1bits.ON ? "Enabled" : "Disabled");
    
    // Print ADC resolution
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC7 Resolution: ");
    switch (ADCCON1bits.SELRES) {
     
        case 0b00:
            printf("6 bits\n\r");
            break;
            
        case 0b01:
            printf("8 bits\n\r");
            break;
            
        case 0b10:
            printf("10 bits\n\r");
            break;
                    
        case 0b11:
            printf("12 bits\n\r");
            break;
        
    }
    
    // Print if fractional of integer mode
    if (ADCCON1bits.FRACT) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Fraction Format: %s\n\r", ADCCON1bits.FRACT ? "Fractional" : "Integer");
    
    // Print trigger source
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC Scan Trigger Source: ");
    switch (ADCCON1bits.STRGSRC) {
     
        case 0b00000:
            printf("No Trigger\n\r");
            break;
            
        case 0b00001:
            printf("Global software edge trigger (GSWTRG)\n\r");
            break;
            
        case 0b00010:
            printf("Global level software trigger (GLSWTRG)\n\r");
            break;
            
        case 0b00100:
            printf("INT0 External interrupt\n\r");
            break;
            
        case 0b00101:
            printf("TMR1 match\n\r");
            break;
            
        case 0b00110:
            printf("TMR3 match\n\r");
            break;
            
        case 0b00111:
            printf("TMR5 match\n\r");
            break;
            
        case 0b01000:
            printf("OCMP1\n\r");
            break;
            
        case 0b01001:
            printf("OCMP3\n\r");
            break;
            
        case 0b01010:
            printf("OCMP5\n\r");
            break;
            
        case 0b01011:
            printf("Comparator 1 (COUT)\n\r");
            break;
            
        case 0b01100:
            printf("Comparator 2 (COUT)\n\r");
            break;
            
        default:
            printf("Undefined\n\r");
            break;
            
    }
    
    // print trigger level/edge
    if (ADCCON1bits.STRGLVL) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Scan Trigger Sensitivity: %s\n\r", ADCCON1bits.STRGLVL ? "Level" : "Edge");
    
    // print trigger suspension status
    if (ADCCON3bits.TRGSUSP) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    Scan Trigger Suspension: %s\n\r", ADCCON3bits.TRGSUSP ? "suspended" : "not suspended");
    
    // Print status of bandgap reference
    if (ADCCON2bits.BGVRRDY) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Bandgap Reference Status: %s\n\r", ADCCON2bits.BGVRRDY ? "Ready" : "Not Ready");
    
    // Print bandgap fault status
    if (ADCCON2bits.REFFLT) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    Bandgap Reference is %s\n\r", ADCCON2bits.REFFLT ? "faulty" : "working properly");
    
    // Print SAMC7
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC7 Sample Time (TSAM7) = %d * TAD7\n\r", ADCCON2bits.SAMC + 2);
    
    // print ADC7 clock divider
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC7 Clock (TAD7) = %d * TQ\n\r", ADCCON2bits.ADCDIV * 2);
    
    // print ADC clock source
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC Clock Source (TCLK): ");
    switch (ADCCON3bits.ADCSEL) {
     
        case 0b00:
            printf("PBCLK3\n\r");
            break;
            
        case 0b01:
            printf("System Clock (TCY)\n\r");
            break;
            
        case 0b10:
            printf("REFCLK3\n\r");
            break;
            
        case 0b11:
            printf("FRC\n\r");
            break;
        
    }
    
    // Print control clock divider
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC Control Clock (TQ) = %d * TCLK\n\r", ADCCON3bits.CONCLKDIV * 2);
    
    // print digital enables
    if (ADCCON3bits.DIGEN0) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC0 is %s\n\r", ADCCON3bits.DIGEN0 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN1) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC1 is %s\n\r", ADCCON3bits.DIGEN1 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN2) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC2 is %s\n\r", ADCCON3bits.DIGEN2 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN3) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC3 is %s\n\r", ADCCON3bits.DIGEN3 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN4) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC4 is %s\n\r", ADCCON3bits.DIGEN4 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN7) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC7 is %s\n\r", ADCCON3bits.DIGEN7 ? "digital enabled" : "digital disabled");
    
    // print voltage reference selection
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    Voltage reference selection: ");
    switch (ADCCON3bits.VREFSEL) {
     
        case 0b00:
            printf("AVDD and AVSS\n\r");
            break;
            
        case 0b01:
            printf("VREFH and AVSS\n\r");
            break;
            
        case 0b10:
            printf("AVDD and VREFL\n\r");
            break;
            
        case 0b11:
            printf("VREFH and VREFL\n\r");
            break;
        
    }
    
    // Print analog enable status    
    if (ADCANCONbits.ANEN0) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC0 is %s\n\r", ADCANCONbits.ANEN0 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN1) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC1 is %s\n\r", ADCANCONbits.ANEN1 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN2) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC2 is %s\n\r", ADCANCONbits.ANEN2 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN3) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC3 is %s\n\r", ADCANCONbits.ANEN3 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN4) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC4 is %s\n\r", ADCANCONbits.ANEN4 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN7) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC7 is %s\n\r", ADCANCONbits.ANEN7 ? "analog enabled" : "analog disabled");
    
    // print wakeup status bits
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC warmup count exponent = %d\n\r", ADCANCONbits.WKUPCLKCNT);
    
    // print wakeup status bits
    if (ADCANCONbits.WKRDY0) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC0 is %s\n\r", ADCANCONbits.WKRDY0 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY1) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC1 is %s\n\r", ADCANCONbits.WKRDY1 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY2) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC2 is %s\n\r", ADCANCONbits.WKRDY2 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY3) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC3 is %s\n\r", ADCANCONbits.WKRDY3 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY4) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC4 is %s\n\r", ADCANCONbits.WKRDY4 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY7) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC7 is %s\n\r", ADCANCONbits.WKRDY7 ? "warmed up" : "cold");
    
    // print configuration data
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC0 config data: 0x%08X\n\r", ADC0CFG);
    printf("    ADC1 config data: 0x%08X\n\r", ADC1CFG);
    printf("    ADC2 config data: 0x%08X\n\r", ADC2CFG);
    printf("    ADC3 config data: 0x%08X\n\r", ADC3CFG);
    printf("    ADC4 config data: 0x%08X\n\r", ADC4CFG);
    printf("    ADC7 config data: 0x%08X\n\r", ADC7CFG);
    
    terminalTextAttributesReset();
    
}