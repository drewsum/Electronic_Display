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

// ADC constants macros
#define ADC_VOLTS_PER_LSB           0.000805861
#define POS3P3_ADC_GAIN             2.0
#define POS12_ADC_GAIN              11.0
#define POS5_ADC_GAIN               2.0
#define POS5P5_ADC_GAIN             2.0
#define POS5P_ADC_GAIN              2.0

// Hardcoded individual channel calibration settings
// These were determined with a DMM and reading un-calibrated results
#define POS3P3_ADC_CAL             1.07863
#define POS12_ADC_CAL              1.00207
#define POS5_ADC_CAL               1.21116
#define POS5P5_ADC_CAL             1.37007
#define POS5P_ADC_CAL              1.21116


// This structure holds ADC measurement results
struct adc_results_t {
    
    double POS3P3_adc;
    double POS3P3_adc_min;
    double POS3P3_adc_max;
    uint32_t POS3P3_adc_raw;
    double POS12_adc;
    double POS12_adc_min;
    double POS12_adc_max;
    uint32_t POS12_adc_raw;
    double POS5P5_adc;
    double POS5P5_adc_min;
    double POS5P5_adc_max;
    uint32_t POS5P5_adc_raw;
    double POS5_adc;
    double POS5_adc_min;
    double POS5_adc_max;
    uint32_t POS5_adc_raw;
    double POS5P_adc;
    double POS5P_adc_min;
    double POS5P_adc_max;
    uint32_t POS5P_adc_raw;
    double vref_adc;
    uint32_t vref_adc_raw;
    double die_temp_adc;
    double die_temp_adc_min;
    double die_temp_adc_max;
    uint32_t die_temp_adc_raw;
    
} adc_results;

// This is an ADC result scaling factor calculated using the internal reference voltage
double adc_cal_gain;

// This function initializes the ADC modules
void ADCInitialize(void);

// This function initializes Timer3 as the ADC trigger timer
void ADCTriggerTimerInitialize(void);

// This function is the analog circuits ready interrupt service routine
void __ISR(_ADC_ARDY_VECTOR, IPL4SRS) ADCAnalogReadyISR(void);

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

// This is the VREF_ADC Interrupt Service Routine
void __ISR(_ADC_DATA43_VECTOR, IPL1SRS) VREFADCISR(void);

// This is the DIE_TEMP_ADC Interrupt service Routine
void __ISR(_ADC_DATA44_VECTOR, IPL1SRS) DieTempADCISR(void);

// This is the ADC end of scan interrupt service routine
void __ISR(_ADC_EOS_VECTOR, IPL1SRS) ADCEndOfScanISR(void);

// This function prints the status of the ADC
void printADCStatus(void);



#endif /* _ADC_H */

/* *****************************************************************************
 End of File
 */
