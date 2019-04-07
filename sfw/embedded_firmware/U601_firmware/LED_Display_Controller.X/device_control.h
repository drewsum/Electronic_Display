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
inline void softwareDelay(uint32_t inputDelay);

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

// This function returns a string containing the device's serial number
char * getStringSerialNumber(void);

// This function returns a 32 bit device ID
uint32_t getDeviceID(void);

// This function returns a string with the part number of the device from the device ID
char * getDeviceIDString(uint32_t device_ID);

// This function returns an 8 bit revision ID
uint8_t getRevisionID(void);

// This function returns a string with the revision ID
char * getRevisionIDString(uint8_t revision_ID);

// This function prints clock settings, requires a given input sysclk
void printClockStatus(uint32_t input_sysclk);


// This function initializes the random number generator
void RNGInitialize(void);

#endif /* _DEVICE_CONTROL_H */

/* *****************************************************************************
 End of File
 */
