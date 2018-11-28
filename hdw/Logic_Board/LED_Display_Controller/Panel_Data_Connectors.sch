EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 29 31
Title "Electronic Display Logic Board"
Date "2018-11-28"
Rev "A"
Comp "Marquette University Senior Design 2018 Group E44"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J2901
U 1 1 5BB405EB
P 2550 1800
F 0 "J2901" H 2600 2317 50  0000 C CNN
F 1 "STRING 1" H 2600 2226 50  0000 C CNN
F 2 "" H 2550 1800 50  0001 C CNN
F 3 "~" H 2550 1800 50  0001 C CNN
	1    2550 1800
	1    0    0    -1  
$EndComp
Text GLabel 2350 1900 0    50   Input ~ 0
Row_A_POS5
Text GLabel 2850 1900 2    50   Input ~ 0
Row_B_POS5
Text GLabel 2850 2000 2    50   Input ~ 0
Row_D_POS5
Text GLabel 2850 1800 2    50   Input ~ 0
Row_E_POS5
Text GLabel 2350 2000 0    50   Input ~ 0
Row_C_POS5
Text GLabel 2350 2100 0    50   Input ~ 0
CLK_POS5
Text GLabel 2350 2200 0    40   Input ~ 0
~OE_POS5
Text GLabel 2850 2100 2    50   Input ~ 0
LAT_POS5
Text GLabel 2350 1500 0    50   Input ~ 0
R0_POS5
Text GLabel 2350 1600 0    50   Input ~ 0
B0_POS5
Text GLabel 2350 1700 0    50   Input ~ 0
R1_POS5
Text GLabel 2350 1800 0    50   Input ~ 0
B1_POS5
Text GLabel 2850 1500 2    50   Input ~ 0
G0_POS5
Text GLabel 2850 1700 2    50   Input ~ 0
G1_POS5
$Comp
L power:GND #PWR02901
U 1 1 5BB40845
P 3400 2350
F 0 "#PWR02901" H 3400 2100 50  0001 C CNN
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
L Connector_Generic:Conn_02x08_Odd_Even J2902
U 1 1 5BB40C27
P 2550 3300
F 0 "J2902" H 2600 3817 50  0000 C CNN
F 1 "STRING 2" H 2600 3726 50  0000 C CNN
F 2 "" H 2550 3300 50  0001 C CNN
F 3 "~" H 2550 3300 50  0001 C CNN
	1    2550 3300
	1    0    0    -1  
$EndComp
Text GLabel 2350 3400 0    50   Input ~ 0
Row_A_POS5
Text GLabel 2850 3400 2    50   Input ~ 0
Row_B_POS5
Text GLabel 2850 3500 2    50   Input ~ 0
Row_D_POS5
Text GLabel 2850 3300 2    50   Input ~ 0
Row_E_POS5
Text GLabel 2350 3500 0    50   Input ~ 0
Row_C_POS5
Text GLabel 2350 3600 0    50   Input ~ 0
CLK_POS5
Text GLabel 2350 3700 0    40   Input ~ 0
~OE_POS5
Text GLabel 2850 3600 2    50   Input ~ 0
LAT_POS5
Text GLabel 2350 3000 0    50   Input ~ 0
R2_POS5
Text GLabel 2350 3100 0    50   Input ~ 0
B2_POS5
Text GLabel 2350 3200 0    50   Input ~ 0
R3_POS5
Text GLabel 2350 3300 0    50   Input ~ 0
B3_POS5
Text GLabel 2850 3000 2    50   Input ~ 0
G2_POS5
Text GLabel 2850 3200 2    50   Input ~ 0
G3_POS5
$Comp
L power:GND #PWR02902
U 1 1 5BB40C3C
P 3400 3850
F 0 "#PWR02902" H 3400 3600 50  0001 C CNN
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
L Connector_Generic:Conn_02x08_Odd_Even J2903
U 1 1 5BB40D11
P 2550 4800
F 0 "J2903" H 2600 5317 50  0000 C CNN
F 1 "STRING 3" H 2600 5226 50  0000 C CNN
F 2 "" H 2550 4800 50  0001 C CNN
F 3 "~" H 2550 4800 50  0001 C CNN
	1    2550 4800
	1    0    0    -1  
$EndComp
Text GLabel 2350 4900 0    50   Input ~ 0
Row_A_POS5
Text GLabel 2850 4900 2    50   Input ~ 0
Row_B_POS5
Text GLabel 2850 5000 2    50   Input ~ 0
Row_D_POS5
Text GLabel 2850 4800 2    50   Input ~ 0
Row_E_POS5
Text GLabel 2350 5000 0    50   Input ~ 0
Row_C_POS5
Text GLabel 2350 5100 0    50   Input ~ 0
CLK_POS5
Text GLabel 2350 5200 0    40   Input ~ 0
~OE_POS5
Text GLabel 2850 5100 2    50   Input ~ 0
LAT_POS5
Text GLabel 2350 4500 0    50   Input ~ 0
R4_POS5
Text GLabel 2350 4600 0    50   Input ~ 0
B4_POS5
Text GLabel 2350 4700 0    50   Input ~ 0
R5_POS5
Text GLabel 2350 4800 0    50   Input ~ 0
B5_POS5
Text GLabel 2850 4500 2    50   Input ~ 0
G4_POS5
Text GLabel 2850 4700 2    50   Input ~ 0
G5_POS5
$Comp
L power:GND #PWR02903
U 1 1 5BB40D26
P 3400 5350
F 0 "#PWR02903" H 3400 5100 50  0001 C CNN
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
L Connector_Generic:Conn_02x08_Odd_Even J2904
U 1 1 5BB40D31
P 2550 6300
F 0 "J2904" H 2600 6817 50  0000 C CNN
F 1 "STRING 4" H 2600 6726 50  0000 C CNN
F 2 "" H 2550 6300 50  0001 C CNN
F 3 "~" H 2550 6300 50  0001 C CNN
	1    2550 6300
	1    0    0    -1  
$EndComp
Text GLabel 2350 6400 0    50   Input ~ 0
Row_A_POS5
Text GLabel 2850 6400 2    50   Input ~ 0
Row_B_POS5
Text GLabel 2850 6500 2    50   Input ~ 0
Row_D_POS5
Text GLabel 2850 6300 2    50   Input ~ 0
Row_E_POS5
Text GLabel 2350 6500 0    50   Input ~ 0
Row_C_POS5
Text GLabel 2350 6600 0    50   Input ~ 0
CLK_POS5
Text GLabel 2350 6700 0    40   Input ~ 0
~OE_POS5
Text GLabel 2850 6600 2    50   Input ~ 0
LAT_POS5
Text GLabel 2350 6000 0    50   Input ~ 0
R6_POS5
Text GLabel 2350 6100 0    50   Input ~ 0
B6_POS5
Text GLabel 2350 6200 0    50   Input ~ 0
R7_POS5
Text GLabel 2350 6300 0    50   Input ~ 0
B7_POS5
Text GLabel 2850 6000 2    50   Input ~ 0
G6_POS5
Text GLabel 2850 6200 2    50   Input ~ 0
G7_POS5
$Comp
L power:GND #PWR02904
U 1 1 5BB40D46
P 3400 6850
F 0 "#PWR02904" H 3400 6600 50  0001 C CNN
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
$Comp
L Power_Protection:SP0505BAJT D2901
U 1 1 5BFD0D17
P 4690 2560
F 0 "D2901" H 4990 2660 50  0000 L CNN
F 1 "SP0505BAJT" H 4990 2585 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 4990 2510 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 4815 2685 50  0001 C CNN
	1    4690 2560
	1    0    0    -1  
$EndComp
Text GLabel 4490 3650 1    50   Input ~ 0
Row_A_POS5
Text GLabel 4590 3650 1    50   Input ~ 0
Row_C_POS5
Text GLabel 4490 2360 1    50   Input ~ 0
R0_POS5
Text GLabel 4590 2360 1    50   Input ~ 0
B0_POS5
Text GLabel 4690 2360 1    50   Input ~ 0
R1_POS5
Text GLabel 4790 2360 1    50   Input ~ 0
B1_POS5
Text GLabel 5680 3650 1    50   Input ~ 0
CLK_POS5
Text GLabel 5780 3650 1    40   Input ~ 0
~OE_POS5
Text GLabel 4790 3650 1    50   Input ~ 0
Row_B_POS5
Text GLabel 4890 3650 1    50   Input ~ 0
Row_D_POS5
Text GLabel 4690 3650 1    50   Input ~ 0
Row_E_POS5
Text GLabel 5880 3650 1    50   Input ~ 0
LAT_POS5
Text GLabel 4890 2360 1    50   Input ~ 0
G0_POS5
Text GLabel 5680 2360 1    50   Input ~ 0
G1_POS5
Text GLabel 5780 2360 1    50   Input ~ 0
R2_POS5
Text GLabel 5880 2360 1    50   Input ~ 0
B2_POS5
Text GLabel 5980 2360 1    50   Input ~ 0
R3_POS5
Text GLabel 6080 2360 1    50   Input ~ 0
B3_POS5
Text GLabel 6870 2360 1    50   Input ~ 0
R4_POS5
Text GLabel 6970 2360 1    50   Input ~ 0
B4_POS5
Text GLabel 7070 2360 1    50   Input ~ 0
R5_POS5
Text GLabel 7170 2360 1    50   Input ~ 0
B5_POS5
Text GLabel 7270 2360 1    50   Input ~ 0
R6_POS5
Text GLabel 8060 2360 1    50   Input ~ 0
B6_POS5
Text GLabel 8160 2360 1    50   Input ~ 0
R7_POS5
Text GLabel 8260 2360 1    50   Input ~ 0
B7_POS5
Text GLabel 8360 2360 1    50   Input ~ 0
G2_POS5
Text GLabel 8460 2360 1    50   Input ~ 0
G3_POS5
Text GLabel 9530 2360 1    50   Input ~ 0
G3_POS5
Text GLabel 9630 2360 1    50   Input ~ 0
G5_POS5
Text GLabel 9330 2360 1    50   Input ~ 0
G6_POS5
Text GLabel 9430 2360 1    50   Input ~ 0
G7_POS5
$Comp
L power:GND #PWR02905
U 1 1 5BFE01B1
P 4690 2760
F 0 "#PWR02905" H 4690 2510 50  0001 C CNN
F 1 "GND" H 4690 2610 50  0000 C CNN
F 2 "" H 4690 2760 50  0001 C CNN
F 3 "" H 4690 2760 50  0001 C CNN
	1    4690 2760
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2903
U 1 1 5BFE2189
P 5880 2560
F 0 "D2903" H 6180 2660 50  0000 L CNN
F 1 "SP0505BAJT" H 6180 2585 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 6180 2510 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 6005 2685 50  0001 C CNN
	1    5880 2560
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02907
U 1 1 5BFE2190
P 5880 2760
F 0 "#PWR02907" H 5880 2510 50  0001 C CNN
F 1 "GND" H 5880 2610 50  0000 C CNN
F 2 "" H 5880 2760 50  0001 C CNN
F 3 "" H 5880 2760 50  0001 C CNN
	1    5880 2760
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2905
U 1 1 5BFE454E
P 7070 2560
F 0 "D2905" H 7370 2660 50  0000 L CNN
F 1 "SP0505BAJT" H 7370 2585 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 7370 2510 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 7195 2685 50  0001 C CNN
	1    7070 2560
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02909
U 1 1 5BFE4555
P 7070 2760
F 0 "#PWR02909" H 7070 2510 50  0001 C CNN
F 1 "GND" H 7070 2610 50  0000 C CNN
F 2 "" H 7070 2760 50  0001 C CNN
F 3 "" H 7070 2760 50  0001 C CNN
	1    7070 2760
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2906
U 1 1 5BFE8728
P 8260 2560
F 0 "D2906" H 8560 2660 50  0000 L CNN
F 1 "SP0505BAJT" H 8560 2585 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 8560 2510 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 8385 2685 50  0001 C CNN
	1    8260 2560
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02910
U 1 1 5BFE872F
P 8260 2760
F 0 "#PWR02910" H 8260 2510 50  0001 C CNN
F 1 "GND" H 8260 2610 50  0000 C CNN
F 2 "" H 8260 2760 50  0001 C CNN
F 3 "" H 8260 2760 50  0001 C CNN
	1    8260 2760
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2902
U 1 1 5BFEC8F8
P 4690 3850
F 0 "D2902" H 4990 3950 50  0000 L CNN
F 1 "SP0505BAJT" H 4990 3875 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 4990 3800 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 4815 3975 50  0001 C CNN
	1    4690 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02906
U 1 1 5BFEC8FF
P 4690 4050
F 0 "#PWR02906" H 4690 3800 50  0001 C CNN
F 1 "GND" H 4690 3900 50  0000 C CNN
F 2 "" H 4690 4050 50  0001 C CNN
F 3 "" H 4690 4050 50  0001 C CNN
	1    4690 4050
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2904
U 1 1 5BFEEC83
P 5880 3850
F 0 "D2904" H 6180 3950 50  0000 L CNN
F 1 "SP0505BAJT" H 6180 3875 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 6180 3800 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 6005 3975 50  0001 C CNN
	1    5880 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02908
U 1 1 5BFEEC8A
P 5880 4050
F 0 "#PWR02908" H 5880 3800 50  0001 C CNN
F 1 "GND" H 5880 3900 50  0000 C CNN
F 2 "" H 5880 4050 50  0001 C CNN
F 3 "" H 5880 4050 50  0001 C CNN
	1    5880 4050
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2907
U 1 1 5BFF32EE
P 9530 2560
F 0 "D2907" H 9830 2660 50  0000 L CNN
F 1 "SP0505BAJT" H 9830 2585 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 9830 2510 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 9655 2685 50  0001 C CNN
	1    9530 2560
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02911
U 1 1 5BFF32F5
P 9530 2760
F 0 "#PWR02911" H 9530 2510 50  0001 C CNN
F 1 "GND" H 9530 2610 50  0000 C CNN
F 2 "" H 9530 2760 50  0001 C CNN
F 3 "" H 9530 2760 50  0001 C CNN
	1    9530 2760
	1    0    0    -1  
$EndComp
NoConn ~ 9730 2360
NoConn ~ 5980 3650
NoConn ~ 6080 3650
Text Notes 6710 5650 0    50   ~ 0
String 1 is the top string,\nString 4 is the bottom string.\nEach string is 5 panels long\nEach panel is 64x64 pixels\nThis yields a 320x256 pixel overall display resolution
Text Notes 550  700  0    100  ~ 20
29. Panel Data Connectors
$Comp
L LED_Display_Local_Library:MU_Logo #G2901
U 1 1 5C002737
P 9900 1100
F 0 "#G2901" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
$EndSCHEMATC
