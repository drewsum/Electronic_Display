/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#include <xc.h>

#include "device_control.h"

// private function prototype

// this function sets up the PLL
void PLLInitialize(void);

// this function sets up reference clock 1
void REFCLK1Initialize(void);

// this function sets up reference clock 2
void REFCLK2Initialize(void);

// this function sets up reference clock 3
void REFCLK3Initialize(void);

// this function sets up reference clock 4
void REFCLK4Initialize(void);

// this function sets up peripheral bus clock 1
void PBCLK1Initialize(void);

// this function sets up peripheral bus clock 2
void PBCLK2Initialize(void);

// this function sets up peripheral bus clock 3
void PBCLK3Initialize(void);

// this function sets up peripheral bus clock 4
void PBCLK4Initialize(void);

// this function sets up peripheral bus clock 5
void PBCLK5Initialize(void);

// this function sets up peripheral bus clock 7
void PBCLK7Initialize(void);

// this function sets up peripheral bus clock 8
void PBCLK8Initialize(void);

// Unlock system function
// This function unlocks the device so that device parameters can be changed
// and the microcontroller can be reset
void deviceUnlock(void) {
    
     // force a lock
    SYSKEY = 0x00000000;
    // write key1 to SYSKEY per datasheet
    SYSKEY = 0xAA996655;
    // write key2 to SYSKEY per datasheet
    SYSKEY = 0x556699AA;
    
}


// Lock system function
// This function re-locks the system so that important device parameters may 
// not be changed
void deviceLock(void) {
    
     // write an invalid key to force lock
    SYSKEY = 0x00000000;
    
}

// Rest device function
// This function resets the microcontroller
void deviceReset(void) {
    
    // disable interrupts
    disableGlobalInterrupts();
    
    // unlock the device
    deviceUnlock();
    
    // Arm reset
    RSWRSTSET = 1;
    
    // read RSWRST register to trigger reset
    unsigned int dummy = RSWRST;
    
}

// This function is a software delay that simply counts loops while decrementing
// the argument
void softwareDelay(uint32_t inputDelay) {
 
    while (inputDelay > 0) {
     
        inputDelay--;
        
    }
    
}

// This function initializes the oscillator and PLL
// This sets up a SYSCLK of 252 MHz
// REFCLK1: Disabled
// REFCLK2: Disabled
// REFCLK3: Disabled
// REFCLK4: Disabled
// PBCLK1: 84 MHz
// PBCLK2: 84 MHz
// PBCLK3: 15.75 MHz
// PBCLK4: 84 MHz
// PBCLK5: 84 MHz
// PBCLK7: 252 MHz
// PBCLK8: 84 MHz
void clockInitialize(void) {
 
    // unlock the device
    deviceUnlock();
    
    // unlock clock and PLL settings
    OSCCONbits.CLKLOCK = 0;
    
    // set the FRC divider to 1
    // This sets FRCDIV frequency to 8 MHz
    OSCCONbits.FRCDIV = 0b000;
    
    // Initialize the PLL
    PLLInitialize();
    
    // Initialize peripheral bus clocks
    PBCLK1Initialize();
    PBCLK2Initialize();
    PBCLK3Initialize();
    PBCLK4Initialize();
    PBCLK5Initialize();
    PBCLK7Initialize();
    PBCLK8Initialize();
    
    // Initialize reference clocks
    REFCLK1Initialize();
    REFCLK2Initialize();
    REFCLK3Initialize();
    REFCLK4Initialize();
    
    // lock clock and PLL settings
    OSCCONbits.CLKLOCK = 1;
    
    // re-lock the device
    deviceLock();
    
}

// this function sets up the PLL
void PLLInitialize(void) {
 
    // Set PLL input range as 5-10 MHz
    SPLLCONbits.PLLRANGE = 0b001;
    
    // Set the input to the PLL as FRC
    SPLLCONbits.PLLICLK = 1;
    
    // Set PLL input divider to 1
    SPLLCONbits.PLLIDIV = 0b000;
    
    // Set PLL multiplier to 63
    SPLLCONbits.PLLMULT = 0b111110; // (62 in binary, 0b0000000 => PLL X 1)
    
    // Set PLL output divider to 2
    SPLLCONbits.PLLODIV = 0b001;
    
}

// this function sets up reference clock 1
void REFCLK1Initialize(void) {
 
    // Set REFCLK1 divider to 1
    REFO1CONbits.RODIV = 0b000000000000000;
    
    // Disable REFCLK1
    REFO1CONbits.ON = 0;
    
    // Disable REFCLK1 in Idle mode
    REFO1CONbits.SIDL = 1;
    
    // Disable output of REFCLK1 onto output pin
    REFO1CONbits.OE = 0;
    
    // Disable REFCLK1 in sleep
    REFO1CONbits.RSLP = 0;
    
}

// this function sets up reference clock 2
void REFCLK2Initialize(void) {
 
    // Set REFCLK2 divider to 1
    REFO2CONbits.RODIV = 0b000000000000000;
    
    // Disable REFCLK2
    REFO2CONbits.ON = 0;
    
    // Disable REFCLK2 in Idle mode
    REFO2CONbits.SIDL = 1;
    
    // Disable output of REFCLK2 onto output pin
    REFO2CONbits.OE = 0;
    
    // Disable REFCLK2 in sleep
    REFO2CONbits.RSLP = 0;
    
}

// this function sets up reference clock 3
void REFCLK3Initialize(void) {
 
    // Set REFCLK3 divider to 1
    REFO3CONbits.RODIV = 0b000000000000000;
    
    // Disable REFCLK3
    REFO3CONbits.ON = 0;
    
    // Disable REFCLK3 in Idle mode
    REFO3CONbits.SIDL = 1;
    
    // Disable output of REFCLK3 onto output pin
    REFO3CONbits.OE = 0;
    
    // Disable REFCLK3 in sleep
    REFO3CONbits.RSLP = 0;
    
}

// this function sets up reference clock 4
void REFCLK4Initialize(void) {
 
    // Set REFCLK4 divider to 1
    REFO4CONbits.RODIV = 0b000000000000000;
    
    // Disable REFCLK4
    REFO4CONbits.ON = 0;
    
    // Disable REFCLK4 in Idle mode
    REFO4CONbits.SIDL = 1;
    
    // Disable output of REFCLK4 onto output pin
    REFO4CONbits.OE = 0;
    
    // Disable REFCLK4 in sleep
    REFO4CONbits.RSLP = 0;
    
}

// this function sets up peripheral bus clock 1
void PBCLK1Initialize(void) {
 
    // wait for divisor to be ready for change
    while (PB1DIVbits.PBDIVRDY == 0);
    
    // Set PBCLK1 divider to 3
    PB1DIVbits.PBDIV = 0b0000010;
    
    // Enable PBCLK1
    // (PBCLK1 cannot be turned off so the ON bit is hardwired 1 in silicon)
    
}

// this function sets up peripheral bus clock 2
void PBCLK2Initialize(void) {
 
    // wait for divisor to be ready for change
    while (PB2DIVbits.PBDIVRDY == 0);
    
    // Set PBCLK2 divider to 3
    PB2DIVbits.PBDIV = 0b0000010;
    
    // Enable PBCLK2
    PB2DIVbits.ON = 1;
    
}

// this function sets up peripheral bus clock 3
void PBCLK3Initialize(void) {
 
    // wait for divisor to be ready for change
    while (PB3DIVbits.PBDIVRDY == 0);
    
    // Set PBCLK3 divider to 16
    PB3DIVbits.PBDIV = 0b1111;;
    
    // Enable PBCLK3
    PB3DIVbits.ON = 1;
    
}

// this function sets up peripheral bus clock 4
void PBCLK4Initialize(void) {
 
    // wait for divisor to be ready for change
    while (PB4DIVbits.PBDIVRDY == 0);
    
    // Set PBCLK4 divider to 3
    PB4DIVbits.PBDIV = 0b0000010;
    
    // Enable PBCLK4
    PB4DIVbits.ON = 1;
    
}

// this function sets up peripheral bus clock 5
void PBCLK5Initialize(void) {
 
    // wait for divisor to be ready for change
    while (PB5DIVbits.PBDIVRDY == 0);
    
    // Set PBCLK5 divider to 3
    PB5DIVbits.PBDIV = 0b0000010;
    
    // Enable PBCLK5
    PB5DIVbits.ON = 1;
    
}

// this function sets up peripheral bus clock 7
void PBCLK7Initialize(void) {
 
    // wait for divisor to be ready for change
    while (PB7DIVbits.PBDIVRDY == 0);
    
    // Set PBCLK7 divider to 1
    PB7DIVbits.PBDIV = 0b0000000;
    
    // Enable PBCLK7
    PB7DIVbits.ON = 1;
    
}

// this function sets up peripheral bus clock 8
void PBCLK8Initialize(void) {
 
    // wait for divisor to be ready for change
    while (PB8DIVbits.PBDIVRDY == 0);
    
    // Set PBCLK8 divider to 3
    PB8DIVbits.PBDIV = 0b0000010;
    
    // Enable PBCLK8
    PB8DIVbits.ON = 1;
    
}

// This function unlocks peripheral pin select
// THIS CAN ONLY BE CALLED ONCE PER DEVICE RESET!!!
void PPSUnlock(void) {

    // Unlock device
    deviceUnlock();
    
    // Unlock PPS
    CFGCONbits.IOLOCK = 0;
    
    // Lock device
    deviceLock();
    
}

// This function locks peripheral pin select
void PPSLock(void) {
    
    // Unlock device
    deviceUnlock();
    
    // Lock PPS
    CFGCONbits.IOLOCK = 1;
    
    // Lock device
    deviceLock();
    
}

// This function unlocks peripheral module disable
void PMDUnlock(void) {
    
    // Unlock device
    deviceUnlock();
    
    // Unlock PMD
    CFGCONbits.PMDLOCK = 0;
    
    // Lock device
    deviceLock();
    
}

// This function locks peripheral module disable
void PMDLock(void) {
    
    // Unlock device
    deviceUnlock();
    
    // Lock PMD
    CFGCONbits.PMDLOCK = 1;
    
    // Lock device
    deviceLock();
    
}

