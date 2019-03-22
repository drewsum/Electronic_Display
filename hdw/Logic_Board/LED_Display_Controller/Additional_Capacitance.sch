EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 32 32
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
L LED_Display_Local_Library:MU_Logo #G3201
U 1 1 5C1B3F68
P 9900 1100
F 0 "#G3201" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
Text Notes 550  700  0    100  ~ 20
32. Additional Capacitance
$Comp
L LED_Display_Local_Library:CP_Tant_Custom C?
U 1 1 5C1BF699
P 1600 3620
AR Path="/5BB181D8/5C1BF699" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C1BF699" Ref="C3202"  Part="1" 
F 0 "C3202" H 1625 3720 50  0000 L CNN
F 1 "100uF" H 1625 3520 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Reflow" H 1638 3470 50  0001 C CNN
F 3 "" H 1625 3720 50  0001 C CNN
F 4 "478-3130-1-ND" H 1600 3620 50  0001 C CNN "Digi-Key PN"
F 5 "3528" H 1450 3720 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 1450 3620 50  0000 R CNN "Voltage"
F 7 "20%" H 1450 3520 50  0000 R CNN "Tolerance"
	1    1600 3620
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1BF6A6
P 1600 3770
AR Path="/5BB181D8/5C1BF6A6" Ref="#PWR?"  Part="1" 
AR Path="/5C1AA7A5/5C1BF6A6" Ref="#PWR03204"  Part="1" 
F 0 "#PWR03204" H 1600 3520 50  0001 C CNN
F 1 "GND" H 1600 3620 50  0000 C CNN
F 2 "" H 1600 3770 50  0001 C CNN
F 3 "" H 1600 3770 50  0001 C CNN
	1    1600 3770
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03203
U 1 1 5C1BF6D8
P 1600 3470
F 0 "#PWR03203" H 1600 3320 50  0001 C CNN
F 1 "+5V" H 1600 3610 50  0000 C CNN
F 2 "" H 1600 3470 50  0001 C CNN
F 3 "" H 1600 3470 50  0001 C CNN
	1    1600 3470
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:CP_Tant_Custom C?
U 1 1 5C1BF71E
P 2440 3620
AR Path="/5BB181D8/5C1BF71E" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C1BF71E" Ref="C3203"  Part="1" 
F 0 "C3203" H 2465 3720 50  0000 L CNN
F 1 "100uF" H 2465 3520 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Reflow" H 2478 3470 50  0001 C CNN
F 3 "" H 2465 3720 50  0001 C CNN
F 4 "478-3130-1-ND" H 2440 3620 50  0001 C CNN "Digi-Key PN"
F 5 "3528" H 2290 3720 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 2290 3620 50  0000 R CNN "Voltage"
F 7 "20%" H 2290 3520 50  0000 R CNN "Tolerance"
	1    2440 3620
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1BF725
P 2440 3770
AR Path="/5BB181D8/5C1BF725" Ref="#PWR?"  Part="1" 
AR Path="/5C1AA7A5/5C1BF725" Ref="#PWR03206"  Part="1" 
F 0 "#PWR03206" H 2440 3520 50  0001 C CNN
F 1 "GND" H 2440 3620 50  0000 C CNN
F 2 "" H 2440 3770 50  0001 C CNN
F 3 "" H 2440 3770 50  0001 C CNN
	1    2440 3770
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03205
U 1 1 5C1BF72B
P 2440 3470
F 0 "#PWR03205" H 2440 3320 50  0001 C CNN
F 1 "+5V" H 2440 3610 50  0000 C CNN
F 2 "" H 2440 3470 50  0001 C CNN
F 3 "" H 2440 3470 50  0001 C CNN
	1    2440 3470
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:CP_Tant_Custom C?
U 1 1 5C1C4382
P 1600 1960
AR Path="/5BB181D8/5C1C4382" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C1C4382" Ref="C3201"  Part="1" 
F 0 "C3201" H 1625 2060 50  0000 L CNN
F 1 "100uF" H 1625 1860 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Reflow" H 1638 1810 50  0001 C CNN
F 3 "" H 1625 2060 50  0001 C CNN
F 4 "478-3130-1-ND" H 1600 1960 50  0001 C CNN "Digi-Key PN"
F 5 "3528" H 1450 2060 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 1450 1960 50  0000 R CNN "Voltage"
F 7 "20%" H 1450 1860 50  0000 R CNN "Tolerance"
	1    1600 1960
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1C4389
P 1600 2110
AR Path="/5BB181D8/5C1C4389" Ref="#PWR?"  Part="1" 
AR Path="/5C1AA7A5/5C1C4389" Ref="#PWR03202"  Part="1" 
F 0 "#PWR03202" H 1600 1860 50  0001 C CNN
F 1 "GND" H 1600 1960 50  0000 C CNN
F 2 "" H 1600 2110 50  0001 C CNN
F 3 "" H 1600 2110 50  0001 C CNN
	1    1600 2110
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR03201
U 1 1 5C1C43D7
P 1600 1810
F 0 "#PWR03201" H 1600 1660 50  0001 C CNN
F 1 "+3.3V" H 1600 1950 50  0000 C CNN
F 2 "" H 1600 1810 50  0001 C CNN
F 3 "" H 1600 1810 50  0001 C CNN
	1    1600 1810
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C37ED58
P 5220 2540
AR Path="/5BAAE10E/5C37ED58" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C37ED58" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C37ED58" Ref="C3204"  Part="1" 
F 0 "C3204" V 4696 2540 50  0000 C CNN
F 1 "330pF" V 4787 2540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 5258 2390 50  0001 C CNN
F 3 "" H 5245 2640 50  0001 C CNN
F 4 "399-6880-1-ND" H 5645 3040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 4878 2540 50  0000 C CNN "display_footprint"
F 6 "50V" V 4969 2540 50  0000 C CNN "Voltage"
F 7 "NP0" V 5060 2540 50  0000 C CNN "Dielectric"
	1    5220 2540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03211
U 1 1 5C37EEE8
P 5370 2540
F 0 "#PWR03211" H 5370 2390 50  0001 C CNN
F 1 "+5V" V 5370 2680 50  0000 L CNN
F 2 "" H 5370 2540 50  0001 C CNN
F 3 "" H 5370 2540 50  0001 C CNN
	1    5370 2540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03207
U 1 1 5C37EF59
P 5070 2540
F 0 "#PWR03207" H 5070 2390 50  0001 C CNN
F 1 "+3.3V" V 5070 2680 50  0000 L CNN
F 2 "" H 5070 2540 50  0001 C CNN
F 3 "" H 5070 2540 50  0001 C CNN
	1    5070 2540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C3817B4
P 6520 2540
AR Path="/5BAAE10E/5C3817B4" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C3817B4" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C3817B4" Ref="C3208"  Part="1" 
F 0 "C3208" V 5996 2540 50  0000 C CNN
F 1 "330pF" V 6087 2540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 6558 2390 50  0001 C CNN
F 3 "" H 6545 2640 50  0001 C CNN
F 4 "399-6880-1-ND" H 6945 3040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 6178 2540 50  0000 C CNN "display_footprint"
F 6 "50V" V 6269 2540 50  0000 C CNN "Voltage"
F 7 "NP0" V 6360 2540 50  0000 C CNN "Dielectric"
	1    6520 2540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03219
U 1 1 5C3817BB
P 6670 2540
F 0 "#PWR03219" H 6670 2390 50  0001 C CNN
F 1 "+5V" V 6670 2680 50  0000 L CNN
F 2 "" H 6670 2540 50  0001 C CNN
F 3 "" H 6670 2540 50  0001 C CNN
	1    6670 2540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03215
U 1 1 5C3817C1
P 6370 2540
F 0 "#PWR03215" H 6370 2390 50  0001 C CNN
F 1 "+3.3V" V 6370 2680 50  0000 L CNN
F 2 "" H 6370 2540 50  0001 C CNN
F 3 "" H 6370 2540 50  0001 C CNN
	1    6370 2540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C381836
P 7820 2540
AR Path="/5BAAE10E/5C381836" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C381836" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C381836" Ref="C3212"  Part="1" 
F 0 "C3212" V 7296 2540 50  0000 C CNN
F 1 "330pF" V 7387 2540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 7858 2390 50  0001 C CNN
F 3 "" H 7845 2640 50  0001 C CNN
F 4 "399-6880-1-ND" H 8245 3040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 7478 2540 50  0000 C CNN "display_footprint"
F 6 "50V" V 7569 2540 50  0000 C CNN "Voltage"
F 7 "NP0" V 7660 2540 50  0000 C CNN "Dielectric"
	1    7820 2540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03227
U 1 1 5C38183D
P 7970 2540
F 0 "#PWR03227" H 7970 2390 50  0001 C CNN
F 1 "+5V" V 7970 2680 50  0000 L CNN
F 2 "" H 7970 2540 50  0001 C CNN
F 3 "" H 7970 2540 50  0001 C CNN
	1    7970 2540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03223
U 1 1 5C381843
P 7670 2540
F 0 "#PWR03223" H 7670 2390 50  0001 C CNN
F 1 "+3.3V" V 7670 2680 50  0000 L CNN
F 2 "" H 7670 2540 50  0001 C CNN
F 3 "" H 7670 2540 50  0001 C CNN
	1    7670 2540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C3818C8
P 9120 2540
AR Path="/5BAAE10E/5C3818C8" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C3818C8" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C3818C8" Ref="C3216"  Part="1" 
F 0 "C3216" V 8596 2540 50  0000 C CNN
F 1 "330pF" V 8687 2540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 9158 2390 50  0001 C CNN
F 3 "" H 9145 2640 50  0001 C CNN
F 4 "399-6880-1-ND" H 9545 3040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 8778 2540 50  0000 C CNN "display_footprint"
F 6 "50V" V 8869 2540 50  0000 C CNN "Voltage"
F 7 "NP0" V 8960 2540 50  0000 C CNN "Dielectric"
	1    9120 2540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03235
U 1 1 5C3818CF
P 9270 2540
F 0 "#PWR03235" H 9270 2390 50  0001 C CNN
F 1 "+5V" V 9270 2680 50  0000 L CNN
F 2 "" H 9270 2540 50  0001 C CNN
F 3 "" H 9270 2540 50  0001 C CNN
	1    9270 2540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03231
U 1 1 5C3818D5
P 8970 2540
F 0 "#PWR03231" H 8970 2390 50  0001 C CNN
F 1 "+3.3V" V 8970 2680 50  0000 L CNN
F 2 "" H 8970 2540 50  0001 C CNN
F 3 "" H 8970 2540 50  0001 C CNN
	1    8970 2540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C384206
P 5220 3540
AR Path="/5BAAE10E/5C384206" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C384206" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C384206" Ref="C3205"  Part="1" 
F 0 "C3205" V 4696 3540 50  0000 C CNN
F 1 "330pF" V 4787 3540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 5258 3390 50  0001 C CNN
F 3 "" H 5245 3640 50  0001 C CNN
F 4 "399-6880-1-ND" H 5645 4040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 4878 3540 50  0000 C CNN "display_footprint"
F 6 "50V" V 4969 3540 50  0000 C CNN "Voltage"
F 7 "NP0" V 5060 3540 50  0000 C CNN "Dielectric"
	1    5220 3540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03212
U 1 1 5C38420D
P 5370 3540
F 0 "#PWR03212" H 5370 3390 50  0001 C CNN
F 1 "+5V" V 5370 3680 50  0000 L CNN
F 2 "" H 5370 3540 50  0001 C CNN
F 3 "" H 5370 3540 50  0001 C CNN
	1    5370 3540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03208
U 1 1 5C384213
P 5070 3540
F 0 "#PWR03208" H 5070 3390 50  0001 C CNN
F 1 "+3.3V" V 5070 3680 50  0000 L CNN
F 2 "" H 5070 3540 50  0001 C CNN
F 3 "" H 5070 3540 50  0001 C CNN
	1    5070 3540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C38421D
P 6520 3540
AR Path="/5BAAE10E/5C38421D" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C38421D" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C38421D" Ref="C3209"  Part="1" 
F 0 "C3209" V 5996 3540 50  0000 C CNN
F 1 "330pF" V 6087 3540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 6558 3390 50  0001 C CNN
F 3 "" H 6545 3640 50  0001 C CNN
F 4 "399-6880-1-ND" H 6945 4040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 6178 3540 50  0000 C CNN "display_footprint"
F 6 "50V" V 6269 3540 50  0000 C CNN "Voltage"
F 7 "NP0" V 6360 3540 50  0000 C CNN "Dielectric"
	1    6520 3540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03220
U 1 1 5C384224
P 6670 3540
F 0 "#PWR03220" H 6670 3390 50  0001 C CNN
F 1 "+5V" V 6670 3680 50  0000 L CNN
F 2 "" H 6670 3540 50  0001 C CNN
F 3 "" H 6670 3540 50  0001 C CNN
	1    6670 3540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03216
U 1 1 5C38422A
P 6370 3540
F 0 "#PWR03216" H 6370 3390 50  0001 C CNN
F 1 "+3.3V" V 6370 3680 50  0000 L CNN
F 2 "" H 6370 3540 50  0001 C CNN
F 3 "" H 6370 3540 50  0001 C CNN
	1    6370 3540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C384234
P 7820 3540
AR Path="/5BAAE10E/5C384234" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C384234" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C384234" Ref="C3213"  Part="1" 
F 0 "C3213" V 7296 3540 50  0000 C CNN
F 1 "330pF" V 7387 3540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 7858 3390 50  0001 C CNN
F 3 "" H 7845 3640 50  0001 C CNN
F 4 "399-6880-1-ND" H 8245 4040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 7478 3540 50  0000 C CNN "display_footprint"
F 6 "50V" V 7569 3540 50  0000 C CNN "Voltage"
F 7 "NP0" V 7660 3540 50  0000 C CNN "Dielectric"
	1    7820 3540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03228
U 1 1 5C38423B
P 7970 3540
F 0 "#PWR03228" H 7970 3390 50  0001 C CNN
F 1 "+5V" V 7970 3680 50  0000 L CNN
F 2 "" H 7970 3540 50  0001 C CNN
F 3 "" H 7970 3540 50  0001 C CNN
	1    7970 3540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03224
U 1 1 5C384241
P 7670 3540
F 0 "#PWR03224" H 7670 3390 50  0001 C CNN
F 1 "+3.3V" V 7670 3680 50  0000 L CNN
F 2 "" H 7670 3540 50  0001 C CNN
F 3 "" H 7670 3540 50  0001 C CNN
	1    7670 3540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C38424B
P 9120 3540
AR Path="/5BAAE10E/5C38424B" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C38424B" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C38424B" Ref="C3217"  Part="1" 
F 0 "C3217" V 8596 3540 50  0000 C CNN
F 1 "330pF" V 8687 3540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 9158 3390 50  0001 C CNN
F 3 "" H 9145 3640 50  0001 C CNN
F 4 "399-6880-1-ND" H 9545 4040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 8778 3540 50  0000 C CNN "display_footprint"
F 6 "50V" V 8869 3540 50  0000 C CNN "Voltage"
F 7 "NP0" V 8960 3540 50  0000 C CNN "Dielectric"
	1    9120 3540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03236
U 1 1 5C384252
P 9270 3540
F 0 "#PWR03236" H 9270 3390 50  0001 C CNN
F 1 "+5V" V 9270 3680 50  0000 L CNN
F 2 "" H 9270 3540 50  0001 C CNN
F 3 "" H 9270 3540 50  0001 C CNN
	1    9270 3540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03232
U 1 1 5C384258
P 8970 3540
F 0 "#PWR03232" H 8970 3390 50  0001 C CNN
F 1 "+3.3V" V 8970 3680 50  0000 L CNN
F 2 "" H 8970 3540 50  0001 C CNN
F 3 "" H 8970 3540 50  0001 C CNN
	1    8970 3540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C384374
P 5220 4540
AR Path="/5BAAE10E/5C384374" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C384374" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C384374" Ref="C3206"  Part="1" 
F 0 "C3206" V 4696 4540 50  0000 C CNN
F 1 "330pF" V 4787 4540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 5258 4390 50  0001 C CNN
F 3 "" H 5245 4640 50  0001 C CNN
F 4 "399-6880-1-ND" H 5645 5040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 4878 4540 50  0000 C CNN "display_footprint"
F 6 "50V" V 4969 4540 50  0000 C CNN "Voltage"
F 7 "NP0" V 5060 4540 50  0000 C CNN "Dielectric"
	1    5220 4540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03213
U 1 1 5C38437B
P 5370 4540
F 0 "#PWR03213" H 5370 4390 50  0001 C CNN
F 1 "+5V" V 5370 4680 50  0000 L CNN
F 2 "" H 5370 4540 50  0001 C CNN
F 3 "" H 5370 4540 50  0001 C CNN
	1    5370 4540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03209
U 1 1 5C384381
P 5070 4540
F 0 "#PWR03209" H 5070 4390 50  0001 C CNN
F 1 "+3.3V" V 5070 4680 50  0000 L CNN
F 2 "" H 5070 4540 50  0001 C CNN
F 3 "" H 5070 4540 50  0001 C CNN
	1    5070 4540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C38438B
P 6520 4540
AR Path="/5BAAE10E/5C38438B" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C38438B" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C38438B" Ref="C3210"  Part="1" 
F 0 "C3210" V 5996 4540 50  0000 C CNN
F 1 "330pF" V 6087 4540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 6558 4390 50  0001 C CNN
F 3 "" H 6545 4640 50  0001 C CNN
F 4 "399-6880-1-ND" H 6945 5040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 6178 4540 50  0000 C CNN "display_footprint"
F 6 "50V" V 6269 4540 50  0000 C CNN "Voltage"
F 7 "NP0" V 6360 4540 50  0000 C CNN "Dielectric"
	1    6520 4540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03221
U 1 1 5C384392
P 6670 4540
F 0 "#PWR03221" H 6670 4390 50  0001 C CNN
F 1 "+5V" V 6670 4680 50  0000 L CNN
F 2 "" H 6670 4540 50  0001 C CNN
F 3 "" H 6670 4540 50  0001 C CNN
	1    6670 4540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03217
U 1 1 5C384398
P 6370 4540
F 0 "#PWR03217" H 6370 4390 50  0001 C CNN
F 1 "+3.3V" V 6370 4680 50  0000 L CNN
F 2 "" H 6370 4540 50  0001 C CNN
F 3 "" H 6370 4540 50  0001 C CNN
	1    6370 4540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C3843A2
P 7820 4540
AR Path="/5BAAE10E/5C3843A2" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C3843A2" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C3843A2" Ref="C3214"  Part="1" 
F 0 "C3214" V 7296 4540 50  0000 C CNN
F 1 "330pF" V 7387 4540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 7858 4390 50  0001 C CNN
F 3 "" H 7845 4640 50  0001 C CNN
F 4 "399-6880-1-ND" H 8245 5040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 7478 4540 50  0000 C CNN "display_footprint"
F 6 "50V" V 7569 4540 50  0000 C CNN "Voltage"
F 7 "NP0" V 7660 4540 50  0000 C CNN "Dielectric"
	1    7820 4540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03229
U 1 1 5C3843A9
P 7970 4540
F 0 "#PWR03229" H 7970 4390 50  0001 C CNN
F 1 "+5V" V 7970 4680 50  0000 L CNN
F 2 "" H 7970 4540 50  0001 C CNN
F 3 "" H 7970 4540 50  0001 C CNN
	1    7970 4540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03225
U 1 1 5C3843AF
P 7670 4540
F 0 "#PWR03225" H 7670 4390 50  0001 C CNN
F 1 "+3.3V" V 7670 4680 50  0000 L CNN
F 2 "" H 7670 4540 50  0001 C CNN
F 3 "" H 7670 4540 50  0001 C CNN
	1    7670 4540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C3843B9
P 9120 4540
AR Path="/5BAAE10E/5C3843B9" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C3843B9" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C3843B9" Ref="C3218"  Part="1" 
F 0 "C3218" V 8596 4540 50  0000 C CNN
F 1 "330pF" V 8687 4540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 9158 4390 50  0001 C CNN
F 3 "" H 9145 4640 50  0001 C CNN
F 4 "399-6880-1-ND" H 9545 5040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 8778 4540 50  0000 C CNN "display_footprint"
F 6 "50V" V 8869 4540 50  0000 C CNN "Voltage"
F 7 "NP0" V 8960 4540 50  0000 C CNN "Dielectric"
	1    9120 4540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03237
U 1 1 5C3843C0
P 9270 4540
F 0 "#PWR03237" H 9270 4390 50  0001 C CNN
F 1 "+5V" V 9270 4680 50  0000 L CNN
F 2 "" H 9270 4540 50  0001 C CNN
F 3 "" H 9270 4540 50  0001 C CNN
	1    9270 4540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03233
U 1 1 5C3843C6
P 8970 4540
F 0 "#PWR03233" H 8970 4390 50  0001 C CNN
F 1 "+3.3V" V 8970 4680 50  0000 L CNN
F 2 "" H 8970 4540 50  0001 C CNN
F 3 "" H 8970 4540 50  0001 C CNN
	1    8970 4540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C386D3B
P 5220 5540
AR Path="/5BAAE10E/5C386D3B" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C386D3B" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C386D3B" Ref="C3207"  Part="1" 
F 0 "C3207" V 4696 5540 50  0000 C CNN
F 1 "330pF" V 4787 5540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 5258 5390 50  0001 C CNN
F 3 "" H 5245 5640 50  0001 C CNN
F 4 "399-6880-1-ND" H 5645 6040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 4878 5540 50  0000 C CNN "display_footprint"
F 6 "50V" V 4969 5540 50  0000 C CNN "Voltage"
F 7 "NP0" V 5060 5540 50  0000 C CNN "Dielectric"
	1    5220 5540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03214
U 1 1 5C386D42
P 5370 5540
F 0 "#PWR03214" H 5370 5390 50  0001 C CNN
F 1 "+5V" V 5370 5680 50  0000 L CNN
F 2 "" H 5370 5540 50  0001 C CNN
F 3 "" H 5370 5540 50  0001 C CNN
	1    5370 5540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03210
U 1 1 5C386D48
P 5070 5540
F 0 "#PWR03210" H 5070 5390 50  0001 C CNN
F 1 "+3.3V" V 5070 5680 50  0000 L CNN
F 2 "" H 5070 5540 50  0001 C CNN
F 3 "" H 5070 5540 50  0001 C CNN
	1    5070 5540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C386D52
P 6520 5540
AR Path="/5BAAE10E/5C386D52" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C386D52" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C386D52" Ref="C3211"  Part="1" 
F 0 "C3211" V 5996 5540 50  0000 C CNN
F 1 "330pF" V 6087 5540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 6558 5390 50  0001 C CNN
F 3 "" H 6545 5640 50  0001 C CNN
F 4 "399-6880-1-ND" H 6945 6040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 6178 5540 50  0000 C CNN "display_footprint"
F 6 "50V" V 6269 5540 50  0000 C CNN "Voltage"
F 7 "NP0" V 6360 5540 50  0000 C CNN "Dielectric"
	1    6520 5540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03222
U 1 1 5C386D59
P 6670 5540
F 0 "#PWR03222" H 6670 5390 50  0001 C CNN
F 1 "+5V" V 6670 5680 50  0000 L CNN
F 2 "" H 6670 5540 50  0001 C CNN
F 3 "" H 6670 5540 50  0001 C CNN
	1    6670 5540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03218
U 1 1 5C386D5F
P 6370 5540
F 0 "#PWR03218" H 6370 5390 50  0001 C CNN
F 1 "+3.3V" V 6370 5680 50  0000 L CNN
F 2 "" H 6370 5540 50  0001 C CNN
F 3 "" H 6370 5540 50  0001 C CNN
	1    6370 5540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C386D69
P 7820 5540
AR Path="/5BAAE10E/5C386D69" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C386D69" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C386D69" Ref="C3215"  Part="1" 
F 0 "C3215" V 7296 5540 50  0000 C CNN
F 1 "330pF" V 7387 5540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 7858 5390 50  0001 C CNN
F 3 "" H 7845 5640 50  0001 C CNN
F 4 "399-6880-1-ND" H 8245 6040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 7478 5540 50  0000 C CNN "display_footprint"
F 6 "50V" V 7569 5540 50  0000 C CNN "Voltage"
F 7 "NP0" V 7660 5540 50  0000 C CNN "Dielectric"
	1    7820 5540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03230
U 1 1 5C386D70
P 7970 5540
F 0 "#PWR03230" H 7970 5390 50  0001 C CNN
F 1 "+5V" V 7970 5680 50  0000 L CNN
F 2 "" H 7970 5540 50  0001 C CNN
F 3 "" H 7970 5540 50  0001 C CNN
	1    7970 5540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03226
U 1 1 5C386D76
P 7670 5540
F 0 "#PWR03226" H 7670 5390 50  0001 C CNN
F 1 "+3.3V" V 7670 5680 50  0000 L CNN
F 2 "" H 7670 5540 50  0001 C CNN
F 3 "" H 7670 5540 50  0001 C CNN
	1    7670 5540
	0    -1   -1   0   
$EndComp
$Comp
L LED_Display_Local_Library:C_Custom C?
U 1 1 5C386D80
P 9120 5540
AR Path="/5BAAE10E/5C386D80" Ref="C?"  Part="1" 
AR Path="/5BE7BB83/5C386D80" Ref="C?"  Part="1" 
AR Path="/5C1AA7A5/5C386D80" Ref="C3219"  Part="1" 
F 0 "C3219" V 8596 5540 50  0000 C CNN
F 1 "330pF" V 8687 5540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 9158 5390 50  0001 C CNN
F 3 "" H 9145 5640 50  0001 C CNN
F 4 "399-6880-1-ND" H 9545 6040 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 8778 5540 50  0000 C CNN "display_footprint"
F 6 "50V" V 8869 5540 50  0000 C CNN "Voltage"
F 7 "NP0" V 8960 5540 50  0000 C CNN "Dielectric"
	1    9120 5540
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR03238
U 1 1 5C386D87
P 9270 5540
F 0 "#PWR03238" H 9270 5390 50  0001 C CNN
F 1 "+5V" V 9270 5680 50  0000 L CNN
F 2 "" H 9270 5540 50  0001 C CNN
F 3 "" H 9270 5540 50  0001 C CNN
	1    9270 5540
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR03234
U 1 1 5C386D8D
P 8970 5540
F 0 "#PWR03234" H 8970 5390 50  0001 C CNN
F 1 "+3.3V" V 8970 5680 50  0000 L CNN
F 2 "" H 8970 5540 50  0001 C CNN
F 3 "" H 8970 5540 50  0001 C CNN
	1    8970 5540
	0    -1   -1   0   
$EndComp
Text Notes 1530 1280 0    50   ~ 0
Bulk Capacitors
Text Notes 5430 1280 0    50   ~ 0
Stitching Capacitors
$EndSCHEMATC
