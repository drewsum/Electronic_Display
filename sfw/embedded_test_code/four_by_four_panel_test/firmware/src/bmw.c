
#include "app.h"
#include "bmw.h"

// fill ram buffer with bmw function
void fillRamBufferBMW(void) {
 
    int address_index;
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = bmw_array[address_index];
        
    }
    
}