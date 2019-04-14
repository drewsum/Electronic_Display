
#include <xc.h>

#include <stdio.h>

#include "pin_macros.h"
#include "panel_control.h"
#include "external_bus_interface.h"
#include "32mz_interrupt_control.h"
#include "device_control.h"

#include "terminal_control.h"

// This pragma tells the linker to allow access of EBI memory space
#pragma region name = "EBI_SRAM" origin = 0xC0000000 size = 262144

// This is tricking the compiler into placing an array in EBI SRAM
extern uint8_t ebi_sram_array[262144] __attribute__((region("EBI_SRAM")));

// Optimizing writing to pins
#define PANEL_CLK_PIN_HIGH()    LATJSET = 0x01
#define PANEL_CLK_PIN_LOW()     LATJCLR = 0x01
#define PANEL_LAT_PIN_HIGH()    LATJSET = 0x02
#define PANEL_LAT_PIN_LOW()     LATJCLR = 0x02
#define nPANEL_OE_PIN_HIGH()    LATJSET = 0x04
#define nPANEL_OE_PIN_LOW()     LATJCLR = 0x04

// Function to handle all multiplexing for panel
void panelMultiplexingHandler(void) {
    
    // Stop on time timer and reset to 0
    // T5CONbits.ON = 0;
    T5CONCLR = 0b1000000000000000;
    // TMR5 = 0;
    
    // Disable output
    nPANEL_OE_PIN_HIGH();
    
    // Set latch low
    PANEL_LAT_PIN_LOW();

    // Set clock low
    PANEL_CLK_PIN_LOW();
    
    // update row bus signals
    LATDCLR = 0xFA00;
    LATDSET = (current_row << 11);
    
    // uint32_t current_row_PWM_frame_index = 960 * current_row + 30720 * current_PWM_frame;
    uint32_t current_row_PWM_frame_index_Red = 960 * current_row + current_PWM_frame_index;
    uint32_t current_row_PWM_frame_index_Green = current_row_PWM_frame_index_Red + 1;
    uint32_t current_row_PWM_frame_index_Blue = current_row_PWM_frame_index_Red + 2;
    
    // Grab data for first shift clock cycle
    uint32_t redData = panel_data_buffer[current_shift_clock_index + current_row_PWM_frame_index_Red];
    uint32_t greenData = panel_data_buffer[current_shift_clock_index + current_row_PWM_frame_index_Green];
    uint32_t blueData = panel_data_buffer[current_shift_clock_index + current_row_PWM_frame_index_Blue];
    
    // loop through 320 shift clock cycles
    for (current_shift_clock_index = 3; current_shift_clock_index < 960; current_shift_clock_index += 3) {
        
        // Present previously gathered data to panels
        // Set red data bus
        LATDCLR = 0x00FF;
        LATDSET = redData;
        // Set green data bus
        LATJCLR = 0x1FE0;
        LATJSET = (greenData << 5);
        // Set blue data bus
        LATHCLR = 0xFF00;
        LATHSET = (blueData << 8);
        
        // Clock data into panel
        PANEL_CLK_PIN_HIGH();
        
        // DO NOT REMOVE THIS
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        
        // Grab data for next clock cycle
        redData = panel_data_buffer[current_shift_clock_index + current_row_PWM_frame_index_Red];
        greenData = panel_data_buffer[current_shift_clock_index + current_row_PWM_frame_index_Green];
        blueData = panel_data_buffer[current_shift_clock_index + current_row_PWM_frame_index_Blue];
        
        // Set clock low
        PANEL_CLK_PIN_LOW();
        
    }
    
    // Present data for last shift clock cycle to panels
    LATDCLR = 0x00FF;
    LATDSET = redData;
    // Set green data bus
    LATJCLR = 0x1FE0;
    LATJSET = (greenData << 5);
    // Set blue data bus
    LATHCLR = 0xFF00;
    LATHSET = (blueData << 8);
    
    // Clock in last column of data
    PANEL_CLK_PIN_HIGH();
    
    softwareDelay(6);
    
    // Release Clock
    PANEL_CLK_PIN_LOW();
    
    // Latch shifted data into shift registers
    PANEL_LAT_PIN_HIGH();
    
    // Enable pixel output
    nPANEL_OE_PIN_LOW();
    
    // Restart on time timer
    // T5CONbits.ON = 1;
    T5CONSET = 0b1000000000000000;
    
    // Next function call, update the next row
    current_row++;
    
    // Reset current_row counter
    if (current_row == 32) {
    
        current_row = 0;
        current_PWM_frame_index += 30720;
        
    }
    
    // Reset current_PWM_frame counter
    if (current_PWM_frame_index == PANEL_DATA_PWM_FRAMES * 30720) {
    
        current_PWM_frame_index = 0;
        
    }
    
}

inline void setPanelRGBBus(uint8_t inputRedByte, uint8_t inputGreenByte, uint8_t inputBlueByte) {
 
    // Set red data bus
    LATDCLR = 0x00FF;
    LATDSET = inputRedByte;
    
    // Set green data bus
    LATJCLR = 0x1FE0;
    LATJSET = (inputGreenByte << 5);
    
    // Set blue data bus
    LATHCLR = 0xFF00;
    LATHSET = (inputBlueByte << 8);
    
}

// Set ROW bus state functions
inline void setPanelRowBus(uint8_t inputByte) {

    // ROW bus is defined as RD11:15
    LATDCLR = 0xFA00;
    LATDSET = (inputByte << 11);
    
}

// This function initializes Timer5 for panel multiplexing
void panelMultiplexingTimerInitialize(void) {
 
    // Disable Timer5 interrupt
    disableInterrupt(Timer5);
    setInterruptPriority(Timer5, 6);
    setInterruptSubpriority(Timer5, 3);
    clearInterruptFlag(Timer5);
    
    // Stop timer 5
    T5CONbits.ON = 0;
    
    // Stop timer 5 in idle
    T5CONbits.SIDL = 1;
    
    // Disable gated time accumulation
    T5CONbits.TGATE = 0;
    
    // Set timer 5 prescalar to 1
    T5CONbits.TCKPS = 0b000;
    
    // Set timer clock input as PBCLK3
    T5CONbits.TCS = 0;
    
    // Clear timer 5
    TMR5 = 0x0000;
    
    // Set timer 5 period match to 250
    PR5 = MUXING_TIMER_PERIOD;
    
    // Start timer 5
    // T5CONbits.ON = 1;
    
    // Enable timer5 interrupt
    enableInterrupt(Timer5);
    
}

// Function for multiplexing timer ISR
void __ISR(_TIMER_5_VECTOR, IPL6SRS) panelMultiplexingTimerISR(void) {
    
    // Do multiplexing tasks
    panelMultiplexingHandler();
    
    clearInterruptFlag(Timer5);
    
}

// Start muxing timer function
inline void panelMultiplexingTimerStart(void) {
    
    T5CONbits.ON = 1;
    
}

// Stop muxing timer function
inline void panelMultiplexingTimerStop(void) {
    
    T5CONbits.ON = 0;
    
}

// Clear muxing timer function
inline void panelMultiplexingTimerClear(void) {
    
    TMR5 = 0;
    
}


// This function stops multiplexing and clears all control signals
void panelMultiplexingSuspend(void) {
    
    // Stop muxing timer
    T5CONbits.ON = 0;
    
    // Clear muxing timer
    TMR5 = 0;
    
    // Clear all control signals
    setPanelRGBBus(0, 0, 0);
    setPanelRowBus(0);
    
    // Clear output enable
    nPANEL_OE_PIN = 1;
    
}

// This function prints the contents of the internal RAM buffer holding frame data
void panelDataBufferPrint(void) {

    // print title of data table
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, UNDERSCORE);
    printf("Contents of first kB of Internal Static Random Access Memory Buffer holding Display Data:\n\r");
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    Starting    Lower Nibble\n\r");
    printf("    Address:    0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F\n\r");
    
    // Access address
    uint32_t loop_address;
    
    // wait for it
    for (loop_address = 0 ; loop_address < PANEL_DATA_ARRAY_SIZE / 256; loop_address += 16) {
        
        if (loop_address % 32 == 0) {
         
            terminalTextAttributes(GREEN, BLACK, NORMAL);
            
        }
        
        else {
         
            terminalTextAttributes(GREEN, BLACK, REVERSE);
            
        }
        
        printf("    0x%08X: 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\n\r", loop_address,
               panel_data_buffer[loop_address + 0],
               panel_data_buffer[loop_address + 1], 
               panel_data_buffer[loop_address + 2], 
               panel_data_buffer[loop_address + 3], 
               panel_data_buffer[loop_address + 4], 
               panel_data_buffer[loop_address + 5], 
               panel_data_buffer[loop_address + 6], 
               panel_data_buffer[loop_address + 7], 
               panel_data_buffer[loop_address + 8], 
               panel_data_buffer[loop_address + 9], 
               panel_data_buffer[loop_address + 0xA], 
               panel_data_buffer[loop_address + 0xB], 
               panel_data_buffer[loop_address + 0xC], 
               panel_data_buffer[loop_address + 0xD], 
               panel_data_buffer[loop_address + 0xE], 
               panel_data_buffer[loop_address + 0xF]);
        
    }
    
    terminalTextAttributesReset();
    
    
}

// This function copies all data from the internal RAM buffer into EBI SRAM
void movePanelDataToEBISRAM(void) {
 
    uint32_t loop_address;
    for (loop_address = 0; loop_address < PANEL_DATA_ARRAY_SIZE; loop_address++) {
     
        ebi_sram_array[loop_address] = panel_data_buffer[loop_address];
        
    }
    
}

// This function copies panel data from EBI SRAM to the internal RAM buffer
void movePanelDataFromEBISRAM(void) {
 
    // Get muxing state
    uint8_t muxing_state = T5CONbits.ON;
    
    // Stop multiplexing
    panelMultiplexingSuspend();
    
    uint32_t loop_address;
    for (loop_address = 0; loop_address < PANEL_DATA_ARRAY_SIZE; loop_address++) {
     
        panel_data_buffer[loop_address] = ebi_sram_array[loop_address];
        
    }
    
    if (muxing_state) panelMultiplexingTimerStart();
    
}

// This function initializes output compare 3 for dimming the display
void panelPWMInitialize(void) {
 
     // Set up Timer 2
    /////////////////
    // Stop timer 2
    T2CONbits.ON = 0;
    
    // Stop timer 2 in idle
    T2CONbits.SIDL = 1;
    
    // Disable gated time accumulation
    T2CONbits.TGATE = 0;
    
    // Set timer 2 prescalar to 1
    T2CONbits.TCKPS = 0b000;
    
    // Set timer clock input as PBCLK3
    // PBCLK3 is 15.75 MHz
    T2CONbits.TCS = 0;
    
    // Clear timer 2
    TMR2 = 0x0000;
    
    // Set timer 2 period match to 100
    PR2 = 100;
    
    // Set up Output Compare 4
    ///////////////////////////////////
    
    // Disable Output Compare when CPU in idle mode
    OC4CONbits.SIDL = 0;
    
    // Select Timer 2 as source for OC4
    OC4CONbits.OCTSEL = 0;
    
    // Set OC4 to 16 bit mode
    OC4CONbits.OC32 = 0;
    
    // Set default output compare clocks to timers 2 and 3
    CFGCONbits.OCACLK = 0;
    
    // Set OC4 to PWM mode, Fault pins disabled
    OC4CONbits.OCM = 0b110;
    
    // Enable Output Compare peripheral
    OC4CONbits.ON = 1;
    
    // Set PWM duty cycle to 50% at boot
    OC4RS = PR2 >> 1;
    // OC4R = 0;
    
    // Start timer 2
    T2CONbits.ON = 1;
    
}

// This function sets panel brightness
// Pass an integer between 0 and 100
// Larger numbers correspond to a brighter display
void panelPWMSetBrightness(uint8_t set_brightness) {

    // Invert since OE pin is active low
    set_brightness = 100 - set_brightness;
    
    // Set duty cycle
    OC4RS = (set_brightness * PR2) / 100;
    
}