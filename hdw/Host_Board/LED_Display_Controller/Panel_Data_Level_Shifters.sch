EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 10 14
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
L 74xx:74HCT541 U?
U 1 1 5BAD3B80
P 5510 3500
F 0 "U?" H 5210 4150 50  0000 C CNN
F 1 "74HCT541" H 5210 2850 50  0000 C CNN
F 2 "" H 5510 3500 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HCT541" H 5510 3500 50  0001 C CNN
	1    5510 3500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J?
U 1 1 5BB413E8
P 1800 4550
F 0 "J?" H 1850 5067 50  0000 C CNN
F 1 "STRING_1" H 1850 4976 50  0000 C CNN
F 2 "" H 1800 4550 50  0001 C CNN
F 3 "~" H 1800 4550 50  0001 C CNN
	1    1800 4550
	1    0    0    -1  
$EndComp
Text GLabel 1600 4650 0    50   Input ~ 0
A_POS5
Text GLabel 2100 4650 2    50   Input ~ 0
B_POS5
Text GLabel 2100 4750 2    50   Input ~ 0
D_POS5
Text GLabel 2100 4550 2    50   Input ~ 0
E_POS5
Text GLabel 1600 4750 0    50   Input ~ 0
C_POS5
Text GLabel 1600 4850 0    50   Input ~ 0
CLK_POS5
Text GLabel 1600 4950 0    40   Input ~ 0
~OE_POS5
Text GLabel 2100 4850 2    50   Input ~ 0
LAT_POS5
Text GLabel 1600 4250 0    50   Input ~ 0
R1_POS5
Text GLabel 1600 4350 0    50   Input ~ 0
B1_POS5
Text GLabel 1600 4450 0    50   Input ~ 0
R2_POS5
Text GLabel 1600 4550 0    50   Input ~ 0
B2_POS5
Text GLabel 2100 4250 2    50   Input ~ 0
G1_POS5
Text GLabel 2100 4450 2    50   Input ~ 0
G2_POS5
$Comp
L power:GND #PWR?
U 1 1 5BB413FD
P 2650 5100
F 0 "#PWR?" H 2650 4850 50  0001 C CNN
F 1 "GND" H 2655 4927 50  0000 C CNN
F 2 "" H 2650 5100 50  0001 C CNN
F 3 "" H 2650 5100 50  0001 C CNN
	1    2650 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 5100 2650 4950
Wire Wire Line
	2650 4950 2100 4950
Wire Wire Line
	2100 4350 2650 4350
Wire Wire Line
	2650 4350 2650 4950
Connection ~ 2650 4950
$EndSCHEMATC
