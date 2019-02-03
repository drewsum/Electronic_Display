
#include <xc.h>
#include <stdio.h>

#include "error_handler.h"
#include "32mz_interrupt_control.h"
#include "pin_macros.h"

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

// This function is called when a general exception occurs
void __attribute__((nomips16)) _general_exception_handler(void) {
    
    // binary expression of exception cause
//    uint8_t exception_cause = (_CP0_GET_CAUSE() & 0x0000007C) >> 2;
//    HEARTBEAT_LED_PIN       = (exception_cause && 0x01) >> 0;
//    OTHER_ERROR_LED_PIN     = (exception_cause && 0x02) >> 1;
//    USB_ERROR_LED_PIN       = (exception_cause && 0x04) >> 2;
//    EBI_ERROR_LED_PIN       = (exception_cause && 0x08) >> 3;
//    WIFI_ERROR_LED_PIN      = (exception_cause && 0x10) >> 4;
//    SPI_ERROR_LED_PIN       = (exception_cause && 0x20) >> 5;
//    nACTIVE_LED_PIN         = (exception_cause && 0x40) >> 6;
    // Signal to user something really bad happened
    EBI_ERROR_LED_PIN = 1;
    SPI_ERROR_LED_PIN = 1;
    WIFI_ERROR_LED_PIN = 1;
    USB_ERROR_LED_PIN = 1;
    OTHER_ERROR_LED_PIN = 1;
    nACTIVE_LED_PIN = 1;
    
    // Disable global interrupts
    setGlobalInterruptsState(0);
    
    // Clear watchdog and deadman to give user time to see error state
    kickTheDog();
    holdThumbTighter();
    
    // Give up
    // Wait for watchdog to save us
    while(1);
    
    // Half-baked exception recovery
    // _CP0_SET_EPC(_CP0_GET_EPC()+4); // increment Error Program Counter (EPC) to next word (skip over offending instruction)
    
}

// This function is called when a TRB exception occurs
void __attribute__((nomips16)) _simple_tlb_refill_exception_handler(void) {

    // Signal to user something really bad happened
    EBI_ERROR_LED_PIN = 1;
    SPI_ERROR_LED_PIN = 1;
    WIFI_ERROR_LED_PIN = 1;
    USB_ERROR_LED_PIN = 1;
    OTHER_ERROR_LED_PIN = 1;
    nACTIVE_LED_PIN = 1;
    
    // Clear watchdog to give user time to see error state
    kickTheDog();
    
    // Give up
    // Wait for watchdog to save us
    while(1);
    
    // Half-baked exception recovery
    // _CP0_SET_EPC(_CP0_GET_EPC()+4); // increment Error Program Counter (EPC) to next word (skip over offending instruction)
    
}

// This function is called when a cache error occurs
void __attribute__((nomips16)) _cache_err_exception_handler(void) {

    // Signal to user something really bad happened
    EBI_ERROR_LED_PIN = 1;
    SPI_ERROR_LED_PIN = 1;
    WIFI_ERROR_LED_PIN = 1;
    USB_ERROR_LED_PIN = 1;
    OTHER_ERROR_LED_PIN = 1;
    nACTIVE_LED_PIN = 1;
    
    // Clear watchdog to give user time to see error state
    kickTheDog();
    
    // Give up
    // Wait for watchdog to save us
    while(1);
    
    // Half-baked exception recovery
    // _CP0_SET_EPC(_CP0_GET_EPC()+4); // increment Error Program Counter (EPC) to next word (skip over offending instruction)
    
}

// This function is called when a bootstrap exception occurs
void __attribute__((nomips16)) _bootstrap_exception_handler(void) {

    // Signal to user something really bad happened
    EBI_ERROR_LED_PIN = 1;
    SPI_ERROR_LED_PIN = 1;
    WIFI_ERROR_LED_PIN = 1;
    USB_ERROR_LED_PIN = 1;
    OTHER_ERROR_LED_PIN = 1;
    nACTIVE_LED_PIN = 1;
    
    // Clear watchdog to give user time to see error state
    kickTheDog();
    
    // Give up
    // Wait for watchdog to save us
    while(1);
    
    // Half-baked exception recovery
    // _CP0_SET_EPC(_CP0_GET_EPC()+4); // increment Error Program Counter (EPC) to next word (skip over offending instruction)
    
}

