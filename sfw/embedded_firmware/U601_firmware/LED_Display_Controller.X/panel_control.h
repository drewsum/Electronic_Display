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

#define PANEL_DATA_PWM_FRAMES   8

#define MUXING_TIMER_PERIOD     95

// Array that will hold all data currently being displayed on panels
uint8_t panel_data_buffer[PANEL_DATA_ARRAY_SIZE];

// Display update variables
uint32_t current_row;
uint32_t current_PWM_frame;

// ram buffer index variables
uint32_t current_shift_clock_index;
uint32_t current_row_index;
uint32_t current_PWM_frame_index;

// Function to handle all mutliplexing for panel
void panelMultiplexingHandler(void);

// Set RGB bus state function
// This function presents the given parameters onto hardware pins, and thus the
// panel shift registers
void setPanelRGBBus(uint8_t inputRedByte, uint8_t inputGreenByte, uint8_t inputBlueByte);

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

// This function initializes output compare 3 for dimming the display
void panelPWMInitialize(void);

// This function sets panel brightness
// Pass an integer between 0 and 100
// Larger numbers correspond to a brighter display
void panelPWMSetBrightness(uint8_t set_brightness);

#endif /* _PANEL_CONTROL_H */

/* *****************************************************************************
 End of File
 */
