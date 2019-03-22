EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 8 32
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
U 3 1 5BB24EE7
P 5580 3530
F 0 "U601" H 6880 1430 50  0000 R CNN
F 1 "PIC32MZ2048EFH144_IPL" H 5580 5680 50  0000 C CNN
F 2 "Housings_QFP:TQFP-144_20x20mm_Pitch0.5mm" H 5580 3530 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/60001320D.pdf" H 5580 3530 50  0001 C CNN
F 4 "" H 5580 3530 50  0001 C CNN "Config"
F 5 "PIC32MZ2048EFH144-I/PL-ND" H 5580 3530 50  0001 C CNN "Digi-Key PN"
	3    5580 3530
	1    0    0    -1  
$EndComp
Text GLabel 7130 3080 2    50   Output ~ 0
EBI_A0
Text GLabel 7130 3480 2    50   Output ~ 0
EBI_A1
Text GLabel 4030 3180 0    50   Output ~ 0
EBI_A2
Text GLabel 7130 3580 2    50   Output ~ 0
EBI_A3
Text GLabel 4030 4580 0    50   Output ~ 0
EBI_A4
Text GLabel 4030 2080 0    50   Output ~ 0
EBI_A8
Text GLabel 4030 1980 0    50   Output ~ 0
EBI_A9
Text GLabel 7130 2980 2    50   Output ~ 0
EBI_A11
Text GLabel 7130 2880 2    50   Output ~ 0
EBI_A13
Text GLabel 7130 3380 2    50   Output ~ 0
EBI_A16
Text GLabel 7130 1980 2    40   Input ~ 0
~EBI_CE
Text GLabel 7130 3680 2    50   Output ~ 0
EBI_A17
Text GLabel 7130 2080 2    50   Output ~ 0
G0_POS3P3
Text GLabel 7130 2180 2    50   Output ~ 0
G1_POS3P3
Text GLabel 7130 2480 2    50   Output ~ 0
G4_POS3P3
Text GLabel 7130 2580 2    50   Output ~ 0
G5_POS3P3
Text GLabel 7130 2280 2    50   Output ~ 0
G2_POS3P3
Text GLabel 7130 2380 2    50   Output ~ 0
G3_POS3P3
Text GLabel 7130 2680 2    50   Output ~ 0
G6_POS3P3
Text GLabel 7130 2780 2    50   Output ~ 0
G7_POS3P3
Text GLabel 4030 4680 0    50   Output ~ 0
B0_POS3P3
Text GLabel 4030 4780 0    50   Output ~ 0
B1_POS3P3
Text GLabel 4030 4880 0    50   Output ~ 0
B2_POS3P3
Text GLabel 4030 4980 0    50   Output ~ 0
B3_POS3P3
Text GLabel 4030 5080 0    50   Output ~ 0
B4_POS3P3
Text GLabel 4030 5180 0    50   Output ~ 0
B5_POS3P3
Text GLabel 4030 5280 0    50   Output ~ 0
B6_POS3P3
Text GLabel 4030 5380 0    50   Output ~ 0
B7_POS3P3
Text GLabel 4030 1580 0    50   Input ~ 0
USB_UART_RX
Text GLabel 4030 2980 0    50   Output ~ 0
WIFI_UART_TX
Text GLabel 4030 3080 0    50   Input ~ 0
WIFI_UART_RX
Text GLabel 7130 1580 2    50   Output ~ 0
Panel_CLK_POS3P3
Text GLabel 7130 1680 2    50   Output ~ 0
Panel_LAT_POS3P3
Text GLabel 7130 1780 2    50   Output ~ 0
~Panel_OE_POS3P3
Text GLabel 4030 2680 0    50   Output ~ 0
Panel_Dim_PWM
Text GLabel 7130 4080 2    50   Input ~ 0
POS3P3_PGOOD
Text GLabel 4030 3580 0    40   Output ~ 0
~ACTIVE_LED
Text GLabel 4030 2880 0    50   Output ~ 0
SPI_Error_LED
Text GLabel 4030 3380 0    50   Output ~ 0
WIFI_Error_LED
Text GLabel 4030 2780 0    50   Output ~ 0
EBI_Error_LED
Text GLabel 4030 3480 0    50   Output ~ 0
USB_Error_LED
Text GLabel 4030 3280 0    50   Output ~ 0
Heartbeat_LED
Text GLabel 4030 2180 0    50   Input ~ 0
POS5P_PGOOD
Text GLabel 4030 2280 0    40   Input ~ 0
~POS5P_THWN
Text GLabel 7130 3980 2    50   Input ~ 0
ENCODER_DIR
Text GLabel 7130 3880 2    50   Input ~ 0
ENCODER_STEP
Text GLabel 7130 3780 2    40   Input ~ 0
~Display_Enable
Text GLabel 4030 1880 0    50   Input ~ 0
POS5_PGOOD
Text GLabel 4030 1780 0    50   Output ~ 0
POS5_RUN
Text GLabel 4030 3880 0    50   Input ~ 0
POS3P3_ADC
Text GLabel 4030 3980 0    50   Input ~ 0
POS12_ADC
Text GLabel 4030 4380 0    50   Input ~ 0
POS5_ADC
Text GLabel 4030 4480 0    50   Input ~ 0
POS5P_ADC
Text GLabel 4030 2380 0    50   Output ~ 0
POS5P_RUN
Text GLabel 4030 4280 0    50   Input ~ 0
POS5P5_ADC
$Comp
L Graphic:SYM_ESD_Large #SYM?
U 1 1 5C01D864
P 7890 4990
AR Path="/5BAAE0FA/5C01D864" Ref="#SYM?"  Part="1" 
AR Path="/5BB182B1/5C01D864" Ref="#SYM?"  Part="1" 
AR Path="/5BB1838A/5C01D864" Ref="#SYM801"  Part="1" 
F 0 "#SYM801" H 7890 5190 50  0001 C CNN
F 1 "SYM_ESD_Large" H 7890 4740 50  0001 C CNN
F 2 "" H 7885 4960 50  0001 C CNN
F 3 "~" H 7885 4960 50  0001 C CNN
	1    7890 4990
	1    0    0    -1  
$EndComp
NoConn ~ 4030 4080
NoConn ~ 7130 1880
Text Notes 550  700  0    100  ~ 20
08. Microcontroller IO Bank 2
$Comp
L LED_Display_Local_Library:MU_Logo #G801
U 1 1 5BFF2FC2
P 9900 1100
F 0 "#G801" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
Text GLabel 4030 4180 0    50   Output ~ 0
Other_Error_LED
Text GLabel 4030 1680 0    50   Input ~ 0
POS12_PGOOD
$EndSCHEMATC
