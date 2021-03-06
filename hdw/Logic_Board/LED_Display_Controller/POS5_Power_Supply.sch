EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 4 32
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
L LED_Display_Local_Library:L_Custom L401
U 1 1 5BE61E7E
P 6040 3230
F 0 "L401" V 5990 3230 50  0000 C CNN
F 1 "3.3uH" V 6115 3230 50  0000 C CNN
F 2 "Inductors_SMD:L_Vishay_IHLP-1212" H 6040 3230 50  0001 C CNN
F 3 "" H 6040 3230 50  0001 C CNN
F 4 "IHLP1212" V 6190 3230 50  0000 C CNN "display_footprint"
F 5 "2.7A" V 6290 3230 50  0000 C CNN "Ampacity"
F 6 "20%" V 6390 3230 50  0000 C CNN "Tolerance"
F 7 "541-2567-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    6040 3230
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5890 3230 5590 3230
$Comp
L LED_Display_Local_Library:C_Custom C404
U 1 1 5BE63583
P 6400 3680
F 0 "C404" H 6425 3780 50  0000 L CNN
F 1 "33pF" H 6425 3580 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6438 3530 50  0001 C CNN
F 3 "" H 6425 3780 50  0001 C CNN
F 4 "0603" H 6250 3780 50  0000 R CNN "display_footprint"
F 5 "50V" H 6250 3680 50  0000 R CNN "Voltage"
F 6 "NP0" H 6250 3580 50  0000 R CNN "Dielectric"
F 7 "399-1055-1-ND" H 6825 4180 60  0001 C CNN "Digi-Key PN"
	1    6400 3680
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R405
U 1 1 5BE635FD
P 7010 3680
F 0 "R405" H 6950 3680 50  0000 R CNN
F 1 "100k" V 7010 3680 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7010 3680 50  0001 C CNN
F 3 "" H 7010 3680 50  0001 C CNN
F 4 "0603" H 7080 3770 50  0000 L CNN "display_footprint"
F 5 "1%" H 7080 3680 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 7080 3600 50  0000 L CNN "Wattage"
F 7 "A106046CT-ND" H 7310 4080 60  0001 C CNN "Digi-Key PN"
	1    7010 3680
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0409
U 1 1 5BE6636E
P 7010 4720
F 0 "#PWR0409" H 7010 4470 50  0001 C CNN
F 1 "GND" H 7010 4570 50  0000 C CNN
F 2 "" H 7010 4720 50  0001 C CNN
F 3 "" H 7010 4720 50  0001 C CNN
	1    7010 4720
	1    0    0    -1  
$EndComp
Wire Wire Line
	7010 4420 7010 4230
Wire Wire Line
	7010 4230 6400 4230
Wire Wire Line
	7010 3530 7010 3230
Wire Wire Line
	6400 3230 6400 3530
Connection ~ 6400 3230
Wire Wire Line
	6400 3230 6190 3230
Connection ~ 6400 4230
Wire Wire Line
	6400 4230 5590 4230
Connection ~ 7010 4230
$Comp
L power:GND #PWR0408
U 1 1 5BE6A7E4
P 4940 5060
F 0 "#PWR0408" H 4940 4810 50  0001 C CNN
F 1 "GND" H 4940 4910 50  0000 C CNN
F 2 "" H 4940 5060 50  0001 C CNN
F 3 "" H 4940 5060 50  0001 C CNN
	1    4940 5060
	1    0    0    -1  
$EndComp
Wire Wire Line
	4940 5060 4940 5020
Wire Wire Line
	4940 5020 4890 5020
Wire Wire Line
	4890 5020 4890 4980
Wire Wire Line
	4940 5020 4990 5020
Wire Wire Line
	4990 5020 4990 4980
Connection ~ 4940 5020
$Comp
L LED_Display_Local_Library:R_Custom R401
U 1 1 5BE6F15A
P 3210 3990
F 0 "R401" H 3150 3990 50  0000 R CNN
F 1 "10k" V 3210 3990 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3210 3990 50  0001 C CNN
F 3 "" H 3210 3990 50  0001 C CNN
F 4 "0603" H 3280 4080 50  0000 L CNN "display_footprint"
F 5 "1%" H 3280 3990 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3280 3910 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 3510 4390 60  0001 C CNN "Digi-Key PN"
	1    3210 3990
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0404
U 1 1 5BE6F4F6
P 3210 5200
F 0 "#PWR0404" H 3210 4950 50  0001 C CNN
F 1 "GND" H 3210 5050 50  0000 C CNN
F 2 "" H 3210 5200 50  0001 C CNN
F 3 "" H 3210 5200 50  0001 C CNN
	1    3210 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0407
U 1 1 5BE6F518
P 4060 5200
F 0 "#PWR0407" H 4060 4950 50  0001 C CNN
F 1 "GND" H 4060 5050 50  0000 C CNN
F 2 "" H 4060 5200 50  0001 C CNN
F 3 "" H 4060 5200 50  0001 C CNN
	1    4060 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4290 4730 4060 4730
Wire Wire Line
	4060 4730 4060 4900
$Comp
L LED_Display_Local_Library:R_Custom R402
U 1 1 5BE753C0
P 3210 5050
F 0 "R402" H 3150 5050 50  0000 R CNN
F 1 "10k" V 3210 5050 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3210 5050 50  0001 C CNN
F 3 "" H 3210 5050 50  0001 C CNN
F 4 "0603" H 3280 5140 50  0000 L CNN "display_footprint"
F 5 "1%" H 3280 5050 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3280 4970 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 3510 5450 60  0001 C CNN "Digi-Key PN"
	1    3210 5050
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R404
U 1 1 5BE75409
P 4060 5050
F 0 "R404" H 4000 5050 50  0000 R CNN
F 1 "10k" V 4060 5050 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 4060 5050 50  0001 C CNN
F 3 "" H 4060 5050 50  0001 C CNN
F 4 "0603" H 4130 5140 50  0000 L CNN "display_footprint"
F 5 "1%" H 4130 5050 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 4130 4970 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 4360 5450 60  0001 C CNN "Digi-Key PN"
	1    4060 5050
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C401
U 1 1 5BE76AE1
P 2500 4140
F 0 "C401" H 2525 4240 50  0000 L CNN
F 1 "2.2uF" H 2525 4040 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2538 3990 50  0001 C CNN
F 3 "" H 2525 4240 50  0001 C CNN
F 4 "0805" H 2350 4240 50  0000 R CNN "display_footprint"
F 5 "16V" H 2350 4140 50  0000 R CNN "Voltage"
F 6 "X7R" H 2350 4040 50  0000 R CNN "Dielectric"
F 7 "445-5691-1-ND" H 2925 4640 60  0001 C CNN "Digi-Key PN"
	1    2500 4140
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0401
U 1 1 5BE76B41
P 2500 4290
F 0 "#PWR0401" H 2500 4040 50  0001 C CNN
F 1 "GND" H 2500 4140 50  0000 C CNN
F 2 "" H 2500 4290 50  0001 C CNN
F 3 "" H 2500 4290 50  0001 C CNN
	1    2500 4290
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:LTC3624DD U401
U 1 1 5BE7A5E1
P 4940 3730
F 0 "U401" H 5390 2780 50  0000 R CNN
F 1 "LTC3624DD" H 4940 3930 50  0000 C CNN
F 2 "Housings_DFN_QFN:DFN-8-1EP_3x3mm_Pitch0.5mm" H 4940 3730 50  0001 C CNN
F 3 "" H 7040 4080 50  0001 C CNN
F 4 "LTC3624IDD#PBF-ND" H 4940 3730 50  0001 C CNN "Digi-Key PN"
	1    4940 3730
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 3830 6400 4230
Wire Wire Line
	7010 3830 7010 4230
Wire Wire Line
	3210 4140 3210 4230
Wire Wire Line
	4290 4230 3210 4230
Connection ~ 3210 4230
Wire Wire Line
	3210 4230 3210 4900
Wire Wire Line
	4290 3730 3210 3730
Wire Wire Line
	2500 3730 2500 3990
Wire Wire Line
	3210 3840 3210 3730
Connection ~ 3210 3730
Wire Wire Line
	3210 3730 2500 3730
$Comp
L LED_Display_Local_Library:R_Custom R403
U 1 1 5BE81C5D
P 4010 3150
F 0 "R403" H 3950 3150 50  0000 R CNN
F 1 "10k" V 4010 3150 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 4010 3150 50  0001 C CNN
F 3 "" H 4010 3150 50  0001 C CNN
F 4 "0603" H 4080 3240 50  0000 L CNN "display_footprint"
F 5 "1%" H 4080 3150 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 4080 3070 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 4310 3550 60  0001 C CNN "Digi-Key PN"
	1    4010 3150
	-1   0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0406
U 1 1 5BE850A3
P 4010 3000
F 0 "#PWR0406" H 4010 2850 50  0001 C CNN
F 1 "+3.3V" H 4010 3140 50  0000 C CNN
F 2 "" H 4010 3000 50  0001 C CNN
F 3 "" H 4010 3000 50  0001 C CNN
	1    4010 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0405
U 1 1 5BE89CE2
P 3480 3090
F 0 "#PWR0405" H 3480 2840 50  0001 C CNN
F 1 "GND" H 3480 2940 50  0000 C CNN
F 2 "" H 3480 3090 50  0001 C CNN
F 3 "" H 3480 3090 50  0001 C CNN
	1    3480 3090
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0403
U 1 1 5BE89D1D
P 2840 3090
F 0 "#PWR0403" H 2840 2840 50  0001 C CNN
F 1 "GND" H 2840 2940 50  0000 C CNN
F 2 "" H 2840 3090 50  0001 C CNN
F 3 "" H 2840 3090 50  0001 C CNN
	1    2840 3090
	1    0    0    -1  
$EndComp
Wire Wire Line
	4290 3430 4010 3430
Wire Wire Line
	4010 3430 4010 3300
Wire Wire Line
	4290 2730 3480 2730
Wire Wire Line
	3480 2730 3480 2790
Wire Wire Line
	3480 2730 2840 2730
Wire Wire Line
	2840 2730 2840 2790
Connection ~ 3480 2730
$Comp
L power:+12V #PWR0402
U 1 1 5BE903DC
P 2840 2650
F 0 "#PWR0402" H 2840 2500 50  0001 C CNN
F 1 "+12V" H 2840 2790 50  0000 C CNN
F 2 "" H 2840 2650 50  0001 C CNN
F 3 "" H 2840 2650 50  0001 C CNN
	1    2840 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2840 2650 2840 2730
Connection ~ 2840 2730
Text GLabel 1840 3430 0    50   Output ~ 0
POS5_PGOOD
Wire Wire Line
	1840 3430 4010 3430
Connection ~ 4010 3430
Text GLabel 1840 4730 0    50   Input ~ 0
POS5_RUN
Wire Wire Line
	1840 4730 4060 4730
Connection ~ 4060 4730
$Comp
L power:GND #PWR0410
U 1 1 5BE97466
P 7810 3590
F 0 "#PWR0410" H 7810 3340 50  0001 C CNN
F 1 "GND" H 7810 3440 50  0000 C CNN
F 2 "" H 7810 3590 50  0001 C CNN
F 3 "" H 7810 3590 50  0001 C CNN
	1    7810 3590
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0411
U 1 1 5BE9746C
P 8450 3590
F 0 "#PWR0411" H 8450 3340 50  0001 C CNN
F 1 "GND" H 8450 3440 50  0000 C CNN
F 2 "" H 8450 3590 50  0001 C CNN
F 3 "" H 8450 3590 50  0001 C CNN
	1    8450 3590
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7810 3230 7810 3290
Wire Wire Line
	7810 3230 8450 3230
Wire Wire Line
	8450 3230 8450 3290
Connection ~ 7810 3230
Connection ~ 8450 3230
Wire Wire Line
	6400 3230 7010 3230
Connection ~ 7010 3230
Wire Wire Line
	7010 3230 7810 3230
$Comp
L power:+5V #PWR0412
U 1 1 5BE988DA
P 9090 3150
F 0 "#PWR0412" H 9090 3000 50  0001 C CNN
F 1 "+5V" H 9090 3290 50  0000 C CNN
F 2 "" H 9090 3150 50  0001 C CNN
F 3 "" H 9090 3150 50  0001 C CNN
	1    9090 3150
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BE9E9A9
P 7810 3440
AR Path="/5BAAE16C/5BE9E9A9" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BE9E9A9" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5BE9E9A9" Ref="C?"  Part="1" 
AR Path="/5BE5222A/5BE9E9A9" Ref="C405"  Part="1" 
F 0 "C405" H 7835 3540 50  0000 L CNN
F 1 "0.1uF" H 7835 3340 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7848 3290 50  0001 C CNN
F 3 "" H 7835 3540 50  0001 C CNN
F 4 "0603" H 7660 3540 50  0000 R CNN "display_footprint"
F 5 "50V" H 7660 3440 50  0000 R CNN "Voltage"
F 6 "X7R" H 7660 3340 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 8235 3940 60  0001 C CNN "Digi-Key PN"
	1    7810 3440
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BE9F007
P 3480 2940
AR Path="/5BAAE16C/5BE9F007" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BE9F007" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5BE9F007" Ref="C?"  Part="1" 
AR Path="/5BE5222A/5BE9F007" Ref="C403"  Part="1" 
F 0 "C403" H 3505 3040 50  0000 L CNN
F 1 "0.1uF" H 3505 2840 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3518 2790 50  0001 C CNN
F 3 "" H 3505 3040 50  0001 C CNN
F 4 "0603" H 3330 3040 50  0000 R CNN "display_footprint"
F 5 "50V" H 3330 2940 50  0000 R CNN "Voltage"
F 6 "X7R" H 3330 2840 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 3905 3440 60  0001 C CNN "Digi-Key PN"
	1    3480 2940
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BEE542D
P 2840 2940
AR Path="/5BAAE10E/5BEE542D" Ref="C?"  Part="1" 
AR Path="/5BE5222A/5BEE542D" Ref="C402"  Part="1" 
F 0 "C402" H 2865 3040 50  0000 L CNN
F 1 "22uF" H 2865 2840 50  0000 L CNN
F 2 "Capacitors_SMD:C_2220" H 2878 2790 50  0001 C CNN
F 3 "" H 2865 3040 50  0001 C CNN
F 4 "445-1453-1-ND" H 3265 3440 60  0001 C CNN "Digi-Key PN"
F 5 "2220" H 2690 3040 50  0000 R CNN "display_footprint"
F 6 "25V" H 2690 2940 50  0000 R CNN "Voltage"
F 7 "X7R" H 2690 2840 50  0000 R CNN "Dielectric"
	1    2840 2940
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R406
U 1 1 5BEEC3B4
P 7010 4570
F 0 "R406" H 6950 4570 50  0000 R CNN
F 1 "13.7k" V 7010 4570 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7010 4570 50  0001 C CNN
F 3 "" H 7010 4570 50  0001 C CNN
F 4 "0603" H 7080 4660 50  0000 L CNN "display_footprint"
F 5 "1%" H 7080 4570 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 7080 4490 50  0000 L CNN "Wattage"
F 7 "P13.7KHCT-ND" H 7310 4970 60  0001 C CNN "Digi-Key PN"
	1    7010 4570
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BEF90C7
P 8450 3440
AR Path="/5BAAE10E/5BEF90C7" Ref="C?"  Part="1" 
AR Path="/5BE5222A/5BEF90C7" Ref="C406"  Part="1" 
F 0 "C406" H 8475 3540 50  0000 L CNN
F 1 "22uF" H 8475 3340 50  0000 L CNN
F 2 "Capacitors_SMD:C_2220" H 8488 3290 50  0001 C CNN
F 3 "" H 8475 3540 50  0001 C CNN
F 4 "445-1453-1-ND" H 8875 3940 60  0001 C CNN "Digi-Key PN"
F 5 "2220" H 8300 3540 50  0000 R CNN "display_footprint"
F 6 "25V" H 8300 3440 50  0000 R CNN "Voltage"
F 7 "X7R" H 8300 3340 50  0000 R CNN "Dielectric"
	1    8450 3440
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BEF9DE0
P 9090 3440
AR Path="/5BAAE10E/5BEF9DE0" Ref="C?"  Part="1" 
AR Path="/5BE5222A/5BEF9DE0" Ref="C407"  Part="1" 
F 0 "C407" H 9115 3540 50  0000 L CNN
F 1 "22uF" H 9115 3340 50  0000 L CNN
F 2 "Capacitors_SMD:C_2220" H 9128 3290 50  0001 C CNN
F 3 "" H 9115 3540 50  0001 C CNN
F 4 "445-1453-1-ND" H 9515 3940 60  0001 C CNN "Digi-Key PN"
F 5 "2220" H 8940 3540 50  0000 R CNN "display_footprint"
F 6 "25V" H 8940 3440 50  0000 R CNN "Voltage"
F 7 "X7R" H 8940 3340 50  0000 R CNN "Dielectric"
	1    9090 3440
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0413
U 1 1 5BEF9E2A
P 9090 3590
F 0 "#PWR0413" H 9090 3340 50  0001 C CNN
F 1 "GND" H 9090 3440 50  0000 C CNN
F 2 "" H 9090 3590 50  0001 C CNN
F 3 "" H 9090 3590 50  0001 C CNN
	1    9090 3590
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9090 3290 9090 3230
Wire Wire Line
	9090 3230 8450 3230
Wire Wire Line
	9090 3150 9090 3230
Connection ~ 9090 3230
$Comp
L Graphic:SYM_ESD_Large #SYM?
U 1 1 5C050F30
P 5760 5160
AR Path="/5BAAE0FA/5C050F30" Ref="#SYM?"  Part="1" 
AR Path="/5BB182B1/5C050F30" Ref="#SYM?"  Part="1" 
AR Path="/5BE5222A/5C050F30" Ref="#SYM401"  Part="1" 
F 0 "#SYM401" H 5760 5360 50  0001 C CNN
F 1 "SYM_ESD_Large" H 5760 4910 50  0001 C CNN
F 2 "" H 5755 5130 50  0001 C CNN
F 3 "~" H 5755 5130 50  0001 C CNN
	1    5760 5160
	1    0    0    -1  
$EndComp
$Comp
L Graphic:SYM_Hot_Large #SYM402
U 1 1 5C064EC3
P 6330 5160
F 0 "#SYM402" H 6330 5360 50  0001 C CNN
F 1 "SYM_Hot_Large" H 6330 4910 50  0001 C CNN
F 2 "" H 6330 4960 50  0001 C CNN
F 3 "~" H 6360 4960 50  0001 C CNN
	1    6330 5160
	1    0    0    -1  
$EndComp
Text Notes 8240 4260 0    50   ~ 0
Designed for 2A Max Iout
Text Notes 550  700  0    100  ~ 20
04. +5V Power Supply
$Comp
L LED_Display_Local_Library:MU_Logo #G401
U 1 1 5BFF2E6E
P 9900 1100
F 0 "#G401" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0401
U 1 1 5C02EDD9
P 9800 3150
F 0 "#FLG0401" H 9800 3225 50  0001 C CNN
F 1 "PWR_FLAG" H 9800 3300 50  0000 C CNN
F 2 "" H 9800 3150 50  0001 C CNN
F 3 "~" H 9800 3150 50  0001 C CNN
	1    9800 3150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0414
U 1 1 5C02EE3D
P 9800 3150
F 0 "#PWR0414" H 9800 3000 50  0001 C CNN
F 1 "+5V" H 9800 3290 50  0000 C CNN
F 2 "" H 9800 3150 50  0001 C CNN
F 3 "" H 9800 3150 50  0001 C CNN
	1    9800 3150
	-1   0    0    1   
$EndComp
$EndSCHEMATC
