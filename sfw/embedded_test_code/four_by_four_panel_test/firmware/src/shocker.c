
#include "app.h"
#include "shocker.h"

// fill ram buffer with shocker function
void fillRamBufferShocker(void) {
 
    int address_index;
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = shocker_array[address_index];
        
    }
    
}