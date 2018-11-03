EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 10 25
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
Text GLabel 1180 1160 0    40   Output ~ 0
~FLASH_WP1
Text GLabel 1180 1260 0    40   Output ~ 0
~FLASH_WP2
Text GLabel 1180 1360 0    40   Output ~ 0
~FLASH_WP3
Text GLabel 1180 1460 0    40   Output ~ 0
~FLASH_WP4
Text GLabel 1180 1560 0    40   Output ~ 0
~FLASH_WP5
Text GLabel 1180 1660 0    40   Output ~ 0
~FLASH_WP6
Text GLabel 1180 1760 0    40   Output ~ 0
~FLASH_WP7
Text GLabel 1180 1860 0    40   Output ~ 0
~FLASH_WP8
NoConn ~ 7130 5180
Text GLabel 9720 1520 0    50   Input ~ 0
R1_POS3P3
Text GLabel 9720 1620 0    50   Input ~ 0
R2_POS3P3
Text GLabel 9720 1720 0    50   Input ~ 0
B1_POS3P3
Text GLabel 9720 1820 0    50   Input ~ 0
B2_POS3P3
Text GLabel 9720 1920 0    50   Input ~ 0
G1_POS3P3
Text GLabel 9720 2020 0    50   Input ~ 0
G2_POS3P3
Text GLabel 9500 1280 0    50   Input ~ 0
~LVL_SHFT_EN
Text GLabel 9650 2760 0    50   Input ~ 0
R3_POS3P3
Text GLabel 9650 2860 0    50   Input ~ 0
R4_POS3P3
Text GLabel 9650 2960 0    50   Input ~ 0
B3_POS3P3
Text GLabel 9650 3060 0    50   Input ~ 0
B4_POS3P3
Text GLabel 9650 3160 0    50   Input ~ 0
G3_POS3P3
Text GLabel 9650 3260 0    50   Input ~ 0
G4_POS3P3
Text GLabel 9140 2170 0    50   Input ~ 0
R5_POS3P3
Text GLabel 9140 2270 0    50   Input ~ 0
R6_POS3P3
Text GLabel 9140 2370 0    50   Input ~ 0
B5_POS3P3
Text GLabel 9140 2470 0    50   Input ~ 0
B6_POS3P3
Text GLabel 9140 2570 0    50   Input ~ 0
G7_POS3P3
Text GLabel 9140 2670 0    50   Input ~ 0
G8_POS3P3
Text GLabel 9320 3560 0    50   Input ~ 0
R7_POS3P3
Text GLabel 9320 3660 0    50   Input ~ 0
R8_POS3P3
Text GLabel 9320 3760 0    50   Input ~ 0
B7_POS3P3
Text GLabel 9320 3860 0    50   Input ~ 0
B8_POS3P3
Text GLabel 9320 3960 0    50   Input ~ 0
G7_POS3P3
Text GLabel 9320 4060 0    50   Input ~ 0
G8_POS3P3
Text GLabel 10040 4070 0    50   Input ~ 0
A_POS3P3
Text GLabel 10040 4170 0    50   Input ~ 0
B_POS3P3
Text GLabel 10040 4270 0    50   Input ~ 0
C_POS3P3
Text GLabel 10040 4370 0    50   Input ~ 0
D_POS3P3
Text GLabel 10040 4470 0    50   Input ~ 0
E_POS3P3
Text GLabel 10040 4570 0    50   Input ~ 0
CLK_POS3P3
Text GLabel 10040 4670 0    50   Input ~ 0
LAT_POS3P3
Text GLabel 10040 4770 0    50   Input ~ 0
~OE_POS3P3
$EndSCHEMATC
