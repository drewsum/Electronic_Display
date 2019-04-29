GitHub Repo: https://github.com/drewsum/Electronic_Display.git

The power board will overheat if the fan is not running.
The power board should shut itself off if the half bridge ICs get too hot, and turn back on when the ICs cool down
The power board has two heatsinks installed (one on front of the board, one on back) to keep input protection MOSFETs Q201 and Q202 cool
The power board has output overcurrent protection, output overvoltage protection, overtemperature protection, input undervoltage protection, input overvoltage protection, and input reverse polarity protection.
The power board can be replaced entirely by an off the shelf 5 Volt 250 Watt power supply. The logic board should operate just the same without the power board present in the system.
There should be four twisted pairs of wires connecting the logic board to the power board
	Orange/Grey: +5VP, output voltage of power board. Measured by the MCU ADC for debugging
	Blue/Black: THWN (Thermal Warn). If this signal goes low, the MCU registers that the power board has overheated and logs this as an error
	Green/Black: PGOOD (Power Good). This signal should be high if the output voltage of the power board is within +/- 10% of 5 volts. This enables the +5VP PGOOD LED on the logic board.
	Yellow/Black: RUN signal. This is a digital signal that allows the MCU to enable and disable the power board
If the power board is operating correctly, there should be three green LEDs illuminated on the PCB: +12V PGOOD, +5V RUN, and +5V PGOOD
The power board was designed in KiCad 5.1 and requires the schematic symbol and footprint libraries located in hdw/lib