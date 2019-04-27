
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "esp8266.h"
#include "32mz_interrupt_control.h"
#include "error_handler.h"
#include "pin_macros.h"
#include "terminal_control.h"
#include "usb_uart.h"
#include "delay_timer.h"
#include "panel_control.h"
#include "external_bus_interface.h"
#include "standard_operation_sm.h"
// #include "test_image_1.h"
#include "spi_flash.h"

// This pragma tells the linker to allow access of EBI memory space
#pragma region name = "EBI_SRAM" origin = 0xC0000000 size = 262144

// This is tricking the compiler into placing an array in EBI SRAM
extern uint8_t ebi_sram_array[262144] __attribute__((region("EBI_SRAM")));



volatile uint32_t esp_8266_TxHead = 0;
volatile uint32_t esp_8266_TxTail = 0;
volatile uint8_t esp_8266_TxBuffer[ESP_8266_TX_BUFFER_SIZE];
volatile uint32_t esp_8266_TxBufferRemaining;

volatile uint32_t esp_8266_RxHead = 0;
volatile uint32_t esp_8266_RxTail = 0;
volatile uint8_t esp_8266_RxBuffer[ESP_8266_RX_BUFFER_SIZE];
volatile uint32_t esp_8266_RxCount;

volatile uint8_t esp_8266_RxStringReady = 0;
volatile uint8_t esp_8266_FlashFlag = 0;

// uint8_t * cipString;


void esp8266Initialize(void) {
 
	// esp8266 module uses UART 1
	
    // Disable UART 1 interrupts
    disableInterrupt(UART1_Receive_Done);
    disableInterrupt(UART1_Transfer_Done);
    disableInterrupt(UART1_Fault);
    
    // Turn off UART 1 for configuration
    U1MODEbits.ON = 0;
    
    // Enable UART 1 operation in IDLE mode
    U1MODEbits.SIDL = 0;
    
    // Disable IrDA encoding
    U1MODEbits.IREN = 0;
    
    // Disable CTS, RTS signals
    // (No flow control used)
    U1MODEbits.UEN = 0b00;
    
    // Enable wake from sleep
    U1MODEbits.WAKE = 1;
    
    // Disable loopback
    U1MODEbits.LPBACK = 0;
    
    // Disable auto-baud
    U1MODEbits.ABAUD = 0;
    
    // RX idle state is logic high
    U1MODEbits.RXINV = 0;
    
    // High speed baud rate setting
    U1MODEbits.BRGH = 1;
    
    // 8 bit data length and no parity
    U1MODEbits.PDSEL = 0b00;
    
    // 1 stop bit
    U1MODEbits.STSEL = 0;
    
    // Disable addressing
    U1STAbits.ADM_EN = 0;
    
    // Interrupt on every transmitted character
    U1STAbits.UTXISEL = 0b00;
    
    // Idle transmit state is high
    U1STAbits.UTXINV = 0;
    
    // Enable receiver
    U1STAbits.URXEN = 1;
    
    // Disable break
    U1STAbits.UTXBRK = 0;
    
    // Enable transmitter
    U1STAbits.UTXEN = 1;
    
    // Interrupt on every character received
    U1STAbits.URXISEL = 0b00;
    
    // Disable address detection
    U1STAbits.ADDEN = 0;
    
    // Set baud rate to 115200 bps
    // From section 21.3 of PIC32MZ reference manual
    // Input CLK is PBCLK2 (84 MHz)
    // With PBCLK2 = 84 MHz, BRGH = 1, baud rate error is 0.16%
    U1BRG = 181;
    
    // initializing the driver state
    esp_8266_TxHead = 0;
    esp_8266_TxTail = 0;
    esp_8266_TxBufferRemaining = sizeof(esp_8266_TxBuffer);
    esp_8266_RxHead = 0;
    esp_8266_RxTail = 0;
    esp_8266_RxCount = 0;
        
    
    // Set interrupt priorities
    setInterruptPriority(UART1_Receive_Done, 7);
    setInterruptPriority(UART1_Transfer_Done, 7);
    setInterruptPriority(UART1_Fault, 1);
    
    // Set interrupt subpriorities
    setInterruptSubpriority(UART1_Receive_Done, 1);
    setInterruptSubpriority(UART1_Transfer_Done, 2);
    setInterruptSubpriority(UART1_Fault, 1);
    
    // Clear all UART 1 Interrupts
    clearInterruptFlag(UART1_Receive_Done);
    clearInterruptFlag(UART1_Transfer_Done);
    clearInterruptFlag(UART1_Fault);
    
    // Enable UART 1
    U1MODEbits.ON = 1;
            
    // Enable receive and error interrupts
    // Transfer interrupt is set in write function
    enableInterrupt(UART1_Receive_Done);
    enableInterrupt(UART1_Fault);
    
}

// This function configures the esp on initialization
void esp8266InitializeConfiguration(void) {
 
    // set the chip enable to high (active high)
    WIFI_CHPD_PIN = 1;
    
    // set the reset line on the chip to high
    nWIFI_RESET_PIN = 0;
    
    // start the delay timer that will interrupt
    delayTimerStart(0x5FFF, esp8266Delay1);
    
}

// This is the esp8266 receive interrupt service routine
void __ISR(_UART1_RX_VECTOR, ipl7SRS) esp8266ReceiveISR(void) {
    
    // Disable SPI3 receive interrupt and stop state machine
    // if (continue_autopilot) {
        
        // SPI_Read_Finished_Flag = 0;
        disableInterrupt(SPI3_Receive_Done);
        clearInterruptFlag(SPI3_Receive_Done);
        continue_autopilot = 0;
        // state = sm_start;
        // sm_previous = 0;
        T6CONbits.ON = 0;
        panelMultiplexingSuspend();
        
        
    // }
    
    // Do receive tasks
    esp8266ReceiveHandler();
    
    // Clear receive interrupt flag
    clearInterruptFlag(UART1_Receive_Done);
    
}

// This is the esp8266 transfer interrupt service routine
void __ISR(_UART1_TX_VECTOR, ipl7SRS) esp8266TransferISR(void) {
    
    // Do transfer tasks
    esp8266TransmitHandler();
    // Clear interrupt flag
    clearInterruptFlag(UART1_Transfer_Done);
    
}

// This is the ESP 8266 fault interrupt service routine
void __ISR(_UART1_FAULT_VECTOR, ipl1SRS) esp8266FaultISR(void) {
    
    // TO-DO: Fault tasks
    error_handler.WIFI_error_flag = 1;   
    // nWIFI_RESET_PIN = 1;
    // wait for chip to reset (time delay)
    // esp8266Initialize()
    
    
    // maybe do a reset here and then reconfigure etc.
    // 
    // Clear fault interrupt flag
    clearInterruptFlag(UART1_Fault);
    
}

// This function pulls a byte from the RX ring buffer
uint8_t esp8266ReadByte(void) {
 
    uint8_t readValue  = 0;
    
    // This state should never be entered
    while(0 == esp_8266_RxCount)
    {
        error_handler.WIFI_error_flag = 1;
        return 0;
    }

    readValue = esp_8266_RxBuffer[esp_8266_RxTail++];
    if(sizeof(esp_8266_RxBuffer) <= esp_8266_RxTail)
    {
        esp_8266_RxTail = 0;
    }
    
    
    disableInterrupt(UART1_Receive_Done);
    esp_8266_RxCount--;
    enableInterrupt(UART1_Receive_Done);
    return readValue;
    
}

void esp8266Putchar(uint8_t txData) {
 
    // wait for ring buffer to open up
    while(0 == esp_8266_TxBufferRemaining);

    if(0 == getInterruptEnable(UART1_Transfer_Done))
    {
        U1TXREG = txData;
        // panelMultiplexingSuspend();
   
    }
    else
    {
        
        disableInterrupt(UART1_Transfer_Done);
        esp_8266_TxBuffer[esp_8266_TxHead++] = txData;
        
        if(sizeof(esp_8266_TxBuffer) <= esp_8266_TxHead)
        {
            esp_8266_TxHead = 0;
        }
        
        esp_8266_TxBufferRemaining--;

    }

     enableInterrupt(UART1_Transfer_Done);
   
    
}

// This serves as the TX interrupt handler and is called by the TX ISR
void esp8266TransmitHandler(void) {
 
    if(sizeof(esp_8266_TxBuffer) > esp_8266_TxBufferRemaining)
    {
        while(U1STAbits.UTXBF == 1);
        U1TXREG = esp_8266_TxBuffer[esp_8266_TxTail++];
        // usbUartPutchar(esp_8266_TxBuffer[esp_8266_TxTail-1]);
        if(sizeof(esp_8266_TxBuffer) <= esp_8266_TxTail)
        {
            esp_8266_TxTail = 0;
        }
        esp_8266_TxBufferRemaining++;
    }
    
    else
    {
        disableInterrupt(UART1_Transfer_Done);        
    }
    
    
}

// This serves as the RX handler and is called by the RX ISR
void esp8266ReceiveHandler(void) {
            
    if(1 == U1STAbits.OERR)
    {
        U1MODEbits.ON = 0;
        error_handler.WIFI_error_flag = 1;
        U1STAbits.OERR = 0;
        U1MODEbits.ON = 1;
    }

    while(U1STAbits.URXDA) {
        
        esp_8266_RxBuffer[esp_8266_RxHead++] = U1RXREG;
        
        if(sizeof(esp_8266_RxBuffer) <= esp_8266_RxHead)
        {
            esp_8266_RxHead = 0;
        }
        esp_8266_RxCount++;
        
    }    
    
    // This chunk tells main() or whatever is pulling from the ring buffer that
    // data is ready to be read, since the terminal sent a newline or 
    // carriage return
    if((esp_8266_RxBuffer[esp_8266_RxHead - 1] == (int) '\n') ||
    (esp_8266_RxBuffer[esp_8266_RxHead - 1] == (int) '\r')) {

        esp_8266_RxStringReady = 1;
                
    }
    
    else {
        
        esp_8266_RxStringReady = 0;
        
    }    
}

// This function pulls data out of the RX ring buffer
void esp8266RingBufferPull(void) {

    int charNumber = esp_8266_RxCount;
            
    // Clear line buffer
    uint32_t index;
    for (index = 0; index < sizeof(esp_8266_line); index++) {

        esp_8266_line[index] = '\0';

    }

    // Fill line from ring buffer
    for(index = 0; index < charNumber; index++){

        esp_8266_line[index] = esp8266ReadByte();

    }

    // Reset ring buffer
    esp_8266_RxTail = 0;
    esp_8266_RxHead = 0;
    esp_8266_RxCount = 0;

    // Try to kill off ending returns/newlines
    /*while((esp_8266_line[strlen(esp_8266_line) - 1] == (int) '\n') ||
          (esp_8266_line[strlen(esp_8266_line) - 1] == (int) '\r')) {
     
        // NULL
        esp_8266_line[strlen(esp_8266_line) - 1] = '\0';
        
    }
    */
    
    // Check to see if line matches a command
    esp8266RingBufferLUT(esp_8266_line);
    
    // Clear ready flag
    esp_8266_RxStringReady = 0;
    
}

void esp8266RingBufferLUT(char * line_in) {
 
    if (    strstart(line_in, "+IPD,") == 0 || 
            strstart(line_in, "IPD,") == 0 ||
            strstart(line_in, "PD,") == 0 ||
            strstart(line_in, "D,") == 0
            ) {
    
        uint32_t dummy;
        sscanf(line_in, "+IPD,%u,%u:%2499c",
                &current_connection_id,
                &dummy,
                received_string);
        
        // printf("Received string = %s, length = %u\r\n", received_string, strlen(received_string));
        
        if (0 == strstart(received_string, "ping")) {
            
            eventually_continue_flag = 1;
            
            strcpy(response_message, "Message Received\r\n");
            // Tell kevin we received message
            delayTimerStart(0x00FF, esp8266_tcp_response_delay1);
            
            if (usb_in_use_flag) {
            
                terminalTextAttributesReset();
                terminalTextAttributes(CYAN, BLACK, NORMAL);
                // printf("WiFi Module Sent:\r\n");
                printf("Received Hello World\r\n");
                terminalTextAttributesReset();

            }
            
        }
        
        else if (0 == strstart(received_string, "Power=0")) {

            panelMultiplexingSuspend();
            muxing_state = 0;
            
            // Stop state machine
            continue_autopilot = 0;
            state = sm_start;
            sm_previous = 0;
            T6CONbits.ON = 0;
            
            strcpy(response_message, "Message Received\r\n");
            // Tell kevin we received message
            delayTimerStart(0x00FF, esp8266_tcp_response_delay1);
            
            if (usb_in_use_flag) {

                terminalTextAttributesReset();
                terminalTextAttributes(CYAN, BLACK, NORMAL);
                printf("%s", esp_8266_line);
                terminalTextAttributesReset();

            }
                
        }
        
                
        else if (0 == strstart(received_string, "Clear_EBI")) {

            clearEBISRAM(); 
            
            strcpy(response_message, "Message Received\r\n");
            // Tell kevin we received message
            delayTimerStart(0x00FF, esp8266_tcp_response_delay1);
            
            if (usb_in_use_flag) {

                terminalTextAttributesReset();
                terminalTextAttributes(CYAN, BLACK, NORMAL);
                // printf("WiFi Module Sent:\r\n");
                printf("%s", esp_8266_line);
                terminalTextAttributesReset();

            }
                
        }
        
        else if (0 == strstart(received_string, "EBI_2_Flash=")) {

            uint32_t chip_to_write;
            sscanf(received_string, "EBI_2_Flash=%d", &chip_to_write);
            if (chip_to_write >= 1 && chip_to_write <= 8) SPI_FLASH_beginWrite((uint8_t) chip_to_write);
            
            strcpy(response_message, "Message Received\r\n");
            // Tell kevin we received message
            delayTimerStart(0xFFFF, esp8266_tcp_response_delay1);
            
            if (usb_in_use_flag)  {

                terminalTextAttributesReset();
                terminalTextAttributes(CYAN, BLACK, NORMAL);
                // printf("WiFi Module Sent:\r\n");
                printf("%s", esp_8266_line);
                terminalTextAttributesReset();

            }
                
        }
        
        else if (0 == strstart(received_string, "Dim=")) {

            uint32_t set_brightness;
            sscanf(received_string, "Dim=%d_", &set_brightness);
            
            if (set_brightness <= 100 && set_brightness >= 5) panelPWMSetBrightness((uint8_t) set_brightness);
            
            strcpy(response_message, "Message Received\r\n");
            // Tell kevin we received message
            delayTimerStart(0x00FF, esp8266_tcp_response_delay1);
            
            if (usb_in_use_flag) {

                terminalTextAttributesReset();
                terminalTextAttributes(CYAN, BLACK, NORMAL);
                // printf("WiFi Module Sent:\r\n");
                printf("Set brightness = %d\r\n", set_brightness);
                terminalTextAttributesReset();

            }
            
            // panelMultiplexingSuspend();
            fillRamBufferSplashScreen();
            // panelMultiplexingTimerStart();
            muxing_state = 1;

            // state machine flags
            eventually_continue_flag = 1;
            
        }
        
        else if (0 == strstart(received_string, "ImageData=")) {

            disableInterrupt(PORTK_Input_Change_Interrupt);
            
            uint32_t image_starting_addr;
            
            // Image data is encoded in this string
            char image_data_str[1200];
            
            sscanf(received_string, "ImageData=Addr=0x%06X,Data=%1024c", &image_starting_addr, image_data_str);

            // printf("Starting Addr = %u, Data = %s\r\n", image_starting_addr, image_data_str);
            
            // Loop through received image data characters and load into EBI SRAM
            uint16_t char_loop_addr;
            for (char_loop_addr = 0; char_loop_addr <= 1024; char_loop_addr += 2) {
             
                // Copy the current hex number into a holding char array
                char hex_input[3];
                hex_input[0] = image_data_str[char_loop_addr];
                hex_input[1] = image_data_str[char_loop_addr + 1];
                hex_input[2] = '\0';
                
                uint8_t current_byte = strtol(hex_input, NULL, 16);
                
                ebi_sram_array[char_loop_addr / 2 + image_starting_addr] = current_byte;
                
            }
            
            strcpy(response_message, "Message Received\r\n");
            
            // Tell kevin we received message
            delayTimerStart(0x00FF, esp8266_tcp_response_delay1);
            
            if (usb_in_use_flag)  {
                
                terminalTextAttributesReset();
                terminalTextAttributes(CYAN, BLACK, NORMAL);
                // printf("WiFi Module Sent:\r\n");
                printf("Image Data: 0x%06X\r\n", image_starting_addr);
                terminalTextAttributesReset();
        
            }
            
        }
        
        else if (0 == strstart(received_string, "Restart_State_Machine")) {

            clearInterruptFlag(PORTK_Input_Change_Interrupt);
            enableInterrupt(PORTK_Input_Change_Interrupt);
            
            fillRamBufferSplashScreen();
            // panelMultiplexingTimerStart();
            // muxing_state = 1;

            // state machine flags
//            continue_autopilot = 1;
//            state = sm_start;
            eventually_continue_flag = 1;
                        
            strcpy(response_message, "Message Received\r\n");
            
            // Tell kevin we received message
            delayTimerStart(0x0FFF, esp8266_tcp_response_delay1);
            
            if (usb_in_use_flag) {

                terminalTextAttributesReset();
                terminalTextAttributes(CYAN, BLACK, NORMAL);
                // printf("WiFi Module Sent:\r\n");
                printf("State Machine Restarted\r\n");
                terminalTextAttributesReset();

            }
                
        }
        
        else if (0 == strstart(received_string, "Project_Data=")) {

            uint32_t set_timer_val;
            uint32_t set_frame_val;
            sscanf(received_string, "Project_Data=%d,%d_", & set_frame_val, &set_timer_val);
            
            if (set_frame_val <= 8 && set_frame_val >= 1) writeNVMVariables((uint8_t) set_frame_val, set_timer_val);
            
            if (usb_in_use_flag) {
                
                terminalTextAttributesReset();
                terminalTextAttributes(CYAN, BLACK, NORMAL);
                printf("Set countdown value = %d\r\n", readDelayNVM());
                printf("Set Frame num = %d\r\n", readFrameNVM());
                terminalTextAttributesReset();

            }

            strcpy(response_message, "Message Received\r\n");
            
            // Tell kevin we received message
            delayTimerStart(0x0FFF, esp8266_tcp_response_delay1);
                            
        }
        
        
        
        else {
            
            strcpy(response_message, "Resend Message\r\n");
            // Tell kevin we received message
            delayTimerStart(0x0FFF, esp8266_tcp_response_delay1);
            
            if (usb_in_use_flag) {

                terminalTextAttributesReset();
                terminalTextAttributes(CYAN, BLACK, NORMAL);
                // printf("WiFi Module Sent:\r\n");
                printf("%s", esp_8266_line);
                terminalTextAttributesReset();

            }
                
        }
        
    }
    
    else {
    
        if (usb_in_use_flag) {

            terminalTextAttributesReset();
            terminalTextAttributes(CYAN, BLACK, NORMAL);
            // printf("WiFi Module Sent:\r\n");
            printf("%s", esp_8266_line);
            terminalTextAttributesReset();

        }
            
    }
    
}

void esp8266Putstring(char * string) {
    uint32_t i;
    //char * new_string;
    char new_string[512];
    strcpy(new_string, "               ");
    strcat(new_string, string);
    
    for(i = 0; i <= strlen(new_string); i++) {
        
        esp8266Putchar(new_string[i]);
    
    }
    
}

