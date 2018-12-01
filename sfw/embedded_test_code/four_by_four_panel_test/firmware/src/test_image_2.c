
#include "app.h"
#include "test_image_2.h"

// fill ram buffer with image 2 function
void fillRamBufferTestImage2(void) {
 
    int address_index;
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = test_image_2_array[address_index];
        
    }
    
}