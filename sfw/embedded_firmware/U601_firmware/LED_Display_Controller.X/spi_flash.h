/* ************************************************************************** */
/** Serial Peripheral Interface FLASH Memory

  @Company
 Marquette Senior Design E44 2018-2019
 
  @File Name
    spi_flash.h

  @Summary
 Gives APIs for controlling 8 external 2 Mb SPI Flash chips for storing data 

 */
/* ************************************************************************** */

#ifndef _SPI_FLASH_H    /* Guard against multiple inclusion */
#define _SPI_FLASH_H

#include <sys/attribs.h>


// enumerate SPI flash state type
enum spi_flash_state_t {

    idle,
    flash1_write,
    flash1_read,
    flash2_write,
    flash2_read,
    flash3_write,
    flash3_read,
    flash4_write,
    flash4_read,
    flash5_write,
    flash5_read,
    flash6_write,
    flash6_read,
    flash7_write,
    flash7_read,
    flash8_write,
    flash8_read    
    
} spi_flash_state;

// indexes ebi sram array as we read the flash chip
uint32_t sram_addr_index;

volatile uint8_t SPI_Read_Finished_Flag;

// Function to initialize SPI
void spiFlashInit(void);

// Function to set GPIO pins for ~CE and ~WP
void spiFlashGPIOSet(void);

// Function to reset GPIO pins for ~CE and ~WP
void spiFlashGPIOReset(void);

// Function to print status
void printSPIFlashStatus(void);

// SPI3 Fault interrupt service routine
void __ISR(_SPI3_FAULT_VECTOR, ipl1SRS) spi3FaultISR(void);

// SPI3 Receive Done interrupt service routine
void __ISR(_SPI3_RX_VECTOR, ipl5SRS) spi3ReceiveISR(void);

//SPI3 Transfer Done interrupt service routine
void __ISR(_SPI3_TX_VECTOR, ipl5SRS) spi3TransferISR(void);

// Function to write single byte to transmit FIFO
void SPI3_writeByte(uint8_t write_byte);

// Function to read single byte from receive FIFO
uint8_t SPI3_readByte(void);

// This function erases q spi flash chip
void SPI_FLASH_chipErase(uint8_t chip_select);

// This function reads from a spi flash chip
void SPI_FLASH_beginRead(uint8_t chip_select);

// This function writes to a spi flash chip
void SPI_FLASH_beginWrite(uint8_t chip_select);

// This function enables write enable
void SPI_Flash_writeEnable(uint8_t chip_select);

// This function programs the status register in the chip passed as a parameter
// It sets all bits in the status register to 0, which disables block protection
// The write enable functions must be called beforehand
void SPI_Flash_blockProtectionDisable(uint8_t chip_select);

#endif /* _SPI_FLASH_H */

/* *****************************************************************************
 End of File
 */
