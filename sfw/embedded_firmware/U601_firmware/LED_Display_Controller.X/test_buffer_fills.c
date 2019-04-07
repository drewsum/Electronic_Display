#include <xc.h>

#include "test_buffer_fills.h"

#include "panel_control.h"

// fill ram buffer with all black pixels
void fillRamBufferBlack(void) {
 
    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        panel_data_buffer[address_index] = 0x00;
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();
    
}

// fill ram buffer with all white pixels
void fillRamBufferWhite(void) {
 
    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        panel_data_buffer[address_index] = 0xFF;
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();
    
}

// fill ram buffer with random data
void fillRamBufferRand(void) {
 
    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    // Load a new seed
    RNGCONbits.LOAD = 1;
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        panel_data_buffer[address_index] = (uint8_t) RNGNUMGEN1;
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();
    
}

// fill ram buffer with all red
void fillRamBufferRed(void) {

    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if (address_index % 3 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            panel_data_buffer[address_index] = 0x00;
            
        }
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();

}

// fill ram buffer with all green
void fillRamBufferGreen(void) {

    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    unsigned int address_index;
    
    for (address_index = 1; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if ((address_index - 1) % 3 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            panel_data_buffer[address_index] = 0x00;
            
        }
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();

}

// fill ram buffer with all blue
void fillRamBufferBlue(void) {

    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    unsigned int address_index;
    
    for (address_index = 2; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if ((address_index - 2) % 3 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            panel_data_buffer[address_index] = 0x00;
            
        }
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();

}

// fill ram buffer with all yellow
void fillRamBufferYellow(void) {

    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if (address_index % 3 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 1) % 3 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            panel_data_buffer[address_index] = 0x00;
            
        }
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();

}

// fill ram buffer with all cyan
void fillRamBufferCyan(void) {
 
    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if ((address_index % 3 - 2) == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 1) % 3 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            panel_data_buffer[address_index] = 0x00;
            
        }
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();
    
}

// fill ram buffer with all magenta
void fillRamBufferMagenta(void) {
 
    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if (address_index % 3 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 2) % 3 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            panel_data_buffer[address_index] = 0x00;
            
        }
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();
    
}


// fill ram buffer with every other red
void fillRamBufferEveryOtherRed(void) {
    
    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if (address_index % 6 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            panel_data_buffer[address_index] = 0x00;
            
        }
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();
    
}

// fill ram buffer with every other blue
void fillRamBufferEveryOtherBlue(void) {
    
    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if ((address_index - 2) % 6 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            panel_data_buffer[address_index] = 0x00;
            
        }
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();
    
}

// fill ram buffer with every other green
void fillRamBufferEveryOtherGreen(void) {
    
    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if ((address_index - 1) % 6 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            panel_data_buffer[address_index] = 0x00;
            
        }
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();
    
}


// fill ram buffer with christmas stripes
void fillRamBufferChristmas(void) {
    
    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if (address_index % 6 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 4) % 6 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            panel_data_buffer[address_index] = 0x00;
            
        }
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();
    
}

// fill ram buffer with rgb stripes
void fillRamBufferRGBStripes(void) {
    
    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
     
        if (address_index % 12 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 4) % 12 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else if ((address_index - 8) % 12 == 0) {
         
            panel_data_buffer[address_index] = 0xFF;
            
        }
        
        else {
         
            panel_data_buffer[address_index] = 0x00;
            
        }
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();
    
}

// fill ram buffer with red rows
void fillRamBufferRedRow(void) {

    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    uint8_t set_flag = 1;
    
    unsigned int address_index;
    
    for (address_index = 0; address_index < PANEL_DATA_ARRAY_SIZE; address_index++) {
             
        if (address_index % 384 == 0) {
        
            set_flag = !set_flag;
           
        }
        
        if (set_flag) {
            
            if (address_index % 3 == 0) {
                
                panel_data_buffer[address_index] = 0xFF;
            
            }
            
            else {
         
            panel_data_buffer[address_index] = 0x00;
            
            }
            
        }
        
        else {
         
            panel_data_buffer[address_index] = 0x00;
            
        }
        
    }
    
    // Start multiplexing
    if (muxing_state) panelMultiplexingTimerStart();

}