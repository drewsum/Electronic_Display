
#include "32mz_interrupt_control.h"

// This function allows for the setting/clearing of a given interrupt
// It manipulates that interrupt's 'Interrupt Enable' bit
uint8_t SetInterruptEnable(interrupt_source_t input_interrupt, uint8_t input_state) {
 
    // Mask off anything larger than 1 to 1
    input_state = input_state >= 1;
    
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
            
            
        
            
            
            
            
            
        default:
            return 1;
            break;
            
    }
    
    return 0;
    
}