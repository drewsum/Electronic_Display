EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 27 31
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
L LED_Display_Local_Library:MAX6816 U?
U 1 1 5BE8273F
P 2680 1920
F 0 "U?" H 2830 1620 50  0000 L CNN
F 1 "MAX6816" H 2830 2220 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-143" H 2830 2420 50  0001 L CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX6816-MAX6818.pdf" H 2830 2320 50  0001 L CNN
F 4 "MAX6816EUS+TCT-ND" H 2830 2520 50  0001 L CNN "Digi-Key PN"
	1    2680 1920
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0487
U 1 1 5BE83CBB
P 2680 2270
F 0 "#PWR0487" H 2680 2020 50  0001 C CNN
F 1 "GND" H 2680 2120 50  0000 C CNN
F 2 "" H 2680 2270 50  0001 C CNN
F 3 "" H 2680 2270 50  0001 C CNN
	1    2680 2270
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0488
U 1 1 5BE83D4B
P 2680 1570
F 0 "#PWR0488" H 2680 1420 50  0001 C CNN
F 1 "+3.3V" H 2680 1710 50  0000 C CNN
F 2 "" H 2680 1570 50  0001 C CNN
F 3 "" H 2680 1570 50  0001 C CNN
	1    2680 1570
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5BE852DD
P 2050 2200
F 0 "SW?" V 2096 2348 50  0000 L CNN
F 1 "Display Enable" V 2005 2348 50  0000 L CNN
F 2 "" H 2050 2400 50  0001 C CNN
F 3 "" H 2050 2400 50  0001 C CNN
	1    2050 2200
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0489
U 1 1 5BE8532E
P 2050 2400
F 0 "#PWR0489" H 2050 2150 50  0001 C CNN
F 1 "GND" H 2050 2250 50  0000 C CNN
F 2 "" H 2050 2400 50  0001 C CNN
F 3 "" H 2050 2400 50  0001 C CNN
	1    2050 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 2000 2050 1920
Wire Wire Line
	2050 1920 2230 1920
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE8FF45
P 3630 1640
F 0 "R?" V 3530 1640 50  0000 C CNN
F 1 "10k" V 3630 1640 50  0000 C CNN
F 2 "" H 3630 1640 50  0001 C CNN
F 3 "" H 3630 1640 50  0001 C CNN
F 4 "0603" H 3730 1730 50  0000 L CNN "display_footprint"
F 5 "1%" H 3730 1640 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3740 1560 50  0000 L CNN "Wattage"
F 7 "PN" H 3930 2040 60  0001 C CNN "Digi-Key PN"
	1    3630 1640
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0490
U 1 1 5BE8FF56
P 3630 1490
F 0 "#PWR0490" H 3630 1340 50  0001 C CNN
F 1 "+3.3V" H 3630 1630 50  0000 C CNN
F 2 "" H 3630 1490 50  0001 C CNN
F 3 "" H 3630 1490 50  0001 C CNN
	1    3630 1490
	1    0    0    -1  
$EndComp
Wire Wire Line
	3630 1790 3630 1920
Wire Wire Line
	3630 1920 3130 1920
Text GLabel 3710 1920 2    50   Output ~ 0
~Display_Enable
Wire Wire Line
	3710 1920 3630 1920
Connection ~ 3630 1920
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 5BE91568
P 1590 4240
F 0 "SW?" H 1590 4500 50  0000 C CNN
F 1 "Brightness/Enable" H 1590 3980 50  0000 C CNN
F 2 "" H 1440 4400 50  0001 C CNN
F 3 "~" H 1590 4500 50  0001 C CNN
	1    1590 4240
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2050 1920 1210 1920
Wire Wire Line
	1210 1920 1210 4140
Connection ~ 2050 1920
Wire Wire Line
	1290 4140 1210 4140
$Comp
L power:GND #PWR0491
U 1 1 5BE941A9
P 1210 4580
F 0 "#PWR0491" H 1210 4330 50  0001 C CNN
F 1 "GND" H 1210 4430 50  0000 C CNN
F 2 "" H 1210 4580 50  0001 C CNN
F 3 "" H 1210 4580 50  0001 C CNN
	1    1210 4580
	1    0    0    -1  
$EndComp
Wire Wire Line
	1210 4580 1210 4340
Wire Wire Line
	1210 4340 1290 4340
$Comp
L power:GND #PWR0492
U 1 1 5BE957A8
P 2000 4580
F 0 "#PWR0492" H 2000 4330 50  0001 C CNN
F 1 "GND" H 2000 4430 50  0000 C CNN
F 2 "" H 2000 4580 50  0001 C CNN
F 3 "" H 2000 4580 50  0001 C CNN
	1    2000 4580
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 4580 2000 4240
Wire Wire Line
	2000 4240 1890 4240
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE38B1E
P 2340 3700
F 0 "R?" V 2240 3700 50  0000 C CNN
F 1 "10k" V 2340 3700 50  0000 C CNN
F 2 "" H 2340 3700 50  0001 C CNN
F 3 "" H 2340 3700 50  0001 C CNN
F 4 "0603" H 2440 3790 50  0000 L CNN "display_footprint"
F 5 "1%" H 2440 3700 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 2450 3620 50  0000 L CNN "Wattage"
F 7 "PN" H 2640 4100 60  0001 C CNN "Digi-Key PN"
	1    2340 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0493
U 1 1 5BE38B25
P 2340 3550
F 0 "#PWR0493" H 2340 3400 50  0001 C CNN
F 1 "+3.3V" H 2340 3690 50  0000 C CNN
F 2 "" H 2340 3550 50  0001 C CNN
F 3 "" H 2340 3550 50  0001 C CNN
	1    2340 3550
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE38BE6
P 3010 3700
F 0 "R?" V 2910 3700 50  0000 C CNN
F 1 "10k" V 3010 3700 50  0000 C CNN
F 2 "" H 3010 3700 50  0001 C CNN
F 3 "" H 3010 3700 50  0001 C CNN
F 4 "0603" H 3110 3790 50  0000 L CNN "display_footprint"
F 5 "1%" H 3110 3700 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3120 3620 50  0000 L CNN "Wattage"
F 7 "PN" H 3310 4100 60  0001 C CNN "Digi-Key PN"
	1    3010 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0494
U 1 1 5BE38BED
P 3010 3550
F 0 "#PWR0494" H 3010 3400 50  0001 C CNN
F 1 "+3.3V" H 3010 3690 50  0000 C CNN
F 2 "" H 3010 3550 50  0001 C CNN
F 3 "" H 3010 3550 50  0001 C CNN
	1    3010 3550
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE3A24F
P 3470 4140
F 0 "R?" V 3370 4140 50  0000 C CNN
F 1 "1k" V 3470 4140 50  0000 C CNN
F 2 "" H 3470 4140 50  0001 C CNN
F 3 "" H 3470 4140 50  0001 C CNN
F 4 "PN" H 3770 4540 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 3570 4140 50  0001 C CNN "display_footprint"
F 6 "1%" V 3670 4140 50  0001 C CNN "Tolerance"
F 7 "1/10W" V 3770 4140 50  0001 C CNN "Wattage"
	1    3470 4140
	0    1    1    0   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE3B8C0
P 3470 4340
F 0 "R?" V 3370 4340 50  0000 C CNN
F 1 "1k" V 3470 4340 50  0000 C CNN
F 2 "" H 3470 4340 50  0001 C CNN
F 3 "" H 3470 4340 50  0001 C CNN
F 4 "PN" H 3770 4740 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 3570 4340 50  0001 C CNN "display_footprint"
F 6 "1%" V 3670 4340 50  0001 C CNN "Tolerance"
F 7 "1/10W" V 3770 4340 50  0001 C CNN "Wattage"
	1    3470 4340
	0    1    1    0   
$EndComp
Wire Wire Line
	3320 4140 2340 4140
Wire Wire Line
	1890 4340 3010 4340
Wire Wire Line
	2340 3850 2340 4140
Connection ~ 2340 4140
Wire Wire Line
	2340 4140 1890 4140
Wire Wire Line
	3010 3850 3010 4340
Connection ~ 3010 4340
Wire Wire Line
	3010 4340 3320 4340
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BE403D4
P 3430 2550
AR Path="/5BAAE16C/5BE403D4" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BE403D4" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5BE403D4" Ref="C?"  Part="1" 
AR Path="/5BE4F849/5BE403D4" Ref="C?"  Part="1" 
F 0 "C?" H 3455 2650 50  0000 L CNN
F 1 "0.1uF" H 3455 2450 50  0000 L CNN
F 2 "" H 3468 2400 50  0001 C CNN
F 3 "" H 3455 2650 50  0001 C CNN
F 4 "0603" H 3280 2650 50  0000 R CNN "display_footprint"
F 5 "25V" H 3280 2550 50  0000 R CNN "Voltage"
F 6 "X7R" H 3280 2450 50  0000 R CNN "Dielectric"
F 7 "PN" H 3855 3050 60  0001 C CNN "Digi-Key PN"
	1    3430 2550
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0495
U 1 1 5BE40522
P 3430 2400
F 0 "#PWR0495" H 3430 2250 50  0001 C CNN
F 1 "+3.3V" H 3430 2540 50  0000 C CNN
F 2 "" H 3430 2400 50  0001 C CNN
F 3 "" H 3430 2400 50  0001 C CNN
	1    3430 2400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0496
U 1 1 5BE4055A
P 3430 2700
F 0 "#PWR0496" H 3430 2450 50  0001 C CNN
F 1 "GND" H 3430 2550 50  0000 C CNN
F 2 "" H 3430 2700 50  0001 C CNN
F 3 "" H 3430 2700 50  0001 C CNN
	1    3430 2700
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BE41B5E
P 3930 4690
AR Path="/5BAAE16C/5BE41B5E" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BE41B5E" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5BE41B5E" Ref="C?"  Part="1" 
AR Path="/5BE4F849/5BE41B5E" Ref="C?"  Part="1" 
F 0 "C?" H 3955 4790 50  0000 L CNN
F 1 "0.1uF" H 3955 4590 50  0000 L CNN
F 2 "" H 3968 4540 50  0001 C CNN
F 3 "" H 3955 4790 50  0001 C CNN
F 4 "0603" H 3780 4790 50  0000 R CNN "display_footprint"
F 5 "25V" H 3780 4690 50  0000 R CNN "Voltage"
F 6 "X7R" H 3780 4590 50  0000 R CNN "Dielectric"
F 7 "PN" H 4355 5190 60  0001 C CNN "Digi-Key PN"
	1    3930 4690
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0497
U 1 1 5BE41B65
P 3930 4840
F 0 "#PWR0497" H 3930 4590 50  0001 C CNN
F 1 "GND" H 3930 4690 50  0000 C CNN
F 2 "" H 3930 4840 50  0001 C CNN
F 3 "" H 3930 4840 50  0001 C CNN
	1    3930 4840
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BE4327E
P 4640 4690
AR Path="/5BAAE16C/5BE4327E" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BE4327E" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5BE4327E" Ref="C?"  Part="1" 
AR Path="/5BE4F849/5BE4327E" Ref="C?"  Part="1" 
F 0 "C?" H 4665 4790 50  0000 L CNN
F 1 "0.1uF" H 4665 4590 50  0000 L CNN
F 2 "" H 4678 4540 50  0001 C CNN
F 3 "" H 4665 4790 50  0001 C CNN
F 4 "0603" H 4490 4790 50  0000 R CNN "display_footprint"
F 5 "25V" H 4490 4690 50  0000 R CNN "Voltage"
F 6 "X7R" H 4490 4590 50  0000 R CNN "Dielectric"
F 7 "PN" H 5065 5190 60  0001 C CNN "Digi-Key PN"
	1    4640 4690
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0498
U 1 1 5BE43285
P 4640 4840
F 0 "#PWR0498" H 4640 4590 50  0001 C CNN
F 1 "GND" H 4640 4690 50  0000 C CNN
F 2 "" H 4640 4840 50  0001 C CNN
F 3 "" H 4640 4840 50  0001 C CNN
	1    4640 4840
	1    0    0    -1  
$EndComp
Wire Wire Line
	3620 4140 4640 4140
Wire Wire Line
	4640 4140 4640 4540
Wire Wire Line
	3620 4340 3930 4340
Wire Wire Line
	3930 4340 3930 4540
$Comp
L LED_Display_Local_Library:74LVC2G14_Power U?
U 1 1 5BE49974
P 5510 3850
F 0 "U?" H 5800 3980 50  0000 L CNN
F 1 "74LVC2G14" H 5800 3730 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 5310 3900 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 5510 3850 50  0001 C CNN
F 4 "296-13011-1-ND" H 5510 3850 50  0001 C CNN "Digi-Key PN"
	1    5510 3850
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0499
U 1 1 5BE39212
P 5510 3750
F 0 "#PWR0499" H 5510 3600 50  0001 C CNN
F 1 "+3.3V" H 5510 3890 50  0000 C CNN
F 2 "" H 5510 3750 50  0001 C CNN
F 3 "" H 5510 3750 50  0001 C CNN
	1    5510 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0500
U 1 1 5BE39279
P 5510 3950
F 0 "#PWR0500" H 5510 3700 50  0001 C CNN
F 1 "GND" H 5510 3800 50  0000 C CNN
F 2 "" H 5510 3950 50  0001 C CNN
F 3 "" H 5510 3950 50  0001 C CNN
	1    5510 3950
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:74LVC2G14_Power U?
U 2 1 5BE3A97B
P 5510 4520
F 0 "U?" H 5800 4650 50  0000 L CNN
F 1 "74LVC2G14" H 5800 4400 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-363_SC-70-6" H 5310 4570 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 5510 4520 50  0001 C CNN
F 4 "296-13011-1-ND" H 5510 4520 50  0001 C CNN "Digi-Key PN"
	2    5510 4520
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0501
U 1 1 5BE3A982
P 5510 4420
F 0 "#PWR0501" H 5510 4270 50  0001 C CNN
F 1 "+3.3V" H 5510 4560 50  0000 C CNN
F 2 "" H 5510 4420 50  0001 C CNN
F 3 "" H 5510 4420 50  0001 C CNN
	1    5510 4420
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0502
U 1 1 5BE3A988
P 5510 4620
F 0 "#PWR0502" H 5510 4370 50  0001 C CNN
F 1 "GND" H 5510 4470 50  0000 C CNN
F 2 "" H 5510 4620 50  0001 C CNN
F 3 "" H 5510 4620 50  0001 C CNN
	1    5510 4620
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE40C55
P 6480 4970
F 0 "R?" V 6380 4970 50  0000 C CNN
F 1 "10k" V 6480 4970 50  0000 C CNN
F 2 "" H 6480 4970 50  0001 C CNN
F 3 "" H 6480 4970 50  0001 C CNN
F 4 "0603" H 6580 5060 50  0000 L CNN "display_footprint"
F 5 "1%" H 6580 4970 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 6590 4890 50  0000 L CNN "Wattage"
F 7 "PN" H 6780 5370 60  0001 C CNN "Digi-Key PN"
	1    6480 4970
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE40CF9
P 7350 4970
F 0 "R?" V 7250 4970 50  0000 C CNN
F 1 "10k" V 7350 4970 50  0000 C CNN
F 2 "" H 7350 4970 50  0001 C CNN
F 3 "" H 7350 4970 50  0001 C CNN
F 4 "0603" H 7450 5060 50  0000 L CNN "display_footprint"
F 5 "1%" H 7450 4970 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 7460 4890 50  0000 L CNN "Wattage"
F 7 "PN" H 7650 5370 60  0001 C CNN "Digi-Key PN"
	1    7350 4970
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0503
U 1 1 5BE40D3B
P 6480 5120
F 0 "#PWR0503" H 6480 4870 50  0001 C CNN
F 1 "GND" H 6480 4970 50  0000 C CNN
F 2 "" H 6480 5120 50  0001 C CNN
F 3 "" H 6480 5120 50  0001 C CNN
	1    6480 5120
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0504
U 1 1 5BE40D82
P 7350 5120
F 0 "#PWR0504" H 7350 4870 50  0001 C CNN
F 1 "GND" H 7350 4970 50  0000 C CNN
F 2 "" H 7350 5120 50  0001 C CNN
F 3 "" H 7350 5120 50  0001 C CNN
	1    7350 5120
	1    0    0    -1  
$EndComp
Wire Wire Line
	6480 4820 6480 4520
Wire Wire Line
	6480 4520 5760 4520
Wire Wire Line
	7350 4820 7350 3850
Wire Wire Line
	7350 3850 5760 3850
Wire Wire Line
	5210 4520 5070 4520
Wire Wire Line
	5070 4520 5070 4340
Wire Wire Line
	5070 4340 3930 4340
Connection ~ 3930 4340
Wire Wire Line
	4640 4140 5070 4140
Wire Wire Line
	5070 4140 5070 3850
Wire Wire Line
	5070 3850 5210 3850
Connection ~ 4640 4140
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BE49006
P 5780 5240
AR Path="/5BAAE16C/5BE49006" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BE49006" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5BE49006" Ref="C?"  Part="1" 
AR Path="/5BE4F849/5BE49006" Ref="C?"  Part="1" 
F 0 "C?" H 5805 5340 50  0000 L CNN
F 1 "0.1uF" H 5805 5140 50  0000 L CNN
F 2 "" H 5818 5090 50  0001 C CNN
F 3 "" H 5805 5340 50  0001 C CNN
F 4 "0603" H 5630 5340 50  0000 R CNN "display_footprint"
F 5 "25V" H 5630 5240 50  0000 R CNN "Voltage"
F 6 "X7R" H 5630 5140 50  0000 R CNN "Dielectric"
F 7 "PN" H 6205 5740 60  0001 C CNN "Digi-Key PN"
	1    5780 5240
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0505
U 1 1 5BE4900D
P 5780 5090
F 0 "#PWR0505" H 5780 4940 50  0001 C CNN
F 1 "+3.3V" H 5780 5230 50  0000 C CNN
F 2 "" H 5780 5090 50  0001 C CNN
F 3 "" H 5780 5090 50  0001 C CNN
	1    5780 5090
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0506
U 1 1 5BE49013
P 5780 5390
F 0 "#PWR0506" H 5780 5140 50  0001 C CNN
F 1 "GND" H 5780 5240 50  0000 C CNN
F 2 "" H 5780 5390 50  0001 C CNN
F 3 "" H 5780 5390 50  0001 C CNN
	1    5780 5390
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:74LVC1G79_Power U?
U 1 1 5BE4DB5B
P 8380 4240
F 0 "U?" H 8490 4440 50  0000 L CNN
F 1 "74LVC1G79" H 8490 4020 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 8180 4340 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 8280 4440 50  0001 C CNN
F 4 "296-9850-1-ND" H 8480 4640 50  0001 C CNN "Digi-Key PN"
	1    8380 4240
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0507
U 1 1 5BE50A2D
P 8380 4390
F 0 "#PWR0507" H 8380 4140 50  0001 C CNN
F 1 "GND" H 8380 4240 50  0000 C CNN
F 2 "" H 8380 4390 50  0001 C CNN
F 3 "" H 8380 4390 50  0001 C CNN
	1    8380 4390
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0508
U 1 1 5BE50A8D
P 8380 4090
F 0 "#PWR0508" H 8380 3940 50  0001 C CNN
F 1 "+3.3V" H 8380 4230 50  0000 C CNN
F 2 "" H 8380 4090 50  0001 C CNN
F 3 "" H 8380 4090 50  0001 C CNN
	1    8380 4090
	1    0    0    -1  
$EndComp
Wire Wire Line
	8130 4140 7950 4140
Wire Wire Line
	7950 4140 7950 3850
Wire Wire Line
	7950 3850 7350 3850
Connection ~ 7350 3850
Wire Wire Line
	8130 4340 7950 4340
Wire Wire Line
	7950 4340 7950 4520
Wire Wire Line
	7950 4520 6480 4520
Connection ~ 6480 4520
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BE540FF
P 8480 5010
AR Path="/5BAAE16C/5BE540FF" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BE540FF" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5BE540FF" Ref="C?"  Part="1" 
AR Path="/5BE4F849/5BE540FF" Ref="C?"  Part="1" 
F 0 "C?" H 8505 5110 50  0000 L CNN
F 1 "0.1uF" H 8505 4910 50  0000 L CNN
F 2 "" H 8518 4860 50  0001 C CNN
F 3 "" H 8505 5110 50  0001 C CNN
F 4 "0603" H 8330 5110 50  0000 R CNN "display_footprint"
F 5 "25V" H 8330 5010 50  0000 R CNN "Voltage"
F 6 "X7R" H 8330 4910 50  0000 R CNN "Dielectric"
F 7 "PN" H 8905 5510 60  0001 C CNN "Digi-Key PN"
	1    8480 5010
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0509
U 1 1 5BE54106
P 8480 4860
F 0 "#PWR0509" H 8480 4710 50  0001 C CNN
F 1 "+3.3V" H 8480 5000 50  0000 C CNN
F 2 "" H 8480 4860 50  0001 C CNN
F 3 "" H 8480 4860 50  0001 C CNN
	1    8480 4860
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0510
U 1 1 5BE5410C
P 8480 5160
F 0 "#PWR0510" H 8480 4910 50  0001 C CNN
F 1 "GND" H 8480 5010 50  0000 C CNN
F 2 "" H 8480 5160 50  0001 C CNN
F 3 "" H 8480 5160 50  0001 C CNN
	1    8480 5160
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE55C3C
P 9230 4410
F 0 "R?" V 9130 4410 50  0000 C CNN
F 1 "10k" V 9230 4410 50  0000 C CNN
F 2 "" H 9230 4410 50  0001 C CNN
F 3 "" H 9230 4410 50  0001 C CNN
F 4 "0603" H 9330 4500 50  0000 L CNN "display_footprint"
F 5 "1%" H 9330 4410 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 9340 4330 50  0000 L CNN "Wattage"
F 7 "PN" H 9530 4810 60  0001 C CNN "Digi-Key PN"
	1    9230 4410
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0511
U 1 1 5BE55CB5
P 9230 4560
F 0 "#PWR0511" H 9230 4310 50  0001 C CNN
F 1 "GND" H 9230 4410 50  0000 C CNN
F 2 "" H 9230 4560 50  0001 C CNN
F 3 "" H 9230 4560 50  0001 C CNN
	1    9230 4560
	1    0    0    -1  
$EndComp
Wire Wire Line
	9230 4260 9230 4140
Wire Wire Line
	9230 4140 8630 4140
Text GLabel 9350 4140 2    50   Output ~ 0
ENCODER_DIR
Wire Wire Line
	9350 4140 9230 4140
Connection ~ 9230 4140
Text GLabel 9350 3850 2    50   Output ~ 0
ENCODER_STEP
Wire Wire Line
	9350 3850 7950 3850
Connection ~ 7950 3850
$Comp
L Power_Protection:PESD3V3L4UG D?
U 1 1 5BF48679
P 2340 4720
F 0 "D?" V 2294 4788 50  0000 L CNN
F 1 "PESD3V3L4UG" V 2385 4788 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-353_SC-70-5" H 2340 4720 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/PESDXL4UF_G_W.pdf" H 2340 4720 50  0001 C CNN
	1    2340 4720
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0512
U 1 1 5BF48715
P 2340 4820
F 0 "#PWR0512" H 2340 4570 50  0001 C CNN
F 1 "GND" H 2340 4670 50  0000 C CNN
F 2 "" H 2340 4820 50  0001 C CNN
F 3 "" H 2340 4820 50  0001 C CNN
	1    2340 4820
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:PESD3V3L4UG D?
U 2 1 5BF4A271
P 3010 4720
F 0 "D?" V 2964 4788 50  0000 L CNN
F 1 "PESD3V3L4UG" V 3055 4788 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-353_SC-70-5" H 3010 4720 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/PESDXL4UF_G_W.pdf" H 3010 4720 50  0001 C CNN
	2    3010 4720
	0    1    1    0   
$EndComp
Wire Wire Line
	3010 4620 3010 4340
Wire Wire Line
	2340 4620 2340 4140
$EndSCHEMATC
