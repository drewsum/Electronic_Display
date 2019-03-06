
#include <xc.h>

#include "error_handler.h"

#include "cause_of_reset.h"


// This function determines the cause of the most recent device reset and
// assigns it to the reset_cause enumeration
reset_cause_t getResetCause(void) {
 
    reset_cause_t reset_cause;
    
    if (RCONbits.POR) {
    
        reset_cause = POR_Reset;
        RCONbits.POR = 0;
        
    }
    
    else if (RCONbits.BOR) {
     
        reset_cause = BOR_Reset;
        RCONbits.BOR = 0;
        
    }
    
    
    else if (RCONbits.EXTR) {
     
        reset_cause = External_Reset;
        RCONbits.EXTR = 0;
        
    }
    
    else if (RCONbits.SWR) {
     
        reset_cause = Software_Reset;
        RCONbits.SWR = 0;
        
    }
    
    else if (RCONbits.CMR) {
     
        reset_cause = Config_Mismatch;
        RCONbits.CMR = 0;
        
    }
    
    else if (RCONbits.DMTO) {
     
        reset_cause = DMT_Reset;
        RCONbits.DMTO = 0;
        
    }
    
    else if (RCONbits.WDTO) {
     
        reset_cause = WDT_Reset;
        RCONbits.WDTO = 0;
        
    }
    
    else if (RCONbits.SLEEP) {
     
        reset_cause = Wake_From_Sleep;
        RCONbits.SLEEP = 0;
        
    }
    
    else if (RCONbits.IDLE) {
     
        reset_cause = Wake_From_Idle;
        RCONbits.IDLE = 0;
        
    }
    
    else {
     
        reset_cause = Undefined;
        error_handler.other_error_flag = 1;
        
    }
    
    if (RCONbits.BCFGERR) {
    
        error_handler.configuration_error_flag = 1;
        RCONbits.BCFGERR = 0;
        
    }
    
    if (RCONbits.BCFGFAIL) {
     
        error_handler.configuration_error_flag = 1;
        RCONbits.BCFGFAIL = 0;
        
    }

    
    return reset_cause;
    
}

// This function returns a string describing the type of device reset that occurred
char * getResetCauseString(reset_cause_t input_cause) {
 
    static char *reset_descriptor_array[] = {
        
        "Undefined",
        "Primary Configuration Registers Error",
        "Primary/Secondary Configuration Registers Error",
        "Configuration Mismatch",
        "External Reset (Master clear)",
        "Software Reset",
        "Deadman Timer Reset",
        "Watchdog Timer Reset",
        "Wake from Sleep",
        "Wake from Idle",
        "Brown Out Reset",
        "Power On Reset"
        
    };
    
    return reset_descriptor_array[input_cause];
    
}

