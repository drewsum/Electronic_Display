EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 13 26
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
L power:GND #PWR?
U 1 1 5BB4AFFE
P 5530 5330
F 0 "#PWR?" H 5530 5080 50  0001 C CNN
F 1 "GND" H 5530 5180 50  0000 C CNN
F 2 "" H 5530 5330 50  0001 C CNN
F 3 "" H 5530 5330 50  0001 C CNN
	1    5530 5330
	1    0    0    -1  
$EndComp
Wire Wire Line
	5530 5330 5530 5290
Wire Wire Line
	5530 5290 5480 5290
Wire Wire Line
	5480 5290 5480 5250
Wire Wire Line
	5530 5290 5580 5290
Wire Wire Line
	5580 5290 5580 5250
Connection ~ 5530 5290
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5BB4B21E
P 5530 2460
F 0 "#PWR?" H 5530 2310 50  0001 C CNN
F 1 "+3.3V" H 5530 2600 50  0000 C CNN
F 2 "" H 5530 2460 50  0000 C CNN
F 3 "" H 5530 2460 50  0000 C CNN
	1    5530 2460
	1    0    0    -1  
$EndComp
Wire Wire Line
	5530 2460 5530 2510
Wire Wire Line
	5530 2510 5580 2510
Wire Wire Line
	5580 2510 5580 2550
Wire Wire Line
	5530 2510 5480 2510
Wire Wire Line
	5480 2510 5480 2550
Connection ~ 5530 2510
Text GLabel 9810 2910 2    50   BiDi ~ 0
EBI_IO0
Text GLabel 9810 3010 2    50   BiDi ~ 0
EBI_IO1
Text GLabel 9810 3110 2    50   BiDi ~ 0
EBI_IO2
Text GLabel 9810 3210 2    50   BiDi ~ 0
EBI_IO3
Text GLabel 9810 3310 2    50   BiDi ~ 0
EBI_IO4
Text GLabel 9810 3410 2    50   BiDi ~ 0
EBI_IO5
Text GLabel 9810 3510 2    50   BiDi ~ 0
EBI_IO6
Text GLabel 9810 3610 2    50   BiDi ~ 0
EBI_IO7
Text GLabel 9810 3710 2    50   BiDi ~ 0
EBI_IO8
Text GLabel 9810 3810 2    50   BiDi ~ 0
EBI_IO9
Text GLabel 9810 3910 2    50   BiDi ~ 0
EBI_IO10
Text GLabel 9810 4010 2    50   BiDi ~ 0
EBI_IO11
Text GLabel 9810 4110 2    50   BiDi ~ 0
EBI_IO12
Text GLabel 9810 4210 2    50   BiDi ~ 0
EBI_IO13
Text GLabel 9810 4310 2    50   BiDi ~ 0
EBI_IO14
Text GLabel 9810 4410 2    50   BiDi ~ 0
EBI_IO15
Text GLabel 1490 1090 0    50   Input ~ 0
EBI_A0
Text GLabel 1490 1190 0    50   Input ~ 0
EBI_A1
Text GLabel 1490 1290 0    50   Input ~ 0
EBI_A2
Text GLabel 1490 1390 0    50   Input ~ 0
EBI_A3
Text GLabel 1490 1490 0    50   Input ~ 0
EBI_A4
Text GLabel 1490 1590 0    50   Input ~ 0
EBI_A5
Text GLabel 1490 1690 0    50   Input ~ 0
EBI_A6
Text GLabel 1490 1790 0    50   Input ~ 0
EBI_A7
Text GLabel 1490 1890 0    50   Input ~ 0
EBI_A8
Text GLabel 1490 1990 0    50   Input ~ 0
EBI_A9
Text GLabel 1490 2090 0    50   Input ~ 0
EBI_A10
Text GLabel 1490 2190 0    50   Input ~ 0
EBI_A11
Text GLabel 1490 2290 0    50   Input ~ 0
EBI_A12
Text GLabel 1490 2390 0    50   Input ~ 0
EBI_A13
Text GLabel 1490 2490 0    50   Input ~ 0
EBI_A14
Text GLabel 1490 2590 0    50   Input ~ 0
EBI_A15
Text GLabel 1490 2690 0    50   Input ~ 0
EBI_A16
Text GLabel 1490 2990 0    40   Input ~ 0
~EBI_BHE
Text GLabel 1490 3090 0    40   Input ~ 0
~EBI_BLE
Text GLabel 1490 3290 0    40   Input ~ 0
~EBI_CE
Text GLabel 9810 4810 2    40   Input ~ 0
~EBI_WE
Text GLabel 9810 4910 2    40   Input ~ 0
~EBI_OE
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C30C
P 1810 7220
AR Path="/5BAAE16C/5BB4C30C" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C30C" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C30C" Ref="C?"  Part="1" 
F 0 "C?" H 1835 7320 50  0000 L CNN
F 1 "0.1uF" H 1835 7120 50  0000 L CNN
F 2 "" H 1848 7070 50  0001 C CNN
F 3 "" H 1835 7320 50  0001 C CNN
F 4 "0603" H 1660 7320 50  0000 R CNN "display_footprint"
F 5 "25V" H 1660 7220 50  0000 R CNN "Voltage"
F 6 "X7R" H 1660 7120 50  0000 R CNN "Dielectric"
F 7 "PN" H 2235 7720 60  0001 C CNN "Digi-Key PN"
	1    1810 7220
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C317
P 2110 7220
AR Path="/5BAAE16C/5BB4C317" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C317" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C317" Ref="C?"  Part="1" 
F 0 "C?" H 2135 7320 50  0000 L CNN
F 1 "10nF" H 2135 7120 50  0000 L CNN
F 2 "" H 2148 7070 50  0001 C CNN
F 3 "" H 2135 7320 50  0001 C CNN
F 4 "0603" H 1960 7320 50  0001 R CNN "display_footprint"
F 5 "25V" H 1960 7220 50  0001 R CNN "Voltage"
F 6 "X7R" H 1960 7120 50  0001 R CNN "Dielectric"
F 7 "PN" H 2535 7720 60  0001 C CNN "Digi-Key PN"
	1    2110 7220
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C322
P 2410 7220
AR Path="/5BAAE16C/5BB4C322" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C322" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C322" Ref="C?"  Part="1" 
F 0 "C?" H 2435 7320 50  0000 L CNN
F 1 "1nF" H 2435 7120 50  0000 L CNN
F 2 "" H 2448 7070 50  0001 C CNN
F 3 "" H 2435 7320 50  0001 C CNN
F 4 "0603" H 2260 7320 50  0001 R CNN "display_footprint"
F 5 "25V" H 2260 7220 50  0001 R CNN "Voltage"
F 6 "X7R" H 2260 7120 50  0001 R CNN "Dielectric"
F 7 "PN" H 2835 7720 60  0001 C CNN "Digi-Key PN"
	1    2410 7220
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BB4C329
P 2110 7450
AR Path="/5BAAE16C/5BB4C329" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BB4C329" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595B/5BB4C329" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2110 7200 50  0001 C CNN
F 1 "GND" H 2110 7300 50  0000 C CNN
F 2 "" H 2110 7450 50  0001 C CNN
F 3 "" H 2110 7450 50  0001 C CNN
	1    2110 7450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2110 7450 2110 7410
Wire Wire Line
	2110 7410 1810 7410
Wire Wire Line
	1810 7410 1810 7370
Connection ~ 2110 7410
Wire Wire Line
	2110 7410 2110 7370
Wire Wire Line
	2110 7410 2410 7410
Wire Wire Line
	2410 7410 2410 7370
$Comp
L power:+3.3V #PWR?
U 1 1 5BB4C336
P 2110 6990
AR Path="/5BAAE16C/5BB4C336" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BB4C336" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595B/5BB4C336" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2110 6840 50  0001 C CNN
F 1 "+3.3V" H 2110 7130 50  0000 C CNN
F 2 "" H 2110 6990 50  0001 C CNN
F 3 "" H 2110 6990 50  0001 C CNN
	1    2110 6990
	1    0    0    -1  
$EndComp
Wire Wire Line
	2110 6990 2110 7030
Wire Wire Line
	1810 7070 1810 7030
Wire Wire Line
	1810 7030 2110 7030
Wire Wire Line
	2410 7030 2410 7070
Connection ~ 2110 7030
Wire Wire Line
	2110 7030 2110 7070
Wire Wire Line
	2110 7030 2410 7030
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C347
P 3210 7220
AR Path="/5BAAE16C/5BB4C347" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C347" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C347" Ref="C?"  Part="1" 
F 0 "C?" H 3235 7320 50  0000 L CNN
F 1 "0.1uF" H 3235 7120 50  0000 L CNN
F 2 "" H 3248 7070 50  0001 C CNN
F 3 "" H 3235 7320 50  0001 C CNN
F 4 "0603" H 3060 7320 50  0000 R CNN "display_footprint"
F 5 "25V" H 3060 7220 50  0000 R CNN "Voltage"
F 6 "X7R" H 3060 7120 50  0000 R CNN "Dielectric"
F 7 "PN" H 3635 7720 60  0001 C CNN "Digi-Key PN"
	1    3210 7220
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C352
P 3510 7220
AR Path="/5BAAE16C/5BB4C352" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C352" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C352" Ref="C?"  Part="1" 
F 0 "C?" H 3535 7320 50  0000 L CNN
F 1 "10nF" H 3535 7120 50  0000 L CNN
F 2 "" H 3548 7070 50  0001 C CNN
F 3 "" H 3535 7320 50  0001 C CNN
F 4 "0603" H 3360 7320 50  0001 R CNN "display_footprint"
F 5 "25V" H 3360 7220 50  0001 R CNN "Voltage"
F 6 "X7R" H 3360 7120 50  0001 R CNN "Dielectric"
F 7 "PN" H 3935 7720 60  0001 C CNN "Digi-Key PN"
	1    3510 7220
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C35D
P 3810 7220
AR Path="/5BAAE16C/5BB4C35D" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C35D" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C35D" Ref="C?"  Part="1" 
F 0 "C?" H 3835 7320 50  0000 L CNN
F 1 "1nF" H 3835 7120 50  0000 L CNN
F 2 "" H 3848 7070 50  0001 C CNN
F 3 "" H 3835 7320 50  0001 C CNN
F 4 "0603" H 3660 7320 50  0001 R CNN "display_footprint"
F 5 "25V" H 3660 7220 50  0001 R CNN "Voltage"
F 6 "X7R" H 3660 7120 50  0001 R CNN "Dielectric"
F 7 "PN" H 4235 7720 60  0001 C CNN "Digi-Key PN"
	1    3810 7220
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BB4C364
P 3510 7450
AR Path="/5BAAE16C/5BB4C364" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BB4C364" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595B/5BB4C364" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3510 7200 50  0001 C CNN
F 1 "GND" H 3510 7300 50  0000 C CNN
F 2 "" H 3510 7450 50  0001 C CNN
F 3 "" H 3510 7450 50  0001 C CNN
	1    3510 7450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3510 7450 3510 7410
Wire Wire Line
	3510 7410 3210 7410
Wire Wire Line
	3210 7410 3210 7370
Connection ~ 3510 7410
Wire Wire Line
	3510 7410 3510 7370
Wire Wire Line
	3510 7410 3810 7410
Wire Wire Line
	3810 7410 3810 7370
$Comp
L power:+3.3V #PWR?
U 1 1 5BB4C371
P 3510 6990
AR Path="/5BAAE16C/5BB4C371" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BB4C371" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595B/5BB4C371" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3510 6840 50  0001 C CNN
F 1 "+3.3V" H 3510 7130 50  0000 C CNN
F 2 "" H 3510 6990 50  0001 C CNN
F 3 "" H 3510 6990 50  0001 C CNN
	1    3510 6990
	1    0    0    -1  
$EndComp
Wire Wire Line
	3510 6990 3510 7030
Wire Wire Line
	3210 7070 3210 7030
Wire Wire Line
	3210 7030 3510 7030
Wire Wire Line
	3810 7030 3810 7070
Connection ~ 3510 7030
Wire Wire Line
	3510 7030 3510 7070
Wire Wire Line
	3510 7030 3810 7030
$Comp
L LED_Display_Local_Library:CY7C1010DV33 U?
U 1 1 5BC1C9FA
P 5530 3900
F 0 "U?" H 6080 2650 50  0000 R CNN
F 1 "CY7C1010DV33" H 5530 3900 50  0000 C CNN
F 2 "" H 5730 4700 50  0001 C CNN
F 3 "http://www.cypress.com/file/42781/download" H 5530 3900 50  0001 C CNN
F 4 "428-1960-ND" H 5530 3900 50  0001 C CNN "Digi-Key PN"
	1    5530 3900
	1    0    0    -1  
$EndComp
$EndSCHEMATC
