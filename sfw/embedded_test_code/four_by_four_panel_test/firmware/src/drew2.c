
#include "app.h"
#include "drew2.h"

// fill ram buffer with drew2 function
void fillRamBufferDrew2(void) {
 
    int address_index;
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = drew2_array[address_index];
        
    }
    
}