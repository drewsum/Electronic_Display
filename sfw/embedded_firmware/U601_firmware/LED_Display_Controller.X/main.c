/*
 * File:   main.c
 * Author: Logan Wedel
 *
 * Created on December 18, 2018, 7:27 PM
 */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// Include configuration bits
// These configure the device startup settings
#include "configure.h"

// Include device control APIs
// The functions allow low level control of the device
// #include "device_control.h"


// Main program entry point
void main(void) {
    
    // Initialize system clocks to following settings:
    // SYSCLK: 252 MHz
    // REFCLK1: Disabled
    // REFCLK2: Disabled
    // REFCLK3: Disabled
    // REFCLK4: Disabled
    // PBCLK1: 84 MHz
    // PBCLK2: 84 MHz
    // PBCLK3: 15.75 MHz
    // PBCLK4: 84 MHz
    // PBCLK5: 84 MHz
    // PBCLK7: 252 MHz
    // PBCLK8: 84 MHz
    // clockInitialize();
    
    // Set RE3 high to show signs of life
    TRISECLR = (1 << 3);
    LATESET = (1 << 3);
    
    while (true) {
        
        Nop();
    
    }
    
    
}
