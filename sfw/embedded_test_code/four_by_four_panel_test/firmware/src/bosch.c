
#include "app.h"
#include "bosch.h"

// fill ram buffer with colors function
void fillRamBufferBosch(void) {
 
    int address_index;
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = bosch_array[address_index];
        
    }
    
}