Github Repo: https://github.com/drewsum/Electronic_Display

There is a rotary encoder located on the side of the logic board. Turning it allows the user to adjust screen brightness. Pressing it inward turns the screen on and off.
The logic board cannot be powered by both the auxiliary input voltage jack (+12VIN AUX) and the input voltage shanks at the same time
The MCU on the logic board was programmed using a PIC KIT 3 programmer from Microchip. PIC KIT 4 may work as well, but has not been tested.
The MCU on the logic board is programmed with firmware located in the project repository at /sfw/embedded_firmware/U601_firmware/
We’ve had issues with SPI Flash Chips 5 and 6 (U2201 and U2301). I believe this is a timing/PCB trace routing issue. At the time of writing, this problem has seemed to be resolved with slow SPI timing.
The MCU can be reset with the reset pushbutton (Manual Reset)
The logic board will shine a red reset LED when the MCU is in reset or is being programmed
The MCU firmware was complied with Microchip’s XC32 compiler, version 2.10, using the MPLAB X IDE, version 5.15
The MCU firmware was compiled at optimization level two. The command line argument -O2 must be added to the XC32 command line driver arguments section of the project settings. Failure to do so will result in screen flickering. Optimization level two may or may not require a Microchip XC32 Pro compiler license. We purchased the Pro license for $30 for a one month subscription when building the project.
The logic board has an extensive USB debugging interface
Connect a Micro USB cable to the USB jack on the top of the logic board
The serial port settings are printed in silkscreen on the logic board near the USB jack
	115.2 kbps
	8 data bits
	1 stop bit
	No parity
	No flow control
Use serial port software such as Tera Term or PuTTY to communicate with the logic board.
When opening a connection, press the enter key twice. This enables USB communication. Skipping this will result in no serial output.
After pressing enter twice, type “Help” and press enter. This will show all available serial commands.
To control what’s on the screen, type “Disable State Machine”. The user can now explicitly control what’s displayed on the screen. “Enable Muxing” and “Disable Muxing” enable and disable the screen. “Enable State Machine” resumes the normal system behavior
The logic board has error state reporting that can be shown through the red error LEDs on the board and through the USB debugging interface
If a CPU exception occurs, all red LEDs on the logic board will illuminate. This should never happen.
The MCU watchdog timer and deadman timer should reset the MCU if a firmware fault occurs
The logic board has green PGOOD LEDs that illuminate when the on board power supplies are within +/-10% of their programmed output voltages. This can show if the power supplies are operating correctly.
Images that the screen displays can only be programmed through the Android App, but there are two hardcoded images stored in MCU flash. These can be displayed on the screen through the USB debugging interface.
The screen can be set to solid colors through the USB debugging interface
The logic board has input undervoltage protection, input overvoltage protection, and input reverse voltage polarity protection.
When programming images from the android app, WiFi UART traffic can be monitored using the USB debugging interface

