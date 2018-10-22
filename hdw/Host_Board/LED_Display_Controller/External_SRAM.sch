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
Text GLabel 6280 2800 2    50   BiDi ~ 0
EBI_IO0
Text GLabel 6280 2900 2    50   BiDi ~ 0
EBI_IO1
Text GLabel 6280 3000 2    50   BiDi ~ 0
EBI_IO2
Text GLabel 6280 3100 2    50   BiDi ~ 0
EBI_IO3
Text GLabel 6280 3200 2    50   BiDi ~ 0
EBI_IO4
Text GLabel 6280 3300 2    50   BiDi ~ 0
EBI_IO5
Text GLabel 6280 3400 2    50   BiDi ~ 0
EBI_IO6
Text GLabel 6280 3500 2    50   BiDi ~ 0
EBI_IO7
Text GLabel 4780 2800 0    50   Input ~ 0
EBI_A0
Text GLabel 4780 2900 0    50   Input ~ 0
EBI_A1
Text GLabel 4780 3000 0    50   Input ~ 0
EBI_A2
Text GLabel 4780 3100 0    50   Input ~ 0
EBI_A3
Text GLabel 4780 3200 0    50   Input ~ 0
EBI_A4
Text GLabel 4780 3300 0    50   Input ~ 0
EBI_A5
Text GLabel 4780 3400 0    50   Input ~ 0
EBI_A6
Text GLabel 4780 3500 0    50   Input ~ 0
EBI_A7
Text GLabel 4780 3600 0    50   Input ~ 0
EBI_A8
Text GLabel 4780 3700 0    50   Input ~ 0
EBI_A9
Text GLabel 4780 3800 0    50   Input ~ 0
EBI_A10
Text GLabel 4780 3900 0    50   Input ~ 0
EBI_A11
Text GLabel 4780 4000 0    50   Input ~ 0
EBI_A12
Text GLabel 4780 4100 0    50   Input ~ 0
EBI_A13
Text GLabel 4780 4200 0    50   Input ~ 0
EBI_A14
Text GLabel 4780 4300 0    50   Input ~ 0
EBI_A15
Text GLabel 4780 4400 0    50   Input ~ 0
EBI_A16
Text GLabel 4780 5000 0    40   Input ~ 0
~EBI_CE
Text GLabel 6280 4900 2    40   Input ~ 0
~EBI_WE
Text GLabel 6280 5000 2    40   Input ~ 0
~EBI_OE
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C30C
P 4570 6070
AR Path="/5BAAE16C/5BB4C30C" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C30C" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C30C" Ref="C?"  Part="1" 
F 0 "C?" H 4595 6170 50  0000 L CNN
F 1 "0.1uF" H 4595 5970 50  0000 L CNN
F 2 "" H 4608 5920 50  0001 C CNN
F 3 "" H 4595 6170 50  0001 C CNN
F 4 "0603" H 4420 6170 50  0000 R CNN "display_footprint"
F 5 "25V" H 4420 6070 50  0000 R CNN "Voltage"
F 6 "X7R" H 4420 5970 50  0000 R CNN "Dielectric"
F 7 "PN" H 4995 6570 60  0001 C CNN "Digi-Key PN"
	1    4570 6070
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C317
P 4870 6070
AR Path="/5BAAE16C/5BB4C317" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C317" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C317" Ref="C?"  Part="1" 
F 0 "C?" H 4895 6170 50  0000 L CNN
F 1 "10nF" H 4895 5970 50  0000 L CNN
F 2 "" H 4908 5920 50  0001 C CNN
F 3 "" H 4895 6170 50  0001 C CNN
F 4 "0603" H 4720 6170 50  0001 R CNN "display_footprint"
F 5 "25V" H 4720 6070 50  0001 R CNN "Voltage"
F 6 "X7R" H 4720 5970 50  0001 R CNN "Dielectric"
F 7 "PN" H 5295 6570 60  0001 C CNN "Digi-Key PN"
	1    4870 6070
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C322
P 5170 6070
AR Path="/5BAAE16C/5BB4C322" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C322" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C322" Ref="C?"  Part="1" 
F 0 "C?" H 5195 6170 50  0000 L CNN
F 1 "1nF" H 5195 5970 50  0000 L CNN
F 2 "" H 5208 5920 50  0001 C CNN
F 3 "" H 5195 6170 50  0001 C CNN
F 4 "0603" H 5020 6170 50  0001 R CNN "display_footprint"
F 5 "25V" H 5020 6070 50  0001 R CNN "Voltage"
F 6 "X7R" H 5020 5970 50  0001 R CNN "Dielectric"
F 7 "PN" H 5595 6570 60  0001 C CNN "Digi-Key PN"
	1    5170 6070
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BB4C329
P 4870 6300
AR Path="/5BAAE16C/5BB4C329" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BB4C329" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595B/5BB4C329" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4870 6050 50  0001 C CNN
F 1 "GND" H 4870 6150 50  0000 C CNN
F 2 "" H 4870 6300 50  0001 C CNN
F 3 "" H 4870 6300 50  0001 C CNN
	1    4870 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4870 6300 4870 6260
Wire Wire Line
	4870 6260 4570 6260
Wire Wire Line
	4570 6260 4570 6220
Connection ~ 4870 6260
Wire Wire Line
	4870 6260 4870 6220
Wire Wire Line
	4870 6260 5170 6260
Wire Wire Line
	5170 6260 5170 6220
$Comp
L power:+3.3V #PWR?
U 1 1 5BB4C336
P 4870 5840
AR Path="/5BAAE16C/5BB4C336" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BB4C336" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595B/5BB4C336" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4870 5690 50  0001 C CNN
F 1 "+3.3V" H 4870 5980 50  0000 C CNN
F 2 "" H 4870 5840 50  0001 C CNN
F 3 "" H 4870 5840 50  0001 C CNN
	1    4870 5840
	1    0    0    -1  
$EndComp
Wire Wire Line
	4870 5840 4870 5880
Wire Wire Line
	4570 5920 4570 5880
Wire Wire Line
	4570 5880 4870 5880
Wire Wire Line
	5170 5880 5170 5920
Connection ~ 4870 5880
Wire Wire Line
	4870 5880 4870 5920
Wire Wire Line
	4870 5880 5170 5880
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C347
P 5970 6070
AR Path="/5BAAE16C/5BB4C347" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C347" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C347" Ref="C?"  Part="1" 
F 0 "C?" H 5995 6170 50  0000 L CNN
F 1 "0.1uF" H 5995 5970 50  0000 L CNN
F 2 "" H 6008 5920 50  0001 C CNN
F 3 "" H 5995 6170 50  0001 C CNN
F 4 "0603" H 5820 6170 50  0000 R CNN "display_footprint"
F 5 "25V" H 5820 6070 50  0000 R CNN "Voltage"
F 6 "X7R" H 5820 5970 50  0000 R CNN "Dielectric"
F 7 "PN" H 6395 6570 60  0001 C CNN "Digi-Key PN"
	1    5970 6070
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C352
P 6270 6070
AR Path="/5BAAE16C/5BB4C352" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C352" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C352" Ref="C?"  Part="1" 
F 0 "C?" H 6295 6170 50  0000 L CNN
F 1 "10nF" H 6295 5970 50  0000 L CNN
F 2 "" H 6308 5920 50  0001 C CNN
F 3 "" H 6295 6170 50  0001 C CNN
F 4 "0603" H 6120 6170 50  0001 R CNN "display_footprint"
F 5 "25V" H 6120 6070 50  0001 R CNN "Voltage"
F 6 "X7R" H 6120 5970 50  0001 R CNN "Dielectric"
F 7 "PN" H 6695 6570 60  0001 C CNN "Digi-Key PN"
	1    6270 6070
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C35D
P 6570 6070
AR Path="/5BAAE16C/5BB4C35D" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C35D" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C35D" Ref="C?"  Part="1" 
F 0 "C?" H 6595 6170 50  0000 L CNN
F 1 "1nF" H 6595 5970 50  0000 L CNN
F 2 "" H 6608 5920 50  0001 C CNN
F 3 "" H 6595 6170 50  0001 C CNN
F 4 "0603" H 6420 6170 50  0001 R CNN "display_footprint"
F 5 "25V" H 6420 6070 50  0001 R CNN "Voltage"
F 6 "X7R" H 6420 5970 50  0001 R CNN "Dielectric"
F 7 "PN" H 6995 6570 60  0001 C CNN "Digi-Key PN"
	1    6570 6070
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BB4C364
P 6270 6300
AR Path="/5BAAE16C/5BB4C364" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BB4C364" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595B/5BB4C364" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6270 6050 50  0001 C CNN
F 1 "GND" H 6270 6150 50  0000 C CNN
F 2 "" H 6270 6300 50  0001 C CNN
F 3 "" H 6270 6300 50  0001 C CNN
	1    6270 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6270 6300 6270 6260
Wire Wire Line
	6270 6260 5970 6260
Wire Wire Line
	5970 6260 5970 6220
Connection ~ 6270 6260
Wire Wire Line
	6270 6260 6270 6220
Wire Wire Line
	6270 6260 6570 6260
Wire Wire Line
	6570 6260 6570 6220
$Comp
L power:+3.3V #PWR?
U 1 1 5BB4C371
P 6270 5840
AR Path="/5BAAE16C/5BB4C371" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BB4C371" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595B/5BB4C371" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6270 5690 50  0001 C CNN
F 1 "+3.3V" H 6270 5980 50  0000 C CNN
F 2 "" H 6270 5840 50  0001 C CNN
F 3 "" H 6270 5840 50  0001 C CNN
	1    6270 5840
	1    0    0    -1  
$EndComp
Wire Wire Line
	6270 5840 6270 5880
Wire Wire Line
	5970 5920 5970 5880
Wire Wire Line
	5970 5880 6270 5880
Wire Wire Line
	6570 5880 6570 5920
Connection ~ 6270 5880
Wire Wire Line
	6270 5880 6270 5920
Wire Wire Line
	6270 5880 6570 5880
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
Text GLabel 4780 4500 0    50   Input ~ 0
EBI_A17
Text Notes 2060 5440 0    50   ~ 0
Consider strapping ~CS~ high since we only have one device on the EBI bus\nThis may or may not work, need to look deeper into EBI reference manual\nIf pins are available, leave this pin connected to the micro, not strapped
$EndSCHEMATC
