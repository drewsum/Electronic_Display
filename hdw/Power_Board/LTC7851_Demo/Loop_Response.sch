EESchema Schematic File Version 4
LIBS:LTC7851_Demo-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 14 14
Title "Electronic Display Power Board"
Date "2018-11-28"
Rev "A"
Comp "Marquette University Senior Design 2018/2019 Group E44"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Transformer_1P_1S T1401
U 1 1 5BC3161A
P 5000 3850
F 0 "T1401" H 5000 4100 50  0000 C CNN
F 1 "1:1 Pulse Transformer" H 5000 3550 50  0000 C CNN
F 2 "Custom Footprints Library:Murata_78601_9C" H 5000 3850 50  0001 C CNN
F 3 "~" H 5000 3850 50  0001 C CNN
F 4 "811-2650-ND" H 5000 3850 50  0001 C CNN "Digi-Key PN"
	1    5000 3850
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01403
U 1 1 5BC31B38
P 4520 3570
F 0 "#PWR01403" H 4520 3420 50  0001 C CNN
F 1 "+5V" H 4520 3710 50  0000 C CNN
F 2 "" H 4520 3570 50  0001 C CNN
F 3 "" H 4520 3570 50  0001 C CNN
	1    4520 3570
	1    0    0    -1  
$EndComp
Wire Wire Line
	4520 3570 4520 3650
Wire Wire Line
	4520 3650 4600 3650
Text GLabel 4600 4050 0    50   UnSpc ~ 0
LOOP_TAP
$Comp
L Connector_Generic:Conn_01x02 J1403
U 1 1 5BC3270C
P 5960 3810
F 0 "J1403" H 5960 3910 50  0000 C CNN
F 1 "Wave_Gen_In" H 5960 3610 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 5960 3810 50  0001 C CNN
F 3 "~" H 5960 3810 50  0001 C CNN
	1    5960 3810
	1    0    0    -1  
$EndComp
Wire Wire Line
	5760 3810 5640 3810
Wire Wire Line
	5640 3810 5640 3650
Wire Wire Line
	5640 3650 5400 3650
Wire Wire Line
	5760 3910 5640 3910
Wire Wire Line
	5640 3910 5640 4050
Wire Wire Line
	5640 4050 5400 4050
$Comp
L Connector_Generic:Conn_01x02 J1401
U 1 1 5BC32CA5
P 4600 5280
F 0 "J1401" H 4600 5380 50  0000 C CNN
F 1 "VOUT" H 4600 5080 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 4600 5280 50  0001 C CNN
F 3 "~" H 4600 5280 50  0001 C CNN
	1    4600 5280
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J1402
U 1 1 5BC32CDE
P 5660 5280
F 0 "J1402" H 5660 5380 50  0000 C CNN
F 1 "LOOP_TAP" H 5660 5080 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 5660 5280 50  0001 C CNN
F 3 "~" H 5660 5280 50  0001 C CNN
	1    5660 5280
	1    0    0    -1  
$EndComp
Text GLabel 5460 5280 0    50   UnSpc ~ 0
LOOP_TAP
$Comp
L power:GND #PWR01404
U 1 1 5BC32FE1
P 5380 5460
F 0 "#PWR01404" H 5380 5210 50  0001 C CNN
F 1 "GND" H 5380 5310 50  0000 C CNN
F 2 "" H 5380 5460 50  0001 C CNN
F 3 "" H 5380 5460 50  0001 C CNN
	1    5380 5460
	1    0    0    -1  
$EndComp
Wire Wire Line
	5380 5460 5380 5380
Wire Wire Line
	5380 5380 5460 5380
$Comp
L power:GND #PWR01402
U 1 1 5BC33094
P 4320 5460
F 0 "#PWR01402" H 4320 5210 50  0001 C CNN
F 1 "GND" H 4320 5310 50  0000 C CNN
F 2 "" H 4320 5460 50  0001 C CNN
F 3 "" H 4320 5460 50  0001 C CNN
	1    4320 5460
	1    0    0    -1  
$EndComp
Wire Wire Line
	4320 5460 4320 5380
Wire Wire Line
	4320 5380 4400 5380
$Comp
L power:+5V #PWR01401
U 1 1 5BC333D8
P 4320 5200
F 0 "#PWR01401" H 4320 5050 50  0001 C CNN
F 1 "+5V" H 4320 5340 50  0000 C CNN
F 2 "" H 4320 5200 50  0001 C CNN
F 3 "" H 4320 5200 50  0001 C CNN
	1    4320 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4320 5200 4320 5280
Wire Wire Line
	4320 5280 4400 5280
$Comp
L power:GND #PWR01405
U 1 1 5BD5340B
P 5640 4130
F 0 "#PWR01405" H 5640 3880 50  0001 C CNN
F 1 "GND" H 5640 3980 50  0000 C CNN
F 2 "" H 5640 4130 50  0001 C CNN
F 3 "" H 5640 4130 50  0001 C CNN
	1    5640 4130
	1    0    0    -1  
$EndComp
Wire Wire Line
	5640 4130 5640 4050
Connection ~ 5640 4050
Text Notes 540  690  0    100  ~ 20
14. Open Loop Transfer Function Test Components
$Comp
L LED_Display_Local_Library:MU_Logo #G?
U 1 1 5C003FC2
P 9900 1100
F 0 "#G?" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
Text Notes 6990 6050 0    50   ~ 0
Do not populate any components on this sheet
$EndSCHEMATC
