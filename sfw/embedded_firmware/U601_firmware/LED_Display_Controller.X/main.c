/*
 * File:   main.c
 * Author: Logan Wedel, Drew Maatman, Caroline Gilger
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
// These are modules written for portability between projects and set up the device
// for basic use
// These functions allow low level control of the device
#include "device_control.h"
// Include PIC32MZ interrupt control
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
// Power saving module (PMD, SLEEP, etc)
#include "power_saving.h"
// Terminal control for USB debugging
#include "terminal_control.h"
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
// Test Buffer Fills
#include "test_buffer_fills.h"
// Delay Timer
#include "delay_timer.h"
// Standard operation state machine
#include "standard_operation_sm.h"

// USB UART Command Ready Flag
extern volatile uint8_t usb_uart_RxStringReady;
// esp8266 Ready Flag
extern volatile uint8_t esp_8266_RxStringReady;

// Cause of Device Reset global variable
reset_cause_t reset_cause;

// EBI init needs to be called before data initialization because EBI SRAM array
// will be initialized before entrance into main();
void _on_reset (void) {
 
    ebiInitialize();
    
}

// Main program entry point
void main(void) {
    
    // Disable global interrupts so clocks can be initialized properly
    disableGlobalInterrupts();
    
    // Initialize system clocks
    clockInitialize();
    
    // Configure interrupt controller
    interruptControllerInitialize();
    
    // Enable Global Interrupts
    enableGlobalInterrupts();
    
    // Save the cause of the most recent device reset
    // This also checks for configuration errors
    reset_cause = getResetCause();
    
    // Initialize GPIO pins to startup settings
    gpioInitialize();
    
    // Initialize UART USB debugging
    usbUartInitialize();
    
    // Clear the terminal
    terminalClearScreen();
    terminalSetCursorHome();
    terminalTextAttributesReset();

    
    // Print debug message s
    printf("Logic Board Initializing...\n\r");
    
    if (    reset_cause == Undefined ||
            reset_cause == Primary_Config_Registers_Error ||
            reset_cause == Primary_Secondary_Config_Registers_Error ||
            reset_cause == Config_Mismatch ||
            reset_cause == DMT_Reset ||
            reset_cause == WDT_Reset ||
            reset_cause == Software_Reset ||
            reset_cause == External_Reset ||
            reset_cause == BOR_Reset) {
    
        terminalTextAttributes(RED, BLACK, NORMAL);
        
    }
    
    else {
     
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        
    }
    
    printf("Cause of most recent device reset: %s\n\r", getResetCauseString(reset_cause));
    
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("Clocks Initialized\n\r");
    printf("Interrupt Controller Initialized, Global Interrupts Enabled\n\r");
    printf("GPIO Pins Initialized\n\r");
    printf("USB UART Initialized\n\r");
    
    // Setup error handling
    errorHandlerInitialize();
    printf("Error Handler Initialized\n\r");
    
    // Setup prefetch module
    prefetchInitialize();
    printf("Prefetch Module Initialized\n\r");
    
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
    
    // Startup the delay timer
    delayTimerInitialize();
    printf("Delay Timer Initialized\r\n");
    
    // EBI set up
    uint8_t ebi_exit_success = testEBISRAM();
    
    if (ebi_exit_success == 0) {
         
            error_handler.EBI_error_flag = 1;
            updateErrorLEDs();
            terminalTextAttributesReset();
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("EBI SRAM Initialized, but R/W self test failed\n\r");
            terminalTextAttributesReset();
            terminalTextAttributes(GREEN, BLACK, NORMAL);
        
        }
        
        else {
            terminalTextAttributesReset();
            terminalTextAttributes(GREEN, BLACK, NORMAL);
            printf("EBI SRAM Initialized, R/W self test passed \n\r");
            clearEBISRAM();
        
        }
    
    // Initialize SPI
    spiFlashInit();
    printf("SPI Flash Initialized\n\r");
    
    // Initialize ESP 8266 chip
    esp8266Initialize();
    printf("ESP8266 UART Initialized\n\r");
    
    // Setup RNG for random pixel values
    RNGInitialize();
    printf("Random Number Generator Initialized\n\r");
    
    // Setup panel brightness PWM
    panelPWMInitialize();
    printf("Panel Brightness PWM Initialized\n\r");

    // Turn off RESET LED
    nACTIVE_LED_PIN = 0;
    printf("Reset LED disabled\n\r");
    
    // enable POS5 power supply
    POS5_RUN_PIN = 1;
    printf("+5V Power Supply Enabled\n\r");
    
    // enable panel data level shifting
    nLEVEL_SHIFT_EN_PIN = 0;
    printf("Panel Data Level Shifters Enabled\n\r");
    
    // Initialize change notifications
    changeNotificationInit();
    printf("Change Notifications Enabled\r\n");
    
    // Setup state machine countdown timer
    countdownTimerInit();
    printf("State Machine Countdown Timer Initialized\r\n");
    
    // Start Timer5
    panelMultiplexingTimerInitialize();
    printf("Panel Multiplexing Timer Initialized\n\r");
    
    // Setup state machine countdown timer
    countdownTimerInit();
    printf("State Machine Countdown Timer Initialized\r\n");    
 
    terminalTextAttributesReset();
    terminalTextAttributes(YELLOW, BLACK, NORMAL);
    printf("\n\rType 'Help' for list of supported commands, press enter twice after reset\n\r\n\r");
    terminalTextAttributesReset();
    
    // Lock configurations
    deviceLock();
    
    // Update error LEDs based on error handler status
    updateErrorLEDs(); 
    
    // Setup ESP after UART1 has been initialized
    esp8266InitializeConfiguration();
    
    // Initiate state machine
    //if(continue_autopilot) standardOpSMInit(); 
    //countdown_val = 5; // for now
    
    // Loop endlessly
    while (true) {
        
        // Check if we've got a received USB UART command waiting
        if(usb_uart_RxStringReady != 0) {

            usbUartRingBufferPull();
        
        }
        
        // Check if we've got a received WiFi string waiting
        if(esp_8266_RxStringReady != 0) {
            
            esp8266RingBufferPull();
        
        }
        
        // If we've moved next frame from SPI Flash into EBI, start state machine timer
        if (SPI_Read_Finished_Flag && continue_autopilot) {
         
            SPI_Read_Finished_Flag = 0;
            
            countdownTimerStart(5);
            
        }
        
        if (state == sm_start && SPI_Read_Finished_Flag) {
         
            SPI_Read_Finished_Flag = 0;
            
            // Copy frame 1 into display buffer
            movePanelDataFromEBISRAM();

            // Start displaying frame 1
            panelMultiplexingTimerStart();

            // increment next flash chip
            flash_chip++;
            SPI_FLASH_beginRead(flash_chip);
            
        }
        
        if(continue_autopilot) {
            
            switch(state) {
                case(start):
                    standardOpSMInit();
                    break;
                    
                case(first_load):
                    state = display;
                    First_Load = 1;
                    nextFlashData();
                    break;
                    
                case(next_load):
                    state = display;
                    nextFlashData();
                    countdownTimerStart(3);
                    terminalTextAttributesReset();
                    terminalTextAttributes(YELLOW, BLACK, NORMAL);
                    printf("Timer Started...\n\r");
                    terminalTextAttributesReset();
                    break;
                    
                case(display):
                    if (SPI_Read_Finished_Flag && Countdown_Timer_Done) {
                   // if (SPI_Read_Finished_Flag) {
                        
                        flash_chip++;
                        state = next_load;
                        Countdown_Timer_Done = 0;
                        movePanelDataFromEBISRAM();
                                                
                        if (First_Load) {

                            panelMultiplexingTimerStart();
                            First_Load = 0;

                        }
                                                                        
                    }
                    
                    break;      
                
                default:
                    break;
                    
            }
            
        } else {
            
            if(SPI_Read_Finished_Flag) {
                
                exitSM();
                
            }
            
        }
             
    }
    
    
}
