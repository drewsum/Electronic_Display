EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 31 31
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
L Device:LED D?
U 1 1 5BF380C5
P 2660 3000
AR Path="/5BB844FD/5BF380C5" Ref="D?"  Part="1" 
AR Path="/5BF346B3/5BF380C5" Ref="D?"  Part="1" 
F 0 "D?" H 2660 3100 50  0000 C CNN
F 1 "Green" V 2690 2810 50  0000 C CNN
F 2 "" H 2660 3000 50  0001 C CNN
F 3 "~" H 2660 3000 50  0001 C CNN
F 4 "0603" V 2610 2820 50  0000 C CNN "foot"
	1    2660 3000
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BF380D0
P 2660 2700
AR Path="/5BAAE1F3/5BF380D0" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5BF380D0" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5BF380D0" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5BF380D0" Ref="R?"  Part="1" 
AR Path="/5BF346B3/5BF380D0" Ref="R?"  Part="1" 
F 0 "R?" H 2560 2700 50  0000 C CNN
F 1 "1k" V 2660 2700 50  0000 C CNN
F 2 "" H 2660 2700 50  0001 C CNN
F 3 "" H 2660 2700 50  0001 C CNN
F 4 "0603" H 2850 2780 50  0000 C CNN "display_footprint"
F 5 "1%" H 2840 2700 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 2870 2630 50  0000 C CNN "Wattage"
F 7 "PN" H 2960 3100 60  0001 C CNN "Digi-Key PN"
	1    2660 2700
	-1   0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF380D7
P 2660 2550
AR Path="/5BB844FD/5BF380D7" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF380D7" Ref="#PWR0546"  Part="1" 
F 0 "#PWR?" H 2660 2400 50  0001 C CNN
F 1 "+3.3V" H 2660 2690 50  0000 C CNN
F 2 "" H 2660 2550 50  0001 C CNN
F 3 "" H 2660 2550 50  0001 C CNN
	1    2660 2550
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:74LVC1G06_Power U?
U 1 1 5BF380DE
P 1920 3310
AR Path="/5BB844FD/5BF380DE" Ref="U?"  Part="1" 
AR Path="/5BF346B3/5BF380DE" Ref="U?"  Part="1" 
F 0 "U?" H 2020 3460 50  0000 L CNN
F 1 "74LVC1G06" H 2020 3210 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 1920 3360 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g06.pdf" H 1920 3310 50  0001 C CNN
F 4 "296-8484-1-ND" H 1920 3310 50  0001 C CNN "Digi-Key PN"
	1    1920 3310
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF380E5
P 1920 3410
AR Path="/5BB844FD/5BF380E5" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF380E5" Ref="#PWR0547"  Part="1" 
F 0 "#PWR?" H 1920 3160 50  0001 C CNN
F 1 "GND" H 1920 3260 50  0000 C CNN
F 2 "" H 1920 3410 50  0001 C CNN
F 3 "" H 1920 3410 50  0001 C CNN
	1    1920 3410
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF380EB
P 1920 3210
AR Path="/5BB844FD/5BF380EB" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF380EB" Ref="#PWR0548"  Part="1" 
F 0 "#PWR?" H 1920 3060 50  0001 C CNN
F 1 "+3.3V" H 1920 3350 50  0000 C CNN
F 2 "" H 1920 3210 50  0001 C CNN
F 3 "" H 1920 3210 50  0001 C CNN
	1    1920 3210
	1    0    0    -1  
$EndComp
Wire Wire Line
	2170 3310 2660 3310
Wire Wire Line
	2660 3310 2660 3150
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BF380F7
P 2270 3900
AR Path="/5BAAE1F3/5BF380F7" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5BF380F7" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5BF380F7" Ref="C?"  Part="1" 
AR Path="/5BB844FD/5BF380F7" Ref="C?"  Part="1" 
AR Path="/5BF346B3/5BF380F7" Ref="C?"  Part="1" 
F 0 "C?" H 2295 4000 50  0000 L CNN
F 1 "0.1uF" H 2295 3800 50  0000 L CNN
F 2 "" H 2308 3750 50  0001 C CNN
F 3 "" H 2295 4000 50  0001 C CNN
F 4 "PN" H 2695 4400 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 2120 4000 50  0000 R CNN "display_footprint"
F 6 "50V" H 2120 3900 50  0000 R CNN "Voltage"
F 7 "X7R" H 2120 3800 50  0000 R CNN "Dielectric"
	1    2270 3900
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF380FE
P 2270 4050
AR Path="/5BE48F98/5BF380FE" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF380FE" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF380FE" Ref="#PWR0549"  Part="1" 
F 0 "#PWR?" H 2270 3800 50  0001 C CNN
F 1 "GND" H 2270 3900 50  0000 C CNN
F 2 "" H 2270 4050 50  0001 C CNN
F 3 "" H 2270 4050 50  0001 C CNN
	1    2270 4050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF38104
P 2270 3750
AR Path="/5BB844FD/5BF38104" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF38104" Ref="#PWR0550"  Part="1" 
F 0 "#PWR?" H 2270 3600 50  0001 C CNN
F 1 "+3.3V" H 2270 3890 50  0000 C CNN
F 2 "" H 2270 3750 50  0001 C CNN
F 3 "" H 2270 3750 50  0001 C CNN
	1    2270 3750
	1    0    0    -1  
$EndComp
Text GLabel 1620 3310 0    50   Input ~ 0
POS12_PGOOD
$Comp
L Device:LED D?
U 1 1 5BF39F18
P 5010 3000
AR Path="/5BB844FD/5BF39F18" Ref="D?"  Part="1" 
AR Path="/5BF346B3/5BF39F18" Ref="D?"  Part="1" 
F 0 "D?" H 5010 3100 50  0000 C CNN
F 1 "Green" V 5040 2810 50  0000 C CNN
F 2 "" H 5010 3000 50  0001 C CNN
F 3 "~" H 5010 3000 50  0001 C CNN
F 4 "0603" V 4960 2820 50  0000 C CNN "foot"
	1    5010 3000
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BF39F23
P 5010 2700
AR Path="/5BAAE1F3/5BF39F23" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5BF39F23" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5BF39F23" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5BF39F23" Ref="R?"  Part="1" 
AR Path="/5BF346B3/5BF39F23" Ref="R?"  Part="1" 
F 0 "R?" H 4910 2700 50  0000 C CNN
F 1 "1k" V 5010 2700 50  0000 C CNN
F 2 "" H 5010 2700 50  0001 C CNN
F 3 "" H 5010 2700 50  0001 C CNN
F 4 "0603" H 5200 2780 50  0000 C CNN "display_footprint"
F 5 "1%" H 5190 2700 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 5220 2630 50  0000 C CNN "Wattage"
F 7 "PN" H 5310 3100 60  0001 C CNN "Digi-Key PN"
	1    5010 2700
	-1   0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF39F2A
P 5010 2550
AR Path="/5BB844FD/5BF39F2A" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF39F2A" Ref="#PWR0551"  Part="1" 
F 0 "#PWR?" H 5010 2400 50  0001 C CNN
F 1 "+3.3V" H 5010 2690 50  0000 C CNN
F 2 "" H 5010 2550 50  0001 C CNN
F 3 "" H 5010 2550 50  0001 C CNN
	1    5010 2550
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:74LVC1G06_Power U?
U 1 1 5BF39F31
P 4270 3310
AR Path="/5BB844FD/5BF39F31" Ref="U?"  Part="1" 
AR Path="/5BF346B3/5BF39F31" Ref="U?"  Part="1" 
F 0 "U?" H 4370 3460 50  0000 L CNN
F 1 "74LVC1G06" H 4370 3210 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 4270 3360 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g06.pdf" H 4270 3310 50  0001 C CNN
F 4 "296-8484-1-ND" H 4270 3310 50  0001 C CNN "Digi-Key PN"
	1    4270 3310
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF39F38
P 4270 3410
AR Path="/5BB844FD/5BF39F38" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF39F38" Ref="#PWR0552"  Part="1" 
F 0 "#PWR?" H 4270 3160 50  0001 C CNN
F 1 "GND" H 4270 3260 50  0000 C CNN
F 2 "" H 4270 3410 50  0001 C CNN
F 3 "" H 4270 3410 50  0001 C CNN
	1    4270 3410
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF39F3E
P 4270 3210
AR Path="/5BB844FD/5BF39F3E" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF39F3E" Ref="#PWR0553"  Part="1" 
F 0 "#PWR?" H 4270 3060 50  0001 C CNN
F 1 "+3.3V" H 4270 3350 50  0000 C CNN
F 2 "" H 4270 3210 50  0001 C CNN
F 3 "" H 4270 3210 50  0001 C CNN
	1    4270 3210
	1    0    0    -1  
$EndComp
Wire Wire Line
	4520 3310 5010 3310
Wire Wire Line
	5010 3310 5010 3150
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BF39F4A
P 4620 3900
AR Path="/5BAAE1F3/5BF39F4A" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5BF39F4A" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5BF39F4A" Ref="C?"  Part="1" 
AR Path="/5BB844FD/5BF39F4A" Ref="C?"  Part="1" 
AR Path="/5BF346B3/5BF39F4A" Ref="C?"  Part="1" 
F 0 "C?" H 4645 4000 50  0000 L CNN
F 1 "0.1uF" H 4645 3800 50  0000 L CNN
F 2 "" H 4658 3750 50  0001 C CNN
F 3 "" H 4645 4000 50  0001 C CNN
F 4 "PN" H 5045 4400 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 4470 4000 50  0000 R CNN "display_footprint"
F 6 "50V" H 4470 3900 50  0000 R CNN "Voltage"
F 7 "X7R" H 4470 3800 50  0000 R CNN "Dielectric"
	1    4620 3900
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF39F51
P 4620 4050
AR Path="/5BE48F98/5BF39F51" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF39F51" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF39F51" Ref="#PWR0554"  Part="1" 
F 0 "#PWR?" H 4620 3800 50  0001 C CNN
F 1 "GND" H 4620 3900 50  0000 C CNN
F 2 "" H 4620 4050 50  0001 C CNN
F 3 "" H 4620 4050 50  0001 C CNN
	1    4620 4050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF39F57
P 4620 3750
AR Path="/5BB844FD/5BF39F57" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF39F57" Ref="#PWR0555"  Part="1" 
F 0 "#PWR?" H 4620 3600 50  0001 C CNN
F 1 "+3.3V" H 4620 3890 50  0000 C CNN
F 2 "" H 4620 3750 50  0001 C CNN
F 3 "" H 4620 3750 50  0001 C CNN
	1    4620 3750
	1    0    0    -1  
$EndComp
Text GLabel 3970 3310 0    50   Input ~ 0
POS3P3_PGOOD
$Comp
L Device:LED D?
U 1 1 5BF3BDA2
P 7390 3000
AR Path="/5BB844FD/5BF3BDA2" Ref="D?"  Part="1" 
AR Path="/5BF346B3/5BF3BDA2" Ref="D?"  Part="1" 
F 0 "D?" H 7390 3100 50  0000 C CNN
F 1 "Green" V 7420 2810 50  0000 C CNN
F 2 "" H 7390 3000 50  0001 C CNN
F 3 "~" H 7390 3000 50  0001 C CNN
F 4 "0603" V 7340 2820 50  0000 C CNN "foot"
	1    7390 3000
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BF3BDAD
P 7390 2700
AR Path="/5BAAE1F3/5BF3BDAD" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5BF3BDAD" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5BF3BDAD" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5BF3BDAD" Ref="R?"  Part="1" 
AR Path="/5BF346B3/5BF3BDAD" Ref="R?"  Part="1" 
F 0 "R?" H 7290 2700 50  0000 C CNN
F 1 "1k" V 7390 2700 50  0000 C CNN
F 2 "" H 7390 2700 50  0001 C CNN
F 3 "" H 7390 2700 50  0001 C CNN
F 4 "0603" H 7580 2780 50  0000 C CNN "display_footprint"
F 5 "1%" H 7570 2700 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 7600 2630 50  0000 C CNN "Wattage"
F 7 "PN" H 7690 3100 60  0001 C CNN "Digi-Key PN"
	1    7390 2700
	-1   0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF3BDB4
P 7390 2550
AR Path="/5BB844FD/5BF3BDB4" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF3BDB4" Ref="#PWR0556"  Part="1" 
F 0 "#PWR?" H 7390 2400 50  0001 C CNN
F 1 "+3.3V" H 7390 2690 50  0000 C CNN
F 2 "" H 7390 2550 50  0001 C CNN
F 3 "" H 7390 2550 50  0001 C CNN
	1    7390 2550
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:74LVC1G06_Power U?
U 1 1 5BF3BDBB
P 6650 3310
AR Path="/5BB844FD/5BF3BDBB" Ref="U?"  Part="1" 
AR Path="/5BF346B3/5BF3BDBB" Ref="U?"  Part="1" 
F 0 "U?" H 6750 3460 50  0000 L CNN
F 1 "74LVC1G06" H 6750 3210 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 6650 3360 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g06.pdf" H 6650 3310 50  0001 C CNN
F 4 "296-8484-1-ND" H 6650 3310 50  0001 C CNN "Digi-Key PN"
	1    6650 3310
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF3BDC2
P 6650 3410
AR Path="/5BB844FD/5BF3BDC2" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF3BDC2" Ref="#PWR0557"  Part="1" 
F 0 "#PWR?" H 6650 3160 50  0001 C CNN
F 1 "GND" H 6650 3260 50  0000 C CNN
F 2 "" H 6650 3410 50  0001 C CNN
F 3 "" H 6650 3410 50  0001 C CNN
	1    6650 3410
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF3BDC8
P 6650 3210
AR Path="/5BB844FD/5BF3BDC8" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF3BDC8" Ref="#PWR0558"  Part="1" 
F 0 "#PWR?" H 6650 3060 50  0001 C CNN
F 1 "+3.3V" H 6650 3350 50  0000 C CNN
F 2 "" H 6650 3210 50  0001 C CNN
F 3 "" H 6650 3210 50  0001 C CNN
	1    6650 3210
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 3310 7390 3310
Wire Wire Line
	7390 3310 7390 3150
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BF3BDD4
P 7000 3900
AR Path="/5BAAE1F3/5BF3BDD4" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5BF3BDD4" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5BF3BDD4" Ref="C?"  Part="1" 
AR Path="/5BB844FD/5BF3BDD4" Ref="C?"  Part="1" 
AR Path="/5BF346B3/5BF3BDD4" Ref="C?"  Part="1" 
F 0 "C?" H 7025 4000 50  0000 L CNN
F 1 "0.1uF" H 7025 3800 50  0000 L CNN
F 2 "" H 7038 3750 50  0001 C CNN
F 3 "" H 7025 4000 50  0001 C CNN
F 4 "PN" H 7425 4400 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 6850 4000 50  0000 R CNN "display_footprint"
F 6 "50V" H 6850 3900 50  0000 R CNN "Voltage"
F 7 "X7R" H 6850 3800 50  0000 R CNN "Dielectric"
	1    7000 3900
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF3BDDB
P 7000 4050
AR Path="/5BE48F98/5BF3BDDB" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF3BDDB" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF3BDDB" Ref="#PWR0559"  Part="1" 
F 0 "#PWR?" H 7000 3800 50  0001 C CNN
F 1 "GND" H 7000 3900 50  0000 C CNN
F 2 "" H 7000 4050 50  0001 C CNN
F 3 "" H 7000 4050 50  0001 C CNN
	1    7000 4050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF3BDE1
P 7000 3750
AR Path="/5BB844FD/5BF3BDE1" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF3BDE1" Ref="#PWR0560"  Part="1" 
F 0 "#PWR?" H 7000 3600 50  0001 C CNN
F 1 "+3.3V" H 7000 3890 50  0000 C CNN
F 2 "" H 7000 3750 50  0001 C CNN
F 3 "" H 7000 3750 50  0001 C CNN
	1    7000 3750
	1    0    0    -1  
$EndComp
Text GLabel 6350 3310 0    50   Input ~ 0
POS5_PGOOD
$Comp
L Device:LED D?
U 1 1 5BF3DCD2
P 9640 3000
AR Path="/5BB844FD/5BF3DCD2" Ref="D?"  Part="1" 
AR Path="/5BF346B3/5BF3DCD2" Ref="D?"  Part="1" 
F 0 "D?" H 9640 3100 50  0000 C CNN
F 1 "Green" V 9670 2810 50  0000 C CNN
F 2 "" H 9640 3000 50  0001 C CNN
F 3 "~" H 9640 3000 50  0001 C CNN
F 4 "0603" V 9590 2820 50  0000 C CNN "foot"
	1    9640 3000
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BF3DCDD
P 9640 2700
AR Path="/5BAAE1F3/5BF3DCDD" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5BF3DCDD" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5BF3DCDD" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5BF3DCDD" Ref="R?"  Part="1" 
AR Path="/5BF346B3/5BF3DCDD" Ref="R?"  Part="1" 
F 0 "R?" H 9540 2700 50  0000 C CNN
F 1 "1k" V 9640 2700 50  0000 C CNN
F 2 "" H 9640 2700 50  0001 C CNN
F 3 "" H 9640 2700 50  0001 C CNN
F 4 "0603" H 9830 2780 50  0000 C CNN "display_footprint"
F 5 "1%" H 9820 2700 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 9850 2630 50  0000 C CNN "Wattage"
F 7 "PN" H 9940 3100 60  0001 C CNN "Digi-Key PN"
	1    9640 2700
	-1   0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF3DCE4
P 9640 2550
AR Path="/5BB844FD/5BF3DCE4" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF3DCE4" Ref="#PWR0561"  Part="1" 
F 0 "#PWR?" H 9640 2400 50  0001 C CNN
F 1 "+3.3V" H 9640 2690 50  0000 C CNN
F 2 "" H 9640 2550 50  0001 C CNN
F 3 "" H 9640 2550 50  0001 C CNN
	1    9640 2550
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:74LVC1G06_Power U?
U 1 1 5BF3DCEB
P 8900 3310
AR Path="/5BB844FD/5BF3DCEB" Ref="U?"  Part="1" 
AR Path="/5BF346B3/5BF3DCEB" Ref="U?"  Part="1" 
F 0 "U?" H 9000 3460 50  0000 L CNN
F 1 "74LVC1G06" H 9000 3210 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 8900 3360 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g06.pdf" H 8900 3310 50  0001 C CNN
F 4 "296-8484-1-ND" H 8900 3310 50  0001 C CNN "Digi-Key PN"
	1    8900 3310
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF3DCF2
P 8900 3410
AR Path="/5BB844FD/5BF3DCF2" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF3DCF2" Ref="#PWR0562"  Part="1" 
F 0 "#PWR?" H 8900 3160 50  0001 C CNN
F 1 "GND" H 8900 3260 50  0000 C CNN
F 2 "" H 8900 3410 50  0001 C CNN
F 3 "" H 8900 3410 50  0001 C CNN
	1    8900 3410
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF3DCF8
P 8900 3210
AR Path="/5BB844FD/5BF3DCF8" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF3DCF8" Ref="#PWR0563"  Part="1" 
F 0 "#PWR?" H 8900 3060 50  0001 C CNN
F 1 "+3.3V" H 8900 3350 50  0000 C CNN
F 2 "" H 8900 3210 50  0001 C CNN
F 3 "" H 8900 3210 50  0001 C CNN
	1    8900 3210
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 3310 9640 3310
Wire Wire Line
	9640 3310 9640 3150
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BF3DD04
P 9250 3900
AR Path="/5BAAE1F3/5BF3DD04" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5BF3DD04" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5BF3DD04" Ref="C?"  Part="1" 
AR Path="/5BB844FD/5BF3DD04" Ref="C?"  Part="1" 
AR Path="/5BF346B3/5BF3DD04" Ref="C?"  Part="1" 
F 0 "C?" H 9275 4000 50  0000 L CNN
F 1 "0.1uF" H 9275 3800 50  0000 L CNN
F 2 "" H 9288 3750 50  0001 C CNN
F 3 "" H 9275 4000 50  0001 C CNN
F 4 "PN" H 9675 4400 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 9100 4000 50  0000 R CNN "display_footprint"
F 6 "50V" H 9100 3900 50  0000 R CNN "Voltage"
F 7 "X7R" H 9100 3800 50  0000 R CNN "Dielectric"
	1    9250 3900
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF3DD0B
P 9250 4050
AR Path="/5BE48F98/5BF3DD0B" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF3DD0B" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF3DD0B" Ref="#PWR0564"  Part="1" 
F 0 "#PWR?" H 9250 3800 50  0001 C CNN
F 1 "GND" H 9250 3900 50  0000 C CNN
F 2 "" H 9250 4050 50  0001 C CNN
F 3 "" H 9250 4050 50  0001 C CNN
	1    9250 4050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF3DD11
P 9250 3750
AR Path="/5BB844FD/5BF3DD11" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5BF3DD11" Ref="#PWR0565"  Part="1" 
F 0 "#PWR?" H 9250 3600 50  0001 C CNN
F 1 "+3.3V" H 9250 3890 50  0000 C CNN
F 2 "" H 9250 3750 50  0001 C CNN
F 3 "" H 9250 3750 50  0001 C CNN
	1    9250 3750
	1    0    0    -1  
$EndComp
Text GLabel 8600 3310 0    50   Input ~ 0
POS5P_PGOOD
$EndSCHEMATC
