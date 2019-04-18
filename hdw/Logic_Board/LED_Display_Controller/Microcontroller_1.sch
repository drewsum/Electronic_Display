EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 7 32
Title "Electronic Display Logic Board"
Date "2018-12-15"
Rev "A"
Comp "Marquette University Senior Design 2018/2019 Group E44"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LED_Display_Local_Library:PIC32MZ2048EFH144_IPL U601
U 2 1 5BB24D03
P 5580 3530
F 0 "U601" H 6880 1430 50  0000 R CNN
F 1 "PIC32MZ2048EFH144_IPL" H 5580 5680 50  0000 C CNN
F 2 "Housings_QFP:TQFP-144_20x20mm_Pitch0.5mm" H 5580 3530 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/60001320D.pdf" H 5580 3530 50  0001 C CNN
F 4 "" H 5580 3530 50  0001 C CNN "Config"
F 5 "PIC32MZ2048EFH144-I/PL-ND" H 5580 3530 50  0001 C CNN "Digi-Key PN"
	2    5580 3530
	1    0    0    -1  
$EndComp
Text GLabel 7130 4480 2    50   Input ~ 0
~MCLR
$Comp
L power:GND #PWR0701
U 1 1 5BB53596
P 7320 5380
F 0 "#PWR0701" H 7320 5130 50  0001 C CNN
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
Text GLabel 4030 5080 0    40   Output ~ 0
~EBI_OE
Text GLabel 4030 4180 0    40   Output ~ 0
~FLASH_Hold
Text GLabel 4030 4380 0    50   Output ~ 0
FLASH_SCK
Text GLabel 4030 3180 0    40   Output ~ 0
~FLASH_CE1
Text GLabel 4030 5280 0    50   Output ~ 0
FLASH_MOSI
Text GLabel 4030 5380 0    50   Input ~ 0
FLASH_MISO
Text GLabel 4030 3280 0    40   Output ~ 0
~FLASH_CE2
Text GLabel 4030 3380 0    40   Output ~ 0
~FLASH_CE3
Text GLabel 4030 3480 0    40   Output ~ 0
~FLASH_CE4
Text GLabel 4030 3580 0    40   Output ~ 0
~FLASH_CE5
Text GLabel 4030 3680 0    40   Output ~ 0
~FLASH_CE6
Text GLabel 4030 3980 0    40   Output ~ 0
~FLASH_CE7
Text GLabel 4030 4080 0    40   Output ~ 0
~FLASH_CE8
Text GLabel 4030 2180 0    40   Output ~ 0
~FLASH_WP1
Text GLabel 4030 2280 0    40   Output ~ 0
~FLASH_WP2
Text GLabel 4030 2380 0    40   Output ~ 0
~FLASH_WP3
Text GLabel 4030 2480 0    40   Output ~ 0
~FLASH_WP4
Text GLabel 4030 2580 0    40   Output ~ 0
~FLASH_WP5
Text GLabel 4030 2680 0    40   Output ~ 0
~FLASH_WP6
Text GLabel 4030 1780 0    40   Output ~ 0
~FLASH_WP7
Text GLabel 4030 1880 0    40   Output ~ 0
~FLASH_WP8
Text GLabel 7130 1580 2    50   Output ~ 0
R0_POS3P3
Text GLabel 7130 1680 2    50   Output ~ 0
R1_POS3P3
Text GLabel 7130 1780 2    50   Output ~ 0
R2_POS3P3
Text GLabel 7130 1880 2    50   Output ~ 0
R3_POS3P3
Text GLabel 7130 1980 2    50   Output ~ 0
R4_POS3P3
Text GLabel 7130 2080 2    50   Output ~ 0
R5_POS3P3
Text GLabel 7130 2180 2    50   Output ~ 0
R6_POS3P3
Text GLabel 7130 2280 2    50   Output ~ 0
R7_POS3P3
Text GLabel 7130 2580 2    50   Output ~ 0
Row_A_POS3P3
Text GLabel 7130 2680 2    50   Output ~ 0
Row_B_POS3P3
Text GLabel 7130 2780 2    50   Output ~ 0
Row_C_POS3P3
Text GLabel 7130 2880 2    50   Output ~ 0
Row_D_POS3P3
Text GLabel 7130 2980 2    50   Output ~ 0
Row_E_POS3P3
Text GLabel 7130 4080 2    50   Output ~ 0
WIFI_CHPD
Text GLabel 7130 4180 2    40   Output ~ 0
~WIFI_RESET
Text GLabel 7130 2480 2    50   Output ~ 0
USB_UART_TX
Text GLabel 4030 1580 0    40   Output ~ 0
~LVL_SHFT_EN
$Comp
L Graphic:SYM_ESD_Large #SYM?
U 1 1 5C01D836
P 7890 4990
AR Path="/5BAAE0FA/5C01D836" Ref="#SYM?"  Part="1" 
AR Path="/5BB182B1/5C01D836" Ref="#SYM701"  Part="1" 
F 0 "#SYM701" H 7890 5190 50  0001 C CNN
F 1 "SYM_ESD_Large" H 7890 4740 50  0001 C CNN
F 2 "" H 7885 4960 50  0001 C CNN
F 3 "~" H 7885 4960 50  0001 C CNN
	1    7890 4990
	1    0    0    -1  
$EndComp
NoConn ~ 7130 5180
NoConn ~ 7130 5480
NoConn ~ 7130 5380
NoConn ~ 4030 1680
NoConn ~ 4030 4280
NoConn ~ 4030 4480
NoConn ~ 4030 5180
NoConn ~ 4030 5480
Text Notes 550  700  0    100  ~ 20
07. Microcontroller IO Bank 1
$Comp
L LED_Display_Local_Library:MU_Logo #G701
U 1 1 5BFF2F9C
P 9900 1100
F 0 "#G701" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
$EndSCHEMATC
