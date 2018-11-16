EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 28 32
Title ""
Date ""
Rev ""
Comp ""
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
U 1 1 5BB875B8
P 4560 1340
F 0 "C?" H 4585 1440 50  0000 L CNN
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
U 1 1 5BB87C09
P 5180 2020
F 0 "#PWR?" H 5180 1770 50  0001 C CNN
F 1 "GND" H 5180 1870 50  0000 C CNN
F 2 "" H 5180 2020 50  0001 C CNN
F 3 "" H 5180 2020 50  0001 C CNN
	1    5180 2020
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:SiC779 U?
U 1 1 5BB8C7AD
P 6080 2810
F 0 "U?" H 6080 960 50  0000 C CNN
F 1 "SiC779" H 6080 4660 50  0000 C CNN
F 2 "Custom Footprints Library:MLP66-40_6x6mm_Pitch0.5mm" H 4430 3560 50  0001 C CNN
F 3 "http://www.vishay.com/docs/67538/sic779.pdf" H 6080 2810 50  0001 C CNN
F 4 "SIC779CD-T1-GE3CT-ND" H 6080 2810 50  0001 C CNN "Digi-Key PN"
	1    6080 2810
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BB8CE1A
P 4560 1490
F 0 "#PWR?" H 4560 1240 50  0001 C CNN
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
U 1 1 5BB9709A
P 6810 4590
F 0 "#PWR?" H 6810 4340 50  0001 C CNN
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
U 1 1 5BB973E8
P 5350 4590
F 0 "#PWR?" H 5350 4340 50  0001 C CNN
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
U 1 1 5BB98C10
P 7440 3310
F 0 "L?" V 7390 3310 50  0000 C CNN
F 1 "0.47uH" V 7515 3310 50  0000 C CNN
F 2 "Inductors_SMD:L_Vishay_IHLP-4040" H 7440 3310 50  0001 C CNN
F 3 "" H 7440 3310 50  0001 C CNN
F 4 "541-2595-1-ND" H 7440 3310 50  0001 C CNN "Digi-Key PN"
F 5 "IHLP4040" V 7590 3310 50  0000 C CNN "display_footprint"
F 6 "30A" V 7690 3310 50  0000 C CNN "Ampacity"
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
U 1 1 5BB9AE0E
P 6980 2470
F 0 "R?" H 6880 2470 50  0000 R CNN
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
U 1 1 5BB9AE19
P 6980 2850
F 0 "C?" H 7005 2950 50  0000 L CNN
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
Wire Wire Line
	7290 3310 7190 3310
Connection ~ 6810 3310
Connection ~ 7190 3310
Wire Wire Line
	7190 3310 6810 3310
Wire Wire Line
	7690 3310 7590 3310
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BBBB2FC
P 7190 3770
F 0 "R?" H 7290 3920 50  0000 L CNN
F 1 "1.4k" V 7190 3770 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7190 3770 50  0001 C CNN
F 3 "" H 7190 3770 50  0001 C CNN
F 4 "P1.40KHCT-ND" H 7490 4170 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 7290 3850 50  0000 L CNN "display_footprint"
F 6 "1%" H 7290 3770 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 7290 3690 50  0000 L CNN "Wattage"
	1    7190 3770
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BBBEAA9
P 7440 4040
F 0 "C?" V 6916 4040 50  0000 C CNN
F 1 "0.22uF" V 7007 3910 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7478 3890 50  0001 C CNN
F 3 "" H 7465 4140 50  0001 C CNN
F 4 "490-5402-1-ND" H 7865 4540 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 7098 4040 50  0000 C CNN "display_footprint"
F 6 "50V" V 7189 4040 50  0000 C CNN "Voltage"
F 7 "X7R" V 7280 4040 50  0000 C CNN "Dielectric"
	1    7440 4040
	0    1    1    0   
$EndComp
Wire Wire Line
	7190 3310 7190 3620
Wire Wire Line
	7190 3920 7190 4040
Wire Wire Line
	7190 4040 7290 4040
Wire Wire Line
	7590 4040 7690 4040
Wire Wire Line
	7690 3310 7690 4040
Wire Wire Line
	7390 4200 7190 4200
Wire Wire Line
	7190 4200 7190 4040
Connection ~ 7190 4040
Wire Wire Line
	7690 4040 7690 4200
Wire Wire Line
	7690 4200 7490 4200
Connection ~ 7690 4040
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BBCE509
P 7880 1340
F 0 "C?" H 7905 1440 50  0000 L CNN
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
U 1 1 5BBCE794
P 7280 1490
F 0 "#PWR?" H 7280 1240 50  0001 C CNN
F 1 "GND" H 7280 1340 50  0000 C CNN
F 2 "" H 7280 1490 50  0001 C CNN
F 3 "" H 7280 1490 50  0001 C CNN
	1    7280 1490
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BBCE7C6
P 7880 1490
F 0 "#PWR?" H 7880 1240 50  0001 C CNN
F 1 "GND" H 7880 1340 50  0000 C CNN
F 2 "" H 7880 1490 50  0001 C CNN
F 3 "" H 7880 1490 50  0001 C CNN
	1    7880 1490
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BBCE811
P 8480 1490
F 0 "#PWR?" H 8480 1240 50  0001 C CNN
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
U 1 1 5BBD7D44
P 8420 3540
F 0 "C?" H 8445 3640 50  0000 L CNN
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
U 1 1 5BBD7D6C
P 8420 3690
F 0 "#PWR?" H 8420 3440 50  0001 C CNN
F 1 "GND" H 8420 3540 50  0000 C CNN
F 2 "" H 8420 3690 50  0001 C CNN
F 3 "" H 8420 3690 50  0001 C CNN
	1    8420 3690
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BBD7D72
P 9020 3690
F 0 "#PWR?" H 9020 3440 50  0001 C CNN
F 1 "GND" H 9020 3540 50  0000 C CNN
F 2 "" H 9020 3690 50  0001 C CNN
F 3 "" H 9020 3690 50  0001 C CNN
	1    9020 3690
	1    0    0    -1  
$EndComp
Connection ~ 7690 3310
Wire Wire Line
	8420 3390 8420 3310
Connection ~ 8420 3310
Wire Wire Line
	8420 3310 7940 3310
Wire Wire Line
	9020 3390 9020 3310
Wire Wire Line
	9020 3310 8420 3310
$Comp
L power:+5V #PWR?
U 1 1 5BBF55EB
P 9620 3150
F 0 "#PWR?" H 9620 3000 50  0001 C CNN
F 1 "+5V" H 9620 3290 50  0000 C CNN
F 2 "" H 9620 3150 50  0001 C CNN
F 3 "" H 9620 3150 50  0001 C CNN
	1    9620 3150
	1    0    0    -1  
$EndComp
Connection ~ 7940 3310
Wire Wire Line
	7940 3310 7690 3310
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BC4AD64
P 7940 5110
F 0 "R?" H 7840 5110 50  0000 R CNN
F 1 "100k" V 7940 5110 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7940 5110 50  0001 C CNN
F 3 "" H 7940 5110 50  0001 C CNN
F 4 "P100KHCT-ND" H 8240 5510 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 8040 5190 50  0000 L CNN "display_footprint"
F 6 "1%" H 8040 5110 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 8040 5030 50  0000 L CNN "Wattage"
	1    7940 5110
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC4F0D5
P 7940 5890
F 0 "#PWR?" H 7940 5640 50  0001 C CNN
F 1 "GND" H 7940 5740 50  0000 C CNN
F 2 "" H 7940 5890 50  0001 C CNN
F 3 "" H 7940 5890 50  0001 C CNN
	1    7940 5890
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BC8C461
P 3310 5380
F 0 "C?" H 3335 5480 50  0000 L CNN
F 1 "2200pF" H 3335 5280 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3348 5230 50  0001 C CNN
F 3 "" H 3335 5480 50  0001 C CNN
F 4 "490-4968-1-ND" H 3735 5880 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 3160 5480 50  0000 R CNN "display_footprint"
F 6 "50V" H 3160 5380 50  0000 R CNN "Voltage"
F 7 "NP0" H 3160 5280 50  0000 R CNN "Dielectric"
	1    3310 5380
	1    0    0    1   
$EndComp
Wire Wire Line
	3310 5530 3310 5690
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BC913E8
P 3850 5610
F 0 "C?" H 3875 5710 50  0000 L CNN
F 1 "100pF" H 3875 5510 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3888 5460 50  0001 C CNN
F 3 "" H 3875 5710 50  0001 C CNN
F 4 "490-4767-1-ND" H 4275 6110 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 3700 5710 50  0000 R CNN "display_footprint"
F 6 "50V" H 3700 5610 50  0000 R CNN "Voltage"
F 7 "NP0" H 3700 5510 50  0000 R CNN "Dielectric"
	1    3850 5610
	1    0    0    1   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BC9167C
P 3310 4320
F 0 "C?" H 3335 4420 50  0000 L CNN
F 1 "3300pF" H 3335 4220 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3348 4170 50  0001 C CNN
F 3 "" H 3335 4420 50  0001 C CNN
F 4 "399-9066-1-ND" H 3735 4820 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 3160 4420 50  0000 R CNN "display_footprint"
F 6 "50V" H 3160 4320 50  0000 R CNN "Voltage"
F 7 "NP0" H 3160 4220 50  0000 R CNN "Dielectric"
	1    3310 4320
	1    0    0    -1  
$EndComp
Wire Wire Line
	3310 4470 3310 4630
$Comp
L LED_Display_Local_Library:LTC7851UHH U?
U 2 1 5BCC0888
P 2510 4210
F 0 "U?" H 2910 2160 50  0000 R CNN
F 1 "LTC7851UHH" H 2510 6260 50  0000 C CNN
F 2 "Custom Footprints Library:QFN-58-1EP_9x5mm_Pitch0.4mm" H -140 4910 50  0001 C CNN
F 3 "http://www.analog.com/media/en/technical-documentation/data-sheets/LTC7851.pdf" H 2510 4210 50  0001 C CNN
F 4 "LTC7851IUHH#PBF-ND" H 2510 4210 50  0001 C CNN "Digi-Key PN"
	2    2510 4210
	1    0    0    -1  
$EndComp
Wire Wire Line
	3310 4170 3310 4110
Wire Wire Line
	3310 4110 3060 4110
Wire Wire Line
	3850 4470 3850 4110
Wire Wire Line
	3850 4110 3310 4110
Connection ~ 3310 4110
Wire Wire Line
	3310 5990 3310 6110
Wire Wire Line
	3310 6110 3060 6110
Wire Wire Line
	3850 5760 3850 6110
Wire Wire Line
	3850 6110 3310 6110
Connection ~ 3310 6110
Text GLabel 3930 4110 2    50   UnSpc ~ 0
POS5_VOSNS
Wire Wire Line
	3850 4110 3930 4110
Connection ~ 3850 4110
Text GLabel 3930 6110 2    50   UnSpc ~ 0
POS5_COMP
Wire Wire Line
	3930 6110 3850 6110
Connection ~ 3850 6110
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BDE1E17
P 1710 6340
F 0 "R?" H 1610 6340 50  0000 R CNN
F 1 "66.5k" V 1710 6340 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 1710 6340 50  0001 C CNN
F 3 "" H 1710 6340 50  0001 C CNN
F 4 "RMCF0603FT66K5CT-ND" H 2010 6740 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 1810 6420 50  0000 L CNN "display_footprint"
F 6 "1%" H 1810 6340 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 1810 6260 50  0000 L CNN "Wattage"
	1    1710 6340
	1    0    0    -1  
$EndComp
Wire Wire Line
	1710 6190 1710 6110
$Comp
L power:GND #PWR?
U 1 1 5BDF03AF
P 1710 6490
F 0 "#PWR?" H 1710 6240 50  0001 C CNN
F 1 "GND" H 1710 6340 50  0000 C CNN
F 2 "" H 1710 6490 50  0001 C CNN
F 3 "" H 1710 6490 50  0001 C CNN
	1    1710 6490
	1    0    0    -1  
$EndComp
Wire Wire Line
	1710 6110 1960 6110
Wire Wire Line
	1960 5510 1710 5510
Wire Wire Line
	1710 5510 1710 5590
$Comp
L power:GND #PWR?
U 1 1 5BE15469
P 1710 5890
F 0 "#PWR?" H 1710 5640 50  0001 C CNN
F 1 "GND" H 1710 5740 50  0000 C CNN
F 2 "" H 1710 5890 50  0001 C CNN
F 3 "" H 1710 5890 50  0001 C CNN
	1    1710 5890
	1    0    0    -1  
$EndComp
Wire Wire Line
	1960 4910 1710 4910
Wire Wire Line
	1710 4910 1710 4990
$Comp
L power:GND #PWR?
U 1 1 5BE155FF
P 1710 5290
F 0 "#PWR?" H 1710 5040 50  0001 C CNN
F 1 "GND" H 1710 5140 50  0000 C CNN
F 2 "" H 1710 5290 50  0001 C CNN
F 3 "" H 1710 5290 50  0001 C CNN
	1    1710 5290
	1    0    0    -1  
$EndComp
Text GLabel 1550 4910 0    50   UnSpc ~ 0
POS5_SS
Connection ~ 1710 4910
Text GLabel 1550 5510 0    50   UnSpc ~ 0
POS5_IAVG
Connection ~ 1710 5510
Text GLabel 1550 6110 0    50   UnSpc ~ 0
POS5_ILIM
Connection ~ 1710 6110
Wire Wire Line
	1550 4910 1710 4910
Wire Wire Line
	1550 5510 1710 5510
Wire Wire Line
	1550 6110 1710 6110
$Comp
L Custom_Library:+5.5V_MNG #PWR?
U 1 1 5BBB1D38
P 4560 1030
F 0 "#PWR?" H 4560 880 50  0001 C CNN
F 1 "+5.5V_MNG" H 4560 1170 50  0000 C CNN
F 2 "" H 4560 1030 50  0001 C CNN
F 3 "" H 4560 1030 50  0001 C CNN
	1    4560 1030
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BBF5660
P 5180 1870
F 0 "C?" H 5205 1970 50  0000 L CNN
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
U 1 1 5BBF579B
P 5180 1340
F 0 "R?" H 5080 1340 50  0000 R CNN
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
U 1 1 5BBF5BBC
P 8480 1030
F 0 "#PWR?" H 8480 880 50  0001 C CNN
F 1 "+12V" H 8480 1170 50  0000 C CNN
F 2 "" H 8480 1030 50  0001 C CNN
F 3 "" H 8480 1030 50  0001 C CNN
	1    8480 1030
	1    0    0    -1  
$EndComp
Wire Wire Line
	8480 1030 8480 1110
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BBFEF87
P 7940 4730
F 0 "R?" H 7840 4730 50  0000 R CNN
F 1 "0" V 7940 4730 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7940 4730 50  0001 C CNN
F 3 "" H 7940 4730 50  0001 C CNN
F 4 "YAG3351CT-ND" H 8240 5130 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 8040 4810 50  0000 L CNN "display_footprint"
F 6 "1%" H 8040 4730 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 8040 4650 50  0000 L CNN "Wattage"
	1    7940 4730
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7940 4960 7940 4920
Wire Wire Line
	7390 5440 7390 5810
Text GLabel 8020 4920 2    50   UnSpc ~ 0
LOOP_TAP
Wire Wire Line
	8020 4920 7940 4920
Connection ~ 7940 4920
Wire Wire Line
	7940 4920 7940 4880
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BC2428E
P 7280 1340
F 0 "C?" H 7305 1440 50  0000 L CNN
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
U 1 1 5BC70CA8
P 9620 3540
F 0 "C?" H 9645 3640 50  0000 L CNN
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
U 1 1 5BC8532D
P 9620 3690
F 0 "#PWR?" H 9620 3440 50  0001 C CNN
F 1 "GND" H 9620 3540 50  0000 C CNN
F 2 "" H 9620 3690 50  0001 C CNN
F 3 "" H 9620 3690 50  0001 C CNN
	1    9620 3690
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BC8633B
P 9020 3540
F 0 "C?" H 9045 3640 50  0000 L CNN
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
U 1 1 5BC8FEA3
P 8480 1340
F 0 "C?" H 8505 1440 50  0000 L CNN
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
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BC9933B
P 7940 5580
F 0 "R?" H 7840 5580 50  0000 R CNN
F 1 "13.7k" V 7940 5580 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7940 5580 50  0001 C CNN
F 3 "" H 7940 5580 50  0001 C CNN
F 4 "P13.7KHCT-ND" H 8240 5980 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 8040 5660 50  0000 L CNN "display_footprint"
F 6 "1%" H 8040 5580 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 8040 5500 50  0000 L CNN "Wattage"
	1    7940 5580
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BCA05EA
P 3850 4620
F 0 "R?" H 3750 4620 50  0000 R CNN
F 1 "10k" V 3850 4620 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3850 4620 50  0001 C CNN
F 3 "" H 3850 4620 50  0001 C CNN
F 4 "RHM10KADCT-ND" H 4150 5020 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 3950 4700 50  0000 L CNN "display_footprint"
F 6 "1%" H 3950 4620 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 3950 4540 50  0000 L CNN "Wattage"
	1    3850 4620
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BCA086C
P 3310 4780
F 0 "R?" H 3210 4780 50  0000 R CNN
F 1 "320" V 3310 4780 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3310 4780 50  0001 C CNN
F 3 "" H 3310 4780 50  0001 C CNN
F 4 "541-4544-1-ND" H 3610 5180 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 3410 4860 50  0000 L CNN "display_footprint"
F 6 "1%" H 3410 4780 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 3410 4700 50  0000 L CNN "Wattage"
	1    3310 4780
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BCA08FE
P 3310 5840
F 0 "R?" H 3210 5840 50  0000 R CNN
F 1 "6.04k" V 3310 5840 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3310 5840 50  0001 C CNN
F 3 "" H 3310 5840 50  0001 C CNN
F 4 "311-6.04KHRCT-ND" H 3610 6240 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 3410 5920 50  0000 L CNN "display_footprint"
F 6 "1%" H 3410 5840 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 3410 5760 50  0000 L CNN "Wattage"
	1    3310 5840
	-1   0    0    1   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BCB3994
P 1710 5740
F 0 "C?" H 1735 5840 50  0000 L CNN
F 1 "100pF" H 1735 5640 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 1748 5590 50  0001 C CNN
F 3 "" H 1735 5840 50  0001 C CNN
F 4 "490-4767-1-ND" H 2135 6240 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 1560 5840 50  0000 R CNN "display_footprint"
F 6 "50V" H 1560 5740 50  0000 R CNN "Voltage"
F 7 "NP0" H 1560 5640 50  0000 R CNN "Dielectric"
	1    1710 5740
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BCC1565
P 1710 5140
F 0 "C?" H 1735 5240 50  0000 L CNN
F 1 "100pF" H 1735 5040 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 1748 4990 50  0001 C CNN
F 3 "" H 1735 5240 50  0001 C CNN
F 4 "490-4767-1-ND" H 2135 5640 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 1560 5240 50  0000 R CNN "display_footprint"
F 6 "50V" H 1560 5140 50  0000 R CNN "Voltage"
F 7 "NP0" H 1560 5040 50  0000 R CNN "Dielectric"
	1    1710 5140
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7940 5260 7940 5340
Wire Wire Line
	3060 2310 5430 2310
Wire Wire Line
	3060 3910 4810 3910
Wire Wire Line
	3060 4010 4710 4010
Wire Wire Line
	4810 5340 7940 5340
Connection ~ 7940 5340
Wire Wire Line
	7940 5340 7940 5430
Wire Wire Line
	4710 5440 7390 5440
Wire Wire Line
	7940 3310 7940 4580
Wire Wire Line
	5010 5140 7490 5140
Wire Wire Line
	7490 4200 7490 5140
Wire Wire Line
	5110 5040 7390 5040
Wire Wire Line
	7390 4200 7390 5040
Wire Wire Line
	4710 4010 4710 5440
Wire Wire Line
	4810 3910 4810 5340
Wire Wire Line
	5110 3310 5110 5040
Wire Wire Line
	3060 3310 5110 3310
Wire Wire Line
	5010 3410 5010 5140
Wire Wire Line
	3060 3410 5010 3410
Wire Wire Line
	3060 5110 3310 5110
Wire Wire Line
	3310 4930 3310 5110
Wire Wire Line
	3310 5110 3850 5110
Wire Wire Line
	3850 4770 3850 5110
Connection ~ 3310 5110
Wire Wire Line
	3310 5230 3310 5110
Wire Wire Line
	3850 5460 3850 5110
Connection ~ 3850 5110
Wire Wire Line
	7940 5730 7940 5810
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BD013D0
P 7680 5810
F 0 "R?" V 7290 5810 50  0000 C CNN
F 1 "0" V 7680 5810 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7680 5810 50  0001 C CNN
F 3 "" H 7680 5810 50  0001 C CNN
F 4 "311-0.0GRCT-ND" H 7980 6210 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 7383 5810 50  0000 C CNN "display_footprint"
F 6 "1%" V 7474 5810 50  0000 C CNN "Tolerance"
F 7 "1/10W" V 7565 5810 50  0000 C CNN "Wattage"
	1    7680 5810
	0    1    -1   0   
$EndComp
Wire Wire Line
	7830 5810 7940 5810
Connection ~ 7940 5810
Wire Wire Line
	7940 5810 7940 5890
Wire Wire Line
	7530 5810 7390 5810
Text Label 3160 3310 0    50   ~ 0
POS5_ISNS1_+
Text Label 3160 3410 0    50   ~ 0
POS5_ISNS1_-
Text Label 3160 3910 0    50   ~ 0
POS5_VSNS1_+
Text Label 3160 4010 0    50   ~ 0
POS5_VSNS1_-
Text Notes 3270 3670 0    50   ~ 0
Route as diff pairs
Wire Wire Line
	6730 4110 6810 4110
Wire Wire Line
	6810 4110 6810 4010
Connection ~ 6810 4010
Text Notes 540  690  0    100  ~ 20
+5V Phase 1
NoConn ~ 5430 2810
NoConn ~ 5430 2910
NoConn ~ 5430 3110
$Comp
L Custom_Library:+5.5V_MNG #PWR?
U 1 1 5BCCA9E9
P 5430 2510
F 0 "#PWR?" H 5430 2360 50  0001 C CNN
F 1 "+5.5V_MNG" V 5430 2650 50  0000 L CNN
F 2 "" H 5430 2510 50  0001 C CNN
F 3 "" H 5430 2510 50  0001 C CNN
	1    5430 2510
	0    -1   -1   0   
$EndComp
$EndSCHEMATC