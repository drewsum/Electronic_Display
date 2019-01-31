/* ************************************************************************** */
/** Watchdog Timer

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    watchdog_timer.h

  @Summary
 Sets up the watchdog timer for a 2 second timeout

 */
/* ************************************************************************** */

#ifndef _WATCHDOG_TIMER_H    /* Guard against multiple inclusion */
#define _WATCHDOG_TIMER_H

#include <xc.h>

#include "error_handler.h"

// Hardcoded description strings
#define WATCHDOG_TIMER_TIMEOUT_STR          "2.048 seconds"
#define DEADMAN_TIMER_TIMEOUT_STR           "2147483648 instruction fetches"

// This function initializes the watchdog timer for a timeout period of 
// 2 seconds, and no window (window always open)
void watchdogTimerInitialize(void);

// This function starts the watchdog timer
void startWatchdogTimer(void);

// This function stops the watchdog timer
void stopWatchdogTimer(void);

// This function clears the watchdog timer
void kickTheDog(void);

// This function initializes the deadman timer
void deadmanTimerInitialize(void);

// This function starts the deadman timer
void startDeadmanTimer(void);

// This function stops the deadman timer
void stopDeadmanTimer(void);

// This function clears the deadman timer
void holdThumbTighter(void);

// This function verifies the DMT has been cleared properly
void verifyThumbTightEnough(void);

// This function returns a string with information on the watchdog timer
char * getStringWatchdogStatus(void);

// This function returns a string with information on the deadman timer
char * getStringDeadmanStatus(void);

#endif /* _WATCHDOG_TIMER_H */

/* *****************************************************************************
 End of File
 */
