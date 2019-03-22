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

// Sizes of TX and RX ring buffers
#define ESP_8266_TX_BUFFER_SIZE 2048
#define ESP_8266_RX_BUFFER_SIZE 4096

char esp_8266_line[ESP_8266_RX_BUFFER_SIZE];

// This function initializes UART 6 for USB debugging
void esp8266Initialize(void);

// This function configures the esp on initialization
void esp8366InitializeConfiguration(void);

// These are the USB UART Interrupt Service Routines
void __ISR(_UART1_RX_VECTOR, ipl7SRS) esp8266ReceiveISR(void);
void __ISR(_UART1_TX_VECTOR, ipl6SRS) esp8266TransferISR(void);
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

// configure the chip with AT commands
void esp8266Configure(void);

// WiFi specific functions
void sendCIPData(uint8_t connectionId, uint8_t * data, uint8_t length);
void sendHTTPResponse(uint8_t connectionId, uint8_t * content, uint8_t length);

#endif /* _ESP8266_H */

/* *****************************************************************************
 End of File
 */
