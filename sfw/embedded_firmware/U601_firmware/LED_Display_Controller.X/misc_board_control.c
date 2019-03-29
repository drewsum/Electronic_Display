
#include <xc.h>
#include <stdio.h>
#include <string.h>

#include "gpio_setup.h"
#include "misc_board_control.h"
#include "32mz_interrupt_control.h"
#include "pin_macros.h"
#include "adc.h"
#include "terminal_control.h"
#include "error_handler.h"
#include "panel_control.h"


// Initialize change notifications
void changeNotificationInit(void) {
    
    // Disable Interrupts
    disableInterrupt(PORTF_Input_Change_Interrupt);
    disableInterrupt(PORTK_Input_Change_Interrupt);
    
    // Configuration for Port F
    CNCONFbits.ON           = 1;
    CNCONFbits.EDGEDETECT   = 1;        
    
    // Configuration for Port K
    CNCONKbits.ON           = 1;
    CNCONKbits.EDGEDETECT   = 1;        
    
    // Interrupt Priorities
    setInterruptPriority(PORTF_Input_Change_Interrupt, 2);
    setInterruptPriority(PORTK_Input_Change_Interrupt, 2);
    setInterruptSubpriority(PORTF_Input_Change_Interrupt, 1);
    setInterruptSubpriority(PORTK_Input_Change_Interrupt, 1);
    
    // Clear interrupt flag
    clearInterruptFlag(PORTF_Input_Change_Interrupt);
    clearInterruptFlag(PORTK_Input_Change_Interrupt);
    
    // Enable change notification interrupt enable bit
    enableInterrupt(PORTF_Input_Change_Interrupt);
    enableInterrupt(PORTK_Input_Change_Interrupt);
        
}



// Port F ISR
void __ISR(_CHANGE_NOTICE_F_VECTOR, IPL2SRS) portFCNISR(void) {
    
    if (CNFFbits.CNFF1 && CNNEFbits.CNNEF1) {
            
        pos12PGoodFEHandler();
    
    }
    
    if (CNFFbits.CNFF3 && CNNEFbits.CNNEF3) {
            
        pos5PGoodFEHandler();
                
    }
    
    if (CNFFbits.CNFF8 && CNNEFbits.CNNEF8) {
            
        pos5pPGoodFEHandler();
         
    }
    
    if (CNFFbits.CNFF12 && CNNEFbits.CNNEF12) {
            
        pos5pThermalWarningFEHandler();

    }
    
    clearInterruptFlag(PORTF_Input_Change_Interrupt);
    
}

// Port K ISR
void __ISR(_CHANGE_NOTICE_K_VECTOR, IPL2SRS) portKCNISR(void) {
    
    if (CNFKbits.CNFK4 && CNNEKbits.CNNEK4) {
            
        displayEnableFEHandler();
                   
    }
    
    if (CNFKbits.CNFK5 && CNENKbits.CNIEK5) {
            
        encoderStepREHandler();
        
    }
    
    if (CNFKbits.CNFK7 && CNNEKbits.CNNEK7) {
            
        pos3p3PGoodFEHandler();
                            
    }
    
    clearInterruptFlag(PORTK_Input_Change_Interrupt);

}

// POS5P Thermal Warning falling edge interrupt handler
void pos5pThermalWarningFEHandler(void) {
    
    
    error_handler.POS5P_thermal_warning_error_flag = 1;
    
}

// POS12 PGOOD falling edge interrupt handler
void pos12PGoodFEHandler(void) {  
       
    // Display on USB UART the value of ADC
    terminalTextAttributesReset();
    terminalTextAttributes(RED, BLACK, NORMAL);
    printf("+12V Input Voltage Measurement: %+0.3f V\n\r", adc_results.POS12_adc);
    terminalTextAttributesReset();
    
    // flag error
    error_handler.POS12_regulation_error_flag = 1;
            
}

// POS5 PGOOD falling edge interrupt handler
void pos5PGoodFEHandler(void) {
    
    // Display on USB UART the value of ADC
    terminalTextAttributesReset();
    terminalTextAttributes(RED, BLACK, NORMAL);
    printf("+5V Power Supply Measurement: %+0.3f V\n\r", adc_results.POS5_adc);
    terminalTextAttributesReset();
    
    // flag error
    error_handler.POS5_regulation_error_flag = 1;
    
}

// POS5P PGOOD falling edge interrupt handler
void pos5pPGoodFEHandler(void) {
     
    // Display on USB UART the value of ADC
    terminalTextAttributesReset();
    terminalTextAttributes(RED, BLACK, NORMAL);    
    printf("+5VP LED Power Supply Measurement: %+0.3f V\n\r", adc_results.POS5P_adc);
    terminalTextAttributesReset();
    
    // flag error
    error_handler.POS5P_regulation_error_flag = 1;

}

// Display enable falling edge interrupt handler
void displayEnableFEHandler(void) {
    
    if (T5CONbits.ON) {
        
        panelMultiplexingSuspend();
                
    } else {
        
        panelMultiplexingTimerStart();
                
    }
    
}

// Encoder step rising edge interrupt handler
void encoderStepREHandler(void) {
    
    uint8_t current_brightness = (OC4R * 100) / PR2;
    
    // if ENCODER_DIR_PIN is high, we are rotating clockwise
    if (ENCODER_DIR_PIN) {
        
        // If we are not at maximum brightness, make brighter
        if (current_brightness < 100) {
            
            panelPWMSetBrightness(current_brightness + 10);
            
        }
        
    } else {
        
        // if we are not at minimum brightness, make dimmer
        if (current_brightness > 0) {
        
            panelPWMSetBrightness(current_brightness - 10);
            
        }   
        
    }
    
}

// POS3P3 PGOOD falling edge interrupt handler
void pos3p3PGoodFEHandler(void) {
           
    // Display on USB UART the value of ADC
    terminalTextAttributesReset();
    terminalTextAttributes(RED, BLACK, NORMAL);
    printf("+3.3V Power Supply Measurement: %+0.3f V\n\r", adc_results.POS3P3_adc);
    terminalTextAttributesReset();

    // flag error
    error_handler.POS3P3_regulation_error_flag = 1;
    
}
