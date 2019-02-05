/* ************************************************************************** */
/** Prefetch

  @Company
 Marquette Senior Design E44

  @File Name
     prefetch.h

 */
/* ************************************************************************** */

#ifndef _PREFETCH_H    /* Guard against multiple inclusion */
#define _PREFETCH_H

#include <xc.h>

// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>


// This function initializes the prefetch module
void prefetchInitialize(void);

// This is the prefetch SEC event interrupt service routine
void __ISR(_PREFETCH_VECTOR, ipl4SRS) prefetchSECEventISR(void);

// This function prints the status of the prefetch module
void printPrefetchStatus(void);


#endif /* _PREFETCH_H */

/* *****************************************************************************
 End of File
 */
