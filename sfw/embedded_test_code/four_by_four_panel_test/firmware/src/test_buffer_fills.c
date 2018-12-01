
#include "app.h"
#include "test_buffer_fills.h"

// fill ram buffer with all white pixels
void fillRamBufferWhite(void) {
 
    unsigned int address_index;
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = 0xFF;
        
    }
    
}

// fill ram buffer with random data
void fillRamBufferRand(void) {
 
    unsigned int address_index;
    
    srand(10);
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        ram_buffer[address_index] = (uint8_t) rand() % 50;
        
    }
    
}

// fill ram buffer with all red
void fillRamBufferRed(void) {

    unsigned int address_index;
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        if (address_index % 3 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            ram_buffer[address_index] = 0x00;
            
        }
        
    }

}

// fill ram buffer with all green
void fillRamBufferGreen(void) {

    unsigned int address_index;
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        if ((address_index - 1) % 3 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            ram_buffer[address_index] = 0x00;
            
        }
        
    }

}

// fill ram buffer with all blue
void fillRamBufferBlue(void) {

    unsigned int address_index;
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        if ((address_index - 2) % 3 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            ram_buffer[address_index] = 0x00;
            
        }
        
    }

}

// fill ram buffer with all yellow
void fillRamBufferYellow(void) {

    unsigned int address_index;
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        if (address_index % 3 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 1) % 3 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            ram_buffer[address_index] = 0x00;
            
        }
        
    }

}

// fill ram buffer with all cyan
void fillRamBufferCyan(void) {
 
    unsigned int address_index;
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        if ((address_index % 3 - 2) == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 1) % 3 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            ram_buffer[address_index] = 0x00;
            
        }
        
    }
    
}

// fill ram buffer with all magenta
void fillRamBufferMagenta(void) {
 
    unsigned int address_index;
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        if (address_index % 3 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 2) % 3 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            ram_buffer[address_index] = 0x00;
            
        }
        
    }
    
}


// fill ram buffer with every other red
void fillRamBufferEveryOtherRed(void) {
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        if (address_index % 6 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            ram_buffer[address_index] = 0x00;
            
        }
        
    }
}

// fill ram buffer with every other blue
void fillRamBufferEveryOtherBlue(void) {
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        if ((address_index - 2) % 6 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            ram_buffer[address_index] = 0x00;
            
        }
        
    }
}

// fill ram buffer with every other green
void fillRamBufferEveryOtherGreen(void) {
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        if ((address_index - 1) % 6 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            ram_buffer[address_index] = 0x00;
            
        }
        
    }
}


// fill ram buffer with christmas stripes
void fillRamBufferChristmas(void) {
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        if (address_index % 6 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 4) % 6 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            ram_buffer[address_index] = 0x00;
            
        }
        
    }
}

// fill ram buffer with rgb stripes
void fillRamBufferRGBStripes(void) {
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
     
        if (address_index % 12 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 4) % 12 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 8) % 12 == 0) {
         
            ram_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            ram_buffer[address_index] = 0x00;
            
        }
        
    }
}

// fill ram buffer with red rows
void fillRamBufferRedRow(void) {

    bool set_flag = true;
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < sizeof(ram_buffer); address_index++) {
             
        if (address_index % 384 == 0) {
        
            set_flag = !set_flag;
           
        }
        
        if (set_flag) {
            
            if (address_index % 3 == 0) {
                
                ram_buffer[address_index] = 0xFF;
            
            }
            
        }
        
        else {
         
            ram_buffer[address_index] = 0x00;
            
        }
        
    }

}