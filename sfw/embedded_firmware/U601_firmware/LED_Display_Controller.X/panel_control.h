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

// Display update variables
uint8_t current_shift_clock;
uint8_t current_row;
uint8_t current_PWM_frame;

// ram buffer index variables
uint32_t current_shift_clock_index;
uint32_t current_row_index;
uint32_t current_PWM_frame_index;

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
void __ISR(_TIMER_5_VECTOR, IPL7SRS) panelMultiplexingTimerISR(void);


#endif /* _PANEL_CONTROL_H */

/* *****************************************************************************
 End of File
 */
