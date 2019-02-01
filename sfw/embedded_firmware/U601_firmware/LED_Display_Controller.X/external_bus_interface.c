#include <xc.h>
#include <proc/p32mz2048efh144.h>

#include "external_bus_interface.h"

#define SRAM_ADDR_CS0 0xC0000000
#define RAM_SIZE 256*1024

// EBI initialization function

void ebiInitialize(void){
    
    // EBI controls access of EBI pins
    CFGEBIAbits.EBIPINEN = 1;
    
    // Configure EBI address pins (0 thru 17) ON 
    CFGEBIAbits.EBIA0EN = 1;
    CFGEBIAbits.EBIA1EN = 1;
    CFGEBIAbits.EBIA2EN = 1;
    CFGEBIAbits.EBIA3EN = 1;
    CFGEBIAbits.EBIA4EN = 1;
    CFGEBIAbits.EBIA5EN = 1;
    CFGEBIAbits.EBIA6EN = 1;
    CFGEBIAbits.EBIA7EN = 1;
    CFGEBIAbits.EBIA8EN = 1;
    CFGEBIAbits.EBIA9EN = 1;
    CFGEBIAbits.EBIA10EN = 1;
    CFGEBIAbits.EBIA11EN = 1;
    CFGEBIAbits.EBIA12EN = 1;
    CFGEBIAbits.EBIA13EN = 1;
    CFGEBIAbits.EBIA14EN = 1;
    CFGEBIAbits.EBIA15EN = 1;
    CFGEBIAbits.EBIA16EN = 1;
    CFGEBIAbits.EBIA17EN = 1;
    
    // Configure EBI address pins (18 thru 23) OFF
    CFGEBIAbits.EBIA18EN = 0;
    CFGEBIAbits.EBIA19EN = 0;
    CFGEBIAbits.EBIA20EN = 0;
    CFGEBIAbits.EBIA21EN = 0;
    CFGEBIAbits.EBIA22EN = 0;
    CFGEBIAbits.EBIA23EN = 0;
    
    // Configure EBI control signals
    CFGEBICbits.EBIRDYEN3 = 0;
    CFGEBICbits.EBIRDYEN2 = 0;
    CFGEBICbits.EBIRDYEN1 = 0;
    
    // Disable RP signal
    CFGEBICbits.EBIRPEN = 0;
    
    // Enable Write Enable signal
    CFGEBICbits.EBIWEEN = 1;
    
    // Enable Output Enable signal
    CFGEBICbits.EBIOEEN = 1;
    
    // Disable byte select signals
    CFGEBICbits.EBIBSEN1 = 0;
    CFGEBICbits.EBIBSEN0 = 0;
    
    // Enable chip 0, Disable all others
    CFGEBICbits.EBICSEN3 = 0;
    CFGEBICbits.EBICSEN2 = 0;
    CFGEBICbits.EBICSEN1 = 0;
    CFGEBICbits.EBICSEN0 = 1;
    
    // Disable upper byte of EBI data, enable lower byte
    CFGEBICbits.EBIDEN1 = 0;
    CFGEBICbits.EBIDEN0 = 1;
    
    // Connect CS0 to physical address
    EBICS0 = 0x20000000;
    
    // Define memory type as 256kB SRAM
    EBIMSK0bits.MEMTYPE = 0b001;
    EBIMSK0bits.MEMSIZE = 0b00011;
    
    // Set EBI timing
    EBIMSK0bits.REGSEL = 0b000;
    
    // Disable Ready pin
    EBISMT0bits.RDYMODE = 0;
    
    // Disable Page mode
    EBISMT0bits.PAGEMODE = 0;
    
    // Set up EBI timing for Chip 0
    EBISMT0bits.TPRC = 0b0000;
    EBISMT0bits.TBTA = 0b000;
    EBISMT0bits.TWP = 0b000000;
    EBISMT0bits.TWR = 0b00;
    EBISMT0bits.TAS = 0b00;
    EBISMT0bits.TRC = 0b000000;
    
}
