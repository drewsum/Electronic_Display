/* ************************************************************************** */
/** Cause of Reset

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    cause_of_reset.h

  @Summary
 Determines the cause of the most recent device reset

/* ************************************************************************** */

#ifndef _CAUSE_OF_RESET_H    /* Guard against multiple inclusion */
#define _CAUSE_OF_RESET_H


// Enumeration defining different types of device resets
typedef enum {
            
    Undefined                                   = 0,
    Primary_Config_Registers_Error              = 1,
    Primary_Secondary_Config_Registers_Error    = 2,
    Config_Mismatch                             = 3,
    External_Reset                              = 4,
    Software_Reset                              = 5,
    DMT_Reset                                   = 6,
    WDT_Reset                                   = 7,
    Wake_From_Sleep                             = 8,
    Wake_From_Idle                              = 9,
    BOR_Reset                                   = 10,
    POR_Reset                                   = 11

} reset_cause_t;

// This function determines the cause of the most recent device reset and
// assigns it to the reset_cause enumeration
reset_cause_t getResetCause(void);

// This function returns a string describing the type of device reset that occurred
char * getResetCauseString(reset_cause_t input_cause);



#endif /* _CAUSE_OF_RESET_H */

/* *****************************************************************************
 End of File
 */
