EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 12 31
Title "Electronic Display Logic Board"
Date "2018-11-28"
Rev "A"
Comp "Marquette University Senior Design 2018/2019 Group E44"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BC13B02
P 1760 2240
AR Path="/5BAAE1F3/5BC13B02" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5BC13B02" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5BC13B02" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5BC13B02" Ref="R1201"  Part="1" 
F 0 "R1201" H 1700 2240 50  0000 R CNN
F 1 "10k" V 1760 2240 50  0000 C CNN
F 2 "" H 1760 2240 50  0001 C CNN
F 3 "" H 1760 2240 50  0001 C CNN
F 4 "0603" H 1830 2320 50  0000 L CNN "display_footprint"
F 5 "1%" H 1830 2240 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 1830 2170 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 2060 2640 60  0001 C CNN "Digi-Key PN"
	1    1760 2240
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01211
U 1 1 5BC13B0F
P 3180 1820
F 0 "#PWR01211" H 3180 1670 50  0001 C CNN
F 1 "+3.3V" H 3180 1960 50  0000 C CNN
F 2 "" H 3180 1820 50  0001 C CNN
F 3 "" H 3180 1820 50  0001 C CNN
	1    3180 1820
	1    0    0    -1  
$EndComp
Text GLabel 1390 2580 0    50   Input ~ 0
~ACTIVE_LED
$Comp
L LED_Display_Local_Library:74LVC1G06_Power U1201
U 1 1 5BF0B0A5
P 2440 2580
F 0 "U1201" H 2540 2730 50  0000 L CNN
F 1 "74LVC1G06" H 2540 2480 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 2440 2630 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g06.pdf" H 2440 2580 50  0001 C CNN
F 4 "296-8484-1-ND" H 2440 2580 50  0001 C CNN "Digi-Key PN"
	1    2440 2580
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01204
U 1 1 5BF0CD47
P 2440 2680
F 0 "#PWR01204" H 2440 2430 50  0001 C CNN
F 1 "GND" H 2440 2530 50  0000 C CNN
F 2 "" H 2440 2680 50  0001 C CNN
F 3 "" H 2440 2680 50  0001 C CNN
	1    2440 2680
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01203
U 1 1 5BF0CDF0
P 2440 2480
F 0 "#PWR01203" H 2440 2330 50  0001 C CNN
F 1 "+3.3V" H 2440 2620 50  0000 C CNN
F 2 "" H 2440 2480 50  0001 C CNN
F 3 "" H 2440 2480 50  0001 C CNN
	1    2440 2480
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01201
U 1 1 5BF0E9BA
P 1760 2090
F 0 "#PWR01201" H 1760 1940 50  0001 C CNN
F 1 "+3.3V" H 1760 2230 50  0000 C CNN
F 2 "" H 1760 2090 50  0001 C CNN
F 3 "" H 1760 2090 50  0001 C CNN
	1    1760 2090
	1    0    0    -1  
$EndComp
Wire Wire Line
	2690 2580 3180 2580
Wire Wire Line
	3180 2580 3180 2420
Wire Wire Line
	2140 2580 1760 2580
Wire Wire Line
	1760 2580 1760 2390
Wire Wire Line
	1390 2580 1760 2580
Connection ~ 1760 2580
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BF17A3C
P 2790 3170
AR Path="/5BAAE1F3/5BF17A3C" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5BF17A3C" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5BF17A3C" Ref="C?"  Part="1" 
AR Path="/5BB844FD/5BF17A3C" Ref="C1201"  Part="1" 
F 0 "C1201" H 2815 3270 50  0000 L CNN
F 1 "0.1uF" H 2815 3070 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2828 3020 50  0001 C CNN
F 3 "" H 2815 3270 50  0001 C CNN
F 4 "311-1344-1-ND" H 3215 3670 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 2640 3270 50  0000 R CNN "display_footprint"
F 6 "50V" H 2640 3170 50  0000 R CNN "Voltage"
F 7 "X7R" H 2640 3070 50  0000 R CNN "Dielectric"
	1    2790 3170
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF17A43
P 2790 3320
AR Path="/5BE48F98/5BF17A43" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF17A43" Ref="#PWR01208"  Part="1" 
F 0 "#PWR01208" H 2790 3070 50  0001 C CNN
F 1 "GND" H 2790 3170 50  0000 C CNN
F 2 "" H 2790 3320 50  0001 C CNN
F 3 "" H 2790 3320 50  0001 C CNN
	1    2790 3320
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01207
U 1 1 5BF17A74
P 2790 3020
F 0 "#PWR01207" H 2790 2870 50  0001 C CNN
F 1 "+3.3V" H 2790 3160 50  0000 C CNN
F 2 "" H 2790 3020 50  0001 C CNN
F 3 "" H 2790 3020 50  0001 C CNN
	1    2790 3020
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01223
U 1 1 5BF1B565
P 6290 1820
F 0 "#PWR01223" H 6290 1670 50  0001 C CNN
F 1 "+3.3V" H 6290 1960 50  0000 C CNN
F 2 "" H 6290 1820 50  0001 C CNN
F 3 "" H 6290 1820 50  0001 C CNN
	1    6290 1820
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:74LVC1G06_Power U1203
U 1 1 5BF1B56D
P 5550 2580
F 0 "U1203" H 5650 2730 50  0000 L CNN
F 1 "74LVC1G06" H 5650 2480 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 5550 2630 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g06.pdf" H 5550 2580 50  0001 C CNN
F 4 "296-8484-1-ND" H 5550 2580 50  0001 C CNN "Digi-Key PN"
	1    5550 2580
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01216
U 1 1 5BF1B574
P 5550 2680
F 0 "#PWR01216" H 5550 2430 50  0001 C CNN
F 1 "GND" H 5550 2530 50  0000 C CNN
F 2 "" H 5550 2680 50  0001 C CNN
F 3 "" H 5550 2680 50  0001 C CNN
	1    5550 2680
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01215
U 1 1 5BF1B57A
P 5550 2480
F 0 "#PWR01215" H 5550 2330 50  0001 C CNN
F 1 "+3.3V" H 5550 2620 50  0000 C CNN
F 2 "" H 5550 2480 50  0001 C CNN
F 3 "" H 5550 2480 50  0001 C CNN
	1    5550 2480
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 2580 6290 2580
Wire Wire Line
	6290 2580 6290 2420
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BF1B590
P 5900 3170
AR Path="/5BAAE1F3/5BF1B590" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5BF1B590" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5BF1B590" Ref="C?"  Part="1" 
AR Path="/5BB844FD/5BF1B590" Ref="C1203"  Part="1" 
F 0 "C1203" H 5925 3270 50  0000 L CNN
F 1 "0.1uF" H 5925 3070 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5938 3020 50  0001 C CNN
F 3 "" H 5925 3270 50  0001 C CNN
F 4 "311-1344-1-ND" H 6325 3670 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 5750 3270 50  0000 R CNN "display_footprint"
F 6 "50V" H 5750 3170 50  0000 R CNN "Voltage"
F 7 "X7R" H 5750 3070 50  0000 R CNN "Dielectric"
	1    5900 3170
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF1B597
P 5900 3320
AR Path="/5BE48F98/5BF1B597" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF1B597" Ref="#PWR01220"  Part="1" 
F 0 "#PWR01220" H 5900 3070 50  0001 C CNN
F 1 "GND" H 5900 3170 50  0000 C CNN
F 2 "" H 5900 3320 50  0001 C CNN
F 3 "" H 5900 3320 50  0001 C CNN
	1    5900 3320
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01219
U 1 1 5BF1B59D
P 5900 3020
F 0 "#PWR01219" H 5900 2870 50  0001 C CNN
F 1 "+3.3V" H 5900 3160 50  0000 C CNN
F 2 "" H 5900 3020 50  0001 C CNN
F 3 "" H 5900 3020 50  0001 C CNN
	1    5900 3020
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 2580 4900 2580
$Comp
L power:GND #PWR?
U 1 1 5BF1B698
P 4900 3000
AR Path="/5BE48F98/5BF1B698" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF1B698" Ref="#PWR01213"  Part="1" 
F 0 "#PWR01213" H 4900 2750 50  0001 C CNN
F 1 "GND" H 4900 2850 50  0000 C CNN
F 2 "" H 4900 3000 50  0001 C CNN
F 3 "" H 4900 3000 50  0001 C CNN
	1    4900 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 2700 4900 2580
Connection ~ 4900 2580
Wire Wire Line
	4900 2580 5250 2580
Text GLabel 4500 2580 0    50   Input ~ 0
WIFI_Error_LED
$Comp
L power:+3.3V #PWR01235
U 1 1 5BF20E04
P 9290 1820
F 0 "#PWR01235" H 9290 1670 50  0001 C CNN
F 1 "+3.3V" H 9290 1960 50  0000 C CNN
F 2 "" H 9290 1820 50  0001 C CNN
F 3 "" H 9290 1820 50  0001 C CNN
	1    9290 1820
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:74LVC1G06_Power U1205
U 1 1 5BF20E0B
P 8550 2580
F 0 "U1205" H 8650 2730 50  0000 L CNN
F 1 "74LVC1G06" H 8650 2480 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 8550 2630 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g06.pdf" H 8550 2580 50  0001 C CNN
F 4 "296-8484-1-ND" H 8550 2580 50  0001 C CNN "Digi-Key PN"
	1    8550 2580
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01228
U 1 1 5BF20E12
P 8550 2680
F 0 "#PWR01228" H 8550 2430 50  0001 C CNN
F 1 "GND" H 8550 2530 50  0000 C CNN
F 2 "" H 8550 2680 50  0001 C CNN
F 3 "" H 8550 2680 50  0001 C CNN
	1    8550 2680
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01227
U 1 1 5BF20E18
P 8550 2480
F 0 "#PWR01227" H 8550 2330 50  0001 C CNN
F 1 "+3.3V" H 8550 2620 50  0000 C CNN
F 2 "" H 8550 2480 50  0001 C CNN
F 3 "" H 8550 2480 50  0001 C CNN
	1    8550 2480
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 2580 9290 2580
Wire Wire Line
	9290 2580 9290 2420
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BF20E24
P 8900 3170
AR Path="/5BAAE1F3/5BF20E24" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5BF20E24" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5BF20E24" Ref="C?"  Part="1" 
AR Path="/5BB844FD/5BF20E24" Ref="C1205"  Part="1" 
F 0 "C1205" H 8925 3270 50  0000 L CNN
F 1 "0.1uF" H 8925 3070 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8938 3020 50  0001 C CNN
F 3 "" H 8925 3270 50  0001 C CNN
F 4 "311-1344-1-ND" H 9325 3670 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 8750 3270 50  0000 R CNN "display_footprint"
F 6 "50V" H 8750 3170 50  0000 R CNN "Voltage"
F 7 "X7R" H 8750 3070 50  0000 R CNN "Dielectric"
	1    8900 3170
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF20E2B
P 8900 3320
AR Path="/5BE48F98/5BF20E2B" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF20E2B" Ref="#PWR01232"  Part="1" 
F 0 "#PWR01232" H 8900 3070 50  0001 C CNN
F 1 "GND" H 8900 3170 50  0000 C CNN
F 2 "" H 8900 3320 50  0001 C CNN
F 3 "" H 8900 3320 50  0001 C CNN
	1    8900 3320
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01231
U 1 1 5BF20E31
P 8900 3020
F 0 "#PWR01231" H 8900 2870 50  0001 C CNN
F 1 "+3.3V" H 8900 3160 50  0000 C CNN
F 2 "" H 8900 3020 50  0001 C CNN
F 3 "" H 8900 3020 50  0001 C CNN
	1    8900 3020
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 2580 7900 2580
$Comp
L power:GND #PWR?
U 1 1 5BF20E38
P 7900 3000
AR Path="/5BE48F98/5BF20E38" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF20E38" Ref="#PWR01225"  Part="1" 
F 0 "#PWR01225" H 7900 2750 50  0001 C CNN
F 1 "GND" H 7900 2850 50  0000 C CNN
F 2 "" H 7900 3000 50  0001 C CNN
F 3 "" H 7900 3000 50  0001 C CNN
	1    7900 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 2700 7900 2580
Connection ~ 7900 2580
Wire Wire Line
	7900 2580 8250 2580
Text GLabel 7500 2580 0    50   Input ~ 0
USB_Error_LED
$Comp
L power:+3.3V #PWR01212
U 1 1 5BF22EB4
P 3180 3820
F 0 "#PWR01212" H 3180 3670 50  0001 C CNN
F 1 "+3.3V" H 3180 3960 50  0000 C CNN
F 2 "" H 3180 3820 50  0001 C CNN
F 3 "" H 3180 3820 50  0001 C CNN
	1    3180 3820
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:74LVC1G06_Power U1202
U 1 1 5BF22EBB
P 2440 4580
F 0 "U1202" H 2540 4730 50  0000 L CNN
F 1 "74LVC1G06" H 2540 4480 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 2440 4630 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g06.pdf" H 2440 4580 50  0001 C CNN
F 4 "296-8484-1-ND" H 2440 4580 50  0001 C CNN "Digi-Key PN"
	1    2440 4580
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01206
U 1 1 5BF22EC2
P 2440 4680
F 0 "#PWR01206" H 2440 4430 50  0001 C CNN
F 1 "GND" H 2440 4530 50  0000 C CNN
F 2 "" H 2440 4680 50  0001 C CNN
F 3 "" H 2440 4680 50  0001 C CNN
	1    2440 4680
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01205
U 1 1 5BF22EC8
P 2440 4480
F 0 "#PWR01205" H 2440 4330 50  0001 C CNN
F 1 "+3.3V" H 2440 4620 50  0000 C CNN
F 2 "" H 2440 4480 50  0001 C CNN
F 3 "" H 2440 4480 50  0001 C CNN
	1    2440 4480
	1    0    0    -1  
$EndComp
Wire Wire Line
	2690 4580 3180 4580
Wire Wire Line
	3180 4580 3180 4420
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BF22ED4
P 2790 5170
AR Path="/5BAAE1F3/5BF22ED4" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5BF22ED4" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5BF22ED4" Ref="C?"  Part="1" 
AR Path="/5BB844FD/5BF22ED4" Ref="C1202"  Part="1" 
F 0 "C1202" H 2815 5270 50  0000 L CNN
F 1 "0.1uF" H 2815 5070 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2828 5020 50  0001 C CNN
F 3 "" H 2815 5270 50  0001 C CNN
F 4 "311-1344-1-ND" H 3215 5670 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 2640 5270 50  0000 R CNN "display_footprint"
F 6 "50V" H 2640 5170 50  0000 R CNN "Voltage"
F 7 "X7R" H 2640 5070 50  0000 R CNN "Dielectric"
	1    2790 5170
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF22EDB
P 2790 5320
AR Path="/5BE48F98/5BF22EDB" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF22EDB" Ref="#PWR01210"  Part="1" 
F 0 "#PWR01210" H 2790 5070 50  0001 C CNN
F 1 "GND" H 2790 5170 50  0000 C CNN
F 2 "" H 2790 5320 50  0001 C CNN
F 3 "" H 2790 5320 50  0001 C CNN
	1    2790 5320
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01209
U 1 1 5BF22EE1
P 2790 5020
F 0 "#PWR01209" H 2790 4870 50  0001 C CNN
F 1 "+3.3V" H 2790 5160 50  0000 C CNN
F 2 "" H 2790 5020 50  0001 C CNN
F 3 "" H 2790 5020 50  0001 C CNN
	1    2790 5020
	1    0    0    -1  
$EndComp
Wire Wire Line
	1390 4580 1790 4580
$Comp
L power:GND #PWR?
U 1 1 5BF22EE8
P 1790 5000
AR Path="/5BE48F98/5BF22EE8" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF22EE8" Ref="#PWR01202"  Part="1" 
F 0 "#PWR01202" H 1790 4750 50  0001 C CNN
F 1 "GND" H 1790 4850 50  0000 C CNN
F 2 "" H 1790 5000 50  0001 C CNN
F 3 "" H 1790 5000 50  0001 C CNN
	1    1790 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1790 4700 1790 4580
Connection ~ 1790 4580
Wire Wire Line
	1790 4580 2140 4580
Text GLabel 1390 4580 0    50   Input ~ 0
SPI_Error_LED
$Comp
L power:+3.3V #PWR01224
U 1 1 5BF272D6
P 6290 3820
F 0 "#PWR01224" H 6290 3670 50  0001 C CNN
F 1 "+3.3V" H 6290 3960 50  0000 C CNN
F 2 "" H 6290 3820 50  0001 C CNN
F 3 "" H 6290 3820 50  0001 C CNN
	1    6290 3820
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:74LVC1G06_Power U1204
U 1 1 5BF272DD
P 5550 4580
F 0 "U1204" H 5650 4730 50  0000 L CNN
F 1 "74LVC1G06" H 5650 4480 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 5550 4630 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g06.pdf" H 5550 4580 50  0001 C CNN
F 4 "296-8484-1-ND" H 5550 4580 50  0001 C CNN "Digi-Key PN"
	1    5550 4580
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01218
U 1 1 5BF272E4
P 5550 4680
F 0 "#PWR01218" H 5550 4430 50  0001 C CNN
F 1 "GND" H 5550 4530 50  0000 C CNN
F 2 "" H 5550 4680 50  0001 C CNN
F 3 "" H 5550 4680 50  0001 C CNN
	1    5550 4680
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01217
U 1 1 5BF272EA
P 5550 4480
F 0 "#PWR01217" H 5550 4330 50  0001 C CNN
F 1 "+3.3V" H 5550 4620 50  0000 C CNN
F 2 "" H 5550 4480 50  0001 C CNN
F 3 "" H 5550 4480 50  0001 C CNN
	1    5550 4480
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 4580 6290 4580
Wire Wire Line
	6290 4580 6290 4420
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BF272F6
P 5900 5170
AR Path="/5BAAE1F3/5BF272F6" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5BF272F6" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5BF272F6" Ref="C?"  Part="1" 
AR Path="/5BB844FD/5BF272F6" Ref="C1204"  Part="1" 
F 0 "C1204" H 5925 5270 50  0000 L CNN
F 1 "0.1uF" H 5925 5070 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5938 5020 50  0001 C CNN
F 3 "" H 5925 5270 50  0001 C CNN
F 4 "311-1344-1-ND" H 6325 5670 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 5750 5270 50  0000 R CNN "display_footprint"
F 6 "50V" H 5750 5170 50  0000 R CNN "Voltage"
F 7 "X7R" H 5750 5070 50  0000 R CNN "Dielectric"
	1    5900 5170
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF272FD
P 5900 5320
AR Path="/5BE48F98/5BF272FD" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF272FD" Ref="#PWR01222"  Part="1" 
F 0 "#PWR01222" H 5900 5070 50  0001 C CNN
F 1 "GND" H 5900 5170 50  0000 C CNN
F 2 "" H 5900 5320 50  0001 C CNN
F 3 "" H 5900 5320 50  0001 C CNN
	1    5900 5320
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01221
U 1 1 5BF27303
P 5900 5020
F 0 "#PWR01221" H 5900 4870 50  0001 C CNN
F 1 "+3.3V" H 5900 5160 50  0000 C CNN
F 2 "" H 5900 5020 50  0001 C CNN
F 3 "" H 5900 5020 50  0001 C CNN
	1    5900 5020
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4580 4900 4580
$Comp
L power:GND #PWR?
U 1 1 5BF2730A
P 4900 5000
AR Path="/5BE48F98/5BF2730A" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF2730A" Ref="#PWR01214"  Part="1" 
F 0 "#PWR01214" H 4900 4750 50  0001 C CNN
F 1 "GND" H 4900 4850 50  0000 C CNN
F 2 "" H 4900 5000 50  0001 C CNN
F 3 "" H 4900 5000 50  0001 C CNN
	1    4900 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 4700 4900 4580
Connection ~ 4900 4580
Wire Wire Line
	4900 4580 5250 4580
Text GLabel 4500 4580 0    50   Input ~ 0
EBI_Error_LED
$Comp
L power:+3.3V #PWR01236
U 1 1 5BF2F977
P 9290 3820
F 0 "#PWR01236" H 9290 3670 50  0001 C CNN
F 1 "+3.3V" H 9290 3960 50  0000 C CNN
F 2 "" H 9290 3820 50  0001 C CNN
F 3 "" H 9290 3820 50  0001 C CNN
	1    9290 3820
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:74LVC1G06_Power U1206
U 1 1 5BF2F97E
P 8550 4580
F 0 "U1206" H 8650 4730 50  0000 L CNN
F 1 "74LVC1G06" H 8650 4480 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 8550 4630 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g06.pdf" H 8550 4580 50  0001 C CNN
F 4 "296-8484-1-ND" H 8550 4580 50  0001 C CNN "Digi-Key PN"
	1    8550 4580
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01230
U 1 1 5BF2F985
P 8550 4680
F 0 "#PWR01230" H 8550 4430 50  0001 C CNN
F 1 "GND" H 8550 4530 50  0000 C CNN
F 2 "" H 8550 4680 50  0001 C CNN
F 3 "" H 8550 4680 50  0001 C CNN
	1    8550 4680
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01229
U 1 1 5BF2F98B
P 8550 4480
F 0 "#PWR01229" H 8550 4330 50  0001 C CNN
F 1 "+3.3V" H 8550 4620 50  0000 C CNN
F 2 "" H 8550 4480 50  0001 C CNN
F 3 "" H 8550 4480 50  0001 C CNN
	1    8550 4480
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 4580 9290 4580
Wire Wire Line
	9290 4580 9290 4420
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BF2F997
P 8900 5170
AR Path="/5BAAE1F3/5BF2F997" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5BF2F997" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5BF2F997" Ref="C?"  Part="1" 
AR Path="/5BB844FD/5BF2F997" Ref="C1206"  Part="1" 
F 0 "C1206" H 8925 5270 50  0000 L CNN
F 1 "0.1uF" H 8925 5070 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8938 5020 50  0001 C CNN
F 3 "" H 8925 5270 50  0001 C CNN
F 4 "311-1344-1-ND" H 9325 5670 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 8750 5270 50  0000 R CNN "display_footprint"
F 6 "50V" H 8750 5170 50  0000 R CNN "Voltage"
F 7 "X7R" H 8750 5070 50  0000 R CNN "Dielectric"
	1    8900 5170
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF2F99E
P 8900 5320
AR Path="/5BE48F98/5BF2F99E" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF2F99E" Ref="#PWR01234"  Part="1" 
F 0 "#PWR01234" H 8900 5070 50  0001 C CNN
F 1 "GND" H 8900 5170 50  0000 C CNN
F 2 "" H 8900 5320 50  0001 C CNN
F 3 "" H 8900 5320 50  0001 C CNN
	1    8900 5320
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01233
U 1 1 5BF2F9A4
P 8900 5020
F 0 "#PWR01233" H 8900 4870 50  0001 C CNN
F 1 "+3.3V" H 8900 5160 50  0000 C CNN
F 2 "" H 8900 5020 50  0001 C CNN
F 3 "" H 8900 5020 50  0001 C CNN
	1    8900 5020
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 4580 7900 4580
$Comp
L power:GND #PWR?
U 1 1 5BF2F9AB
P 7900 5000
AR Path="/5BE48F98/5BF2F9AB" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5BF2F9AB" Ref="#PWR01226"  Part="1" 
F 0 "#PWR01226" H 7900 4750 50  0001 C CNN
F 1 "GND" H 7900 4850 50  0000 C CNN
F 2 "" H 7900 5000 50  0001 C CNN
F 3 "" H 7900 5000 50  0001 C CNN
	1    7900 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 4700 7900 4580
Connection ~ 7900 4580
Wire Wire Line
	7900 4580 8250 4580
Text GLabel 7500 4580 0    50   Input ~ 0
Panel_Enable_LED
Text Notes 550  700  0    100  ~ 20
12. Status LEDs Bank 1
$Comp
L LED_Display_Local_Library:MU_Logo #G1201
U 1 1 5BFF7A31
P 9900 1100
F 0 "#G1201" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C052BD8
P 3180 1970
AR Path="/5BAAE1F3/5C052BD8" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C052BD8" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C052BD8" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C052BD8" Ref="R1203"  Part="1" 
F 0 "R1203" H 3120 1970 50  0000 R CNN
F 1 "1k" V 3180 1970 50  0000 C CNN
F 2 "" H 3180 1970 50  0001 C CNN
F 3 "" H 3180 1970 50  0001 C CNN
F 4 "0603" H 3250 2050 50  0000 L CNN "display_footprint"
F 5 "1%" H 3250 1970 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3250 1900 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT1K00CT-ND" H 3480 2370 60  0001 C CNN "Digi-Key PN"
	1    3180 1970
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C05322F
P 6290 1970
AR Path="/5BAAE1F3/5C05322F" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C05322F" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C05322F" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C05322F" Ref="R1207"  Part="1" 
F 0 "R1207" H 6230 1970 50  0000 R CNN
F 1 "1k" V 6290 1970 50  0000 C CNN
F 2 "" H 6290 1970 50  0001 C CNN
F 3 "" H 6290 1970 50  0001 C CNN
F 4 "0603" H 6360 2050 50  0000 L CNN "display_footprint"
F 5 "1%" H 6360 1970 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 6360 1900 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT1K00CT-ND" H 6590 2370 60  0001 C CNN "Digi-Key PN"
	1    6290 1970
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C053423
P 9290 1970
AR Path="/5BAAE1F3/5C053423" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C053423" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C053423" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C053423" Ref="R1211"  Part="1" 
F 0 "R1211" H 9230 1970 50  0000 R CNN
F 1 "1k" V 9290 1970 50  0000 C CNN
F 2 "" H 9290 1970 50  0001 C CNN
F 3 "" H 9290 1970 50  0001 C CNN
F 4 "0603" H 9360 2050 50  0000 L CNN "display_footprint"
F 5 "1%" H 9360 1970 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 9360 1900 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT1K00CT-ND" H 9590 2370 60  0001 C CNN "Digi-Key PN"
	1    9290 1970
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C0535F9
P 9290 3970
AR Path="/5BAAE1F3/5C0535F9" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C0535F9" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C0535F9" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C0535F9" Ref="R1212"  Part="1" 
F 0 "R1212" H 9230 3970 50  0000 R CNN
F 1 "1k" V 9290 3970 50  0000 C CNN
F 2 "" H 9290 3970 50  0001 C CNN
F 3 "" H 9290 3970 50  0001 C CNN
F 4 "0603" H 9360 4050 50  0000 L CNN "display_footprint"
F 5 "1%" H 9360 3970 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 9360 3900 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT1K00CT-ND" H 9590 4370 60  0001 C CNN "Digi-Key PN"
	1    9290 3970
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C0537F7
P 6290 3970
AR Path="/5BAAE1F3/5C0537F7" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C0537F7" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C0537F7" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C0537F7" Ref="R1208"  Part="1" 
F 0 "R1208" H 6230 3970 50  0000 R CNN
F 1 "1k" V 6290 3970 50  0000 C CNN
F 2 "" H 6290 3970 50  0001 C CNN
F 3 "" H 6290 3970 50  0001 C CNN
F 4 "0603" H 6360 4050 50  0000 L CNN "display_footprint"
F 5 "1%" H 6360 3970 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 6360 3900 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT1K00CT-ND" H 6590 4370 60  0001 C CNN "Digi-Key PN"
	1    6290 3970
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C0539C4
P 3180 3970
AR Path="/5BAAE1F3/5C0539C4" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C0539C4" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C0539C4" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C0539C4" Ref="R1204"  Part="1" 
F 0 "R1204" H 3120 3970 50  0000 R CNN
F 1 "1k" V 3180 3970 50  0000 C CNN
F 2 "" H 3180 3970 50  0001 C CNN
F 3 "" H 3180 3970 50  0001 C CNN
F 4 "0603" H 3250 4050 50  0000 L CNN "display_footprint"
F 5 "1%" H 3250 3970 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3250 3900 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT1K00CT-ND" H 3480 4370 60  0001 C CNN "Digi-Key PN"
	1    3180 3970
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C055EE3
P 4900 2850
AR Path="/5BAAE1F3/5C055EE3" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C055EE3" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C055EE3" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C055EE3" Ref="R1205"  Part="1" 
F 0 "R1205" H 4840 2850 50  0000 R CNN
F 1 "10k" V 4900 2850 50  0000 C CNN
F 2 "" H 4900 2850 50  0001 C CNN
F 3 "" H 4900 2850 50  0001 C CNN
F 4 "0603" H 4970 2930 50  0000 L CNN "display_footprint"
F 5 "1%" H 4970 2850 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 4970 2780 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 5200 3250 60  0001 C CNN "Digi-Key PN"
	1    4900 2850
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C05609D
P 7900 2850
AR Path="/5BAAE1F3/5C05609D" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C05609D" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C05609D" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C05609D" Ref="R1209"  Part="1" 
F 0 "R1209" H 7840 2850 50  0000 R CNN
F 1 "10k" V 7900 2850 50  0000 C CNN
F 2 "" H 7900 2850 50  0001 C CNN
F 3 "" H 7900 2850 50  0001 C CNN
F 4 "0603" H 7970 2930 50  0000 L CNN "display_footprint"
F 5 "1%" H 7970 2850 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 7970 2780 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 8200 3250 60  0001 C CNN "Digi-Key PN"
	1    7900 2850
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C056217
P 7900 4850
AR Path="/5BAAE1F3/5C056217" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C056217" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C056217" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C056217" Ref="R1210"  Part="1" 
F 0 "R1210" H 7840 4850 50  0000 R CNN
F 1 "10k" V 7900 4850 50  0000 C CNN
F 2 "" H 7900 4850 50  0001 C CNN
F 3 "" H 7900 4850 50  0001 C CNN
F 4 "0603" H 7970 4930 50  0000 L CNN "display_footprint"
F 5 "1%" H 7970 4850 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 7970 4780 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 8200 5250 60  0001 C CNN "Digi-Key PN"
	1    7900 4850
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C056497
P 4900 4850
AR Path="/5BAAE1F3/5C056497" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C056497" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C056497" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C056497" Ref="R1206"  Part="1" 
F 0 "R1206" H 4840 4850 50  0000 R CNN
F 1 "10k" V 4900 4850 50  0000 C CNN
F 2 "" H 4900 4850 50  0001 C CNN
F 3 "" H 4900 4850 50  0001 C CNN
F 4 "0603" H 4970 4930 50  0000 L CNN "display_footprint"
F 5 "1%" H 4970 4850 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 4970 4780 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 5200 5250 60  0001 C CNN "Digi-Key PN"
	1    4900 4850
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C0566FD
P 1790 4850
AR Path="/5BAAE1F3/5C0566FD" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C0566FD" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C0566FD" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C0566FD" Ref="R1202"  Part="1" 
F 0 "R1202" H 1730 4850 50  0000 R CNN
F 1 "10k" V 1790 4850 50  0000 C CNN
F 2 "" H 1790 4850 50  0001 C CNN
F 3 "" H 1790 4850 50  0001 C CNN
F 4 "0603" H 1860 4930 50  0000 L CNN "display_footprint"
F 5 "1%" H 1860 4850 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 1860 4780 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 2090 5250 60  0001 C CNN "Digi-Key PN"
	1    1790 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1201
U 1 1 5C059447
P 3180 2270
F 0 "D1201" V 3218 1907 50  0000 L CNN
F 1 "Red" V 3127 2153 50  0000 R CNN
F 2 "" H 3180 2270 50  0001 C CNN
F 3 "~" H 3180 2270 50  0001 C CNN
F 4 "160-1447-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    3180 2270
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D1203
U 1 1 5C059713
P 6290 2270
F 0 "D1203" V 6328 1907 50  0000 L CNN
F 1 "Red" V 6237 2153 50  0000 R CNN
F 2 "" H 6290 2270 50  0001 C CNN
F 3 "~" H 6290 2270 50  0001 C CNN
F 4 "160-1447-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    6290 2270
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D1205
U 1 1 5C05996D
P 9290 2270
F 0 "D1205" V 9328 1907 50  0000 L CNN
F 1 "Red" V 9237 2153 50  0000 R CNN
F 2 "" H 9290 2270 50  0001 C CNN
F 3 "~" H 9290 2270 50  0001 C CNN
F 4 "160-1447-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    9290 2270
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D1202
U 1 1 5C059C2A
P 3180 4270
F 0 "D1202" V 3218 3907 50  0000 L CNN
F 1 "Red" V 3127 4153 50  0000 R CNN
F 2 "" H 3180 4270 50  0001 C CNN
F 3 "~" H 3180 4270 50  0001 C CNN
F 4 "160-1447-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    3180 4270
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D1204
U 1 1 5C059E99
P 6290 4270
F 0 "D1204" V 6328 3907 50  0000 L CNN
F 1 "Red" V 6237 4153 50  0000 R CNN
F 2 "" H 6290 4270 50  0001 C CNN
F 3 "~" H 6290 4270 50  0001 C CNN
F 4 "160-1447-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    6290 4270
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D1206
U 1 1 5C05A06E
P 9290 4270
F 0 "D1206" V 9328 3907 50  0000 L CNN
F 1 "Green" V 9237 4153 50  0000 R CNN
F 2 "" H 9290 4270 50  0001 C CNN
F 3 "~" H 9290 4270 50  0001 C CNN
F 4 "160-1446-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    9290 4270
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR01242
U 1 1 5C073202
P 3180 5900
F 0 "#PWR01242" H 3180 5750 50  0001 C CNN
F 1 "+3.3V" H 3180 6040 50  0000 C CNN
F 2 "" H 3180 5900 50  0001 C CNN
F 3 "" H 3180 5900 50  0001 C CNN
	1    3180 5900
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:74LVC1G06_Power U1207
U 1 1 5C073209
P 2440 6660
F 0 "U1207" H 2540 6810 50  0000 L CNN
F 1 "74LVC1G06" H 2540 6560 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 2440 6710 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g06.pdf" H 2440 6660 50  0001 C CNN
F 4 "296-8484-1-ND" H 2440 6660 50  0001 C CNN "Digi-Key PN"
	1    2440 6660
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01239
U 1 1 5C073210
P 2440 6760
F 0 "#PWR01239" H 2440 6510 50  0001 C CNN
F 1 "GND" H 2440 6610 50  0000 C CNN
F 2 "" H 2440 6760 50  0001 C CNN
F 3 "" H 2440 6760 50  0001 C CNN
	1    2440 6760
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01238
U 1 1 5C073216
P 2440 6560
F 0 "#PWR01238" H 2440 6410 50  0001 C CNN
F 1 "+3.3V" H 2440 6700 50  0000 C CNN
F 2 "" H 2440 6560 50  0001 C CNN
F 3 "" H 2440 6560 50  0001 C CNN
	1    2440 6560
	1    0    0    -1  
$EndComp
Wire Wire Line
	2690 6660 3180 6660
Wire Wire Line
	3180 6660 3180 6500
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C073222
P 2790 7250
AR Path="/5BAAE1F3/5C073222" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5C073222" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5C073222" Ref="C?"  Part="1" 
AR Path="/5BB844FD/5C073222" Ref="C1207"  Part="1" 
F 0 "C1207" H 2815 7350 50  0000 L CNN
F 1 "0.1uF" H 2815 7150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2828 7100 50  0001 C CNN
F 3 "" H 2815 7350 50  0001 C CNN
F 4 "311-1344-1-ND" H 3215 7750 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 2640 7350 50  0000 R CNN "display_footprint"
F 6 "50V" H 2640 7250 50  0000 R CNN "Voltage"
F 7 "X7R" H 2640 7150 50  0000 R CNN "Dielectric"
	1    2790 7250
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C073229
P 2790 7400
AR Path="/5BE48F98/5C073229" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5C073229" Ref="#PWR01241"  Part="1" 
F 0 "#PWR01241" H 2790 7150 50  0001 C CNN
F 1 "GND" H 2790 7250 50  0000 C CNN
F 2 "" H 2790 7400 50  0001 C CNN
F 3 "" H 2790 7400 50  0001 C CNN
	1    2790 7400
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01240
U 1 1 5C07322F
P 2790 7100
F 0 "#PWR01240" H 2790 6950 50  0001 C CNN
F 1 "+3.3V" H 2790 7240 50  0000 C CNN
F 2 "" H 2790 7100 50  0001 C CNN
F 3 "" H 2790 7100 50  0001 C CNN
	1    2790 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1390 6660 1790 6660
$Comp
L power:GND #PWR?
U 1 1 5C073236
P 1790 7080
AR Path="/5BE48F98/5C073236" Ref="#PWR?"  Part="1" 
AR Path="/5BB844FD/5C073236" Ref="#PWR01237"  Part="1" 
F 0 "#PWR01237" H 1790 6830 50  0001 C CNN
F 1 "GND" H 1790 6930 50  0000 C CNN
F 2 "" H 1790 7080 50  0001 C CNN
F 3 "" H 1790 7080 50  0001 C CNN
	1    1790 7080
	1    0    0    -1  
$EndComp
Wire Wire Line
	1790 6780 1790 6660
Connection ~ 1790 6660
Wire Wire Line
	1790 6660 2140 6660
Text GLabel 1390 6660 0    50   Input ~ 0
Other_Error_LED
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C073244
P 3180 6050
AR Path="/5BAAE1F3/5C073244" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C073244" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C073244" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C073244" Ref="R1214"  Part="1" 
F 0 "R1214" H 3120 6050 50  0000 R CNN
F 1 "1k" V 3180 6050 50  0000 C CNN
F 2 "" H 3180 6050 50  0001 C CNN
F 3 "" H 3180 6050 50  0001 C CNN
F 4 "0603" H 3250 6130 50  0000 L CNN "display_footprint"
F 5 "1%" H 3250 6050 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3250 5980 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT1K00CT-ND" H 3480 6450 60  0001 C CNN "Digi-Key PN"
	1    3180 6050
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5C07324F
P 1790 6930
AR Path="/5BAAE1F3/5C07324F" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5C07324F" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5C07324F" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5C07324F" Ref="R1213"  Part="1" 
F 0 "R1213" H 1730 6930 50  0000 R CNN
F 1 "10k" V 1790 6930 50  0000 C CNN
F 2 "" H 1790 6930 50  0001 C CNN
F 3 "" H 1790 6930 50  0001 C CNN
F 4 "0603" H 1860 7010 50  0000 L CNN "display_footprint"
F 5 "1%" H 1860 6930 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 1860 6860 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 2090 7330 60  0001 C CNN "Digi-Key PN"
	1    1790 6930
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1207
U 1 1 5C073256
P 3180 6350
F 0 "D1207" V 3218 5987 50  0000 L CNN
F 1 "Red" V 3127 6233 50  0000 R CNN
F 2 "" H 3180 6350 50  0001 C CNN
F 3 "~" H 3180 6350 50  0001 C CNN
F 4 "160-1447-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    3180 6350
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
