EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 13 26
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LED_Display_Local_Library:PIC32MZ2048EFH144_IPL U?
U 2 1 5BB24D03
P 5580 3530
F 0 "U?" H 6880 1430 50  0000 R CNN
F 1 "PIC32MZ2048EFH144_IPL" H 5580 5680 50  0000 C CNN
F 2 "Housings_QFP:TQFP-144_20x20mm_Pitch0.5mm" H 5580 3530 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/60001320D.pdf" H 5580 3530 50  0001 C CNN
F 4 "ALL" H 5580 3530 50  0001 C CNN "Config"
F 5 "PIC32MZ2048EFH144-I/PL-ND" H 5580 3530 50  0001 C CNN "Digi-Key PN"
	2    5580 3530
	1    0    0    -1  
$EndComp
Text GLabel 7130 4480 2    50   Input ~ 0
~MCLR
NoConn ~ 7130 5380
NoConn ~ 7130 5480
$Comp
L power:GND #PWR?
U 1 1 5BB53596
P 7320 5380
F 0 "#PWR?" H 7320 5130 50  0001 C CNN
F 1 "GND" H 7320 5230 50  0000 C CNN
F 2 "" H 7320 5380 50  0001 C CNN
F 3 "" H 7320 5380 50  0001 C CNN
	1    7320 5380
	1    0    0    -1  
$EndComp
Wire Wire Line
	7320 5380 7320 5280
Wire Wire Line
	7320 5280 7130 5280
Text GLabel 4030 2980 0    50   BiDi ~ 0
ICSPDAT
Text GLabel 4030 3080 0    50   Input ~ 0
ICSPCLK
Text GLabel 4030 2080 0    50   Output ~ 0
EBI_A5
Text GLabel 4030 4780 0    50   Output ~ 0
EBI_A6
Text GLabel 4030 3880 0    50   Output ~ 0
EBI_A7
Text GLabel 4030 3780 0    50   Output ~ 0
EBI_A10
Text GLabel 4030 4880 0    50   Output ~ 0
EBI_A12
Text GLabel 4030 1980 0    50   Output ~ 0
EBI_A14
Text GLabel 7130 2380 2    50   Output ~ 0
EBI_A15
Text GLabel 7130 3280 2    50   BiDi ~ 0
EBI_IO0
Text GLabel 7130 3380 2    50   BiDi ~ 0
EBI_IO1
Text GLabel 7130 3480 2    50   BiDi ~ 0
EBI_IO2
Text GLabel 7130 3580 2    50   BiDi ~ 0
EBI_IO3
Text GLabel 7130 3680 2    50   BiDi ~ 0
EBI_IO4
Text GLabel 7130 3780 2    50   BiDi ~ 0
EBI_IO5
Text GLabel 7130 3880 2    50   BiDi ~ 0
EBI_IO6
Text GLabel 7130 3980 2    50   BiDi ~ 0
EBI_IO7
Text GLabel 7130 2680 2    50   BiDi ~ 0
EBI_IO12
Text GLabel 7130 2780 2    50   BiDi ~ 0
EBI_IO13
Text GLabel 7130 1780 2    50   BiDi ~ 0
EBI_IO14
Text GLabel 7130 1880 2    50   BiDi ~ 0
EBI_IO15
Text GLabel 4030 4980 0    40   Output ~ 0
~EBI_WE
Text GLabel 4030 5080 0    40   Input ~ 0
~EBI_OE
Text GLabel 1130 3390 0    40   Input ~ 0
~FLASH_Hold
Text GLabel 1130 4150 0    50   Input ~ 0
FLASH_SCK
Text GLabel 1260 2420 0    40   Input ~ 0
~FLASH_CE1
Text GLabel 1130 3750 0    50   Input ~ 0
FLASH_MOSI
Text GLabel 660  4860 2    50   Output ~ 0
FLASH_MISO
Text GLabel 1260 2520 0    40   Input ~ 0
~FLASH_CE2
Text GLabel 1260 2620 0    40   Input ~ 0
~FLASH_CE3
Text GLabel 1260 2720 0    40   Input ~ 0
~FLASH_CE4
Text GLabel 1260 2820 0    40   Input ~ 0
~FLASH_CE5
Text GLabel 1260 2920 0    40   Input ~ 0
~FLASH_CE6
Text GLabel 1260 3020 0    40   Input ~ 0
~FLASH_CE7
Text GLabel 1260 3120 0    40   Input ~ 0
~FLASH_CE8
$EndSCHEMATC
