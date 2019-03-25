
#include <xc.h>

#include "gpio_setup.h"
#include "misc_board_control.h"
#include "32mz_interrupt_control.h"
#include "pin_macros.h"


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
    
        pos12PGoodHandler();
    
    }
    
    if (CNFFbits.CNFF3 && CNNEFbits.CNNEF3) {
    
        pos5PGoodHandler();
        
    }
    
    if (CNFFbits.CNFF8 && CNNEFbits.CNNEF8) {
    
        pos5pPGoodHandler();
    
    }
    
    
    if (CNFFbits.CNFF12 && CNNEFbits.CNNEF12) {
        
        pos5pThermalWarningHandler();
        
    }
    
    clearInterruptFlag(PORTF_Input_Change_Interrupt);
    
}

// Port K ISR
void __ISR(_CHANGE_NOTICE_K_VECTOR, IPL2SRS) portKCNISR(void) {
    
    if (CNFKbits.CNFK4 && CNNEKbits.CNNEK4) {
        
        displayEnableHandler();
        
    }
    
    if (CNFKbits.CNFK5 && CNENKbits.CNIEK5) {
        
        encoderStepHandler();
        
    }
    
    if (CNFKbits.CNFK7 && CNNEKbits.CNNEK7) {
        
        pos3p3PGoodHandler();
        
    }
    
    clearInterruptFlag(PORTK_Input_Change_Interrupt);

}

// POS5P Thermal Warning interrupt handler
void pos5pThermalWarningHandler(void) {
    
    // Turn POS5 Run pin low and turn on error LED
    OTHER_ERROR_LED_PIN = 1;
    POS5_RUN_PIN = 0;
    
    // Wait until POS5P THWN pin is high again
    while(!nPOS5P_THWN_PIN);
    
    // Turn POS5 Run pin high and turn off error LED
    OTHER_ERROR_LED_PIN = 0;
    POS5_RUN_PIN = 1;
    
}

// POS12 PGOOD interrupt handler
void pos12PGoodHandler(void) {
    
    // Turn on error LED
    OTHER_ERROR_LED_PIN = 1;   
    
    
    
    
    // Turn off error LED
    OTHER_ERROR_LED_PIN = 0;
}

// POS5 PGOOD interrupt handler
void pos5PGoodHandler(void) {
    
    // Turn POS5 Run pin low and turn on error LED
    OTHER_ERROR_LED_PIN = 1;
    POS5_RUN_PIN = 0;
    
    // Wait until POS5 PGOOD pin is high again
    while(!POS5_PGOOD_PIN);
    
    // Turn POS5 Run pin high and turn off error LED
    OTHER_ERROR_LED_PIN = 0;
    POS5_RUN_PIN = 1;
    
}

// POS5P PGOOD interrupt handler
void pos5pPGoodHandler(void) {
    
    // Turn POS5 Run pin low and turn on error LED
    OTHER_ERROR_LED_PIN = 1;
    POS5_RUN_PIN = 0;
    
    // Wait until POS5P PGOOD pin is high again
    while(!POS5P_PGOOD_PIN);
    
    // Turn POS5 Run pin high and turn off error LED
    OTHER_ERROR_LED_PIN = 0;
    POS5_RUN_PIN = 1;
    
}

// Display enable interrupt handler
void displayEnableHandler(void) {
    
    
    
}

// Encoder step interrupt handler
void encoderStepHandler(void) {
    
    
    
}

// POS3P3 PGOOD interrupt handler
void pos3p3PGoodHandler(void) {
    
    
    
}



