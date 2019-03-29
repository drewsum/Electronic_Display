
#include <xc.h>
#include <proc/p32mz2048efh144.h>

#include "gpio_setup.h"

// initializes GPIO ports on microcontroller
void gpioInitialize (void){
    
    // Unlock peripheral pin select
    PPSUnlock();
    
    portAGPIOInitialize();
    portBGPIOInitialize();
    portCGPIOInitialize();
    portDGPIOInitialize();
    portEGPIOInitialize();
    portFGPIOInitialize();
    portGGPIOInitialize();
    portHGPIOInitialize();
    portJGPIOInitialize();
    portKGPIOInitialize();
    
    // Lock PPS
    PPSLock();
    
}

// initializes port A GPIO pins
void portAGPIOInitialize (void){
    
    // Setup RA0
    TRISAbits.TRISA0    = TRIS_OUTPUT;
    LATAbits.LATA0      = LAT_HIGH;
    ODCAbits.ODCA0      = ODC_ENABLE;
    ANSELAbits.ANSA0    = ANALOG_DISABLE;
    
    // Setup RA1
    TRISAbits.TRISA1    = TRIS_OUTPUT;
    LATAbits.LATA1      = LAT_LOW;
    ODCAbits.ODCA1      = ODC_DISABLE;
    
    // Setup RA2
    TRISAbits.TRISA2    = TRIS_OUTPUT;
    LATAbits.LATA2      = LAT_HIGH;
    ODCAbits.ODCA2      = ODC_DISABLE;
    
    // Setup RA3
    TRISAbits.TRISA3    = TRIS_OUTPUT;
    LATAbits.LATA3      = LAT_HIGH;
    ODCAbits.ODCA3      = ODC_DISABLE;
    
    // Setup RA4
    TRISAbits.TRISA4    = TRIS_OUTPUT;
    LATAbits.LATA4      = LAT_LOW;
    ODCAbits.ODCA4      = ODC_DISABLE;
    
    // Setup RA5
    TRISAbits.TRISA5    = TRIS_OUTPUT;
    LATAbits.LATA5      = LAT_LOW;
    ODCAbits.ODCA5      = ODC_DISABLE;
    ANSELAbits.ANSA5    = ANALOG_DISABLE;
    
    // Setup RA6
    TRISAbits.TRISA6    = TRIS_OUTPUT;
    LATAbits.LATA6      = LAT_HIGH;
    ODCAbits.ODCA6      = ODC_DISABLE;
    
    // Setup RA7
    TRISAbits.TRISA7    = TRIS_OUTPUT;
    LATAbits.LATA7      = LAT_HIGH;
    ODCAbits.ODCA7      = ODC_DISABLE;
    
    // Setup RA9
    TRISAbits.TRISA9    = TRIS_OUTPUT;
    LATAbits.LATA9      = LAT_HIGH;
    ODCAbits.ODCA9      = ODC_DISABLE;
    ANSELAbits.ANSA9    = ANALOG_DISABLE;
    
    // Setup RA10
    TRISAbits.TRISA10   = TRIS_OUTPUT;
    LATAbits.LATA10     = LAT_HIGH;
    ODCAbits.ODCA10     = ODC_DISABLE;
    ANSELAbits.ANSA10   = ANALOG_DISABLE;
    
    // Setup RA14
    TRISAbits.TRISA14   = TRIS_OUTPUT;
    LATAbits.LATA14     = LAT_HIGH;
    ODCAbits.ODCA14     = ODC_DISABLE;
    RPA14Rbits.RPA14R   = 0b0000;           // Disconnected from peripherals
    
    // Setup RA15
    TRISAbits.TRISA15   = TRIS_OUTPUT;
    LATAbits.LATA15     = LAT_HIGH;
    ODCAbits.ODCA15     = ODC_DISABLE;
    RPA15Rbits.RPA15R   = 0b0000;           // Disconnected from peripherals
}

// initializes port B GPIO pins
void portBGPIOInitialize (void){
    
    // Setup RB0
    TRISBbits.TRISB0    = TRIS_OUTPUT;
    LATBbits.LATB0      = LAT_LOW;
    ODCBbits.ODCB0      = ODC_DISABLE;
    ANSELBbits.ANSB0    = ANALOG_DISABLE;
    RPB0Rbits.RPB0R     = 0b0000;           // Disconnected from peripherals
    
    // Setup RB1
    TRISBbits.TRISB1    = TRIS_INPUT;
    LATBbits.LATB1      = LAT_LOW;
    ODCBbits.ODCB1      = ODC_DISABLE;
    ANSELBbits.ANSB1    = ANALOG_DISABLE;
    RPB1Rbits.RPB1R     = 0b0000;           // Disconnected from peripherals
    
    // Setup RB2
    TRISBbits.TRISB2    = TRIS_OUTPUT;
    LATBbits.LATB2      = LAT_HIGH;
    ODCBbits.ODCB2      = ODC_DISABLE;
    ANSELBbits.ANSB2    = ANALOG_DISABLE;
    RPB2Rbits.RPB2R     = 0b0000;           // Disconnected from peripherals
    
    // Setup RB3
    TRISBbits.TRISB3    = TRIS_OUTPUT;
    LATBbits.LATB3      = LAT_HIGH;
    ODCBbits.ODCB3      = ODC_DISABLE;
    ANSELBbits.ANSB3    = ANALOG_DISABLE;
    RPB3Rbits.RPB3R     = 0b0000;           // Disconnected from peripherals
    
    // Setup RB4
    TRISBbits.TRISB4    = TRIS_OUTPUT;
    LATBbits.LATB4      = LAT_HIGH;
    ODCBbits.ODCB4      = ODC_DISABLE;
    ANSELBbits.ANSB4    = ANALOG_DISABLE;
    
    // Setup RB5
    TRISBbits.TRISB5    = TRIS_OUTPUT;
    LATBbits.LATB5      = LAT_HIGH;
    ODCBbits.ODCB5      = ODC_DISABLE;
    ANSELBbits.ANSB5    = ANALOG_DISABLE;
    RPB5Rbits.RPB5R     = 0b0000;           // Disconnected from peripherals
    
    // Setup RB6
    TRISBbits.TRISB6    = TRIS_OUTPUT;
    LATBbits.LATB6      = LAT_HIGH;
    ODCBbits.ODCB6      = ODC_DISABLE;
    ANSELBbits.ANSB6    = ANALOG_DISABLE;
    RPB6Rbits.RPB6R     = 0b0000;           // Disconnected from peripherals
    
    // Setup RB7
    TRISBbits.TRISB7    = TRIS_OUTPUT;
    LATBbits.LATB7      = LAT_HIGH;
    ODCBbits.ODCB7      = ODC_DISABLE;
    ANSELBbits.ANSB7    = ANALOG_DISABLE;
    RPB7Rbits.RPB7R     = 0b0000;           // Disconnected from peripherals
    
    // Setup RB8
    TRISBbits.TRISB8    = TRIS_OUTPUT;
    LATBbits.LATB8      = LAT_LOW;
    ODCBbits.ODCB8      = ODC_DISABLE;
    ANSELBbits.ANSB8    = ANALOG_DISABLE;
    RPB8Rbits.RPB8R     = 0b0000;           // Disconnected from peripherals
        
    // Setup RB9
    TRISBbits.TRISB9    = TRIS_OUTPUT;
    LATBbits.LATB9      = LAT_LOW;
    ODCBbits.ODCB9      = ODC_DISABLE;
    ANSELBbits.ANSB9    = ANALOG_DISABLE;
    RPB9Rbits.RPB9R     = 0b0000;           // Disconnected from peripherals
    
    // Setup RB10
    TRISBbits.TRISB10   = TRIS_OUTPUT;
    LATBbits.LATB10     = LAT_HIGH;
    ODCBbits.ODCB10     = ODC_DISABLE;
    ANSELBbits.ANSB10   = ANALOG_DISABLE;
    RPB10Rbits.RPB10R   = 0b0000;           // Disconnected from peripherals
    
    // Setup RB11
    TRISBbits.TRISB11   = TRIS_OUTPUT;
    LATBbits.LATB11     = LAT_HIGH;
    ODCBbits.ODCB11     = ODC_DISABLE;
    ANSELBbits.ANSB11   = ANALOG_DISABLE;
    
    // Setup RB12
    TRISBbits.TRISB12   = TRIS_OUTPUT;
    LATBbits.LATB12     = LAT_HIGH;
    ODCBbits.ODCB12     = ODC_DISABLE;
    ANSELBbits.ANSB12   = ANALOG_DISABLE;
    
    // Setup RB13
    TRISBbits.TRISB13   = TRIS_OUTPUT;
    LATBbits.LATB13     = LAT_LOW;
    ODCBbits.ODCB13     = ODC_DISABLE;
    ANSELBbits.ANSB13   = ANALOG_DISABLE;
    
    // Setup RB14
    TRISBbits.TRISB14   = TRIS_OUTPUT;
    LATBbits.LATB14     = LAT_LOW;
    ODCBbits.ODCB14     = ODC_DISABLE;
    ANSELBbits.ANSB14   = ANALOG_DISABLE;
    RPB14Rbits.RPB14R   = 0b0000;           // Using this pin as SCK3
    
    // Setup RB15
    TRISBbits.TRISB15   = TRIS_OUTPUT;
    LATBbits.LATB15     = LAT_LOW;
    ODCBbits.ODCB15     = ODC_DISABLE;
    ANSELBbits.ANSB15   = ANALOG_DISABLE;
    RPB15Rbits.RPB15R   = 0b0000;           // Disconnected from peripherals
        
}

// initializes port C GPIO pins
void portCGPIOInitialize (void){
    
    // Setup RC1
    TRISCbits.TRISC1    = TRIS_OUTPUT;
    LATCbits.LATC1      = LAT_LOW;
    ODCCbits.ODCC1      = ODC_DISABLE;
    ANSELCbits.ANSC1    = ANALOG_DISABLE;
    RPC1Rbits.RPC1R     = 0b0000;           // Disconnected from peripherals
    
    // Setup RC2
    TRISCbits.TRISC2    = TRIS_OUTPUT;
    LATCbits.LATC2      = LAT_LOW;
    ODCCbits.ODCC2      = ODC_DISABLE;
    ANSELCbits.ANSC2    = ANALOG_DISABLE;
    RPC2Rbits.RPC2R     = 0b0000;           // Disconnected from peripherals
    
    // Setup RC3
    TRISCbits.TRISC3    = TRIS_OUTPUT;
    LATCbits.LATC3      = LAT_HIGH;
    ODCCbits.ODCC3      = ODC_DISABLE;
    ANSELCbits.ANSC3    = ANALOG_DISABLE;
    RPC3Rbits.RPC3R     = 0b0000;           // Disconnected from peripherals
    
    // Setup RC4
    TRISCbits.TRISC4    = TRIS_OUTPUT;
    LATCbits.LATC4      = LAT_HIGH;
    ODCCbits.ODCC4      = ODC_DISABLE;
    ANSELCbits.ANSC4    = ANALOG_DISABLE;
    RPC4Rbits.RPC4R     = 0b0000;           // Disconnected from peripherals
    
    // Setup RC12
    TRISCbits.TRISC12   = TRIS_OUTPUT;
    LATCbits.LATC12     = LAT_LOW;
    ODCCbits.ODCC12     = ODC_DISABLE;
    
    // Setup RC13
    TRISCbits.TRISC13   = TRIS_OUTPUT;
    LATCbits.LATC13     = LAT_LOW;
    ODCCbits.ODCC13     = ODC_DISABLE;
    RPC13Rbits.RPC13R   = 0b0111;           // Set to SDO3 peripheral pin
    
    // Setup RC14
    TRISCbits.TRISC14   = TRIS_INPUT;
    LATCbits.LATC14     = LAT_LOW;
    ODCCbits.ODCC14     = ODC_DISABLE;
    SDI3Rbits.SDI3R     = 0b0111;          // Set to SDI3 peripheral pin
    
    // Setup RC15
    TRISCbits.TRISC15   = TRIS_OUTPUT;
    LATCbits.LATC15     = LAT_LOW;
    ODCCbits.ODCC15     = ODC_DISABLE;
    
}

// initializes port D GPIO pins
void portDGPIOInitialize (void){
    
    // Setup RD0
    TRISDbits.TRISD0    = TRIS_OUTPUT;
    LATDbits.LATD0      = LAT_LOW;
    ODCDbits.ODCD0      = ODC_DISABLE;
    RPD0Rbits.RPD0R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RD1
    TRISDbits.TRISD1    = TRIS_OUTPUT;
    LATDbits.LATD1      = LAT_LOW;
    ODCDbits.ODCD1      = ODC_DISABLE;
    RPD1Rbits.RPD1R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RD2
    TRISDbits.TRISD2    = TRIS_OUTPUT;
    LATDbits.LATD2      = LAT_LOW;
    ODCDbits.ODCD2      = ODC_DISABLE;
    RPD2Rbits.RPD2R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RD3
    TRISDbits.TRISD3    = TRIS_OUTPUT;
    LATDbits.LATD3      = LAT_LOW;
    ODCDbits.ODCD3      = ODC_DISABLE;
    RPD3Rbits.RPD3R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RD4
    TRISDbits.TRISD4    = TRIS_OUTPUT;
    LATDbits.LATD4      = LAT_LOW;
    ODCDbits.ODCD4      = ODC_DISABLE;
    RPD4Rbits.RPD4R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RD5
    TRISDbits.TRISD5    = TRIS_OUTPUT;
    LATDbits.LATD5      = LAT_LOW;
    ODCDbits.ODCD5      = ODC_DISABLE;
    RPD5Rbits.RPD5R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RD6
    TRISDbits.TRISD6    = TRIS_OUTPUT;
    LATDbits.LATD6      = LAT_LOW;
    ODCDbits.ODCD6      = ODC_DISABLE;
    RPD6Rbits.RPD6R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RD7
    TRISDbits.TRISD7    = TRIS_OUTPUT;
    LATDbits.LATD7      = LAT_LOW;
    ODCDbits.ODCD7      = ODC_DISABLE;
    RPD7Rbits.RPD7R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RD9
    TRISDbits.TRISD9    = TRIS_OUTPUT;
    LATDbits.LATD9      = LAT_LOW;
    ODCDbits.ODCD9      = ODC_DISABLE;
    RPD9Rbits.RPD9R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RD10
    TRISDbits.TRISD10   = TRIS_OUTPUT;
    LATDbits.LATD10     = LAT_HIGH;
    ODCDbits.ODCD10     = ODC_DISABLE;
    RPD10R              = 0b0001;               // Set RD10 as UART 3 TX
    
    // Setup RD11
    TRISDbits.TRISD11   = TRIS_OUTPUT;
    LATDbits.LATD11     = LAT_LOW;
    ODCDbits.ODCD11     = ODC_DISABLE;
    RPD11Rbits.RPD11R   = 0b0000;               // Disconnected from peripherals
    
    // Setup RD12
    TRISDbits.TRISD12   = TRIS_OUTPUT;
    LATDbits.LATD12     = LAT_LOW;
    ODCDbits.ODCD12     = ODC_DISABLE;
    RPD12Rbits.RPD12R   = 0b0000;               // Disconnected from peripherals
    
    // Setup RD13
    TRISDbits.TRISD13   = TRIS_OUTPUT;
    LATDbits.LATD13     = LAT_LOW;
    ODCDbits.ODCD13     = ODC_DISABLE;
    
    // Setup RD14
    TRISDbits.TRISD14   = TRIS_OUTPUT;
    LATDbits.LATD14     = LAT_LOW;
    ODCDbits.ODCD14     = ODC_DISABLE;
    ANSELDbits.ANSD14   = ANALOG_DISABLE;
    RPD14Rbits.RPD14R   = 0b0000;               // Disconnected from peripherals
    
    // Setup RD15
    TRISDbits.TRISD15   = TRIS_OUTPUT;
    LATDbits.LATD15     = LAT_LOW;
    ODCDbits.ODCD15     = ODC_DISABLE;
    ANSELDbits.ANSD15   = ANALOG_DISABLE;
    RPD15Rbits.RPD15R   = 0b0000;               // Disconnected from peripherals
        
}

// initializes port E GPIO pins
void portEGPIOInitialize (void){
    
    // Setup RE0
    TRISEbits.TRISE0    = TRIS_INPUT;
    LATEbits.LATE0      = LAT_LOW;
    ODCEbits.ODCE0      = ODC_DISABLE;
    
    // Setup RE1
    TRISEbits.TRISE1    = TRIS_INPUT;
    LATEbits.LATE1      = LAT_LOW;
    ODCEbits.ODCE1      = ODC_DISABLE;
    
    // Setup RE2
    TRISEbits.TRISE2    = TRIS_INPUT;
    LATEbits.LATE2      = LAT_LOW;
    ODCEbits.ODCE2      = ODC_DISABLE;
    
    // Setup RE3
    TRISEbits.TRISE3    = TRIS_INPUT;
    LATEbits.LATE3      = LAT_LOW;
    ODCEbits.ODCE3      = ODC_DISABLE;
    RPE3Rbits.RPE3R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RE4
    TRISEbits.TRISE4    = TRIS_INPUT;
    LATEbits.LATE4      = LAT_LOW;
    ODCEbits.ODCE4      = ODC_DISABLE;
    ANSELEbits.ANSE4    = ANALOG_DISABLE;
    
    // Setup RE5
    TRISEbits.TRISE5    = TRIS_INPUT;
    LATEbits.LATE5      = LAT_LOW;
    ODCEbits.ODCE5      = ODC_DISABLE;
    ANSELEbits.ANSE5    = ANALOG_DISABLE;
    RPE5Rbits.RPE5R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RE6
    TRISEbits.TRISE6    = TRIS_INPUT;
    LATEbits.LATE6      = LAT_LOW;
    ODCEbits.ODCE6      = ODC_DISABLE;
    ANSELEbits.ANSE6    = ANALOG_DISABLE;
    
    // Setup RE7
    TRISEbits.TRISE7    = TRIS_INPUT;
    LATEbits.LATE7      = LAT_LOW;
    ODCEbits.ODCE7      = ODC_DISABLE;
    ANSELEbits.ANSE7    = ANALOG_DISABLE;
    
    // Setup RE8
    TRISEbits.TRISE8    = TRIS_OUTPUT;
    LATEbits.LATE8      = LAT_LOW;
    ODCEbits.ODCE8      = ODC_DISABLE;
    ANSELEbits.ANSE8    = ANALOG_DISABLE;
    RPE8Rbits.RPE8R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RE9
    TRISEbits.TRISE9    = TRIS_OUTPUT;
    LATEbits.LATE9      = LAT_HIGH;
    ODCEbits.ODCE9      = ODC_DISABLE;
    ANSELEbits.ANSE9    = ANALOG_DISABLE;
    RPE9Rbits.RPE9R     = 0b0000;               // Disconnected from peripherals
    
}

// initializes port F GPIO pins
void portFGPIOInitialize (void){
 
    // Setup RF0
    TRISFbits.TRISF0    = TRIS_INPUT;
    LATFbits.LATF0      = LAT_LOW;
    ODCFbits.ODCF0      = ODC_DISABLE;
    U3RXR               = 0b0100;               // Set RF0 as UART 3 RX
    
    // Setup RF1
    TRISFbits.TRISF1    = TRIS_INPUT;
    LATFbits.LATF1      = LAT_LOW;
    ODCFbits.ODCF1      = ODC_DISABLE;
    // I DONT THINK THIS IS RIGHT SO IM COMMENTING IT OUT - Caroline 
//    CNNEFbits.CNNEF1    = 1;                    // Enable falling edge change notification
    
    // Setup RF2
    TRISFbits.TRISF2    = TRIS_OUTPUT;
    LATFbits.LATF2      = LAT_LOW;
    ODCFbits.ODCF2      = ODC_DISABLE;
    RPF2Rbits.RPF2R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RF3
    TRISFbits.TRISF3    = TRIS_INPUT;
    LATFbits.LATF3      = LAT_LOW;
    ODCFbits.ODCF3      = ODC_DISABLE;
    RPF3Rbits.RPF3R     = 0b0000;               // Disconnected from peripherals
    CNNEFbits.CNNEF3    = 1;                    // Enable falling edge change notification
    
    // Setup RF4
    TRISFbits.TRISF4    = TRIS_OUTPUT;
    LATFbits.LATF4      = LAT_LOW;
    ODCFbits.ODCF4      = ODC_DISABLE;
    RPF4Rbits.RPF4R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RF5
    TRISFbits.TRISF5    = TRIS_OUTPUT;
    LATFbits.LATF5      = LAT_LOW;
    ODCFbits.ODCF5      = ODC_DISABLE;
    RPF5Rbits.RPF5R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RF8
    TRISFbits.TRISF8    = TRIS_INPUT;
    LATFbits.LATF8      = LAT_LOW;
    ODCFbits.ODCF8      = ODC_DISABLE;
    CNNEFbits.CNNEF8    = 1;                    // Enable falling edge change notification
    
    // Setup RF12
    TRISFbits.TRISF12   = TRIS_INPUT;
    LATFbits.LATF12     = LAT_HIGH;
    ODCFbits.ODCF12     = ODC_DISABLE;
    ANSELFbits.ANSF12   = ANALOG_DISABLE;
    CNNEFbits.CNNEF12   = 1;                    // Enable falling edge change notification
    
    // Setup RF13
    TRISFbits.TRISF13   = TRIS_OUTPUT;
    LATFbits.LATF13     = LAT_LOW;
    ODCFbits.ODCF13     = ODC_DISABLE;
    ANSELFbits.ANSF13   = ANALOG_DISABLE;
    RPF13Rbits.RPF13R   = 0b0000;               // Disconnected from peripherals
    
}

// initializes port G GPIO pins
void portGGPIOInitialize (void){
    
    // Setup RG0
    TRISGbits.TRISG0    = TRIS_OUTPUT;
    LATGbits.LATG0      = LAT_LOW;
    ODCGbits.ODCG0      = ODC_DISABLE;
    RPG0Rbits.RPG0R     = 0b1011;               // Routed OC4 to RPG0
    
    // Setup RG1
    TRISGbits.TRISG1    = TRIS_OUTPUT;
    LATGbits.LATG1      = LAT_LOW;
    ODCGbits.ODCG1      = ODC_DISABLE;
    RPG1Rbits.RPG1R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RG6
    TRISGbits.TRISG6    = TRIS_OUTPUT;
    LATGbits.LATG6      = LAT_LOW;
    ODCGbits.ODCG6      = ODC_DISABLE;
    ANSELGbits.ANSG6    = ANALOG_DISABLE;
    RPG6Rbits.RPG6R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RG7
    TRISGbits.TRISG7    = TRIS_OUTPUT;
    LATGbits.LATG7      = LAT_LOW;
    ODCGbits.ODCG7      = ODC_DISABLE;
    ANSELGbits.ANSG7    = ANALOG_DISABLE;
    RPG7Rbits.RPG7R     = 0b0001;               // Set RG7 to U1TX
    
    // Setup RG8
    TRISGbits.TRISG8    = TRIS_INPUT;
    LATGbits.LATG8      = LAT_LOW;
    ODCGbits.ODCG8      = ODC_DISABLE;
    ANSELGbits.ANSG8    = ANALOG_DISABLE;
    U1RXRbits.U1RXR     = 0b0001;               // RG8 to U1RX
    
    // Setup RG9
    TRISGbits.TRISG9    = TRIS_OUTPUT;
    LATGbits.LATG9      = LAT_LOW;
    ODCGbits.ODCG9      = ODC_DISABLE;
    ANSELGbits.ANSG9    = ANALOG_DISABLE;
    RPG9Rbits.RPG9R     = 0b0000;               // Disconnected from peripherals
    
    // Setup RG12
    TRISGbits.TRISG12   = TRIS_OUTPUT;
    LATGbits.LATG12     = LAT_LOW;
    ODCGbits.ODCG12     = ODC_DISABLE;
    
    // Setup RG13
    TRISGbits.TRISG13   = TRIS_OUTPUT;
    LATGbits.LATG13     = LAT_LOW;
    ODCGbits.ODCG13     = ODC_DISABLE;
    
    // Setup RG14
    TRISGbits.TRISG14   = TRIS_OUTPUT;
    LATGbits.LATG14     = LAT_LOW;
    ODCGbits.ODCG14     = ODC_DISABLE;
   
    // Setup RG15
    TRISGbits.TRISG15   = TRIS_OUTPUT;
    LATGbits.LATG15     = LAT_HIGH;
    ODCGbits.ODCG15     = ODC_ENABLE;
    
}

// initializes port H GPIO pins
void portHGPIOInitialize (void){
    
    // Setup RH0
    TRISHbits.TRISH0    = TRIS_INPUT;
    LATHbits.LATH0      = LAT_LOW;
    ODCHbits.ODCH0      = ODC_DISABLE;
    ANSELHbits.ANSH0    = ANALOG_ENABLE;
    
    // Setup RH1
    TRISHbits.TRISH1    = TRIS_INPUT;
    LATHbits.LATH1      = LAT_LOW;
    ODCHbits.ODCH1      = ODC_DISABLE;
    ANSELHbits.ANSH1    = ANALOG_ENABLE;
    
    // Setup RH2
    TRISHbits.TRISH2    = TRIS_OUTPUT;
    LATHbits.LATH2      = LAT_LOW;
    ODCHbits.ODCH2      = ODC_DISABLE;
    
    // Setup RH3
    TRISHbits.TRISH3    = TRIS_OUTPUT;
    LATHbits.LATH3      = LAT_LOW;
    ODCHbits.ODCH3      = ODC_DISABLE;
    
    // Setup RH4
    TRISHbits.TRISH4    = TRIS_INPUT;
    LATHbits.LATH4      = LAT_LOW;
    ODCHbits.ODCH4      = ODC_DISABLE;
    ANSELHbits.ANSH4    = ANALOG_ENABLE;
    
    // Setup RH5
    TRISHbits.TRISH5    = TRIS_INPUT;
    LATHbits.LATH5      = LAT_LOW;
    ODCHbits.ODCH5      = ODC_DISABLE;
    ANSELHbits.ANSH5    = ANALOG_ENABLE;
    
    // Setup RH6
    TRISHbits.TRISH6    = TRIS_INPUT;
    LATHbits.LATH6      = LAT_LOW;
    ODCHbits.ODCH6      = ODC_DISABLE;
    ANSELHbits.ANSH6    = ANALOG_ENABLE;
    
    // Setup RH7
    TRISHbits.TRISH7    = TRIS_OUTPUT;
    LATHbits.LATH7      = LAT_LOW;
    ODCHbits.ODCH7      = ODC_DISABLE;
    
    // Setup RH8
    TRISHbits.TRISH8    = TRIS_OUTPUT;
    LATHbits.LATH8      = LAT_LOW;
    ODCHbits.ODCH8      = ODC_DISABLE;
    
    // Setup RH9
    TRISHbits.TRISH9    = TRIS_OUTPUT;
    LATHbits.LATH9      = LAT_LOW;
    ODCHbits.ODCH9      = ODC_DISABLE;
    
    // Setup RH10
    TRISHbits.TRISH10   = TRIS_OUTPUT;
    LATHbits.LATH10     = LAT_LOW;
    ODCHbits.ODCH10     = ODC_DISABLE;
    
    // Setup RH11
    TRISHbits.TRISH11   = TRIS_OUTPUT;
    LATHbits.LATH11     = LAT_LOW;
    ODCHbits.ODCH11     = ODC_DISABLE;
    
    // Setup RH12
    TRISHbits.TRISH12   = TRIS_OUTPUT;
    LATHbits.LATH12     = LAT_LOW;
    ODCHbits.ODCH12     = ODC_DISABLE;
    
    // Setup RH13
    TRISHbits.TRISH13   = TRIS_OUTPUT;
    LATHbits.LATH13     = LAT_LOW;
    ODCHbits.ODCH13     = ODC_DISABLE;
    
    // Setup RH14
    TRISHbits.TRISH14   = TRIS_OUTPUT;
    LATHbits.LATH14     = LAT_LOW;
    ODCHbits.ODCH14     = ODC_DISABLE;
    
    // Setup RH15
    TRISHbits.TRISH15   = TRIS_OUTPUT;
    LATHbits.LATH15     = LAT_LOW;
    ODCHbits.ODCH15     = ODC_DISABLE;
    
}

// initializes port J GPIO pins
void portJGPIOInitialize (void){
    
    // Setup RJ0
    TRISJbits.TRISJ0    = TRIS_OUTPUT;
    LATJbits.LATJ0      = LAT_LOW;
    ODCJbits.ODCJ0      = ODC_DISABLE;
    
    // Setup RJ1
    TRISJbits.TRISJ1    = TRIS_OUTPUT;
    LATJbits.LATJ1      = LAT_LOW;
    ODCJbits.ODCJ1      = ODC_DISABLE;
    
    // Setup RJ2
    TRISJbits.TRISJ2    = TRIS_OUTPUT;
    LATJbits.LATJ2      = LAT_HIGH;
    ODCJbits.ODCJ2      = ODC_DISABLE;
    
    // Setup RJ3
    TRISJbits.TRISJ3    = TRIS_OUTPUT;
    LATJbits.LATJ3      = LAT_LOW;
    ODCJbits.ODCJ3      = ODC_DISABLE;
    
    // Setup RJ4
    TRISJbits.TRISJ4    = TRIS_OUTPUT;
    LATJbits.LATJ4      = LAT_LOW;
    ODCJbits.ODCJ4      = ODC_DISABLE;
    
    // Setup RJ5
    TRISJbits.TRISJ5    = TRIS_OUTPUT;
    LATJbits.LATJ5      = LAT_LOW;
    ODCJbits.ODCJ5      = ODC_DISABLE;
    
    // Setup RJ6
    TRISJbits.TRISJ6    = TRIS_OUTPUT;
    LATJbits.LATJ6      = LAT_LOW;
    ODCJbits.ODCJ6      = ODC_DISABLE;
    
    // Setup RJ7
    TRISJbits.TRISJ7    = TRIS_OUTPUT;
    LATJbits.LATJ7      = LAT_LOW;
    ODCJbits.ODCJ7      = ODC_DISABLE;
    
    // Setup RJ8
    TRISJbits.TRISJ8    = TRIS_OUTPUT;
    LATJbits.LATJ8      = LAT_LOW;
    ODCJbits.ODCJ8      = ODC_DISABLE;
    ANSELJbits.ANSJ8    = ANALOG_DISABLE;
    
    // Setup RJ9
    TRISJbits.TRISJ9    = TRIS_OUTPUT;
    LATJbits.LATJ9      = LAT_LOW;
    ODCJbits.ODCJ9      = ODC_DISABLE;
    ANSELJbits.ANSJ9    = ANALOG_DISABLE;
    
    // Setup RJ10
    TRISJbits.TRISJ10   = TRIS_OUTPUT;
    LATJbits.LATJ10     = LAT_LOW;
    ODCJbits.ODCJ10     = ODC_DISABLE;
    
    // Setup RJ11
    TRISJbits.TRISJ11   = TRIS_OUTPUT;
    LATJbits.LATJ11     = LAT_LOW;
    ODCJbits.ODCJ11     = ODC_DISABLE;
    ANSELJbits.ANSJ11   = ANALOG_DISABLE;
    
    // Setup RJ12
    TRISJbits.TRISJ12   = TRIS_OUTPUT;
    LATJbits.LATJ12     = LAT_LOW;
    ODCJbits.ODCJ12     = ODC_DISABLE;
    
    // Setup RJ13
    TRISJbits.TRISJ13   = TRIS_OUTPUT;
    LATJbits.LATJ13     = LAT_LOW;
    ODCJbits.ODCJ13     = ODC_DISABLE;
    
    // Setup RJ14
    TRISJbits.TRISJ14   = TRIS_OUTPUT;
    LATJbits.LATJ14     = LAT_LOW;
    ODCJbits.ODCJ14     = ODC_DISABLE;
    
    // Setup RJ15
    TRISJbits.TRISJ15   = TRIS_OUTPUT;
    LATJbits.LATJ15     = LAT_LOW;
    ODCJbits.ODCJ15     = ODC_DISABLE;
    
}

// initializes port K GPIO pins
void portKGPIOInitialize (void){
    
    // Setup RK0
    TRISKbits.TRISK0    = TRIS_OUTPUT;
    LATKbits.LATK0      = LAT_LOW;
    ODCKbits.ODCK0      = ODC_DISABLE;
    
    // Setup RK1
    TRISKbits.TRISK1    = TRIS_OUTPUT;
    LATKbits.LATK1      = LAT_LOW;
    ODCKbits.ODCK1      = ODC_DISABLE;
    
    // Setup RK2
    TRISKbits.TRISK2    = TRIS_OUTPUT;
    LATKbits.LATK2      = LAT_LOW;
    ODCKbits.ODCK2      = ODC_DISABLE;
    
    // Setup RK3
    TRISKbits.TRISK3    = TRIS_OUTPUT;
    LATKbits.LATK3      = LAT_LOW;
    ODCKbits.ODCK3      = ODC_DISABLE;
    
    // Setup RK4
    TRISKbits.TRISK4    = TRIS_INPUT;
    LATKbits.LATK4      = LAT_HIGH;
    ODCKbits.ODCK4      = ODC_DISABLE;
    CNNEKbits.CNNEK4    = 1;                    // Enable falling edge change notification
    
    // Setup RK5
    TRISKbits.TRISK5    = TRIS_INPUT;
    LATKbits.LATK5      = LAT_LOW;
    ODCKbits.ODCK5      = ODC_DISABLE;
    CNENKbits.CNIEK5    = 1;                    // Enable rising edge change notification
    
    // Setup RK6
    TRISKbits.TRISK6    = TRIS_INPUT;
    LATKbits.LATK6      = LAT_LOW;
    ODCKbits.ODCK6      = ODC_DISABLE;
    
    // Setup RK7
    TRISKbits.TRISK7    = TRIS_INPUT;
    LATKbits.LATK7      = LAT_LOW;
    ODCKbits.ODCK7      = ODC_DISABLE;
    CNNEKbits.CNNEK7    = 1;                    // Enable falling edge change notification
    
}