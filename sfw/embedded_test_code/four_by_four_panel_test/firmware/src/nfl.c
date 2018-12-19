
#include "app.h"
#include "nfl.h"

// fill ram buffer with NFL function
void fillRamBufferNFL(void) {
 
    int address_index;
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = nfl_array[address_index];
        
    }
    
}