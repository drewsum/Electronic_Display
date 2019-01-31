
#include <xc.h>

#include "error_handler.h"

#include "cause_of_reset.h"


// This function determines the cause of the most recent device reset and
// assigns it to the reset_cause enumeration
reset_cause_t getResetCause(void) {
 
    reset_cause_t reset_cause;
    
    if (RCONbits.EXTR) {
     
        reset_cause = External_Reset;
        
    }
    
    else if (RCONbits.SWR) {
     
        reset_cause = Software_Reset;
        
    }
    
    else if (RCONbits.DMTO) {
     
        reset_cause = DMT_Reset;
        
    }
    
    else if (RCONbits.WDTO) {
     
        reset_cause = WDT_Reset;
        
    }
    
    else if (RCONbits.SLEEP) {
     
        reset_cause = Wake_From_Sleep;
        
    }
    
    else if (RCONbits.IDLE) {
     
        reset_cause = Wake_From_Idle;
        
    }
    
    else if (RCONbits.BOR) {
     
        reset_cause = BOR_Reset;
        
    }
    
    else if (RCONbits.POR) {
     
        reset_cause = POR_Reset;
        
    }
    
    else if (RCONbits.BCFGERR) {
     
        reset_cause = Primary_Config_Registers_Error;
        
    }
    
    else if (RCONbits.BCFGFAIL) {
     
        reset_cause = Primary_Secondary_Config_Registers_Error;
        
    }
    
    else if (RCONbits.CMR) {
     
        reset_cause = Config_Mismatch;
        
    }
    
    else {
     
        reset_cause = Undefined;
        error_handler.other_error_flag = 1;
        
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

