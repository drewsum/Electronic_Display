EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 13 24
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
L LED_Display_Local_Library:PIC32MZ2048EFH144_IPL U?
U 2 1 5BB24D03
P 5580 3530
F 0 "U?" H 6880 1430 50  0000 R CNN
F 1 "PIC32MZ2048EFH144_IPL" H 5580 5680 50  0000 C CNN
F 2 "Housings_QFP:TQFP-144_20x20mm_Pitch0.5mm" H 5580 3530 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/60001320D.pdf" H 5580 3530 50  0001 C CNN
F 4 "ALL" H 5580 3530 50  0001 C CNN "Config"
F 5 "PIC32MZ2048EFH144-I/PL-ND" H 5580 3530 50  0001 C CNN "Digi-Key PN"
	2    5580 3530
	1    0    0    -1  
$EndComp
Text GLabel 7130 4480 2    50   Input ~ 0
~MCLR
NoConn ~ 7130 5380
NoConn ~ 7130 5480
$Comp
L power:GND #PWR?
U 1 1 5BB53596
P 7320 5380
F 0 "#PWR?" H 7320 5130 50  0001 C CNN
F 1 "GND" H 7320 5230 50  0000 C CNN
F 2 "" H 7320 5380 50  0001 C CNN
F 3 "" H 7320 5380 50  0001 C CNN
	1    7320 5380
	1    0    0    -1  
$EndComp
Wire Wire Line
	7320 5380 7320 5280
Wire Wire Line
	7320 5280 7130 5280
$EndSCHEMATC
