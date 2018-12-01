/*******************************************************************************
  OC Driver Functions for Static Single Instance Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_oc_static.c

  Summary:
    OC driver implementation for the static single instance driver.

  Description:
    The OC device driver provides a simple interface to manage the OC
    modules on Microchip microcontrollers.
    
  Remarks:
    Static interfaces incorporate the driver instance number within the names
    of the routines, eliminating the need for an object ID or object handle.
    Static single-open interfaces also eliminate the need for the open handle.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTOCULAR PURPOSE.
IN NO EVENT SHALL MOCROCHIP OR ITS LOCENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STROCT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVOCES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Header Includes
// *****************************************************************************
// *****************************************************************************
#include "peripheral/oc/plib_oc.h"

// *****************************************************************************
// *****************************************************************************
// Section: Instance 0 static driver functions
// *****************************************************************************
// *****************************************************************************
void DRV_OC0_Initialize(void)
{
    /* Setup OC0 Instance */
    PLIB_OC_ModeSelect(OC_ID_4, OC_COMPARE_TURN_OFF_MODE);
    PLIB_OC_BufferSizeSelect(OC_ID_4, OC_BUFFER_SIZE_16BIT);
    PLIB_OC_TimerSelect(OC_ID_4, OC_TIMER_16BIT_TMR3);
    PLIB_OC_Buffer16BitSet(OC_ID_4, 65535);
    PLIB_OC_PulseWidth16BitSet(OC_ID_4, 10);
}

void DRV_OC0_Enable(void)
{
   PLIB_OC_Enable(OC_ID_4);
}

void DRV_OC0_Disable(void)
{
   PLIB_OC_Disable(OC_ID_4);
}

void DRV_OC0_Start(void)
{
   PLIB_OC_Enable(OC_ID_4);
}

void DRV_OC0_Stop(void)
{
   PLIB_OC_Disable(OC_ID_4);
}

bool DRV_OC0_FaultHasOccurred(void)
{
   return PLIB_OC_FaultHasOccurred(OC_ID_4);
}

/*******************************************************************************
 End of File
*/
