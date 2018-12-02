
#include "app.h"
#include "swirl.h"

// fill ram buffer with swirl function
void fillRamBufferSwirl(void) {
 
    int address_index;
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = swirl_array[address_index];
        
    }
    
}