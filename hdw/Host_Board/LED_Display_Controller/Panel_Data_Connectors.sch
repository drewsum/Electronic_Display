EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 8 31
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
L power:GND #PWR0184
U 1 1 5BB40845
P 3400 2350
F 0 "#PWR0184" H 3400 2100 50  0001 C CNN
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
L power:GND #PWR0185
U 1 1 5BB40C3C
P 3400 3850
F 0 "#PWR0185" H 3400 3600 50  0001 C CNN
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
L power:GND #PWR0186
U 1 1 5BB40D26
P 3400 5350
F 0 "#PWR0186" H 3400 5100 50  0001 C CNN
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
L power:GND #PWR0187
U 1 1 5BB40D46
P 3400 6850
F 0 "#PWR0187" H 3400 6600 50  0001 C CNN
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
L Power_Protection:SP0505BAJT D?
U 1 1 5BFD0D17
P 5000 1680
F 0 "D?" H 5300 1780 50  0000 L CNN
F 1 "SP0505BAJT" H 5300 1705 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 5300 1630 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 5125 1805 50  0001 C CNN
	1    5000 1680
	1    0    0    -1  
$EndComp
Text GLabel 4800 2770 1    50   Input ~ 0
A_POS5
Text GLabel 4900 2770 1    50   Input ~ 0
C_POS5
Text GLabel 4800 1480 1    50   Input ~ 0
R1_POS5
Text GLabel 4900 1480 1    50   Input ~ 0
B1_POS5
Text GLabel 5000 1480 1    50   Input ~ 0
R2_POS5
Text GLabel 5100 1480 1    50   Input ~ 0
B2_POS5
Text GLabel 5990 2770 1    50   Input ~ 0
CLK_POS5
Text GLabel 6090 2770 1    40   Input ~ 0
~OE_POS5
Text GLabel 5100 2770 1    50   Input ~ 0
B_POS5
Text GLabel 5200 2770 1    50   Input ~ 0
D_POS5
Text GLabel 5000 2770 1    50   Input ~ 0
E_POS5
Text GLabel 6190 2770 1    50   Input ~ 0
LAT_POS5
Text GLabel 5200 1480 1    50   Input ~ 0
G1_POS5
Text GLabel 5990 1480 1    50   Input ~ 0
G2_POS5
Text GLabel 6090 1480 1    50   Input ~ 0
R3_POS5
Text GLabel 6190 1480 1    50   Input ~ 0
B3_POS5
Text GLabel 6290 1480 1    50   Input ~ 0
R4_POS5
Text GLabel 6390 1480 1    50   Input ~ 0
B4_POS5
Text GLabel 7180 1480 1    50   Input ~ 0
R5_POS5
Text GLabel 7280 1480 1    50   Input ~ 0
B5_POS5
Text GLabel 7380 1480 1    50   Input ~ 0
R6_POS5
Text GLabel 7480 1480 1    50   Input ~ 0
B6_POS5
Text GLabel 7580 1480 1    50   Input ~ 0
R7_POS5
Text GLabel 8370 1480 1    50   Input ~ 0
B7_POS5
Text GLabel 8470 1480 1    50   Input ~ 0
R8_POS5
Text GLabel 8570 1480 1    50   Input ~ 0
B8_POS5
Text GLabel 8670 1480 1    50   Input ~ 0
G3_POS5
Text GLabel 8770 1480 1    50   Input ~ 0
G4_POS5
Text GLabel 9840 1480 1    50   Input ~ 0
G5_POS5
Text GLabel 9940 1480 1    50   Input ~ 0
G6_POS5
Text GLabel 9640 1480 1    50   Input ~ 0
G7_POS5
Text GLabel 9740 1480 1    50   Input ~ 0
G8_POS5
$Comp
L power:GND #PWR?
U 1 1 5BFE01B1
P 5000 1880
F 0 "#PWR?" H 5000 1630 50  0001 C CNN
F 1 "GND" H 5000 1730 50  0000 C CNN
F 2 "" H 5000 1880 50  0001 C CNN
F 3 "" H 5000 1880 50  0001 C CNN
	1    5000 1880
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D?
U 1 1 5BFE2189
P 6190 1680
F 0 "D?" H 6490 1780 50  0000 L CNN
F 1 "SP0505BAJT" H 6490 1705 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 6490 1630 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 6315 1805 50  0001 C CNN
	1    6190 1680
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BFE2190
P 6190 1880
F 0 "#PWR?" H 6190 1630 50  0001 C CNN
F 1 "GND" H 6190 1730 50  0000 C CNN
F 2 "" H 6190 1880 50  0001 C CNN
F 3 "" H 6190 1880 50  0001 C CNN
	1    6190 1880
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D?
U 1 1 5BFE454E
P 7380 1680
F 0 "D?" H 7680 1780 50  0000 L CNN
F 1 "SP0505BAJT" H 7680 1705 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 7680 1630 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 7505 1805 50  0001 C CNN
	1    7380 1680
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BFE4555
P 7380 1880
F 0 "#PWR?" H 7380 1630 50  0001 C CNN
F 1 "GND" H 7380 1730 50  0000 C CNN
F 2 "" H 7380 1880 50  0001 C CNN
F 3 "" H 7380 1880 50  0001 C CNN
	1    7380 1880
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D?
U 1 1 5BFE8728
P 8570 1680
F 0 "D?" H 8870 1780 50  0000 L CNN
F 1 "SP0505BAJT" H 8870 1705 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 8870 1630 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 8695 1805 50  0001 C CNN
	1    8570 1680
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BFE872F
P 8570 1880
F 0 "#PWR?" H 8570 1630 50  0001 C CNN
F 1 "GND" H 8570 1730 50  0000 C CNN
F 2 "" H 8570 1880 50  0001 C CNN
F 3 "" H 8570 1880 50  0001 C CNN
	1    8570 1880
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D?
U 1 1 5BFEC8F8
P 5000 2970
F 0 "D?" H 5300 3070 50  0000 L CNN
F 1 "SP0505BAJT" H 5300 2995 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 5300 2920 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 5125 3095 50  0001 C CNN
	1    5000 2970
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BFEC8FF
P 5000 3170
F 0 "#PWR?" H 5000 2920 50  0001 C CNN
F 1 "GND" H 5000 3020 50  0000 C CNN
F 2 "" H 5000 3170 50  0001 C CNN
F 3 "" H 5000 3170 50  0001 C CNN
	1    5000 3170
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D?
U 1 1 5BFEEC83
P 6190 2970
F 0 "D?" H 6490 3070 50  0000 L CNN
F 1 "SP0505BAJT" H 6490 2995 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 6490 2920 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 6315 3095 50  0001 C CNN
	1    6190 2970
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BFEEC8A
P 6190 3170
F 0 "#PWR?" H 6190 2920 50  0001 C CNN
F 1 "GND" H 6190 3020 50  0000 C CNN
F 2 "" H 6190 3170 50  0001 C CNN
F 3 "" H 6190 3170 50  0001 C CNN
	1    6190 3170
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0505BAJT D?
U 1 1 5BFF32EE
P 9840 1680
F 0 "D?" H 10140 1780 50  0000 L CNN
F 1 "SP0505BAJT" H 10140 1705 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 10140 1630 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 9965 1805 50  0001 C CNN
	1    9840 1680
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BFF32F5
P 9840 1880
F 0 "#PWR?" H 9840 1630 50  0001 C CNN
F 1 "GND" H 9840 1730 50  0000 C CNN
F 2 "" H 9840 1880 50  0001 C CNN
F 3 "" H 9840 1880 50  0001 C CNN
	1    9840 1880
	1    0    0    -1  
$EndComp
NoConn ~ 10040 1480
NoConn ~ 6290 2770
NoConn ~ 6390 2770
Text Notes 6710 5650 0    50   ~ 0
String 1 is the top string,\nString 4 is the bottom string.\nEach string is 5 panels long\nEach panel is 64x64 pixels\nThis yields a 320x256 pixel overall display resolution
$EndSCHEMATC
