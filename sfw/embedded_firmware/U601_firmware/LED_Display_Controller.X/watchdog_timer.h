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


// This function initializes the watchdog timer for a timeout period of 
// 2 seconds, and no window (window always open)
void watchdogTimerInitialize(void);

#endif /* _WATCHDOG_TIMER_H */

/* *****************************************************************************
 End of File
 */
