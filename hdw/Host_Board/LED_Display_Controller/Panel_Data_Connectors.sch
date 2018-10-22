EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 8 26
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
L Connector_Generic:Conn_02x08_Odd_Even J?
U 1 1 5BB405EB
P 2550 1800
F 0 "J?" H 2600 2317 50  0000 C CNN
F 1 "STRING_1" H 2600 2226 50  0000 C CNN
F 2 "" H 2550 1800 50  0001 C CNN
F 3 "~" H 2550 1800 50  0001 C CNN
	1    2550 1800
	1    0    0    -1  
$EndComp
Text GLabel 2350 1900 0    50   Input ~ 0
A_POS5
Text GLabel 2850 1900 2    50   Input ~ 0
B_POS5
Text GLabel 2850 2000 2    50   Input ~ 0
D_POS5
Text GLabel 2850 1800 2    50   Input ~ 0
E_POS5
Text GLabel 2350 2000 0    50   Input ~ 0
C_POS5
Text GLabel 2350 2100 0    50   Input ~ 0
CLK_POS5
Text GLabel 2350 2200 0    40   Input ~ 0
~OE_POS5
Text GLabel 2850 2100 2    50   Input ~ 0
LAT_POS5
Text GLabel 2350 1500 0    50   Input ~ 0
R1_POS5
Text GLabel 2350 1600 0    50   Input ~ 0
B1_POS5
Text GLabel 2350 1700 0    50   Input ~ 0
R2_POS5
Text GLabel 2350 1800 0    50   Input ~ 0
B2_POS5
Text GLabel 2850 1500 2    50   Input ~ 0
G1_POS5
Text GLabel 2850 1700 2    50   Input ~ 0
G2_POS5
$Comp
L power:GND #PWR?
U 1 1 5BB40845
P 3400 2350
F 0 "#PWR?" H 3400 2100 50  0001 C CNN
F 1 "GND" H 3405 2177 50  0000 C CNN
F 2 "" H 3400 2350 50  0001 C CNN
F 3 "" H 3400 2350 50  0001 C CNN
	1    3400 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 2350 3400 2200
Wire Wire Line
	3400 2200 2850 2200
Wire Wire Line
	2850 1600 3400 1600
Wire Wire Line
	3400 1600 3400 2200
Connection ~ 3400 2200
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J?
U 1 1 5BB40C27
P 2550 3300
F 0 "J?" H 2600 3817 50  0000 C CNN
F 1 "STRING_2" H 2600 3726 50  0000 C CNN
F 2 "" H 2550 3300 50  0001 C CNN
F 3 "~" H 2550 3300 50  0001 C CNN
	1    2550 3300
	1    0    0    -1  
$EndComp
Text GLabel 2350 3400 0    50   Input ~ 0
A_POS5
Text GLabel 2850 3400 2    50   Input ~ 0
B_POS5
Text GLabel 2850 3500 2    50   Input ~ 0
D_POS5
Text GLabel 2850 3300 2    50   Input ~ 0
E_POS5
Text GLabel 2350 3500 0    50   Input ~ 0
C_POS5
Text GLabel 2350 3600 0    50   Input ~ 0
CLK_POS5
Text GLabel 2350 3700 0    40   Input ~ 0
~OE_POS5
Text GLabel 2850 3600 2    50   Input ~ 0
LAT_POS5
Text GLabel 2350 3000 0    50   Input ~ 0
R3_POS5
Text GLabel 2350 3100 0    50   Input ~ 0
B3_POS5
Text GLabel 2350 3200 0    50   Input ~ 0
R4_POS5
Text GLabel 2350 3300 0    50   Input ~ 0
B4_POS5
Text GLabel 2850 3000 2    50   Input ~ 0
G3_POS5
Text GLabel 2850 3200 2    50   Input ~ 0
G4_POS5
$Comp
L power:GND #PWR?
U 1 1 5BB40C3C
P 3400 3850
F 0 "#PWR?" H 3400 3600 50  0001 C CNN
F 1 "GND" H 3405 3677 50  0000 C CNN
F 2 "" H 3400 3850 50  0001 C CNN
F 3 "" H 3400 3850 50  0001 C CNN
	1    3400 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 3850 3400 3700
Wire Wire Line
	3400 3700 2850 3700
Wire Wire Line
	2850 3100 3400 3100
Wire Wire Line
	3400 3100 3400 3700
Connection ~ 3400 3700
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J?
U 1 1 5BB40D11
P 2550 4800
F 0 "J?" H 2600 5317 50  0000 C CNN
F 1 "STRING_3" H 2600 5226 50  0000 C CNN
F 2 "" H 2550 4800 50  0001 C CNN
F 3 "~" H 2550 4800 50  0001 C CNN
	1    2550 4800
	1    0    0    -1  
$EndComp
Text GLabel 2350 4900 0    50   Input ~ 0
A_POS5
Text GLabel 2850 4900 2    50   Input ~ 0
B_POS5
Text GLabel 2850 5000 2    50   Input ~ 0
D_POS5
Text GLabel 2850 4800 2    50   Input ~ 0
E_POS5
Text GLabel 2350 5000 0    50   Input ~ 0
C_POS5
Text GLabel 2350 5100 0    50   Input ~ 0
CLK_POS5
Text GLabel 2350 5200 0    40   Input ~ 0
~OE_POS5
Text GLabel 2850 5100 2    50   Input ~ 0
LAT_POS5
Text GLabel 2350 4500 0    50   Input ~ 0
R5_POS5
Text GLabel 2350 4600 0    50   Input ~ 0
B5_POS5
Text GLabel 2350 4700 0    50   Input ~ 0
R6_POS5
Text GLabel 2350 4800 0    50   Input ~ 0
B6_POS5
Text GLabel 2850 4500 2    50   Input ~ 0
G5_POS5
Text GLabel 2850 4700 2    50   Input ~ 0
G6_POS5
$Comp
L power:GND #PWR?
U 1 1 5BB40D26
P 3400 5350
F 0 "#PWR?" H 3400 5100 50  0001 C CNN
F 1 "GND" H 3405 5177 50  0000 C CNN
F 2 "" H 3400 5350 50  0001 C CNN
F 3 "" H 3400 5350 50  0001 C CNN
	1    3400 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 5350 3400 5200
Wire Wire Line
	3400 5200 2850 5200
Wire Wire Line
	2850 4600 3400 4600
Wire Wire Line
	3400 4600 3400 5200
Connection ~ 3400 5200
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J?
U 1 1 5BB40D31
P 2550 6300
F 0 "J?" H 2600 6817 50  0000 C CNN
F 1 "STRING_4" H 2600 6726 50  0000 C CNN
F 2 "" H 2550 6300 50  0001 C CNN
F 3 "~" H 2550 6300 50  0001 C CNN
	1    2550 6300
	1    0    0    -1  
$EndComp
Text GLabel 2350 6400 0    50   Input ~ 0
A_POS5
Text GLabel 2850 6400 2    50   Input ~ 0
B_POS5
Text GLabel 2850 6500 2    50   Input ~ 0
D_POS5
Text GLabel 2850 6300 2    50   Input ~ 0
E_POS5
Text GLabel 2350 6500 0    50   Input ~ 0
C_POS5
Text GLabel 2350 6600 0    50   Input ~ 0
CLK_POS5
Text GLabel 2350 6700 0    40   Input ~ 0
~OE_POS5
Text GLabel 2850 6600 2    50   Input ~ 0
LAT_POS5
Text GLabel 2350 6000 0    50   Input ~ 0
R7_POS5
Text GLabel 2350 6100 0    50   Input ~ 0
B7_POS5
Text GLabel 2350 6200 0    50   Input ~ 0
R8_POS5
Text GLabel 2350 6300 0    50   Input ~ 0
B8_POS5
Text GLabel 2850 6000 2    50   Input ~ 0
G7_POS5
Text GLabel 2850 6200 2    50   Input ~ 0
G8_POS5
$Comp
L power:GND #PWR?
U 1 1 5BB40D46
P 3400 6850
F 0 "#PWR?" H 3400 6600 50  0001 C CNN
F 1 "GND" H 3405 6677 50  0000 C CNN
F 2 "" H 3400 6850 50  0001 C CNN
F 3 "" H 3400 6850 50  0001 C CNN
	1    3400 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 6850 3400 6700
Wire Wire Line
	3400 6700 2850 6700
Wire Wire Line
	2850 6100 3400 6100
Wire Wire Line
	3400 6100 3400 6700
Connection ~ 3400 6700
$EndSCHEMATC
