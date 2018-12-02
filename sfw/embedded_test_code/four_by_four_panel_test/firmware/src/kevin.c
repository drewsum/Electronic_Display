
#include "app.h"
#include "kevin.h"

// fill ram buffer with kevin function
void fillRamBufferKevin(void) {
 
    int address_index;
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = kevin_array[address_index];
        
    }
    
}