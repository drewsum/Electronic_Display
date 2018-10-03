EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 15 20
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
L LED_Display_Local_Library:CY7C1011DV33 U?
U 1 1 5BB4ADC9
P 5250 3640
F 0 "U?" H 5800 2390 50  0000 R CNN
F 1 "CY7C1011DV33" H 5250 3640 50  0000 C CNN
F 2 "" H 5450 4440 50  0001 C CNN
F 3 "http://www.cypress.com/file/42816/download" H 5250 3640 50  0001 C CNN
F 4 "428-3834-1-ND" H 6000 2590 50  0001 C CNN "Digi-Key PN"
	1    5250 3640
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BB4AFFE
P 5250 5070
F 0 "#PWR?" H 5250 4820 50  0001 C CNN
F 1 "GND" H 5250 4920 50  0000 C CNN
F 2 "" H 5250 5070 50  0001 C CNN
F 3 "" H 5250 5070 50  0001 C CNN
	1    5250 5070
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 5070 5250 5030
Wire Wire Line
	5250 5030 5200 5030
Wire Wire Line
	5200 5030 5200 4990
Wire Wire Line
	5250 5030 5300 5030
Wire Wire Line
	5300 5030 5300 4990
Connection ~ 5250 5030
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5BB4B21E
P 5250 2200
F 0 "#PWR?" H 5250 2050 50  0001 C CNN
F 1 "+3.3V" H 5250 2340 50  0000 C CNN
F 2 "" H 5250 2200 50  0000 C CNN
F 3 "" H 5250 2200 50  0000 C CNN
	1    5250 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2200 5250 2250
Wire Wire Line
	5250 2250 5300 2250
Wire Wire Line
	5300 2250 5300 2290
Wire Wire Line
	5250 2250 5200 2250
Wire Wire Line
	5200 2250 5200 2290
Connection ~ 5250 2250
Text GLabel 6000 2540 2    50   BiDi ~ 0
EBI_IO0
Text GLabel 6000 2640 2    50   BiDi ~ 0
EBI_IO1
Text GLabel 6000 2740 2    50   BiDi ~ 0
EBI_IO2
Text GLabel 6000 2840 2    50   BiDi ~ 0
EBI_IO3
Text GLabel 6000 2940 2    50   BiDi ~ 0
EBI_IO4
Text GLabel 6000 3040 2    50   BiDi ~ 0
EBI_IO5
Text GLabel 6000 3140 2    50   BiDi ~ 0
EBI_IO6
Text GLabel 6000 3240 2    50   BiDi ~ 0
EBI_IO7
Text GLabel 6000 3340 2    50   BiDi ~ 0
EBI_IO8
Text GLabel 6000 3440 2    50   BiDi ~ 0
EBI_IO9
Text GLabel 6000 3540 2    50   BiDi ~ 0
EBI_IO10
Text GLabel 6000 3640 2    50   BiDi ~ 0
EBI_IO11
Text GLabel 6000 3740 2    50   BiDi ~ 0
EBI_IO12
Text GLabel 6000 3840 2    50   BiDi ~ 0
EBI_IO13
Text GLabel 6000 3940 2    50   BiDi ~ 0
EBI_IO14
Text GLabel 6000 4040 2    50   BiDi ~ 0
EBI_IO15
Text GLabel 4500 2540 0    50   Input ~ 0
EBI_A0
Text GLabel 4500 2640 0    50   Input ~ 0
EBI_A1
Text GLabel 4500 2740 0    50   Input ~ 0
EBI_A2
Text GLabel 4500 2840 0    50   Input ~ 0
EBI_A3
Text GLabel 4500 2940 0    50   Input ~ 0
EBI_A4
Text GLabel 4500 3040 0    50   Input ~ 0
EBI_A5
Text GLabel 4500 3140 0    50   Input ~ 0
EBI_A6
Text GLabel 4500 3240 0    50   Input ~ 0
EBI_A7
Text GLabel 4500 3340 0    50   Input ~ 0
EBI_A8
Text GLabel 4500 3440 0    50   Input ~ 0
EBI_A9
Text GLabel 4500 3540 0    50   Input ~ 0
EBI_A10
Text GLabel 4500 3640 0    50   Input ~ 0
EBI_A11
Text GLabel 4500 3740 0    50   Input ~ 0
EBI_A12
Text GLabel 4500 3840 0    50   Input ~ 0
EBI_A13
Text GLabel 4500 3940 0    50   Input ~ 0
EBI_A14
Text GLabel 4500 4040 0    50   Input ~ 0
EBI_A15
Text GLabel 4500 4140 0    50   Input ~ 0
EBI_A16
Text GLabel 4500 4440 0    40   Input ~ 0
~EBI_BHE
Text GLabel 4500 4540 0    40   Input ~ 0
~EBI_BLE
Text GLabel 4500 4740 0    40   Input ~ 0
~EBI_CE
Text GLabel 6000 4440 2    40   Input ~ 0
~EBI_WE
Text GLabel 6000 4540 2    40   Input ~ 0
~EBI_OE
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C30C
P 4260 5710
AR Path="/5BAAE16C/5BB4C30C" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C30C" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C30C" Ref="C?"  Part="1" 
F 0 "C?" H 4285 5810 50  0000 L CNN
F 1 "0.1uF" H 4285 5610 50  0000 L CNN
F 2 "" H 4298 5560 50  0001 C CNN
F 3 "" H 4285 5810 50  0001 C CNN
F 4 "0603" H 4110 5810 50  0000 R CNN "display_footprint"
F 5 "25V" H 4110 5710 50  0000 R CNN "Voltage"
F 6 "X7R" H 4110 5610 50  0000 R CNN "Dielectric"
F 7 "PN" H 4685 6210 60  0001 C CNN "Digi-Key PN"
	1    4260 5710
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C317
P 4560 5710
AR Path="/5BAAE16C/5BB4C317" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C317" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C317" Ref="C?"  Part="1" 
F 0 "C?" H 4585 5810 50  0000 L CNN
F 1 "10nF" H 4585 5610 50  0000 L CNN
F 2 "" H 4598 5560 50  0001 C CNN
F 3 "" H 4585 5810 50  0001 C CNN
F 4 "0603" H 4410 5810 50  0001 R CNN "display_footprint"
F 5 "25V" H 4410 5710 50  0001 R CNN "Voltage"
F 6 "X7R" H 4410 5610 50  0001 R CNN "Dielectric"
F 7 "PN" H 4985 6210 60  0001 C CNN "Digi-Key PN"
	1    4560 5710
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C322
P 4860 5710
AR Path="/5BAAE16C/5BB4C322" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C322" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C322" Ref="C?"  Part="1" 
F 0 "C?" H 4885 5810 50  0000 L CNN
F 1 "1nF" H 4885 5610 50  0000 L CNN
F 2 "" H 4898 5560 50  0001 C CNN
F 3 "" H 4885 5810 50  0001 C CNN
F 4 "0603" H 4710 5810 50  0001 R CNN "display_footprint"
F 5 "25V" H 4710 5710 50  0001 R CNN "Voltage"
F 6 "X7R" H 4710 5610 50  0001 R CNN "Dielectric"
F 7 "PN" H 5285 6210 60  0001 C CNN "Digi-Key PN"
	1    4860 5710
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BB4C329
P 4560 5940
AR Path="/5BAAE16C/5BB4C329" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BB4C329" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595B/5BB4C329" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4560 5690 50  0001 C CNN
F 1 "GND" H 4560 5790 50  0000 C CNN
F 2 "" H 4560 5940 50  0001 C CNN
F 3 "" H 4560 5940 50  0001 C CNN
	1    4560 5940
	1    0    0    -1  
$EndComp
Wire Wire Line
	4560 5940 4560 5900
Wire Wire Line
	4560 5900 4260 5900
Wire Wire Line
	4260 5900 4260 5860
Connection ~ 4560 5900
Wire Wire Line
	4560 5900 4560 5860
Wire Wire Line
	4560 5900 4860 5900
Wire Wire Line
	4860 5900 4860 5860
$Comp
L power:+3.3V #PWR?
U 1 1 5BB4C336
P 4560 5480
AR Path="/5BAAE16C/5BB4C336" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BB4C336" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595B/5BB4C336" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4560 5330 50  0001 C CNN
F 1 "+3.3V" H 4560 5620 50  0000 C CNN
F 2 "" H 4560 5480 50  0001 C CNN
F 3 "" H 4560 5480 50  0001 C CNN
	1    4560 5480
	1    0    0    -1  
$EndComp
Wire Wire Line
	4560 5480 4560 5520
Wire Wire Line
	4260 5560 4260 5520
Wire Wire Line
	4260 5520 4560 5520
Wire Wire Line
	4860 5520 4860 5560
Connection ~ 4560 5520
Wire Wire Line
	4560 5520 4560 5560
Wire Wire Line
	4560 5520 4860 5520
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C347
P 5660 5710
AR Path="/5BAAE16C/5BB4C347" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C347" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C347" Ref="C?"  Part="1" 
F 0 "C?" H 5685 5810 50  0000 L CNN
F 1 "0.1uF" H 5685 5610 50  0000 L CNN
F 2 "" H 5698 5560 50  0001 C CNN
F 3 "" H 5685 5810 50  0001 C CNN
F 4 "0603" H 5510 5810 50  0000 R CNN "display_footprint"
F 5 "25V" H 5510 5710 50  0000 R CNN "Voltage"
F 6 "X7R" H 5510 5610 50  0000 R CNN "Dielectric"
F 7 "PN" H 6085 6210 60  0001 C CNN "Digi-Key PN"
	1    5660 5710
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C352
P 5960 5710
AR Path="/5BAAE16C/5BB4C352" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C352" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C352" Ref="C?"  Part="1" 
F 0 "C?" H 5985 5810 50  0000 L CNN
F 1 "10nF" H 5985 5610 50  0000 L CNN
F 2 "" H 5998 5560 50  0001 C CNN
F 3 "" H 5985 5810 50  0001 C CNN
F 4 "0603" H 5810 5810 50  0001 R CNN "display_footprint"
F 5 "25V" H 5810 5710 50  0001 R CNN "Voltage"
F 6 "X7R" H 5810 5610 50  0001 R CNN "Dielectric"
F 7 "PN" H 6385 6210 60  0001 C CNN "Digi-Key PN"
	1    5960 5710
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BB4C35D
P 6260 5710
AR Path="/5BAAE16C/5BB4C35D" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BB4C35D" Ref="C?"  Part="1" 
AR Path="/5BB2595B/5BB4C35D" Ref="C?"  Part="1" 
F 0 "C?" H 6285 5810 50  0000 L CNN
F 1 "1nF" H 6285 5610 50  0000 L CNN
F 2 "" H 6298 5560 50  0001 C CNN
F 3 "" H 6285 5810 50  0001 C CNN
F 4 "0603" H 6110 5810 50  0001 R CNN "display_footprint"
F 5 "25V" H 6110 5710 50  0001 R CNN "Voltage"
F 6 "X7R" H 6110 5610 50  0001 R CNN "Dielectric"
F 7 "PN" H 6685 6210 60  0001 C CNN "Digi-Key PN"
	1    6260 5710
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BB4C364
P 5960 5940
AR Path="/5BAAE16C/5BB4C364" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BB4C364" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595B/5BB4C364" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5960 5690 50  0001 C CNN
F 1 "GND" H 5960 5790 50  0000 C CNN
F 2 "" H 5960 5940 50  0001 C CNN
F 3 "" H 5960 5940 50  0001 C CNN
	1    5960 5940
	1    0    0    -1  
$EndComp
Wire Wire Line
	5960 5940 5960 5900
Wire Wire Line
	5960 5900 5660 5900
Wire Wire Line
	5660 5900 5660 5860
Connection ~ 5960 5900
Wire Wire Line
	5960 5900 5960 5860
Wire Wire Line
	5960 5900 6260 5900
Wire Wire Line
	6260 5900 6260 5860
$Comp
L power:+3.3V #PWR?
U 1 1 5BB4C371
P 5960 5480
AR Path="/5BAAE16C/5BB4C371" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BB4C371" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595B/5BB4C371" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5960 5330 50  0001 C CNN
F 1 "+3.3V" H 5960 5620 50  0000 C CNN
F 2 "" H 5960 5480 50  0001 C CNN
F 3 "" H 5960 5480 50  0001 C CNN
	1    5960 5480
	1    0    0    -1  
$EndComp
Wire Wire Line
	5960 5480 5960 5520
Wire Wire Line
	5660 5560 5660 5520
Wire Wire Line
	5660 5520 5960 5520
Wire Wire Line
	6260 5520 6260 5560
Connection ~ 5960 5520
Wire Wire Line
	5960 5520 5960 5560
Wire Wire Line
	5960 5520 6260 5520
$EndSCHEMATC
