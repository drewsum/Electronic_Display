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

#ifndef _PANEL_PIN_INIT_H    /* Guard against multiple inclusion */
#define _PANEL_PIN_INIT_H

#include "app.h"

// Red output bus TRIS setting macros
#define red0TRIS    TRISAbits.TRISA0
#define red1TRIS    TRISAbits.TRISA1
#define red2TRIS    TRISAbits.TRISA2
#define red3TRIS    TRISAbits.TRISA3
#define red4TRIS    TRISAbits.TRISA4
#define red5TRIS    TRISAbits.TRISA5
#define red6TRIS    TRISAbits.TRISA6
#define red7TRIS    TRISAbits.TRISA7

// Green output bus TRIS setting macros
#define green0TRIS    TRISBbits.TRISB0
#define green1TRIS    TRISBbits.TRISB1
#define green2TRIS    TRISBbits.TRISB2
#define green3TRIS    TRISBbits.TRISB3
#define green4TRIS    TRISBbits.TRISB4
#define green5TRIS    TRISBbits.TRISB5
#define green6TRIS    TRISBbits.TRISB6
#define green7TRIS    TRISBbits.TRISB7

// Blue output bus TRIS setting macros
#define blue0TRIS    TRISBbits.TRISB8
#define blue1TRIS    TRISBbits.TRISB9
#define blue2TRIS    TRISBbits.TRISB10
#define blue3TRIS    TRISBbits.TRISB11
#define blue4TRIS    TRISBbits.TRISB12
#define blue5TRIS    TRISBbits.TRISB13
#define blue6TRIS    TRISBbits.TRISB14
#define blue7TRIS    TRISBbits.TRISB15

// Row output bus TRIS setting macros
#define rowETRIS    TRISDbits.TRISD9
#define rowDTRIS    TRISDbits.TRISD10
#define rowCTRIS    TRISDbits.TRISD11
#define rowBTRIS    TRISDbits.TRISD12
#define rowATRIS    TRISDbits.TRISD13

// Panel control line TRIS setting macros
#define panelLATTRIS    TRISAbits.TRISA14
#define panelCLKTRIS    TRISFbits.TRISF4
#define panelnOETRIS    TRISFbits.TRISF5

// Panel control line pin macros
#define panelLAT    LATAbits.LATA14
#define panelCLK    LATFbits.LATF4
#define panelnOE    LATFbits.LATF5


// Set RGB bus state functions
void setPanelRedBus(uint8_t);
void setPanelGreenBus(uint8_t);
void setPanelBlueBus(uint8_t);

// Set ROW bus state functions
void setPanelRowBus(uint8_t);

// panel signal tris init function
void panelPinInit(void);



#endif /* _PANEL_PIN_INIT_H */

/* *****************************************************************************
 End of File
 */
