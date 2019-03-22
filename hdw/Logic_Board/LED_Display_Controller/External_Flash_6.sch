EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 23 32
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
L LED_Display_Local_Library:SST25PF020B U?
U 1 1 5BBEA3D6
P 6080 3650
AR Path="/5BB2595E/5BBEA3D6" Ref="U?"  Part="1" 
AR Path="/5BB53D61/5BBEA3D6" Ref="U2301"  Part="1" 
F 0 "U2301" H 5830 3990 50  0000 C CNN
F 1 "SST25PF020B" H 6110 3990 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 6080 3150 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20005135B.pdf" H 6080 3650 50  0001 C CNN
F 4 "SST25PF020B-80-4C-SAE-TCT-ND" H 6030 4190 40  0001 C CNN "Digi-Key PN"
	1    6080 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BBEA3DD
P 6080 4050
AR Path="/5BB2595E/5BBEA3DD" Ref="#PWR?"  Part="1" 
AR Path="/5BB53D61/5BBEA3DD" Ref="#PWR02307"  Part="1" 
F 0 "#PWR02307" H 6080 3800 50  0001 C CNN
F 1 "GND" H 6080 3900 50  0000 C CNN
F 2 "" H 6080 4050 50  0001 C CNN
F 3 "" H 6080 4050 50  0001 C CNN
	1    6080 4050
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BBEA3ED
P 5330 4320
AR Path="/5BB2595E/5BBEA3ED" Ref="R?"  Part="1" 
AR Path="/5BB53D61/5BBEA3ED" Ref="R2310"  Part="1" 
F 0 "R2310" H 5270 4320 50  0000 R CNN
F 1 "10k" V 5330 4320 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 5330 4320 50  0001 C CNN
F 3 "" H 5330 4320 50  0001 C CNN
F 4 "0603" H 5410 4400 50  0000 L CNN "display_footprint"
F 5 "1%" H 5410 4320 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 5410 4240 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 5630 4720 60  0001 C CNN "Digi-Key PN"
	1    5330 4320
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BBEA3F8
P 4520 4320
AR Path="/5BB2595E/5BBEA3F8" Ref="R?"  Part="1" 
AR Path="/5BB53D61/5BBEA3F8" Ref="R2308"  Part="1" 
F 0 "R2308" H 4460 4320 50  0000 R CNN
F 1 "10k" V 4520 4320 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 4520 4320 50  0001 C CNN
F 3 "" H 4520 4320 50  0001 C CNN
F 4 "0603" H 4600 4400 50  0000 L CNN "display_footprint"
F 5 "1%" H 4600 4320 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 4600 4240 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 4820 4720 60  0001 C CNN "Digi-Key PN"
	1    4520 4320
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BBEA403
P 5110 3130
AR Path="/5BB2595E/5BBEA403" Ref="R?"  Part="1" 
AR Path="/5BB53D61/5BBEA403" Ref="R2309"  Part="1" 
F 0 "R2309" H 5050 3130 50  0000 R CNN
F 1 "10k" V 5110 3130 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 5110 3130 50  0001 C CNN
F 3 "" H 5110 3130 50  0001 C CNN
F 4 "0603" H 5190 3210 50  0000 L CNN "display_footprint"
F 5 "1%" H 5190 3130 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 5190 3050 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 5410 3530 60  0001 C CNN "Digi-Key PN"
	1    5110 3130
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BBEA40E
P 4520 3130
AR Path="/5BB2595E/5BBEA40E" Ref="R?"  Part="1" 
AR Path="/5BB53D61/5BBEA40E" Ref="R2307"  Part="1" 
F 0 "R2307" H 4460 3130 50  0000 R CNN
F 1 "10k" V 4520 3130 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 4520 3130 50  0001 C CNN
F 3 "" H 4520 3130 50  0001 C CNN
F 4 "0603" H 4600 3210 50  0000 L CNN "display_footprint"
F 5 "1%" H 4600 3130 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 4600 3050 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 4820 3530 60  0001 C CNN "Digi-Key PN"
	1    4520 3130
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BBEA419
P 3930 3130
AR Path="/5BB2595E/5BBEA419" Ref="R?"  Part="1" 
AR Path="/5BB53D61/5BBEA419" Ref="R2306"  Part="1" 
F 0 "R2306" H 3870 3130 50  0000 R CNN
F 1 "10k" V 3930 3130 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3930 3130 50  0001 C CNN
F 3 "" H 3930 3130 50  0001 C CNN
F 4 "0603" H 4010 3210 50  0000 L CNN "display_footprint"
F 5 "1%" H 4010 3130 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 4010 3050 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 4230 3530 60  0001 C CNN "Digi-Key PN"
	1    3930 3130
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BBEA424
P 6750 3850
AR Path="/5BB2595E/5BBEA424" Ref="R?"  Part="1" 
AR Path="/5BB53D61/5BBEA424" Ref="R2311"  Part="1" 
F 0 "R2311" H 6690 3850 50  0000 R CNN
F 1 "10k" V 6750 3850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 6750 3850 50  0001 C CNN
F 3 "" H 6750 3850 50  0001 C CNN
F 4 "0603" H 6830 3930 50  0000 L CNN "display_footprint"
F 5 "1%" H 6830 3850 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 6830 3770 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 7050 4250 60  0001 C CNN "Digi-Key PN"
	1    6750 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BBEA42B
P 4520 4470
AR Path="/5BB2595E/5BBEA42B" Ref="#PWR?"  Part="1" 
AR Path="/5BB53D61/5BBEA42B" Ref="#PWR02303"  Part="1" 
F 0 "#PWR02303" H 4520 4220 50  0001 C CNN
F 1 "GND" H 4520 4320 50  0000 C CNN
F 2 "" H 4520 4470 50  0001 C CNN
F 3 "" H 4520 4470 50  0001 C CNN
	1    4520 4470
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BBEA431
P 5330 4470
AR Path="/5BB2595E/5BBEA431" Ref="#PWR?"  Part="1" 
AR Path="/5BB53D61/5BBEA431" Ref="#PWR02305"  Part="1" 
F 0 "#PWR02305" H 5330 4220 50  0001 C CNN
F 1 "GND" H 5330 4320 50  0000 C CNN
F 2 "" H 5330 4470 50  0001 C CNN
F 3 "" H 5330 4470 50  0001 C CNN
	1    5330 4470
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BBEA437
P 6750 4000
AR Path="/5BB2595E/5BBEA437" Ref="#PWR?"  Part="1" 
AR Path="/5BB53D61/5BBEA437" Ref="#PWR02310"  Part="1" 
F 0 "#PWR02310" H 6750 3750 50  0001 C CNN
F 1 "GND" H 6750 3850 50  0000 C CNN
F 2 "" H 6750 4000 50  0001 C CNN
F 3 "" H 6750 4000 50  0001 C CNN
	1    6750 4000
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BBEA453
P 3420 3450
AR Path="/5BB2595E/5BBEA453" Ref="R?"  Part="1" 
AR Path="/5BB53D61/5BBEA453" Ref="R2301"  Part="1" 
F 0 "R2301" V 3380 3580 50  0000 L CNN
F 1 "100" V 3420 3450 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3420 3450 50  0001 C CNN
F 3 "" H 3420 3450 50  0001 C CNN
F 4 "0603" V 3520 3450 50  0001 C CNN "display_footprint"
F 5 "1%" V 3620 3450 50  0001 C CNN "Tolerance"
F 6 "1/10W" V 3720 3450 50  0001 C CNN "Wattage"
F 7 "A106047CT-ND" H 3720 3850 60  0001 C CNN "Digi-Key PN"
	1    3420 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	3570 3750 4520 3750
Wire Wire Line
	3570 3850 4520 3850
Wire Wire Line
	3570 3450 5330 3450
Wire Wire Line
	5680 3550 5110 3550
Wire Wire Line
	5110 3550 5110 3280
Wire Wire Line
	5330 3450 5330 4170
Connection ~ 5330 3450
Wire Wire Line
	5330 3450 5680 3450
Wire Wire Line
	4520 4170 4520 3850
Wire Wire Line
	4520 3280 4520 3750
Connection ~ 4520 3750
Wire Wire Line
	4520 3750 5680 3750
Wire Wire Line
	3930 3280 3930 3650
Wire Wire Line
	3930 3650 5680 3650
Connection ~ 3930 3650
Text GLabel 3270 3450 0    50   Input ~ 0
FLASH_MOSI
Text GLabel 3270 3750 0    40   Input ~ 0
~FLASH_CE6
Text GLabel 3270 3850 0    50   Input ~ 0
FLASH_SCK
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BBEA480
P 7130 3450
AR Path="/5BB2595E/5BBEA480" Ref="R?"  Part="1" 
AR Path="/5BB53D61/5BBEA480" Ref="R2312"  Part="1" 
F 0 "R2312" V 7030 3450 50  0000 C CNN
F 1 "100" V 7130 3450 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7130 3450 50  0001 C CNN
F 3 "" H 7130 3450 50  0001 C CNN
F 4 "0603" V 7230 3450 50  0001 C CNN "display_footprint"
F 5 "1%" V 7330 3450 50  0001 C CNN "Tolerance"
F 6 "1/10W" V 7430 3450 50  0001 C CNN "Wattage"
F 7 "A106047CT-ND" H 7430 3850 60  0001 C CNN "Digi-Key PN"
	1    7130 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	6980 3450 6750 3450
Wire Wire Line
	6750 3700 6750 3450
Connection ~ 6750 3450
Wire Wire Line
	6750 3450 6480 3450
Text GLabel 7280 3450 2    50   Output ~ 0
FLASH_MISO
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BBEA490
P 5790 5430
AR Path="/5BAAE16C/5BBEA490" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BBEA490" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5BBEA490" Ref="C?"  Part="1" 
AR Path="/5BB53D61/5BBEA490" Ref="C2301"  Part="1" 
F 0 "C2301" H 5815 5530 50  0000 L CNN
F 1 "0.1uF" H 5815 5330 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5828 5280 50  0001 C CNN
F 3 "" H 5815 5530 50  0001 C CNN
F 4 "0603" H 5640 5530 50  0000 R CNN "display_footprint"
F 5 "50V" H 5640 5430 50  0000 R CNN "Voltage"
F 6 "X7R" H 5640 5330 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 6215 5930 60  0001 C CNN "Digi-Key PN"
	1    5790 5430
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BBEA49B
P 6090 5430
AR Path="/5BAAE16C/5BBEA49B" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BBEA49B" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5BBEA49B" Ref="C?"  Part="1" 
AR Path="/5BB53D61/5BBEA49B" Ref="C2302"  Part="1" 
F 0 "C2302" H 6115 5530 50  0000 L CNN
F 1 "10nF" H 6115 5330 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6128 5280 50  0001 C CNN
F 3 "" H 6115 5530 50  0001 C CNN
F 4 "0603" H 5940 5530 50  0001 R CNN "display_footprint"
F 5 "50V" H 5940 5430 50  0001 R CNN "Voltage"
F 6 "X7R" H 5940 5330 50  0001 R CNN "Dielectric"
F 7 "1276-1921-1-ND" H 6515 5930 60  0001 C CNN "Digi-Key PN"
	1    6090 5430
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BBEA4A6
P 6390 5430
AR Path="/5BAAE16C/5BBEA4A6" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5BBEA4A6" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5BBEA4A6" Ref="C?"  Part="1" 
AR Path="/5BB53D61/5BBEA4A6" Ref="C2303"  Part="1" 
F 0 "C2303" H 6415 5530 50  0000 L CNN
F 1 "1nF" H 6415 5330 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6428 5280 50  0001 C CNN
F 3 "" H 6415 5530 50  0001 C CNN
F 4 "0603" H 6240 5530 50  0001 R CNN "display_footprint"
F 5 "50V" H 6240 5430 50  0001 R CNN "Voltage"
F 6 "X7R" H 6240 5330 50  0001 R CNN "Dielectric"
F 7 "1276-1018-1-ND" H 6815 5930 60  0001 C CNN "Digi-Key PN"
	1    6390 5430
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BBEA4AD
P 6090 5660
AR Path="/5BAAE16C/5BBEA4AD" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BBEA4AD" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595E/5BBEA4AD" Ref="#PWR?"  Part="1" 
AR Path="/5BB53D61/5BBEA4AD" Ref="#PWR02309"  Part="1" 
F 0 "#PWR02309" H 6090 5410 50  0001 C CNN
F 1 "GND" H 6090 5510 50  0000 C CNN
F 2 "" H 6090 5660 50  0001 C CNN
F 3 "" H 6090 5660 50  0001 C CNN
	1    6090 5660
	1    0    0    -1  
$EndComp
Wire Wire Line
	6090 5660 6090 5620
Wire Wire Line
	6090 5620 5790 5620
Wire Wire Line
	5790 5620 5790 5580
Connection ~ 6090 5620
Wire Wire Line
	6090 5620 6090 5580
Wire Wire Line
	6090 5620 6390 5620
Wire Wire Line
	6390 5620 6390 5580
$Comp
L power:+3.3V #PWR?
U 1 1 5BBEA4BA
P 6090 5200
AR Path="/5BAAE16C/5BBEA4BA" Ref="#PWR?"  Part="1" 
AR Path="/5BB181D8/5BBEA4BA" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595E/5BBEA4BA" Ref="#PWR?"  Part="1" 
AR Path="/5BB53D61/5BBEA4BA" Ref="#PWR02308"  Part="1" 
F 0 "#PWR02308" H 6090 5050 50  0001 C CNN
F 1 "+3.3V" H 6090 5340 50  0000 C CNN
F 2 "" H 6090 5200 50  0001 C CNN
F 3 "" H 6090 5200 50  0001 C CNN
	1    6090 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6090 5200 6090 5240
Wire Wire Line
	5790 5280 5790 5240
Wire Wire Line
	5790 5240 6090 5240
Wire Wire Line
	6390 5240 6390 5280
Connection ~ 6090 5240
Wire Wire Line
	6090 5240 6090 5280
Wire Wire Line
	6090 5240 6390 5240
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BBEA4CB
P 3420 3550
AR Path="/5BB2595E/5BBEA4CB" Ref="R?"  Part="1" 
AR Path="/5BB53D61/5BBEA4CB" Ref="R2302"  Part="1" 
F 0 "R2302" V 3380 3680 50  0000 L CNN
F 1 "100" V 3420 3550 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3420 3550 50  0001 C CNN
F 3 "" H 3420 3550 50  0001 C CNN
F 4 "0603" V 3520 3550 50  0001 C CNN "display_footprint"
F 5 "1%" V 3620 3550 50  0001 C CNN "Tolerance"
F 6 "1/10W" V 3720 3550 50  0001 C CNN "Wattage"
F 7 "A106047CT-ND" H 3720 3950 60  0001 C CNN "Digi-Key PN"
	1    3420 3550
	0    1    1    0   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BBEA4D6
P 3420 3750
AR Path="/5BB2595E/5BBEA4D6" Ref="R?"  Part="1" 
AR Path="/5BB53D61/5BBEA4D6" Ref="R2304"  Part="1" 
F 0 "R2304" V 3380 3880 50  0000 L CNN
F 1 "100" V 3420 3750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3420 3750 50  0001 C CNN
F 3 "" H 3420 3750 50  0001 C CNN
F 4 "0603" V 3520 3750 50  0001 C CNN "display_footprint"
F 5 "1%" V 3620 3750 50  0001 C CNN "Tolerance"
F 6 "1/10W" V 3720 3750 50  0001 C CNN "Wattage"
F 7 "A106047CT-ND" H 3720 4150 60  0001 C CNN "Digi-Key PN"
	1    3420 3750
	0    1    1    0   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BBEA4E1
P 3420 3850
AR Path="/5BB2595E/5BBEA4E1" Ref="R?"  Part="1" 
AR Path="/5BB53D61/5BBEA4E1" Ref="R2305"  Part="1" 
F 0 "R2305" V 3380 3980 50  0000 L CNN
F 1 "100" V 3420 3850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3420 3850 50  0001 C CNN
F 3 "" H 3420 3850 50  0001 C CNN
F 4 "0603" V 3520 3850 50  0001 C CNN "display_footprint"
F 5 "1%" V 3620 3850 50  0001 C CNN "Tolerance"
F 6 "1/10W" V 3720 3850 50  0001 C CNN "Wattage"
F 7 "A106047CT-ND" H 3720 4250 60  0001 C CNN "Digi-Key PN"
	1    3420 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	5110 3550 3570 3550
Connection ~ 5110 3550
Text GLabel 3270 3550 0    40   Input ~ 0
~FLASH_Hold
$Comp
L LED_Display_Local_Library:R_Custom R2303
U 1 1 5BC1EEE1
P 3420 3650
F 0 "R2303" V 3380 3780 50  0000 L CNN
F 1 "100" V 3420 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3420 3650 50  0001 C CNN
F 3 "" H 3420 3650 50  0001 C CNN
F 4 "0603" V 3520 3650 50  0001 C CNN "display_footprint"
F 5 "1%" V 3620 3650 50  0001 C CNN "Tolerance"
F 6 "1/10W" V 3720 3650 50  0001 C CNN "Wattage"
F 7 "A106047CT-ND" H 3720 4050 60  0001 C CNN "Digi-Key PN"
	1    3420 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	3570 3650 3930 3650
Text GLabel 3270 3650 0    40   Input ~ 0
~FLASH_WP6
$Comp
L power:+3.3V #PWR02306
U 1 1 5BDF99D9
P 6080 3250
F 0 "#PWR02306" H 6080 3100 50  0001 C CNN
F 1 "+3.3V" H 6080 3390 50  0000 C CNN
F 2 "" H 6080 3250 50  0001 C CNN
F 3 "" H 6080 3250 50  0001 C CNN
	1    6080 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR02304
U 1 1 5BDF9A0D
P 5110 2980
F 0 "#PWR02304" H 5110 2830 50  0001 C CNN
F 1 "+3.3V" H 5110 3120 50  0000 C CNN
F 2 "" H 5110 2980 50  0001 C CNN
F 3 "" H 5110 2980 50  0001 C CNN
	1    5110 2980
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR02302
U 1 1 5BDF9A3A
P 4520 2980
F 0 "#PWR02302" H 4520 2830 50  0001 C CNN
F 1 "+3.3V" H 4520 3120 50  0000 C CNN
F 2 "" H 4520 2980 50  0001 C CNN
F 3 "" H 4520 2980 50  0001 C CNN
	1    4520 2980
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR02301
U 1 1 5BDF9A67
P 3930 2980
F 0 "#PWR02301" H 3930 2830 50  0001 C CNN
F 1 "+3.3V" H 3930 3120 50  0000 C CNN
F 2 "" H 3930 2980 50  0001 C CNN
F 3 "" H 3930 2980 50  0001 C CNN
	1    3930 2980
	1    0    0    -1  
$EndComp
$Comp
L Graphic:SYM_ESD_Large #SYM?
U 1 1 5C02C58C
P 6490 4500
AR Path="/5BAAE0FA/5C02C58C" Ref="#SYM?"  Part="1" 
AR Path="/5BB182B1/5C02C58C" Ref="#SYM?"  Part="1" 
AR Path="/5BB53D61/5C02C58C" Ref="#SYM2301"  Part="1" 
F 0 "#SYM2301" H 6490 4700 50  0001 C CNN
F 1 "SYM_ESD_Large" H 6490 4250 50  0001 C CNN
F 2 "" H 6485 4470 50  0001 C CNN
F 3 "~" H 6485 4470 50  0001 C CNN
	1    6490 4500
	1    0    0    -1  
$EndComp
Text Notes 550  700  0    100  ~ 20
23. External FLASH 6
$Comp
L LED_Display_Local_Library:MU_Logo #G2301
U 1 1 5BFFDEA2
P 9900 1100
F 0 "#G2301" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
Connection ~ 4520 3850
Wire Wire Line
	4520 3850 5680 3850
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C173551
P 2010 6900
AR Path="/5BAAE16C/5C173551" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5C173551" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5C173551" Ref="C?"  Part="1" 
AR Path="/5BB53D61/5C173551" Ref="C2304"  Part="1" 
F 0 "C2304" H 2035 7000 50  0000 L CNN
F 1 "0.1uF" H 2035 6800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2048 6750 50  0001 C CNN
F 3 "" H 2035 7000 50  0001 C CNN
F 4 "0603" H 1860 7000 50  0000 R CNN "display_footprint"
F 5 "50V" H 1860 6900 50  0000 R CNN "Voltage"
F 6 "X7R" H 1860 6800 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 2435 7400 60  0001 C CNN "Digi-Key PN"
	1    2010 6900
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:74LVC1G07_Power U?
U 1 1 5C173559
P 1670 6320
AR Path="/5BB2595E/5C173559" Ref="U?"  Part="1" 
AR Path="/5BB53D61/5C173559" Ref="U2302"  Part="1" 
F 0 "U2302" H 1770 6420 50  0000 L CNN
F 1 "74LVC1G07" H 1770 6220 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 1670 6320 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 1670 6320 50  0001 C CNN
F 4 "296-8486-1-ND" H 1670 6320 50  0001 C CNN "Digi-Key PN"
	1    1670 6320
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5C173560
P 1670 6220
AR Path="/5BB2595E/5C173560" Ref="#PWR?"  Part="1" 
AR Path="/5BB53D61/5C173560" Ref="#PWR02311"  Part="1" 
F 0 "#PWR02311" H 1670 6070 50  0001 C CNN
F 1 "+3.3V" H 1670 6360 50  0000 C CNN
F 2 "" H 1670 6220 50  0001 C CNN
F 3 "" H 1670 6220 50  0001 C CNN
	1    1670 6220
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5C173566
P 2010 6750
AR Path="/5BB2595E/5C173566" Ref="#PWR?"  Part="1" 
AR Path="/5BB53D61/5C173566" Ref="#PWR02313"  Part="1" 
F 0 "#PWR02313" H 2010 6600 50  0001 C CNN
F 1 "+3.3V" H 2010 6890 50  0000 C CNN
F 2 "" H 2010 6750 50  0001 C CNN
F 3 "" H 2010 6750 50  0001 C CNN
	1    2010 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C17356C
P 2010 7050
AR Path="/5BB2595E/5C17356C" Ref="#PWR?"  Part="1" 
AR Path="/5BB53D61/5C17356C" Ref="#PWR02314"  Part="1" 
F 0 "#PWR02314" H 2010 6800 50  0001 C CNN
F 1 "GND" H 2010 6900 50  0000 C CNN
F 2 "" H 2010 7050 50  0001 C CNN
F 3 "" H 2010 7050 50  0001 C CNN
	1    2010 7050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C173572
P 1670 6420
AR Path="/5BB2595E/5C173572" Ref="#PWR?"  Part="1" 
AR Path="/5BB53D61/5C173572" Ref="#PWR02312"  Part="1" 
F 0 "#PWR02312" H 1670 6170 50  0001 C CNN
F 1 "GND" H 1670 6270 50  0000 C CNN
F 2 "" H 1670 6420 50  0001 C CNN
F 3 "" H 1670 6420 50  0001 C CNN
	1    1670 6420
	1    0    0    -1  
$EndComp
Text GLabel 1370 6320 0    40   Input ~ 0
~FLASH_CE6
$Comp
L power:+3.3V #PWR?
U 1 1 5C173579
P 2410 5560
AR Path="/5BB844FD/5C173579" Ref="#PWR?"  Part="1" 
AR Path="/5BF346B3/5C173579" Ref="#PWR?"  Part="1" 
AR Path="/5BB2595E/5C173579" Ref="#PWR?"  Part="1" 
AR Path="/5BB53D61/5C173579" Ref="#PWR02315"  Part="1" 
F 0 "#PWR02315" H 2410 5410 50  0001 C CNN
F 1 "+3.3V" H 2410 5700 50  0000 C CNN
F 2 "" H 2410 5560 50  0001 C CNN
F 3 "" H 2410 5560 50  0001 C CNN
	1    2410 5560
	1    0    0    -1  
$EndComp
Wire Wire Line
	1920 6320 2410 6320
Wire Wire Line
	2410 6320 2410 6160
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C173585
P 2410 5710
AR Path="/5BAAE1F3/5C173585" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C173585" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C173585" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C173585" Ref="R?"  Part="1" 
AR Path="/5BF346B3/5C173585" Ref="R?"  Part="1" 
AR Path="/5BB2595E/5C173585" Ref="R?"  Part="1" 
AR Path="/5BB53D61/5C173585" Ref="R2313"  Part="1" 
F 0 "R2313" H 2350 5710 50  0000 R CNN
F 1 "1k" V 2410 5710 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2410 5710 50  0001 C CNN
F 3 "" H 2410 5710 50  0001 C CNN
F 4 "0603" H 2480 5790 50  0000 L CNN "display_footprint"
F 5 "1%" H 2480 5710 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 2480 5640 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT1K00CT-ND" H 2710 6110 60  0001 C CNN "Digi-Key PN"
	1    2410 5710
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 5C17358D
P 2410 6010
AR Path="/5BB844FD/5C17358D" Ref="D?"  Part="1" 
AR Path="/5BF346B3/5C17358D" Ref="D?"  Part="1" 
AR Path="/5BB2595E/5C17358D" Ref="D?"  Part="1" 
AR Path="/5BB53D61/5C17358D" Ref="D2301"  Part="1" 
F 0 "D2301" V 2440 5890 50  0000 R CNN
F 1 "Green" V 2357 5893 50  0000 R CNN
F 2 "LEDs:LED_0603" H 2410 6010 50  0001 C CNN
F 3 "~" H 2410 6010 50  0001 C CNN
F 4 "160-1446-1-ND" H -2600 3010 50  0001 C CNN "Digi-Key PN"
	1    2410 6010
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
