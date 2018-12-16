EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 32 32
Title "Electronic Display Logic Board"
Date "2018-12-15"
Rev "A"
Comp "Marquette University Senior Design 2018/2019 Group E44"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LED_Display_Local_Library:MU_Logo #G3201
U 1 1 5C1B3F68
P 9900 1100
F 0 "#G3201" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
Text Notes 550  700  0    100  ~ 20
32. Additional Capacitance
$Comp
L LED_Display_Local_Library:CP_Tant_Custom C?
U 1 1 5C1BF699
P 1600 4840
AR Path="/5BB181D8/5C1BF699" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C1BF699" Ref="C3202"  Part="1" 
F 0 "C3202" H 1625 4940 50  0000 L CNN
F 1 "100uF" H 1625 4740 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Reflow" H 1638 4690 50  0001 C CNN
F 3 "" H 1625 4940 50  0001 C CNN
F 4 "478-3130-1-ND" H 1600 4840 50  0001 C CNN "Digi-Key PN"
F 5 "3528" H 1450 4940 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 1450 4840 50  0000 R CNN "Voltage"
F 7 "20%" H 1450 4740 50  0000 R CNN "Tolerance"
	1    1600 4840
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1BF6A6
P 1600 4990
AR Path="/5BB181D8/5C1BF6A6" Ref="#PWR?"  Part="1" 
AR Path="/5C1AA7A5/5C1BF6A6" Ref="#PWR03204"  Part="1" 
F 0 "#PWR03204" H 1600 4740 50  0001 C CNN
F 1 "GND" H 1600 4840 50  0000 C CNN
F 2 "" H 1600 4990 50  0001 C CNN
F 3 "" H 1600 4990 50  0001 C CNN
	1    1600 4990
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03203
U 1 1 5C1BF6D8
P 1600 4690
F 0 "#PWR03203" H 1600 4540 50  0001 C CNN
F 1 "+5V" H 1600 4830 50  0000 C CNN
F 2 "" H 1600 4690 50  0001 C CNN
F 3 "" H 1600 4690 50  0001 C CNN
	1    1600 4690
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:CP_Tant_Custom C?
U 1 1 5C1BF71E
P 2440 4840
AR Path="/5BB181D8/5C1BF71E" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C1BF71E" Ref="C3203"  Part="1" 
F 0 "C3203" H 2465 4940 50  0000 L CNN
F 1 "100uF" H 2465 4740 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Reflow" H 2478 4690 50  0001 C CNN
F 3 "" H 2465 4940 50  0001 C CNN
F 4 "478-3130-1-ND" H 2440 4840 50  0001 C CNN "Digi-Key PN"
F 5 "3528" H 2290 4940 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 2290 4840 50  0000 R CNN "Voltage"
F 7 "20%" H 2290 4740 50  0000 R CNN "Tolerance"
	1    2440 4840
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1BF725
P 2440 4990
AR Path="/5BB181D8/5C1BF725" Ref="#PWR?"  Part="1" 
AR Path="/5C1AA7A5/5C1BF725" Ref="#PWR03206"  Part="1" 
F 0 "#PWR03206" H 2440 4740 50  0001 C CNN
F 1 "GND" H 2440 4840 50  0000 C CNN
F 2 "" H 2440 4990 50  0001 C CNN
F 3 "" H 2440 4990 50  0001 C CNN
	1    2440 4990
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03205
U 1 1 5C1BF72B
P 2440 4690
F 0 "#PWR03205" H 2440 4540 50  0001 C CNN
F 1 "+5V" H 2440 4830 50  0000 C CNN
F 2 "" H 2440 4690 50  0001 C CNN
F 3 "" H 2440 4690 50  0001 C CNN
	1    2440 4690
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:CP_Tant_Custom C?
U 1 1 5C1C4382
P 1600 1960
AR Path="/5BB181D8/5C1C4382" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C1C4382" Ref="C3201"  Part="1" 
F 0 "C3201" H 1625 2060 50  0000 L CNN
F 1 "100uF" H 1625 1860 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Reflow" H 1638 1810 50  0001 C CNN
F 3 "" H 1625 2060 50  0001 C CNN
F 4 "478-3130-1-ND" H 1600 1960 50  0001 C CNN "Digi-Key PN"
F 5 "3528" H 1450 2060 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 1450 1960 50  0000 R CNN "Voltage"
F 7 "20%" H 1450 1860 50  0000 R CNN "Tolerance"
	1    1600 1960
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1C4389
P 1600 2110
AR Path="/5BB181D8/5C1C4389" Ref="#PWR?"  Part="1" 
AR Path="/5C1AA7A5/5C1C4389" Ref="#PWR03202"  Part="1" 
F 0 "#PWR03202" H 1600 1860 50  0001 C CNN
F 1 "GND" H 1600 1960 50  0000 C CNN
F 2 "" H 1600 2110 50  0001 C CNN
F 3 "" H 1600 2110 50  0001 C CNN
	1    1600 2110
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR03201
U 1 1 5C1C43D7
P 1600 1810
F 0 "#PWR03201" H 1600 1660 50  0001 C CNN
F 1 "+3.3V" H 1600 1950 50  0000 C CNN
F 2 "" H 1600 1810 50  0001 C CNN
F 3 "" H 1600 1810 50  0001 C CNN
	1    1600 1810
	1    0    0    -1  
$EndComp
$EndSCHEMATC