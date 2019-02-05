#include <xc.h>
#include <stdio.h>
#include <string.h>

#include "terminal_control.h"
#include "spi_flash.h"
#include "32mz_interrupt_control.h"
#include "error_handler.h"
#include "pin_macros.h"

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
    SPI3STATbits.SPIROV = 0;    
    
    // Configure SPI3 registers
    SPI3CONbits.FRMEN = 0;      // Framed SPI support is disabled
    SPI3CONbits.MSSEN = 0;      // Disable slave select SPI support
    SPI3CONbits.FRMSYPW = 0;    // Set frame sync pulse as one word length wide <1> or one clock wide <0>
    SPI3CONbits.MCLKSEL = 0;    // PBCLK is used
    SPI3CONbits.ENHBUF = 0;     // Disable enhanced buffer
    SPI3CONbits.SIDL = 0;       // Continue operation in IDLE mode
    SPI3CONbits.DISSDO = 1;     // SDO3 pin is controlled PORT register
    SPI3CONbits.MODE16 = 0;     // 16 bit mode disabled
    SPI3CONbits.MODE32 = 0;     // 32 bit mode disabled
    SPI3CONbits.SMP = 1;        // Input data sampled at the end of data output time
    SPI3CONbits.CKE = 1;        // Output data changes on clock falling edge
    SPI3CONbits.SSEN = 0;       // Slave Select pin is controlled by PORT 
    SPI3CONbits.CKP = 0;        // Idle state for clock is low, active state is high
    SPI3CONbits.MSTEN = 1;      // Master mode
    SPI3CONbits.DISSDI = 1;     // SDI3 pin is controlled by PORT
    SPI3CONbits.STXISEL = 0b01; // Interrupt is generated when buffer is empty
    SPI3CONbits.SRXISEL = 0b01; // Interrupt is generated when buffer is not empty
    // SPI1BRG = 3;             // Baud Rate configuration
    
    // Configure bits for Framed Mode ONLY
    /* SPI3CONbits.FRMSYNC = 0;  
     * SPI3CONbits.FRMPOL = 0;  
     * SPI3CONbits.FRMCNT = 0;   
     * SPI3CONbits.SPIFE = 0; */     
    
    // Turn on module after configuration
    SPI3CONbits.ON = 1;         
    spi_flash_state = idle;
       
    enableInterrupt(SPI3_Fault);
         
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
    
    terminalTextAttributesReset();
}

// SPI3 Fault interrupt service routine
void __ISR(_SPI3_FAULT_VECTOR, ipl1SRS) spi3FaultISR(void) {
    
    // Print something for now
    printf("SPI3 Fault ISR");
    
    // Clear interrupt flag after ISR
    clearInterruptFlag(SPI3_Fault);
}

// SPI3 Receive Done interrupt service routine
void __ISR(_SPI3_RX_VECTOR, ipl5SRS) spi3ReceiveISR(void) {

    // Print something for now
    printf("SPI3 Receive Done ISR");

    // Clear interrupt flag after ISR
    clearInterruptFlag(SPI3_Receive_Done);
}

//SPI3 Transfer Done interrupt service routine
void __ISR(_SPI3_TX_VECTOR, ipl4SRS) spi3TransferISR(void) {

    // Print something for now
    printf("SPI3 Transfer Done ISR");

    // Clear interrupt flag after ISR
    clearInterruptFlag(SPI3_Transfer_Done);

}



