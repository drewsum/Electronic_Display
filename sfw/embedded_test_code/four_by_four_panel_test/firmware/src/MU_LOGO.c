
#include "app.h"
#include "MU_LOGO.h"

// fill ram buffer with MU logo function
void fillRamBufferMULogo(void) {
 
    int address_index;
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = mu_logo_array[address_index];
        
    }
    
}