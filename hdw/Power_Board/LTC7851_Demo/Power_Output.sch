EESchema Schematic File Version 4
LIBS:LTC7851_Demo-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 9 14
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
L Connector:Screw_Terminal_01x01 J901
U 1 1 5BC3341B
P 5520 2650
F 0 "J901" H 5520 2750 50  0000 C CNN
F 1 "+5V OUT" H 5520 2550 50  0000 C CNN
F 2 "Custom Footprints Library:Wuerth_7461096_M4_Shank_9pos" H 5520 2650 50  0001 C CNN
F 3 "~" H 5520 2650 50  0001 C CNN
F 4 "732-3214-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    5520 2650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x01 J902
U 1 1 5BC33AA7
P 5520 2950
F 0 "J902" H 5520 3050 50  0000 C CNN
F 1 "+5V OUT" H 5520 2850 50  0000 C CNN
F 2 "Custom Footprints Library:Wuerth_7461096_M4_Shank_9pos" H 5520 2950 50  0001 C CNN
F 3 "~" H 5520 2950 50  0001 C CNN
F 4 "732-3214-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    5520 2950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0901
U 1 1 5BC33B1C
P 5240 2570
F 0 "#PWR0901" H 5240 2420 50  0001 C CNN
F 1 "+5V" H 5240 2710 50  0000 C CNN
F 2 "" H 5240 2570 50  0001 C CNN
F 3 "" H 5240 2570 50  0001 C CNN
	1    5240 2570
	1    0    0    -1  
$EndComp
Wire Wire Line
	5240 2570 5240 2650
Wire Wire Line
	5240 2650 5320 2650
Wire Wire Line
	5240 2650 5240 2950
Wire Wire Line
	5240 2950 5320 2950
Connection ~ 5240 2650
$Comp
L Connector:Screw_Terminal_01x01 J903
U 1 1 5BC33E64
P 5520 3280
F 0 "J903" H 5520 3380 50  0000 C CNN
F 1 "GND OUT" H 5520 3180 50  0000 C CNN
F 2 "Custom Footprints Library:Wuerth_7461096_M4_Shank_9pos" H 5520 3280 50  0001 C CNN
F 3 "~" H 5520 3280 50  0001 C CNN
F 4 "732-3214-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    5520 3280
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x01 J904
U 1 1 5BC341B2
P 5520 3570
F 0 "J904" H 5520 3670 50  0000 C CNN
F 1 "GND OUT" H 5520 3470 50  0000 C CNN
F 2 "Custom Footprints Library:Wuerth_7461096_M4_Shank_9pos" H 5520 3570 50  0001 C CNN
F 3 "~" H 5520 3570 50  0001 C CNN
F 4 "732-3214-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    5520 3570
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0902
U 1 1 5BC34225
P 5240 3650
F 0 "#PWR0902" H 5240 3400 50  0001 C CNN
F 1 "GND" H 5240 3500 50  0000 C CNN
F 2 "" H 5240 3650 50  0001 C CNN
F 3 "" H 5240 3650 50  0001 C CNN
	1    5240 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5240 3650 5240 3570
Wire Wire Line
	5240 3570 5320 3570
Wire Wire Line
	5240 3570 5240 3280
Wire Wire Line
	5240 3280 5320 3280
Connection ~ 5240 3570
Text Notes 3340 3220 0    50   ~ 0
Place bulk output caps close to terminals
Text Notes 540  690  0    100  ~ 20
Power Output
$EndSCHEMATC
