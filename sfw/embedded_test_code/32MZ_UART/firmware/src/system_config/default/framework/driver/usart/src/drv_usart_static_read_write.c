/*******************************************************************************
  USART driver static implementation of Read Write model.

  Company:
    Microchip Technology Inc.

  File Name:
    drv_usart_static_read_write.c

  Summary:
    Source code for the USART driver static implementation of File IO data
    transfer model.

  Description:
    This file contains the source code for the static implementation of the
    USART driver File IO data transfer model.

  Remarks:
    Static interfaces incorporate the driver instance number within the names
    of the routines, eliminating the need for an object ID or object handle.

    Static single-open interfaces also eliminate the need for the open handle.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
//DOM-IGNORE-END
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "system_config.h"
#include "system_definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

/* This is the USART Driver Buffer object */
DRV_USART_BUFFER_OBJ gDrvUSARTBuffer;

extern DRV_USART_OBJ  gDrvUSART0Obj ;

// *****************************************************************************
// *****************************************************************************
// Section: Instance 0 static driver functions
// *****************************************************************************
// *****************************************************************************
size_t DRV_USART0_Read(void * destination,const size_t nBytes)
{
    DRV_USART_OBJ *dObj = (DRV_USART_OBJ*)NULL;
    DRV_USART_BUFFER_OBJ * iterator, * bufferObj;
    size_t count = 0;

    dObj = &gDrvUSART0Obj;

    if((destination == NULL) || (nBytes == 0))
    {
        /* We have a NULL pointer or don't have
           any data to write. */

        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\nUSART Driver: NULL data pointer or no data to write");
        return 0;
    }

    /* This is a blocking implementation. We populate the client buffer
       object and add it to the queue. We then wait till the buffer is
       completely processed. */
    
    /* Because we are modifying the queue, we should disable the
       interrupt */
    SYS_INT_SourceDisable(INT_SOURCE_USART_1_RECEIVE);
    SYS_INT_SourceDisable(INT_SOURCE_USART_1_ERROR);

    /* Get the queue head */
    iterator = dObj->queueRead;

    /* If the queue is not empty, get to the end of the queue */
    if(iterator != NULL)
    {
        while(iterator->next != NULL)
        {
        iterator = iterator->next;
    }
    }

    /* We should be at the end of the queue now, Use buffer object */
    bufferObj = &gDrvUSARTBuffer;
    bufferObj->buffer = destination;
    bufferObj->nCurrentBytes = 0;
    bufferObj->size = nBytes;
    bufferObj->inUse = true;
    bufferObj->flags = (DRV_USART_BUFFER_OBJ_FLAG_READ_WRITE);

    /* Add this object to the queue and enable the RX interrupt */
    bufferObj->previous = iterator;
    bufferObj->next = NULL;

    /* If we are not at the start of the queue, then update the next
       pointer of the last object else set the queue head to point to
       this object */
    if(dObj->queueRead == NULL)
    {
        dObj->queueRead = bufferObj;
    }
    else
    {
        iterator->next = bufferObj;
        bufferObj->previous = iterator;
    }

    /* Update the queue size as we have added a buffer to the queue */
    dObj->queueSizeCurrentRead ++;

    /* Now enable the interrupt and release the mutex so that the system
       can proceed */

    SYS_INT_SourceEnable(INT_SOURCE_USART_1_RECEIVE);
    SYS_INT_SourceEnable(INT_SOURCE_USART_1_ERROR);
    while(bufferObj->inUse);
    if(bufferObj->nCurrentBytes != nBytes)
            {
        /* This means this buffer was terminated because of an
           error. */
                        
                return(DRV_USART_READ_ERROR);
            }
            
    count = nBytes;
    return(count);
}

size_t DRV_USART0_Write(void * source, const size_t nBytes)
{
    DRV_USART_OBJ *dObj = (DRV_USART_OBJ*)NULL;
    DRV_USART_BUFFER_OBJ * iterator, * bufferObj;
    size_t count = 0;
    uint8_t * data;

    dObj = &gDrvUSART0Obj;

    if((source == NULL) || (nBytes == 0))
    {
        /* We have a NULL pointer or don't have
           any data to write. */

        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\nUSART Driver: NULL data pointer or no data to write");
        return 0;
    }

    data = (uint8_t *)source;

    /* This is a blocking implementation. We populate the client buffer
       object and add it to the queue. We then wait till the buffer is
       completely processed. */

    /* Because we are modifying the queue, we should disable the
       interrupt */

    SYS_INT_SourceDisable(INT_SOURCE_USART_1_TRANSMIT);

    /* Get the queue head */
    iterator = dObj->queueWrite;

    /* If the queue is not empty, then get to the
       end of the queue */
    if(iterator != NULL)
    {
        while(iterator->next != NULL)
        {
            iterator = iterator->next;
    }
    }

    /* We should be at the end of the queue now, Use buffer object */
    bufferObj = &gDrvUSARTBuffer;
    bufferObj->buffer = source;
    bufferObj->nCurrentBytes = 0;
    bufferObj->size = nBytes;
    bufferObj->inUse = true;
    bufferObj->flags = (DRV_USART_BUFFER_OBJ_FLAG_READ_WRITE);

    /* Add this object to the queue and enable the RX interrupt */
    bufferObj->previous = iterator;
    bufferObj->next = NULL;

    /* If we are not at the start of the queue, then update the next
       pointer of the last object else set the queue head to point to
       this object */
    if(dObj->queueWrite == NULL)
    {
        dObj->queueWrite = bufferObj;
        bufferObj->nCurrentBytes = 1;
        dObj->queueSizeCurrentWrite ++;
        PLIB_USART_TransmitterByteSend(USART_ID_1, data[0]);
    }
    else
    {
        iterator->next = bufferObj;
        bufferObj->previous = iterator;
        dObj->queueSizeCurrentWrite ++;
    }

    /* Now enable the interrupt so that the system
       can proceed */
    SYS_INT_SourceEnable(INT_SOURCE_USART_1_TRANSMIT);

    while(bufferObj->inUse);
    if(bufferObj->nCurrentBytes != nBytes)
            {
        /* This means this buffer was terminated because of an
           error. */
                return(DRV_USART_WRITE_ERROR);
            }

    count = nBytes;

    return(count);
}

/*******************************************************************************
 End of File
*/
