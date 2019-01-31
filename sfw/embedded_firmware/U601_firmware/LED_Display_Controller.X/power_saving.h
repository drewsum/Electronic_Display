/* ************************************************************************** */
/** Power Saving

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    power_saving.h

  @Summary
 Gives APIs for disabling unused peripherals and entering/exiting sleep mode, etc

 */
/* ************************************************************************** */

#ifndef _POWER_SAVING_H    /* Guard against multiple inclusion */
#define _POWER_SAVING_H

#include <xc.h>

#include "device_control.h"


// This function disables unused peripherals on startup for power savings
// THIS FUNCTION CAN ONLY BE CALLED ONCE DUE TO PMD LOCKOUT AFTER ONE WRITE SESSION
void PMDInitialize(void);

// This function prints the status of PMD settings
void printPMDStatus(void);


#endif /* _POWER_SAVING_H */

/* *****************************************************************************
 End of File
 */
