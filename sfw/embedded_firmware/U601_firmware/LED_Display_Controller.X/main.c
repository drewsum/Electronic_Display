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

// USB UART Command Ready Flag
extern volatile uint8_t usb_uart_RxStringReady;

// Main program entry point
void main(void) {
    
    // Enable multi-vector interrupt mode
    INTCONbits.MVEC = 1;
    
    // Enable Global Interrupts
    enableGlobalInterrupts();
    
    // Initialize system clocks
    clockInitialize();
        
    // Initialize GPIO pins to startup settings
    gpioInitialize();
    
    // Initialize UART USB debugging
    USB_UART_Initialize();
    
    // Print debug message
    USB_UART_print(" System Boot\n\r");
    USB_UART_print("Clocks Initialized to the following settings:\n\r");
    USB_UART_print("    SYSCLK: 252 MHz\n\r"
                   "    REFCLK1: Disabled\n\r"
                   "    REFCLK2: Disabled\n\r"
                   "    REFCLK3: Disabled\n\r"
                   "    REFCLK4: Disabled\n\r"
                   "    PBCLK1: 84 MHz\n\r"
                   "    PBCLK2: 84 MHz\n\r"
                   "    PBCLK3: 15.75 MHz\n\r"
                   "    PBCLK4: 84 MHz\n\r"
                   "    PBCLK5: 84 MHz\n\r"
                   "    PBCLK7: 252 MHz\n\r"
                   "    PBCLK8: 84 MHz\n\r");   
    USB_UART_print("GPIO Pins Initialized\n\r");
    USB_UART_print("USB UART Initialized to the following settings:\n\r"
                   "    Baud Rate: 115.2 kbs\n\r"
                   "    Data Length: 8 bits\n\r"
                   "    Parity: None\n\r"
                   "    Stop Bits: 1\n\r"
                   "    Flow Control: None\n\r");
    
    // Setup heartbeat timer
    heartbeatTimerInitialize();
    USB_UART_print("Heartbeat Timer Initialized\n\r");
    
    // Disable unused peripherals for power savings
    PMDInitialize();
    USB_UART_print("Peripheral Module Disable Initialized for reduced power consumption\n\r");
            
    // Setup the watchdog timer
    watchdogTimerInitialize();
    USB_UART_print("Watchdog Timer Initialized with a timeout of 2.048 seconds\n\r");
    
    // Startup the deadman timer
    deadmanTimerInitialize();
    USB_UART_print("Deadman Timer Initialized with a timeout of 2147483648 instruction fetches\n\r");
    
    // Turn off RESET LED
    nACTIVE_LED_PIN = 0;
    USB_UART_print("Reset LED disabled\n\r");
    
    // Loop endlessly
    while (true) {
        
        // Twiddle thumbs
        Nop();
                
        // Check if we've got a received USB UART command waiting
        if(usb_uart_RxStringReady) {

            USB_UART_ringBufferPull();
        
        }
        
        
    }
    
    
}
