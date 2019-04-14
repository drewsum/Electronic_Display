/* ************************************************************************** */
/** Interrupt Control APIs

  @Company
    Marquette Senior Design E44

  @File Name
    32mz_interrupt_control.h

  @Summary
    Easier interface for enabling and disabling interrupts, checking interrupt flags, etc
    on the PIC32MZ family
  
  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _32MZ_INTERRUPT_CONTROL_H    /* Guard against multiple inclusion */
#define _32MZ_INTERRUPT_CONTROL_H

#include <xc.h>

#include "sys/attribs.h"

// This typdef describes all of the interrupt sources available on the 32MZ EF family
typedef enum {
    
    Core_Timer_Interrupt                    = 0,
    Core_Software_Interrupt_0               = 1,
    Core_Software_Interrupt_1               = 2,
    External_Interrupt_0                    = 3,
    Timer1                                  = 4,
    Input_Capture_1_Error                   = 5,
    Input_Capture_1                         = 6,
    Output_Compare_1                        = 7,
    External_Interrupt_1                    = 8,
    Timer2                                  = 9,
    Input_Capture_2_Error                   = 10,
    Input_Capture_2                         = 11,
    Output_Compare_2                        = 12,
    External_Interrupt_2                    = 13,
    Timer3                                  = 14,
    Input_Capture_3_Error                   = 15,
    Input_Capture_3                         = 16,
    Output_Compare_3                        = 17,
    External_Interrupt_3                    = 18,
    Timer4                                  = 19,
    Input_Capture_4_Error                   = 20,
    Input_Capture_4                         = 21,
    Output_Compare_4                        = 22,
    External_Interrupt_4                    = 23,
    Timer5                                  = 24,
    Input_Capture_5_Error                   = 25,
    Input_Capture_5                         = 26,
    Output_Compare_5                        = 27,
    Timer6                                  = 28,
    Input_Capture_6_Error                   = 29,
    Input_Capture_6                         = 30,
    Output_Compare_6                        = 31,
    Timer7                                  = 32,
    Input_Capture_7_Error                   = 33,
    Input_Capture_7                         = 34,
    Output_Compare_7                        = 35,
    Timer8                                  = 36,
    Input_Capture_8_Error                   = 37,
    Input_Capture_8                         = 38,
    Output_Compare_8                        = 39,
    Timer9                                  = 40,
    Input_Capture_9_Error                   = 41,
    Input_Capture_9                         = 42,
    Output_Compare_9                        = 43,
    ADC_Global_Interrupt                    = 44,
    ADC_FIFO_Data_Ready_Interrupt           = 45,
    ADC_Digital_Comparator_1                = 46,
    ADC_Digital_Comparator_2                = 47,
    ADC_Digital_Comparator_3                = 48,
    ADC_Digital_Comparator_4                = 49,
    ADC_Digital_Comparator_5                = 50,
    ADC_Digital_Comparator_6                = 51,
    ADC_Digital_Filter_1                    = 52,
    ADC_Digital_Filter_2                    = 53,
    ADC_Digital_Filter_3                    = 54,
    ADC_Digital_Filter_4                    = 55,
    ADC_Digital_Filter_5                    = 56,
    ADC_Digital_Filter_6                    = 57,
    ADC_Fault                               = 58,
    ADC_Data_0                              = 59,
    ADC_Data_1                              = 60,
    ADC_Data_2                              = 61,
    ADC_Data_3                              = 62,
    ADC_Data_4                              = 63,
    ADC_Data_5                              = 64,
    ADC_Data_6                              = 65,
    ADC_Data_7                              = 66,
    ADC_Data_8                              = 67,
    ADC_Data_9                              = 68,
    ADC_Data_10                             = 69,
    ADC_Data_11                             = 70,
    ADC_Data_12                             = 71,
    ADC_Data_13                             = 72,
    ADC_Data_14                             = 73,
    ADC_Data_15                             = 74,
    ADC_Data_16                             = 75,
    ADC_Data_17                             = 76,
    ADC_Data_18                             = 77,
    ADC_Data_19                             = 78,
    ADC_Data_20                             = 79,
    ADC_Data_21                             = 80,
    ADC_Data_22                             = 81,
    ADC_Data_23                             = 82,
    ADC_Data_24                             = 83,
    ADC_Data_25                             = 84,
    ADC_Data_26                             = 85,
    ADC_Data_27                             = 86,
    ADC_Data_28                             = 87,
    ADC_Data_29                             = 88,
    ADC_Data_30                             = 89,
    ADC_Data_31                             = 90,
    ADC_Data_32                             = 91,
    ADC_Data_33                             = 92,
    ADC_Data_34                             = 93,
    ADC_Data_35                             = 94,
    ADC_Data_36                             = 95,
    ADC_Data_37                             = 96,
    ADC_Data_38                             = 97,
    ADC_Data_39                             = 98,
    ADC_Data_40                             = 99,
    ADC_Data_41                             = 100,
    ADC_Data_42                             = 101,
    ADC_Data_43                             = 102,
    ADC_Data_44                             = 103,
    Core_Performance_Counter_Interrupt      = 104,
    Core_Fast_Debug_Channel_Interrupt       = 105,
    System_Bus_Protection_Violation         = 106,
    Crypto_Engine_Event                     = 107,
    SPI1_Fault                              = 109,
    SPI1_Receive_Done                       = 110,
    SPI1_Transfer_Done                      = 111,
    UART1_Fault                             = 112,
    UART1_Receive_Done                      = 113,
    UART1_Transfer_Done                     = 114,
    I2C1_Bus_Collision_Event                = 115,
    I2C1_Slave_Event                        = 116,
    I2C1_Master_Event                       = 117,
    PORTA_Input_Change_Interrupt            = 118,
    PORTB_Input_Change_Interrupt            = 119,
    PORTC_Input_Change_Interrupt            = 120,
    PORTD_Input_Change_Interrupt            = 121,
    PORTE_Input_Change_Interrupt            = 122,
    PORTF_Input_Change_Interrupt            = 123,
    PORTG_Input_Change_Interrupt            = 124,
    PORTH_Input_Change_Interrupt            = 125,
    PORTJ_Input_Change_Interrupt            = 126,
    PORTK_Input_Change_Interrupt            = 127,
    Parallel_Master_Port                    = 128,
    Parallel_Master_Port_Error              = 129,
    Comparator_1_Interrupt                  = 130,
    Comparator_2_Interrupt                  = 131,
    USB_General_Event                       = 132,
    USB_DMA_Event                           = 133,
    DMA_Channel_0                           = 134,
    DMA_Channel_1                           = 135,
    DMA_Channel_2                           = 136,
    DMA_Channel_3                           = 137,
    DMA_Channel_4                           = 138,
    DMA_Channel_5                           = 139,
    DMA_Channel_6                           = 140,
    DMA_Channel_7                           = 141,
    SPI2_Fault                              = 142,
    SPI2_Receive_Done                       = 143,
    SPI2_Transfer_Done                      = 144,
    UART2_Fault                             = 145,
    UART2_Receive_Done                      = 146,
    UART2_Transfer_Done                     = 147,
    I2C2_Bus_Collision_Event                = 148,
    I2C2_Slave_Event                        = 149,
    I2C2_Master_Event                       = 150,
    Control_Area_Network_1                  = 151,
    Control_Area_Network_2                  = 152,
    Ethernet_Interrupt                      = 153,
    SPI3_Fault                              = 154,
    SPI3_Receive_Done                       = 155,
    SPI3_Transfer_Done                      = 156,
    UART3_Fault                             = 157,
    UART3_Receive_Done                      = 158,
    UART3_Transfer_Done                     = 159,
    I2C3_Bus_Collision_Event                = 160,
    I2C3_Slave_Event                        = 161,
    I2C3_Master_Event                       = 162,
    SPI4_Fault                              = 163,
    SPI4_Receive_Done                       = 164,
    SPI4_Transfer_Done                      = 165,
    Real_Time_Clock                         = 166,
    Flash_Control_Event                     = 167,
    Prefetch_Module_SEC_Event               = 168,
    SQI1_Event                              = 169,
    UART4_Fault                             = 170,
    UART4_Receive_Done                      = 171,
    UART4_Transfer_Done                     = 172,
    I2C4_Bus_Collision_Event                = 173,
    I2C4_Slave_Event                        = 174,
    I2C4_Master_Event                       = 175,
    SPI5_Fault                              = 176,
    SPI5_Receive_Done                       = 177,
    SPI5_Transfer_Done                      = 178,
    UART5_Fault                             = 179,
    UART5_Receive_Done                      = 180,
    UART5_Transfer_Done                     = 181,
    I2C5_Bus_Collision_Event                = 182,
    I2C5_Slave_Event                        = 183,
    I2C5_Master_Event                       = 184,
    SPI6_Fault                              = 185,
    SPI6_Receive_Done                       = 186,
    SPI6_Transfer_Done                      = 187,
    UART6_Fault                             = 188,
    UART6_Receive_Done                      = 189,
    UART6_Transfer_Done                     = 190,
    ADC_End_Of_Scan_Ready                   = 192,
    ADC_Analog_Circuits_Ready               = 193,
    ADC_Update_Ready                        = 194,
    ADC_Group_Early_Interrupt_Request       = 196,
    ADC0_Early_Interrupt                    = 198,
    ADC1_Early_Interrupt                    = 199,
    ADC2_Early_Interrupt                    = 200,
    ADC3_Early_Interrupt                    = 201,
    ADC4_Early_Interrupt                    = 202,
    ADC7_Early_Interrupt                    = 205,
    ADC0_Warm_Interrupt                     = 206,
    ADC1_Warm_Interrupt                     = 207,
    ADC2_Warm_Interrupt                     = 208,
    ADC3_Warm_Interrupt                     = 209,
    ADC4_Warm_Interrupt                     = 210,
    ADC7_Warm_Interrupt                     = 213

} interrupt_source_t;

// This function configures the system for multi-interrupt operation and
// assigns shadow registers sets to priority level ISRs
void interruptControllerInitialize(void);

// This function enables global interrupts
void enableGlobalInterrupts(void);

// This function disables global interrupts
void disableGlobalInterrupts(void);

// This function returns the state of global interrupt enable
// Returns 0 if global interrupts are disabled
// returns 1 if global interrupts are enabled
uint8_t getGlobalInterruptsState(void);

// This function explicitly sets the state of global interrupts
void setGlobalInterruptsState(uint8_t);

// This function allows for the setting/clearing of a given interrupt enable
// It manipulates the interrupt's 'Interrupt Enable' bit with IEC registers
void setInterruptEnable(interrupt_source_t input_interrupt, uint8_t input_state);

// This function allows for the reading of a given interrupt enable
// It reads the interrupt's 'Interrupt Enable' bit with IEC registers
// Returns the state of the given interrupt
uint8_t getInterruptEnable(interrupt_source_t input_interrupt);

// This function allows for the setting/clearing of a given interrupt flag
// It manipulates the interrupt's 'Interrupt Flag' bit
void setInterruptFlag(interrupt_source_t input_interrupt, uint8_t input_state);

// This function allows for the reading of a given interrupt flag
// It reads the interrupt's 'Interrupt Flag' bit
// Returns the state of the given interrupt flag
uint8_t getInterruptFlag(interrupt_source_t input_interrupt);

// This function sets the priority for a given interrupt
void setInterruptPriority(interrupt_source_t input_interrupt, uint8_t input_priority);

// This function sets the subpriority for a given interrupt
void setInterruptSubpriority(interrupt_source_t input_interrupt, uint8_t input_subpriority);

// This function returns the given interrupt priority
uint8_t getInterruptPriority(interrupt_source_t input_interrupt);

// This function returns the given interrupt subpriority
uint8_t getInterruptSubriority(interrupt_source_t input_interrupt);

// This function enables selected interrupt
void enableInterrupt(interrupt_source_t input_interrupt);

// This function disables selected interrupt
void disableInterrupt(interrupt_source_t input_interrupt);

// This function clears selected interrupt flag
void clearInterruptFlag(interrupt_source_t input_interrupt);

// This function returns a string of the given interrupt name
char * getInterruptNameStringPadded(interrupt_source_t input_interrupt);

// This function prints information on all interrupt settings
void printInterruptStatus(void);

#endif /* _32MZ_INTERRUPT_CONTROL_H */

/* *****************************************************************************
 End of File
 */
