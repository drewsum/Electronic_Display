
#include <xc.h>
#include <stdio.h>

#include "error_handler.h"
#include "32mz_interrupt_control.h"
#include "pin_macros.h"
#include "terminal_control.h"

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

// This function prints the status of the error handler flags
void printErrorHandlerStatus(void) {
 
    terminalTextAttributesReset();    
    
    terminalTextAttributes(GREEN, BLACK, UNDERSCORE);
    
    // Print heading
    printf("Error Handler Status:\n\r");
    
    // Print status of each error handler element
    // Configuration Error
    if (error_handler.configuration_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   Configuration error %s\n\r", error_handler.configuration_error_flag ? "has occurred" : "has not occurred");
    
    // EBI Error
    if (error_handler.EBI_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   EBI SRAM error %s\n\r", error_handler.EBI_error_flag ? "has occurred" : "has not occurred");
    
    // SPI Error
    if (error_handler.SPI_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   SPI Flash error %s\n\r", error_handler.SPI_error_flag ? "has occurred" : "has not occurred");
    
    // WIFI Error
    if (error_handler.WIFI_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   WIFI Module error %s\n\r", error_handler.WIFI_error_flag ? "has occurred" : "has not occurred");
    
    // USB Error
    if (error_handler.USB_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   USB UART error %s\n\r", error_handler.USB_error_flag ? "has occurred" : "has not occurred");
    
    // Other Error
    if (error_handler.other_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   Other errors %s\n\r", error_handler.other_error_flag ? "have occurred" : "have not occurred");
    
    // POS5P Thermal Warning Error
    if (error_handler.POS5P_thermal_warning_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   POS5P thermal warning %s\n\r", error_handler.POS5P_thermal_warning_error_flag ? "has occurred" : "has not occurred");
    
    // POS3P3 Regulation Error
    if (error_handler.POS3P3_regulation_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   POS3P3 regulation error %s\n\r", error_handler.POS3P3_regulation_error_flag ? "has occurred" : "has not occurred");
    
    // POS5 Regulation Error
    if (error_handler.POS5_regulation_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   POS5 regulation error %s\n\r", error_handler.POS5_regulation_error_flag ? "has occurred" : "has not occurred");
    
    // POS12 Regulation Error
    if (error_handler.POS12_regulation_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   POS12 regulation error %s\n\r", error_handler.POS12_regulation_error_flag ? "has occurred" : "has not occurred");
    
    // POS5P Regulation Error
    if (error_handler.POS5P_regulation_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   POS5P regulation error %s\n\r", error_handler.POS5P_regulation_error_flag ? "has occurred" : "has not occurred");
    
    // POS5P5 Regulation Error
    if (error_handler.POS5P5_regulation_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   POS5P5 regulation error %s\n\r", error_handler.POS5P5_regulation_error_flag ? "has occurred" : "has not occurred");
    
    // DMT Error
    if (error_handler.DMT_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   Deadman Timer error %s\n\r", error_handler.DMT_error_flag ? "has occurred" : "has not occurred");
    
    // System Bus Protection Error
    if (error_handler.system_bus_protection_violation_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   System bus protection violation error %s\n\r", error_handler.system_bus_protection_violation_flag ? "has occurred" : "has not occurred");
    
    
    
    
    
    terminalTextAttributesReset();    
    
}

// This function clears the error handler flags
void clearErrorHandler(void) {
 
    error_handler.DMT_error_flag = 0;
    error_handler.EBI_error_flag = 0;
    error_handler.POS12_regulation_error_flag = 0;
    error_handler.POS3P3_regulation_error_flag = 0;
    error_handler.POS5P5_regulation_error_flag = 0;
    error_handler.POS5P_regulation_error_flag = 0;
    error_handler.POS5P_thermal_warning_error_flag = 0;
    error_handler.POS5_regulation_error_flag = 0;
    error_handler.SPI_error_flag = 0;
    error_handler.USB_error_flag = 0;
    error_handler.WIFI_error_flag = 0;
    error_handler.configuration_error_flag = 0;
    error_handler.other_error_flag = 0;
    error_handler.system_bus_protection_violation_flag = 0;
    
}

// This function updates the error LEDs based on the error handler state
void updateErrorLEDs(void) {
 
    // Configuration Error
    if (error_handler.configuration_error_flag) OTHER_ERROR_LED_PIN = 1;
    else OTHER_ERROR_LED_PIN = 0;

    // EBI Error
    if (error_handler.EBI_error_flag) EBI_ERROR_LED_PIN = 1;
    else EBI_ERROR_LED_PIN = 0;
    
    // SPI Error
    if (error_handler.SPI_error_flag) SPI_ERROR_LED_PIN = 1;
    else SPI_ERROR_LED_PIN = 0;
    
    // WIFI Error
    if (error_handler.WIFI_error_flag) WIFI_ERROR_LED_PIN = 1;
    else WIFI_ERROR_LED_PIN = 0;
    
    // USB Error
    if (error_handler.USB_error_flag) USB_ERROR_LED_PIN = 1;
    else USB_ERROR_LED_PIN = 0;
    
    // Other Error
    if (error_handler.other_error_flag) OTHER_ERROR_LED_PIN = 1;
    else OTHER_ERROR_LED_PIN = 0;
    
    // POS5P Thermal Warning Error
    if (error_handler.POS5P_thermal_warning_error_flag) OTHER_ERROR_LED_PIN = 1;
    else OTHER_ERROR_LED_PIN = 0;
    
    // POS3P3 Regulation Error
    if (error_handler.POS3P3_regulation_error_flag) OTHER_ERROR_LED_PIN = 1;
    else OTHER_ERROR_LED_PIN = 0;
    
    // POS5 Regulation Error
    if (error_handler.POS5_regulation_error_flag) OTHER_ERROR_LED_PIN = 1;
    else OTHER_ERROR_LED_PIN = 0;
    
    // POS12 Regulation Error
    if (error_handler.POS12_regulation_error_flag) OTHER_ERROR_LED_PIN = 1;
    else OTHER_ERROR_LED_PIN = 0;
    
    // POS5P Regulation Error
    if (error_handler.POS5P_regulation_error_flag) OTHER_ERROR_LED_PIN = 1;
    else OTHER_ERROR_LED_PIN = 0;
    
    // POS5P5 Regulation Error
    if (error_handler.POS5P5_regulation_error_flag) OTHER_ERROR_LED_PIN = 1;
    else OTHER_ERROR_LED_PIN = 0;
    
    // DMT Error
    if (error_handler.DMT_error_flag) OTHER_ERROR_LED_PIN = 1;
    else OTHER_ERROR_LED_PIN = 0;
    
    // System Bus Protection Error
    if (error_handler.system_bus_protection_violation_flag) OTHER_ERROR_LED_PIN = 1;
    else OTHER_ERROR_LED_PIN = 0;
    
    
    
}