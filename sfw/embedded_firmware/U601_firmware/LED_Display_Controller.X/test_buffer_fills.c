#include <xc.h>

#include "test_buffer_fills.h"

#include "panel_control.h"

// This pragma tells the linker to allow access of EBI memory space
#pragma region name = "EBI_SRAM" origin = 0xC0000000 size = 262144

// This is tricking the compiler into placing an array in EBI SRAM
extern uint8_t ebi_sram_array[262144] __attribute__((region("EBI_SRAM")));

// fill ram buffer with all white pixels
void fillRamBufferWhite(void) {
 
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        ebi_sram_array[address_index] = 0xFF;
        
    }
    
}

// fill ram buffer with random data
void fillRamBufferRand(void) {
 
    unsigned int address_index;
    
    srand(10);
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        ebi_sram_array[address_index] = (uint8_t) rand() % 255;
        
    }
    
}

// fill ram buffer with all red
void fillRamBufferRed(void) {

    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if (address_index % 3 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else {
         
            ebi_sram_array[address_index] = 0x00;
            
        }
        
    }

}

// fill ram buffer with all green
void fillRamBufferGreen(void) {

    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if ((address_index - 1) % 3 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else {
         
            ebi_sram_array[address_index] = 0x00;
            
        }
        
    }

}

// fill ram buffer with all blue
void fillRamBufferBlue(void) {

    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if ((address_index - 2) % 3 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else {
         
            ebi_sram_array[address_index] = 0x00;
            
        }
        
    }

}

// fill ram buffer with all yellow
void fillRamBufferYellow(void) {

    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if (address_index % 3 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 1) % 3 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else {
         
            ebi_sram_array[address_index] = 0x00;
            
        }
        
    }

}

// fill ram buffer with all cyan
void fillRamBufferCyan(void) {
 
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if ((address_index % 3 - 2) == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 1) % 3 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else {
         
            ebi_sram_array[address_index] = 0x00;
            
        }
        
    }
    
}

// fill ram buffer with all magenta
void fillRamBufferMagenta(void) {
 
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if (address_index % 3 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 2) % 3 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else {
         
            ebi_sram_array[address_index] = 0x00;
            
        }
        
    }
    
}


// fill ram buffer with every other red
void fillRamBufferEveryOtherRed(void) {
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if (address_index % 6 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else {
         
            ebi_sram_array[address_index] = 0x00;
            
        }
        
    }
}

// fill ram buffer with every other blue
void fillRamBufferEveryOtherBlue(void) {
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if ((address_index - 2) % 6 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else {
         
            ebi_sram_array[address_index] = 0x00;
            
        }
        
    }
    
}

// fill ram buffer with every other green
void fillRamBufferEveryOtherGreen(void) {
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if ((address_index - 1) % 6 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else {
         
            ebi_sram_array[address_index] = 0x00;
            
        }
        
    }
}


// fill ram buffer with christmas stripes
void fillRamBufferChristmas(void) {
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if (address_index % 6 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 4) % 6 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else {
         
            ebi_sram_array[address_index] = 0x00;
            
        }
        
    }
}

// fill ram buffer with rgb stripes
void fillRamBufferRGBStripes(void) {
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if (address_index % 12 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 4) % 12 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 8) % 12 == 0) {
         
            ebi_sram_array[address_index] = 0xFF;
            
        }
        
        else {
         
            ebi_sram_array[address_index] = 0x00;
            
        }
        
    }
}

// fill ram buffer with red rows
void fillRamBufferRedRow(void) {

    uint8_t set_flag = 1;
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
             
        if (address_index % 384 == 0) {
        
            set_flag = !set_flag;
           
        }
        
        if (set_flag) {
            
            if (address_index % 3 == 0) {
                
                ebi_sram_array[address_index] = 0xFF;
            
            }
            
            else {
         
            ebi_sram_array[address_index] = 0x00;
            
            }
            
        }
        
        else {
         
            ebi_sram_array[address_index] = 0x00;
            
        }
        
    }

}