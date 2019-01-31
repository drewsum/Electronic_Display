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

// Cause of Device Reset
reset_cause_t reset_cause;

// Main program entry point
void main(void) {
    
    // Enable multi-vector interrupt mode
    INTCONbits.MVEC = 1;
    
    // Enable Global Interrupts
    enableGlobalInterrupts();
    
    // Initialize system clocks
    clockInitialize();
    
    // Save the cause of the most recent device reset
    reset_cause = getResetCause();
        
    // Initialize GPIO pins to startup settings
    gpioInitialize();
    
    // Initialize UART USB debugging
    USB_UART_Initialize();
    
    // Print debug message s
    printf(" Logic Board Initializing...\n\r");
    
    if (    reset_cause == Undefined ||
            reset_cause == Primary_Config_Registers_Error ||
            reset_cause == Primary_Secondary_Config_Registers_Error ||
            reset_cause == Config_Mismatch ||
            reset_cause == DMT_Reset ||
            reset_cause == WDT_Reset ||
            reset_cause == Software_Reset ||
            reset_cause == External_Reset ||
            reset_cause == BOR_Reset) {
    
        USB_UART_textAttributes(RED, BLACK, BOLD);
        
    }
    
    else {
     
        USB_UART_textAttributes(GREEN, BLACK, NORMAL);
        
    }
    
    printf("Cause of most recent device reset: %s\n\r", getResetCauseString(reset_cause));
    
    USB_UART_textAttributesReset();
    USB_UART_textAttributes(GREEN, BLACK, NORMAL);
    printf("Clocks Initialized to the following settings:\n\r");
    printf("    SYSCLK: %s\n\r", stringFromClockSetting(SYSCLK_INT));
    printf("    REFCLK1: %s\n\r", stringFromClockSetting(REFCLK1_INT));
    printf("    REFCLK2: %s\n\r", stringFromClockSetting(REFCLK2_INT));
    printf("    REFCLK3: %s\n\r", stringFromClockSetting(REFCLK3_INT));
    printf("    REFCLK4: %s\n\r", stringFromClockSetting(REFCLK4_INT));
    printf("    PBCLK1: %s\n\r", stringFromClockSetting(PBCLK1_INT));
    printf("    PBCLK2: %s\n\r", stringFromClockSetting(PBCLK2_INT));
    printf("    PBCLK3: %s\n\r", stringFromClockSetting(PBCLK3_INT));
    printf("    PBCLK4: %s\n\r", stringFromClockSetting(PBCLK4_INT));
    printf("    PBCLK5: %s\n\r", stringFromClockSetting(PBCLK5_INT));
    printf("    PBCLK7: %s\n\r", stringFromClockSetting(PBCLK7_INT));
    printf("    PBCLK8: %s\n\r", stringFromClockSetting(PBCLK8_INT));
    
    printf("GPIO Pins Initialized\n\r");
    printf("USB UART Initialized to the following settings:\n\r");
    printf("    Baud Rate: %s\n\r", USB_UART_BAUD_RATE_STR);
    printf("    Data Length: %s\n\r", USB_UART_DATA_LENGTH_STR);
    printf("    Parity: %s\n\r", USB_UART_PARITY_STR);
    printf("    Stop Bits: %s\n\r", USB_UART_STOP_BITS_STR);
    printf("    Flow Control: %s\n\r", USB_UART_FLOW_CONTROL_STR);
    
    // Setup heartbeat timer
    heartbeatTimerInitialize();
    printf("Heartbeat Timer Initialized\n\r");
    
    // Disable unused peripherals for power savings
    PMDInitialize();
    printf("Unused Peripheral Modules Disabled\n\r");
            
    // Setup the watchdog timer
    watchdogTimerInitialize();
    printf("Watchdog Timer Initialized\n\r");
    
    // Startup the deadman timer
    deadmanTimerInitialize();
    printf("Deadman Timer Initialized\n\r");
    
    // Turn off RESET LED
    nACTIVE_LED_PIN = 0;
    printf("Reset LED disabled\n\r");
    
    USB_UART_textAttributesReset();
    USB_UART_textAttributes(YELLOW, BLACK, NORMAL);
    printf("Type 'Help' for list of supported commands\n\r");
    USB_UART_textAttributesReset();
    
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
