
#include <xc.h>

#include "nfl_logo.h"

#include "panel_control.h"

// fill ram buffer with NFL logo function
void fillRamBufferNFL(void) {
 
    uint32_t address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        ebi_sram_array[address_index] = nfl_array[address_index];
        
    }
    
}