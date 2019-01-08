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
// These are APIs written for portability between projects and set up the device
// for basic use
// The functions allow low level control of the device
#include "device_control.h"
// Include PIC32MZ interrupt control APIs
#include "32mz_interrupt_control.h"
// Include cause of reset determination
#include "cause_of_reset.h"
// Include configuration bits
// These configure the device startup settings
#include "configure.h"
// Include watchdog timer
// WDT will reset the micro if it has not been cleared within 2.048 seconds
#include "watchdog_timer.h"


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
// USB debugging
#include "usb_uart.h"
// External Bus Interface (EBI)
#include "external_bus_interface.h"
// LED Panel Control
#include "panel_control.h"
// SPI Flash Memory
#include "spi_flash.h"
// ESP8266 WiFi module, and android app interface
#include "esp8266.h"
// Analog to Digital Converter
#include "adc.h"
// Rotary encoder for controlling brightness
#include "rotary_encoder.h"
// Miscellaneous Board Control
#include "misc_board_control.h"

// Main program entry point
void main(void) {
    
    // Initialize system clocks
    clockInitialize();
    
    // Initialize GPIO pins to startup settings
    gpioInitialize();
    
    // Setup heartbeat timer
    heartbeatTimerInitialize();
    
    // Setup the watchdog timer
    watchdogTimerInitialize();
    
    // Loop endlessly
    while (true) {
        
        // Verify DMT was cleared properly
        verifyThumbTightEnough();
    
    }
    
    
}
