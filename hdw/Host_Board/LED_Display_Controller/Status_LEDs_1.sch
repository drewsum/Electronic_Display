EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 22 31
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
P 9500 5190
AR Path="/5BAAE16C/5BC13AD2" Ref="Q?"  Part="1" 
AR Path="/5BB844FD/5BC13AD2" Ref="Q?"  Part="1" 
F 0 "Q?" H 9700 5265 50  0000 L CNN
F 1 "BSS214NW" H 9700 5190 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-323_SC-70" H 9700 5115 50  0001 L CIN
F 3 "https://www.infineon.com/dgdl/Infineon-BSS214NW-DS-v02_02-en.pdf?fileId=db3a30431b3e89eb011b695aebc01bde" H 9500 5190 50  0001 L CNN
	1    9500 5190
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC13AD9
P 9600 5390
F 0 "#PWR?" H 9600 5140 50  0001 C CNN
F 1 "GND" H 9600 5240 50  0000 C CNN
F 2 "" H 9600 5390 50  0001 C CNN
F 3 "" H 9600 5390 50  0001 C CNN
	1    9600 5390
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 5BC13AE0
P 9600 4840
F 0 "D?" H 9600 4940 50  0000 C CNN
F 1 "Red" V 9630 4650 50  0000 C CNN
F 2 "" H 9600 4840 50  0001 C CNN
F 3 "~" H 9600 4840 50  0001 C CNN
F 4 "0603" V 9550 4660 50  0000 C CNN "foot"
	1    9600 4840
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BC13AEB
P 9600 4540
AR Path="/5BAAE1F3/5BC13AEB" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5BC13AEB" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5BC13AEB" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5BC13AEB" Ref="R?"  Part="1" 
F 0 "R?" H 9500 4540 50  0000 C CNN
F 1 "1k" V 9600 4540 50  0000 C CNN
F 2 "" H 9600 4540 50  0001 C CNN
F 3 "" H 9600 4540 50  0001 C CNN
F 4 "0603" H 9790 4620 50  0000 C CNN "display_footprint"
F 5 "1%" H 9780 4540 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 9810 4470 50  0000 C CNN "Wattage"
F 7 "PN" H 9900 4940 60  0001 C CNN "Digi-Key PN"
	1    9600 4540
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BC13AF6
P 8560 5190
F 0 "R?" V 8460 5190 50  0000 C CNN
F 1 "10" V 8560 5190 50  0000 C CNN
F 2 "" H 8560 5190 50  0001 C CNN
F 3 "" H 8560 5190 50  0001 C CNN
F 4 "0603" V 8660 5190 50  0000 C CNN "display_footprint"
F 5 "1%" V 8760 5190 50  0000 C CNN "Tolerance"
F 6 "1/10W" V 8860 5190 50  0000 C CNN "Wattage"
F 7 "PN" H 8860 5590 60  0001 C CNN "Digi-Key PN"
	1    8560 5190
	0    -1   -1   0   
$EndComp
Text GLabel 8410 5190 0    50   Input ~ 0
ICSP_DETECT
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BC13B02
P 9010 5420
AR Path="/5BAAE1F3/5BC13B02" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5BC13B02" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5BC13B02" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5BC13B02" Ref="R?"  Part="1" 
F 0 "R?" H 8910 5420 50  0000 C CNN
F 1 "10k" V 9010 5420 50  0000 C CNN
F 2 "" H 9010 5420 50  0001 C CNN
F 3 "" H 9010 5420 50  0001 C CNN
F 4 "0603" H 9200 5500 50  0000 C CNN "display_footprint"
F 5 "1%" H 9190 5420 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 9220 5350 50  0000 C CNN "Wattage"
F 7 "PN" H 9310 5820 60  0001 C CNN "Digi-Key PN"
	1    9010 5420
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC13B09
P 9010 5570
F 0 "#PWR?" H 9010 5320 50  0001 C CNN
F 1 "GND" H 9010 5420 50  0000 C CNN
F 2 "" H 9010 5570 50  0001 C CNN
F 3 "" H 9010 5570 50  0001 C CNN
	1    9010 5570
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BC13B0F
P 9600 4390
F 0 "#PWR?" H 9600 4240 50  0001 C CNN
F 1 "+3.3V" H 9600 4530 50  0000 C CNN
F 2 "" H 9600 4390 50  0001 C CNN
F 3 "" H 9600 4390 50  0001 C CNN
	1    9600 4390
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 5190 9010 5190
Wire Wire Line
	9010 5270 9010 5190
Connection ~ 9010 5190
Wire Wire Line
	9010 5190 8710 5190
$EndSCHEMATC
