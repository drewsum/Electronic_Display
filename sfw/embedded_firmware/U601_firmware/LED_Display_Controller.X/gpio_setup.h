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

#ifndef _GPIO_SETUP_H    /* Guard against multiple inclusion */
#define _GPIO_SETUP_H

#include <xc.h>

#include "device_control.h"

#define TRIS_INPUT          1
#define TRIS_OUTPUT         0

#define LAT_HIGH            1
#define LAT_LOW             0

#define ODC_ENABLE          1
#define ODC_DISABLE         0

#define ANALOG_ENABLE       1
#define ANALOG_DISABLE      0


// initializes GPIO ports on microcontroller
void gpioInitialize (void);

// initializes port A GPIO pins
void portAGPIOInitialize (void);

// initializes port B GPIO pins
void portBGPIOInitialize (void);

// initializes port C GPIO pins
void portCGPIOInitialize (void);

// initializes port D GPIO pins
void portDGPIOInitialize (void);

// initializes port E GPIO pins
void portEGPIOInitialize (void);

// initializes port F GPIO pins
void portFGPIOInitialize (void);

// initializes port G GPIO pins
void portGGPIOInitialize (void);

// initializes port H GPIO pins
void portHGPIOInitialize (void);

// initializes port J GPIO pins
void portJGPIOInitialize (void);

// initializes port K GPIO pins
void portKGPIOInitialize (void);


#endif /* _GPIO_SETUP_H */

/* *****************************************************************************
 End of File
 */
