
#include "Panel_Pin_Init.h"

// This function sets the state of the 8 RED bus pins
void setPanelRedBus(uint8_t inputByte) {
    
    // RED bus is defined as RA0:7
    LATA = (LATA & 0xFF00) | inputByte;
    
}

// This function sets the state of the 8 GREEN bus pins
void setPanelGreenBus(uint8_t inputByte) {
    
    // GREEN bus is defined as RB0:7
    LATB = (LATB & 0xFF00) | inputByte;
    
}

// This function sets the state of the 8 BLUE bus pins
void setPanelBlueBus(uint8_t inputByte) {
    
    // BLUE bus is defined as RB8:15
    LATB = (LATB & 0x00FF) | (inputByte << 8);
    
}

// Set ROW bus state functions
void setPanelRowBus(uint8_t inputByte) {
 
    LATD = (LATD & 0b1100000111111111) | ((inputByte & 0x1F) << 9);
    
}


void panelPinInit(void) {
 
    // Set up red control bus pins as outputs
    red0TRIS = 0;
    red1TRIS = 0;
    red2TRIS = 0;
    red3TRIS = 0;
    red4TRIS = 0;
    red5TRIS = 0;
    red6TRIS = 0;
    red7TRIS = 0;
    
    // Set up green control bus pins as outputs
    green0TRIS = 0;
    green1TRIS = 0;
    green2TRIS = 0;
    green3TRIS = 0;
    green4TRIS = 0;
    green5TRIS = 0;
    green6TRIS = 0;
    green7TRIS = 0;
    
    // Set up blue control bus pins as outputs
    blue0TRIS = 0;
    blue1TRIS = 0;
    blue2TRIS = 0;
    blue3TRIS = 0;
    blue4TRIS = 0;
    blue5TRIS = 0;
    blue6TRIS = 0;
    blue7TRIS = 0;
    
    // Set up row control bus pins as outputs
    rowETRIS = 0;
    rowDTRIS = 0;
    rowCTRIS = 0;
    rowBTRIS = 0;
    rowATRIS = 0;
    
    // Set control lines as outputs
    panelLATTRIS = 0;
    panelCLKTRIS = 0;
    panelnOETRIS = 0;
    
    // Set control line default states
    panelLAT = 1;
    panelCLK = 0;
    panelnOE = 0;
    
    // Clear all RGB bus signals
    setPanelRedBus(0x00);
    setPanelGreenBus(0x00);
    setPanelBlueBus(0x00);
    
    // set row select bus to 0
    setPanelRowBus(0x00);
    
    
}
