
#include <xc.h>

#include "nfl_logo.h"

#include "panel_control.h"

// fill ram buffer with NFL logo function
void fillRamBufferNFL(void) {
 
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    uint32_t address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        panel_data_buffer[address_index] = nfl_array[address_index];
        
    }
    
    // Start multiplexing
    panelMultiplexingTimerStart();
    
}