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
L Connector_Generic:Conn_02x04_Odd_Even J?
U 1 1 5BDCD8E7
P 3700 3540
F 0 "J?" H 3750 3740 50  0000 C CNN
F 1 "ESP8266 Socket" H 3750 3240 50  0000 C CNN
F 2 "" H 3700 3540 50  0001 C CNN
F 3 "~" H 3700 3540 50  0001 C CNN
	1    3700 3540
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0139
U 1 1 5BDCDEB4
P 3340 3980
F 0 "#PWR0139" H 3340 3730 50  0001 C CNN
F 1 "GND" H 3340 3830 50  0000 C CNN
F 2 "" H 3340 3980 50  0001 C CNN
F 3 "" H 3340 3980 50  0001 C CNN
	1    3340 3980
	1    0    0    -1  
$EndComp
Wire Wire Line
	3340 3980 3340 3440
Wire Wire Line
	3340 3440 3500 3440
Text GLabel 8600 3440 2    50   Output ~ 0
WIFI_UART_RX
Text GLabel 8600 3540 2    50   Input ~ 0
WIFI_CHPD
Text GLabel 8290 4040 2    40   Input ~ 0
~WIFI_RESET
$Comp
L power:+3.3V #PWR0140
U 1 1 5BDCEFF8
P 4200 3300
F 0 "#PWR0140" H 4200 3150 50  0001 C CNN
F 1 "+3.3V" H 4200 3440 50  0000 C CNN
F 2 "" H 4200 3300 50  0001 C CNN
F 3 "" H 4200 3300 50  0001 C CNN
	1    4200 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 3300 4200 3740
Wire Wire Line
	4200 3740 4000 3740
Text GLabel 2480 3740 0    50   Input ~ 0
WIFI_UART_TX
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5BDD13BB
P 5990 4110
AR Path="/5BAAE1F3/5BDD13BB" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5BDD13BB" Ref="C?"  Part="1" 
F 0 "C?" H 6015 4210 50  0000 L CNN
F 1 "0.1uF" H 6015 4010 50  0000 L CNN
F 2 "" H 6028 3960 50  0001 C CNN
F 3 "" H 6015 4210 50  0001 C CNN
F 4 "PN" H 6415 4610 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 5840 4210 50  0000 R CNN "display_footprint"
F 6 "50V" H 5840 4110 50  0000 R CNN "Voltage"
F 7 "X7R" H 5840 4010 50  0000 R CNN "Dielectric"
	1    5990 4110
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BDD13C6
P 5990 3070
AR Path="/5BAAE1F3/5BDD13C6" Ref="R?"  Part="1" 
AR Path="/5BAAE1CB/5BDD13C6" Ref="R?"  Part="1" 
F 0 "R?" V 5890 3070 50  0000 C CNN
F 1 "10k" V 5990 3070 50  0000 C CNN
F 2 "" H 5990 3070 50  0001 C CNN
F 3 "" H 5990 3070 50  0001 C CNN
F 4 "0603" H 6090 3160 50  0000 L CNN "display_footprint"
F 5 "1%" H 6090 3070 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 6100 2990 50  0000 L CNN "Wattage"
F 7 "PN" H 6290 3470 60  0001 C CNN "Digi-Key PN"
	1    5990 3070
	-1   0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0141
U 1 1 5BDD14E5
P 5990 2920
F 0 "#PWR0141" H 5990 2770 50  0001 C CNN
F 1 "+3.3V" H 5990 3060 50  0000 C CNN
F 2 "" H 5990 2920 50  0001 C CNN
F 3 "" H 5990 2920 50  0001 C CNN
	1    5990 2920
	1    0    0    -1  
$EndComp
Connection ~ 5990 3640
Wire Wire Line
	5990 3640 5990 3960
$Comp
L Custom_Library:2N7002 Q?
U 1 1 5BDD20D6
P 7430 4040
F 0 "Q?" H 7636 4086 50  0000 L CNN
F 1 "2N7002" H 7636 3995 50  0000 L CNN
F 2 "Housings_SOIC:PowerPAK_SO-8_Single" H 7630 3965 50  0001 L CIN
F 3 "http://www.vishay.com/docs/65543/sir836dp.pdf" H 7630 4115 50  0001 L CNN
F 4 "SIR836DP-T1-GE3CT-ND" H 7830 4315 60  0001 C CNN "Digi-Key PN"
	1    7430 4040
	-1   0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BDD215C
P 6950 3640
F 0 "R?" V 7050 3640 50  0000 C CNN
F 1 "100" V 6950 3640 50  0000 C CNN
F 2 "" H 6950 3640 50  0001 C CNN
F 3 "" H 6950 3640 50  0001 C CNN
F 4 "PN" H 7250 4040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 7050 3640 50  0001 C CNN "display_footprint"
F 6 "1%" V 7150 3640 50  0001 C CNN "Tolerance"
F 7 "1/10W" V 7250 3640 50  0001 C CNN "Wattage"
	1    6950 3640
	0    1    1    0   
$EndComp
Wire Wire Line
	6800 3640 6580 3640
$Comp
L power:GND #PWR0142
U 1 1 5BDD27D8
P 7330 4240
F 0 "#PWR0142" H 7330 3990 50  0001 C CNN
F 1 "GND" H 7330 4090 50  0000 C CNN
F 2 "" H 7330 4240 50  0001 C CNN
F 3 "" H 7330 4240 50  0001 C CNN
	1    7330 4240
	1    0    0    -1  
$EndComp
Wire Wire Line
	7330 3840 7330 3640
Wire Wire Line
	7330 3640 7100 3640
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BDD6978
P 7680 3070
AR Path="/5BB2595E/5BDD6978" Ref="R?"  Part="1" 
AR Path="/5BAAE1CB/5BDD6978" Ref="R?"  Part="1" 
F 0 "R?" V 7580 3070 50  0000 C CNN
F 1 "10k" V 7680 3070 50  0000 C CNN
F 2 "" H 7680 3070 50  0001 C CNN
F 3 "" H 7680 3070 50  0001 C CNN
F 4 "PN" H 7980 3470 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 7760 3150 50  0000 L CNN "display_footprint"
F 6 "1%" H 7760 3070 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 7760 2990 50  0000 L CNN "Wattage"
	1    7680 3070
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BDD6AE7
P 8140 4040
F 0 "R?" V 8040 4040 50  0000 C CNN
F 1 "10" V 8140 4040 50  0000 C CNN
F 2 "" H 8140 4040 50  0001 C CNN
F 3 "" H 8140 4040 50  0001 C CNN
F 4 "PN" H 8440 4440 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 8240 4040 50  0000 C CNN "display_footprint"
F 6 "1%" V 8340 4040 50  0000 C CNN "Tolerance"
F 7 "1/10W" V 8440 4040 50  0000 C CNN "Wattage"
	1    8140 4040
	0    1    -1   0   
$EndComp
Wire Wire Line
	7630 4040 7680 4040
Connection ~ 7680 4040
Wire Wire Line
	7680 4040 7990 4040
$Comp
L power:+3.3V #PWR0143
U 1 1 5BDD84D0
P 7680 2920
F 0 "#PWR0143" H 7680 2770 50  0001 C CNN
F 1 "+3.3V" H 7680 3060 50  0000 C CNN
F 2 "" H 7680 2920 50  0001 C CNN
F 3 "" H 7680 2920 50  0001 C CNN
	1    7680 2920
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BDD96BA
P 4560 4110
AR Path="/5BAAE1F3/5BDD96BA" Ref="R?"  Part="1" 
AR Path="/5BAAE1CB/5BDD96BA" Ref="R?"  Part="1" 
F 0 "R?" V 4460 4110 50  0000 C CNN
F 1 "10k" V 4560 4110 50  0000 C CNN
F 2 "" H 4560 4110 50  0001 C CNN
F 3 "" H 4560 4110 50  0001 C CNN
F 4 "0603" H 4660 4200 50  0000 L CNN "display_footprint"
F 5 "1%" H 4660 4110 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 4670 4030 50  0000 L CNN "Wattage"
F 7 "PN" H 4860 4510 60  0001 C CNN "Digi-Key PN"
	1    4560 4110
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BDD96FC
P 4560 3070
AR Path="/5BAAE1F3/5BDD96FC" Ref="R?"  Part="1" 
AR Path="/5BAAE1CB/5BDD96FC" Ref="R?"  Part="1" 
F 0 "R?" V 4460 3070 50  0000 C CNN
F 1 "10k" V 4560 3070 50  0000 C CNN
F 2 "" H 4560 3070 50  0001 C CNN
F 3 "" H 4560 3070 50  0001 C CNN
F 4 "0603" H 4660 3160 50  0000 L CNN "display_footprint"
F 5 "1%" H 4660 3070 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 4670 2990 50  0000 L CNN "Wattage"
F 7 "PN" H 4860 3470 60  0001 C CNN "Digi-Key PN"
	1    4560 3070
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0144
U 1 1 5BDD975B
P 4560 4260
F 0 "#PWR0144" H 4560 4010 50  0001 C CNN
F 1 "GND" H 4560 4110 50  0000 C CNN
F 2 "" H 4560 4260 50  0001 C CNN
F 3 "" H 4560 4260 50  0001 C CNN
	1    4560 4260
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0145
U 1 1 5BDD97C8
P 4560 2920
F 0 "#PWR0145" H 4560 2770 50  0001 C CNN
F 1 "+3.3V" H 4560 3060 50  0000 C CNN
F 2 "" H 4560 2920 50  0001 C CNN
F 3 "" H 4560 2920 50  0001 C CNN
	1    4560 2920
	1    0    0    -1  
$EndComp
Wire Wire Line
	5990 3220 5990 3640
Wire Wire Line
	7680 3220 7680 4040
Wire Wire Line
	4000 3440 4560 3440
Text Notes 2840 4880 0    50   ~ 0
ESP8266 Pinout does not match default KiCad pin socket footprint. \nAlter the pin numbers in layout
Wire Wire Line
	4560 3960 4560 3540
Wire Wire Line
	4560 3540 4000 3540
Wire Wire Line
	4560 3440 4560 3220
$Comp
L power:GND #PWR0146
U 1 1 5BDDE1AF
P 5990 4260
F 0 "#PWR0146" H 5990 4010 50  0001 C CNN
F 1 "GND" H 5990 4110 50  0000 C CNN
F 2 "" H 5990 4260 50  0001 C CNN
F 3 "" H 5990 4260 50  0001 C CNN
	1    5990 4260
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BDDFE41
P 3020 3070
AR Path="/5BAAE1F3/5BDDFE41" Ref="R?"  Part="1" 
AR Path="/5BAAE1CB/5BDDFE41" Ref="R?"  Part="1" 
F 0 "R?" V 2920 3070 50  0000 C CNN
F 1 "10k" V 3020 3070 50  0000 C CNN
F 2 "" H 3020 3070 50  0001 C CNN
F 3 "" H 3020 3070 50  0001 C CNN
F 4 "0603" H 3120 3160 50  0000 L CNN "display_footprint"
F 5 "1%" H 3120 3070 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3130 2990 50  0000 L CNN "Wattage"
F 7 "PN" H 3320 3470 60  0001 C CNN "Digi-Key PN"
	1    3020 3070
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3020 3220 3020 3740
Wire Wire Line
	3020 3740 3500 3740
$Comp
L power:+3.3V #PWR0147
U 1 1 5BDE065C
P 3020 2920
F 0 "#PWR0147" H 3020 2770 50  0001 C CNN
F 1 "+3.3V" H 3020 3060 50  0000 C CNN
F 2 "" H 3020 2920 50  0001 C CNN
F 3 "" H 3020 2920 50  0001 C CNN
	1    3020 2920
	1    0    0    -1  
$EndComp
Wire Wire Line
	2780 3740 3020 3740
Connection ~ 3020 3740
NoConn ~ 3500 3540
NoConn ~ 3500 3640
Wire Wire Line
	4560 3440 5160 3440
Connection ~ 4560 3440
Connection ~ 4560 3540
Wire Wire Line
	4000 3640 5990 3640
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE3C385
P 8450 3440
AR Path="/5BAAE2B6/5BE3C385" Ref="R?"  Part="1" 
AR Path="/5BB6CF6D/5BE3C385" Ref="R?"  Part="1" 
AR Path="/5BBE424C/5BE3C385" Ref="R?"  Part="1" 
AR Path="/5BAAE1CB/5BE3C385" Ref="R?"  Part="1" 
F 0 "R?" V 8410 3300 50  0000 R CNN
F 1 "100" V 8450 3440 50  0000 C CNN
F 2 "" H 8450 3440 50  0001 C CNN
F 3 "" H 8450 3440 50  0001 C CNN
F 4 "0603" V 8550 3440 50  0001 C CNN "display_footprint"
F 5 "1%" V 8650 3440 50  0001 C CNN "Tolerance"
F 6 "1/10W" V 8750 3440 50  0001 C CNN "Wattage"
F 7 "PN" H 8750 3840 60  0001 C CNN "Digi-Key PN"
	1    8450 3440
	0    1    1    0   
$EndComp
$Comp
L LED_Display_Local_Library:R_Custom R?
U 1 1 5BE3C39B
P 2630 3740
AR Path="/5BAAE2B6/5BE3C39B" Ref="R?"  Part="1" 
AR Path="/5BB6CF6D/5BE3C39B" Ref="R?"  Part="1" 
AR Path="/5BBE424C/5BE3C39B" Ref="R?"  Part="1" 
AR Path="/5BAAE1CB/5BE3C39B" Ref="R?"  Part="1" 
F 0 "R?" V 2590 3600 50  0000 R CNN
F 1 "100" V 2630 3740 50  0000 C CNN
F 2 "" H 2630 3740 50  0001 C CNN
F 3 "" H 2630 3740 50  0001 C CNN
F 4 "0603" V 2730 3740 50  0001 C CNN "display_footprint"
F 5 "1%" V 2830 3740 50  0001 C CNN "Tolerance"
F 6 "1/10W" V 2930 3740 50  0001 C CNN "Wattage"
F 7 "PN" H 2930 4140 60  0001 C CNN "Digi-Key PN"
	1    2630 3740
	0    -1   1    0   
$EndComp
Wire Wire Line
	4560 3540 5500 3540
$Comp
L Power_Protection:PESD3V3L4UG D?
U 1 1 5BFC1C6A
P 3020 4070
F 0 "D?" V 2974 4003 50  0000 R CNN
F 1 "PESD3V3L4UG" V 3065 4003 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-353_SC-70-5" H 3020 4070 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/PESDXL4UF_G_W.pdf" H 3020 4070 50  0001 C CNN
	1    3020 4070
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BFC1E28
P 3020 4170
F 0 "#PWR?" H 3020 3920 50  0001 C CNN
F 1 "GND" H 3020 4020 50  0000 C CNN
F 2 "" H 3020 4170 50  0001 C CNN
F 3 "" H 3020 4170 50  0001 C CNN
	1    3020 4170
	1    0    0    -1  
$EndComp
Wire Wire Line
	3020 3970 3020 3740
$Comp
L Power_Protection:PESD3V3L4UG D?
U 2 1 5BFC409A
P 5160 4070
F 0 "D?" H 5160 4170 50  0000 C CNN
F 1 "PESD3V3L4UG" H 5160 3970 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-353_SC-70-5" H 5160 4070 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/PESDXL4UF_G_W.pdf" H 5160 4070 50  0001 C CNN
	2    5160 4070
	0    1    1    0   
$EndComp
Wire Wire Line
	5160 3970 5160 3440
Connection ~ 5160 3440
Wire Wire Line
	5160 3440 8300 3440
$Comp
L Power_Protection:PESD3V3L4UG D?
U 3 1 5BFC4F76
P 5500 4070
F 0 "D?" H 5500 4170 50  0000 C CNN
F 1 "PESD3V3L4UG" H 5500 3970 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-353_SC-70-5" H 5500 4070 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/PESDXL4UF_G_W.pdf" H 5500 4070 50  0001 C CNN
	3    5500 4070
	0    1    1    0   
$EndComp
Wire Wire Line
	5500 3970 5500 3540
Connection ~ 5500 3540
Wire Wire Line
	5500 3540 8600 3540
$Comp
L Power_Protection:PESD3V3L4UG D?
U 3 1 5BFC9B68
P 6580 4070
F 0 "D?" H 6580 4170 50  0000 C CNN
F 1 "PESD3V3L4UG" H 6580 3970 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-353_SC-70-5" H 6580 4070 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/PESDXL4UF_G_W.pdf" H 6580 4070 50  0001 C CNN
	3    6580 4070
	0    1    1    0   
$EndComp
Wire Wire Line
	6580 3970 6580 3640
Connection ~ 6580 3640
Wire Wire Line
	6580 3640 5990 3640
$Comp
L Graphic:SYM_ESD_Large #SYM?
U 1 1 5C001643
P 3850 4210
F 0 "#SYM?" H 3850 4410 50  0001 C CNN
F 1 "SYM_ESD_Large" H 3850 3960 50  0001 C CNN
F 2 "" H 3845 4180 50  0001 C CNN
F 3 "~" H 3845 4180 50  0001 C CNN
	1    3850 4210
	1    0    0    -1  
$EndComp
$EndSCHEMATC
