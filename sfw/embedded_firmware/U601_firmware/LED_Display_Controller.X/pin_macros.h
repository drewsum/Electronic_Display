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

#ifndef _PIN_MACROS_H    /* Guard against multiple inclusion */
#define _PIN_MACROS_H

#include <xc.h>

// PORTA Pin Macros
#define nLEVEL_SHIFT_EN_PIN         LATAbits.LATA0
#define nFLASH_WP7_PIN              LATAbits.LATA2
#define nFLASH_WP8_PIN              LATAbits.LATA3
#define nFLASH_WP1_PIN              LATAbits.LATA6
#define nFLASH_WP2_PIN              LATAbits.LATA7
#define nFLASH_WP3_PIN              LATAbits.LATA9
#define nFLASH_WP4_PIN              LATAbits.LATA10
#define nFLASH_WP5_PIN              LATAbits.LATA14
#define nFLASH_WP6_PIN              LATAbits.LATA15

// PORTB Pin Macros
#define nFLASH_CE1_PIN              LATBbits.LATB2
#define nFLASH_CE2_PIN              LATBbits.LATB3
#define nFLASH_CE3_PIN              LATBbits.LATB4
#define nFLASH_CE4_PIN              LATBbits.LATB5
#define nFLASH_CE5_PIN              LATBbits.LATB6
#define nFLASH_CE6_PIN              LATBbits.LATB7
#define nFLASH_CE7_PIN              LATBbits.LATB10
#define nFLASH_CE8_PIN              LATBbits.LATB11
#define nFLASH_HOLD_PIN             LATBbits.LATB12
#define FLASH_SCK_PIN               LATBbits.LATB14

// PORTC Pin Macros
#define FLASH_MOSI_PIN              LATCbits.LATC13
#define FLASH_MISO_PIN              PORTCbits.RC14

// PORTE Pin Macros
#define WIFI_CHPD_PIN               LATEbits.LATE8
#define nWIFI_RESET_PIN             LATEbits.LATE9

// PORTF Pin Macros



#endif /* _PIN_MACROS_H */

/* *****************************************************************************
 End of File
 */
