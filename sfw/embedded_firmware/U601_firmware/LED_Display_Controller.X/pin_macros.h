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

// These pin macros allow for easier manipulation of GPIO with matching
// signal names from the hardware schematic

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
#define POS12_PGOOD_PIN             PORTfbits.RF1
#define POS5_RUN_PIN                LATFbits.LATF2
#define POS5_PGOOD_PIN              PORTFbits.RF3
#define POS5P_PGOOD_PIN             PORTFbits.RF8
#define nPOS5P_THWN_PIN             PORTFbits.RF12
#define POS5P_RUN_PIN               LATFbits.LATF13

// PortG Pin Macros
#define PANEL_DIM_PWM_PIN           LATGbits.LATG0
#define EBI_ERROR_LED_PIN           LATGbits.LATG1
#define SPI_ERROR_LED_PIN           LATGbits.LATG6
#define HEARTBEAT_LED_PIN           LATGbits.LATG12
#define WIFI_ERROR_LED_PIN          LATGbits.LATG13
#define USB_ERROR_LED_PIN           LATGbits.LATG14
#define nACTIVE_LED_PIN             LATGbits.LATG15

// Port H Pin Macros
#define OTHER_ERROR_LED_PIN         LATHbits.LATH3

// Port J Pin Macros
#define PANEL_CLK_PIN               LATJbits.LATJ0
#define PANEL_LAT_PIN               LATJbits.LATJ1
#define nPANEL_OE_PIN               LATJbits.LATJ2

// Port K Pin Macros
#define nDISPLAY_ENABLE_PIN         PORTKbits.RK4
#define ENCODER_STEP_PIN            PORTKbits.RK5
#define ENCODER_DIR_PIN             PORTKbits.RK6
#define POS3P3_PGOOD_PIN            PORTKbits.RK7

#endif /* _PIN_MACROS_H */

/* *****************************************************************************
 End of File
 */
