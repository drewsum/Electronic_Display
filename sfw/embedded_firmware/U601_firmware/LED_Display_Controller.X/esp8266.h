/* ************************************************************************** */
/** ESP8266

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    esp8266.h

  @Summary
 Gives APIs for communicating with ESP826 6WiFi module over UART1

 */
/* ************************************************************************** */

#ifndef _ESP8266_H    /* Guard against multiple inclusion */
#define _ESP8266_H

#include <xc.h>
// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>

#include "delay_timer.h"

// Sizes of TX and RX ring buffers
#define ESP_8266_TX_BUFFER_SIZE 16384
#define ESP_8266_RX_BUFFER_SIZE 2048

char esp_8266_line[ESP_8266_RX_BUFFER_SIZE];

extern volatile uint32_t esp_8266_TxHead;
extern volatile uint32_t esp_8266_TxTail;
extern volatile uint32_t esp_8266_TxBufferRemaining;

// This is the current connection ID for the ESP
uint32_t current_connection_id = 20;

// This is the string that is sent back to the android app after a TCP transaction
char response_message[40];

// This is the string of data plucked out of the TCP transaction,
// it should match exactly what is sent from the android phone
char received_string[2500];

// This function initializes UART 1 for ESP8266 WiFi Module
void esp8266Initialize(void);

// This function configures the esp on initialization
void esp8266InitializeConfiguration(void);

// These are the ESP UART Interrupt Service Routines
void __ISR(_UART1_RX_VECTOR, ipl7SRS) esp8266ReceiveISR(void);
void __ISR(_UART1_TX_VECTOR, ipl7SRS) esp8266TransferISR(void);
void __ISR(_UART1_FAULT_VECTOR, ipl1SRS) esp8266FaultISR(void);

// This function allows reading of a byte from UART1
uint8_t esp8266ReadByte(void);

// This function places a character into the output stream of UART1
void esp8266Putchar(uint8_t txData);
void esp8266Putstring(char * string);
// These are the UART1 interrupt handlers
void esp8266TransmitHandler(void);
void esp8266ReceiveHandler(void);

// Ring buffer interface functions
void esp8266RingBufferPull(void);
void esp8266RingBufferLUT(char * esp_8266_line);

#endif /* _ESP8266_H */

/* *****************************************************************************
 End of File
 */
