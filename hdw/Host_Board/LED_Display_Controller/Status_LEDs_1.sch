EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 21 30
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
L Transistor_FET:BSS214NW Q?
U 1 1 5BC13AD2
P 2240 1690
AR Path="/5BAAE16C/5BC13AD2" Ref="Q?"  Part="1" 
AR Path="/5BB844FD/5BC13AD2" Ref="Q?"  Part="1" 
F 0 "Q?" H 2440 1765 50  0000 L CNN
F 1 "BSS214NW" H 2440 1690 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-323_SC-70" H 2440 1615 50  0001 L CIN
F 3 "https://www.infineon.com/dgdl/Infineon-BSS214NW-DS-v02_02-en.pdf?fileId=db3a30431b3e89eb011b695aebc01bde" H 2240 1690 50  0001 L CNN
	1    2240 1690
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC13AD9
P 2340 1890
F 0 "#PWR?" H 2340 1640 50  0001 C CNN
F 1 "GND" H 2340 1740 50  0000 C CNN
F 2 "" H 2340 1890 50  0001 C CNN
F 3 "" H 2340 1890 50  0001 C CNN
	1    2340 1890
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 5BC13AE0
P 2340 1340
F 0 "D?" H 2340 1440 50  0000 C CNN
F 1 "Red" V 2370 1150 50  0000 C CNN
F 2 "" H 2340 1340 50  0001 C CNN
F 3 "~" H 2340 1340 50  0001 C CNN
F 4 "0603" V 2290 1160 50  0000 C CNN "foot"
	1    2340 1340
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BC13AEB
P 2340 1040
AR Path="/5BAAE1F3/5BC13AEB" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5BC13AEB" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5BC13AEB" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5BC13AEB" Ref="R?"  Part="1" 
F 0 "R?" H 2240 1040 50  0000 C CNN
F 1 "1k" V 2340 1040 50  0000 C CNN
F 2 "" H 2340 1040 50  0001 C CNN
F 3 "" H 2340 1040 50  0001 C CNN
F 4 "0603" H 2530 1120 50  0000 C CNN "display_footprint"
F 5 "1%" H 2520 1040 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 2550 970 50  0000 C CNN "Wattage"
F 7 "PN" H 2640 1440 60  0001 C CNN "Digi-Key PN"
	1    2340 1040
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BC13AF6
P 1300 1690
F 0 "R?" V 1200 1690 50  0000 C CNN
F 1 "10" V 1300 1690 50  0000 C CNN
F 2 "" H 1300 1690 50  0001 C CNN
F 3 "" H 1300 1690 50  0001 C CNN
F 4 "0603" V 1400 1690 50  0000 C CNN "display_footprint"
F 5 "1%" V 1500 1690 50  0000 C CNN "Tolerance"
F 6 "1/10W" V 1600 1690 50  0000 C CNN "Wattage"
F 7 "PN" H 1600 2090 60  0001 C CNN "Digi-Key PN"
	1    1300 1690
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BC13B02
P 1750 1480
AR Path="/5BAAE1F3/5BC13B02" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5BC13B02" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5BC13B02" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5BC13B02" Ref="R?"  Part="1" 
F 0 "R?" H 1650 1480 50  0000 C CNN
F 1 "10k" V 1750 1480 50  0000 C CNN
F 2 "" H 1750 1480 50  0001 C CNN
F 3 "" H 1750 1480 50  0001 C CNN
F 4 "0603" H 1940 1560 50  0000 C CNN "display_footprint"
F 5 "1%" H 1930 1480 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 1960 1410 50  0000 C CNN "Wattage"
F 7 "PN" H 2050 1880 60  0001 C CNN "Digi-Key PN"
	1    1750 1480
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BC13B0F
P 2340 890
F 0 "#PWR?" H 2340 740 50  0001 C CNN
F 1 "+3.3V" H 2340 1030 50  0000 C CNN
F 2 "" H 2340 890 50  0001 C CNN
F 3 "" H 2340 890 50  0001 C CNN
	1    2340 890 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 1690 1750 1690
$Comp
L power:+3.3V #PWR?
U 1 1 5BE12615
P 1750 1330
F 0 "#PWR?" H 1750 1180 50  0001 C CNN
F 1 "+3.3V" H 1750 1470 50  0000 C CNN
F 2 "" H 1750 1330 50  0001 C CNN
F 3 "" H 1750 1330 50  0001 C CNN
	1    1750 1330
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 1630 1750 1690
Connection ~ 1750 1690
Wire Wire Line
	1750 1690 2040 1690
Text GLabel 1150 1690 0    50   Input ~ 0
~ACTIVE_LED
$EndSCHEMATC
