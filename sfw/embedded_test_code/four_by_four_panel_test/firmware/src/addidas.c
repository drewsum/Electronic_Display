
#include "app.h"
#include "addidas.h"

// fill ram buffer with colors function
void fillRamBufferAddidas(void) {
 
    int address_index;
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = addidas_array[address_index];
        
    }
    
}