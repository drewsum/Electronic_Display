
#include <xc.h>

#include "splash_screen.h"

#include "panel_control.h"

// fill ram buffer with Splash Screen function
void fillRamBufferSplashScreen(void) {
 
    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    uint32_t address_index;
    
    for (address_index = 0; address_index < sizeof(splash_screen_array); address_index++) {
    
        panel_data_buffer[address_index] = splash_screen_array[address_index];
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();
    
}
