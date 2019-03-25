
#include <xc.h>

#include "test_image_1.h"

#include "panel_control.h"

// fill ram buffer with Test Image 1 logo function
void fillRamBufferTestImage1(void) {
 
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    uint32_t address_index;
    
    for (address_index = 0; address_index < sizeof(test_image_1_array); address_index++) {
     
        panel_data_buffer[address_index] = test_image_1_array[address_index];
        
    }
    
    // Start multiplexing
    panelMultiplexingTimerStart();
    
}