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

// POS5P Thermal Warning interrupt handler
void pos5pThermalWarningHandler(void);

// POS12 PGOOD interrupt handler
void pos12PGoodHandler(void);

// POS5 PGOOD interrupt handler
void pos5PGoodHandler(void);

// POS5P PGOOD interrupt handler
void pos5pPGoodHandler(void);

// Display enable interrupt handler
void displayEnableHandler(void);

// Encoder step interrupt handler
void encoderStepHandler(void);

// POS3P3 PGOOD interrupt handler
void pos3p3PGoodHandler(void);



#endif /* _MISC_BOARD_CONTROL_H */

/* *****************************************************************************
 End of File
 */
