/* ************************************************************************** */
/** Miscellaneous Board Control

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    misc_board_control.h

  @Summary
 Gives APIs for controlling miscellaneous functionality of the logic board/power board

 */
/* ************************************************************************** */

#ifndef _MISC_BOARD_CONTROL_H    /* Guard against multiple inclusion */
#define _MISC_BOARD_CONTROL_H

#include <xc.h>

#include <sys/attribs.h>

// Initialize change notifications
void changeNotificationInit(void);

// Port F ISR
void __ISR(_CHANGE_NOTICE_F_VECTOR, IPL2SRS) portFCNISR(void);

// Port K ISR
void __ISR(_CHANGE_NOTICE_K_VECTOR, IPL2SRS) portKCNISR(void);

// POS5P Thermal Warning falling edge interrupt handler
void pos5pThermalWarningFEHandler(void);

// POS12 PGOOD falling edge interrupt handler
void pos12PGoodFEHandler(void);

// POS5 PGOOD falling edge interrupt handler
void pos5PGoodFEHandler(void);

// POS5P PGOOD falling edge interrupt handler
void pos5pPGoodFEHandler(void);

// Display enable falling edge interrupt handler
void displayEnableFEHandler(void);

// Encoder step rising edge interrupt handler
void encoderStepREHandler(void);

// POS3P3 PGOOD falling edge interrupt handler
void pos3p3PGoodFEHandler(void);

#endif /* _MISC_BOARD_CONTROL_H */

/* *****************************************************************************
 End of File
 */
