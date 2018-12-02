
#include "app.h"
#include "colors.h"

// fill ram buffer with colors function
void fillRamBufferColors(void) {
 
    int address_index;
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = colors_array[address_index];
        
    }
    
}