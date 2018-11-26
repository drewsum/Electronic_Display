EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 5 31
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
L Connector_Generic:Conn_01x06 J?
U 1 1 5BB4A695
P 1070 1990
F 0 "J?" H 1070 2290 50  0000 C CNN
F 1 "PROG" H 1070 1590 50  0000 C CNN
F 2 "" H 1070 1990 50  0001 C CNN
F 3 "~" H 1070 1990 50  0001 C CNN
	1    1070 1990
	-1   0    0    -1  
$EndComp
Text GLabel 1270 1790 2    50   UnSpc ~ 0
~MCLR
Text GLabel 1270 2090 2    50   BiDi ~ 0
ICSPDAT
Text GLabel 1270 2190 2    50   Output ~ 0
ICSPCLK
$Comp
L power:GND #PWR0130
U 1 1 5BB4A7C4
P 1790 2040
F 0 "#PWR0130" H 1790 1790 50  0001 C CNN
F 1 "GND" H 1790 1890 50  0000 C CNN
F 2 "" H 1790 2040 50  0001 C CNN
F 3 "" H 1790 2040 50  0001 C CNN
	1    1790 2040
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1790 1820 1790 1890
Wire Wire Line
	1790 1890 1270 1890
Wire Wire Line
	1790 2040 1790 1990
Wire Wire Line
	1790 1990 1270 1990
NoConn ~ 1270 2290
$Comp
L power:+3.3V #PWR0131
U 1 1 5BBE4D2A
P 1790 1820
F 0 "#PWR0131" H 1790 1670 50  0001 C CNN
F 1 "+3.3V" H 1790 1960 50  0000 C CNN
F 2 "" H 1790 1820 50  0001 C CNN
F 3 "" H 1790 1820 50  0001 C CNN
	1    1790 1820
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BC13497
P 2460 2030
F 0 "C?" H 2485 2130 50  0000 L CNN
F 1 "0.1uF" H 2485 1930 50  0000 L CNN
F 2 "" H 2498 1880 50  0001 C CNN
F 3 "" H 2485 2130 50  0001 C CNN
F 4 "0603" H 2310 2130 50  0000 R CNN "display_footprint"
F 5 "50V" H 2310 2030 50  0000 R CNN "Voltage"
F 6 "X7R" H 2310 1930 50  0000 R CNN "Dielectric"
F 7 "PN" H 2885 2530 60  0001 C CNN "Digi-Key PN"
	1    2460 2030
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0132
U 1 1 5BC1349E
P 2460 2180
F 0 "#PWR0132" H 2460 1930 50  0001 C CNN
F 1 "GND" H 2460 2030 50  0000 C CNN
F 2 "" H 2460 2180 50  0001 C CNN
F 3 "" H 2460 2180 50  0001 C CNN
	1    2460 2180
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0133
U 1 1 5BC134A4
P 2460 1880
F 0 "#PWR0133" H 2460 1730 50  0001 C CNN
F 1 "+3.3V" H 2460 2020 50  0000 C CNN
F 2 "" H 2460 1880 50  0001 C CNN
F 3 "" H 2460 1880 50  0001 C CNN
	1    2460 1880
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BC152E5
P 7550 2020
AR Path="/5BAAE1F3/5BC152E5" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5BC152E5" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5BC152E5" Ref="R?"  Part="1" 
F 0 "R?" H 7450 2020 50  0000 C CNN
F 1 "10k" V 7550 2020 50  0000 C CNN
F 2 "" H 7550 2020 50  0001 C CNN
F 3 "" H 7550 2020 50  0001 C CNN
F 4 "0603" H 7740 2100 50  0000 C CNN "display_footprint"
F 5 "1%" H 7730 2020 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 7760 1950 50  0000 C CNN "Wattage"
F 7 "PN" H 7850 2420 60  0001 C CNN "Digi-Key PN"
	1    7550 2020
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BC1574E
P 7550 2830
F 0 "C?" H 7575 2930 50  0000 L CNN
F 1 "0.1uF" H 7575 2730 50  0000 L CNN
F 2 "" H 7588 2680 50  0001 C CNN
F 3 "" H 7575 2930 50  0001 C CNN
F 4 "0603" H 7400 2930 50  0000 R CNN "display_footprint"
F 5 "50V" H 7400 2830 50  0000 R CNN "Voltage"
F 6 "X7R" H 7400 2730 50  0000 R CNN "Dielectric"
F 7 "PN" H 7975 3330 60  0001 C CNN "Digi-Key PN"
	1    7550 2830
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0134
U 1 1 5BC1583F
P 7550 1870
F 0 "#PWR0134" H 7550 1720 50  0001 C CNN
F 1 "+3.3V" H 7550 2010 50  0000 C CNN
F 2 "" H 7550 1870 50  0001 C CNN
F 3 "" H 7550 1870 50  0001 C CNN
	1    7550 1870
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BC15CB4
P 7550 2490
AR Path="/5BAAE1F3/5BC15CB4" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5BC15CB4" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5BC15CB4" Ref="R?"  Part="1" 
F 0 "R?" H 7450 2490 50  0000 C CNN
F 1 "0" V 7550 2490 50  0000 C CNN
F 2 "" H 7550 2490 50  0001 C CNN
F 3 "" H 7550 2490 50  0001 C CNN
F 4 "DNP" H 7630 2650 50  0000 L CNN "Config"
F 5 "PN" H 7850 2890 60  0001 C CNN "Digi-Key PN"
F 6 "0603" H 7740 2570 50  0000 C CNN "display_footprint"
F 7 "1%" H 7730 2490 50  0000 C CNN "Tolerance"
F 8 "1/10W" H 7760 2420 50  0000 C CNN "Wattage"
	1    7550 2490
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7550 2640 7550 2680
$Comp
L power:GND #PWR0135
U 1 1 5BC15E18
P 7550 2980
F 0 "#PWR0135" H 7550 2730 50  0001 C CNN
F 1 "GND" H 7550 2830 50  0000 C CNN
F 2 "" H 7550 2980 50  0001 C CNN
F 3 "" H 7550 2980 50  0001 C CNN
	1    7550 2980
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BC16316
P 8080 2250
F 0 "R?" V 7980 2250 50  0000 C CNN
F 1 "1k" V 8080 2250 50  0000 C CNN
F 2 "" H 8080 2250 50  0001 C CNN
F 3 "" H 8080 2250 50  0001 C CNN
F 4 "0603" V 8180 2250 50  0000 C CNN "display_footprint"
F 5 "1%" V 8280 2250 50  0000 C CNN "Tolerance"
F 6 "1/10W" V 8380 2250 50  0000 C CNN "Wattage"
F 7 "PN" H 8380 2650 60  0001 C CNN "Digi-Key PN"
	1    8080 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	7550 2170 7550 2250
Wire Wire Line
	7930 2250 7550 2250
Connection ~ 7550 2250
Wire Wire Line
	7550 2250 7550 2340
Text GLabel 8230 2250 2    50   UnSpc ~ 0
~MCLR
$Comp
L Switch:SW_Push SW?
U 1 1 5BC17B44
P 5020 2770
F 0 "SW?" H 5020 3055 50  0000 C CNN
F 1 "MRST" H 5020 2964 50  0000 C CNN
F 2 "" H 5020 2970 50  0001 C CNN
F 3 "" H 5020 2970 50  0001 C CNN
	1    5020 2770
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BC190FF
P 6860 2250
F 0 "R?" V 6760 2250 50  0000 C CNN
F 1 "100" V 6860 2250 50  0000 C CNN
F 2 "" H 6860 2250 50  0001 C CNN
F 3 "" H 6860 2250 50  0001 C CNN
F 4 "0603" V 6960 2250 50  0000 C CNN "display_footprint"
F 5 "1%" V 7060 2250 50  0000 C CNN "Tolerance"
F 6 "1/10W" V 7160 2250 50  0000 C CNN "Wattage"
F 7 "PN" H 7160 2650 60  0001 C CNN "Digi-Key PN"
	1    6860 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	7010 2250 7550 2250
$Comp
L Transistor_FET:BSS214NW Q?
U 1 1 5BE087BA
P 6410 2770
AR Path="/5BAAE16C/5BE087BA" Ref="Q?"  Part="1" 
AR Path="/5BB844FD/5BE087BA" Ref="Q?"  Part="1" 
F 0 "Q?" H 6610 2845 50  0000 L CNN
F 1 "BSS214NW" H 6610 2770 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-323_SC-70" H 6610 2695 50  0001 L CIN
F 3 "https://www.infineon.com/dgdl/Infineon-BSS214NW-DS-v02_02-en.pdf?fileId=db3a30431b3e89eb011b695aebc01bde" H 6410 2770 50  0001 L CNN
	1    6410 2770
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0136
U 1 1 5BE087C1
P 6510 2970
F 0 "#PWR0136" H 6510 2720 50  0001 C CNN
F 1 "GND" H 6510 2820 50  0000 C CNN
F 2 "" H 6510 2970 50  0001 C CNN
F 3 "" H 6510 2970 50  0001 C CNN
	1    6510 2970
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE087CB
P 5470 2770
F 0 "R?" V 5370 2770 50  0000 C CNN
F 1 "10" V 5470 2770 50  0000 C CNN
F 2 "" H 5470 2770 50  0001 C CNN
F 3 "" H 5470 2770 50  0001 C CNN
F 4 "0603" V 5570 2770 50  0000 C CNN "display_footprint"
F 5 "1%" V 5670 2770 50  0000 C CNN "Tolerance"
F 6 "1/10W" V 5770 2770 50  0000 C CNN "Wattage"
F 7 "PN" H 5770 3170 60  0001 C CNN "Digi-Key PN"
	1    5470 2770
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE087D6
P 5920 3000
AR Path="/5BAAE1F3/5BE087D6" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5BE087D6" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5BE087D6" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5BE087D6" Ref="R?"  Part="1" 
F 0 "R?" H 5820 3000 50  0000 C CNN
F 1 "10k" V 5920 3000 50  0000 C CNN
F 2 "" H 5920 3000 50  0001 C CNN
F 3 "" H 5920 3000 50  0001 C CNN
F 4 "0603" H 6110 3080 50  0000 C CNN "display_footprint"
F 5 "1%" H 6100 3000 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 6130 2930 50  0000 C CNN "Wattage"
F 7 "PN" H 6220 3400 60  0001 C CNN "Digi-Key PN"
	1    5920 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0137
U 1 1 5BE087DD
P 5920 3150
F 0 "#PWR0137" H 5920 2900 50  0001 C CNN
F 1 "GND" H 5920 3000 50  0000 C CNN
F 2 "" H 5920 3150 50  0001 C CNN
F 3 "" H 5920 3150 50  0001 C CNN
	1    5920 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6210 2770 5920 2770
Wire Wire Line
	5920 2850 5920 2770
Connection ~ 5920 2770
Wire Wire Line
	5920 2770 5620 2770
Wire Wire Line
	6510 2570 6510 2250
Wire Wire Line
	6510 2250 6710 2250
Wire Wire Line
	5320 2770 5220 2770
$Comp
L power:+3.3V #PWR0138
U 1 1 5BE0F966
P 4670 2720
F 0 "#PWR0138" H 4670 2570 50  0001 C CNN
F 1 "+3.3V" H 4670 2860 50  0000 C CNN
F 2 "" H 4670 2720 50  0001 C CNN
F 3 "" H 4670 2720 50  0001 C CNN
	1    4670 2720
	1    0    0    -1  
$EndComp
Wire Wire Line
	4670 2720 4670 2770
Wire Wire Line
	4670 2770 4820 2770
Text Notes 550  700  0    100  ~ 20
05. Microcontroller Programming
$Comp
L LED_Display_Local_Library:MU_Logo #G?
U 1 1 5BFF2EC4
P 9900 1100
F 0 "#G?" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
$EndSCHEMATC
