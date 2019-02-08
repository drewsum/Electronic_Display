/* ************************************************************************** */
/** Analog to Digital Converter

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    adc.h

  @Summary
 Gives APIs for controlling ADC and measuring application channels

 */
/* ************************************************************************** */

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

#ifndef _ADC_H    /* Guard against multiple inclusion */
#define _ADC_H

#include <xc.h>

// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>

// This structure holds ADC measurement results
struct adc_results_t {
    
    double POS3P3_adc;
    uint32_t POS3P3_adc_raw;
    double POS12_adc;
    uint32_t POS12_adc_raw;
    double POS5P5_adc;
    uint32_t POS5P5_adc_raw;
    double POS5_adc;
    uint32_t POS5_adc_raw;
    double POS5P_adc;
    uint32_t POS5P_adc_raw;
    
} adc_results;


// This function initializes the ADC modules
void ADCInitialize(void);

// This function initializes Timer3 as the ADC trigger timer
void ADCTriggerTimerInitialize(void);

// This is the interrupt service routine for ADC7 warm up
void __ISR(_ADC7_WARM_VECTOR, IPL4SRS) ADC7WarmISR(void);

// This is the POS3P3_ADC Interrupt Service Routine
void __ISR(_ADC_DATA38_VECTOR, IPL1SRS) POS3P3ADCISR(void);

// This is the POS12_ADC Interrupt Service Routine
void __ISR(_ADC_DATA39_VECTOR, IPL1SRS) POS12ADCISR(void);

// This is the POS5_ADC Interrupt Service Routine
void __ISR(_ADC_DATA40_VECTOR, IPL1SRS) POS5ADCISR(void);

// This is the POS5P5_ADC Interrupt Service Routine
void __ISR(_ADC_DATA41_VECTOR, IPL1SRS) POS5P5ADCISR(void);

// This is the POS5P_ADC Interrupt Service Routine
void __ISR(_ADC_DATA42_VECTOR, IPL1SRS) POS5PADCISR(void);



#endif /* _ADC_H */

/* *****************************************************************************
 End of File
 */
