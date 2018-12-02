

#include "app.h"
#include "tv_test.h"

// fill ram buffer with tv test function
void fillRamBufferTVTest(void) {
 
    int address_index;
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = tv_test_array[address_index];
        
    }
    
}