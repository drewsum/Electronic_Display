/* ************************************************************************** */
/** Panel Control

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    panel_control.h

  @Summary
 Gives APIs for controlling 20 external 64 x 64 pixel RGB LED panels

 */
/* ************************************************************************** */

#ifndef _PANEL_CONTROL_H    /* Guard against multiple inclusion */
#define _PANEL_CONTROL_H

#include <xc.h>
#include <sys/attribs.h>

#define PANEL_DATA_ARRAY_SIZE 245760

// Array that will hold all data currently being displayed on panels
uint8_t panel_data_buffer[PANEL_DATA_ARRAY_SIZE];

// Display update variables
uint32_t current_shift_clock;
uint32_t current_row;
uint32_t current_PWM_frame;

// ram buffer index variables
uint32_t current_shift_clock_index;
uint32_t current_row_index;
uint32_t current_PWM_frame_index;


// THESE ARE TEMPORARY VARIABLES
#warning "Remove temporary panel control variables"
uint8_t panel_clock_high_delay = 10;
uint8_t panel_clock_low_delay = 10;

// Function to handle all mutliplexing for panel
void panelMultiplexingHandler(void);

// Set RGB bus state functions
void setPanelRedBus(uint8_t inputByte);
void setPanelGreenBus(uint8_t inputByte);
void setPanelBlueBus(uint8_t inputByte);

// Set ROW bus state functions
void setPanelRowBus(uint8_t inputByte);

// This function initializes Timer5 for panel multiplexing
void panelMultiplexingTimerInitialize(void);

// Start muxing timer function
void panelMultiplexingTimerStart(void);

// Stpo muxing timer function
void panelMultiplexingTimerStop(void);

// Clear muxing timer function
void panelMultiplexingTimerClear(void);

// Function for multiplexing timer ISR
void __ISR(_TIMER_5_VECTOR, IPL6SRS) panelMultiplexingTimerISR(void);

// This function stops multiplexing and clears all control signals
void panelMultiplexingSuspend(void);

// This function prints the contents of the internal RAM buffer holding frame data
void panelDataBufferPrint(void);

// This function copies all data from the internal RAM buffer into EBI SRAM
void movePanelDataToEBISRAM(void);

// This function copies panel data from EBI SRAM to the internal RAM buffer
void movePanelDataFromEBISRAM(void);

// This function initializes output compare 4 for dimming the display
void panelPWMInitialize(void);

// This function sets panel brightness
// Pass an integer between 0 and 100
// Larger numbers correspond to a brighter display
void panelPWMSetBrightness(uint8_t set_brightness);

#endif /* _PANEL_CONTROL_H */

/* *****************************************************************************
 End of File
 */
