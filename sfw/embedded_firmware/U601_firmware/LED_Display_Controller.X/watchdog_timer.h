/* ************************************************************************** */
/** Watchdog Timer

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    watchdog_timer.h

  @Summary
 Sets up the watchdog timer for a 2.048 second timeout

 */
/* ************************************************************************** */

#ifndef _WATCHDOG_TIMER_H    /* Guard against multiple inclusion */
#define _WATCHDOG_TIMER_H

#include <xc.h>
// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>


#include "error_handler.h"
#include "32mz_interrupt_control.h"

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

// This function prints information on the watchdog timer
void printWatchdogStatus(void);

// This function prints information on the deadman timer
void printDeadmanStatus(void);

#endif /* _WATCHDOG_TIMER_H */

/* *****************************************************************************
 End of File
 */
