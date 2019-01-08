/*
 * File:   main.c
 * Author: Logan Wedel
 *
 * Created on December 18, 2018, 7:27 PM
 */

// Include built in C standard functions, device macros
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// Include device control APIs
// The functions allows low level control of the device
#include "device_control.h"
// Include PIC32MZ interrupt control APIs
#include "32mz_interrupt_control.h"
// Include cause of reset determination
#include "cause_of_reset.h"
// Include configuration bits
// These configure the device startup settings
#include "configure.h"


// Include application specific APIs
// Include error handling
#include "error_handler.h"
// Include initialization of GPIO ports
#include "gpio_setup.h"
// Include pin macros for easy GPIO manipulation
#include "pin_macros.h"
// heartbeat timer
#include "heartbeat_timer.h"
// Power saving APIs (PMD, SLEEP, etc)
#include "power_saving.h"

// Main program entry point
void main(void) {
    
    // Initialize system clocks
    clockInitialize();
    
    // Initialize GPIO pins to startup settings
    gpioInitialize();
    
    // Setup heartbeat timer
    heartbeatTimerInitialize();
    
    while (true) {
        
        Nop();
    
    }
    
    
}
