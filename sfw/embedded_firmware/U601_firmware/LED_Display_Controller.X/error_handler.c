
#include <xc.h>

#include "error_handler.h"
#include "32mz_interrupt_control.h"

// This function initializes the error handler structure to detect fault conditions
void errorHandlerInitialize(void) {
 
    // Setup system bus protection violation interrupt
    disableInterrupt(System_Bus_Protection_Violation);
    setInterruptPriority(System_Bus_Protection_Violation, 1);
    setInterruptSubpriority(System_Bus_Protection_Violation, 1);
    clearInterruptFlag(System_Bus_Protection_Violation);
    enableInterrupt(System_Bus_Protection_Violation);
    
}

// System Bus Protection Violation interrupt service routine
void __ISR(_SYSTEM_BUS_PROTECTION_VECTOR, ipl1AUTO) systemBusProtectionISR(void) {
 
    // Record a system bus protection violation occurred
    error_handler.system_bus_protection_violation_flag = 1;
    clearInterruptFlag(System_Bus_Protection_Violation);
    
}