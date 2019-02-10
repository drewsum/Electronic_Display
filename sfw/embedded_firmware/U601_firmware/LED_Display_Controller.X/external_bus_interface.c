#include <xc.h>
#include <proc/p32mz2048efh144.h>
#include <stdio.h>

#include "external_bus_interface.h"
#include "terminal_control.h"

#define SRAM_ADDR_CS0 0xC0000000
#define RAM_SIZE 262144

// This pragma tells the linker to allow access of EBI memory space
#pragma region name = "EBI_SRAM" origin = 0xC0000000 size = 262144

// This is tricking the compiler into placing an array in EBI SRAM
uint8_t ext_array[262144] __attribute__((region("EBI_SRAM")));

// EBI initialization function
void ebiInitialize(void){
    
    // Setup EBI permissions for memory
//    SBT1REG2bits.BASE = (0x20000000 >> 10);     // Starting at phy mem addr 0x20000000
//    SBT1REG2bits.SIZE = 0b01001;                // 256 kB
//    SBT1RD2bits.GROUP0 = 1;                     // PG0 can read
//    SBT1WR2bits.GROUP0 = 1;                     // PG0 can write
//    SBT1RD2bits.GROUP1 = 1;                     // PG1 can read
//    SBT1WR2bits.GROUP1 = 1;                     // PG1 can write
//    SBT1RD2bits.GROUP2 = 1;                     // PG2 can read
//    SBT1WR2bits.GROUP2 = 1;                     // PG2 can write
//    SBT1RD2bits.GROUP3 = 1;                     // PG3 can read
//    SBT1WR2bits.GROUP3 = 1;                     // PG3 can write
    
    // Disable KSEG2 caching
//    uint32_t val = _CP0_GET_CONFIG();
//    val = val & 0x2FFFFFFF;
//    val = val | 0x20000000;
//    // Write modified value back to CP0 config register
//    _mtc0 (_CP0_CONFIG, _CP0_CONFIG_SELECT, val); 
    
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
    
    // Set EBI timing settings
    EBIMSK0bits.REGSEL = 0b000;
    
//    // Disable Ready pin
//    EBISMT0bits.RDYMODE = 0;
//    
//    // Disable Page mode
//    EBISMT0bits.PAGEMODE = 0;
//    
//    // Set up EBI timing for Chip 0
//    EBISMT0bits.TPRC = 0b0000;
//    EBISMT0bits.TBTA = 0b000;
//    EBISMT0bits.TWP = 0b000000;
//    EBISMT0bits.TWR = 0b00;
//    EBISMT0bits.TAS = 0b00;
//    EBISMT0bits.TRC = 0b000000;
    
    EBISMT0 = 0x000029CA;
    
    // EBISMCON - Memory Control Register
    // Set Register 2 width to 8 bits
    EBISMCONbits.SMDWIDTH2 = 0b100;
    
    // Set Register 1 width to 8 bits
    EBISMCONbits.SMDWIDTH1 = 0b100;
    
    // Set Register 0 width to 8 bits
    EBISMCONbits.SMDWIDTH0 = 0b100;
       
}

// Prints EBI status

void printEBIStatus(void){
    
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, UNDERSCORE);
    printf("EBI Status:\n\r");

    terminalTextAttributes(GREEN, BLACK, NORMAL);
    
    // Status of EBI
    
    if (CFGEBIAbits.EBIPINEN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Enabled: %c\n\r",
            CFGEBIAbits.EBIPINEN ? 'T' : 'F');
    
    // Status of EBI Pins 0 thru 23

    if (CFGEBIAbits.EBIA0EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 0 Enabled: %c\n\r",
            CFGEBIAbits.EBIA0EN ? 'T' : 'F');
    
    if (CFGEBIAbits.EBIA1EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 1 Enabled: %c\n\r",
            CFGEBIAbits.EBIA1EN ? 'T' : 'F');
    
    if (CFGEBIAbits.EBIA2EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 2 Enabled: %c\n\r",
            CFGEBIAbits.EBIA2EN ? 'T' : 'F');
    
    if (CFGEBIAbits.EBIA3EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 3 Enabled: %c\n\r",
            CFGEBIAbits.EBIA3EN ? 'T' : 'F');
    
    if (CFGEBIAbits.EBIA4EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 4 Enabled: %c\n\r",
            CFGEBIAbits.EBIA4EN ? 'T' : 'F');
    
    if (CFGEBIAbits.EBIA5EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 5 Enabled: %c\n\r",
            CFGEBIAbits.EBIA5EN ? 'T' : 'F');
    
    if (CFGEBIAbits.EBIA5EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 5 Enabled: %c\n\r",
            CFGEBIAbits.EBIA5EN ? 'T' : 'F');
    
    if (CFGEBIAbits.EBIA6EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 6 Enabled: %c\n\r",
            CFGEBIAbits.EBIA6EN ? 'T' : 'F');
    
    if (CFGEBIAbits.EBIA7EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 7 Enabled: %c\n\r",
            CFGEBIAbits.EBIA7EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA8EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 8 Enabled: %c\n\r",
            CFGEBIAbits.EBIA8EN ? 'T' : 'F');
    
    if (CFGEBIAbits.EBIA9EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 9 Enabled: %c\n\r",
            CFGEBIAbits.EBIA9EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA10EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 10 Enabled: %c\n\r",
            CFGEBIAbits.EBIA10EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA11EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 11 Enabled: %c\n\r",
            CFGEBIAbits.EBIA11EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA12EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 12 Enabled: %c\n\r",
            CFGEBIAbits.EBIA12EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA13EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 13 Enabled: %c\n\r",
            CFGEBIAbits.EBIA13EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA14EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 14 Enabled: %c\n\r",
            CFGEBIAbits.EBIA14EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA15EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 15 Enabled: %c\n\r",
            CFGEBIAbits.EBIA15EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA16EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 16 Enabled: %c\n\r",
            CFGEBIAbits.EBIA16EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA17EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 17 Enabled: %c\n\r",
            CFGEBIAbits.EBIA17EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA18EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 18 Enabled: %c\n\r",
            CFGEBIAbits.EBIA18EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA19EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 19 Enabled: %c\n\r",
            CFGEBIAbits.EBIA19EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA20EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 20 Enabled: %c\n\r",
            CFGEBIAbits.EBIA20EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA21EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 21 Enabled: %c\n\r",
            CFGEBIAbits.EBIA21EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA22EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 22 Enabled: %c\n\r",
            CFGEBIAbits.EBIA22EN ? 'T' : 'F');

    if (CFGEBIAbits.EBIA23EN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Address Pin 23 Enabled: %c\n\r",
            CFGEBIAbits.EBIA23EN ? 'T' : 'F');
    
    // Status of EBI control signals 
    
    if (CFGEBICbits.EBIRDYEN3) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Ready 3 Enable: %c\n\r",
            CFGEBICbits.EBIRDYEN3 ? 'T' : 'F');
    
    if (CFGEBICbits.EBIRDYEN2) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Ready 2 Enable: %c\n\r",
            CFGEBICbits.EBIRDYEN2 ? 'T' : 'F');
    
    if (CFGEBICbits.EBIRDYEN1) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Ready 1 Enable: %c\n\r",
            CFGEBICbits.EBIRDYEN1 ? 'T' : 'F');
    
    // RP signal status
    
    if (CFGEBICbits.EBIRPEN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI RP Enable: %c\n\r",
            CFGEBICbits.EBIRPEN ? 'T' : 'F');
    
    // EBI Write Enable status
    
    if (CFGEBICbits.EBIWEEN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Write Enable: %c\n\r",
            CFGEBICbits.EBIWEEN ? 'T' : 'F');
    
    // EBI Output Enable status
    
    if (CFGEBICbits.EBIOEEN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Output Enable: %c\n\r",
            CFGEBICbits.EBIOEEN ? 'T' : 'F');
    
    // EBI Byte Select status
    
    if (CFGEBICbits.EBIBSEN1) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBIBS1 Pin Enable: %c\n\r",
            CFGEBICbits.EBIBSEN1 ? 'T' : 'F');
    
    if (CFGEBICbits.EBIBSEN0) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBIBS0 Pin Enable: %c\n\r",
            CFGEBICbits.EBIBSEN0 ? 'T' : 'F');
    
    // EBI Chip Enable status
    
    if (CFGEBICbits.EBICSEN0) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Chip Select 0 Enable: %c\n\r",
            CFGEBICbits.EBICSEN0 ? 'T' : 'F');
    
    if (CFGEBICbits.EBICSEN1) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Chip Select 1 Enable: %c\n\r",
            CFGEBICbits.EBICSEN1 ? 'T' : 'F');
    
    if (CFGEBICbits.EBICSEN2) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Chip Select 2 Enable: %c\n\r",
            CFGEBICbits.EBICSEN2 ? 'T' : 'F');
    
    if (CFGEBICbits.EBICSEN3) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Chip Select 3 Enable: %c\n\r",
            CFGEBICbits.EBICSEN3 ? 'T' : 'F');
    
    // Print upper/lower byte select status
    
    if (CFGEBICbits.EBIDEN1) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Data Upper Byte Enable: %c\n\r",
            CFGEBICbits.EBIDEN1 ? 'T' : 'F');
    
    if (CFGEBICbits.EBIDEN0) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    EBI Data Lower Byte Enable: %c\n\r",
            CFGEBICbits.EBIDEN0 ? 'T' : 'F');
    
    // EBI memory type status
    
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    Memory Type: ");
            
    switch (EBIMSK0bits.MEMTYPE) {
     
        case 0b010:
            printf("NOR Flash\n\r");
            break;
        
        case 0b001:
            printf("SRAM\r\n");
            break;
            
        default:
            printf("Undefined: 0x%02X\n\r", EBIMSK0bits.MEMTYPE);
            break;
      }
    
    // EBI Memory size
    
    printf("    Memory Size: ");
    
    switch  (EBIMSK0bits.MEMSIZE) {
        
        case 0b01001: 
            printf("16 MB\r\n");
            break;
        
        case 0b01000: 
            printf("8 MB\r\n");
            break;
        
        case 0b00111: 
            printf("4 MB\r\n");
            break;
        
        case 0b00110: 
            printf("2 MB\r\n");
            break;
        
        case 0b00101: 
            printf("1 MB\r\n");
            break;
        
        case 0b00100: 
            printf("512 KB\r\n");
            break;
        
        case 0b00011: 
            printf("256 KB\r\n");
            break;
        
        case 0b00010: 
            printf("128 KB\r\n");
            break;
        
        case 0b00001: 
            printf("64 KB\r\n");
            break;
            
        default:
            printf("Undefined: 0x%02X\n\r", EBIMSK0bits.MEMSIZE);
            break;
    }
    
    // EBI timing status
    
    printf("    EBI Timing:\n\r");
    printf("        Data Bus Turnaraound time: %d clock cycles\n\r",
            EBISMT0bits.TBTA + 1);
    printf("        Write Pulse Width: %d clock cycles\n\r",
            EBISMT0bits.TWP + 1);
    printf("        TAS: %d clock cycles\n\r",
            EBISMT0bits.TWR + 1);
    printf("        Write Address Setup Time: %d clock cycles\n\r",
            EBISMT0bits.TAS + 1);
    printf("        Read Cycle Time %d clock cycles\n\r",
            EBISMT0bits.TRC + 1);

    
    
    terminalTextAttributesReset();
    
}

// This function writes a byte to EBI SRAM at the input address
void ebiSRAMWrite(uint8_t input_data, uint32_t input_address) {
 
//    uint32_t *addr;
//    
//    // Set address we're accessing to the start address + the input address
//    addr = (uint32_t *) (const) (0xC0000000 + (uint32_t) input_address);
//    
//    // Write the input data to the memory location pointed to by addr
//    *addr = input_data;
        
    
    
}

// This function reads a byte from the input address passed
uint8_t ebiSRAMRead(uint32_t input_address) {
 
//    uint32_t *addr;
//    
//    // Set address we're accessing to the start address + the input address
//    addr = (uint32_t *) (const) (0xC0000000 + (uint32_t) input_address);
//    
//    // Return the value in external memory pointed to by addr
//    return *addr;
    
    
    
    
    
}

// This function loops through all possible external memory addresses and tests to
// see if the writes and reads actually work
// Returns 0 if test failure
// returns 1 for test success
uint8_t testEBISRAM(void) {
 
    // Below is copied directly from EBI ref manual, example 47-5
    // Writing and reading was changed to function implementation from pointers
    
    // Write loop
    uint32_t loop_address;
    
    for (loop_address = 0; loop_address < RAM_SIZE; loop_address++) {
        
        ext_array[loop_address] = 0xFF;
    }
    
    
    // The value we're reading from EBI
    uint8_t val;
    
    for (loop_address = 0 ; loop_address < RAM_SIZE; loop_address++) {
        
        val = ext_array[loop_address];
        if (val != 0xFF) {
        
            return (0); //Exit Failure
        
        }
    
    }
    
    return (1); // exit success
    
}

void ebiPrintSRAM(void){
    
    // The value we're reading from EBI
    uint8_t val;
    
    // Access address
    uint32_t loop_address;
    
    // wait for it
    for (loop_address = 0 ; loop_address < 256; loop_address += 16) {
        
        printf("    0x%08X: 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\n\r", loop_address,
               ext_array[loop_address + 0],
               ext_array[loop_address + 1], 
               ext_array[loop_address + 2], 
               ext_array[loop_address + 3], 
               ext_array[loop_address + 4], 
               ext_array[loop_address + 5], 
               ext_array[loop_address + 6], 
               ext_array[loop_address + 7], 
               ext_array[loop_address + 8], 
               ext_array[loop_address + 9], 
               ext_array[loop_address + 0xA], 
               ext_array[loop_address + 0xB], 
               ext_array[loop_address + 0xC], 
               ext_array[loop_address + 0xD], 
               ext_array[loop_address + 0xE], 
               ext_array[loop_address + 0xF]);
        
    }
    
}