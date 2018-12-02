
#include "app.h"
#include "fire.h"

// fill ram buffer with fire function
void fillRamBufferFire(void) {
 
    int address_index;
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = fire_array[address_index];
        
    }
    
}