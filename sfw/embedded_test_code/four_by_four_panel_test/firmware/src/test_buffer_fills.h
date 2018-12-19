/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _TEST_BUFFER_FILLS_H    /* Guard against multiple inclusion */
#define _TEST_BUFFER_FILLS_H

extern uint8_t ram_buffer[98324];

// fill ram buffer with all white pixels
void fillRamBufferWhite(void);

// fill ram buffer with random data
void fillRamBufferRand(void);

// fill ram buffer with all green
void fillRamBufferRed(void);

// fill ram buffer with all green
void fillRamBufferGreen(void);

// fill ram buffer with all blue
void fillRamBufferBlue(void);

// fill ram buffer with all yellow
void fillRamBufferYellow(void);

// fill ram buffer with all cyan
void fillRamBufferCyan(void);

// fill ram buffer with all magenta
void fillRamBufferMagenta(void);

// fill ram buffer with all magenta
void fillRamBufferEveryOtherRed(void);

// fill ram buffer with every other red
void fillRamBufferEveryOtherBlue(void);

// fill ram buffer with every other green
void fillRamBufferEveryOtherGreen(void);

// fill ram buffer with christmas stripes
void fillRamBufferChristmas(void);

// fill ram buffer with RGB stripes
void fillRamBufferRGBStripes(void);

// fill ram buffer with red rows
void fillRamBufferRedRow(void);



#endif /* _TEST_BUFFER_FILLS_H */

/* *****************************************************************************
 End of File
 */
