#include <xc.h>
#include <stdio.h>
#include <string.h>

#include "terminal_control.h"
#include "spi_flash.h"
#include "32mz_interrupt_control.h"
#include "error_handler.h"
#include "pin_macros.h"
#include "external_bus_interface.h"
#include "panel_control.h"

// This pragma tells the linker to allow access of EBI memory space
#pragma region name = "EBI_SRAM" origin = 0xC0000000 size = 262144

// This is tricking the compiler into placing an array in EBI SRAM
extern uint8_t ebi_sram_array[262144] __attribute__((region("EBI_SRAM")));

// Function to initialize SPI
void spiFlashInit(void)
{
    
    // Disable SPI3 Fault interrupt
    disableInterrupt(SPI3_Fault);
    setInterruptPriority(SPI3_Fault, 1);
    setInterruptSubpriority(SPI3_Fault, 2);
    clearInterruptFlag(SPI3_Fault);
    
    // Disable SPI3 Receive Done Interrupt
    disableInterrupt(SPI3_Receive_Done);
    setInterruptPriority(SPI3_Receive_Done, 5);
    setInterruptSubpriority(SPI3_Receive_Done, 3);
    clearInterruptFlag(SPI3_Receive_Done);
    
    // Disable SPI3 Transfer Done Interrupt
    disableInterrupt(SPI3_Transfer_Done);    
    setInterruptPriority(SPI3_Transfer_Done, 5);
    setInterruptSubpriority(SPI3_Transfer_Done, 2);
    clearInterruptFlag(SPI3_Transfer_Done);
       
    // Turn off module before configuration
    SPI3CONbits.ON = 0;         
    SPI3BUF = 0;                
    SPI3CONbits.ENHBUF = 0;     // Disable enhanced buffer
    SPI3BRG = 5;                // Baud Rate configuration: PBCLK2 = 84MHz, FSCK = 10MHz 
    SPI3STATbits.SPIROV = 0;    
    SPI3CONbits.MSTEN = 1;      // Master mode
    
    // Configure SPI3 registers
    SPI3CONbits.FRMEN = 0;      // Framed SPI support is disabled
    SPI3CONbits.MSSEN = 0;      // Disable slave select SPI support
    SPI3CONbits.FRMSYPW = 0;    // Set frame sync pulse as one word length wide <1> or one clock wide <0>
    SPI3CONbits.MCLKSEL = 0;    // PBCLK is used
    SPI3CONbits.SIDL = 0;       // Continue operation in IDLE mode
    SPI3CONbits.DISSDO = 0;     // SDO3 pin is controlled by module
    SPI3CONbits.MODE16 = 0;     // 16 bit mode disabled
    SPI3CONbits.MODE32 = 0;     // 32 bit mode disabled
    SPI3CONbits.SMP = 1;        // Input data sampled at the end of data output time
    SPI3CONbits.CKE = 1;        // Output data changes on clock falling edge
    SPI3CONbits.SSEN = 0;       // Slave Select pin is controlled by PORT 
    SPI3CONbits.CKP = 0;        // Idle state for clock is low, active state is high
    SPI3CONbits.DISSDI = 0;     // SDI3 pin is controlled by module
    SPI3CONbits.STXISEL = 0b01; // Interrupt is generated when buffer is empty
    SPI3CONbits.SRXISEL = 0b01; // Interrupt is generated when buffer is not empty
    SPI3CON2bits.AUDEN = 0;     // Disable audio mode
    SPI3CON2bits.SPITUREN = 1;  // Transmit underrun triggers a fault interrupt
    
    // Configure bits for Framed Mode ONLY
    SPI3CONbits.FRMSYNC = 0;  
    SPI3CONbits.FRMPOL = 0;  
    SPI3CONbits.FRMCNT = 0;   
    SPI3CONbits.SPIFE = 0;
    
    // Turn on module after configuration
    SPI3CONbits.ON = 1;         
    spi_flash_state = idle;
       
    enableInterrupt(SPI3_Fault);
    
    uint8_t active_chip;
    for (active_chip = 1; active_chip <= 8; active_chip++) {
        SPI_Flash_writeEnable(active_chip);
    }
         
    spi_flash_state = idle;
    
    spiFlashGPIOReset();
}

// Function to set GPIO pins for ~CE and ~WP
void spiFlashGPIOSet(void) {
    
    switch(spi_flash_state) {
        case flash1_write:
            // ~CE Pins
            nFLASH_CE1_PIN = 0;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 0;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;   
            
            break;
            
        case flash1_read:
            // ~CE Pins
            nFLASH_CE1_PIN = 0;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
            
        case flash2_write:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 0;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 0;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
            
        case flash2_read:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 0;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
            
        case flash3_write:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 0;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 0;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
            
        case flash3_read:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 0;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
            
        case flash4_write:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 0;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 0;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
            
        case flash4_read:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 0;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
            
        case flash5_write:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 0;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 0;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
            
        case flash5_read:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 0;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
            
        case flash6_write:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 0;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 0;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
            
        case flash6_read:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 0;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
            
        case flash7_write:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 0;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 0;
            nFLASH_WP8_PIN = 1;  
            
            break;
        
        case flash7_read:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 0;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
        
        case flash8_write:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 0;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 0;  
            
            break;
        
        case flash8_read:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 0;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
     
        default:
            // ~CE Pins
            nFLASH_CE1_PIN = 1;
            nFLASH_CE2_PIN = 1;
            nFLASH_CE3_PIN = 1;
            nFLASH_CE4_PIN = 1;
            nFLASH_CE5_PIN = 1;
            nFLASH_CE6_PIN = 1;
            nFLASH_CE7_PIN = 1;
            nFLASH_CE8_PIN = 1;
            
            // ~WP Pins
            nFLASH_WP1_PIN = 1;
            nFLASH_WP2_PIN = 1;
            nFLASH_WP3_PIN = 1;
            nFLASH_WP4_PIN = 1;
            nFLASH_WP5_PIN = 1;
            nFLASH_WP6_PIN = 1;
            nFLASH_WP7_PIN = 1;
            nFLASH_WP8_PIN = 1;  
            
            break;
    }
    
}

// Function to reset GPIO pins for ~CE and ~WP
void spiFlashGPIOReset(void) {
    
    // ~CE Pins
    nFLASH_CE1_PIN = 1;
    nFLASH_CE2_PIN = 1;
    nFLASH_CE3_PIN = 1;
    nFLASH_CE4_PIN = 1;
    nFLASH_CE5_PIN = 1;
    nFLASH_CE6_PIN = 1;
    nFLASH_CE7_PIN = 1;
    nFLASH_CE8_PIN = 1;

    // ~WP Pins
    nFLASH_WP1_PIN = 1;
    nFLASH_WP2_PIN = 1;
    nFLASH_WP3_PIN = 1;
    nFLASH_WP4_PIN = 1;
    nFLASH_WP5_PIN = 1;
    nFLASH_WP6_PIN = 1;
    nFLASH_WP7_PIN = 1;
    nFLASH_WP8_PIN = 1; 
    
}

// Function to print status
void printSPIFlashStatus(void) {
    
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, UNDERSCORE);
    printf("SPI Flash Status:\n\r");
    
    if (SPI3CONbits.FRMEN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    SPI Frame Support %s\n\r",
            SPI3CONbits.FRMEN ? "Enabled" : "Disabled");

    if (SPI3CONbits.MSSEN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Slave Select Support %s\n\r",
            SPI3CONbits.MSSEN ? "Enabled" : "Disabled");
    
    if (SPI3CONbits.FRMSYPW) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Frame Sync Pulse Width %s\n\r",
            SPI3CONbits.FRMSYPW ? "Word" : "Clock");
    
    if (SPI3CONbits.MCLKSEL) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Master Clock Select %s\n\r",
            SPI3CONbits.MCLKSEL ? "MCLK" : "PBCLK");
    
    if (SPI3CONbits.ENHBUF) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Enhanced Buffer Support %s\n\r",
            SPI3CONbits.ENHBUF ? "Enabled" : "Disabled");
    
    if (SPI3CONbits.SIDL) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Stop in Idle Mode %s\n\r",
            SPI3CONbits.SIDL ? "Discontinue" : "Continue");
        
    if (SPI3CONbits.DISSDO) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Module SDOx Pin Control %s\n\r",
            SPI3CONbits.DISSDO ? "Disabled" : "Enabled");
    
    if (SPI3CONbits.MODE16) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    16 Bit Communication %s\n\r",
            SPI3CONbits.MODE16 ? "Enabled" : "Disabled");
    
    if (SPI3CONbits.MODE32) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    32 Bit Communication %s\n\r",
            SPI3CONbits.MODE32 ? "Enabled" : "Disabled");
    
    if (SPI3CONbits.SMP) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Input Sample Phase %s\n\r",
            SPI3CONbits.SMP ? "End of Data" : "Middle of Data");
    
    if (SPI3CONbits.CKE) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Clock Edge Select %s\n\r",
            SPI3CONbits.CKE ? "Falling Edge" : "Rising Edge");
    
    if (SPI3CONbits.SSEN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Slave Select Enable %s\n\r",
            SPI3CONbits.SSEN ? "Enabled" : "Disabled");
    
    if (SPI3CONbits.CKP) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Clock Polarity %s\n\r",
            SPI3CONbits.CKP ? "Inverted" : "Standard");
    
    if (SPI3CONbits.MSTEN) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Master Mode Enable %s\n\r",
            SPI3CONbits.MSTEN ? "Enabled" : "Disabled");
    
    if (SPI3CONbits.DISSDI) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Module SDIx Pin Control %s\n\r",
            SPI3CONbits.DISSDI ? "Disabled" : "Enabled");
    
    printf("\n\r    Transmit Buffer Interrupt: ");
    
    switch (SPI3CONbits.STXISEL) {
     
        case 0b00:
            printf("When transmit operations are complete\n\r");
            break;
            
        case 0b01:
            printf("When buffer is completely empty\n\r");
            break;
            
        case 0b10:
            printf("When buffer is less than half empty\n\r");
            break;
    
        case 0b11:
            printf("When the buffer is not full\n\r");
            break;
            
    }
    
    
    printf("    Receive Buffer Interrupt: ");
    
    switch (SPI3CONbits.SRXISEL) {
     
        case 0b00:
            printf("When last word in receive buffer is read\n\r");
            break;
            
        case 0b01:
            printf("When buffer is not empty\n\r");
            break;
            
        case 0b10:
            printf("When buffer is at least half full\n\r");
            break;
    
        case 0b11:
            printf("When buffer is full\n\r");
            break;
            
    }
        
    printf("\n\r    SPIBRG: %d\n\r", SPI3BRG);
    
    terminalTextAttributesReset();
}

// SPI3 Fault interrupt service routine
void __ISR(_SPI3_FAULT_VECTOR, ipl1SRS) spi3FaultISR(void) {
    
    // Record a SPI error
    error_handler.SPI_error_flag = 1;
    
    if (SPI3STATbits.SPIROV) {
        error_handler.SPI_receive_overflow_error_flag = 1;
        SPI3STATbits.SPIROV = 0;
    }
    
    if (SPI3STATbits.SPITUR) {
        error_handler.SPI_transfer_underrun_error_flag = 1;
        SPI3STATbits.SPITUR = 0;
    }
    
    // Disable SPI interrupts
    disableInterrupt(SPI3_Transfer_Done);
    disableInterrupt(SPI3_Receive_Done);
    
    // Clear interrupt flag after ISR
    clearInterruptFlag(SPI3_Fault);
}

// SPI3 Receive Done interrupt service routine
void __ISR(_SPI3_RX_VECTOR, ipl5SRS) spi3ReceiveISR(void) {
     
    // Load in byte to ebi_sram_array and increment index
    ebi_sram_array[sram_addr_index] = SPI3BUF;
    sram_addr_index++;
    
    // Check if we are at the end of the array
    if (sram_addr_index >= PANEL_DATA_ARRAY_SIZE) {
        
        disableInterrupt(SPI3_Receive_Done);
        
        spiFlashGPIOReset();
        
        spi_flash_state = idle;
        
        // Disable RX overrun interrupt trigger
        SPI3STATbits.SPIROV = 0;
        SPI3CON2bits.SPIROVEN = 0;
        
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Transfer from Flash to EBI SRAM complete\n\r");
        terminalTextAttributesReset();
        
        panelMultiplexingTimerStart();
        
    } else {
        
        SPI3_writeByte(0x00);
        
    }
           
    // Clear interrupt flag after ISR
    clearInterruptFlag(SPI3_Receive_Done);
}

//SPI3 Transfer Done interrupt service routine
void __ISR(_SPI3_TX_VECTOR, ipl5SRS) spi3TransferISR(void) {

    // Load in byte to ebi_sram_array and increment index
    SPI3BUF = ebi_sram_array[sram_addr_index];
    sram_addr_index++;
    
    // Check if we are at the end of the array
    if (sram_addr_index >= PANEL_DATA_ARRAY_SIZE) {
        
        disableInterrupt(SPI3_Transfer_Done);
        
        // SPI3_writeByte(0x04);
        // SPI3_writeByte(0x80);
        
        spiFlashGPIOReset();
        
        spi_flash_state = idle;
               
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Transfer from EBI SRAM to Flash complete\n\r");
        terminalTextAttributesReset();
        
        panelMultiplexingTimerStart();
        
    }

    // Clear interrupt flag after ISR
    clearInterruptFlag(SPI3_Transfer_Done);

}

// Function to write single byte to transmit FIFO
void SPI3_writeByte(uint8_t write_byte) {
    
    SPI3BUF = write_byte;
    
}


// Function to read single byte from receive FIFO
uint8_t SPI3_readByte(void) {
    
    return SPI3BUF;
    
}

// This function erases a spi flash chip
void SPI_FLASH_chipErase(uint8_t chip_select) {
 
    // Enable spi_flash_state corresponding to chip_select
    switch (chip_select) {
        case 1:
            spi_flash_state = flash1_write;
            break;
        case 2:
            spi_flash_state = flash2_write;
            break;
        case 3:
            spi_flash_state = flash3_write;
            break;
        case 4:
            spi_flash_state = flash4_write;
            break;
        case 5:
            spi_flash_state = flash5_write;
            break;
        case 6:
            spi_flash_state = flash6_write;
            break;
        case 7:
            spi_flash_state = flash7_write;
            break;
        case 8:
            spi_flash_state = flash8_write;
            break;
        default:
            break;
    }
    
    // Set CS and WP signals
    spiFlashGPIOSet();
    
    disableInterrupt(SPI3_Transfer_Done);
    
    // Write enable opcode
    SPI3_writeByte(0x06);

    // Wait for transfer to complete
    while(SPI3STATbits.SPIBUSY);
    
    // Write chip erase opcode to SPI3
    SPI3_writeByte(0x60);
    
    // Wait for transfer to complete
    while(SPI3STATbits.SPIBUSY);
        
    // Clear state machine
    spi_flash_state = idle;
    
    // Clear CS and WP signals
    spiFlashGPIOReset();
    
    clearInterruptFlag(SPI3_Transfer_Done);
    clearInterruptFlag(SPI3_Receive_Done);
    
}

// This function reads from a spi flash chip
void SPI_FLASH_beginRead(uint8_t chip_select) {
    
    panelMultiplexingSuspend();
    
    // Enable spi_flash_state corresponding to chip_select
    switch (chip_select) {
        case 1:
            spi_flash_state = flash1_read;
            break;
        case 2:
            spi_flash_state = flash2_read;
            break;
        case 3:
            spi_flash_state = flash3_read;
            break;
        case 4:
            spi_flash_state = flash4_read;
            break;
        case 5:
            spi_flash_state = flash5_read;
            break;
        case 6:
            spi_flash_state = flash6_read;
            break;
        case 7:
            spi_flash_state = flash7_read;
            break;
        case 8:
            spi_flash_state = flash8_read;
            break;
        default:
            break;
    }
    
    // Set CS and WP signals
    spiFlashGPIOSet();
    
    // Set addr index to 0
    sram_addr_index = 0;
      
    // Write chip read opcode to SPI3 (0x0B for high speed read, 0x03 for standard read))
    SPI3_writeByte(0x0B);
    
    // Wait for transfer to complete
    while(SPI3STATbits.SPIBUSY);
    
    // Write addr1 byte
    SPI3_writeByte(0x00);
    
    // Wait for transfer to complete
    while(SPI3STATbits.SPIBUSY);
    
    // Write addr2 byte
    SPI3_writeByte(0x00);
    
    // Wait for transfer to complete
    while(SPI3STATbits.SPIBUSY);
    
    // Write addr3 byte
    SPI3_writeByte(0x00);
    
    // Wait for transfer to complete
    while(SPI3STATbits.SPIBUSY);
    
    // Write dummy byte (needed for high speed read)
    SPI3_writeByte(0xDD);
    
    // Wait for transfer to complete
    while(SPI3STATbits.SPIBUSY);
        
    // write another dummy byte to start read
    SPI3_writeByte(0x00);
    
    // Enable overrun error detection
    SPI3STATbits.SPIROV = 0;
    SPI3CON2bits.SPIROVEN = 1;  // Receive Overrun triggers a fault interrupt

    
    // Enable receive interrupt and wait
    clearInterruptFlag(SPI3_Receive_Done);
    enableInterrupt(SPI3_Receive_Done);
    
}

// This function writes to a spi flash chip
void SPI_FLASH_beginWrite(uint8_t chip_select) {
    
    panelMultiplexingSuspend();
    
    // Be sure chip is in erased state
    SPI_FLASH_chipErase(chip_select);
    
    // Enable spi_flash_state corresponding to chip_select
    switch (chip_select) {
        case 1:
            spi_flash_state = flash1_write;
            break;
        case 2:
            spi_flash_state = flash2_write;
            break;
        case 3:
            spi_flash_state = flash3_write;
            break;
        case 4:
            spi_flash_state = flash4_write;
            break;
        case 5:
            spi_flash_state = flash5_write;
            break;
        case 6:
            spi_flash_state = flash6_write;
            break;
        case 7:
            spi_flash_state = flash7_write;
            break;
        case 8:
            spi_flash_state = flash8_write;
            break;
        default:
            break;
    }
    
    // Set CS and WP signals
    spiFlashGPIOSet();
    
    // Set addr index to 0
    sram_addr_index = 0;
    
//    // Send write enable 
//    SPI3_writeByte(0x06);
    
    // Send AAI programming opcode
    SPI3_writeByte(0xAD);
    
    // Wait for transfer to complete
    while(SPI3STATbits.SPIBUSY);
    
    // Send address bytes
    SPI3_writeByte(0x00);
    
    // Wait for transfer to complete
    while(SPI3STATbits.SPIBUSY);
    
    SPI3_writeByte(0x00);
    
    // Wait for transfer to complete
    while(SPI3STATbits.SPIBUSY);
        
    SPI3_writeByte(0x00);
    
    // Wait for transfer to complete
    while(SPI3STATbits.SPIBUSY);
    
    clearInterruptFlag(SPI3_Transfer_Done);
    enableInterrupt(SPI3_Transfer_Done);
       
}

// This function enables write enable
void SPI_Flash_writeEnable(uint8_t chip_select){
    
    // Enable spi_flash_state corresponding to chip_select
    switch (chip_select) {
        case 1:
            spi_flash_state = flash1_write;
            break;
        case 2:
            spi_flash_state = flash2_write;
            break;
        case 3:
            spi_flash_state = flash3_write;
            break;
        case 4:
            spi_flash_state = flash4_write;
            break;
        case 5:
            spi_flash_state = flash5_write;
            break;
        case 6:
            spi_flash_state = flash6_write;
            break;
        case 7:
            spi_flash_state = flash7_write;
            break;
        case 8:
            spi_flash_state = flash8_write;
            break;
        default:
            break;
    }
    
    // Set CS and WP signals
    spiFlashGPIOSet();
    
    // Send write enable opcode
    SPI3_writeByte(0x06);
    
    // Wait for transfer to complete
    while(SPI3STATbits.SPIBUSY);
    
    clearInterruptFlag(SPI3_Transfer_Done);
    clearInterruptFlag(SPI3_Receive_Done);
    
}