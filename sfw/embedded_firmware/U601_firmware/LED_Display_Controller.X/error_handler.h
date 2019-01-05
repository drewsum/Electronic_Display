/* ************************************************************************** */
/** Error Handler

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    error_handler.h

  @Summary
 Provides functions and variables/structures for recording and reporting errors
 during runtime

 */
/* ************************************************************************** */

#ifndef _ERROR_HANDLER_H    /* Guard against multiple inclusion */
#define _ERROR_HANDLER_H

#include <xc.h>

// Error handler structure - can hold up to 32 flags (I think, we'll see if we run over)
// Follow the convention in XC32 user's guide section 8.6.2
// Each flag indicates if the described error has occurred
// This is used for controlling status LEDs and USB debugging
// Access a flag like any C structure
struct {
    
    unsigned configuration_error_flsg                   : 1;    // error in device setup
    unsigned EBI_error_flag                             : 1;    // error with extended bus interface (external SRAM)
    unsigned SPI_error_flag                             : 1;    // Error with external flash SPI
    unsigned WIFI_error_flag                            : 1;    // Error with WIFI module
    unsigned USB_error_flag                             : 1;    // Error with USB debugging interface
    unsigned other_error_flag                           : 1;    // Other error event
    unsigned POS5P_thermal_warning_error_flag           : 1;    // Power board thermal warning event flag
    unsigned POS3P3_regulation_error_flag               : 1;    // +3.3V power supply regulation error
    unsigned POS5_regulation_error_flag                 : 1;    // +5V power supply regulation error
    unsigned POS12_regulation_error_flag                : 1;    // +12V input regulation error
    unsigned POS5P_regulation_error_flag                : 1;    // External power board regulation error
    unsigned POS5P5_regulation_error_flag               : 1;    // +5.5V power supply regulation error
    
} error_handler;



#endif /* _ERROR_HANDLER_H */

/* *****************************************************************************
 End of File
 */
