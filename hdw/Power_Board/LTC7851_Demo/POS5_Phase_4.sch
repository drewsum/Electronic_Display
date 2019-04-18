EESchema Schematic File Version 4
LIBS:LTC7851_Demo-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 7 14
Title "Electronic Display Power Board"
Date "2018-11-28"
Rev "A"
Comp "Marquette University Senior Design 2018/2019 Group E44"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 1960 3310 0    50   Input ~ 0
POS5_RUN
Text GLabel 1960 3910 0    50   Output ~ 0
POS5_PGOOD_OC
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BD4BE0C
P 4560 1340
AR Path="/5BB86F29/5BD4BE0C" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4BE0C" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4BE0C" Ref="C704"  Part="1" 
F 0 "C704" H 4585 1440 50  0000 L CNN
F 1 "1uF" H 4585 1240 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4598 1190 50  0001 C CNN
F 3 "" H 4585 1440 50  0001 C CNN
F 4 "1276-6524-1-ND" H 4985 1840 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 4410 1440 50  0000 R CNN "display_footprint"
F 6 "16V" H 4410 1340 50  0000 R CNN "Voltage"
F 7 "X7R" H 4410 1240 50  0000 R CNN "Dielectric"
	1    4560 1340
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BD4BE13
P 5180 2020
AR Path="/5BB86F29/5BD4BE13" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BE13" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BE13" Ref="#PWR0711"  Part="1" 
F 0 "#PWR0711" H 5180 1770 50  0001 C CNN
F 1 "GND" H 5180 1870 50  0000 C CNN
F 2 "" H 5180 2020 50  0001 C CNN
F 3 "" H 5180 2020 50  0001 C CNN
	1    5180 2020
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:SiC779 U?
U 1 1 5BD4BE1A
P 6080 2810
AR Path="/5BB86F29/5BD4BE1A" Ref="U?"  Part="1" 
AR Path="/5BB86F2C/5BD4BE1A" Ref="U?"  Part="1" 
AR Path="/5BB86F32/5BD4BE1A" Ref="U701"  Part="1" 
F 0 "U701" H 6080 960 50  0000 C CNN
F 1 "SiC779" H 6080 4660 50  0000 C CNN
F 2 "Custom Footprints Library:MLP66-40_6x6mm_Pitch0.5mm" H 4430 3560 50  0001 C CNN
F 3 "http://www.vishay.com/docs/67538/sic779.pdf" H 6080 2810 50  0001 C CNN
F 4 "SIC779CD-T1-GE3CT-ND" H 6080 2810 50  0001 C CNN "Digi-Key PN"
	1    6080 2810
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BD4BE21
P 4560 1490
AR Path="/5BB86F29/5BD4BE21" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BE21" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BE21" Ref="#PWR0708"  Part="1" 
F 0 "#PWR0708" H 4560 1240 50  0001 C CNN
F 1 "GND" H 4560 1340 50  0000 C CNN
F 2 "" H 4560 1490 50  0001 C CNN
F 3 "" H 4560 1490 50  0001 C CNN
	1    4560 1490
	1    0    0    -1  
$EndComp
Wire Wire Line
	5430 1610 5180 1610
Wire Wire Line
	5180 1610 5180 1490
Wire Wire Line
	5180 1610 5180 1720
Connection ~ 5180 1610
Wire Wire Line
	5430 1110 5180 1110
Wire Wire Line
	4560 1110 4560 1190
Wire Wire Line
	5180 1190 5180 1110
Connection ~ 5180 1110
Wire Wire Line
	5180 1110 4560 1110
Wire Wire Line
	4560 1030 4560 1110
Connection ~ 4560 1110
Text GLabel 5430 2610 0    40   Output ~ 0
~POS5_THDN
$Comp
L power:GND #PWR?
U 1 1 5BD4BE41
P 6810 4590
AR Path="/5BB86F29/5BD4BE41" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BE41" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BE41" Ref="#PWR0715"  Part="1" 
F 0 "#PWR0715" H 6810 4340 50  0001 C CNN
F 1 "GND" H 6810 4440 50  0000 C CNN
F 2 "" H 6810 4590 50  0001 C CNN
F 3 "" H 6810 4590 50  0001 C CNN
	1    6810 4590
	1    0    0    -1  
$EndComp
Wire Wire Line
	6810 4590 6810 4510
Wire Wire Line
	6810 4510 6730 4510
Wire Wire Line
	6810 4510 6810 4410
Wire Wire Line
	6810 4410 6730 4410
Connection ~ 6810 4510
Wire Wire Line
	6810 4410 6810 4310
Wire Wire Line
	6810 4310 6730 4310
Connection ~ 6810 4410
$Comp
L power:GND #PWR?
U 1 1 5BD4BE4F
P 5350 4590
AR Path="/5BB86F29/5BD4BE4F" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BE4F" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BE4F" Ref="#PWR0712"  Part="1" 
F 0 "#PWR0712" H 5350 4340 50  0001 C CNN
F 1 "GND" H 5350 4440 50  0000 C CNN
F 2 "" H 5350 4590 50  0001 C CNN
F 3 "" H 5350 4590 50  0001 C CNN
	1    5350 4590
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 4590 5350 4510
Wire Wire Line
	5350 4510 5430 4510
Wire Wire Line
	5430 3310 5350 3310
Wire Wire Line
	5430 3410 5350 3410
Wire Wire Line
	5430 3510 5350 3510
Wire Wire Line
	5430 3610 5350 3610
Wire Wire Line
	5430 3710 5350 3710
Wire Wire Line
	5430 3810 5350 3810
Wire Wire Line
	5430 3910 5350 3910
Wire Wire Line
	5430 4010 5350 4010
Wire Wire Line
	5430 4110 5350 4110
Wire Wire Line
	5430 4210 5350 4210
Wire Wire Line
	5430 4310 5350 4310
Wire Wire Line
	5430 4410 5350 4410
Wire Wire Line
	5350 3310 5350 3410
Connection ~ 5350 4510
Connection ~ 5350 3410
Wire Wire Line
	5350 3410 5350 3510
Connection ~ 5350 3510
Wire Wire Line
	5350 3510 5350 3610
Connection ~ 5350 3610
Wire Wire Line
	5350 3610 5350 3710
Connection ~ 5350 3710
Wire Wire Line
	5350 3710 5350 3810
Connection ~ 5350 3810
Wire Wire Line
	5350 3810 5350 3910
Connection ~ 5350 3910
Wire Wire Line
	5350 3910 5350 4010
Connection ~ 5350 4010
Wire Wire Line
	5350 4010 5350 4110
Connection ~ 5350 4110
Wire Wire Line
	5350 4110 5350 4210
Connection ~ 5350 4210
Wire Wire Line
	5350 4210 5350 4310
Connection ~ 5350 4310
Wire Wire Line
	5350 4310 5350 4410
Connection ~ 5350 4410
Wire Wire Line
	5350 4410 5350 4510
Wire Wire Line
	6730 3310 6810 3310
Wire Wire Line
	6730 3410 6810 3410
Wire Wire Line
	6730 3510 6810 3510
Wire Wire Line
	6730 3610 6810 3610
Wire Wire Line
	6730 3710 6810 3710
Wire Wire Line
	6730 3810 6810 3810
Wire Wire Line
	6730 3910 6810 3910
Wire Wire Line
	6730 4010 6810 4010
Wire Wire Line
	6810 3310 6810 3410
Connection ~ 6810 3410
Wire Wire Line
	6810 3410 6810 3510
Connection ~ 6810 3510
Wire Wire Line
	6810 3510 6810 3610
Connection ~ 6810 3610
Wire Wire Line
	6810 3610 6810 3710
Connection ~ 6810 3710
Wire Wire Line
	6810 3710 6810 3810
Connection ~ 6810 3810
Wire Wire Line
	6810 3810 6810 3910
Connection ~ 6810 3910
Wire Wire Line
	6810 3910 6810 4010
$Comp
L LED_Display_Local_Library:L_Custom L?
U 1 1 5BD4BE94
P 7440 3310
AR Path="/5BB86F29/5BD4BE94" Ref="L?"  Part="1" 
AR Path="/5BB86F2C/5BD4BE94" Ref="L?"  Part="1" 
AR Path="/5BB86F32/5BD4BE94" Ref="L701"  Part="1" 
F 0 "L701" V 7390 3310 50  0000 C CNN
F 1 "1uH" V 7515 3310 50  0000 C CNN
F 2 "Inductors_SMD:L_Vishay_IHLP-4040" H 7440 3310 50  0001 C CNN
F 3 "" H 7440 3310 50  0001 C CNN
F 4 "541-1306-1-ND" H 7440 3310 50  0001 C CNN "Digi-Key PN"
F 5 "IHLP4040" V 7590 3310 50  0000 C CNN "display_footprint"
F 6 "25A" V 7690 3310 50  0000 C CNN "Ampacity"
F 7 "20%" V 7790 3310 50  0000 C CNN "Tolerance"
	1    7440 3310
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6730 1110 6810 1110
Wire Wire Line
	6730 1210 6810 1210
Wire Wire Line
	6730 1310 6810 1310
Wire Wire Line
	6730 1410 6810 1410
Wire Wire Line
	6730 1510 6810 1510
Wire Wire Line
	6730 1610 6810 1610
Wire Wire Line
	6730 1710 6810 1710
Wire Wire Line
	6730 1810 6810 1810
Wire Wire Line
	6810 1110 6810 1210
Connection ~ 6810 1210
Wire Wire Line
	6810 1210 6810 1310
Connection ~ 6810 1310
Wire Wire Line
	6810 1310 6810 1410
Connection ~ 6810 1410
Wire Wire Line
	6810 1410 6810 1510
Connection ~ 6810 1510
Wire Wire Line
	6810 1510 6810 1610
Connection ~ 6810 1610
Wire Wire Line
	6810 1610 6810 1710
Connection ~ 6810 1710
Wire Wire Line
	6810 1710 6810 1810
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BD4BEB5
P 6980 2470
AR Path="/5BB86F29/5BD4BEB5" Ref="R?"  Part="1" 
AR Path="/5BB86F2C/5BD4BEB5" Ref="R?"  Part="1" 
AR Path="/5BB86F32/5BD4BEB5" Ref="R702"  Part="1" 
F 0 "R702" H 6920 2470 50  0000 R CNN
F 1 "2" V 6980 2470 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 6980 2470 50  0001 C CNN
F 3 "" H 6980 2470 50  0001 C CNN
F 4 "RMCF0603FT2R00CT-ND" H 7280 2870 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 7080 2550 50  0000 L CNN "display_footprint"
F 6 "1%" H 7080 2470 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 7080 2390 50  0000 L CNN "Wattage"
	1    6980 2470
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BD4BEC0
P 6980 2850
AR Path="/5BB86F29/5BD4BEC0" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4BEC0" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4BEC0" Ref="C708"  Part="1" 
F 0 "C708" H 7005 2950 50  0000 L CNN
F 1 "0.1uF" H 7005 2750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7018 2700 50  0001 C CNN
F 3 "" H 7005 2950 50  0001 C CNN
F 4 "490-4779-1-ND" H 7405 3350 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 6830 2950 50  0000 R CNN "display_footprint"
F 6 "50V" H 6830 2850 50  0000 R CNN "Voltage"
F 7 "X7R" H 6830 2750 50  0000 R CNN "Dielectric"
	1    6980 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6980 3110 6980 3000
Wire Wire Line
	6980 2700 6980 2620
Wire Wire Line
	6980 3110 6730 3110
Wire Wire Line
	6980 2320 6980 2210
Wire Wire Line
	6980 2210 6730 2210
Connection ~ 6810 3310
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BD4BEF6
P 7880 1340
AR Path="/5BB86F29/5BD4BEF6" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4BEF6" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4BEF6" Ref="C711"  Part="1" 
F 0 "C711" H 7905 1440 50  0000 L CNN
F 1 "22uF" H 7905 1240 50  0000 L CNN
F 2 "Capacitors_SMD:C_1210" H 7918 1190 50  0001 C CNN
F 3 "" H 7905 1440 50  0001 C CNN
F 4 "445-1436-1-ND" H 8305 1840 60  0001 C CNN "Digi-Key PN"
F 5 "1210" H 7730 1440 50  0000 R CNN "display_footprint"
F 6 "25V" H 7730 1340 50  0000 R CNN "Voltage"
F 7 "X5R" H 7730 1240 50  0000 R CNN "Dielectric"
	1    7880 1340
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BD4BEFD
P 7280 1490
AR Path="/5BB86F29/5BD4BEFD" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BEFD" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BEFD" Ref="#PWR0716"  Part="1" 
F 0 "#PWR0716" H 7280 1240 50  0001 C CNN
F 1 "GND" H 7280 1340 50  0000 C CNN
F 2 "" H 7280 1490 50  0001 C CNN
F 3 "" H 7280 1490 50  0001 C CNN
	1    7280 1490
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BD4BF03
P 7880 1490
AR Path="/5BB86F29/5BD4BF03" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF03" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BF03" Ref="#PWR0717"  Part="1" 
F 0 "#PWR0717" H 7880 1240 50  0001 C CNN
F 1 "GND" H 7880 1340 50  0000 C CNN
F 2 "" H 7880 1490 50  0001 C CNN
F 3 "" H 7880 1490 50  0001 C CNN
	1    7880 1490
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BD4BF09
P 8480 1490
AR Path="/5BB86F29/5BD4BF09" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF09" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BF09" Ref="#PWR0720"  Part="1" 
F 0 "#PWR0720" H 8480 1240 50  0001 C CNN
F 1 "GND" H 8480 1340 50  0000 C CNN
F 2 "" H 8480 1490 50  0001 C CNN
F 3 "" H 8480 1490 50  0001 C CNN
	1    8480 1490
	1    0    0    -1  
$EndComp
Connection ~ 6810 1110
Wire Wire Line
	7280 1190 7280 1110
Connection ~ 7280 1110
Wire Wire Line
	7280 1110 6810 1110
Wire Wire Line
	7880 1190 7880 1110
Connection ~ 7880 1110
Wire Wire Line
	7880 1110 7280 1110
Wire Wire Line
	8480 1190 8480 1110
Connection ~ 8480 1110
Wire Wire Line
	8480 1110 7880 1110
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BD4BF1D
P 8420 3540
AR Path="/5BB86F29/5BD4BF1D" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF1D" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4BF1D" Ref="C712"  Part="1" 
F 0 "C712" H 8445 3640 50  0000 L CNN
F 1 "100uF" H 8445 3440 50  0000 L CNN
F 2 "Capacitors_SMD:C_1210" H 8458 3390 50  0001 C CNN
F 3 "" H 8445 3640 50  0001 C CNN
F 4 "587-3432-1-ND" H 8845 4040 60  0001 C CNN "Digi-Key PN"
F 5 "1210" H 8270 3640 50  0000 R CNN "display_footprint"
F 6 "10V" H 8270 3540 50  0000 R CNN "Voltage"
F 7 "X5R" H 8270 3440 50  0000 R CNN "Dielectric"
	1    8420 3540
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BD4BF24
P 8420 3690
AR Path="/5BB86F29/5BD4BF24" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF24" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BF24" Ref="#PWR0718"  Part="1" 
F 0 "#PWR0718" H 8420 3440 50  0001 C CNN
F 1 "GND" H 8420 3540 50  0000 C CNN
F 2 "" H 8420 3690 50  0001 C CNN
F 3 "" H 8420 3690 50  0001 C CNN
	1    8420 3690
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BD4BF2A
P 9020 3690
AR Path="/5BB86F29/5BD4BF2A" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF2A" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BF2A" Ref="#PWR0721"  Part="1" 
F 0 "#PWR0721" H 9020 3440 50  0001 C CNN
F 1 "GND" H 9020 3540 50  0000 C CNN
F 2 "" H 9020 3690 50  0001 C CNN
F 3 "" H 9020 3690 50  0001 C CNN
	1    9020 3690
	1    0    0    -1  
$EndComp
Wire Wire Line
	8420 3390 8420 3310
Connection ~ 8420 3310
Wire Wire Line
	9020 3390 9020 3310
Wire Wire Line
	9020 3310 8420 3310
$Comp
L power:+5V #PWR?
U 1 1 5BD4BF35
P 9620 3150
AR Path="/5BB86F29/5BD4BF35" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF35" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BF35" Ref="#PWR0722"  Part="1" 
F 0 "#PWR0722" H 9620 3000 50  0001 C CNN
F 1 "+5V" H 9620 3290 50  0000 C CNN
F 2 "" H 9620 3150 50  0001 C CNN
F 3 "" H 9620 3150 50  0001 C CNN
	1    9620 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BD4BF3B
P 3330 7520
AR Path="/5BB86F29/5BD4BF3B" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF3B" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BF3B" Ref="#PWR0702"  Part="1" 
F 0 "#PWR0702" H 3330 7270 50  0001 C CNN
F 1 "GND" H 3330 7370 50  0000 C CNN
F 2 "" H 3330 7520 50  0001 C CNN
F 3 "" H 3330 7520 50  0001 C CNN
	1    3330 7520
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BD4BF41
P 3930 7520
AR Path="/5BB86F29/5BD4BF41" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF41" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BF41" Ref="#PWR0704"  Part="1" 
F 0 "#PWR0704" H 3930 7270 50  0001 C CNN
F 1 "GND" H 3930 7370 50  0000 C CNN
F 2 "" H 3930 7520 50  0001 C CNN
F 3 "" H 3930 7520 50  0001 C CNN
	1    3930 7520
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BD4BF47
P 4530 7520
AR Path="/5BB86F29/5BD4BF47" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF47" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BF47" Ref="#PWR0706"  Part="1" 
F 0 "#PWR0706" H 4530 7270 50  0001 C CNN
F 1 "GND" H 4530 7370 50  0000 C CNN
F 2 "" H 4530 7520 50  0001 C CNN
F 3 "" H 4530 7520 50  0001 C CNN
	1    4530 7520
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BD4BF4D
P 5130 7520
AR Path="/5BB86F29/5BD4BF4D" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF4D" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BF4D" Ref="#PWR0710"  Part="1" 
F 0 "#PWR0710" H 5130 7270 50  0001 C CNN
F 1 "GND" H 5130 7370 50  0000 C CNN
F 2 "" H 5130 7520 50  0001 C CNN
F 3 "" H 5130 7520 50  0001 C CNN
	1    5130 7520
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BD4BF53
P 5730 7520
AR Path="/5BB86F29/5BD4BF53" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF53" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BF53" Ref="#PWR0714"  Part="1" 
F 0 "#PWR0714" H 5730 7270 50  0001 C CNN
F 1 "GND" H 5730 7370 50  0000 C CNN
F 2 "" H 5730 7520 50  0001 C CNN
F 3 "" H 5730 7520 50  0001 C CNN
	1    5730 7520
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:LTC7851UHH U?
U 5 1 5BD4BF5A
P 2510 4210
AR Path="/5BB86F29/5BD4BF5A" Ref="U?"  Part="2" 
AR Path="/5BB86F2C/5BD4BF5A" Ref="U?"  Part="3" 
AR Path="/5BB86F32/5BD4BF5A" Ref="U301"  Part="5" 
F 0 "U301" H 2910 2160 50  0000 R CNN
F 1 "LTC7851UHH" H 2510 6260 50  0000 C CNN
F 2 "Custom Footprints Library:QFN-58-1EP_9x5mm_Pitch0.4mm" H -140 4910 50  0001 C CNN
F 3 "http://www.analog.com/media/en/technical-documentation/data-sheets/LTC7851.pdf" H 2510 4210 50  0001 C CNN
F 4 "LTC7851IUHH#PBF-ND" H 2510 4210 50  0001 C CNN "Digi-Key PN"
	5    2510 4210
	1    0    0    -1  
$EndComp
Text GLabel 3060 4110 2    50   UnSpc ~ 0
POS5_VOSNS
Text GLabel 3060 6110 2    50   UnSpc ~ 0
POS5_COMP
Text GLabel 1960 4910 0    50   UnSpc ~ 0
POS5_SS
Text GLabel 1960 5510 0    50   UnSpc ~ 0
POS5_IAVG
Text GLabel 1960 6110 0    50   UnSpc ~ 0
POS5_ILIM
$Comp
L LED_Display_Local_Library:+5.5V_MNG #PWR?
U 1 1 5BD4BF66
P 4560 1030
AR Path="/5BB86F29/5BD4BF66" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF66" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BF66" Ref="#PWR0707"  Part="1" 
F 0 "#PWR0707" H 4560 880 50  0001 C CNN
F 1 "+5.5V_MNG" H 4560 1170 50  0000 C CNN
F 2 "" H 4560 1030 50  0001 C CNN
F 3 "" H 4560 1030 50  0001 C CNN
	1    4560 1030
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BD4BF70
P 5180 1870
AR Path="/5BB86F29/5BD4BF70" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF70" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4BF70" Ref="C706"  Part="1" 
F 0 "C706" H 5205 1970 50  0000 L CNN
F 1 "0.1uF" H 5205 1770 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5218 1720 50  0001 C CNN
F 3 "" H 5205 1970 50  0001 C CNN
F 4 "490-4779-1-ND" H 5605 2370 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 5030 1970 50  0000 R CNN "display_footprint"
F 6 "50V" H 5030 1870 50  0000 R CNN "Voltage"
F 7 "X7R" H 5030 1770 50  0000 R CNN "Dielectric"
	1    5180 1870
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BD4BF7B
P 5180 1340
AR Path="/5BB86F29/5BD4BF7B" Ref="R?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF7B" Ref="R?"  Part="1" 
AR Path="/5BB86F32/5BD4BF7B" Ref="R701"  Part="1" 
F 0 "R701" H 5120 1340 50  0000 R CNN
F 1 "2" V 5180 1340 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 5180 1340 50  0001 C CNN
F 3 "" H 5180 1340 50  0001 C CNN
F 4 "RMCF0603FT2R00CT-ND" H 5480 1740 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 5280 1420 50  0000 L CNN "display_footprint"
F 6 "1%" H 5280 1340 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 5280 1260 50  0000 L CNN "Wattage"
	1    5180 1340
	-1   0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 5BD4BF82
P 8480 1030
AR Path="/5BB86F29/5BD4BF82" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF82" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BF82" Ref="#PWR0719"  Part="1" 
F 0 "#PWR0719" H 8480 880 50  0001 C CNN
F 1 "+12V" H 8480 1170 50  0000 C CNN
F 2 "" H 8480 1030 50  0001 C CNN
F 3 "" H 8480 1030 50  0001 C CNN
	1    8480 1030
	1    0    0    -1  
$EndComp
Wire Wire Line
	8480 1030 8480 1110
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BD4BF8D
P 7280 1340
AR Path="/5BB86F29/5BD4BF8D" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF8D" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4BF8D" Ref="C709"  Part="1" 
F 0 "C709" H 7305 1440 50  0000 L CNN
F 1 "1uF" H 7305 1240 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7318 1190 50  0001 C CNN
F 3 "" H 7305 1440 50  0001 C CNN
F 4 "1276-6524-1-ND" H 7705 1840 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 7130 1440 50  0000 R CNN "display_footprint"
F 6 "16V" H 7130 1340 50  0000 R CNN "Voltage"
F 7 "X7R" H 7130 1240 50  0000 R CNN "Dielectric"
	1    7280 1340
	1    0    0    -1  
$EndComp
Connection ~ 9020 3310
$Comp
L LED_Display_Local_Library:CP_Tant_Custom C?
U 1 1 5BD4BF99
P 9620 3540
AR Path="/5BB86F29/5BD4BF99" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4BF99" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4BF99" Ref="C715"  Part="1" 
F 0 "C715" H 9645 3640 50  0000 L CNN
F 1 "100uF" H 9645 3440 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Reflow" H 9658 3390 50  0001 C CNN
F 3 "" H 9645 3640 50  0001 C CNN
F 4 "478-9994-1-ND" H 9620 3540 50  0001 C CNN "Digi-Key PN"
F 5 "3528" H 9470 3640 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 9470 3540 50  0000 R CNN "Voltage"
F 7 "20%" H 9470 3440 50  0000 R CNN "Tolerance"
	1    9620 3540
	1    0    0    -1  
$EndComp
Wire Wire Line
	9620 3390 9620 3310
Wire Wire Line
	9620 3310 9020 3310
Wire Wire Line
	9620 3150 9620 3310
Connection ~ 9620 3310
$Comp
L power:GND #PWR?
U 1 1 5BD4BFA4
P 9620 3690
AR Path="/5BB86F29/5BD4BFA4" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BFA4" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BFA4" Ref="#PWR0723"  Part="1" 
F 0 "#PWR0723" H 9620 3440 50  0001 C CNN
F 1 "GND" H 9620 3540 50  0000 C CNN
F 2 "" H 9620 3690 50  0001 C CNN
F 3 "" H 9620 3690 50  0001 C CNN
	1    9620 3690
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5BD4BFAA
P 3330 7220
AR Path="/5BB86F29/5BD4BFAA" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BFAA" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BFAA" Ref="#PWR0701"  Part="1" 
F 0 "#PWR0701" H 3330 7070 50  0001 C CNN
F 1 "+5V" H 3330 7360 50  0000 C CNN
F 2 "" H 3330 7220 50  0001 C CNN
F 3 "" H 3330 7220 50  0001 C CNN
	1    3330 7220
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5BD4BFB0
P 3930 7220
AR Path="/5BB86F29/5BD4BFB0" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BFB0" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BFB0" Ref="#PWR0703"  Part="1" 
F 0 "#PWR0703" H 3930 7070 50  0001 C CNN
F 1 "+5V" H 3930 7360 50  0000 C CNN
F 2 "" H 3930 7220 50  0001 C CNN
F 3 "" H 3930 7220 50  0001 C CNN
	1    3930 7220
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5BD4BFB6
P 4530 7220
AR Path="/5BB86F29/5BD4BFB6" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BFB6" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BFB6" Ref="#PWR0705"  Part="1" 
F 0 "#PWR0705" H 4530 7070 50  0001 C CNN
F 1 "+5V" H 4530 7360 50  0000 C CNN
F 2 "" H 4530 7220 50  0001 C CNN
F 3 "" H 4530 7220 50  0001 C CNN
	1    4530 7220
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5BD4BFBC
P 5130 7220
AR Path="/5BB86F29/5BD4BFBC" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BFBC" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BFBC" Ref="#PWR0709"  Part="1" 
F 0 "#PWR0709" H 5130 7070 50  0001 C CNN
F 1 "+5V" H 5130 7360 50  0000 C CNN
F 2 "" H 5130 7220 50  0001 C CNN
F 3 "" H 5130 7220 50  0001 C CNN
	1    5130 7220
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5BD4BFC2
P 5730 7220
AR Path="/5BB86F29/5BD4BFC2" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F2C/5BD4BFC2" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BD4BFC2" Ref="#PWR0713"  Part="1" 
F 0 "#PWR0713" H 5730 7070 50  0001 C CNN
F 1 "+5V" H 5730 7360 50  0000 C CNN
F 2 "" H 5730 7220 50  0001 C CNN
F 3 "" H 5730 7220 50  0001 C CNN
	1    5730 7220
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BD4BFCC
P 9020 3540
AR Path="/5BB86F29/5BD4BFCC" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4BFCC" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4BFCC" Ref="C714"  Part="1" 
F 0 "C714" H 9045 3640 50  0000 L CNN
F 1 "100uF" H 9045 3440 50  0000 L CNN
F 2 "Capacitors_SMD:C_1210" H 9058 3390 50  0001 C CNN
F 3 "" H 9045 3640 50  0001 C CNN
F 4 "587-3432-1-ND" H 9445 4040 60  0001 C CNN "Digi-Key PN"
F 5 "1210" H 8870 3640 50  0000 R CNN "display_footprint"
F 6 "10V" H 8870 3540 50  0000 R CNN "Voltage"
F 7 "X5R" H 8870 3440 50  0000 R CNN "Dielectric"
	1    9020 3540
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BD4BFD8
P 8480 1340
AR Path="/5BB86F29/5BD4BFD8" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4BFD8" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4BFD8" Ref="C713"  Part="1" 
F 0 "C713" H 8505 1440 50  0000 L CNN
F 1 "22uF" H 8505 1240 50  0000 L CNN
F 2 "Capacitors_SMD:C_1210" H 8518 1190 50  0001 C CNN
F 3 "" H 8505 1440 50  0001 C CNN
F 4 "445-1436-1-ND" H 8905 1840 60  0001 C CNN "Digi-Key PN"
F 5 "1210" H 8330 1440 50  0000 R CNN "display_footprint"
F 6 "25V" H 8330 1340 50  0000 R CNN "Voltage"
F 7 "X5R" H 8330 1240 50  0000 R CNN "Dielectric"
	1    8480 1340
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:CP_Tant_Custom C?
U 1 1 5BD4BFE3
P 3330 7370
AR Path="/5BB86F29/5BD4BFE3" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4BFE3" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4BFE3" Ref="C701"  Part="1" 
F 0 "C701" H 3355 7470 50  0000 L CNN
F 1 "100uF" H 3355 7270 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Reflow" H 3368 7220 50  0001 C CNN
F 3 "" H 3355 7470 50  0001 C CNN
F 4 "478-9994-1-ND" H 3330 7370 50  0001 C CNN "Digi-Key PN"
F 5 "3528" H 3180 7470 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 3180 7370 50  0000 R CNN "Voltage"
F 7 "20%" H 3180 7270 50  0000 R CNN "Tolerance"
	1    3330 7370
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:CP_Tant_Custom C?
U 1 1 5BD4BFEE
P 3930 7370
AR Path="/5BB86F29/5BD4BFEE" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4BFEE" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4BFEE" Ref="C702"  Part="1" 
F 0 "C702" H 3955 7470 50  0000 L CNN
F 1 "100uF" H 3955 7270 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Reflow" H 3968 7220 50  0001 C CNN
F 3 "" H 3955 7470 50  0001 C CNN
F 4 "478-9994-1-ND" H 3930 7370 50  0001 C CNN "Digi-Key PN"
F 5 "3528" H 3780 7470 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 3780 7370 50  0000 R CNN "Voltage"
F 7 "20%" H 3780 7270 50  0000 R CNN "Tolerance"
	1    3930 7370
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:CP_Tant_Custom C?
U 1 1 5BD4BFF9
P 4530 7370
AR Path="/5BB86F29/5BD4BFF9" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4BFF9" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4BFF9" Ref="C703"  Part="1" 
F 0 "C703" H 4555 7470 50  0000 L CNN
F 1 "100uF" H 4555 7270 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Reflow" H 4568 7220 50  0001 C CNN
F 3 "" H 4555 7470 50  0001 C CNN
F 4 "478-9994-1-ND" H 4530 7370 50  0001 C CNN "Digi-Key PN"
F 5 "3528" H 4380 7470 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 4380 7370 50  0000 R CNN "Voltage"
F 7 "20%" H 4380 7270 50  0000 R CNN "Tolerance"
	1    4530 7370
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:CP_Tant_Custom C?
U 1 1 5BD4C004
P 5130 7370
AR Path="/5BB86F29/5BD4C004" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4C004" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4C004" Ref="C705"  Part="1" 
F 0 "C705" H 5155 7470 50  0000 L CNN
F 1 "100uF" H 5155 7270 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Reflow" H 5168 7220 50  0001 C CNN
F 3 "" H 5155 7470 50  0001 C CNN
F 4 "478-9994-1-ND" H 5130 7370 50  0001 C CNN "Digi-Key PN"
F 5 "3528" H 4980 7470 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 4980 7370 50  0000 R CNN "Voltage"
F 7 "20%" H 4980 7270 50  0000 R CNN "Tolerance"
	1    5130 7370
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:CP_Tant_Custom C?
U 1 1 5BD4C00F
P 5730 7370
AR Path="/5BB86F29/5BD4C00F" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BD4C00F" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BD4C00F" Ref="C707"  Part="1" 
F 0 "C707" H 5755 7470 50  0000 L CNN
F 1 "100uF" H 5755 7270 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Reflow" H 5768 7220 50  0001 C CNN
F 3 "" H 5755 7470 50  0001 C CNN
F 4 "478-9994-1-ND" H 5730 7370 50  0001 C CNN "Digi-Key PN"
F 5 "3528" H 5580 7470 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 5580 7370 50  0000 R CNN "Voltage"
F 7 "20%" H 5580 7270 50  0000 R CNN "Tolerance"
	1    5730 7370
	1    0    0    -1  
$EndComp
Wire Wire Line
	3060 2310 5430 2310
NoConn ~ 3060 3910
NoConn ~ 3060 4010
Text GLabel 3060 5110 2    50   UnSpc ~ 0
POS5_EXTVCC
Wire Wire Line
	6730 4110 6810 4110
Wire Wire Line
	6810 4110 6810 4010
Connection ~ 6810 4010
Text Notes 540  690  0    100  ~ 20
07. +5V Phase 4
NoConn ~ 5430 2810
NoConn ~ 5430 2910
NoConn ~ 5430 3110
$Comp
L LED_Display_Local_Library:+5.5V_MNG #PWR?
U 1 1 5BCB24CC
P 5430 2510
AR Path="/5BB86F29/5BCB24CC" Ref="#PWR?"  Part="1" 
AR Path="/5BB86F32/5BCB24CC" Ref="#PWR0104"  Part="1" 
F 0 "#PWR0104" H 5430 2360 50  0001 C CNN
F 1 "+5.5V_MNG" V 5430 2650 50  0000 L CNN
F 2 "" H 5430 2510 50  0001 C CNN
F 3 "" H 5430 2510 50  0001 C CNN
	1    5430 2510
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE7E56E
P 4410 3110
AR Path="/5BB86F29/5BE7E56E" Ref="R?"  Part="1" 
AR Path="/5BB86F2C/5BE7E56E" Ref="R?"  Part="1" 
AR Path="/5BB86F32/5BE7E56E" Ref="R703"  Part="1" 
F 0 "R703" V 4790 3110 50  0000 C CNN
F 1 "1.96k" V 4410 3110 40  0000 C CNN
F 2 "Resistors_SMD:R_0402" H 4410 3110 50  0001 C CNN
F 3 "" H 4410 3110 50  0001 C CNN
F 4 "311-1.96KLRCT-ND" H 4710 3510 60  0001 C CNN "Digi-Key PN"
F 5 "0402" V 4708 3110 50  0000 C CNN "display_footprint"
F 6 "1%" V 4617 3110 50  0000 C CNN "Tolerance"
F 7 "1/16W" V 4526 3110 50  0000 C CNN "Wattage"
	1    4410 3110
	0    1    -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BE7E579
P 3790 3360
AR Path="/5BB86F29/5BE7E579" Ref="C?"  Part="1" 
AR Path="/5BB86F2C/5BE7E579" Ref="C?"  Part="1" 
AR Path="/5BB86F32/5BE7E579" Ref="C710"  Part="1" 
F 0 "C710" H 3675 3178 50  0000 R CNN
F 1 "0.22uF" H 3675 3269 50  0000 R CNN
F 2 "Capacitors_SMD:C_0402" H 3828 3210 50  0001 C CNN
F 3 "" H 3815 3460 50  0001 C CNN
F 4 "1276-1049-1-ND" H 4215 3860 60  0001 C CNN "Digi-Key PN"
F 5 "0402" H 3675 3360 50  0000 R CNN "display_footprint"
F 6 "10V" H 3675 3451 50  0000 R CNN "Voltage"
F 7 "X5R" H 3675 3542 50  0000 R CNN "Dielectric"
	1    3790 3360
	-1   0    0    1   
$EndComp
Wire Wire Line
	4260 3110 3790 3110
Wire Wire Line
	3790 3110 3790 3210
Wire Wire Line
	3790 3510 3790 3610
Wire Wire Line
	3630 3110 3790 3110
Connection ~ 3790 3110
Wire Wire Line
	3790 3610 3630 3610
Text Notes 3170 3780 0    50   ~ 0
Route as diff pairs
Wire Wire Line
	3630 3110 3630 3310
Wire Wire Line
	3630 3610 3630 3410
Wire Wire Line
	3630 3410 3060 3410
Wire Wire Line
	3060 3310 3630 3310
Wire Wire Line
	4560 3110 5150 3110
Wire Wire Line
	5150 3110 5150 4910
Wire Wire Line
	5050 5010 5050 3610
Wire Wire Line
	5050 3610 3790 3610
Connection ~ 3790 3610
Text Label 5940 4910 0    50   ~ 0
POS5_ISNS4_+
Text Label 5940 5010 0    50   ~ 0
POS5_ISNS4_-
Wire Wire Line
	5150 4910 7390 4910
Wire Wire Line
	7490 5010 5050 5010
Wire Wire Line
	7190 3310 7190 3420
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE7E599
P 7190 3570
AR Path="/5BB86F29/5BE7E599" Ref="R?"  Part="1" 
AR Path="/5BB86F32/5BE7E599" Ref="R704"  Part="1" 
F 0 "R704" H 7240 3570 50  0000 L CNN
F 1 "0" V 7190 3570 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" H 7190 3570 50  0001 C CNN
F 3 "" H 7190 3570 50  0001 C CNN
F 4 "RMCF0402ZT0R00CT-ND" H 7490 3970 60  0001 C CNN "Digi-Key PN"
F 5 "0402" V 6893 3570 50  0001 C CNN "display_footprint"
F 6 "1%" V 6984 3570 50  0001 C CNN "Tolerance"
F 7 "1/16W" V 7075 3570 50  0001 C CNN "Wattage"
	1    7190 3570
	1    0    0    1   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE7E5A4
P 7690 3570
AR Path="/5BB86F29/5BE7E5A4" Ref="R?"  Part="1" 
AR Path="/5BB86F32/5BE7E5A4" Ref="R705"  Part="1" 
F 0 "R705" H 7740 3570 50  0000 L CNN
F 1 "0" V 7690 3570 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" H 7690 3570 50  0001 C CNN
F 3 "" H 7690 3570 50  0001 C CNN
F 4 "RMCF0402ZT0R00CT-ND" H 7990 3970 60  0001 C CNN "Digi-Key PN"
F 5 "0402" V 7393 3570 50  0001 C CNN "display_footprint"
F 6 "1%" V 7484 3570 50  0001 C CNN "Tolerance"
F 7 "1/16W" V 7575 3570 50  0001 C CNN "Wattage"
	1    7690 3570
	1    0    0    1   
$EndComp
Wire Wire Line
	7190 3720 7190 3800
Wire Wire Line
	7690 3420 7690 3310
Wire Wire Line
	7390 4910 7390 3800
Wire Wire Line
	7390 3800 7190 3800
Wire Wire Line
	7690 3720 7690 3800
Wire Wire Line
	7690 3800 7490 3800
Wire Wire Line
	7490 3800 7490 5010
Wire Wire Line
	7590 3310 7690 3310
Wire Wire Line
	6810 3310 7190 3310
Connection ~ 7190 3310
Wire Wire Line
	7190 3310 7290 3310
Connection ~ 7690 3310
Wire Wire Line
	7690 3310 8420 3310
$Comp
L LED_Display_Local_Library:MU_Logo #G?
U 1 1 5C003DBA
P 9900 1100
F 0 "#G?" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
Text Notes 3760 6930 0    50   ~ 0
Do not populate any of the capacitors below:\nC701, C702, C703, C705, C707
$EndSCHEMATC
