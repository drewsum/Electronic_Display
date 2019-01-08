/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _DEVICE_CONTROL_H    /* Guard against multiple inclusion */
#define _DEVICE_CONTROL_H

#include <xc.h>

#include "32mz_interrupt_control.h"

// Unlock system function
// This function unlocks the device so that device parameters can be changed
// and the microcontroller can be reset
void deviceUnlock(void);


// Lock system function
// This function re-locks the system so that important device parameters may 
// not be changed
void deviceLock(void);

// Rest device function
// This function resets the microcontroller
void deviceReset(void);

// This function initializes the system clocks
void clockInitialize(void);


#endif /* _DEVICE_CONTROL_H */

/* *****************************************************************************
 End of File
 */
