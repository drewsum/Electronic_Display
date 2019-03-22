EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 30 32
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
L Connector_Generic:Conn_01x03 J?
U 1 1 5BBF638E
P 1980 2000
AR Path="/5BAAE1DC/5BBF638E" Ref="J?"  Part="1" 
AR Path="/5BBF5233/5BBF638E" Ref="J3001"  Part="1" 
F 0 "J3001" H 2060 2042 50  0000 L CNN
F 1 "USB UART" H 2060 1951 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 1980 2000 50  0001 C CNN
F 3 "~" H 1980 2000 50  0001 C CNN
	1    1980 2000
	1    0    0    -1  
$EndComp
Text GLabel 1780 1900 0    50   UnSpc ~ 0
USB_UART_TX
Text GLabel 1780 2000 0    50   UnSpc ~ 0
USB_UART_RX
$Comp
L power:GND #PWR?
U 1 1 5BBF6397
P 1780 2100
AR Path="/5BAAE1DC/5BBF6397" Ref="#PWR?"  Part="1" 
AR Path="/5BBF5233/5BBF6397" Ref="#PWR03002"  Part="1" 
F 0 "#PWR03002" H 1780 1850 50  0001 C CNN
F 1 "GND" H 1780 1950 50  0000 C CNN
F 2 "" H 1780 2100 50  0001 C CNN
F 3 "" H 1780 2100 50  0001 C CNN
	1    1780 2100
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:TP TP?
U 1 1 5BBF8ECA
P 1640 5980
AR Path="/5BAAE0FA/5BBF8ECA" Ref="TP?"  Part="1" 
AR Path="/5BBF5233/5BBF8ECA" Ref="TP3001"  Part="1" 
F 0 "TP3001" H 1640 6130 50  0000 C CNN
F 1 "TP" H 1640 6130 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x01_Pitch2.54mm" H 1640 5980 60  0001 C CNN
F 3 "" H 1640 5980 60  0000 C CNN
	1    1640 5980
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BBF8ED1
P 1640 5980
AR Path="/5BAAE0FA/5BBF8ED1" Ref="#PWR?"  Part="1" 
AR Path="/5BBF5233/5BBF8ED1" Ref="#PWR03001"  Part="1" 
F 0 "#PWR03001" H 1640 5730 50  0001 C CNN
F 1 "GND" H 1640 5830 50  0000 C CNN
F 2 "" H 1640 5980 50  0001 C CNN
F 3 "" H 1640 5980 50  0001 C CNN
	1    1640 5980
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:+12Vin #PWR?
U 1 1 5BBF987B
P 2040 5980
AR Path="/5BAAE0FA/5BBF987B" Ref="#PWR?"  Part="1" 
AR Path="/5BBF5233/5BBF987B" Ref="#PWR03003"  Part="1" 
F 0 "#PWR03003" H 2040 5830 50  0001 C CNN
F 1 "+12Vin" H 2040 6130 50  0000 C CNN
F 2 "" H 2040 5980 50  0000 C CNN
F 3 "" H 2040 5980 50  0000 C CNN
	1    2040 5980
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:TP TP?
U 1 1 5BBF9883
P 2040 5980
AR Path="/5BAAE0FA/5BBF9883" Ref="TP?"  Part="1" 
AR Path="/5BBF5233/5BBF9883" Ref="TP3002"  Part="1" 
F 0 "TP3002" H 2040 6130 50  0000 C CNN
F 1 "TP" H 2040 6130 50  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 2040 5980 60  0001 C CNN
F 3 "" H 2040 5980 60  0000 C CNN
	1    2040 5980
	-1   0    0    1   
$EndComp
$Comp
L LED_Display_Local_Library:TP TP?
U 1 1 5BBF98E5
P 2480 5980
AR Path="/5BAAE0FA/5BBF98E5" Ref="TP?"  Part="1" 
AR Path="/5BBF5233/5BBF98E5" Ref="TP3003"  Part="1" 
F 0 "TP3003" H 2480 6130 50  0000 C CNN
F 1 "TP" H 2480 6130 50  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 2480 5980 60  0001 C CNN
F 3 "" H 2480 5980 60  0000 C CNN
	1    2480 5980
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR03004
U 1 1 5BBF996F
P 2480 5980
F 0 "#PWR03004" H 2480 5830 50  0001 C CNN
F 1 "+12V" H 2480 6120 50  0000 C CNN
F 2 "" H 2480 5980 50  0001 C CNN
F 3 "" H 2480 5980 50  0001 C CNN
	1    2480 5980
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:GND_USB #PWR?
U 1 1 5BBFA77B
P 4680 6050
AR Path="/5BAAE1F3/5BBFA77B" Ref="#PWR?"  Part="1" 
AR Path="/5BBF5233/5BBFA77B" Ref="#PWR03009"  Part="1" 
F 0 "#PWR03009" H 4680 5800 50  0001 C CNN
F 1 "GND_USB" H 4680 5900 50  0000 C CNN
F 2 "" H 4680 6050 50  0001 C CNN
F 3 "" H 4680 6050 50  0001 C CNN
	1    4680 6050
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP?
U 1 1 5BBFA781
P 4680 6050
AR Path="/5BAAE1F3/5BBFA781" Ref="TP?"  Part="1" 
AR Path="/5BBF5233/5BBFA781" Ref="TP3007"  Part="1" 
F 0 "TP3007" H 4680 6260 50  0000 C CNN
F 1 "TP" H 4680 6250 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x01_Pitch2.54mm" H 4880 6050 50  0001 C CNN
F 3 "~" H 4880 6050 50  0001 C CNN
	1    4680 6050
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:TP TP3008
U 1 1 5BBFB09C
P 5330 6010
F 0 "TP3008" H 5330 6160 50  0000 C CNN
F 1 "TP" H 5330 6160 50  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 5330 6010 60  0001 C CNN
F 3 "" H 5330 6010 60  0000 C CNN
	1    5330 6010
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:+5V_USB #PWR03011
U 1 1 5BBFB102
P 5330 6010
F 0 "#PWR03011" H 5330 5860 50  0001 C CNN
F 1 "+5V_USB" H 5330 6150 50  0000 C CNN
F 2 "" H 5330 6010 50  0001 C CNN
F 3 "" H 5330 6010 50  0001 C CNN
	1    5330 6010
	-1   0    0    1   
$EndComp
$Comp
L LED_Display_Local_Library:TP TP?
U 1 1 5BD1E3B2
P 2940 5980
AR Path="/5BAAE0FA/5BD1E3B2" Ref="TP?"  Part="1" 
AR Path="/5BBF5233/5BD1E3B2" Ref="TP3004"  Part="1" 
F 0 "TP3004" H 2940 6130 50  0000 C CNN
F 1 "TP" H 2940 6130 50  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 2940 5980 60  0001 C CNN
F 3 "" H 2940 5980 60  0000 C CNN
	1    2940 5980
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR03005
U 1 1 5BD1E45C
P 2940 5980
F 0 "#PWR03005" H 2940 5830 50  0001 C CNN
F 1 "+3.3V" H 2940 6120 50  0000 C CNN
F 2 "" H 2940 5980 50  0001 C CNN
F 3 "" H 2940 5980 50  0001 C CNN
	1    2940 5980
	1    0    0    -1  
$EndComp
Text GLabel 3420 1900 0    50   UnSpc ~ 0
WIFI_UART_TX
Text GLabel 3420 2000 0    50   UnSpc ~ 0
WIFI_UART_RX
$Comp
L Connector_Generic:Conn_01x03 J?
U 1 1 5BE765ED
P 3620 2000
AR Path="/5BAAE1DC/5BE765ED" Ref="J?"  Part="1" 
AR Path="/5BBF5233/5BE765ED" Ref="J3002"  Part="1" 
F 0 "J3002" H 3700 2042 50  0000 L CNN
F 1 "WIFI UART" H 3700 1951 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 3620 2000 50  0001 C CNN
F 3 "~" H 3620 2000 50  0001 C CNN
	1    3620 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BE765F6
P 3420 2100
AR Path="/5BAAE1DC/5BE765F6" Ref="#PWR?"  Part="1" 
AR Path="/5BBF5233/5BE765F6" Ref="#PWR03007"  Part="1" 
F 0 "#PWR03007" H 3420 1850 50  0001 C CNN
F 1 "GND" H 3420 1950 50  0000 C CNN
F 2 "" H 3420 2100 50  0001 C CNN
F 3 "" H 3420 2100 50  0001 C CNN
	1    3420 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J3003
U 1 1 5BF544D4
P 5180 2000
F 0 "J3003" H 5260 1992 50  0000 L CNN
F 1 "FLASH SPI" H 5260 1901 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 5180 2000 50  0001 C CNN
F 3 "~" H 5180 2000 50  0001 C CNN
	1    5180 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BF54513
P 4980 2200
AR Path="/5BAAE1DC/5BF54513" Ref="#PWR?"  Part="1" 
AR Path="/5BBF5233/5BF54513" Ref="#PWR03010"  Part="1" 
F 0 "#PWR03010" H 4980 1950 50  0001 C CNN
F 1 "GND" H 4980 2050 50  0000 C CNN
F 2 "" H 4980 2200 50  0001 C CNN
F 3 "" H 4980 2200 50  0001 C CNN
	1    4980 2200
	1    0    0    -1  
$EndComp
Text GLabel 4980 2100 0    50   UnSpc ~ 0
FLASH_SCK
Text GLabel 4980 1900 0    50   UnSpc ~ 0
FLASH_MOSI
Text GLabel 4980 2000 0    50   UnSpc ~ 0
FLASH_MISO
$Comp
L LED_Display_Local_Library:TP TP?
U 1 1 5BF9B560
P 3340 5980
AR Path="/5BAAE0FA/5BF9B560" Ref="TP?"  Part="1" 
AR Path="/5BBF5233/5BF9B560" Ref="TP3005"  Part="1" 
F 0 "TP3005" H 3340 6130 50  0000 C CNN
F 1 "TP" H 3340 6130 50  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 3340 5980 60  0001 C CNN
F 3 "" H 3340 5980 60  0000 C CNN
	1    3340 5980
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR03006
U 1 1 5BF9B5AC
P 3340 5980
F 0 "#PWR03006" H 3340 5830 50  0001 C CNN
F 1 "+5V" H 3340 6120 50  0000 C CNN
F 2 "" H 3340 5980 50  0001 C CNN
F 3 "" H 3340 5980 50  0001 C CNN
	1    3340 5980
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:TP TP?
U 1 1 5BF9B60D
P 3680 5980
AR Path="/5BAAE0FA/5BF9B60D" Ref="TP?"  Part="1" 
AR Path="/5BBF5233/5BF9B60D" Ref="TP3006"  Part="1" 
F 0 "TP3006" H 3680 6130 50  0000 C CNN
F 1 "TP" H 3680 6130 50  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 3680 5980 60  0001 C CNN
F 3 "" H 3680 5980 60  0000 C CNN
	1    3680 5980
	-1   0    0    1   
$EndComp
$Comp
L LED_Display_Local_Library:+5.5V #PWR03008
U 1 1 5BF9B68F
P 3680 5980
F 0 "#PWR03008" H 3680 5830 50  0001 C CNN
F 1 "+5.5V" H 3680 6120 50  0000 C CNN
F 2 "" H 3680 5980 50  0001 C CNN
F 3 "" H 3680 5980 50  0001 C CNN
	1    3680 5980
	1    0    0    -1  
$EndComp
Text Notes 550  700  0    100  ~ 20
30. Test Points
$Comp
L LED_Display_Local_Library:MU_Logo #G3001
U 1 1 5C0027D2
P 9900 1100
F 0 "#G3001" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:TP TP?
U 1 1 5C0ACA52
P 1260 5980
AR Path="/5BAAE0FA/5C0ACA52" Ref="TP?"  Part="1" 
AR Path="/5BBF5233/5C0ACA52" Ref="TP3010"  Part="1" 
F 0 "TP3010" H 1260 6130 50  0000 C CNN
F 1 "TP" H 1260 6130 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x01_Pitch2.54mm" H 1260 5980 60  0001 C CNN
F 3 "" H 1260 5980 60  0000 C CNN
	1    1260 5980
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C0ACA59
P 1260 5980
AR Path="/5BAAE0FA/5C0ACA59" Ref="#PWR?"  Part="1" 
AR Path="/5BBF5233/5C0ACA59" Ref="#PWR03015"  Part="1" 
F 0 "#PWR03015" H 1260 5730 50  0001 C CNN
F 1 "GND" H 1260 5830 50  0000 C CNN
F 2 "" H 1260 5980 50  0001 C CNN
F 3 "" H 1260 5980 50  0001 C CNN
	1    1260 5980
	1    0    0    -1  
$EndComp
$Comp
L LED_Display_Local_Library:TP TP?
U 1 1 5C0ACABF
P 900 5980
AR Path="/5BAAE0FA/5C0ACABF" Ref="TP?"  Part="1" 
AR Path="/5BBF5233/5C0ACABF" Ref="TP3009"  Part="1" 
F 0 "TP3009" H 900 6130 50  0000 C CNN
F 1 "TP" H 900 6130 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x01_Pitch2.54mm" H 900 5980 60  0001 C CNN
F 3 "" H 900 5980 60  0000 C CNN
	1    900  5980
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C0ACAC6
P 900 5980
AR Path="/5BAAE0FA/5C0ACAC6" Ref="#PWR?"  Part="1" 
AR Path="/5BBF5233/5C0ACAC6" Ref="#PWR03014"  Part="1" 
F 0 "#PWR03014" H 900 5730 50  0001 C CNN
F 1 "GND" H 900 5830 50  0000 C CNN
F 2 "" H 900 5980 50  0001 C CNN
F 3 "" H 900 5980 50  0001 C CNN
	1    900  5980
	1    0    0    -1  
$EndComp
$EndSCHEMATC
