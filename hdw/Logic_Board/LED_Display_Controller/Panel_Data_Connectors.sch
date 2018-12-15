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
Comp "Marquette University Senior Design 2018/2019 Group E44"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J2901
U 1 1 5BB405EB
P 2550 1570
F 0 "J2901" H 2600 2087 50  0000 C CNN
F 1 "STRING 1" H 2600 1996 50  0000 C CNN
F 2 "Connectors_IDC:IDC-Header_2x08_Pitch2.54mm_Straight" H 2550 1570 50  0001 C CNN
F 3 "~" H 2550 1570 50  0001 C CNN
F 4 "ED10523-ND" H 0   -230 50  0001 C CNN "Digi-Key PN"
	1    2550 1570
	1    0    0    -1  
$EndComp
Text GLabel 2350 1670 0    50   Input ~ 0
Row_A_POS5
Text GLabel 2850 1670 2    50   Input ~ 0
Row_B_POS5
Text GLabel 2850 1770 2    50   Input ~ 0
Row_D_POS5
Text GLabel 2850 1570 2    50   Input ~ 0
Row_E_POS5
Text GLabel 2350 1770 0    50   Input ~ 0
Row_C_POS5
Text GLabel 2350 1870 0    50   Input ~ 0
Panel_CLK_POS5
Text GLabel 2350 1970 0    40   Input ~ 0
~Panel_OE_POS5
Text GLabel 2850 1870 2    50   Input ~ 0
Panel_LAT_POS5
Text GLabel 2350 1270 0    50   Input ~ 0
R0_POS5
Text GLabel 2350 1370 0    50   Input ~ 0
B0_POS5
Text GLabel 2350 1470 0    50   Input ~ 0
R1_POS5
Text GLabel 2350 1570 0    50   Input ~ 0
B1_POS5
Text GLabel 2850 1270 2    50   Input ~ 0
G0_POS5
Text GLabel 2850 1470 2    50   Input ~ 0
G1_POS5
$Comp
L power:GND #PWR02901
U 1 1 5BB40845
P 3650 2120
F 0 "#PWR02901" H 3650 1870 50  0001 C CNN
F 1 "GND" H 3655 1947 50  0000 C CNN
F 2 "" H 3650 2120 50  0001 C CNN
F 3 "" H 3650 2120 50  0001 C CNN
	1    3650 2120
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 2120 3650 1970
Wire Wire Line
	3650 1370 3650 1970
Connection ~ 3650 1970
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J2902
U 1 1 5BB40C27
P 2550 3070
F 0 "J2902" H 2600 3587 50  0000 C CNN
F 1 "STRING 2" H 2600 3496 50  0000 C CNN
F 2 "Connectors_IDC:IDC-Header_2x08_Pitch2.54mm_Straight" H 2550 3070 50  0001 C CNN
F 3 "~" H 2550 3070 50  0001 C CNN
F 4 "ED10523-ND" H 0   -230 50  0001 C CNN "Digi-Key PN"
	1    2550 3070
	1    0    0    -1  
$EndComp
Text GLabel 2350 3170 0    50   Input ~ 0
Row_A_POS5
Text GLabel 2850 3170 2    50   Input ~ 0
Row_B_POS5
Text GLabel 2850 3270 2    50   Input ~ 0
Row_D_POS5
Text GLabel 2850 3070 2    50   Input ~ 0
Row_E_POS5
Text GLabel 2350 3270 0    50   Input ~ 0
Row_C_POS5
Text GLabel 2350 3370 0    50   Input ~ 0
Panel_CLK_POS5
Text GLabel 2350 3470 0    40   Input ~ 0
~Panel_OE_POS5
Text GLabel 2850 3370 2    50   Input ~ 0
Panel_LAT_POS5
Text GLabel 2350 2770 0    50   Input ~ 0
R2_POS5
Text GLabel 2350 2870 0    50   Input ~ 0
B2_POS5
Text GLabel 2350 2970 0    50   Input ~ 0
R3_POS5
Text GLabel 2350 3070 0    50   Input ~ 0
B3_POS5
Text GLabel 2850 2770 2    50   Input ~ 0
G2_POS5
Text GLabel 2850 2970 2    50   Input ~ 0
G3_POS5
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J2903
U 1 1 5BB40D11
P 2550 4570
F 0 "J2903" H 2600 5087 50  0000 C CNN
F 1 "STRING 3" H 2600 4996 50  0000 C CNN
F 2 "Connectors_IDC:IDC-Header_2x08_Pitch2.54mm_Straight" H 2550 4570 50  0001 C CNN
F 3 "~" H 2550 4570 50  0001 C CNN
F 4 "ED10523-ND" H 0   -230 50  0001 C CNN "Digi-Key PN"
	1    2550 4570
	1    0    0    -1  
$EndComp
Text GLabel 2350 4670 0    50   Input ~ 0
Row_A_POS5
Text GLabel 2850 4670 2    50   Input ~ 0
Row_B_POS5
Text GLabel 2850 4770 2    50   Input ~ 0
Row_D_POS5
Text GLabel 2850 4570 2    50   Input ~ 0
Row_E_POS5
Text GLabel 2350 4770 0    50   Input ~ 0
Row_C_POS5
Text GLabel 2350 4870 0    50   Input ~ 0
Panel_CLK_POS5
Text GLabel 2350 4970 0    40   Input ~ 0
~Panel_OE_POS5
Text GLabel 2850 4870 2    50   Input ~ 0
Panel_LAT_POS5
Text GLabel 2350 4270 0    50   Input ~ 0
R4_POS5
Text GLabel 2350 4370 0    50   Input ~ 0
B4_POS5
Text GLabel 2350 4470 0    50   Input ~ 0
R5_POS5
Text GLabel 2350 4570 0    50   Input ~ 0
B5_POS5
Text GLabel 2850 4270 2    50   Input ~ 0
G4_POS5
Text GLabel 2850 4470 2    50   Input ~ 0
G5_POS5
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J2904
U 1 1 5BB40D31
P 2550 6070
F 0 "J2904" H 2600 6587 50  0000 C CNN
F 1 "STRING 4" H 2600 6496 50  0000 C CNN
F 2 "Connectors_IDC:IDC-Header_2x08_Pitch2.54mm_Straight" H 2550 6070 50  0001 C CNN
F 3 "~" H 2550 6070 50  0001 C CNN
F 4 "ED10523-ND" H 0   -230 50  0001 C CNN "Digi-Key PN"
	1    2550 6070
	1    0    0    -1  
$EndComp
Text GLabel 2350 6170 0    50   Input ~ 0
Row_A_POS5
Text GLabel 2850 6170 2    50   Input ~ 0
Row_B_POS5
Text GLabel 2850 6270 2    50   Input ~ 0
Row_D_POS5
Text GLabel 2850 6070 2    50   Input ~ 0
Row_E_POS5
Text GLabel 2350 6270 0    50   Input ~ 0
Row_C_POS5
Text GLabel 2350 6370 0    50   Input ~ 0
Panel_CLK_POS5
Text GLabel 2350 6470 0    40   Input ~ 0
~Panel_OE_POS5
Text GLabel 2850 6370 2    50   Input ~ 0
Panel_LAT_POS5
Text GLabel 2350 5770 0    50   Input ~ 0
R6_POS5
Text GLabel 2350 5870 0    50   Input ~ 0
B6_POS5
Text GLabel 2350 5970 0    50   Input ~ 0
R7_POS5
Text GLabel 2350 6070 0    50   Input ~ 0
B7_POS5
Text GLabel 2850 5770 2    50   Input ~ 0
G6_POS5
Text GLabel 2850 5970 2    50   Input ~ 0
G7_POS5
Text GLabel 6580 1450 1    50   Input ~ 0
Row_A_POS5
Text GLabel 6480 1450 1    50   Input ~ 0
Row_C_POS5
Text GLabel 5030 1450 1    50   Input ~ 0
R0_POS5
Text GLabel 4930 1450 1    50   Input ~ 0
B0_POS5
Text GLabel 4730 1450 1    50   Input ~ 0
R1_POS5
Text GLabel 6680 1450 1    50   Input ~ 0
B1_POS5
Text GLabel 8430 1450 1    50   Input ~ 0
Panel_CLK_POS5
Text GLabel 8030 1450 1    40   Input ~ 0
~Panel_OE_POS5
Text GLabel 6380 1450 1    50   Input ~ 0
Row_B_POS5
Text GLabel 8330 1450 1    50   Input ~ 0
Row_D_POS5
Text GLabel 6780 1450 1    50   Input ~ 0
Row_E_POS5
Text GLabel 8230 1450 1    50   Input ~ 0
Panel_LAT_POS5
Text GLabel 5130 1450 1    50   Input ~ 0
G0_POS5
Text GLabel 4830 1450 1    50   Input ~ 0
G1_POS5
Text Notes 2130 7740 0    50   ~ 0
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
$Comp
L Power_Protection:SP0505BAJT D2901
U 1 1 5C14E3A9
P 4930 1650
F 0 "D2901" H 5230 1750 50  0000 L CNN
F 1 "SP0505BAJT" H 5230 1675 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 5230 1600 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 5055 1775 50  0001 C CNN
F 4 "F3160CT-ND" H 4930 1650 50  0001 C CNN "Digi-Key PN"
	1    4930 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02905
U 1 1 5C150614
P 4930 1850
F 0 "#PWR02905" H 4930 1600 50  0001 C CNN
F 1 "GND" H 4930 1700 50  0000 C CNN
F 2 "" H 4930 1850 50  0001 C CNN
F 3 "" H 4930 1850 50  0001 C CNN
	1    4930 1850
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2902
U 1 1 5C150760
P 6580 1650
F 0 "D2902" H 6880 1750 50  0000 L CNN
F 1 "SP0505BAJT" H 6880 1675 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 6880 1600 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 6705 1775 50  0001 C CNN
F 4 "F3160CT-ND" H 6580 1650 50  0001 C CNN "Digi-Key PN"
	1    6580 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02906
U 1 1 5C150767
P 6580 1850
F 0 "#PWR02906" H 6580 1600 50  0001 C CNN
F 1 "GND" H 6580 1700 50  0000 C CNN
F 2 "" H 6580 1850 50  0001 C CNN
F 3 "" H 6580 1850 50  0001 C CNN
	1    6580 1850
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2903
U 1 1 5C150847
P 8230 1650
F 0 "D2903" H 8530 1750 50  0000 L CNN
F 1 "SP0505BAJT" H 8530 1675 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 8530 1600 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 8355 1775 50  0001 C CNN
F 4 "F3160CT-ND" H 8230 1650 50  0001 C CNN "Digi-Key PN"
	1    8230 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02907
U 1 1 5C15084E
P 8230 1850
F 0 "#PWR02907" H 8230 1600 50  0001 C CNN
F 1 "GND" H 8230 1700 50  0000 C CNN
F 2 "" H 8230 1850 50  0001 C CNN
F 3 "" H 8230 1850 50  0001 C CNN
	1    8230 1850
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2904
U 1 1 5C167280
P 4930 3150
F 0 "D2904" H 5230 3250 50  0000 L CNN
F 1 "SP0505BAJT" H 5230 3175 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 5230 3100 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 5055 3275 50  0001 C CNN
F 4 "F3160CT-ND" H 4930 3150 50  0001 C CNN "Digi-Key PN"
	1    4930 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02908
U 1 1 5C167287
P 4930 3350
F 0 "#PWR02908" H 4930 3100 50  0001 C CNN
F 1 "GND" H 4930 3200 50  0000 C CNN
F 2 "" H 4930 3350 50  0001 C CNN
F 3 "" H 4930 3350 50  0001 C CNN
	1    4930 3350
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2905
U 1 1 5C16728E
P 6580 3150
F 0 "D2905" H 6880 3250 50  0000 L CNN
F 1 "SP0505BAJT" H 6880 3175 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 6880 3100 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 6705 3275 50  0001 C CNN
F 4 "F3160CT-ND" H 6580 3150 50  0001 C CNN "Digi-Key PN"
	1    6580 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02911
U 1 1 5C167295
P 6580 3350
F 0 "#PWR02911" H 6580 3100 50  0001 C CNN
F 1 "GND" H 6580 3200 50  0000 C CNN
F 2 "" H 6580 3350 50  0001 C CNN
F 3 "" H 6580 3350 50  0001 C CNN
	1    6580 3350
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2906
U 1 1 5C16729C
P 8230 3150
F 0 "D2906" H 8530 3250 50  0000 L CNN
F 1 "SP0505BAJT" H 8530 3175 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 8530 3100 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 8355 3275 50  0001 C CNN
F 4 "F3160CT-ND" H 8230 3150 50  0001 C CNN "Digi-Key PN"
	1    8230 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02914
U 1 1 5C1672A3
P 8230 3350
F 0 "#PWR02914" H 8230 3100 50  0001 C CNN
F 1 "GND" H 8230 3200 50  0000 C CNN
F 2 "" H 8230 3350 50  0001 C CNN
F 3 "" H 8230 3350 50  0001 C CNN
	1    8230 3350
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2907
U 1 1 5C1674BD
P 4930 4650
F 0 "D2907" H 5230 4750 50  0000 L CNN
F 1 "SP0505BAJT" H 5230 4675 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 5230 4600 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 5055 4775 50  0001 C CNN
F 4 "F3160CT-ND" H 4930 4650 50  0001 C CNN "Digi-Key PN"
	1    4930 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02909
U 1 1 5C1674C4
P 4930 4850
F 0 "#PWR02909" H 4930 4600 50  0001 C CNN
F 1 "GND" H 4930 4700 50  0000 C CNN
F 2 "" H 4930 4850 50  0001 C CNN
F 3 "" H 4930 4850 50  0001 C CNN
	1    4930 4850
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2908
U 1 1 5C1674CB
P 6580 4650
F 0 "D2908" H 6880 4750 50  0000 L CNN
F 1 "SP0505BAJT" H 6880 4675 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 6880 4600 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 6705 4775 50  0001 C CNN
F 4 "F3160CT-ND" H 6580 4650 50  0001 C CNN "Digi-Key PN"
	1    6580 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02912
U 1 1 5C1674D2
P 6580 4850
F 0 "#PWR02912" H 6580 4600 50  0001 C CNN
F 1 "GND" H 6580 4700 50  0000 C CNN
F 2 "" H 6580 4850 50  0001 C CNN
F 3 "" H 6580 4850 50  0001 C CNN
	1    6580 4850
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2909
U 1 1 5C1674D9
P 8230 4650
F 0 "D2909" H 8530 4750 50  0000 L CNN
F 1 "SP0505BAJT" H 8530 4675 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 8530 4600 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 8355 4775 50  0001 C CNN
F 4 "F3160CT-ND" H 8230 4650 50  0001 C CNN "Digi-Key PN"
	1    8230 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02915
U 1 1 5C1674E0
P 8230 4850
F 0 "#PWR02915" H 8230 4600 50  0001 C CNN
F 1 "GND" H 8230 4700 50  0000 C CNN
F 2 "" H 8230 4850 50  0001 C CNN
F 3 "" H 8230 4850 50  0001 C CNN
	1    8230 4850
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2910
U 1 1 5C1674F6
P 4930 6150
F 0 "D2910" H 5230 6250 50  0000 L CNN
F 1 "SP0505BAJT" H 5230 6175 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 5230 6100 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 5055 6275 50  0001 C CNN
F 4 "F3160CT-ND" H 4930 6150 50  0001 C CNN "Digi-Key PN"
	1    4930 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02910
U 1 1 5C1674FD
P 4930 6350
F 0 "#PWR02910" H 4930 6100 50  0001 C CNN
F 1 "GND" H 4930 6200 50  0000 C CNN
F 2 "" H 4930 6350 50  0001 C CNN
F 3 "" H 4930 6350 50  0001 C CNN
	1    4930 6350
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2911
U 1 1 5C167504
P 6580 6150
F 0 "D2911" H 6880 6250 50  0000 L CNN
F 1 "SP0505BAJT" H 6880 6175 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 6880 6100 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 6705 6275 50  0001 C CNN
F 4 "F3160CT-ND" H 6580 6150 50  0001 C CNN "Digi-Key PN"
	1    6580 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02913
U 1 1 5C16750B
P 6580 6350
F 0 "#PWR02913" H 6580 6100 50  0001 C CNN
F 1 "GND" H 6580 6200 50  0000 C CNN
F 2 "" H 6580 6350 50  0001 C CNN
F 3 "" H 6580 6350 50  0001 C CNN
	1    6580 6350
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D2912
U 1 1 5C167512
P 8230 6150
F 0 "D2912" H 8530 6250 50  0000 L CNN
F 1 "SP0505BAJT" H 8530 6175 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 8530 6100 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 8355 6275 50  0001 C CNN
F 4 "F3160CT-ND" H 8230 6150 50  0001 C CNN "Digi-Key PN"
	1    8230 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02916
U 1 1 5C167519
P 8230 6350
F 0 "#PWR02916" H 8230 6100 50  0001 C CNN
F 1 "GND" H 8230 6200 50  0000 C CNN
F 2 "" H 8230 6350 50  0001 C CNN
F 3 "" H 8230 6350 50  0001 C CNN
	1    8230 6350
	1    0    0    -1  
$EndComp
NoConn ~ 8130 1450
NoConn ~ 8130 2950
NoConn ~ 8130 4450
NoConn ~ 8130 5950
Text GLabel 5030 2950 1    50   Input ~ 0
R2_POS5
Text GLabel 4930 2950 1    50   Input ~ 0
B2_POS5
Text GLabel 4730 2950 1    50   Input ~ 0
R3_POS5
Text GLabel 5130 2950 1    50   Input ~ 0
G2_POS5
Text GLabel 4830 2950 1    50   Input ~ 0
G3_POS5
Text GLabel 5030 4450 1    50   Input ~ 0
R4_POS5
Text GLabel 4930 4450 1    50   Input ~ 0
B4_POS5
Text GLabel 4730 4450 1    50   Input ~ 0
R5_POS5
Text GLabel 5130 4450 1    50   Input ~ 0
G4_POS5
Text GLabel 4830 4450 1    50   Input ~ 0
G5_POS5
Text GLabel 5030 5950 1    50   Input ~ 0
R6_POS5
Text GLabel 4930 5950 1    50   Input ~ 0
B6_POS5
Text GLabel 4730 5950 1    50   Input ~ 0
R7_POS5
Text GLabel 5130 5950 1    50   Input ~ 0
G6_POS5
Text GLabel 4830 5950 1    50   Input ~ 0
G7_POS5
Text GLabel 6580 2950 1    50   Input ~ 0
Row_A_POS5
Text GLabel 6480 2950 1    50   Input ~ 0
Row_C_POS5
Text GLabel 6680 2950 1    50   Input ~ 0
B1_POS5
Text GLabel 6380 2950 1    50   Input ~ 0
Row_B_POS5
Text GLabel 6780 2950 1    50   Input ~ 0
Row_E_POS5
Text GLabel 6580 4450 1    50   Input ~ 0
Row_A_POS5
Text GLabel 6480 4450 1    50   Input ~ 0
Row_C_POS5
Text GLabel 6680 4450 1    50   Input ~ 0
B1_POS5
Text GLabel 6380 4450 1    50   Input ~ 0
Row_B_POS5
Text GLabel 6780 4450 1    50   Input ~ 0
Row_E_POS5
Text GLabel 6580 5950 1    50   Input ~ 0
Row_A_POS5
Text GLabel 6480 5950 1    50   Input ~ 0
Row_C_POS5
Text GLabel 6680 5950 1    50   Input ~ 0
B1_POS5
Text GLabel 6380 5950 1    50   Input ~ 0
Row_B_POS5
Text GLabel 6780 5950 1    50   Input ~ 0
Row_E_POS5
Text GLabel 8430 2950 1    50   Input ~ 0
Panel_CLK_POS5
Text GLabel 8030 2950 1    40   Input ~ 0
~Panel_OE_POS5
Text GLabel 8330 2950 1    50   Input ~ 0
Row_D_POS5
Text GLabel 8230 2950 1    50   Input ~ 0
Panel_LAT_POS5
Text GLabel 8430 4450 1    50   Input ~ 0
Panel_CLK_POS5
Text GLabel 8030 4450 1    40   Input ~ 0
~Panel_OE_POS5
Text GLabel 8330 4450 1    50   Input ~ 0
Row_D_POS5
Text GLabel 8230 4450 1    50   Input ~ 0
Panel_LAT_POS5
Text GLabel 8430 5950 1    50   Input ~ 0
CLK_POS5
Text GLabel 8030 5950 1    40   Input ~ 0
~OE_POS5
Text GLabel 8330 5950 1    50   Input ~ 0
Row_D_POS5
Text GLabel 8230 5950 1    50   Input ~ 0
LAT_POS5
Wire Wire Line
	2850 1970 3650 1970
Wire Wire Line
	2850 1370 3650 1370
$Comp
L power:GND #PWR0110
U 1 1 5C1900F3
P 3650 3620
F 0 "#PWR0110" H 3650 3370 50  0001 C CNN
F 1 "GND" H 3655 3447 50  0000 C CNN
F 2 "" H 3650 3620 50  0001 C CNN
F 3 "" H 3650 3620 50  0001 C CNN
	1    3650 3620
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 3620 3650 3470
Wire Wire Line
	3650 2870 3650 3470
Connection ~ 3650 3470
Wire Wire Line
	2850 3470 3650 3470
Wire Wire Line
	2850 2870 3650 2870
$Comp
L power:GND #PWR0111
U 1 1 5C190162
P 3650 5120
F 0 "#PWR0111" H 3650 4870 50  0001 C CNN
F 1 "GND" H 3655 4947 50  0000 C CNN
F 2 "" H 3650 5120 50  0001 C CNN
F 3 "" H 3650 5120 50  0001 C CNN
	1    3650 5120
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 5120 3650 4970
Wire Wire Line
	3650 4370 3650 4970
Connection ~ 3650 4970
Wire Wire Line
	2850 4970 3650 4970
Wire Wire Line
	2850 4370 3650 4370
$Comp
L power:GND #PWR0112
U 1 1 5C1901F7
P 3650 6620
F 0 "#PWR0112" H 3650 6370 50  0001 C CNN
F 1 "GND" H 3655 6447 50  0000 C CNN
F 2 "" H 3650 6620 50  0001 C CNN
F 3 "" H 3650 6620 50  0001 C CNN
	1    3650 6620
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 6620 3650 6470
Wire Wire Line
	3650 5870 3650 6470
Connection ~ 3650 6470
Wire Wire Line
	2850 6470 3650 6470
Wire Wire Line
	2850 5870 3650 5870
$EndSCHEMATC
