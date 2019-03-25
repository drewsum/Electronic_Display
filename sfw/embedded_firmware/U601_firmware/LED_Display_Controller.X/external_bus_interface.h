/* ************************************************************************** */
/** External Bus Interface (EBI)

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    external_bus_interface.h

  @Summary
 APIs for setting up and using EBI with a 2 Mb external SRAM
 
 */
/* ************************************************************************** */

#ifndef _EXTERNAL_BUS_INTERFACE_H    /* Guard against multiple inclusion */
#define _EXTERNAL_BUS_INTERFACE_H

#define EBI_SRAM_SIZE 262144

// EBI initialization function

void ebiInitialize(void);

// Print EBI status

void printEBIStatus(void);

// This function loops through all possible external memory addresses and tests to
// see if the writes and reads actually work
// Returns 0 if test failure
// returns 1 for test success
uint8_t testEBISRAM(void);

// This function clears all bits in the EBI SRAM
void clearEBISRAM(void);

// Prints contents of EBI SRAM
void ebiPrintSRAM(void);


#endif /* _EXTERNAL_BUS_INTERFACE_H */

/* *****************************************************************************
 End of File
 */
