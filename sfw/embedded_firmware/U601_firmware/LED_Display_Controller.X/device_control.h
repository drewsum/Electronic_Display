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

// Hardcoded Clock Setting Integers, in Hertz
#define SYSCLK_INT          252000000
#define REFCLK1_INT         0
#define REFCLK2_INT         0
#define REFCLK3_INT         0
#define REFCLK4_INT         0
#define PBCLK1_INT          84000000
#define PBCLK2_INT          84000000
#define PBCLK3_INT          15750000
#define PBCLK4_INT          84000000
#define PBCLK5_INT          84000000
#define PBCLK7_INT          252000000
#define PBCLK8_INT          84000000

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

// This function is a software delay that simply counts loops while decrementing
// the argument
void softwareDelay(uint32_t inputDelay);

// This function initializes the system clocks
void clockInitialize(void);

// This function returns a formatted string of a given clock setting from an integer
char * stringFromClockSetting(uint32_t clock_integer);

// This function unlocks peripheral pin select
// THIS CAN ONLY BE CALLED ONCE PER DEVICE RESET!!!
void PPSUnlock(void);

// This function locks peripheral pin select
void PPSLock(void);

// This function unlocks peripheral module disable
void PMDUnlock(void);

// This function locks peripheral module disable
void PMDLock(void);



#endif /* _DEVICE_CONTROL_H */

/* *****************************************************************************
 End of File
 */
