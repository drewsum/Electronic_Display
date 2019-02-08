
#include <xc.h>
#include <stdio.h>

#include "32mz_interrupt_control.h"
#include "terminal_control.h"

// This function configures the system for multi-interrupt operation and
// assigns shadow registers sets to priority level ISRs
void interruptControllerInitialize(void) {
 
    // Enable multi-vector interrupt mode
    INTCONbits.MVEC = 1;
    
    // Assign shadow register sets to interrupt priorities
    // assign shadow set #7-#1 to priority level #7-#1 ISRs
    PRISS = 0x76543210;

}

// This function enables global interrupts
void enableGlobalInterrupts(void) {
 
    // This is built into the XC32 compiler
    __builtin_enable_interrupts();
    
}

// This function disables global interrupts
void disableGlobalInterrupts(void) {
 
    // This is built into the XC32 compiler
    __builtin_disable_interrupts();
    
}

// This function returns the state of global interrupt enable
// Returns 0 if global interrupts are disabled
// returns 1 if global interrupts are enabled
uint8_t getGlobalInterruptsState(void) {
 
    return __builtin_get_isr_state();
    
}

// This function explicitly sets the state of global interrupts
void setGlobalInterruptsState(uint8_t input_state) {

    __builtin_set_isr_state(input_state);
    
}


// This function allows for the setting/clearing of a given interrupt
// It manipulates that interrupt's 'Interrupt Enable' bit
void setInterruptEnable(interrupt_source_t input_interrupt, uint8_t input_state) {
 
    // Mask off anything larger than 1 to 1
    // input_state = input_state >= 1;
    
    // Decide which interrupt control bits to manipulate based on which interrupt
    // is being enabled or disabled
    switch (input_interrupt) {
        
        case Core_Timer_Interrupt:
            IEC0bits.CTIE = input_state;
            break;
            
        case Core_Software_Interrupt_0:
            IEC0bits.CS0IE = input_state;
            break;
            
        case Core_Software_Interrupt_1:
            IEC0bits.CS1IE = input_state;
            break;
            
        case External_Interrupt_0:
            IEC0bits.INT0IE = input_state;
            break;
            
        case Timer1:
            IEC0bits.T1IE = input_state;
            break;
            
        case Input_Capture_1_Error:
            IEC0bits.IC1EIE = input_state;
            break;
            
        case Input_Capture_1:
            IEC0bits.IC1IE = input_state;
            break;
            
        case Output_Compare_1:
            IEC0bits.OC1IE = input_state;
            break;
            
        case External_Interrupt_1:
            IEC0bits.INT1IE = input_state;
            break;
            
        case Timer2:
            IEC0bits.T2IE = input_state;
            break;
            
        case Input_Capture_2_Error:
            IEC0bits.IC2EIE = input_state;
            break;
            
        case Input_Capture_2:
            IEC0bits.IC2IE = input_state;
            break;
            
        case Output_Compare_2:
            IEC0bits.OC2IE = input_state;
            break;
            
        case External_Interrupt_2:
            IEC0bits.INT2IE = input_state;
            break;
            
        case Timer3:
            IEC0bits.T3IE = input_state;
            break;
            
        case Input_Capture_3_Error:
            IEC0bits.IC3EIE = input_state;
            break;
            
        case Input_Capture_3:
            IEC0bits.IC3IE = input_state;
            break;
            
        case Output_Compare_3:
            IEC0bits.OC3IE = input_state;
            break;
            
        case External_Interrupt_3:
            IEC0bits.INT3IE = input_state;
            break;
            
        case Timer4:
            IEC0bits.T4IE = input_state;
            break;
            
        case Input_Capture_4_Error:
            IEC0bits.IC4EIE = input_state;
            break;
            
        case Input_Capture_4:
            IEC0bits.IC4IE = input_state;
            break;
            
        case Output_Compare_4:
            IEC0bits.OC4IE = input_state;
            break;
            
        case External_Interrupt_4:
            IEC0bits.INT4IE = input_state;
            break;
            
        case Timer5:
            IEC0bits.T5IE = input_state;
            break;
            
        case Input_Capture_5_Error:
            IEC0bits.IC5EIE = input_state;
            break;
            
        case Input_Capture_5:
            IEC0bits.IC5IE = input_state;
            break;
            
        case Output_Compare_5:
            IEC0bits.OC5IE = input_state;
            break;
            
        case Timer6:
            IEC0bits.T6IE = input_state;
            break;
            
        case Input_Capture_6_Error:
            IEC0bits.IC6EIE = input_state;
            break;
            
        case Input_Capture_6:
            IEC0bits.IC6IE = input_state;
            break;
            
        case Output_Compare_6:
            IEC0bits.OC6IE = input_state;
            break;
            
        case Timer7:
            IEC1bits.T7IE = input_state;
            break;
            
        case Input_Capture_7_Error:
            IEC1bits.IC7EIE = input_state;
            break;
            
        case Input_Capture_7:
            IEC1bits.IC7IE = input_state;
            break;
            
        case Output_Compare_7:
            IEC1bits.OC7IE = input_state;
            break;
            
        case Timer8:
            IEC1bits.T8IE = input_state;
            break;
            
        case Input_Capture_8_Error:
            IEC1bits.IC8EIE = input_state;
            break;
            
        case Input_Capture_8:
            IEC1bits.IC8IE = input_state;
            break;
            
        case Output_Compare_8:
            IEC1bits.OC8IE = input_state;
            break;
            
        case Timer9:
            IEC1bits.T9IE = input_state;
            break;
            
        case Input_Capture_9_Error:
            IEC1bits.IC9EIE = input_state;
            break;
            
        case Input_Capture_9:
            IEC1bits.IC9IE = input_state;
            break;
            
        case Output_Compare_9:
            IEC1bits.OC9IE = input_state;
            break;
            
        case ADC_Global_Interrupt:
            IEC1bits.ADCIE = input_state;
            break;
            
        case ADC_FIFO_Data_Ready_Interrupt:
            IEC1bits.ADCFIFOIE = input_state;
            break;
            
        case ADC_Digital_Comparator_1:
            IEC1bits.ADCDC1IE = input_state;
            break;
        
        case ADC_Digital_Comparator_2:
            IEC1bits.ADCDC2IE = input_state;
            break;
            
        case ADC_Digital_Comparator_3:
            IEC1bits.ADCDC3IE = input_state;
            break;
            
        case ADC_Digital_Comparator_4:
            IEC1bits.ADCDC4IE = input_state;
            break;
            
        case ADC_Digital_Comparator_5:
            IEC1bits.ADCDC5IE = input_state;
            break;
            
        case ADC_Digital_Comparator_6:
            IEC1bits.ADCDC6IE = input_state;
            break;
            
        case ADC_Digital_Filter_1:
            IEC1bits.ADCDF1IE = input_state;
            break;
            
        case ADC_Digital_Filter_2:
            IEC1bits.ADCDF2IE = input_state;
            break;
            
        case ADC_Digital_Filter_3:
            IEC1bits.ADCDF3IE = input_state;
            break;
            
        case ADC_Digital_Filter_4:
            IEC1bits.ADCDF4IE = input_state;
            break;
            
        case ADC_Digital_Filter_5:
            IEC1bits.ADCDF5IE = input_state;
            break;
            
        case ADC_Digital_Filter_6:
            IEC1bits.ADCDF6IE = input_state;
            break;
            
        case ADC_Fault:
            IEC1bits.ADCFLTIE = input_state;
            break;
            
        case ADC_Data_0:
            IEC1bits.ADCD0IE = input_state;
            break;
            
        case ADC_Data_1:
            IEC1bits.ADCD1IE = input_state;
            break;
            
        case ADC_Data_2:
            IEC1bits.ADCD2IE = input_state;
            break;
            
        case ADC_Data_3:
            IEC1bits.ADCD3IE = input_state;
            break;
            
        case ADC_Data_4:
            IEC1bits.ADCD4IE = input_state;
            break;
            
        case ADC_Data_5:
            IEC2bits.ADCD5IE = input_state;
            break;
            
        case ADC_Data_6:
            IEC2bits.ADCD6IE = input_state;
            break;
            
        case ADC_Data_7:
            IEC2bits.ADCD7IE = input_state;
            break;
            
        case ADC_Data_8:
            IEC2bits.ADCD8IE = input_state;
            break;
            
        case ADC_Data_9:
            IEC2bits.ADCD9IE = input_state;
            break;
            
        case ADC_Data_10:
            IEC2bits.ADCD10IE = input_state;
            break;
            
        case ADC_Data_11:
            IEC2bits.ADCD11IE = input_state;
            break;
            
        case ADC_Data_12:
            IEC2bits.ADCD12IE = input_state;
            break;
            
        case ADC_Data_13:
            IEC2bits.ADCD13IE = input_state;
            break;
            
        case ADC_Data_14:
            IEC2bits.ADCD14IE = input_state;
            break;
            
        case ADC_Data_15:
            IEC2bits.ADCD15IE = input_state;
            break;
            
        case ADC_Data_16:
            IEC2bits.ADCD16IE = input_state;
            break;
            
        case ADC_Data_17:
            IEC2bits.ADCD17IE = input_state;
            break;
            
        case ADC_Data_18:
            IEC2bits.ADCD18IE = input_state;
            break;
            
        case ADC_Data_19:
            IEC2bits.ADCD19IE = input_state;
            break;
            
        case ADC_Data_20:
            IEC2bits.ADCD20IE = input_state;
            break;
            
        case ADC_Data_21:
            IEC2bits.ADCD21IE = input_state;
            break;
            
        case ADC_Data_22:
            IEC2bits.ADCD22IE = input_state;
            break;
            
        case ADC_Data_23:
            IEC2bits.ADCD23IE = input_state;
            break;
            
        case ADC_Data_24:
            IEC2bits.ADCD24IE = input_state;
            break;
            
        case ADC_Data_25:
            IEC2bits.ADCD25IE = input_state;
            break;
            
        case ADC_Data_26:
            IEC2bits.ADCD26IE = input_state;
            break;
            
        case ADC_Data_27:
            IEC2bits.ADCD27IE = input_state;
            break;
            
        case ADC_Data_28:
            IEC2bits.ADCD28IE = input_state;
            break;
            
        case ADC_Data_29:
            IEC2bits.ADCD29IE = input_state;
            break;
            
        case ADC_Data_30:
            IEC2bits.ADCD30IE = input_state;
            break;
            
        case ADC_Data_31:
            IEC2bits.ADCD31IE = input_state;
            break;
            
        case ADC_Data_32:
            IEC2bits.ADCD32IE = input_state;
            break;
            
        case ADC_Data_33:
            IEC2bits.ADCD33IE = input_state;
            break;
            
        case ADC_Data_34:
            IEC2bits.ADCD34IE = input_state;
            break;
            
        case ADC_Data_35:
            IEC2bits.ADCD35IE = input_state;
            break;
            
        case ADC_Data_36:
            IEC2bits.ADCD36IE = input_state;
            break;
            
        case ADC_Data_37:
            IEC3bits.ADCD37IE = input_state;
            break;
            
        case ADC_Data_38:
            IEC3bits.ADCD38IE = input_state;
            break;
            
        case ADC_Data_39:
            IEC3bits.ADCD39IE = input_state;
            break;
            
        case ADC_Data_40:
            IEC3bits.ADCD40IE = input_state;
            break;
            
        case ADC_Data_41:
            IEC3bits.ADCD41IE = input_state;
            break;
            
        case ADC_Data_42:
            IEC3bits.ADCD42IE = input_state;
            break;
            
        case ADC_Data_43:
            IEC3bits.ADCD43IE = input_state;
            break;
            
        case ADC_Data_44:
            IEC3bits.ADCD44IE = input_state;
            break;
            
        case Core_Performance_Counter_Interrupt:
            IEC3bits.CPCIE = input_state;
            break;
            
        case Core_Fast_Debug_Channel_Interrupt:
            IEC3bits.CFDCIE = input_state;
            break;
            
        case System_Bus_Protection_Violation:
            IEC3bits.SBIE = input_state;
            break;
            
        case SPI1_Fault:
            IEC3bits.SPI1EIE = input_state;
            break;
            
        case SPI1_Receive_Done:
            IEC3bits.SPI1RXIE = input_state;
            break;
            
        case SPI1_Transfer_Done:
            IEC3bits.SPI1TXIE = input_state;
            break;
            
        case UART1_Fault:
            IEC3bits.U1EIE = input_state;
            break;
            
        case UART1_Receive_Done:
            IEC3bits.U1RXIE = input_state;
            break;
            
        case UART1_Transfer_Done:
            IEC3bits.U1TXIE = input_state;
            break;
            
        case I2C1_Bus_Collision_Event:
            IEC3bits.I2C1BIE = input_state;
            break;
            
        case I2C1_Slave_Event:
            IEC3bits.I2C1SIE = input_state;
            break;
            
        case I2C1_Master_Event:
            IEC3bits.I2C1MIE = input_state;
            break;
            
        case PORTA_Input_Change_Interrupt:
            IEC3bits.CNAIE = input_state;
            break;
            
        case PORTB_Input_Change_Interrupt:
            IEC3bits.CNBIE = input_state;
            break;
            
        case PORTC_Input_Change_Interrupt:
            IEC3bits.CNCIE = input_state;
            break;
            
        case PORTD_Input_Change_Interrupt:
            IEC3bits.CNDIE = input_state;
            break;
            
        case PORTE_Input_Change_Interrupt:
            IEC3bits.CNEIE = input_state;
            break;
            
        case PORTF_Input_Change_Interrupt:
            IEC3bits.CNFIE = input_state;
            break;
            
        case PORTG_Input_Change_Interrupt:
            IEC3bits.CNGIE = input_state;
            break;
            
        case PORTH_Input_Change_Interrupt:
            IEC3bits.CNHIE = input_state;
            break;
            
        case PORTJ_Input_Change_Interrupt:
            IEC3bits.CNJIE = input_state;
            break;
            
        case PORTK_Input_Change_Interrupt:
            IEC3bits.CNKIE = input_state;
            break;
            
        case Parallel_Master_Port:
            IEC4bits.PMPIE = input_state;
            break;
            
        case Parallel_Master_Port_Error:
            IEC4bits.PMPEIE = input_state;
            break;
            
        case Comparator_1_Interrupt:
            IEC4bits.CMP1IE = input_state;
            break;
            
        case Comparator_2_Interrupt:
            IEC4bits.CMP2IE = input_state;
            break;
            
        case USB_General_Event:
            IEC4bits.USBIE = input_state;
            break;
            
        case USB_DMA_Event:
            IEC4bits.USBDMAIE = input_state;
            break;
            
        case DMA_Channel_0:
            IEC4bits.DMA0IE = input_state;
            break;
            
        case DMA_Channel_1:
            IEC4bits.DMA1IE = input_state;
            break;
            
        case DMA_Channel_2:
            IEC4bits.DMA2IE = input_state;
            break;
            
        case DMA_Channel_3:
            IEC4bits.DMA3IE = input_state;
            break;
            
        case DMA_Channel_4:
            IEC4bits.DMA4IE = input_state;
            break;
            
        case DMA_Channel_5:
            IEC4bits.DMA5IE = input_state;
            break;
            
        case DMA_Channel_6:
            IEC4bits.DMA6IE = input_state;
            break;
            
        case DMA_Channel_7:
            IEC4bits.DMA7IE = input_state;
            break;
            
        case SPI2_Fault:
            IEC4bits.SPI2EIE = input_state;
            break;
            
        case SPI2_Receive_Done:
            IEC4bits.SPI2RXIE = input_state;
            break;
            
        case SPI2_Transfer_Done:
            IEC4bits.SPI2TXIE = input_state;
            break;
            
        case UART2_Fault:
            IEC4bits.U2EIE = input_state;
            break;
            
        case UART2_Receive_Done:
            IEC4bits.U2RXIE = input_state;
            break;
            
        case UART2_Transfer_Done:
            IEC4bits.U2TXIE = input_state;
            break;
            
        case I2C2_Bus_Collision_Event:
            IEC4bits.I2C2BIE = input_state;
            break;
            
        case I2C2_Slave_Event:
            IEC4bits.I2C2SIE = input_state;
            break;
            
        case I2C2_Master_Event:
            IEC4bits.I2C2MIE = input_state;
            break;
            
        case Control_Area_Network_1:
            IEC4bits.CAN1IE = input_state;
            break;
                    
        case Control_Area_Network_2:
            IEC4bits.CAN2IE = input_state;
            break;
            
        case Ethernet_Interrupt:
            IEC4bits.ETHIE = input_state;
            break;
            
        case SPI3_Fault:
            IEC4bits.SPI3EIE = input_state;
            break;
            
        case SPI3_Receive_Done:
            IEC4bits.SPI3RXIE = input_state;
            break;
            
        case SPI3_Transfer_Done:
            IEC4bits.SPI3TXIE = input_state;
            break;
            
        case UART3_Fault:
            IEC4bits.U3EIE = input_state;
            break;
            
        case UART3_Receive_Done:
            IEC4bits.U3RXIE = input_state;
            break;
            
        case UART3_Transfer_Done:
            IEC4bits.U3TXIE = input_state;
            break;
            
        case I2C3_Bus_Collision_Event:
            IEC5bits.I2C3BIE = input_state;
            break;
            
        case I2C3_Slave_Event:
            IEC5bits.I2C3SIE = input_state;
            break;
            
        case I2C3_Master_Event:
            IEC5bits.I2C3MIE = input_state;
            break;
            
        case SPI4_Fault:
            IEC5bits.SPI5EIE = input_state;
            break;
            
        case SPI4_Receive_Done:
            IEC5bits.SPI4RXIE = input_state;
            break;
            
        case SPI4_Transfer_Done:
            IEC5bits.SPI4TXIE = input_state;
            break;
            
        case Real_Time_Clock:
            IEC5bits.RTCCIE = input_state;
            break;
            
        case Flash_Control_Event:
            IEC5bits.FCEIE = input_state;
            break;
            
        case Prefetch_Module_SEC_Event:
            IEC5bits.PREIE = input_state;
            break;
            
        case SQI1_Event:
            IEC5bits.SQI1IE = input_state;
            break;
            
        case UART4_Fault:
            IEC5bits.U4EIE = input_state;
            break;
            
        case UART4_Receive_Done:
            IEC5bits.U4RXIE = input_state;
            break;
            
        case UART4_Transfer_Done:
            IEC5bits.U4TXIE = input_state;
            break;
            
        case I2C4_Bus_Collision_Event:
            IEC5bits.I2C4BIE = input_state;
            break;
            
        case I2C4_Slave_Event:
            IEC5bits.I2C4SIE = input_state;
            break;
            
        case I2C4_Master_Event:
            IEC5bits.I2C4MIE = input_state;
            break;
            
        case SPI5_Fault:
            IEC5bits.SPI5EIE = input_state;
            break;
            
        case SPI5_Receive_Done:
            IEC5bits.SPI5RXIE = input_state;
            break;
            
        case SPI5_Transfer_Done:
            IEC5bits.SPI5TXIE = input_state;
            break;
            
        case UART5_Fault:
            IEC5bits.U5EIE = input_state;
            break;
            
        case UART5_Receive_Done:
            IEC5bits.U5RXIE = input_state;
            break;
            
        case UART5_Transfer_Done:
            IEC5bits.U5TXIE = input_state;
            break;
            
        case I2C5_Bus_Collision_Event:
            IEC5bits.I2C5BIE = input_state;
            break;
            
        case I2C5_Slave_Event:
            IEC5bits.I2C5SIE = input_state;
            break;
            
        case I2C5_Master_Event:
            IEC5bits.I2C5MIE = input_state;
            break;
        
        case SPI6_Fault:
            IEC5bits.SPI6IE = input_state;  // Error in microchip bitfield macro!!!
            break;
            
        case SPI6_Receive_Done:
            IEC5bits.SPI6RXIE = input_state;
            break;
            
        case SPI6_Transfer_Done:
            IEC5bits.SPI6TXIE = input_state;
            break;
            
        case UART6_Fault:
            IEC5bits.U6EIE = input_state;
            break;
            
        case UART6_Receive_Done:
            IEC5bits.U6RXIE = input_state;
            break;
            
        case UART6_Transfer_Done:
            IEC5bits.U6TXIE = input_state;
            break;
        
        case ADC_End_Of_Scan_Ready:
            IEC6bits.ADCEOSIE = input_state;
            break;
            
        case ADC_Analog_Circuits_Ready:
            IEC6bits.ADCARDYIE = input_state;
            break;
            
        case ADC_Update_Ready:
            IEC6bits.ADCURDYIE = input_state;
            break;
            
        case ADC_Group_Early_Interrupt_Request:
            IEC6bits.ADCGRPIE = input_state;
            break;
            
        case ADC0_Early_Interrupt:
            IEC6bits.ADC0EIE = input_state;
            break;
            
        case ADC1_Early_Interrupt:
            IEC6bits.ADC1EIE = input_state;
            break;
            
        case ADC2_Early_Interrupt:
            IEC6bits.ADC2EIE = input_state;
            break;
            
        case ADC3_Early_Interrupt:
            IEC6bits.ADC3EIE = input_state;
            break;
            
        case ADC4_Early_Interrupt:
            IEC6bits.ADC4EIE = input_state;
            break;
            
        case ADC7_Early_Interrupt:
            IEC6bits.ADC7EIE = input_state;
            break;
            
        case ADC0_Warm_Interrupt:
            IEC6bits.ADC0WIE = input_state;
            break;
            
        case ADC1_Warm_Interrupt:
            IEC6bits.ADC1WIE = input_state;
            break;
            
        case ADC2_Warm_Interrupt:
            IEC6bits.ADC2WIE = input_state;
            break;
            
        case ADC3_Warm_Interrupt:
            IEC6bits.ADC3WIE = input_state;
            break;
            
        case ADC4_Warm_Interrupt:
            IEC6bits.ADC4WIE = input_state;
            break;
            
        case ADC7_Warm_Interrupt:
            IEC6bits.ADC7WIE = input_state;
            break;
            
        default:
            break;
            
    }

}

// This function allows for the reading of a given interrupt enable
// It reads the interrupt's 'Interrupt Enable' bit with IEC registers
// Returns the state of the given interrupt
uint8_t getInterruptEnable(interrupt_source_t input_interrupt) {

    // Decide which interrupt control bits to manipulate based on which interrupt
    // is being enabled or disabled
    switch (input_interrupt) {
        
        case Core_Timer_Interrupt:
            return IEC0bits.CTIE;
            break;
            
        case Core_Software_Interrupt_0:
            return IEC0bits.CS0IE;
            break;
            
        case Core_Software_Interrupt_1:
            return IEC0bits.CS1IE;
            break;
            
        case External_Interrupt_0:
            return IEC0bits.INT0IE;
            break;
            
        case Timer1:
            return IEC0bits.T1IE;
            break;
            
        case Input_Capture_1_Error:
            return IEC0bits.IC1EIE;
            break;
            
        case Input_Capture_1:
            return IEC0bits.IC1IE;
            break;
            
        case Output_Compare_1:
            return IEC0bits.OC1IE;
            break;
            
        case External_Interrupt_1:
            return IEC0bits.INT1IE;
            break;
            
        case Timer2:
            return IEC0bits.T2IE;
            break;
            
        case Input_Capture_2_Error:
            return IEC0bits.IC2EIE;
            break;
            
        case Input_Capture_2:
            return IEC0bits.IC2IE;
            break;
            
        case Output_Compare_2:
            return IEC0bits.OC2IE;
            break;
            
        case External_Interrupt_2:
            return IEC0bits.INT2IE;
            break;
            
        case Timer3:
            return IEC0bits.T3IE;
            break;
            
        case Input_Capture_3_Error:
            return IEC0bits.IC3EIE;
            break;
            
        case Input_Capture_3:
            return IEC0bits.IC3IE;
            break;
            
        case Output_Compare_3:
            return IEC0bits.OC3IE;
            break;
            
        case External_Interrupt_3:
            return IEC0bits.INT3IE;
            break;
            
        case Timer4:
            return IEC0bits.T4IE;
            break;
            
        case Input_Capture_4_Error:
            return IEC0bits.IC4EIE;
            break;
            
        case Input_Capture_4:
            return IEC0bits.IC4IE;
            break;
            
        case Output_Compare_4:
            return IEC0bits.OC4IE;
            break;
            
        case External_Interrupt_4:
            return IEC0bits.INT4IE;
            break;
            
        case Timer5:
            return IEC0bits.T5IE;
            break;
            
        case Input_Capture_5_Error:
            return IEC0bits.IC5EIE;
            break;
            
        case Input_Capture_5:
            return IEC0bits.IC5IE;
            break;
            
        case Output_Compare_5:
            return IEC0bits.OC5IE;
            break;
            
        case Timer6:
            return IEC0bits.T6IE;
            break;
            
        case Input_Capture_6_Error:
            return IEC0bits.IC6EIE;
            break;
            
        case Input_Capture_6:
            return IEC0bits.IC6IE;
            break;
            
        case Output_Compare_6:
            return IEC0bits.OC6IE;
            break;
            
        case Timer7:
            return IEC1bits.T7IE;
            break;
            
        case Input_Capture_7_Error:
            return IEC1bits.IC7EIE;
            break;
            
        case Input_Capture_7:
            return IEC1bits.IC7IE;
            break;
            
        case Output_Compare_7:
            return IEC1bits.OC7IE;
            break;
            
        case Timer8:
            return IEC1bits.T8IE;
            break;
            
        case Input_Capture_8_Error:
            return IEC1bits.IC8EIE;
            break;
            
        case Input_Capture_8:
            return IEC1bits.IC8IE;
            break;
            
        case Output_Compare_8:
            return IEC1bits.OC8IE;
            break;
            
        case Timer9:
            return IEC1bits.T9IE;
            break;
            
        case Input_Capture_9_Error:
            return IEC1bits.IC9EIE;
            break;
            
        case Input_Capture_9:
            return IEC1bits.IC9IE;
            break;
            
        case Output_Compare_9:
            return IEC1bits.OC9IE;
            break;
            
        case ADC_Global_Interrupt:
            return IEC1bits.ADCIE;
            break;
            
        case ADC_FIFO_Data_Ready_Interrupt:
            return IEC1bits.ADCFIFOIE;
            break;
            
        case ADC_Digital_Comparator_1:
            return IEC1bits.ADCDC1IE;
            break;
        
        case ADC_Digital_Comparator_2:
            return IEC1bits.ADCDC2IE;
            break;
            
        case ADC_Digital_Comparator_3:
            return IEC1bits.ADCDC3IE;
            break;
            
        case ADC_Digital_Comparator_4:
            return IEC1bits.ADCDC4IE;
            break;
            
        case ADC_Digital_Comparator_5:
            return IEC1bits.ADCDC5IE;
            break;
            
        case ADC_Digital_Comparator_6:
            return IEC1bits.ADCDC6IE;
            break;
            
        case ADC_Digital_Filter_1:
            return IEC1bits.ADCDF1IE;
            break;
            
        case ADC_Digital_Filter_2:
            return IEC1bits.ADCDF2IE;
            break;
            
        case ADC_Digital_Filter_3:
            return IEC1bits.ADCDF3IE;
            break;
            
        case ADC_Digital_Filter_4:
            return IEC1bits.ADCDF4IE;
            break;
            
        case ADC_Digital_Filter_5:
            return IEC1bits.ADCDF5IE;
            break;
            
        case ADC_Digital_Filter_6:
            return IEC1bits.ADCDF6IE;
            break;
            
        case ADC_Fault:
            return IEC1bits.ADCFLTIE;
            break;
            
        case ADC_Data_0:
            return IEC1bits.ADCD0IE;
            break;
            
        case ADC_Data_1:
            return IEC1bits.ADCD1IE;
            break;
            
        case ADC_Data_2:
            return IEC1bits.ADCD2IE;
            break;
            
        case ADC_Data_3:
            return IEC1bits.ADCD3IE;
            break;
            
        case ADC_Data_4:
            return IEC1bits.ADCD4IE;
            break;
            
        case ADC_Data_5:
            return IEC2bits.ADCD5IE;
            break;
            
        case ADC_Data_6:
            return IEC2bits.ADCD6IE;
            break;
            
        case ADC_Data_7:
            return IEC2bits.ADCD7IE;
            break;
            
        case ADC_Data_8:
            return IEC2bits.ADCD8IE;
            break;
            
        case ADC_Data_9:
            return IEC2bits.ADCD9IE;
            break;
            
        case ADC_Data_10:
            return IEC2bits.ADCD10IE;
            break;
            
        case ADC_Data_11:
            return IEC2bits.ADCD11IE;
            break;
            
        case ADC_Data_12:
            return IEC2bits.ADCD12IE;
            break;
            
        case ADC_Data_13:
            return IEC2bits.ADCD13IE;
            break;
            
        case ADC_Data_14:
            return IEC2bits.ADCD14IE;
            break;
            
        case ADC_Data_15:
            return IEC2bits.ADCD15IE;
            break;
            
        case ADC_Data_16:
            return IEC2bits.ADCD16IE;
            break;
            
        case ADC_Data_17:
            return IEC2bits.ADCD17IE;
            break;
            
        case ADC_Data_18:
            return IEC2bits.ADCD18IE;
            break;
            
        case ADC_Data_19:
            return IEC2bits.ADCD19IE;
            break;
            
        case ADC_Data_20:
            return IEC2bits.ADCD20IE;
            break;
            
        case ADC_Data_21:
            return IEC2bits.ADCD21IE;
            break;
            
        case ADC_Data_22:
            return IEC2bits.ADCD22IE;
            break;
            
        case ADC_Data_23:
            return IEC2bits.ADCD23IE;
            break;
            
        case ADC_Data_24:
            return IEC2bits.ADCD24IE;
            break;
            
        case ADC_Data_25:
            return IEC2bits.ADCD25IE;
            break;
            
        case ADC_Data_26:
            return IEC2bits.ADCD26IE;
            break;
            
        case ADC_Data_27:
            return IEC2bits.ADCD27IE;
            break;
            
        case ADC_Data_28:
            return IEC2bits.ADCD28IE;
            break;
            
        case ADC_Data_29:
            return IEC2bits.ADCD29IE;
            break;
            
        case ADC_Data_30:
            return IEC2bits.ADCD30IE;
            break;
            
        case ADC_Data_31:
            return IEC2bits.ADCD31IE;
            break;
            
        case ADC_Data_32:
            return IEC2bits.ADCD32IE;
            break;
            
        case ADC_Data_33:
            return IEC2bits.ADCD33IE;
            break;
            
        case ADC_Data_34:
            return IEC2bits.ADCD34IE;
            break;
            
        case ADC_Data_35:
            return IEC2bits.ADCD35IE;
            break;
            
        case ADC_Data_36:
            return IEC2bits.ADCD36IE;
            break;
            
        case ADC_Data_37:
            return IEC3bits.ADCD37IE;
            break;
            
        case ADC_Data_38:
            return IEC3bits.ADCD38IE;
            break;
            
        case ADC_Data_39:
            return IEC3bits.ADCD39IE;
            break;
            
        case ADC_Data_40:
            return IEC3bits.ADCD40IE;
            break;
            
        case ADC_Data_41:
            return IEC3bits.ADCD41IE;
            break;
            
        case ADC_Data_42:
            return IEC3bits.ADCD42IE;
            break;
            
        case ADC_Data_43:
            return IEC3bits.ADCD43IE;
            break;
            
        case ADC_Data_44:
            return IEC3bits.ADCD44IE;
            break;
            
        case Core_Performance_Counter_Interrupt:
            return IEC3bits.CPCIE;
            break;
            
        case Core_Fast_Debug_Channel_Interrupt:
            return IEC3bits.CFDCIE;
            break;
            
        case System_Bus_Protection_Violation:
            return IEC3bits.SBIE;
            break;
            
        case SPI1_Fault:
            return IEC3bits.SPI1EIE;
            break;
            
        case SPI1_Receive_Done:
            return IEC3bits.SPI1RXIE;
            break;
            
        case SPI1_Transfer_Done:
            return IEC3bits.SPI1TXIE;
            break;
            
        case UART1_Fault:
            return IEC3bits.U1EIE;
            break;
            
        case UART1_Receive_Done:
            return IEC3bits.U1RXIE;
            break;
            
        case UART1_Transfer_Done:
            return IEC3bits.U1TXIE;
            break;
            
        case I2C1_Bus_Collision_Event:
            return IEC3bits.I2C1BIE;
            break;
            
        case I2C1_Slave_Event:
            return IEC3bits.I2C1SIE;
            break;
            
        case I2C1_Master_Event:
            return IEC3bits.I2C1MIE;
            break;
            
        case PORTA_Input_Change_Interrupt:
            return IEC3bits.CNAIE;
            break;
            
        case PORTB_Input_Change_Interrupt:
            return IEC3bits.CNBIE;
            break;
            
        case PORTC_Input_Change_Interrupt:
            return IEC3bits.CNCIE;
            break;
            
        case PORTD_Input_Change_Interrupt:
            return IEC3bits.CNDIE;
            break;
            
        case PORTE_Input_Change_Interrupt:
            return IEC3bits.CNEIE;
            break;
            
        case PORTF_Input_Change_Interrupt:
            return IEC3bits.CNFIE;
            break;
            
        case PORTG_Input_Change_Interrupt:
            return IEC3bits.CNGIE;
            break;
            
        case PORTH_Input_Change_Interrupt:
            return IEC3bits.CNHIE;
            break;
            
        case PORTJ_Input_Change_Interrupt:
            return IEC3bits.CNJIE;
            break;
            
        case PORTK_Input_Change_Interrupt:
            return IEC3bits.CNKIE;
            break;
            
        case Parallel_Master_Port:
            return IEC4bits.PMPIE;
            break;
            
        case Parallel_Master_Port_Error:
            return IEC4bits.PMPEIE;
            break;
            
        case Comparator_1_Interrupt:
            return IEC4bits.CMP1IE;
            break;
            
        case Comparator_2_Interrupt:
            return IEC4bits.CMP2IE;
            break;
            
        case USB_General_Event:
            return IEC4bits.USBIE;
            break;
            
        case USB_DMA_Event:
            return IEC4bits.USBDMAIE;
            break;
            
        case DMA_Channel_0:
            return IEC4bits.DMA0IE;
            break;
            
        case DMA_Channel_1:
            return IEC4bits.DMA1IE;
            break;
            
        case DMA_Channel_2:
            return IEC4bits.DMA2IE;
            break;
            
        case DMA_Channel_3:
            return IEC4bits.DMA3IE;
            break;
            
        case DMA_Channel_4:
            return IEC4bits.DMA4IE;
            break;
            
        case DMA_Channel_5:
            return IEC4bits.DMA5IE;
            break;
            
        case DMA_Channel_6:
            return IEC4bits.DMA6IE;
            break;
            
        case DMA_Channel_7:
            return IEC4bits.DMA7IE;
            break;
            
        case SPI2_Fault:
            return IEC4bits.SPI2EIE;
            break;
            
        case SPI2_Receive_Done:
            return IEC4bits.SPI2RXIE;
            break;
            
        case SPI2_Transfer_Done:
            return IEC4bits.SPI2TXIE;
            break;
            
        case UART2_Fault:
            return IEC4bits.U2EIE;
            break;
            
        case UART2_Receive_Done:
            return IEC4bits.U2RXIE;
            break;
            
        case UART2_Transfer_Done:
            return IEC4bits.U2TXIE;
            break;
            
        case I2C2_Bus_Collision_Event:
            return IEC4bits.I2C2BIE;
            break;
            
        case I2C2_Slave_Event:
            return IEC4bits.I2C2SIE;
            break;
            
        case I2C2_Master_Event:
            return IEC4bits.I2C2MIE;
            break;
            
        case Control_Area_Network_1:
            return IEC4bits.CAN1IE;
            break;
                    
        case Control_Area_Network_2:
            return IEC4bits.CAN2IE;
            break;
            
        case Ethernet_Interrupt:
            return IEC4bits.ETHIE;
            break;
            
        case SPI3_Fault:
            return IEC4bits.SPI3EIE;
            break;
            
        case SPI3_Receive_Done:
            return IEC4bits.SPI3RXIE;
            break;
            
        case SPI3_Transfer_Done:
            return IEC4bits.SPI3TXIE;
            break;
            
        case UART3_Fault:
            return IEC4bits.U3EIE;
            break;
            
        case UART3_Receive_Done:
            return IEC4bits.U3RXIE;
            break;
            
        case UART3_Transfer_Done:
            return IEC4bits.U3TXIE;
            break;
            
        case I2C3_Bus_Collision_Event:
            return IEC5bits.I2C3BIE;
            break;
            
        case I2C3_Slave_Event:
            return IEC5bits.I2C3SIE;
            break;
            
        case I2C3_Master_Event:
            return IEC5bits.I2C3MIE;
            break;
            
        case SPI4_Fault:
            return IEC5bits.SPI5EIE;
            break;
            
        case SPI4_Receive_Done:
            return IEC5bits.SPI4RXIE;
            break;
            
        case SPI4_Transfer_Done:
            return IEC5bits.SPI4TXIE;
            break;
            
        case Real_Time_Clock:
            return IEC5bits.RTCCIE;
            break;
            
        case Flash_Control_Event:
            return IEC5bits.FCEIE;
            break;
            
        case Prefetch_Module_SEC_Event:
            return IEC5bits.PREIE;
            break;
            
        case SQI1_Event:
            return IEC5bits.SQI1IE;
            break;
            
        case UART4_Fault:
            return IEC5bits.U4EIE;
            break;
            
        case UART4_Receive_Done:
            return IEC5bits.U4RXIE;
            break;
            
        case UART4_Transfer_Done:
            return IEC5bits.U4TXIE;
            break;
            
        case I2C4_Bus_Collision_Event:
            return IEC5bits.I2C4BIE;
            break;
            
        case I2C4_Slave_Event:
            return IEC5bits.I2C4SIE;
            break;
            
        case I2C4_Master_Event:
            return IEC5bits.I2C4MIE;
            break;
            
        case SPI5_Fault:
            return IEC5bits.SPI5EIE;
            break;
            
        case SPI5_Receive_Done:
            return IEC5bits.SPI5RXIE;
            break;
            
        case SPI5_Transfer_Done:
            return IEC5bits.SPI5TXIE;
            break;
            
        case UART5_Fault:
            return IEC5bits.U5EIE;
            break;
            
        case UART5_Receive_Done:
            return IEC5bits.U5RXIE;
            break;
            
        case UART5_Transfer_Done:
            return IEC5bits.U5TXIE;
            break;
            
        case I2C5_Bus_Collision_Event:
            return IEC5bits.I2C5BIE;
            break;
            
        case I2C5_Slave_Event:
            return IEC5bits.I2C5SIE;
            break;
            
        case I2C5_Master_Event:
            return IEC5bits.I2C5MIE;
            break;
        
        case SPI6_Fault:
            return IEC5bits.SPI6IE;  // Error in microchip bitfield macro!!!
            break;
            
        case SPI6_Receive_Done:
            return IEC5bits.SPI6RXIE;
            break;
            
        case SPI6_Transfer_Done:
            return IEC5bits.SPI6TXIE;
            break;
            
        case UART6_Fault:
            return IEC5bits.U6EIE;
            break;
            
        case UART6_Receive_Done:
            return IEC5bits.U6RXIE;
            break;
            
        case UART6_Transfer_Done:
            return IEC5bits.U6TXIE;
            break;
        
        case ADC_End_Of_Scan_Ready:
            return IEC6bits.ADCEOSIE;
            break;
            
        case ADC_Analog_Circuits_Ready:
            return IEC6bits.ADCARDYIE;
            break;
            
        case ADC_Update_Ready:
            return IEC6bits.ADCURDYIE;
            break;
            
        case ADC_Group_Early_Interrupt_Request:
            return IEC6bits.ADCGRPIE;
            break;
            
        case ADC0_Early_Interrupt:
            return IEC6bits.ADC0EIE;
            break;
            
        case ADC1_Early_Interrupt:
            return IEC6bits.ADC1EIE;
            break;
            
        case ADC2_Early_Interrupt:
            return IEC6bits.ADC2EIE;
            break;
            
        case ADC3_Early_Interrupt:
            return IEC6bits.ADC3EIE;
            break;
            
        case ADC4_Early_Interrupt:
            return IEC6bits.ADC4EIE;
            break;
            
        case ADC7_Early_Interrupt:
            return IEC6bits.ADC7EIE;
            break;
            
        case ADC0_Warm_Interrupt:
            return IEC6bits.ADC0WIE;
            break;
            
        case ADC1_Warm_Interrupt:
            return IEC6bits.ADC1WIE;
            break;
            
        case ADC2_Warm_Interrupt:
            return IEC6bits.ADC2WIE;
            break;
            
        case ADC3_Warm_Interrupt:
            return IEC6bits.ADC3WIE;
            break;
            
        case ADC4_Warm_Interrupt:
            return IEC6bits.ADC4WIE;
            break;
            
        case ADC7_Warm_Interrupt:
            return IEC6bits.ADC7WIE;
            break;
            
        default:
            return 0;
            break;
                   
    }
    
}


// This function allows for the setting/clearing of a given interrupt flag
// It manipulates the interrupt's 'Interrupt Flag' bit
// Returns 0 if no errors
// Returns 1 if errors
void setInterruptFlag(interrupt_source_t input_interrupt, uint8_t input_state) {
 
    // Mask off anything larger than 1 to 1
    // input_state = input_state >= 1;
    
    // Decide which interrupt control bits to manipulate based on which interrupt
    // is being enabled or disabled
    switch (input_interrupt) {
        
        case Core_Timer_Interrupt:
            IFS0bits.CTIF = input_state;
            break;
            
        case Core_Software_Interrupt_0:
            IFS0bits.CS0IF = input_state;
            break;
            
        case Core_Software_Interrupt_1:
            IFS0bits.CS1IF = input_state;
            break;
            
        case External_Interrupt_0:
            IFS0bits.INT0IF = input_state;
            break;
            
        case Timer1:
            IFS0bits.T1IF = input_state;
            break;
            
        case Input_Capture_1_Error:
            IFS0bits.IC1EIF = input_state;
            break;
            
        case Input_Capture_1:
            IFS0bits.IC1IF = input_state;
            break;
            
        case Output_Compare_1:
            IFS0bits.OC1IF = input_state;
            break;
            
        case External_Interrupt_1:
            IFS0bits.INT1IF = input_state;
            break;
            
        case Timer2:
            IFS0bits.T2IF = input_state;
            break;
            
        case Input_Capture_2_Error:
            IFS0bits.IC2EIF = input_state;
            break;
            
        case Input_Capture_2:
            IFS0bits.IC2IF = input_state;
            break;
            
        case Output_Compare_2:
            IFS0bits.OC2IF = input_state;
            break;
            
        case External_Interrupt_2:
            IFS0bits.INT2IF = input_state;
            break;
            
        case Timer3:
            IFS0bits.T3IF = input_state;
            break;
            
        case Input_Capture_3_Error:
            IFS0bits.IC3EIF = input_state;
            break;
            
        case Input_Capture_3:
            IFS0bits.IC3IF = input_state;
            break;
            
        case Output_Compare_3:
            IFS0bits.OC3IF = input_state;
            break;
            
        case External_Interrupt_3:
            IFS0bits.INT3IF = input_state;
            break;
            
        case Timer4:
            IFS0bits.T4IF = input_state;
            break;
            
        case Input_Capture_4_Error:
            IFS0bits.IC4EIF = input_state;
            break;
            
        case Input_Capture_4:
            IFS0bits.IC4IF = input_state;
            break;
            
        case Output_Compare_4:
            IFS0bits.OC4IF = input_state;
            break;
            
        case External_Interrupt_4:
            IFS0bits.INT4IF = input_state;
            break;
            
        case Timer5:
            IFS0bits.T5IF = input_state;
            break;
            
        case Input_Capture_5_Error:
            IFS0bits.IC5EIF = input_state;
            break;
            
        case Input_Capture_5:
            IFS0bits.IC5IF = input_state;
            break;
            
        case Output_Compare_5:
            IFS0bits.OC5IF = input_state;
            break;
            
        case Timer6:
            IFS0bits.T6IF = input_state;
            break;
            
        case Input_Capture_6_Error:
            IFS0bits.IC6EIF = input_state;
            break;
            
        case Input_Capture_6:
            IFS0bits.IC6IF = input_state;
            break;
            
        case Output_Compare_6:
            IFS0bits.OC6IF = input_state;
            break;
            
        case Timer7:
            IFS1bits.T7IF = input_state;
            break;
            
        case Input_Capture_7_Error:
            IFS1bits.IC7EIF = input_state;
            break;
            
        case Input_Capture_7:
            IFS1bits.IC7IF = input_state;
            break;
            
        case Output_Compare_7:
            IFS1bits.OC7IF = input_state;
            break;
            
        case Timer8:
            IFS1bits.T8IF = input_state;
            break;
            
        case Input_Capture_8_Error:
            IFS1bits.IC8EIF = input_state;
            break;
            
        case Input_Capture_8:
            IFS1bits.IC8IF = input_state;
            break;
            
        case Output_Compare_8:
            IFS1bits.OC8IF = input_state;
            break;
            
        case Timer9:
            IFS1bits.T9IF = input_state;
            break;
            
        case Input_Capture_9_Error:
            IFS1bits.IC9EIF = input_state;
            break;
            
        case Input_Capture_9:
            IFS1bits.IC9IF = input_state;
            break;
            
        case Output_Compare_9:
            IFS1bits.OC9IF = input_state;
            break;
            
        case ADC_Global_Interrupt:
            IFS1bits.ADCIF = input_state;
            break;
            
        case ADC_FIFO_Data_Ready_Interrupt:
            IFS1bits.ADCFIFOIF = input_state;
            break;
            
        case ADC_Digital_Comparator_1:
            IFS1bits.ADCDC1IF = input_state;
            break;
        
        case ADC_Digital_Comparator_2:
            IFS1bits.ADCDC2IF = input_state;
            break;
            
        case ADC_Digital_Comparator_3:
            IFS1bits.ADCDC3IF = input_state;
            break;
            
        case ADC_Digital_Comparator_4:
            IFS1bits.ADCDC4IF = input_state;
            break;
            
        case ADC_Digital_Comparator_5:
            IFS1bits.ADCDC5IF = input_state;
            break;
            
        case ADC_Digital_Comparator_6:
            IFS1bits.ADCDC6IF = input_state;
            break;
            
        case ADC_Digital_Filter_1:
            IFS1bits.ADCDF1IF = input_state;
            break;
            
        case ADC_Digital_Filter_2:
            IFS1bits.ADCDF2IF = input_state;
            break;
            
        case ADC_Digital_Filter_3:
            IFS1bits.ADCDF3IF = input_state;
            break;
            
        case ADC_Digital_Filter_4:
            IFS1bits.ADCDF4IF = input_state;
            break;
            
        case ADC_Digital_Filter_5:
            IFS1bits.ADCDF5IF = input_state;
            break;
            
        case ADC_Digital_Filter_6:
            IFS1bits.ADCDF6IF = input_state;
            break;
            
        case ADC_Fault:
            IFS1bits.ADCFLTIF = input_state;
            break;
            
        case ADC_Data_0:
            IFS1bits.ADCD0IF = input_state;
            break;
            
        case ADC_Data_1:
            IFS1bits.ADCD1IF = input_state;
            break;
            
        case ADC_Data_2:
            IFS1bits.ADCD2IF = input_state;
            break;
            
        case ADC_Data_3:
            IFS1bits.ADCD3IF = input_state;
            break;
            
        case ADC_Data_4:
            IFS1bits.ADCD4IF = input_state;
            break;
            
        case ADC_Data_5:
            IFS2bits.ADCD5IF = input_state;
            break;
            
        case ADC_Data_6:
            IFS2bits.ADCD6IF = input_state;
            break;
            
        case ADC_Data_7:
            IFS2bits.ADCD7IF = input_state;
            break;
            
        case ADC_Data_8:
            IFS2bits.ADCD8IF = input_state;
            break;
            
        case ADC_Data_9:
            IFS2bits.ADCD9IF = input_state;
            break;
            
        case ADC_Data_10:
            IFS2bits.ADCD10IF = input_state;
            break;
            
        case ADC_Data_11:
            IFS2bits.ADCD11IF = input_state;
            break;
            
        case ADC_Data_12:
            IFS2bits.ADCD12IF = input_state;
            break;
            
        case ADC_Data_13:
            IFS2bits.ADCD13IF = input_state;
            break;
            
        case ADC_Data_14:
            IFS2bits.ADCD14IF = input_state;
            break;
            
        case ADC_Data_15:
            IFS2bits.ADCD15IF = input_state;
            break;
            
        case ADC_Data_16:
            IFS2bits.ADCD16IF = input_state;
            break;
            
        case ADC_Data_17:
            IFS2bits.ADCD17IF = input_state;
            break;
            
        case ADC_Data_18:
            IFS2bits.ADCD18IF = input_state;
            break;
            
        case ADC_Data_19:
            IFS2bits.ADCD19IF = input_state;
            break;
            
        case ADC_Data_20:
            IFS2bits.ADCD20IF = input_state;
            break;
            
        case ADC_Data_21:
            IFS2bits.ADCD21IF = input_state;
            break;
            
        case ADC_Data_22:
            IFS2bits.ADCD22IF = input_state;
            break;
            
        case ADC_Data_23:
            IFS2bits.ADCD23IF = input_state;
            break;
            
        case ADC_Data_24:
            IFS2bits.ADCD24IF = input_state;
            break;
            
        case ADC_Data_25:
            IFS2bits.ADCD25IF = input_state;
            break;
            
        case ADC_Data_26:
            IFS2bits.ADCD26IF = input_state;
            break;
            
        case ADC_Data_27:
            IFS2bits.ADCD27IF = input_state;
            break;
            
        case ADC_Data_28:
            IFS2bits.ADCD28IF = input_state;
            break;
            
        case ADC_Data_29:
            IFS2bits.ADCD29IF = input_state;
            break;
            
        case ADC_Data_30:
            IFS2bits.ADCD30IF = input_state;
            break;
            
        case ADC_Data_31:
            IFS2bits.ADCD31IF = input_state;
            break;
            
        case ADC_Data_32:
            IFS2bits.ADCD32IF = input_state;
            break;
            
        case ADC_Data_33:
            IFS2bits.ADCD33IF = input_state;
            break;
            
        case ADC_Data_34:
            IFS2bits.ADCD34IF = input_state;
            break;
            
        case ADC_Data_35:
            IFS2bits.ADCD35IF = input_state;
            break;
            
        case ADC_Data_36:
            IFS2bits.ADCD36IF = input_state;
            break;
            
        case ADC_Data_37:
            IFS3bits.ADCD37IF = input_state;
            break;
            
        case ADC_Data_38:
            IFS3bits.ADCD38IF = input_state;
            break;
            
        case ADC_Data_39:
            IFS3bits.ADCD39IF = input_state;
            break;
            
        case ADC_Data_40:
            IFS3bits.ADCD40IF = input_state;
            break;
            
        case ADC_Data_41:
            IFS3bits.ADCD41IF = input_state;
            break;
            
        case ADC_Data_42:
            IFS3bits.ADCD42IF = input_state;
            break;
            
        case ADC_Data_43:
            IFS3bits.ADCD43IF = input_state;
            break;
            
        case ADC_Data_44:
            IFS3bits.ADCD44IF = input_state;
            break;
            
        case Core_Performance_Counter_Interrupt:
            IFS3bits.CPCIF = input_state;
            break;
            
        case Core_Fast_Debug_Channel_Interrupt:
            IFS3bits.CFDCIF = input_state;
            break;
            
        case System_Bus_Protection_Violation:
            IFS3bits.SBIF = input_state;
            break;
            
        case SPI1_Fault:
            IFS3bits.SPI1EIF = input_state;
            break;
            
        case SPI1_Receive_Done:
            IFS3bits.SPI1RXIF = input_state;
            break;
            
        case SPI1_Transfer_Done:
            IFS3bits.SPI1TXIF = input_state;
            break;
            
        case UART1_Fault:
            IFS3bits.U1EIF = input_state;
            break;
            
        case UART1_Receive_Done:
            IFS3bits.U1RXIF = input_state;
            break;
            
        case UART1_Transfer_Done:
            IFS3bits.U1TXIF = input_state;
            break;
            
        case I2C1_Bus_Collision_Event:
            IFS3bits.I2C1BIF = input_state;
            break;
            
        case I2C1_Slave_Event:
            IFS3bits.I2C1SIF = input_state;
            break;
            
        case I2C1_Master_Event:
            IFS3bits.I2C1MIF = input_state;
            break;
            
        case PORTA_Input_Change_Interrupt:
            IFS3bits.CNAIF = input_state;
            break;
            
        case PORTB_Input_Change_Interrupt:
            IFS3bits.CNBIF = input_state;
            break;
            
        case PORTC_Input_Change_Interrupt:
            IFS3bits.CNCIF = input_state;
            break;
            
        case PORTD_Input_Change_Interrupt:
            IFS3bits.CNDIF = input_state;
            break;
            
        case PORTE_Input_Change_Interrupt:
            IFS3bits.CNEIF = input_state;
            break;
            
        case PORTF_Input_Change_Interrupt:
            IFS3bits.CNFIF = input_state;
            break;
            
        case PORTG_Input_Change_Interrupt:
            IFS3bits.CNGIF = input_state;
            break;
            
        case PORTH_Input_Change_Interrupt:
            IFS3bits.CNHIF = input_state;
            break;
            
        case PORTJ_Input_Change_Interrupt:
            IFS3bits.CNJIF = input_state;
            break;
            
        case PORTK_Input_Change_Interrupt:
            IFS3bits.CNKIF = input_state;
            break;
            
        case Parallel_Master_Port:
            IFS4bits.PMPIF = input_state;
            break;
            
        case Parallel_Master_Port_Error:
            IFS4bits.PMPEIF = input_state;
            break;
            
        case Comparator_1_Interrupt:
            IFS4bits.CMP1IF = input_state;
            break;
            
        case Comparator_2_Interrupt:
            IFS4bits.CMP2IF = input_state;
            break;
            
        case USB_General_Event:
            IFS4bits.USBIF = input_state;
            break;
            
        case USB_DMA_Event:
            IFS4bits.USBDMAIF = input_state;
            break;
            
        case DMA_Channel_0:
            IFS4bits.DMA0IF = input_state;
            break;
            
        case DMA_Channel_1:
            IFS4bits.DMA1IF = input_state;
            break;
            
        case DMA_Channel_2:
            IFS4bits.DMA2IF = input_state;
            break;
            
        case DMA_Channel_3:
            IFS4bits.DMA3IF = input_state;
            break;
            
        case DMA_Channel_4:
            IFS4bits.DMA4IF = input_state;
            break;
            
        case DMA_Channel_5:
            IFS4bits.DMA5IF = input_state;
            break;
            
        case DMA_Channel_6:
            IFS4bits.DMA6IF = input_state;
            break;
            
        case DMA_Channel_7:
            IFS4bits.DMA7IF = input_state;
            break;
            
        case SPI2_Fault:
            IFS4bits.SPI2EIF = input_state;
            break;
            
        case SPI2_Receive_Done:
            IFS4bits.SPI2RXIF = input_state;
            break;
            
        case SPI2_Transfer_Done:
            IFS4bits.SPI2TXIF = input_state;
            break;
            
        case UART2_Fault:
            IFS4bits.U2EIF = input_state;
            break;
            
        case UART2_Receive_Done:
            IFS4bits.U2RXIF = input_state;
            break;
            
        case UART2_Transfer_Done:
            IFS4bits.U2TXIF = input_state;
            break;
            
        case I2C2_Bus_Collision_Event:
            IFS4bits.I2C2BIF = input_state;
            break;
            
        case I2C2_Slave_Event:
            IFS4bits.I2C2SIF = input_state;
            break;
            
        case I2C2_Master_Event:
            IFS4bits.I2C2MIF = input_state;
            break;
            
        case Control_Area_Network_1:
            IFS4bits.CAN1IF = input_state;
            break;
                    
        case Control_Area_Network_2:
            IFS4bits.CAN2IF = input_state;
            break;
            
        case Ethernet_Interrupt:
            IFS4bits.ETHIF = input_state;
            break;
            
        case SPI3_Fault:
            IFS4bits.SPI3EIF = input_state;
            break;
            
        case SPI3_Receive_Done:
            IFS4bits.SPI3RXIF = input_state;
            break;
            
        case SPI3_Transfer_Done:
            IFS4bits.SPI3TXIF = input_state;
            break;
            
        case UART3_Fault:
            IFS4bits.U3EIF = input_state;
            break;
            
        case UART3_Receive_Done:
            IFS4bits.U3RXIF = input_state;
            break;
            
        case UART3_Transfer_Done:
            IFS4bits.U3TXIF = input_state;
            break;
            
        case I2C3_Bus_Collision_Event:
            IFS5bits.I2C3BIF = input_state;
            break;
            
        case I2C3_Slave_Event:
            IFS5bits.I2C3SIF = input_state;
            break;
            
        case I2C3_Master_Event:
            IFS5bits.I2C3MIF = input_state;
            break;
            
        case SPI4_Fault:
            IFS5bits.SPI5EIF = input_state;
            break;
            
        case SPI4_Receive_Done:
            IFS5bits.SPI4RXIF = input_state;
            break;
            
        case SPI4_Transfer_Done:
            IFS5bits.SPI4TXIF = input_state;
            break;
            
        case Real_Time_Clock:
            IFS5bits.RTCCIF = input_state;
            break;
            
        case Flash_Control_Event:
            IFS5bits.FCEIF = input_state;
            break;
            
        case Prefetch_Module_SEC_Event:
            IFS5bits.PREIF = input_state;
            break;
            
        case SQI1_Event:
            IFS5bits.SQI1IF = input_state;
            break;
            
        case UART4_Fault:
            IFS5bits.U4EIF = input_state;
            break;
            
        case UART4_Receive_Done:
            IFS5bits.U4RXIF = input_state;
            break;
            
        case UART4_Transfer_Done:
            IFS5bits.U4TXIF = input_state;
            break;
            
        case I2C4_Bus_Collision_Event:
            IFS5bits.I2C4BIF = input_state;
            break;
            
        case I2C4_Slave_Event:
            IFS5bits.I2C4SIF = input_state;
            break;
            
        case I2C4_Master_Event:
            IFS5bits.I2C4MIF = input_state;
            break;
            
        case SPI5_Fault:
            IFS5bits.SPI5EIF = input_state;
            break;
            
        case SPI5_Receive_Done:
            IFS5bits.SPI5RXIF = input_state;
            break;
            
        case SPI5_Transfer_Done:
            IFS5bits.SPI5TXIF = input_state;
            break;
            
        case UART5_Fault:
            IFS5bits.U5EIF = input_state;
            break;
            
        case UART5_Receive_Done:
            IFS5bits.U5RXIF = input_state;
            break;
            
        case UART5_Transfer_Done:
            IFS5bits.U5TXIF = input_state;
            break;
            
        case I2C5_Bus_Collision_Event:
            IFS5bits.I2C5BIF = input_state;
            break;
            
        case I2C5_Slave_Event:
            IFS5bits.I2C5SIF = input_state;
            break;
            
        case I2C5_Master_Event:
            IFS5bits.I2C5MIF = input_state;
            break;
        
        case SPI6_Fault:
            IFS5bits.SPI6IF = input_state;  // Error in microchip bitfield macro!!!
            break;
            
        case SPI6_Receive_Done:
            IFS5bits.SPI6RXIF = input_state;
            break;
            
        case SPI6_Transfer_Done:
            IFS5bits.SPI6TX = input_state;  // Error in microchip bitfield macro!!!
            break;
            
        case UART6_Fault:
            IFS5bits.U6EIF = input_state;
            break;
            
        case UART6_Receive_Done:
            IFS5bits.U6RXIF = input_state;
            break;
            
        case UART6_Transfer_Done:
            IFS5bits.U6TXIF = input_state;
            break;
        
        case ADC_End_Of_Scan_Ready:
            IFS6bits.ADCEOSIF = input_state;
            break;
            
        case ADC_Analog_Circuits_Ready:
            IFS6bits.ADCARDYIF = input_state;
            break;
            
        case ADC_Update_Ready:
            IFS6bits.ADCURDYIF = input_state;
            break;
            
        case ADC_Group_Early_Interrupt_Request:
            IFS6bits.ADCGRPIF = input_state;
            break;
            
        case ADC0_Early_Interrupt:
            IFS6bits.ADC0EIF = input_state;
            break;
            
        case ADC1_Early_Interrupt:
            IFS6bits.ADC1EIF = input_state;
            break;
            
        case ADC2_Early_Interrupt:
            IFS6bits.ADC2EIF = input_state;
            break;
            
        case ADC3_Early_Interrupt:
            IFS6bits.ADC3EIF = input_state;
            break;
            
        case ADC4_Early_Interrupt:
            IFS6bits.ADC4EIF = input_state;
            break;
            
        case ADC7_Early_Interrupt:
            IFS6bits.ADC7EIF = input_state;
            break;
            
        case ADC0_Warm_Interrupt:
            IFS6bits.ADC0WIF = input_state;
            break;
            
        case ADC1_Warm_Interrupt:
            IFS6bits.ADC1WIF = input_state;
            break;
            
        case ADC2_Warm_Interrupt:
            IFS6bits.ADC2WIF = input_state;
            break;
            
        case ADC3_Warm_Interrupt:
            IFS6bits.ADC3WIF = input_state;
            break;
            
        case ADC4_Warm_Interrupt:
            IFS6bits.ADC4WIF = input_state;
            break;
            
        case ADC7_Warm_Interrupt:
            IFS6bits.ADC7WIF = input_state;
            break;
            
        default:
            break;
            
    }

}

// This function allows for the reading of a given interrupt flag
// It reads the interrupt's 'Interrupt Flag' bit
// Returns the state of the given interrupt flag
uint8_t getInterruptFlag(interrupt_source_t input_interrupt) {
    
    // Decide which interrupt control bits to manipulate based on which interrupt
    // is being enabled or disabled
    switch (input_interrupt) {
        
        case Core_Timer_Interrupt:
            return IFS0bits.CTIF;
            break;
            
        case Core_Software_Interrupt_0:
            return IFS0bits.CS0IF;
            break;
            
        case Core_Software_Interrupt_1:
            return IFS0bits.CS1IF;
            break;
            
        case External_Interrupt_0:
            return IFS0bits.INT0IF;
            break;
            
        case Timer1:
            return IFS0bits.T1IF;
            break;
            
        case Input_Capture_1_Error:
            return IFS0bits.IC1EIF;
            break;
            
        case Input_Capture_1:
            return IFS0bits.IC1IF;
            break;
            
        case Output_Compare_1:
            return IFS0bits.OC1IF;
            break;
            
        case External_Interrupt_1:
            return IFS0bits.INT1IF;
            break;
            
        case Timer2:
            return IFS0bits.T2IF;
            break;
            
        case Input_Capture_2_Error:
            return IFS0bits.IC2EIF;
            break;
            
        case Input_Capture_2:
            return IFS0bits.IC2IF;
            break;
            
        case Output_Compare_2:
            return IFS0bits.OC2IF;
            break;
            
        case External_Interrupt_2:
            return IFS0bits.INT2IF;
            break;
            
        case Timer3:
            return IFS0bits.T3IF;
            break;
            
        case Input_Capture_3_Error:
            return IFS0bits.IC3EIF;
            break;
            
        case Input_Capture_3:
            return IFS0bits.IC3IF;
            break;
            
        case Output_Compare_3:
            return IFS0bits.OC3IF;
            break;
            
        case External_Interrupt_3:
            return IFS0bits.INT3IF;
            break;
            
        case Timer4:
            return IFS0bits.T4IF;
            break;
            
        case Input_Capture_4_Error:
            return IFS0bits.IC4EIF;
            break;
            
        case Input_Capture_4:
            return IFS0bits.IC4IF;
            break;
            
        case Output_Compare_4:
            return IFS0bits.OC4IF;
            break;
            
        case External_Interrupt_4:
            return IFS0bits.INT4IF;
            break;
            
        case Timer5:
            return IFS0bits.T5IF;
            break;
            
        case Input_Capture_5_Error:
            return IFS0bits.IC5EIF;
            break;
            
        case Input_Capture_5:
            return IFS0bits.IC5IF;
            break;
            
        case Output_Compare_5:
            return IFS0bits.OC5IF;
            break;
            
        case Timer6:
            return IFS0bits.T6IF;
            break;
            
        case Input_Capture_6_Error:
            return IFS0bits.IC6EIF;
            break;
            
        case Input_Capture_6:
            return IFS0bits.IC6IF;
            break;
            
        case Output_Compare_6:
            return IFS0bits.OC6IF;
            break;
            
        case Timer7:
            return IFS1bits.T7IF;
            break;
            
        case Input_Capture_7_Error:
            return IFS1bits.IC7EIF;
            break;
            
        case Input_Capture_7:
            return IFS1bits.IC7IF;
            break;
            
        case Output_Compare_7:
            return IFS1bits.OC7IF;
            break;
            
        case Timer8:
            return IFS1bits.T8IF;
            break;
            
        case Input_Capture_8_Error:
            return IFS1bits.IC8EIF;
            break;
            
        case Input_Capture_8:
            return IFS1bits.IC8IF;
            break;
            
        case Output_Compare_8:
            return IFS1bits.OC8IF;
            break;
            
        case Timer9:
            return IFS1bits.T9IF;
            break;
            
        case Input_Capture_9_Error:
            return IFS1bits.IC9EIF;
            break;
            
        case Input_Capture_9:
            return IFS1bits.IC9IF;
            break;
            
        case Output_Compare_9:
            return IFS1bits.OC9IF;
            break;
            
        case ADC_Global_Interrupt:
            return IFS1bits.ADCIF;
            break;
            
        case ADC_FIFO_Data_Ready_Interrupt:
            return IFS1bits.ADCFIFOIF;
            break;
            
        case ADC_Digital_Comparator_1:
            return IFS1bits.ADCDC1IF;
            break;
        
        case ADC_Digital_Comparator_2:
            return IFS1bits.ADCDC2IF;
            break;
            
        case ADC_Digital_Comparator_3:
            return IFS1bits.ADCDC3IF;
            break;
            
        case ADC_Digital_Comparator_4:
            return IFS1bits.ADCDC4IF;
            break;
            
        case ADC_Digital_Comparator_5:
            return IFS1bits.ADCDC5IF;
            break;
            
        case ADC_Digital_Comparator_6:
            return IFS1bits.ADCDC6IF;
            break;
            
        case ADC_Digital_Filter_1:
            return IFS1bits.ADCDF1IF;
            break;
            
        case ADC_Digital_Filter_2:
            return IFS1bits.ADCDF2IF;
            break;
            
        case ADC_Digital_Filter_3:
            return IFS1bits.ADCDF3IF;
            break;
            
        case ADC_Digital_Filter_4:
            return IFS1bits.ADCDF4IF;
            break;
            
        case ADC_Digital_Filter_5:
            return IFS1bits.ADCDF5IF;
            break;
            
        case ADC_Digital_Filter_6:
            return IFS1bits.ADCDF6IF;
            break;
            
        case ADC_Fault:
            return IFS1bits.ADCFLTIF;
            break;
            
        case ADC_Data_0:
            return IFS1bits.ADCD0IF;
            break;
            
        case ADC_Data_1:
            return IFS1bits.ADCD1IF;
            break;
            
        case ADC_Data_2:
            return IFS1bits.ADCD2IF;
            break;
            
        case ADC_Data_3:
            return IFS1bits.ADCD3IF;
            break;
            
        case ADC_Data_4:
            return IFS1bits.ADCD4IF;
            break;
            
        case ADC_Data_5:
            return IFS2bits.ADCD5IF;
            break;
            
        case ADC_Data_6:
            return IFS2bits.ADCD6IF;
            break;
            
        case ADC_Data_7:
            return IFS2bits.ADCD7IF;
            break;
            
        case ADC_Data_8:
            return IFS2bits.ADCD8IF;
            break;
            
        case ADC_Data_9:
            return IFS2bits.ADCD9IF;
            break;
            
        case ADC_Data_10:
            return IFS2bits.ADCD10IF;
            break;
            
        case ADC_Data_11:
            return IFS2bits.ADCD11IF;
            break;
            
        case ADC_Data_12:
            return IFS2bits.ADCD12IF;
            break;
            
        case ADC_Data_13:
            return IFS2bits.ADCD13IF;
            break;
            
        case ADC_Data_14:
            return IFS2bits.ADCD14IF;
            break;
            
        case ADC_Data_15:
            return IFS2bits.ADCD15IF;
            break;
            
        case ADC_Data_16:
            return IFS2bits.ADCD16IF;
            break;
            
        case ADC_Data_17:
            return IFS2bits.ADCD17IF;
            break;
            
        case ADC_Data_18:
            return IFS2bits.ADCD18IF;
            break;
            
        case ADC_Data_19:
            return IFS2bits.ADCD19IF;
            break;
            
        case ADC_Data_20:
            return IFS2bits.ADCD20IF;
            break;
            
        case ADC_Data_21:
            return IFS2bits.ADCD21IF;
            break;
            
        case ADC_Data_22:
            return IFS2bits.ADCD22IF;
            break;
            
        case ADC_Data_23:
            return IFS2bits.ADCD23IF;
            break;
            
        case ADC_Data_24:
            return IFS2bits.ADCD24IF;
            break;
            
        case ADC_Data_25:
            return IFS2bits.ADCD25IF;
            break;
            
        case ADC_Data_26:
            return IFS2bits.ADCD26IF;
            break;
            
        case ADC_Data_27:
            return IFS2bits.ADCD27IF;
            break;
            
        case ADC_Data_28:
            return IFS2bits.ADCD28IF;
            break;
            
        case ADC_Data_29:
            return IFS2bits.ADCD29IF;
            break;
            
        case ADC_Data_30:
            return IFS2bits.ADCD30IF;
            break;
            
        case ADC_Data_31:
            return IFS2bits.ADCD31IF;
            break;
            
        case ADC_Data_32:
            return IFS2bits.ADCD32IF;
            break;
            
        case ADC_Data_33:
            return IFS2bits.ADCD33IF;
            break;
            
        case ADC_Data_34:
            return IFS2bits.ADCD34IF;
            break;
            
        case ADC_Data_35:
            return IFS2bits.ADCD35IF;
            break;
            
        case ADC_Data_36:
            return IFS2bits.ADCD36IF;
            break;
            
        case ADC_Data_37:
            return IFS3bits.ADCD37IF;
            break;
            
        case ADC_Data_38:
            return IFS3bits.ADCD38IF;
            break;
            
        case ADC_Data_39:
            return IFS3bits.ADCD39IF;
            break;
            
        case ADC_Data_40:
            return IFS3bits.ADCD40IF;
            break;
            
        case ADC_Data_41:
            return IFS3bits.ADCD41IF;
            break;
            
        case ADC_Data_42:
            return IFS3bits.ADCD42IF;
            break;
            
        case ADC_Data_43:
            return IFS3bits.ADCD43IF;
            break;
            
        case ADC_Data_44:
            return IFS3bits.ADCD44IF;
            break;
            
        case Core_Performance_Counter_Interrupt:
            return IFS3bits.CPCIF;
            break;
            
        case Core_Fast_Debug_Channel_Interrupt:
            return IFS3bits.CFDCIF;
            break;
            
        case System_Bus_Protection_Violation:
            return IFS3bits.SBIF;
            break;
            
        case SPI1_Fault:
            return IFS3bits.SPI1EIF;
            break;
            
        case SPI1_Receive_Done:
            return IFS3bits.SPI1RXIF;
            break;
            
        case SPI1_Transfer_Done:
            return IFS3bits.SPI1TXIF;
            break;
            
        case UART1_Fault:
            return IFS3bits.U1EIF;
            break;
            
        case UART1_Receive_Done:
            return IFS3bits.U1RXIF;
            break;
            
        case UART1_Transfer_Done:
            return IFS3bits.U1TXIF;
            break;
            
        case I2C1_Bus_Collision_Event:
            return IFS3bits.I2C1BIF;
            break;
            
        case I2C1_Slave_Event:
            return IFS3bits.I2C1SIF;
            break;
            
        case I2C1_Master_Event:
            return IFS3bits.I2C1MIF;
            break;
            
        case PORTA_Input_Change_Interrupt:
            return IFS3bits.CNAIF;
            break;
            
        case PORTB_Input_Change_Interrupt:
            return IFS3bits.CNBIF;
            break;
            
        case PORTC_Input_Change_Interrupt:
            return IFS3bits.CNCIF;
            break;
            
        case PORTD_Input_Change_Interrupt:
            return IFS3bits.CNDIF;
            break;
            
        case PORTE_Input_Change_Interrupt:
            return IFS3bits.CNEIF;
            break;
            
        case PORTF_Input_Change_Interrupt:
            return IFS3bits.CNFIF;
            break;
            
        case PORTG_Input_Change_Interrupt:
            return IFS3bits.CNGIF;
            break;
            
        case PORTH_Input_Change_Interrupt:
            return IFS3bits.CNHIF;
            break;
            
        case PORTJ_Input_Change_Interrupt:
            return IFS3bits.CNJIF;
            break;
            
        case PORTK_Input_Change_Interrupt:
            return IFS3bits.CNKIF;
            break;
            
        case Parallel_Master_Port:
            return IFS4bits.PMPIF;
            break;
            
        case Parallel_Master_Port_Error:
            return IFS4bits.PMPEIF;
            break;
            
        case Comparator_1_Interrupt:
            return IFS4bits.CMP1IF;
            break;
            
        case Comparator_2_Interrupt:
            return IFS4bits.CMP2IF;
            break;
            
        case USB_General_Event:
            return IFS4bits.USBIF;
            break;
            
        case USB_DMA_Event:
            return IFS4bits.USBDMAIF;
            break;
            
        case DMA_Channel_0:
            return IFS4bits.DMA0IF;
            break;
            
        case DMA_Channel_1:
            return IFS4bits.DMA1IF;
            break;
            
        case DMA_Channel_2:
            return IFS4bits.DMA2IF;
            break;
            
        case DMA_Channel_3:
            return IFS4bits.DMA3IF;
            break;
            
        case DMA_Channel_4:
            return IFS4bits.DMA4IF;
            break;
            
        case DMA_Channel_5:
            return IFS4bits.DMA5IF;
            break;
            
        case DMA_Channel_6:
            return IFS4bits.DMA6IF;
            break;
            
        case DMA_Channel_7:
            return IFS4bits.DMA7IF;
            break;
            
        case SPI2_Fault:
            return IFS4bits.SPI2EIF;
            break;
            
        case SPI2_Receive_Done:
            return IFS4bits.SPI2RXIF;
            break;
            
        case SPI2_Transfer_Done:
            return IFS4bits.SPI2TXIF;
            break;
            
        case UART2_Fault:
            return IFS4bits.U2EIF;
            break;
            
        case UART2_Receive_Done:
            return IFS4bits.U2RXIF;
            break;
            
        case UART2_Transfer_Done:
            return IFS4bits.U2TXIF;
            break;
            
        case I2C2_Bus_Collision_Event:
            return IFS4bits.I2C2BIF;
            break;
            
        case I2C2_Slave_Event:
            return IFS4bits.I2C2SIF;
            break;
            
        case I2C2_Master_Event:
            return IFS4bits.I2C2MIF;
            break;
            
        case Control_Area_Network_1:
            return IFS4bits.CAN1IF;
            break;
                    
        case Control_Area_Network_2:
            return IFS4bits.CAN2IF;
            break;
            
        case Ethernet_Interrupt:
            return IFS4bits.ETHIF;
            break;
            
        case SPI3_Fault:
            return IFS4bits.SPI3EIF;
            break;
            
        case SPI3_Receive_Done:
            return IFS4bits.SPI3RXIF;
            break;
            
        case SPI3_Transfer_Done:
            return IFS4bits.SPI3TXIF;
            break;
            
        case UART3_Fault:
            return IFS4bits.U3EIF;
            break;
            
        case UART3_Receive_Done:
            return IFS4bits.U3RXIF;
            break;
            
        case UART3_Transfer_Done:
            return IFS4bits.U3TXIF;
            break;
            
        case I2C3_Bus_Collision_Event:
            return IFS5bits.I2C3BIF;
            break;
            
        case I2C3_Slave_Event:
            return IFS5bits.I2C3SIF;
            break;
            
        case I2C3_Master_Event:
            return IFS5bits.I2C3MIF;
            break;
            
        case SPI4_Fault:
            return IFS5bits.SPI5EIF;
            break;
            
        case SPI4_Receive_Done:
            return IFS5bits.SPI4RXIF;
            break;
            
        case SPI4_Transfer_Done:
            return IFS5bits.SPI4TXIF;
            break;
            
        case Real_Time_Clock:
            return IFS5bits.RTCCIF;
            break;
            
        case Flash_Control_Event:
            return IFS5bits.FCEIF;
            break;
            
        case Prefetch_Module_SEC_Event:
            return IFS5bits.PREIF;
            break;
            
        case SQI1_Event:
            return IFS5bits.SQI1IF;
            break;
            
        case UART4_Fault:
            return IFS5bits.U4EIF;
            break;
            
        case UART4_Receive_Done:
            return IFS5bits.U4RXIF;
            break;
            
        case UART4_Transfer_Done:
            return IFS5bits.U4TXIF;
            break;
            
        case I2C4_Bus_Collision_Event:
            return IFS5bits.I2C4BIF;
            break;
            
        case I2C4_Slave_Event:
            return IFS5bits.I2C4SIF;
            break;
            
        case I2C4_Master_Event:
            return IFS5bits.I2C4MIF;
            break;
            
        case SPI5_Fault:
            return IFS5bits.SPI5EIF;
            break;
            
        case SPI5_Receive_Done:
            return IFS5bits.SPI5RXIF;
            break;
            
        case SPI5_Transfer_Done:
            return IFS5bits.SPI5TXIF;
            break;
            
        case UART5_Fault:
            return IFS5bits.U5EIF;
            break;
            
        case UART5_Receive_Done:
            return IFS5bits.U5RXIF;
            break;
            
        case UART5_Transfer_Done:
            return IFS5bits.U5TXIF;
            break;
            
        case I2C5_Bus_Collision_Event:
            return IFS5bits.I2C5BIF;
            break;
            
        case I2C5_Slave_Event:
            return IFS5bits.I2C5SIF;
            break;
            
        case I2C5_Master_Event:
            return IFS5bits.I2C5MIF;
            break;
        
        case SPI6_Fault:
            return IFS5bits.SPI6IF;  // Error in microchip bitfield macro!!!
            break;
            
        case SPI6_Receive_Done:
            return IFS5bits.SPI6RXIF;
            break;
            
        case SPI6_Transfer_Done:
            return IFS5bits.SPI6TX;  // Error in microchip bitfield macro!!!
            break;
            
        case UART6_Fault:
            return IFS5bits.U6EIF;
            break;
            
        case UART6_Receive_Done:
            return IFS5bits.U6RXIF;
            break;
            
        case UART6_Transfer_Done:
            return IFS5bits.U6TXIF;
            break;
        
        case ADC_End_Of_Scan_Ready:
            return IFS6bits.ADCEOSIF;
            break;
            
        case ADC_Analog_Circuits_Ready:
            return IFS6bits.ADCARDYIF;
            break;
            
        case ADC_Update_Ready:
            return IFS6bits.ADCURDYIF;
            break;
            
        case ADC_Group_Early_Interrupt_Request:
            return IFS6bits.ADCGRPIF;
            break;
            
        case ADC0_Early_Interrupt:
            return IFS6bits.ADC0EIF;
            break;
            
        case ADC1_Early_Interrupt:
            return IFS6bits.ADC1EIF;
            break;
            
        case ADC2_Early_Interrupt:
            return IFS6bits.ADC2EIF;
            break;
            
        case ADC3_Early_Interrupt:
            return IFS6bits.ADC3EIF;
            break;
            
        case ADC4_Early_Interrupt:
            return IFS6bits.ADC4EIF;
            break;
            
        case ADC7_Early_Interrupt:
            return IFS6bits.ADC7EIF;
            break;
            
        case ADC0_Warm_Interrupt:
            return IFS6bits.ADC0WIF;
            break;
            
        case ADC1_Warm_Interrupt:
            return IFS6bits.ADC1WIF;
            break;
            
        case ADC2_Warm_Interrupt:
            return IFS6bits.ADC2WIF;
            break;
            
        case ADC3_Warm_Interrupt:
            return IFS6bits.ADC3WIF;
            break;
            
        case ADC4_Warm_Interrupt:
            return IFS6bits.ADC4WIF;
            break;
            
        case ADC7_Warm_Interrupt:
            return IFS6bits.ADC7WIF;
            break;
            
        default:
            return 0;
            break;
            
    }
    
}

// This function sets the priority for a given interrupt
void setInterruptPriority(interrupt_source_t input_interrupt, uint8_t input_priority) {
    
    // verify input priority is between 0 and 7
    if (input_priority > 7) {
        
        input_priority = 7;
    
    }
    
    // Decide which interrupt control bits to manipulate based on which interrupt
    // is having its priority set
    switch (input_interrupt) {
        
        case Core_Timer_Interrupt:
            IPC0bits.CTIP = input_priority;
            break;
            
        case Core_Software_Interrupt_0:
            IPC0bits.CS0IP = input_priority;
            break;
            
        case Core_Software_Interrupt_1:
            IPC0bits.CS1IP = input_priority;
            break;
            
        case External_Interrupt_0:
            IPC0bits.INT0IP = input_priority;
            break;
            
        case Timer1:
            IPC1bits.T1IP = input_priority;
            break;
            
        case Input_Capture_1_Error:
            IPC1bits.IC1EIP = input_priority;
            break;
            
        case Input_Capture_1:
            IPC1bits.IC1IP = input_priority;
            break;
            
        case Output_Compare_1:
            IPC1bits.OC1IP = input_priority;
            break;
            
        case External_Interrupt_1:
            IPC2bits.INT1IP = input_priority;
            break;
            
        case Timer2:
            IPC2bits.T2IP = input_priority;
            break;
            
        case Input_Capture_2_Error:
            IPC2bits.IC2EIP = input_priority;
            break;
            
        case Input_Capture_2:
            IPC2bits.IC2IP = input_priority;
            break;
            
        case Output_Compare_2:
            IPC3bits.OC2IP = input_priority;
            break;
            
        case External_Interrupt_2:
            IPC3bits.INT2IP = input_priority;
            break;
            
        case Timer3:
            IPC3bits.T3IP = input_priority;
            break;
            
        case Input_Capture_3_Error:
            IPC3bits.IC3EIP = input_priority;
            break;
            
        case Input_Capture_3:
            IPC4bits.IC3IP = input_priority;
            break;
            
        case Output_Compare_3:
            IPC4bits.OC3IP = input_priority;
            break;
            
        case External_Interrupt_3:
            IPC4bits.INT3IP = input_priority;
            break;
            
        case Timer4:
            IPC4bits.T4IP = input_priority;
            break;
            
        case Input_Capture_4_Error:
            IPC5bits.IC4EIP = input_priority;
            break;
            
        case Input_Capture_4:
            IPC5bits.IC4IP = input_priority;
            break;
            
        case Output_Compare_4:
            IPC5bits.OC4IP = input_priority;
            break;
            
        case External_Interrupt_4:
            IPC5bits.INT4IP = input_priority;
            break;
            
        case Timer5:
            IPC6bits.T5IP = input_priority;
            break;
            
        case Input_Capture_5_Error:
            IPC6bits.IC5EIP = input_priority;
            break;
            
        case Input_Capture_5:
            IPC6bits.IC5IP = input_priority;
            break;
            
        case Output_Compare_5:
            IPC6bits.OC5IP = input_priority;
            break;
            
        case Timer6:
            IPC7bits.T6IP = input_priority;
            break;
            
        case Input_Capture_6_Error:
            IPC7bits.IC6EIP = input_priority;
            break;
            
        case Input_Capture_6:
            IPC7bits.IC6IP = input_priority;
            break;
            
        case Output_Compare_6:
            IPC7bits.OC6IP = input_priority;
            break;
            
        case Timer7:
            IPC8bits.T7IP = input_priority;
            break;
            
        case Input_Capture_7_Error:
            IPC8bits.IC7EIP = input_priority;
            break;
            
        case Input_Capture_7:
            IPC8bits.IC7IP = input_priority;
            break;
            
        case Output_Compare_7:
            IPC8bits.OC7IP = input_priority;
            break;
            
        case Timer8:
            IPC9bits.T8IP = input_priority;
            break;
            
        case Input_Capture_8_Error:
            IPC9bits.IC8EIP = input_priority;
            break;
            
        case Input_Capture_8:
            IPC9bits.IC8IP = input_priority;
            break;
            
        case Output_Compare_8:
            IPC9bits.OC8IP = input_priority;
            break;
            
        case Timer9:
            IPC10bits.T9IP = input_priority;
            break;
            
        case Input_Capture_9_Error:
            IPC10bits.IC9EIP = input_priority;
            break;
            
        case Input_Capture_9:
            IPC10bits.OC9IP = input_priority;
            break;
            
        case Output_Compare_9:
            IPC10bits.OC9IP = input_priority;
            break;
            
        case ADC_Global_Interrupt:
            IPC11bits.ADCIP = input_priority;
            break;
            
        case ADC_FIFO_Data_Ready_Interrupt:
            IPC11bits.ADCFIFOIP = input_priority;
            break;
            
        case ADC_Digital_Comparator_1:
            IPC11bits.ADCDC1IP = input_priority;
            break;
        
        case ADC_Digital_Comparator_2:
            IPC11bits.ADCDC2IP = input_priority;
            break;
            
        case ADC_Digital_Comparator_3:
            IPC12bits.ADCDC3IP = input_priority;
            break;
            
        case ADC_Digital_Comparator_4:
            IPC12bits.ADCDC4IP = input_priority;
            break;
            
        case ADC_Digital_Comparator_5:
            IPC12bits.ADCDC5IP = input_priority;
            break;
            
        case ADC_Digital_Comparator_6:
            IPC12bits.ADCDC6IP = input_priority;
            break;
            
        case ADC_Digital_Filter_1:
            IPC13bits.ADCDF1IP = input_priority;
            break;
            
        case ADC_Digital_Filter_2:
            IPC13bits.ADCDF2IP = input_priority;
            break;
            
        case ADC_Digital_Filter_3:
            IPC13bits.ADCDF3IP = input_priority;
            break;
            
        case ADC_Digital_Filter_4:
            IPC13bits.ADCDF4IP = input_priority;
            break;
            
        case ADC_Digital_Filter_5:
            IPC14bits.ADCDF5IP = input_priority;
            break;
            
        case ADC_Digital_Filter_6:
            IPC14bits.ADCDF6IP = input_priority;
            break;
            
        case ADC_Fault:
            IPC14bits.ADCFLTIP = input_priority;
            break;
            
        case ADC_Data_0:
            IPC14bits.ADCD0IP = input_priority;
            break;
            
        case ADC_Data_1:
            IPC15bits.ADCD1IP = input_priority;
            break;
            
        case ADC_Data_2:
            IPC15bits.ADCD2IP = input_priority;
            break;
            
        case ADC_Data_3:
            IPC15bits.ADCD3IP = input_priority;
            break;
            
        case ADC_Data_4:
            IPC15bits.ADCD4IP = input_priority;
            break;
            
        case ADC_Data_5:
            IPC16bits.ADCD5IP = input_priority;
            break;
            
        case ADC_Data_6:
            IPC16bits.ADCD6IP = input_priority;
            break;
            
        case ADC_Data_7:
            IPC16bits.ADCD7IP = input_priority;
            break;
            
        case ADC_Data_8:
            IPC16bits.ADCD8IP = input_priority;
            break;
            
        case ADC_Data_9:
            IPC17bits.ADCD9IP = input_priority;
            break;
            
        case ADC_Data_10:
            IPC17bits.ADCD10IP = input_priority;
            break;
            
        case ADC_Data_11:
            IPC17bits.ADCD11IP = input_priority;
            break;
            
        case ADC_Data_12:
            IPC17bits.ADCD12IP = input_priority;
            break;
            
        case ADC_Data_13:
            IPC18bits.ADCD13IP = input_priority;
            break;
            
        case ADC_Data_14:
            IPC18bits.ADCD14IP = input_priority;
            break;
            
        case ADC_Data_15:
            IPC18bits.ADCD15IP = input_priority;
            break;
            
        case ADC_Data_16:
            IPC18bits.ADCD16IP = input_priority;
            break;
            
        case ADC_Data_17:
            IPC19bits.ADCD17IP = input_priority;
            break;
            
        case ADC_Data_18:
            IPC19bits.ADCD18IP = input_priority;
            break;
            
        case ADC_Data_19:
            IPC19bits.ADCD19IP = input_priority;
            break;
            
        case ADC_Data_20:
            IPC19bits.ADCD20IP = input_priority;
            break;
            
        case ADC_Data_21:
            IPC20bits.ADCD21IP = input_priority;
            break;
            
        case ADC_Data_22:
            IPC20bits.ADCD22IP = input_priority;
            break;
            
        case ADC_Data_23:
            IPC20bits.ADCD23IP = input_priority;
            break;
            
        case ADC_Data_24:
            IPC20bits.ADCD24IP = input_priority;
            break;
            
        case ADC_Data_25:
            IPC21bits.ADCD25IP = input_priority;
            break;
            
        case ADC_Data_26:
            IPC21bits.ADCD26IP = input_priority;
            break;
            
        case ADC_Data_27:
            IPC21bits.ADCD27IP = input_priority;
            break;
            
        case ADC_Data_28:
            IPC21bits.ADCD28IP = input_priority;
            break;
            
        case ADC_Data_29:
            IPC22bits.ADCD29IP = input_priority;
            break;
            
        case ADC_Data_30:
            IPC22bits.ADCD30IP = input_priority;
            break;
            
        case ADC_Data_31:
            IPC22bits.ADCD31IP = input_priority;
            break;
            
        case ADC_Data_32:
            IPC22bits.ADCD32IP = input_priority;
            break;
            
        case ADC_Data_33:
            IPC23bits.ADCD33IP = input_priority;
            break;
            
        case ADC_Data_34:
            IPC23bits.ADCD34IP = input_priority;
            break;
            
        case ADC_Data_35:
            IPC23bits.ADCD35IP = input_priority;
            break;
            
        case ADC_Data_36:
            IPC23bits.ADCD36IP = input_priority;
            break;
            
        case ADC_Data_37:
            IPC24bits.ADCD37IP = input_priority;
            break;
            
        case ADC_Data_38:
            IPC24bits.ADCD38IP = input_priority;
            break;
            
        case ADC_Data_39:
            IPC24bits.ADCD39IP = input_priority;
            break;
            
        case ADC_Data_40:
            IPC24bits.ADCD40IP = input_priority;
            break;
            
        case ADC_Data_41:
            IPC25bits.ADCD41IP = input_priority;
            break;
            
        case ADC_Data_42:
            IPC25bits.ADCD42IP = input_priority;
            break;
            
        case ADC_Data_43:
            IPC25bits.ADCD43IP = input_priority;
            break;
            
        case ADC_Data_44:
            IPC25bits.ADCD44IP = input_priority;
            break;
            
        case Core_Performance_Counter_Interrupt:
            IPC26bits.CPCIP = input_priority;
            break;
            
        case Core_Fast_Debug_Channel_Interrupt:
            IPC26bits.CFDCIP = input_priority;
            break;
            
        case System_Bus_Protection_Violation:
            IPC26bits.SBIP = input_priority;
            break;
            
        case SPI1_Fault:
            IPC27bits.SPI1EIP = input_priority;
            break;
            
        case SPI1_Receive_Done:
            IPC27bits.SPI1RXIP = input_priority;
            break;
            
        case SPI1_Transfer_Done:
            IPC27bits.SPI1TXIP = input_priority;
            break;
            
        case UART1_Fault:
            IPC28bits.U1EIP = input_priority;
            break;
            
        case UART1_Receive_Done:
            IPC28bits.U1RXIP = input_priority;
            break;
            
        case UART1_Transfer_Done:
            IPC28bits.U1TXIP = input_priority;
            break;
            
        case I2C1_Bus_Collision_Event:
            IPC28bits.I2C1BIP = input_priority;
            break;
            
        case I2C1_Slave_Event:
            IPC29bits.I2C1SIP = input_priority;
            break;
            
        case I2C1_Master_Event:
            IPC29bits.I2C1MIP = input_priority;
            break;
            
        case PORTA_Input_Change_Interrupt:
            IPC29bits.CNAIP = input_priority;
            break;
            
        case PORTB_Input_Change_Interrupt:
            IPC29bits.CNBIP = input_priority;
            break;
            
        case PORTC_Input_Change_Interrupt:
            IPC30bits.CNCIP = input_priority;
            break;
            
        case PORTD_Input_Change_Interrupt:
            IPC30bits.CNDIP = input_priority;
            break;
            
        case PORTE_Input_Change_Interrupt:
            IPC30bits.CNEIP = input_priority;
            break;
            
        case PORTF_Input_Change_Interrupt:
            IPC30bits.CNFIP = input_priority;
            break;
            
        case PORTG_Input_Change_Interrupt:
            IPC31bits.CNGIP = input_priority;
            break;
            
        case PORTH_Input_Change_Interrupt:
            IPC31bits.CNHIP = input_priority;
            break;
            
        case PORTJ_Input_Change_Interrupt:
            IPC31bits.CNJIP = input_priority;
            break;
            
        case PORTK_Input_Change_Interrupt:
            IPC31bits.CNKIP = input_priority;
            break;
            
        case Parallel_Master_Port:
            IPC32bits.PMPIP = input_priority;
            break;
            
        case Parallel_Master_Port_Error:
            IPC32bits.PMPEIP = input_priority;
            break;
            
        case Comparator_1_Interrupt:
            IPC32bits.CMP1IP = input_priority;
            break;
            
        case Comparator_2_Interrupt:
            IPC32bits.CMP2IP = input_priority;
            break;
            
        case USB_General_Event:
            IPC33bits.USBIP = input_priority;
            break;
            
        case USB_DMA_Event:
            IPC33bits.USBDMAIP = input_priority;
            break;
            
        case DMA_Channel_0:
            IPC33bits.DMA0IP = input_priority;
            break;
            
        case DMA_Channel_1:
            IPC33bits.DMA1IP = input_priority;
            break;
            
        case DMA_Channel_2:
            IPC34bits.DMA2IP = input_priority;
            break;
            
        case DMA_Channel_3:
            IPC34bits.DMA3IP = input_priority;
            break;
            
        case DMA_Channel_4:
            IPC34bits.DMA4IP = input_priority;
            break;
            
        case DMA_Channel_5:
            IPC34bits.DMA5IP = input_priority;
            break;
            
        case DMA_Channel_6:
            IPC35bits.DMA6IP = input_priority;
            break;
            
        case DMA_Channel_7:
            IPC35bits.DMA7IP = input_priority;
            break;
            
        case SPI2_Fault:
            IPC35bits.SPI2EIP = input_priority;
            break;
            
        case SPI2_Receive_Done:
            IPC35bits.SPI2RXIP = input_priority;
            break;
            
        case SPI2_Transfer_Done:
            IPC36bits.SPI2TXIP = input_priority;
            break;
            
        case UART2_Fault:
            IPC36bits.U2EIP = input_priority;
            break;
            
        case UART2_Receive_Done:
            IPC36bits.U2RXIP = input_priority;
            break;
            
        case UART2_Transfer_Done:
            IPC36bits.U2TXIP = input_priority;
            break;
            
        case I2C2_Bus_Collision_Event:
            IPC37bits.I2C2BIP = input_priority;
            break;
            
        case I2C2_Slave_Event:
            IPC37bits.I2C2SIP = input_priority;
            break;
            
        case I2C2_Master_Event:
            IPC37bits.I2C2MIP = input_priority;
            break;
            
        case Control_Area_Network_1:
            IPC37bits.CAN1IP = input_priority;
            break;
                    
        case Control_Area_Network_2:
            IPC38bits.CAN2IP = input_priority;
            break;
            
        case Ethernet_Interrupt:
            IPC38bits.ETHIP = input_priority;
            break;
            
        case SPI3_Fault:
            IPC38bits.SPI3EIP = input_priority;
            break;
            
        case SPI3_Receive_Done:
            IPC38bits.SPI3RXIP = input_priority;
            break;
            
        case SPI3_Transfer_Done:
            IPC39bits.SPI3TXIP = input_priority;
            break;
            
        case UART3_Fault:
            IPC39bits.U3EIP = input_priority;
            break;
            
        case UART3_Receive_Done:
            IPC39bits.U3RXIP = input_priority;
            break;
            
        case UART3_Transfer_Done:
            IPC39bits.U3TXIP = input_priority;
            break;
            
        case I2C3_Bus_Collision_Event:
            IPC40bits.I2C3BIP = input_priority;
            break;
            
        case I2C3_Slave_Event:
            IPC40bits.I2C3SIP = input_priority;
            break;
            
        case I2C3_Master_Event:
            IPC40bits.I2C3MIP = input_priority;
            break;
            
        case SPI4_Fault:
            IPC40bits.SPI4EIP = input_priority;
            break;
            
        case SPI4_Receive_Done:
            IPC41bits.SPI4RXIP = input_priority;
            break;
            
        case SPI4_Transfer_Done:
            IPC41bits.SPI4TXIP = input_priority;
            break;
            
        case Real_Time_Clock:
            IPC41bits.RTCCIP = input_priority;
            break;
            
        case Flash_Control_Event:
            IPC41bits.FCEIP = input_priority;
            break;
            
        case Prefetch_Module_SEC_Event:
            IPC42bits.PREIP = input_priority;
            break;
            
        case SQI1_Event:
            IPC42bits.SQI1IP = input_priority;
            break;
            
        case UART4_Fault:
            IPC42bits.U4EIP = input_priority;
            break;
            
        case UART4_Receive_Done:
            IPC42bits.U4RXIP = input_priority;
            break;
            
        case UART4_Transfer_Done:
            IPC43bits.U4TXIP = input_priority;
            break;
            
        case I2C4_Bus_Collision_Event:
            IPC43bits.I2C4BIP = input_priority;
            break;
            
        case I2C4_Slave_Event:
            IPC43bits.I2C4SIP = input_priority;
            break;
            
        case I2C4_Master_Event:
            IPC43bits.I2C4MIP = input_priority;
            break;
            
        case SPI5_Fault:
            IPC44bits.SPI5EIP = input_priority;
            break;
            
        case SPI5_Receive_Done:
            IPC44bits.SPI5RXIP = input_priority;
            break;
            
        case SPI5_Transfer_Done:
            IPC44bits.SPI5TXIP = input_priority;
            break;
            
        case UART5_Fault:
            IPC44bits.U5EIP = input_priority;
            break;
            
        case UART5_Receive_Done:
            IPC45bits.U5RXIP = input_priority;
            break;
            
        case UART5_Transfer_Done:
            IPC45bits.U5TXIP = input_priority;
            break;
            
        case I2C5_Bus_Collision_Event:
            IPC45bits.I2C5BIP = input_priority;
            break;
            
        case I2C5_Slave_Event:
            IPC45bits.I2C5SIP = input_priority;
            break;
            
        case I2C5_Master_Event:
            IPC46bits.I2C5MIP = input_priority;
            break;
        
        case SPI6_Fault:
            IPC46bits.SPI6EIP = input_priority;
            break;
            
        case SPI6_Receive_Done:
            IPC46bits.SPI6RXIP = input_priority;
            break;
            
        case SPI6_Transfer_Done:
            IPC46bits.SPI6TXIP = input_priority;
            break;
            
        case UART6_Fault:
            IPC47bits.U6EIP = input_priority;
            break;
            
        case UART6_Receive_Done:
            IPC47bits.U6RXIP = input_priority;
            break;
            
        case UART6_Transfer_Done:
            IPC47bits.U6TXIP = input_priority;
            break;
        
        case ADC_End_Of_Scan_Ready:
            IPC48bits.ADCEOSIP = input_priority;
            break;
            
        case ADC_Analog_Circuits_Ready:
            IPC48bits.ADCARDYIP = input_priority;
            break;
            
        case ADC_Update_Ready:
            IPC48bits.ADCURDYIP = input_priority;
            break;
            
        case ADC_Group_Early_Interrupt_Request:
            IPC49bits.ADCGRPIP = input_priority;
            break;
            
        case ADC0_Early_Interrupt:
            IPC49bits.ADC0EIP = input_priority;
            break;
            
        case ADC1_Early_Interrupt:
            IPC49bits.ADC1EIP = input_priority;
            break;
            
        case ADC2_Early_Interrupt:
            IPC50bits.ADC2EIP = input_priority;
            break;
            
        case ADC3_Early_Interrupt:
            IPC50bits.ADC3EIP = input_priority;
            break;
            
        case ADC4_Early_Interrupt:
            IPC50bits.ADC4EIP = input_priority;
            break;
            
        case ADC7_Early_Interrupt:
            IPC51bits.ADC7EIP = input_priority;
            break;
            
        case ADC0_Warm_Interrupt:
            IPC51bits.ADC0WIP = input_priority;
            break;
            
        case ADC1_Warm_Interrupt:
            IPC51bits.ADC1WIP = input_priority;
            break;
            
        case ADC2_Warm_Interrupt:
            IPC52bits.ADC2WIP = input_priority;
            break;
            
        case ADC3_Warm_Interrupt:
            IPC52bits.ADC3WIP = input_priority;
            break;
            
        case ADC4_Warm_Interrupt:
            IPC52bits.ADC4WIP = input_priority;
            break;
            
        case ADC7_Warm_Interrupt:
            IPC53bits.ADC7WIP = input_priority;
            break;
            
        default:
            break;
            
    }
    
}

// This function sets the subpriority for a given interrupt
void setInterruptSubpriority(interrupt_source_t input_interrupt, uint8_t input_subpriority) {

    // check if input subpriority is valid
    if (input_subpriority > 3) {
     
        input_subpriority = 3;
        
    }
    
    // Decide which interrupt control bits to manipulate based on which interrupt
    // is having its priority set
    switch (input_interrupt) {
        
        case Core_Timer_Interrupt:
            IPC0bits.CTIS = input_subpriority;
            break;
            
        case Core_Software_Interrupt_0:
            IPC0bits.CS0IS = input_subpriority;
            break;
            
        case Core_Software_Interrupt_1:
            IPC0bits.CS1IS = input_subpriority;
            break;
            
        case External_Interrupt_0:
            IPC0bits.INT0IS = input_subpriority;
            break;
            
        case Timer1:
            IPC1bits.T1IS = input_subpriority;
            break;
            
        case Input_Capture_1_Error:
            IPC1bits.IC1EIS = input_subpriority;
            break;
            
        case Input_Capture_1:
            IPC1bits.IC1IS = input_subpriority;
            break;
            
        case Output_Compare_1:
            IPC1bits.OC1IS = input_subpriority;
            break;
            
        case External_Interrupt_1:
            IPC2bits.INT1IS = input_subpriority;
            break;
            
        case Timer2:
            IPC2bits.T2IS = input_subpriority;
            break;
            
        case Input_Capture_2_Error:
            IPC2bits.IC2EIS = input_subpriority;
            break;
            
        case Input_Capture_2:
            IPC2bits.IC2IS = input_subpriority;
            break;
            
        case Output_Compare_2:
            IPC3bits.OC2IS = input_subpriority;
            break;
            
        case External_Interrupt_2:
            IPC3bits.INT2IS = input_subpriority;
            break;
            
        case Timer3:
            IPC3bits.T3IS = input_subpriority;
            break;
            
        case Input_Capture_3_Error:
            IPC3bits.IC3EIS = input_subpriority;
            break;
            
        case Input_Capture_3:
            IPC4bits.IC3IS = input_subpriority;
            break;
            
        case Output_Compare_3:
            IPC4bits.OC3IS = input_subpriority;
            break;
            
        case External_Interrupt_3:
            IPC4bits.INT3IS = input_subpriority;
            break;
            
        case Timer4:
            IPC4bits.T4IS = input_subpriority;
            break;
            
        case Input_Capture_4_Error:
            IPC5bits.IC4EIS = input_subpriority;
            break;
            
        case Input_Capture_4:
            IPC5bits.IC4IS = input_subpriority;
            break;
            
        case Output_Compare_4:
            IPC5bits.OC4IS = input_subpriority;
            break;
            
        case External_Interrupt_4:
            IPC5bits.INT4IS = input_subpriority;
            break;
            
        case Timer5:
            IPC6bits.T5IS = input_subpriority;
            break;
            
        case Input_Capture_5_Error:
            IPC6bits.IC5EIS = input_subpriority;
            break;
            
        case Input_Capture_5:
            IPC6bits.IC5IS = input_subpriority;
            break;
            
        case Output_Compare_5:
            IPC6bits.OC5IS = input_subpriority;
            break;
            
        case Timer6:
            IPC7bits.T6IS = input_subpriority;
            break;
            
        case Input_Capture_6_Error:
            IPC7bits.IC6EIS = input_subpriority;
            break;
            
        case Input_Capture_6:
            IPC7bits.IC6IS = input_subpriority;
            break;
            
        case Output_Compare_6:
            IPC7bits.OC6IS = input_subpriority;
            break;
            
        case Timer7:
            IPC8bits.T7IS = input_subpriority;
            break;
            
        case Input_Capture_7_Error:
            IPC8bits.IC7EIS = input_subpriority;
            break;
            
        case Input_Capture_7:
            IPC8bits.IC7IS = input_subpriority;
            break;
            
        case Output_Compare_7:
            IPC8bits.OC7IS = input_subpriority;
            break;
            
        case Timer8:
            IPC9bits.T8IS = input_subpriority;
            break;
            
        case Input_Capture_8_Error:
            IPC9bits.IC8EIS = input_subpriority;
            break;
            
        case Input_Capture_8:
            IPC9bits.IC8IS = input_subpriority;
            break;
            
        case Output_Compare_8:
            IPC9bits.OC8IS = input_subpriority;
            break;
            
        case Timer9:
            IPC10bits.T9IS = input_subpriority;
            break;
            
        case Input_Capture_9_Error:
            IPC10bits.IC9EIS = input_subpriority;
            break;
            
        case Input_Capture_9:
            IPC10bits.OC9IS = input_subpriority;
            break;
            
        case Output_Compare_9:
            IPC10bits.OC9IS = input_subpriority;
            break;
            
        case ADC_Global_Interrupt:
            IPC11bits.ADCIS = input_subpriority;
            break;
            
        case ADC_FIFO_Data_Ready_Interrupt:
            IPC11bits.ADCFIFOIS = input_subpriority;
            break;
            
        case ADC_Digital_Comparator_1:
            IPC11bits.ADCDC1IS = input_subpriority;
            break;
        
        case ADC_Digital_Comparator_2:
            IPC11bits.ADCDC2IS = input_subpriority;
            break;
            
        case ADC_Digital_Comparator_3:
            IPC12bits.ADCDC3IS = input_subpriority;
            break;
            
        case ADC_Digital_Comparator_4:
            IPC12bits.ADCDC4IS = input_subpriority;
            break;
            
        case ADC_Digital_Comparator_5:
            IPC12bits.ADCDC5IS = input_subpriority;
            break;
            
        case ADC_Digital_Comparator_6:
            IPC12bits.ADCDC6IS = input_subpriority;
            break;
            
        case ADC_Digital_Filter_1:
            IPC13bits.ADCDF1IS = input_subpriority;
            break;
            
        case ADC_Digital_Filter_2:
            IPC13bits.ADCDF2IS = input_subpriority;
            break;
            
        case ADC_Digital_Filter_3:
            IPC13bits.ADCDF3IS = input_subpriority;
            break;
            
        case ADC_Digital_Filter_4:
            IPC13bits.ADCDF4IS = input_subpriority;
            break;
            
        case ADC_Digital_Filter_5:
            IPC14bits.ADCDF5IS = input_subpriority;
            break;
            
        case ADC_Digital_Filter_6:
            IPC14bits.ADCDF6IS = input_subpriority;
            break;
            
        case ADC_Fault:
            IPC14bits.ADCFLTIS = input_subpriority;
            break;
            
        case ADC_Data_0:
            IPC14bits.ADCD0IS = input_subpriority;
            break;
            
        case ADC_Data_1:
            IPC15bits.ADCD1IS = input_subpriority;
            break;
            
        case ADC_Data_2:
            IPC15bits.ADCD2IS = input_subpriority;
            break;
            
        case ADC_Data_3:
            IPC15bits.ADCD3IS = input_subpriority;
            break;
            
        case ADC_Data_4:
            IPC15bits.ADCD4IS = input_subpriority;
            break;
            
        case ADC_Data_5:
            IPC16bits.ADCD5IS = input_subpriority;
            break;
            
        case ADC_Data_6:
            IPC16bits.ADCD6IS = input_subpriority;
            break;
            
        case ADC_Data_7:
            IPC16bits.ADCD7IS = input_subpriority;
            break;
            
        case ADC_Data_8:
            IPC16bits.ADCD8IS = input_subpriority;
            break;
            
        case ADC_Data_9:
            IPC17bits.ADCD9IS = input_subpriority;
            break;
            
        case ADC_Data_10:
            IPC17bits.ADCD10IS = input_subpriority;
            break;
            
        case ADC_Data_11:
            IPC17bits.ADCD11IS = input_subpriority;
            break;
            
        case ADC_Data_12:
            IPC17bits.ADCD12IS = input_subpriority;
            break;
            
        case ADC_Data_13:
            IPC18bits.ADCD13IS = input_subpriority;
            break;
            
        case ADC_Data_14:
            IPC18bits.ADCD14IS = input_subpriority;
            break;
            
        case ADC_Data_15:
            IPC18bits.ADCD15IS = input_subpriority;
            break;
            
        case ADC_Data_16:
            IPC18bits.ADCD16IS = input_subpriority;
            break;
            
        case ADC_Data_17:
            IPC19bits.ADCD17IS = input_subpriority;
            break;
            
        case ADC_Data_18:
            IPC19bits.ADCD18IS = input_subpriority;
            break;
            
        case ADC_Data_19:
            IPC19bits.ADCD19IS = input_subpriority;
            break;
            
        case ADC_Data_20:
            IPC19bits.ADCD20IS = input_subpriority;
            break;
            
        case ADC_Data_21:
            IPC20bits.ADCD21IS = input_subpriority;
            break;
            
        case ADC_Data_22:
            IPC20bits.ADCD22IS = input_subpriority;
            break;
            
        case ADC_Data_23:
            IPC20bits.ADCD23IS = input_subpriority;
            break;
            
        case ADC_Data_24:
            IPC20bits.ADCD24IS = input_subpriority;
            break;
            
        case ADC_Data_25:
            IPC21bits.ADCD25IS = input_subpriority;
            break;
            
        case ADC_Data_26:
            IPC21bits.ADCD26IS = input_subpriority;
            break;
            
        case ADC_Data_27:
            IPC21bits.ADCD27IS = input_subpriority;
            break;
            
        case ADC_Data_28:
            IPC21bits.ADCD28IS = input_subpriority;
            break;
            
        case ADC_Data_29:
            IPC22bits.ADCD29IS = input_subpriority;
            break;
            
        case ADC_Data_30:
            IPC22bits.ADCD30IS = input_subpriority;
            break;
            
        case ADC_Data_31:
            IPC22bits.ADCD31IS = input_subpriority;
            break;
            
        case ADC_Data_32:
            IPC22bits.ADCD32IS = input_subpriority;
            break;
            
        case ADC_Data_33:
            IPC23bits.ADCD33IS = input_subpriority;
            break;
            
        case ADC_Data_34:
            IPC23bits.ADCD34IS = input_subpriority;
            break;
            
        case ADC_Data_35:
            IPC23bits.ADCD35IS = input_subpriority;
            break;
            
        case ADC_Data_36:
            IPC23bits.ADCD36IS = input_subpriority;
            break;
            
        case ADC_Data_37:
            IPC24bits.ADCD37IS = input_subpriority;
            break;
            
        case ADC_Data_38:
            IPC24bits.ADCD38IS = input_subpriority;
            break;
            
        case ADC_Data_39:
            IPC24bits.ADCD39IS = input_subpriority;
            break;
            
        case ADC_Data_40:
            IPC24bits.ADCD40IS = input_subpriority;
            break;
            
        case ADC_Data_41:
            IPC25bits.ADCD41IS = input_subpriority;
            break;
            
        case ADC_Data_42:
            IPC25bits.ADCD42IS = input_subpriority;
            break;
            
        case ADC_Data_43:
            IPC25bits.ADCD43IS = input_subpriority;
            break;
            
        case ADC_Data_44:
            IPC25bits.ADCD44IS = input_subpriority;
            break;
            
        case Core_Performance_Counter_Interrupt:
            IPC26bits.CPCIS = input_subpriority;
            break;
            
        case Core_Fast_Debug_Channel_Interrupt:
            IPC26bits.CFDCIS = input_subpriority;
            break;
            
        case System_Bus_Protection_Violation:
            IPC26bits.SBIS = input_subpriority;
            break;
            
        case SPI1_Fault:
            IPC27bits.SPI1EIS = input_subpriority;
            break;
            
        case SPI1_Receive_Done:
            IPC27bits.SPI1RXIS = input_subpriority;
            break;
            
        case SPI1_Transfer_Done:
            IPC27bits.SPI1TXIS = input_subpriority;
            break;
            
        case UART1_Fault:
            IPC28bits.U1EIS = input_subpriority;
            break;
            
        case UART1_Receive_Done:
            IPC28bits.U1RXIS = input_subpriority;
            break;
            
        case UART1_Transfer_Done:
            IPC28bits.U1TXIS = input_subpriority;
            break;
            
        case I2C1_Bus_Collision_Event:
            IPC28bits.I2C1BIS = input_subpriority;
            break;
            
        case I2C1_Slave_Event:
            IPC29bits.I2C1SIS = input_subpriority;
            break;
            
        case I2C1_Master_Event:
            IPC29bits.I2C1MIS = input_subpriority;
            break;
            
        case PORTA_Input_Change_Interrupt:
            IPC29bits.CNAIS = input_subpriority;
            break;
            
        case PORTB_Input_Change_Interrupt:
            IPC29bits.CNBIS = input_subpriority;
            break;
            
        case PORTC_Input_Change_Interrupt:
            IPC30bits.CNCIS = input_subpriority;
            break;
            
        case PORTD_Input_Change_Interrupt:
            IPC30bits.CNDIS = input_subpriority;
            break;
            
        case PORTE_Input_Change_Interrupt:
            IPC30bits.CNEIS = input_subpriority;
            break;
            
        case PORTF_Input_Change_Interrupt:
            IPC30bits.CNFIS = input_subpriority;
            break;
            
        case PORTG_Input_Change_Interrupt:
            IPC31bits.CNGIS = input_subpriority;
            break;
            
        case PORTH_Input_Change_Interrupt:
            IPC31bits.CNHIS = input_subpriority;
            break;
            
        case PORTJ_Input_Change_Interrupt:
            IPC31bits.CNJIS = input_subpriority;
            break;
            
        case PORTK_Input_Change_Interrupt:
            IPC31bits.CNKIS = input_subpriority;
            break;
            
        case Parallel_Master_Port:
            IPC32bits.PMPIS = input_subpriority;
            break;
            
        case Parallel_Master_Port_Error:
            IPC32bits.PMPEIS = input_subpriority;
            break;
            
        case Comparator_1_Interrupt:
            IPC32bits.CMP1IS = input_subpriority;
            break;
            
        case Comparator_2_Interrupt:
            IPC32bits.CMP2IS = input_subpriority;
            break;
            
        case USB_General_Event:
            IPC33bits.USBIS = input_subpriority;
            break;
            
        case USB_DMA_Event:
            IPC33bits.USBDMAIS = input_subpriority;
            break;
            
        case DMA_Channel_0:
            IPC33bits.DMA0IS = input_subpriority;
            break;
            
        case DMA_Channel_1:
            IPC33bits.DMA1IS = input_subpriority;
            break;
            
        case DMA_Channel_2:
            IPC34bits.DMA2IS = input_subpriority;
            break;
            
        case DMA_Channel_3:
            IPC34bits.DMA3IS = input_subpriority;
            break;
            
        case DMA_Channel_4:
            IPC34bits.DMA4IS = input_subpriority;
            break;
            
        case DMA_Channel_5:
            IPC34bits.DMA5IS = input_subpriority;
            break;
            
        case DMA_Channel_6:
            IPC35bits.DMA6IS = input_subpriority;
            break;
            
        case DMA_Channel_7:
            IPC35bits.DMA7IS = input_subpriority;
            break;
            
        case SPI2_Fault:
            IPC35bits.SPI2EIS = input_subpriority;
            break;
            
        case SPI2_Receive_Done:
            IPC35bits.SPI2RXIS = input_subpriority;
            break;
            
        case SPI2_Transfer_Done:
            IPC36bits.SPI2TXIS = input_subpriority;
            break;
            
        case UART2_Fault:
            IPC36bits.U2EIS = input_subpriority;
            break;
            
        case UART2_Receive_Done:
            IPC36bits.U2RXIS = input_subpriority;
            break;
            
        case UART2_Transfer_Done:
            IPC36bits.U2TXIS = input_subpriority;
            break;
            
        case I2C2_Bus_Collision_Event:
            IPC37bits.I2C2BIS = input_subpriority;
            break;
            
        case I2C2_Slave_Event:
            IPC37bits.I2C2SIS = input_subpriority;
            break;
            
        case I2C2_Master_Event:
            IPC37bits.I2C2MIS = input_subpriority;
            break;
            
        case Control_Area_Network_1:
            IPC37bits.CAN1IS = input_subpriority;
            break;
                    
        case Control_Area_Network_2:
            IPC38bits.CAN2IS = input_subpriority;
            break;
            
        case Ethernet_Interrupt:
            IPC38bits.ETHIS = input_subpriority;
            break;
            
        case SPI3_Fault:
            IPC38bits.SPI3EIS = input_subpriority;
            break;
            
        case SPI3_Receive_Done:
            IPC38bits.SPI3RXIS = input_subpriority;
            break;
            
        case SPI3_Transfer_Done:
            IPC39bits.SPI3TXIS = input_subpriority;
            break;
            
        case UART3_Fault:
            IPC39bits.U3EIS = input_subpriority;
            break;
            
        case UART3_Receive_Done:
            IPC39bits.U3RXIS = input_subpriority;
            break;
            
        case UART3_Transfer_Done:
            IPC39bits.U3TXIS = input_subpriority;
            break;
            
        case I2C3_Bus_Collision_Event:
            IPC40bits.I2C3BIS = input_subpriority;
            break;
            
        case I2C3_Slave_Event:
            IPC40bits.I2C3SIS = input_subpriority;
            break;
            
        case I2C3_Master_Event:
            IPC40bits.I2C3MIS = input_subpriority;
            break;
            
        case SPI4_Fault:
            IPC40bits.SPI4EIS = input_subpriority;
            break;
            
        case SPI4_Receive_Done:
            IPC41bits.SPI4RXIS = input_subpriority;
            break;
            
        case SPI4_Transfer_Done:
            IPC41bits.SPI4TXIS = input_subpriority;
            break;
            
        case Real_Time_Clock:
            IPC41bits.RTCCIS = input_subpriority;
            break;
            
        case Flash_Control_Event:
            IPC41bits.FCEIS = input_subpriority;
            break;
            
        case Prefetch_Module_SEC_Event:
            IPC42bits.PREIS = input_subpriority;
            break;
            
        case SQI1_Event:
            IPC42bits.SQI1IS = input_subpriority;
            break;
            
        case UART4_Fault:
            IPC42bits.U4EIS = input_subpriority;
            break;
            
        case UART4_Receive_Done:
            IPC42bits.U4RXIS = input_subpriority;
            break;
            
        case UART4_Transfer_Done:
            IPC43bits.U4TXIS = input_subpriority;
            break;
            
        case I2C4_Bus_Collision_Event:
            IPC43bits.I2C4BIS = input_subpriority;
            break;
            
        case I2C4_Slave_Event:
            IPC43bits.I2C4SIS = input_subpriority;
            break;
            
        case I2C4_Master_Event:
            IPC43bits.I2C4MIS = input_subpriority;
            break;
            
        case SPI5_Fault:
            IPC44bits.SPI5EIS = input_subpriority;
            break;
            
        case SPI5_Receive_Done:
            IPC44bits.SPI5RXIS = input_subpriority;
            break;
            
        case SPI5_Transfer_Done:
            IPC44bits.SPI5TXIS = input_subpriority;
            break;
            
        case UART5_Fault:
            IPC44bits.U5EIS = input_subpriority;
            break;
            
        case UART5_Receive_Done:
            IPC45bits.U5RXIS = input_subpriority;
            break;
            
        case UART5_Transfer_Done:
            IPC45bits.U5TXIS = input_subpriority;
            break;
            
        case I2C5_Bus_Collision_Event:
            IPC45bits.I2C5BIS = input_subpriority;
            break;
            
        case I2C5_Slave_Event:
            IPC45bits.I2C5SIS = input_subpriority;
            break;
            
        case I2C5_Master_Event:
            IPC46bits.I2C5MIS = input_subpriority;
            break;
        
        case SPI6_Fault:
            IPC46bits.SPI6EIS = input_subpriority;
            break;
            
        case SPI6_Receive_Done:
            IPC46bits.SPI6RXIS = input_subpriority;
            break;
            
        case SPI6_Transfer_Done:
            IPC46bits.SPI6TXIS = input_subpriority;
            break;
            
        case UART6_Fault:
            IPC47bits.U6EIS = input_subpriority;
            break;
            
        case UART6_Receive_Done:
            IPC47bits.U6RXIS = input_subpriority;
            break;
            
        case UART6_Transfer_Done:
            IPC47bits.U6TXIS = input_subpriority;
            break;
        
        case ADC_End_Of_Scan_Ready:
            IPC48bits.ADCEOSIS = input_subpriority;
            break;
            
        case ADC_Analog_Circuits_Ready:
            IPC48bits.ADCARDYIS = input_subpriority;
            break;
            
        case ADC_Update_Ready:
            IPC48bits.ADCURDYIS = input_subpriority;
            break;
            
        case ADC_Group_Early_Interrupt_Request:
            IPC49bits.ADCGRPIS = input_subpriority;
            break;
            
        case ADC0_Early_Interrupt:
            IPC49bits.ADC0EIS = input_subpriority;
            break;
            
        case ADC1_Early_Interrupt:
            IPC49bits.ADC1EIS = input_subpriority;
            break;
            
        case ADC2_Early_Interrupt:
            IPC50bits.ADC2EIS = input_subpriority;
            break;
            
        case ADC3_Early_Interrupt:
            IPC50bits.ADC3EIS = input_subpriority;
            break;
            
        case ADC4_Early_Interrupt:
            IPC50bits.ADC4EIS = input_subpriority;
            break;
            
        case ADC7_Early_Interrupt:
            IPC51bits.ADC7EIS = input_subpriority;
            break;
            
        case ADC0_Warm_Interrupt:
            IPC51bits.ADC0WIS = input_subpriority;
            break;
            
        case ADC1_Warm_Interrupt:
            IPC51bits.ADC1WIS = input_subpriority;
            break;
            
        case ADC2_Warm_Interrupt:
            IPC52bits.ADC2WIS = input_subpriority;
            break;
            
        case ADC3_Warm_Interrupt:
            IPC52bits.ADC3WIS = input_subpriority;
            break;
            
        case ADC4_Warm_Interrupt:
            IPC52bits.ADC4WIS = input_subpriority;
            break;
            
        case ADC7_Warm_Interrupt:
            IPC53bits.ADC7WIS = input_subpriority;
            break;
            
        default:
            break;
            
    }
    
    
    

}

// This function returns the given interrupt priority
uint8_t getInterruptPriority(interrupt_source_t input_interrupt) {
 
    // Decide which interrupt control bits to return based on which interrupt
    switch (input_interrupt) {
        
        case Core_Timer_Interrupt:
            return IPC0bits.CTIP;
            break;
            
        case Core_Software_Interrupt_0:
            return IPC0bits.CS0IP;
            break;
            
        case Core_Software_Interrupt_1:
            return IPC0bits.CS1IP;
            break;
            
        case External_Interrupt_0:
            return IPC0bits.INT0IP;
            break;
            
        case Timer1:
            return IPC1bits.T1IP;
            break;
            
        case Input_Capture_1_Error:
            return IPC1bits.IC1EIP;
            break;
            
        case Input_Capture_1:
            return IPC1bits.IC1IP;
            break;
            
        case Output_Compare_1:
            return IPC1bits.OC1IP;
            break;
            
        case External_Interrupt_1:
            return IPC2bits.INT1IP;
            break;
            
        case Timer2:
            return IPC2bits.T2IP;
            break;
            
        case Input_Capture_2_Error:
            return IPC2bits.IC2EIP;
            break;
            
        case Input_Capture_2:
            return IPC2bits.IC2IP;
            break;
            
        case Output_Compare_2:
            return IPC3bits.OC2IP;
            break;
            
        case External_Interrupt_2:
            return IPC3bits.INT2IP;
            break;
            
        case Timer3:
            return IPC3bits.T3IP;
            break;
            
        case Input_Capture_3_Error:
            return IPC3bits.IC3EIP;
            break;
            
        case Input_Capture_3:
            return IPC4bits.IC3IP;
            break;
            
        case Output_Compare_3:
            return IPC4bits.OC3IP;
            break;
            
        case External_Interrupt_3:
            return IPC4bits.INT3IP;
            break;
            
        case Timer4:
            return IPC4bits.T4IP;
            break;
            
        case Input_Capture_4_Error:
            return IPC5bits.IC4EIP;
            break;
            
        case Input_Capture_4:
            return IPC5bits.IC4IP;
            break;
            
        case Output_Compare_4:
            return IPC5bits.OC4IP;
            break;
            
        case External_Interrupt_4:
            return IPC5bits.INT4IP;
            break;
            
        case Timer5:
            return IPC6bits.T5IP;
            break;
            
        case Input_Capture_5_Error:
            return IPC6bits.IC5EIP;
            break;
            
        case Input_Capture_5:
            return IPC6bits.IC5IP;
            break;
            
        case Output_Compare_5:
            return IPC6bits.OC5IP;
            break;
            
        case Timer6:
            return IPC7bits.T6IP;
            break;
            
        case Input_Capture_6_Error:
            return IPC7bits.IC6EIP;
            break;
            
        case Input_Capture_6:
            return IPC7bits.IC6IP;
            break;
            
        case Output_Compare_6:
            return IPC7bits.OC6IP;
            break;
            
        case Timer7:
            return IPC8bits.T7IP;
            break;
            
        case Input_Capture_7_Error:
            return IPC8bits.IC7EIP;
            break;
            
        case Input_Capture_7:
            return IPC8bits.IC7IP;
            break;
            
        case Output_Compare_7:
            return IPC8bits.OC7IP;
            break;
            
        case Timer8:
            return IPC9bits.T8IP;
            break;
            
        case Input_Capture_8_Error:
            return IPC9bits.IC8EIP;
            break;
            
        case Input_Capture_8:
            return IPC9bits.IC8IP;
            break;
            
        case Output_Compare_8:
            return IPC9bits.OC8IP;
            break;
            
        case Timer9:
            return IPC10bits.T9IP;
            break;
            
        case Input_Capture_9_Error:
            return IPC10bits.IC9EIP;
            break;
            
        case Input_Capture_9:
            return IPC10bits.OC9IP;
            break;
            
        case Output_Compare_9:
            return IPC10bits.OC9IP;
            break;
            
        case ADC_Global_Interrupt:
            return IPC11bits.ADCIP;
            break;
            
        case ADC_FIFO_Data_Ready_Interrupt:
            return IPC11bits.ADCFIFOIP;
            break;
            
        case ADC_Digital_Comparator_1:
            return IPC11bits.ADCDC1IP;
            break;
        
        case ADC_Digital_Comparator_2:
            return IPC11bits.ADCDC2IP;
            break;
            
        case ADC_Digital_Comparator_3:
            return IPC12bits.ADCDC3IP;
            break;
            
        case ADC_Digital_Comparator_4:
            return IPC12bits.ADCDC4IP;
            break;
            
        case ADC_Digital_Comparator_5:
            return IPC12bits.ADCDC5IP;
            break;
            
        case ADC_Digital_Comparator_6:
            return IPC12bits.ADCDC6IP;
            break;
            
        case ADC_Digital_Filter_1:
            return IPC13bits.ADCDF1IP;
            break;
            
        case ADC_Digital_Filter_2:
            return IPC13bits.ADCDF2IP;
            break;
            
        case ADC_Digital_Filter_3:
            return IPC13bits.ADCDF3IP;
            break;
            
        case ADC_Digital_Filter_4:
            return IPC13bits.ADCDF4IP;
            break;
            
        case ADC_Digital_Filter_5:
            return IPC14bits.ADCDF5IP;
            break;
            
        case ADC_Digital_Filter_6:
            return IPC14bits.ADCDF6IP;
            break;
            
        case ADC_Fault:
            return IPC14bits.ADCFLTIP;
            break;
            
        case ADC_Data_0:
            return IPC14bits.ADCD0IP;
            break;
            
        case ADC_Data_1:
            return IPC15bits.ADCD1IP;
            break;
            
        case ADC_Data_2:
            return IPC15bits.ADCD2IP;
            break;
            
        case ADC_Data_3:
            return IPC15bits.ADCD3IP;
            break;
            
        case ADC_Data_4:
            return IPC15bits.ADCD4IP;
            break;
            
        case ADC_Data_5:
            return IPC16bits.ADCD5IP;
            break;
            
        case ADC_Data_6:
            return IPC16bits.ADCD6IP;
            break;
            
        case ADC_Data_7:
            return IPC16bits.ADCD7IP;
            break;
            
        case ADC_Data_8:
            return IPC16bits.ADCD8IP;
            break;
            
        case ADC_Data_9:
            return IPC17bits.ADCD9IP;
            break;
            
        case ADC_Data_10:
            return IPC17bits.ADCD10IP;
            break;
            
        case ADC_Data_11:
            return IPC17bits.ADCD11IP;
            break;
            
        case ADC_Data_12:
            return IPC17bits.ADCD12IP;
            break;
            
        case ADC_Data_13:
            return IPC18bits.ADCD13IP;
            break;
            
        case ADC_Data_14:
            return IPC18bits.ADCD14IP;
            break;
            
        case ADC_Data_15:
            return IPC18bits.ADCD15IP;
            break;
            
        case ADC_Data_16:
            return IPC18bits.ADCD16IP;
            break;
            
        case ADC_Data_17:
            return IPC19bits.ADCD17IP;
            break;
            
        case ADC_Data_18:
            return IPC19bits.ADCD18IP;
            break;
            
        case ADC_Data_19:
            return IPC19bits.ADCD19IP;
            break;
            
        case ADC_Data_20:
            return IPC19bits.ADCD20IP;
            break;
            
        case ADC_Data_21:
            return IPC20bits.ADCD21IP;
            break;
            
        case ADC_Data_22:
            return IPC20bits.ADCD22IP;
            break;
            
        case ADC_Data_23:
            return IPC20bits.ADCD23IP;
            break;
            
        case ADC_Data_24:
            return IPC20bits.ADCD24IP;
            break;
            
        case ADC_Data_25:
            return IPC21bits.ADCD25IP;
            break;
            
        case ADC_Data_26:
            return IPC21bits.ADCD26IP;
            break;
            
        case ADC_Data_27:
            return IPC21bits.ADCD27IP;
            break;
            
        case ADC_Data_28:
            return IPC21bits.ADCD28IP;
            break;
            
        case ADC_Data_29:
            return IPC22bits.ADCD29IP;
            break;
            
        case ADC_Data_30:
            return IPC22bits.ADCD30IP;
            break;
            
        case ADC_Data_31:
            return IPC22bits.ADCD31IP;
            break;
            
        case ADC_Data_32:
            return IPC22bits.ADCD32IP;
            break;
            
        case ADC_Data_33:
            return IPC23bits.ADCD33IP;
            break;
            
        case ADC_Data_34:
            return IPC23bits.ADCD34IP;
            break;
            
        case ADC_Data_35:
            return IPC23bits.ADCD35IP;
            break;
            
        case ADC_Data_36:
            return IPC23bits.ADCD36IP;
            break;
            
        case ADC_Data_37:
            return IPC24bits.ADCD37IP;
            break;
            
        case ADC_Data_38:
            return IPC24bits.ADCD38IP;
            break;
            
        case ADC_Data_39:
            return IPC24bits.ADCD39IP;
            break;
            
        case ADC_Data_40:
            return IPC24bits.ADCD40IP;
            break;
            
        case ADC_Data_41:
            return IPC25bits.ADCD41IP;
            break;
            
        case ADC_Data_42:
            return IPC25bits.ADCD42IP;
            break;
            
        case ADC_Data_43:
            return IPC25bits.ADCD43IP;
            break;
            
        case ADC_Data_44:
            return IPC25bits.ADCD44IP;
            break;
            
        case Core_Performance_Counter_Interrupt:
            return IPC26bits.CPCIP;
            break;
            
        case Core_Fast_Debug_Channel_Interrupt:
            return IPC26bits.CFDCIP;
            break;
            
        case System_Bus_Protection_Violation:
            return IPC26bits.SBIP;
            break;
            
        case SPI1_Fault:
            return IPC27bits.SPI1EIP;
            break;
            
        case SPI1_Receive_Done:
            return IPC27bits.SPI1RXIP;
            break;
            
        case SPI1_Transfer_Done:
            return IPC27bits.SPI1TXIP;
            break;
            
        case UART1_Fault:
            return IPC28bits.U1EIP;
            break;
            
        case UART1_Receive_Done:
            return IPC28bits.U1RXIP;
            break;
            
        case UART1_Transfer_Done:
            return IPC28bits.U1TXIP;
            break;
            
        case I2C1_Bus_Collision_Event:
            return IPC28bits.I2C1BIP;
            break;
            
        case I2C1_Slave_Event:
            return IPC29bits.I2C1SIP;
            break;
            
        case I2C1_Master_Event:
            return IPC29bits.I2C1MIP;
            break;
            
        case PORTA_Input_Change_Interrupt:
            return IPC29bits.CNAIP;
            break;
            
        case PORTB_Input_Change_Interrupt:
            return IPC29bits.CNBIP;
            break;
            
        case PORTC_Input_Change_Interrupt:
            return IPC30bits.CNCIP;
            break;
            
        case PORTD_Input_Change_Interrupt:
            return IPC30bits.CNDIP;
            break;
            
        case PORTE_Input_Change_Interrupt:
            return IPC30bits.CNEIP;
            break;
            
        case PORTF_Input_Change_Interrupt:
            return IPC30bits.CNFIP;
            break;
            
        case PORTG_Input_Change_Interrupt:
            return IPC31bits.CNGIP;
            break;
            
        case PORTH_Input_Change_Interrupt:
            return IPC31bits.CNHIP;
            break;
            
        case PORTJ_Input_Change_Interrupt:
            return IPC31bits.CNJIP;
            break;
            
        case PORTK_Input_Change_Interrupt:
            return IPC31bits.CNKIP;
            break;
            
        case Parallel_Master_Port:
            return IPC32bits.PMPIP;
            break;
            
        case Parallel_Master_Port_Error:
            return IPC32bits.PMPEIP;
            break;
            
        case Comparator_1_Interrupt:
            return IPC32bits.CMP1IP;
            break;
            
        case Comparator_2_Interrupt:
            return IPC32bits.CMP2IP;
            break;
            
        case USB_General_Event:
            return IPC33bits.USBIP;
            break;
            
        case USB_DMA_Event:
            return IPC33bits.USBDMAIP;
            break;
            
        case DMA_Channel_0:
            return IPC33bits.DMA0IP;
            break;
            
        case DMA_Channel_1:
            return IPC33bits.DMA1IP;
            break;
            
        case DMA_Channel_2:
            return IPC34bits.DMA2IP;
            break;
            
        case DMA_Channel_3:
            return IPC34bits.DMA3IP;
            break;
            
        case DMA_Channel_4:
            return IPC34bits.DMA4IP;
            break;
            
        case DMA_Channel_5:
            return IPC34bits.DMA5IP;
            break;
            
        case DMA_Channel_6:
            return IPC35bits.DMA6IP;
            break;
            
        case DMA_Channel_7:
            return IPC35bits.DMA7IP;
            break;
            
        case SPI2_Fault:
            return IPC35bits.SPI2EIP;
            break;
            
        case SPI2_Receive_Done:
            return IPC35bits.SPI2RXIP;
            break;
            
        case SPI2_Transfer_Done:
            return IPC36bits.SPI2TXIP;
            break;
            
        case UART2_Fault:
            return IPC36bits.U2EIP;
            break;
            
        case UART2_Receive_Done:
            return IPC36bits.U2RXIP;
            break;
            
        case UART2_Transfer_Done:
            return IPC36bits.U2TXIP;
            break;
            
        case I2C2_Bus_Collision_Event:
            return IPC37bits.I2C2BIP;
            break;
            
        case I2C2_Slave_Event:
            return IPC37bits.I2C2SIP;
            break;
            
        case I2C2_Master_Event:
            return IPC37bits.I2C2MIP;
            break;
            
        case Control_Area_Network_1:
            return IPC37bits.CAN1IP;
            break;
                    
        case Control_Area_Network_2:
            return IPC38bits.CAN2IP;
            break;
            
        case Ethernet_Interrupt:
            return IPC38bits.ETHIP;
            break;
            
        case SPI3_Fault:
            return IPC38bits.SPI3EIP;
            break;
            
        case SPI3_Receive_Done:
            return IPC38bits.SPI3RXIP;
            break;
            
        case SPI3_Transfer_Done:
            return IPC39bits.SPI3TXIP;
            break;
            
        case UART3_Fault:
            return IPC39bits.U3EIP;
            break;
            
        case UART3_Receive_Done:
            return IPC39bits.U3RXIP;
            break;
            
        case UART3_Transfer_Done:
            return IPC39bits.U3TXIP;
            break;
            
        case I2C3_Bus_Collision_Event:
            return IPC40bits.I2C3BIP;
            break;
            
        case I2C3_Slave_Event:
            return IPC40bits.I2C3SIP;
            break;
            
        case I2C3_Master_Event:
            return IPC40bits.I2C3MIP;
            break;
            
        case SPI4_Fault:
            return IPC40bits.SPI4EIP;
            break;
            
        case SPI4_Receive_Done:
            return IPC41bits.SPI4RXIP;
            break;
            
        case SPI4_Transfer_Done:
            return IPC41bits.SPI4TXIP;
            break;
            
        case Real_Time_Clock:
            return IPC41bits.RTCCIP;
            break;
            
        case Flash_Control_Event:
            return IPC41bits.FCEIP;
            break;
            
        case Prefetch_Module_SEC_Event:
            return IPC42bits.PREIP;
            break;
            
        case SQI1_Event:
            return IPC42bits.SQI1IP;
            break;
            
        case UART4_Fault:
            return IPC42bits.U4EIP;
            break;
            
        case UART4_Receive_Done:
            return IPC42bits.U4RXIP;
            break;
            
        case UART4_Transfer_Done:
            return IPC43bits.U4TXIP;
            break;
            
        case I2C4_Bus_Collision_Event:
            return IPC43bits.I2C4BIP;
            break;
            
        case I2C4_Slave_Event:
            return IPC43bits.I2C4SIP;
            break;
            
        case I2C4_Master_Event:
            return IPC43bits.I2C4MIP;
            break;
            
        case SPI5_Fault:
            return IPC44bits.SPI5EIP;
            break;
            
        case SPI5_Receive_Done:
            return IPC44bits.SPI5RXIP;
            break;
            
        case SPI5_Transfer_Done:
            return IPC44bits.SPI5TXIP;
            break;
            
        case UART5_Fault:
            return IPC44bits.U5EIP;
            break;
            
        case UART5_Receive_Done:
            return IPC45bits.U5RXIP;
            break;
            
        case UART5_Transfer_Done:
            return IPC45bits.U5TXIP;
            break;
            
        case I2C5_Bus_Collision_Event:
            return IPC45bits.I2C5BIP;
            break;
            
        case I2C5_Slave_Event:
            return IPC45bits.I2C5SIP;
            break;
            
        case I2C5_Master_Event:
            return IPC46bits.I2C5MIP;
            break;
        
        case SPI6_Fault:
            return IPC46bits.SPI6EIP;
            break;
            
        case SPI6_Receive_Done:
            return IPC46bits.SPI6RXIP;
            break;
            
        case SPI6_Transfer_Done:
            return IPC46bits.SPI6TXIP;
            break;
            
        case UART6_Fault:
            return IPC47bits.U6EIP;
            break;
            
        case UART6_Receive_Done:
            return IPC47bits.U6RXIP;
            break;
            
        case UART6_Transfer_Done:
            return IPC47bits.U6TXIP;
            break;
        
        case ADC_End_Of_Scan_Ready:
            return IPC48bits.ADCEOSIP;
            break;
            
        case ADC_Analog_Circuits_Ready:
            return IPC48bits.ADCARDYIP;
            break;
            
        case ADC_Update_Ready:
            return IPC48bits.ADCURDYIP;
            break;
            
        case ADC_Group_Early_Interrupt_Request:
            return IPC49bits.ADCGRPIP;
            break;
            
        case ADC0_Early_Interrupt:
            return IPC49bits.ADC0EIP;
            break;
            
        case ADC1_Early_Interrupt:
            return IPC49bits.ADC1EIP;
            break;
            
        case ADC2_Early_Interrupt:
            return IPC50bits.ADC2EIP;
            break;
            
        case ADC3_Early_Interrupt:
            return IPC50bits.ADC3EIP;
            break;
            
        case ADC4_Early_Interrupt:
            return IPC50bits.ADC4EIP;
            break;
            
        case ADC7_Early_Interrupt:
            return IPC51bits.ADC7EIP;
            break;
            
        case ADC0_Warm_Interrupt:
            return IPC51bits.ADC0WIP;
            break;
            
        case ADC1_Warm_Interrupt:
            return IPC51bits.ADC1WIP;
            break;
            
        case ADC2_Warm_Interrupt:
            return IPC52bits.ADC2WIP;
            break;
            
        case ADC3_Warm_Interrupt:
            return IPC52bits.ADC3WIP;
            break;
            
        case ADC4_Warm_Interrupt:
            return IPC52bits.ADC4WIP;
            break;
            
        case ADC7_Warm_Interrupt:
            return IPC53bits.ADC7WIP;
            break;
            
        default:
            return 0;
            break;
            
    }

    
}

// This function returns the given interrupt subpriority
uint8_t getInterruptSubriority(interrupt_source_t input_interrupt) {
 
    // Decide which interrupt control bits to manipulate based on which interrupt
    // is having its priority set
    switch (input_interrupt) {
        
        case Core_Timer_Interrupt:
            return IPC0bits.CTIS;
            break;
            
        case Core_Software_Interrupt_0:
            return IPC0bits.CS0IS;
            break;
            
        case Core_Software_Interrupt_1:
            return IPC0bits.CS1IS;
            break;
            
        case External_Interrupt_0:
            return IPC0bits.INT0IS;
            break;
            
        case Timer1:
            return IPC1bits.T1IS;
            break;
            
        case Input_Capture_1_Error:
            return IPC1bits.IC1EIS;
            break;
            
        case Input_Capture_1:
            return IPC1bits.IC1IS;
            break;
            
        case Output_Compare_1:
            return IPC1bits.OC1IS;
            break;
            
        case External_Interrupt_1:
            return IPC2bits.INT1IS;
            break;
            
        case Timer2:
            return IPC2bits.T2IS;
            break;
            
        case Input_Capture_2_Error:
            return IPC2bits.IC2EIS;
            break;
            
        case Input_Capture_2:
            return IPC2bits.IC2IS;
            break;
            
        case Output_Compare_2:
            return IPC3bits.OC2IS;
            break;
            
        case External_Interrupt_2:
            return IPC3bits.INT2IS;
            break;
            
        case Timer3:
            return IPC3bits.T3IS;
            break;
            
        case Input_Capture_3_Error:
            return IPC3bits.IC3EIS;
            break;
            
        case Input_Capture_3:
            return IPC4bits.IC3IS;
            break;
            
        case Output_Compare_3:
            return IPC4bits.OC3IS;
            break;
            
        case External_Interrupt_3:
            return IPC4bits.INT3IS;
            break;
            
        case Timer4:
            return IPC4bits.T4IS;
            break;
            
        case Input_Capture_4_Error:
            return IPC5bits.IC4EIS;
            break;
            
        case Input_Capture_4:
            return IPC5bits.IC4IS;
            break;
            
        case Output_Compare_4:
            return IPC5bits.OC4IS;
            break;
            
        case External_Interrupt_4:
            return IPC5bits.INT4IS;
            break;
            
        case Timer5:
            return IPC6bits.T5IS;
            break;
            
        case Input_Capture_5_Error:
            return IPC6bits.IC5EIS;
            break;
            
        case Input_Capture_5:
            return IPC6bits.IC5IS;
            break;
            
        case Output_Compare_5:
            return IPC6bits.OC5IS;
            break;
            
        case Timer6:
            return IPC7bits.T6IS;
            break;
            
        case Input_Capture_6_Error:
            return IPC7bits.IC6EIS;
            break;
            
        case Input_Capture_6:
            return IPC7bits.IC6IS;
            break;
            
        case Output_Compare_6:
            return IPC7bits.OC6IS;
            break;
            
        case Timer7:
            return IPC8bits.T7IS;
            break;
            
        case Input_Capture_7_Error:
            return IPC8bits.IC7EIS;
            break;
            
        case Input_Capture_7:
            return IPC8bits.IC7IS;
            break;
            
        case Output_Compare_7:
            return IPC8bits.OC7IS;
            break;
            
        case Timer8:
            return IPC9bits.T8IS;
            break;
            
        case Input_Capture_8_Error:
            return IPC9bits.IC8EIS;
            break;
            
        case Input_Capture_8:
            return IPC9bits.IC8IS;
            break;
            
        case Output_Compare_8:
            return IPC9bits.OC8IS;
            break;
            
        case Timer9:
            return IPC10bits.T9IS;
            break;
            
        case Input_Capture_9_Error:
            return IPC10bits.IC9EIS;
            break;
            
        case Input_Capture_9:
            return IPC10bits.OC9IS;
            break;
            
        case Output_Compare_9:
            return IPC10bits.OC9IS;
            break;
            
        case ADC_Global_Interrupt:
            return IPC11bits.ADCIS;
            break;
            
        case ADC_FIFO_Data_Ready_Interrupt:
            return IPC11bits.ADCFIFOIS;
            break;
            
        case ADC_Digital_Comparator_1:
            return IPC11bits.ADCDC1IS;
            break;
        
        case ADC_Digital_Comparator_2:
            return IPC11bits.ADCDC2IS;
            break;
            
        case ADC_Digital_Comparator_3:
            return IPC12bits.ADCDC3IS;
            break;
            
        case ADC_Digital_Comparator_4:
            return IPC12bits.ADCDC4IS;
            break;
            
        case ADC_Digital_Comparator_5:
            return IPC12bits.ADCDC5IS;
            break;
            
        case ADC_Digital_Comparator_6:
            return IPC12bits.ADCDC6IS;
            break;
            
        case ADC_Digital_Filter_1:
            return IPC13bits.ADCDF1IS;
            break;
            
        case ADC_Digital_Filter_2:
            return IPC13bits.ADCDF2IS;
            break;
            
        case ADC_Digital_Filter_3:
            return IPC13bits.ADCDF3IS;
            break;
            
        case ADC_Digital_Filter_4:
            return IPC13bits.ADCDF4IS;
            break;
            
        case ADC_Digital_Filter_5:
            return IPC14bits.ADCDF5IS;
            break;
            
        case ADC_Digital_Filter_6:
            return IPC14bits.ADCDF6IS;
            break;
            
        case ADC_Fault:
            return IPC14bits.ADCFLTIS;
            break;
            
        case ADC_Data_0:
            return IPC14bits.ADCD0IS;
            break;
            
        case ADC_Data_1:
            return IPC15bits.ADCD1IS;
            break;
            
        case ADC_Data_2:
            return IPC15bits.ADCD2IS;
            break;
            
        case ADC_Data_3:
            return IPC15bits.ADCD3IS;
            break;
            
        case ADC_Data_4:
            return IPC15bits.ADCD4IS;
            break;
            
        case ADC_Data_5:
            return IPC16bits.ADCD5IS;
            break;
            
        case ADC_Data_6:
            return IPC16bits.ADCD6IS;
            break;
            
        case ADC_Data_7:
            return IPC16bits.ADCD7IS;
            break;
            
        case ADC_Data_8:
            return IPC16bits.ADCD8IS;
            break;
            
        case ADC_Data_9:
            return IPC17bits.ADCD9IS;
            break;
            
        case ADC_Data_10:
            return IPC17bits.ADCD10IS;
            break;
            
        case ADC_Data_11:
            return IPC17bits.ADCD11IS;
            break;
            
        case ADC_Data_12:
            return IPC17bits.ADCD12IS;
            break;
            
        case ADC_Data_13:
            return IPC18bits.ADCD13IS;
            break;
            
        case ADC_Data_14:
            return IPC18bits.ADCD14IS;
            break;
            
        case ADC_Data_15:
            return IPC18bits.ADCD15IS;
            break;
            
        case ADC_Data_16:
            return IPC18bits.ADCD16IS;
            break;
            
        case ADC_Data_17:
            return IPC19bits.ADCD17IS;
            break;
            
        case ADC_Data_18:
            return IPC19bits.ADCD18IS;
            break;
            
        case ADC_Data_19:
            return IPC19bits.ADCD19IS;
            break;
            
        case ADC_Data_20:
            return IPC19bits.ADCD20IS;
            break;
            
        case ADC_Data_21:
            return IPC20bits.ADCD21IS;
            break;
            
        case ADC_Data_22:
            return IPC20bits.ADCD22IS;
            break;
            
        case ADC_Data_23:
            return IPC20bits.ADCD23IS;
            break;
            
        case ADC_Data_24:
            return IPC20bits.ADCD24IS;
            break;
            
        case ADC_Data_25:
            return IPC21bits.ADCD25IS;
            break;
            
        case ADC_Data_26:
            return IPC21bits.ADCD26IS;
            break;
            
        case ADC_Data_27:
            return IPC21bits.ADCD27IS;
            break;
            
        case ADC_Data_28:
            return IPC21bits.ADCD28IS;
            break;
            
        case ADC_Data_29:
            return IPC22bits.ADCD29IS;
            break;
            
        case ADC_Data_30:
            return IPC22bits.ADCD30IS;
            break;
            
        case ADC_Data_31:
            return IPC22bits.ADCD31IS;
            break;
            
        case ADC_Data_32:
            return IPC22bits.ADCD32IS;
            break;
            
        case ADC_Data_33:
            return IPC23bits.ADCD33IS;
            break;
            
        case ADC_Data_34:
            return IPC23bits.ADCD34IS;
            break;
            
        case ADC_Data_35:
            return IPC23bits.ADCD35IS;
            break;
            
        case ADC_Data_36:
            return IPC23bits.ADCD36IS;
            break;
            
        case ADC_Data_37:
            return IPC24bits.ADCD37IS;
            break;
            
        case ADC_Data_38:
            return IPC24bits.ADCD38IS;
            break;
            
        case ADC_Data_39:
            return IPC24bits.ADCD39IS;
            break;
            
        case ADC_Data_40:
            return IPC24bits.ADCD40IS;
            break;
            
        case ADC_Data_41:
            return IPC25bits.ADCD41IS;
            break;
            
        case ADC_Data_42:
            return IPC25bits.ADCD42IS;
            break;
            
        case ADC_Data_43:
            return IPC25bits.ADCD43IS;
            break;
            
        case ADC_Data_44:
            return IPC25bits.ADCD44IS;
            break;
            
        case Core_Performance_Counter_Interrupt:
            return IPC26bits.CPCIS;
            break;
            
        case Core_Fast_Debug_Channel_Interrupt:
            return IPC26bits.CFDCIS;
            break;
            
        case System_Bus_Protection_Violation:
            return IPC26bits.SBIS;
            break;
            
        case SPI1_Fault:
            return IPC27bits.SPI1EIS;
            break;
            
        case SPI1_Receive_Done:
            return IPC27bits.SPI1RXIS;
            break;
            
        case SPI1_Transfer_Done:
            return IPC27bits.SPI1TXIS;
            break;
            
        case UART1_Fault:
            return IPC28bits.U1EIS;
            break;
            
        case UART1_Receive_Done:
            return IPC28bits.U1RXIS;
            break;
            
        case UART1_Transfer_Done:
            return IPC28bits.U1TXIS;
            break;
            
        case I2C1_Bus_Collision_Event:
            return IPC28bits.I2C1BIS;
            break;
            
        case I2C1_Slave_Event:
            return IPC29bits.I2C1SIS;
            break;
            
        case I2C1_Master_Event:
            return IPC29bits.I2C1MIS;
            break;
            
        case PORTA_Input_Change_Interrupt:
            return IPC29bits.CNAIS;
            break;
            
        case PORTB_Input_Change_Interrupt:
            return IPC29bits.CNBIS;
            break;
            
        case PORTC_Input_Change_Interrupt:
            return IPC30bits.CNCIS;
            break;
            
        case PORTD_Input_Change_Interrupt:
            return IPC30bits.CNDIS;
            break;
            
        case PORTE_Input_Change_Interrupt:
            return IPC30bits.CNEIS;
            break;
            
        case PORTF_Input_Change_Interrupt:
            return IPC30bits.CNFIS;
            break;
            
        case PORTG_Input_Change_Interrupt:
            return IPC31bits.CNGIS;
            break;
            
        case PORTH_Input_Change_Interrupt:
            return IPC31bits.CNHIS;
            break;
            
        case PORTJ_Input_Change_Interrupt:
            return IPC31bits.CNJIS;
            break;
            
        case PORTK_Input_Change_Interrupt:
            return IPC31bits.CNKIS;
            break;
            
        case Parallel_Master_Port:
            return IPC32bits.PMPIS;
            break;
            
        case Parallel_Master_Port_Error:
            return IPC32bits.PMPEIS;
            break;
            
        case Comparator_1_Interrupt:
            return IPC32bits.CMP1IS;
            break;
            
        case Comparator_2_Interrupt:
            return IPC32bits.CMP2IS;
            break;
            
        case USB_General_Event:
            return IPC33bits.USBIS;
            break;
            
        case USB_DMA_Event:
            return IPC33bits.USBDMAIS;
            break;
            
        case DMA_Channel_0:
            return IPC33bits.DMA0IS;
            break;
            
        case DMA_Channel_1:
            return IPC33bits.DMA1IS;
            break;
            
        case DMA_Channel_2:
            return IPC34bits.DMA2IS;
            break;
            
        case DMA_Channel_3:
            return IPC34bits.DMA3IS;
            break;
            
        case DMA_Channel_4:
            return IPC34bits.DMA4IS;
            break;
            
        case DMA_Channel_5:
            return IPC34bits.DMA5IS;
            break;
            
        case DMA_Channel_6:
            return IPC35bits.DMA6IS;
            break;
            
        case DMA_Channel_7:
            return IPC35bits.DMA7IS;
            break;
            
        case SPI2_Fault:
            return IPC35bits.SPI2EIS;
            break;
            
        case SPI2_Receive_Done:
            return IPC35bits.SPI2RXIS;
            break;
            
        case SPI2_Transfer_Done:
            return IPC36bits.SPI2TXIS;
            break;
            
        case UART2_Fault:
            return IPC36bits.U2EIS;
            break;
            
        case UART2_Receive_Done:
            return IPC36bits.U2RXIS;
            break;
            
        case UART2_Transfer_Done:
            return IPC36bits.U2TXIS;
            break;
            
        case I2C2_Bus_Collision_Event:
            return IPC37bits.I2C2BIS;
            break;
            
        case I2C2_Slave_Event:
            return IPC37bits.I2C2SIS;
            break;
            
        case I2C2_Master_Event:
            return IPC37bits.I2C2MIS;
            break;
            
        case Control_Area_Network_1:
            return IPC37bits.CAN1IS;
            break;
                    
        case Control_Area_Network_2:
            return IPC38bits.CAN2IS;
            break;
            
        case Ethernet_Interrupt:
            return IPC38bits.ETHIS;
            break;
            
        case SPI3_Fault:
            return IPC38bits.SPI3EIS;
            break;
            
        case SPI3_Receive_Done:
            return IPC38bits.SPI3RXIS;
            break;
            
        case SPI3_Transfer_Done:
            return IPC39bits.SPI3TXIS;
            break;
            
        case UART3_Fault:
            return IPC39bits.U3EIS;
            break;
            
        case UART3_Receive_Done:
            return IPC39bits.U3RXIS;
            break;
            
        case UART3_Transfer_Done:
            return IPC39bits.U3TXIS;
            break;
            
        case I2C3_Bus_Collision_Event:
            return IPC40bits.I2C3BIS;
            break;
            
        case I2C3_Slave_Event:
            return IPC40bits.I2C3SIS;
            break;
            
        case I2C3_Master_Event:
            return IPC40bits.I2C3MIS;
            break;
            
        case SPI4_Fault:
            return IPC40bits.SPI4EIS;
            break;
            
        case SPI4_Receive_Done:
            return IPC41bits.SPI4RXIS;
            break;
            
        case SPI4_Transfer_Done:
            return IPC41bits.SPI4TXIS;
            break;
            
        case Real_Time_Clock:
            return IPC41bits.RTCCIS;
            break;
            
        case Flash_Control_Event:
            return IPC41bits.FCEIS;
            break;
            
        case Prefetch_Module_SEC_Event:
            return IPC42bits.PREIS;
            break;
            
        case SQI1_Event:
            return IPC42bits.SQI1IS;
            break;
            
        case UART4_Fault:
            return IPC42bits.U4EIS;
            break;
            
        case UART4_Receive_Done:
            return IPC42bits.U4RXIS;
            break;
            
        case UART4_Transfer_Done:
            return IPC43bits.U4TXIS;
            break;
            
        case I2C4_Bus_Collision_Event:
            return IPC43bits.I2C4BIS;
            break;
            
        case I2C4_Slave_Event:
            return IPC43bits.I2C4SIS;
            break;
            
        case I2C4_Master_Event:
            return IPC43bits.I2C4MIS;
            break;
            
        case SPI5_Fault:
            return IPC44bits.SPI5EIS;
            break;
            
        case SPI5_Receive_Done:
            return IPC44bits.SPI5RXIS;
            break;
            
        case SPI5_Transfer_Done:
            return IPC44bits.SPI5TXIS;
            break;
            
        case UART5_Fault:
            return IPC44bits.U5EIS;
            break;
            
        case UART5_Receive_Done:
            return IPC45bits.U5RXIS;
            break;
            
        case UART5_Transfer_Done:
            return IPC45bits.U5TXIS;
            break;
            
        case I2C5_Bus_Collision_Event:
            return IPC45bits.I2C5BIS;
            break;
            
        case I2C5_Slave_Event:
            return IPC45bits.I2C5SIS;
            break;
            
        case I2C5_Master_Event:
            return IPC46bits.I2C5MIS;
            break;
        
        case SPI6_Fault:
            return IPC46bits.SPI6EIS;
            break;
            
        case SPI6_Receive_Done:
            return IPC46bits.SPI6RXIS;
            break;
            
        case SPI6_Transfer_Done:
            return IPC46bits.SPI6TXIS;
            break;
            
        case UART6_Fault:
            return IPC47bits.U6EIS;
            break;
            
        case UART6_Receive_Done:
            return IPC47bits.U6RXIS;
            break;
            
        case UART6_Transfer_Done:
            return IPC47bits.U6TXIS;
            break;
        
        case ADC_End_Of_Scan_Ready:
            return IPC48bits.ADCEOSIS;
            break;
            
        case ADC_Analog_Circuits_Ready:
            return IPC48bits.ADCARDYIS;
            break;
            
        case ADC_Update_Ready:
            return IPC48bits.ADCURDYIS;
            break;
            
        case ADC_Group_Early_Interrupt_Request:
            return IPC49bits.ADCGRPIS;
            break;
            
        case ADC0_Early_Interrupt:
            return IPC49bits.ADC0EIS;
            break;
            
        case ADC1_Early_Interrupt:
            return IPC49bits.ADC1EIS;
            break;
            
        case ADC2_Early_Interrupt:
            return IPC50bits.ADC2EIS;
            break;
            
        case ADC3_Early_Interrupt:
            return IPC50bits.ADC3EIS;
            break;
            
        case ADC4_Early_Interrupt:
            return IPC50bits.ADC4EIS;
            break;
            
        case ADC7_Early_Interrupt:
            return IPC51bits.ADC7EIS;
            break;
            
        case ADC0_Warm_Interrupt:
            return IPC51bits.ADC0WIS;
            break;
            
        case ADC1_Warm_Interrupt:
            return IPC51bits.ADC1WIS;
            break;
            
        case ADC2_Warm_Interrupt:
            return IPC52bits.ADC2WIS;
            break;
            
        case ADC3_Warm_Interrupt:
            return IPC52bits.ADC3WIS;
            break;
            
        case ADC4_Warm_Interrupt:
            return IPC52bits.ADC4WIS;
            break;
            
        case ADC7_Warm_Interrupt:
            return IPC53bits.ADC7WIS;
            break;
            
        default:
            return 0;
            break;
            
    }
    
}


// This function enables a particular interrupt
// Returns 0 if no errors
// Returns 1 if errors
void enableInterrupt(interrupt_source_t input_interrupt) {
 
    setInterruptEnable(input_interrupt, 1);
    
}

// This function disables selected interrupt
void disableInterrupt(interrupt_source_t input_interrupt) {
 
    setInterruptEnable(input_interrupt, 0);
    
}

// This function clears selected interrupt flag
void clearInterruptFlag(interrupt_source_t input_interrupt) {
 
    setInterruptFlag(input_interrupt, 0);
    
}

// This function returns a string of the given interrupt name
char * getInterruptNameStringPadded(interrupt_source_t input_interrupt) {
    
    char *interrupt_descriptor_array[] = {
        
        "Core Timer                ",
        "Core Software 0           ",
        "Core Software 1           ",
        "External Int 0            ",
        "Timer1                    ",
        "Input Capture 1 Error     ",
        "Input Capture 1           ",
        "Output Compare 1          ",
        "External Int 1            ",
        "Timer2                    ",
        "Input Capture 2 Error     ",
        "Input Capture 2           ",
        "Output Compare 2          ",
        "External Intt 2           ",
        "Timer3                    ",
        "Input Capture 3 Error     ",
        "Input Capture 3           ",
        "Output Compare 3          ",
        "External Int 3            ",
        "Timer4                    ",
        "Input Capture 4 Error     ",
        "Input Capture 4           ",
        "Output Compare 4          ",
        "External Int 4            ",
        "Timer5                    ",
        "Input Capture 5 Error     ",
        "Input Capture 5           ",
        "Output Compare 5          ",
        "Timer6                    ",
        "Input Capture 6 Error     ",
        "Input Capture 6           ",
        "Output Compare 6          ",
        "Timer7                    ",
        "Input Capture 7 Error     ",
        "Input Capture 7           ",
        "Output Compare 7          ",
        "Timer8                    ",
        "Input Capture 8 Error     ",
        "Input Capture 8           ",
        "Output Compare 8          ",
        "Timer9                    ",
        "Input Capture 9 Error     ",
        "Input Capture 9           ",
        "Output Compare 9          ",
        "ADC Global Int            ",
        "ADC FIFO Data Ready       ",
        "ADC Digital Comparator 1  ",
        "ADC Digital Comparator 2  ",
        "ADC Digital Comparator 3  ",
        "ADC Digital Comparator 4  ",
        "ADC Digital Comparator 5  ",
        "ADC Digital Comparator 6  ",
        "ADC Digital Filter 1      ",
        "ADC Digital Filter 2      ",
        "ADC Digital Filter 3      ",
        "ADC Digital Filter 4      ",
        "ADC Digital Filter 5      ",
        "ADC Digital Filter 6      ",
        "ADC Fault                 ",
        "ADC Data 0                ",
        "ADC Data 1                ",
        "ADC Data 2                ",
        "ADC Data 3                ",
        "ADC Data 4                ",
        "ADC Data 5                ",
        "ADC Data 6                ",
        "ADC Data 7                ",
        "ADC Data 8                ",
        "ADC Data 9                ",
        "ADC Data 10               ",
        "ADC Data 11               ",
        "ADC Data 12               ",
        "ADC Data 13               ",
        "ADC Data 14               ",
        "ADC Data 15               ",
        "ADC Data 16               ",
        "ADC Data 17               ",
        "ADC Data 18               ",
        "ADC Data 19               ",
        "ADC Data 20               ",
        "ADC Data 21               ",
        "ADC Data 22               ",
        "ADC Data 23               ",
        "ADC Data 24               ",
        "ADC Data 25               ",
        "ADC Data 26               ",
        "ADC Data 27               ",
        "ADC Data 28               ",
        "ADC Data 29               ",
        "ADC Data 30               ",
        "ADC Data 31               ",
        "ADC Data 32               ",
        "ADC Data 33               ",
        "ADC Data 34               ",
        "ADC Data 35               ",
        "ADC Data 36               ",
        "ADC Data 37               ",
        "ADC Data 38               ",
        "ADC Data 39               ",
        "ADC Data 40               ",
        "ADC Data 41               ",
        "ADC Data 42               ",
        "ADC Data 43               ",
        "ADC Data 44               ",
        "Core Performance Counter  ",
        "Core Fast Debug Channel   ",
        "System Bus Protection     ",
        "Crypto Engine Event       ",
        "Not Present               ",
        "SPI1 Fault                ",
        "SPI1 Receive Done         ",
        "SPI1 Transfer Done        ",
        "UART1 Fault               ",
        "UART1 Receive Done        ",
        "UART1 Transfer Done       ",
        "I2C1 Bus Collision Event  ",
        "I2C1 Slave Event          ",
        "I2C1 Master Event         ",
        "PORTA Input Change        ",
        "PORTB Input Change        ",
        "PORTC Input Change        ",
        "PORTD Input Change        ",
        "PORTE Input Change        ",
        "PORTF Input Change        ",
        "PORTG Input Change        ",
        "PORTH Input Change        ",
        "PORTJ Input Change        ",
        "PORTK Input Change        ",
        "Parallel Master Port      ",
        "Parallel Master Port Error",
        "Comparator 1              ",
        "Comparator 2              ",
        "USB General Event         ",
        "USB DMA Event             ",
        "DMA Channel 0             ",
        "DMA Channel 1             ",
        "DMA Channel 2             ",
        "DMA Channel 3             ",
        "DMA Channel 4             ",
        "DMA Channel 5             ",
        "DMA Channel 6             ",
        "DMA Channel 7             ",
        "SPI2 Fault                ",
        "SPI2 Receive Done         ",
        "SPI2 Transfer Done        ",
        "UART2 Fault               ",
        "UART2 Receive Done        ",
        "UART2 Transfer Done       ",
        "I2C2 Bus Collision        ",
        "I2C2 Slave Event          ",
        "I2C2 Master Event         ",
        "Control Area Network 1    ",
        "Control Area Network 2    ",
        "Ethernet Interrupt        ",
        "SPI3 Fault                ",
        "SPI3 Receive Done         ",
        "SPI3 Transfer Done        ",
        "UART3 Fault               ",
        "UART3 Receive Done        ",
        "UART3 Transfer Done       ",
        "I2C3 Bus Collision        ",
        "I2C3 Slave Event          ",
        "I2C3 Master Event         ",
        "SPI4 Fault                ",
        "SPI4 Receive Done         ",
        "SPI4 Transfer Done        ",
        "Real Time Clock           ",
        "Flash Control Event       ",
        "Prefetch Module SEC       ",
        "SQI1 Event                ",
        "UART4 Fault               ",
        "UART4 Receive Done        ",
        "UART4 Transfer Done       ",
        "I2C4 Bus Collision        ",
        "I2C4 Slave Event          ",
        "I2C4 Master Event         ",
        "SPI5 Fault                ",
        "SPI5 Receive Done         ",
        "SPI5 Transfer Done        ",
        "UART5 Fault               ",
        "UART5 Receive Done        ",
        "UART5 Transfer Done       ",
        "I2C5 Bus Collision        ",
        "I2C5 Slave Event          ",
        "I2C5 Master Event         ",
        "SPI6 Fault                ",
        "SPI6 Receive Done         ",
        "SPI6 Transfer Done        ",
        "UART6 Fault               ",
        "UART6 Receive Done        ",
        "UART6 Transfer Done       ",
        "Not Present               ",
        "ADC End Of Scan Ready     ",
        "ADC Analog Circuits Ready ",
        "ADC Update Ready          ",
        "Not Present               ",
        "ADC Group Early IRQ       ",
        "Not Present               ",
        "ADC0 Early Int            ",
        "ADC1 Early Int            ",
        "ADC2 Early Int            ",
        "ADC3 Early Int            ",
        "ADC4 Early Int            ",
        "Not Present               ",
        "Not Present               ",
        "ADC7 Early Int            ",
        "ADC0 Warm Int             ",
        "ADC1 Warm Int             ",
        "ADC2 Warm Int             ",
        "ADC3 Warm Int             ",
        "ADC4 Warm Int             ",
        "Not Present               ",
        "Not Present               ",
        "ADC7 Warm Int             " 

    };
    
    return interrupt_descriptor_array[input_interrupt];
    
}

// This function prints information on all interrupt settings
void printInterruptStatus(void) {
    
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, UNDERSCORE);
    printf("Interrupt Controller Status:\n\r");

    terminalTextAttributesReset();
    
    if (getGlobalInterruptsState()) terminalTextAttributes(GREEN, BLACK, NORMAL);
            else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("Global Interrupt Enable: %s\n\r", getGlobalInterruptsState() ? "T" : "F");
    
    // Print interrupt vector mode
    if (INTCONbits.MVEC) terminalTextAttributes(GREEN, BLACK, NORMAL);
            else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("Interrupt Vector Mode: %s\n\r", INTCONbits.MVEC ? "Multi-Vector" : "Single-Vector");

    // Print interrupt priority shadow register settings
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("Interrupt Priority Shadow Register Setting: 0x%08X\n\r", PRISS);
    
    terminalTextAttributes(GREEN, BLACK, REVERSE);
    printf("\n\rInterrupts in list are marked green if they are enabled or have IPL > 0\n\r");
    
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("\n\rInterrupt sources:\n\r");
    terminalTextAttributes(GREEN, BLACK, REVERSE);
    printf("###  Name                     EN?  IPL ISL IRQ?\n\r");
    
    terminalTextAttributesReset();

    // Loop through all possible interrupts
    uint8_t i;
    for (i = 0; i <= 213; i++) {
     
        if (i % 2 == 0) {
         
            
            if (getInterruptEnable(i) || getInterruptPriority(i) > 0) terminalTextAttributes(GREEN, BLACK, NORMAL);
            else terminalTextAttributes(RED, BLACK, NORMAL);
            
        }
        
        else {
         
            if (getInterruptEnable(i) || getInterruptPriority(i) > 0) terminalTextAttributes(GREEN, BLACK, REVERSE);
            else terminalTextAttributes(RED, BLACK, REVERSE);
            
        }
        
        printf("%03d  %s %c    %d   %d    %c\n\r", 
                i,
                getInterruptNameStringPadded(i),
                getInterruptEnable(i) ? 'T' : 'F',
                getInterruptPriority(i),
                getInterruptSubriority(i),
                getInterruptFlag(i) ? 'T' : 'F');

    }

    terminalTextAttributesReset();    
    
}
