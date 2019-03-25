/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _CONFIGURE_H    /* Guard against multiple inclusion */
#define _CONFIGURE_H

// PIC32MZ2048EFH144 Configuration Bit Settings

// 'C' source line config statements

// DEVCFG3
// USERID = No Setting
#pragma config FMIIEN = OFF             // Ethernet RMII/MII Enable (RMII Enabled)
#pragma config FETHIO = ON              // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config PGL1WAY = ON             // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
#pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config FUSBIDIO = OFF           // USB USBID Selection (Controlled by Port Function)

// DEVCFG2
#pragma config FPLLIDIV = DIV_4         // System PLL Input Divider (1x Divider)
#pragma config FPLLRNG = RANGE_5_10_MHZ // System PLL Input Range (5-10 MHz Input)
#pragma config FPLLICLK = PLL_FRC       // System PLL Input Clock Selection (FRC is input to the System PLL)
#pragma config FPLLMULT = MUL_63        // System PLL Multiplier (PLL Multiply by 63)
#pragma config FPLLODIV = DIV_2         // System PLL Output Clock Divider (2x Divider)
#pragma config UPLLFSEL = FREQ_24MHZ    // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

// DEVCFG1
#pragma config FNOSC = FRCDIV             // Oscillator Selection Bits (FRC)
#pragma config DMTINTV = WIN_127_128    // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Disable SOSC)
#pragma config IESO = OFF               // Internal/External Switch Over (Disabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FCKSM = CSECME           // Clock Switching and Monitor Selection (Clock Switch Enabled, FSCM Enabled)
#pragma config WDTPS = PS2048           // Watchdog Timer Postscaler (1:2048)
#pragma config WDTSPGM = STOP           // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config WINDIS = NORMAL          // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config FWDTEN = ON              // Watchdog Timer Enable (WDT Enabled)
#pragma config FWDTWINSZ = WINSZ_75     // Watchdog Timer Window Size (Window size is 75%)
#pragma config DMTCNT = DMT31           // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config FDMTEN = ON              // Deadman Timer Enable (Deadman Timer is enabled)

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is disabled)
#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
#pragma config ICESEL = ICS_PGx1        // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config TRCEN = OFF              // Trace Enable (Trace features in the CPU are disabled)
#pragma config BOOTISA = MIPS32         // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config FECCCON = OFF_LOCKED             // Dynamic Flash ECC Configuration (Flash ECC is enabled (ECCCON bits are locked))
#pragma config FSLEEP = OFF             // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config DBGPER = PG_ALL          // Debug Mode CPU Access Permission (Allow CPU access to all permission regions)
#pragma config SMCLR = MCLR_NORM        // Soft Master Clear Enable bit (MCLR pin generates a normal system Reset)
#pragma config SOSCGAIN = GAIN_2X       // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config SOSCBOOST = ON           // Secondary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config POSCGAIN = GAIN_2X       // Primary Oscillator Gain Control bits (2x gain setting)
#pragma config POSCBOOST = ON           // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config EJTAGBEN = NORMAL        // EJTAG Boot (Normal EJTAG functionality)

// DEVCP0
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

#pragma config TSEQ = 0xffff
#pragma config CSEQ = 0x0000

// SEQ3

// DEVADC0

// DEVADC1

// DEVADC2

// DEVADC3

// DEVADC4

// DEVADC7

// ADEVCFG3
// USERID = No Setting
#pragma config_alt FMIIEN = OFF         // Ethernet RMII/MII Enable (RMII Enabled)
#pragma config_alt FETHIO = ON          // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config_alt PGL1WAY = ON         // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
#pragma config_alt PMDL1WAY = ON        // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config_alt IOL1WAY = ON         // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config_alt FUSBIDIO = OFF       // USB USBID Selection (Controlled by Port Function)

// ADEVCFG2
#pragma config_alt FPLLIDIV = DIV_4     // System PLL Input Divider (1x Divider)
#pragma config_alt FPLLRNG = RANGE_5_10_MHZ// System PLL Input Range (5-10 MHz Input)
#pragma config_alt FPLLICLK = PLL_FRC   // System PLL Input Clock Selection (FRC is input to the System PLL)
#pragma config_alt FPLLMULT = MUL_63    // System PLL Multiplier (PLL Multiply by 63)
#pragma config_alt FPLLODIV = DIV_2     // System PLL Output Clock Divider (2x Divider)
#pragma config_alt UPLLFSEL = FREQ_24MHZ// USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

// ADEVCFG1
#pragma config_alt FNOSC = FRCDIV             // Oscillator Selection Bits (FRC)
#pragma config_alt DMTINTV = WIN_127_128// DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config_alt FSOSCEN = OFF        // Secondary Oscillator Enable (Disable SOSC)
#pragma config_alt IESO = OFF           // Internal/External Switch Over (Disabled)
#pragma config_alt POSCMOD = OFF        // Primary Oscillator Configuration (Primary osc disabled)
#pragma config_alt OSCIOFNC = OFF       // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config_alt FCKSM = CSECME       // Clock Switching and Monitor Selection (Clock Switch Enabled, FSCM Enabled)
#pragma config_alt WDTPS = PS2048       // Watchdog Timer Postscaler (1:2048)
#pragma config_alt WDTSPGM = STOP       // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config_alt WINDIS = NORMAL      // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config_alt FWDTEN = ON          // Watchdog Timer Enable (WDT Enabled)
#pragma config_alt FWDTWINSZ = WINSZ_75 // Watchdog Timer Window Size (Window size is 75%)
#pragma config_alt DMTCNT = DMT31       // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config_alt FDMTEN = ON          // Deadman Timer Enable (Deadman Timer is enabled)

// ADEVCFG0
#pragma config_alt DEBUG = OFF          // Background Debugger Enable (Debugger is disabled)
#pragma config_alt JTAGEN = OFF          // JTAG Enable (JTAG Port Enabled)
#pragma config_alt ICESEL = ICS_PGx1    // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config_alt TRCEN = OFF           // Trace Disable (Trace features in the CPU are Disabled)
#pragma config_alt BOOTISA = MIPS32     // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config_alt FECCCON = OFF_LOCKED    // Dynamic Flash ECC Configuration (Dynamic Flash ECC is enabled (ECCCON bits are locked))
#pragma config_alt FSLEEP = OFF         // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config_alt DBGPER = PG_ALL      // Debug Mode CPU Access Permission (Allow CPU access to all permission regions)
#pragma config_alt SMCLR = MCLR_NORM    // Soft Master Clear Enable bit (MCLR pin generates a normal system Reset)
#pragma config_alt SOSCGAIN = GAIN_2X   // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config_alt SOSCBOOST = ON       // Secondary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config_alt POSCGAIN = GAIN_2X   // Primary Oscillator Gain Control bits (2x gain setting)
#pragma config_alt POSCBOOST = ON       // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config_alt EJTAGBEN = NORMAL    // EJTAG Boot (Normal EJTAG functionality)

// ADEVCP0
#pragma config_alt CP = OFF             // Code Protect (Protection Disabled)

#pragma config_alt TSEQ = 0xfffe
#pragma config_alt CSEQ = 00001

// ASEQ3

// AUBADEVCFG3
// USERID = No Setting
#pragma config_auba FMIIEN = OFF        // Ethernet RMII/MII Enable (RMII Enabled)
#pragma config_auba FETHIO = ON         // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config_auba PGL1WAY = ON        // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
#pragma config_auba PMDL1WAY = ON       // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config_auba IOL1WAY = ON        // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config_auba FUSBIDIO = OFF      // USB USBID Selection (Controlled by Port Function)

// AUBADEVCFG2
#pragma config_auba FPLLIDIV = DIV_4    // System PLL Input Divider (1x Divider)
#pragma config_auba FPLLRNG = RANGE_5_10_MHZ// System PLL Input Range (5-10 MHz Input)
#pragma config_auba FPLLICLK = PLL_FRC  // System PLL Input Clock Selection (FRC is input to the System PLL)
#pragma config_auba FPLLMULT = MUL_63   // System PLL Multiplier (PLL Multiply by 63)
#pragma config_auba FPLLODIV = DIV_2    // System PLL Output Clock Divider (2x Divider)
#pragma config_auba UPLLFSEL = FREQ_24MHZ// USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

// AUBADEVCFG1
#pragma config_auba FNOSC = FRCDIV             // Oscillator Selection Bits (FRC)
#pragma config_auba DMTINTV = WIN_127_128// DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config_auba FSOSCEN = OFF       // Secondary Oscillator Enable (Disable SOSC)
#pragma config_auba IESO = OFF           // Internal/External Switch Over (Disabled)
#pragma config_auba POSCMOD = OFF       // Primary Oscillator Configuration (Primary osc disabled)
#pragma config_auba OSCIOFNC = OFF      // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config_auba FCKSM = CSECME      // Clock Switching and Monitor Selection (Clock Switch Enabled, FSCM Enabled)
#pragma config_auba WDTPS = PS2048      // Watchdog Timer Postscaler (1:2048)
#pragma config_auba WDTSPGM = STOP      // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config_auba WINDIS = NORMAL     // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config_auba FWDTEN = ON         // Watchdog Timer Enable (WDT Enabled)
#pragma config_auba FWDTWINSZ = WINSZ_75// Watchdog Timer Window Size (Window size is 75%)
#pragma config_auba DMTCNT = DMT31      // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config_auba FDMTEN = ON         // Deadman Timer Enable (Deadman Timer is enabled)

// AUBADEVCFG0
#pragma config_auba DEBUG = OFF         // Background Debugger Enable (Debugger is disabled)
#pragma config_auba JTAGEN = OFF         // JTAG Enable (JTAG Port Enabled)
#pragma config_auba ICESEL = ICS_PGx1   // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config_auba TRCEN = OFF         // Trace Enable (Trace features in the CPU are disabled)
#pragma config_auba BOOTISA = MIPS32    // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config_auba FECCCON = OFF_LOCKED   // Dynamic Flash ECC Configuration (Dynamic Flash ECC is enabled (ECCCON bits are locked))
#pragma config_auba FSLEEP = OFF        // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config_auba DBGPER = PG_ALL     // Debug Mode CPU Access Permission (Allow CPU access to all permission regions)
#pragma config_auba SMCLR = MCLR_NORM   // Soft Master Clear Enable bit (MCLR pin generates a normal system Reset)
#pragma config_auba SOSCGAIN = GAIN_2X  // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config_auba SOSCBOOST = ON      // Secondary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config_auba POSCGAIN = GAIN_2X  // Primary Oscillator Gain Control bits (2x gain setting)
#pragma config_auba POSCBOOST = ON      // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config_auba EJTAGBEN = NORMAL   // EJTAG Boot (Normal EJTAG functionality)

// AUBADEVCP0
#pragma config_auba CP = OFF            // Code Protect (Protection Disabled)

#pragma config_auba TSEQ = 0xfffc
#pragma config_auba CSEQ = 0x0003

// AUBASEQ3

// UBADEVCFG3
// USERID = No Setting
#pragma config_uba FMIIEN = OFF         // Ethernet RMII/MII Enable (RMII Enabled)
#pragma config_uba FETHIO = ON          // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config_uba PGL1WAY = ON         // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
#pragma config_uba PMDL1WAY = ON        // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config_uba IOL1WAY = ON         // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config_uba FUSBIDIO = OFF       // USB USBID Selection (Controlled by Port Function)

// UBADEVCFG2
#pragma config_uba FPLLIDIV = DIV_4     // System PLL Input Divider (1x Divider)
#pragma config_uba FPLLRNG = RANGE_5_10_MHZ// System PLL Input Range (5-10 MHz Input)
#pragma config_uba FPLLICLK = PLL_FRC   // System PLL Input Clock Selection (FRC is input to the System PLL)
#pragma config_uba FPLLMULT = MUL_63    // System PLL Multiplier (PLL Multiply by 63)
#pragma config_uba FPLLODIV = DIV_2     // System PLL Output Clock Divider (2x Divider)
#pragma config_uba UPLLFSEL = FREQ_24MHZ// USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

// UBADEVCFG1
#pragma config_uba FNOSC = FRCDIV             // Oscillator Selection Bits (FRC)
#pragma config_uba DMTINTV = WIN_127_128// DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config_uba FSOSCEN = OFF        // Secondary Oscillator Enable (Disable SOSC)
#pragma config_uba IESO = OFF            // Internal/External Switch Over (Disabled)
#pragma config_uba POSCMOD = OFF        // Primary Oscillator Configuration (Primary osc disabled)
#pragma config_uba OSCIOFNC = OFF       // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config_uba FCKSM = CSECME       // Clock Switching and Monitor Selection (Clock Switch Enabled, FSCM Enabled)
#pragma config_uba WDTPS = PS2048       // Watchdog Timer Postscaler (1:2048)
#pragma config_uba WDTSPGM = STOP       // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config_uba WINDIS = NORMAL      // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config_uba FWDTEN = ON          // Watchdog Timer Enable (WDT Enabled)
#pragma config_uba FWDTWINSZ = WINSZ_75 // Watchdog Timer Window Size (Window size is 75%)
#pragma config_uba DMTCNT = DMT31       // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config_uba FDMTEN = ON          // Deadman Timer Enable (Deadman Timer is enabled)

// UBADEVCFG0
#pragma config_uba DEBUG = OFF          // Background Debugger Enable (Debugger is disabled)
#pragma config_uba JTAGEN = OFF          // JTAG Enable (JTAG Port Enabled)
#pragma config_uba ICESEL = ICS_PGx1    // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config_uba TRCEN = OFF          // Trace Enable (Trace features in the CPU are disabled)
#pragma config_uba BOOTISA = MIPS32     // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config_uba FECCCON = OFF_LOCKED    // Dynamic Flash ECC Configuration (Dynamic Flash ECC is enabled (ECCCON bits are locked))
#pragma config_uba FSLEEP = OFF         // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config_uba DBGPER = PG_ALL      // Debug Mode CPU Access Permission (Allow CPU access to all permission regions)
#pragma config_uba SMCLR = MCLR_NORM    // Soft Master Clear Enable bit (MCLR pin generates a normal system Reset)
#pragma config_uba SOSCGAIN = GAIN_2X   // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config_uba SOSCBOOST = ON       // Secondary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config_uba POSCGAIN = GAIN_2X   // Primary Oscillator Gain Control bits (2x gain setting)
#pragma config_uba POSCBOOST = ON       // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config_uba EJTAGBEN = NORMAL    // EJTAG Boot (Normal EJTAG functionality)

// UBADEVCP0
#pragma config_uba CP = OFF             // Code Protect (Protection Disabled)

#pragma config_uba TSEQ = 0xfffd
#pragma config_uba CSEQ = 0000e

#endif /* _CONFIGURE_H */

/* *****************************************************************************
 End of File
 */
