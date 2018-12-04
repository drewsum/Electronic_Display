EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 1 31
Title "Electronic Display Logic Board"
Date "2018-11-28"
Rev "A"
Comp "Marquette University Senior Design 2018/2019 Group E44"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3760 1600 500  150 
U 5BAAE0FA
F0 "Power Input" 50
F1 "Power_Input.sch" 50
$EndSheet
$Sheet
S 3760 1940 500  150 
U 5BAAE10E
F0 "POS3P3 Power Supply" 50
F1 "POS3P3_Power_Supply.sch" 50
$EndSheet
$Sheet
S 3760 2290 500  150 
U 5BE5222A
F0 "POS5 Power Supply" 50
F1 "POS5_Power_Supply.sch" 50
$EndSheet
$Sheet
S 3760 2630 500  150 
U 5BAAE16C
F0 "Microcontroller Programming" 50
F1 "Microcontroller_Programming.sch" 50
$EndSheet
$Sheet
S 3760 2970 500  150 
U 5BB181D8
F0 "Microcontroller Power" 50
F1 "Microcontroller_Power.sch" 50
$EndSheet
$Sheet
S 3760 3310 500  150 
U 5BB182B1
F0 "Microcontroller 1" 50
F1 "Microcontroller_1.sch" 50
$EndSheet
$Sheet
S 3760 3650 500  150 
U 5BB1838A
F0 "Microcontroller 2" 50
F1 "Microcontroller_2.sch" 50
$EndSheet
$Sheet
S 3760 3990 500  150 
U 5BAAE1CB
F0 "WiFi Module" 50
F1 "Wi_Fi_Module.sch" 50
$EndSheet
$Sheet
S 3760 4330 500  150 
U 5BAAE1DC
F0 "USB UART Isolation" 50
F1 "USB_UART_Isolation.sch" 50
$EndSheet
$Sheet
S 3760 4670 500  150 
U 5BAAE1F3
F0 "USB UART Bridge" 50
F1 "USB_UART_Bridge.sch" 50
$EndSheet
$Sheet
S 3760 5010 500  150 
U 5BB844FD
F0 "Status LEDs 1" 50
F1 "Status_LEDs_1.sch" 50
$EndSheet
$Sheet
S 3760 5350 500  150 
U 5BF346B3
F0 "Status LEDs 2" 50
F1 "Status_LEDs_2.sch" 50
$EndSheet
$Sheet
S 3760 5690 500  150 
U 5BE4F849
F0 "Pushbuttons" 50
F1 "Pushbuttons.sch" 50
$EndSheet
$Sheet
S 3760 6030 500  150 
U 5BE7BB83
F0 "Internal Rail Monitoring" 50
F1 "Internal_Rail_Monitoring.sch" 50
$EndSheet
$Sheet
S 3760 6370 500  150 
U 5BE48F98
F0 "LED POS5 Monitoring" 50
F1 "LED_POS5_Monitoring.sch" 50
$EndSheet
$Sheet
S 8730 1600 500  150 
U 5BB2595B
F0 "External SRAM" 50
F1 "External_SRAM.sch" 50
$EndSheet
$Sheet
S 8730 1940 500  150 
U 5BB2595E
F0 "External Flash 1" 50
F1 "External_Flash_1.sch" 50
$EndSheet
$Sheet
S 8730 2290 500  150 
U 5BB25AE7
F0 "External Flash 2" 50
F1 "External_Flash_2.sch" 50
$EndSheet
$Sheet
S 8730 2630 500  150 
U 5BB25AEA
F0 "External Flash 3" 50
F1 "External_Flash_3.sch" 50
$EndSheet
$Sheet
S 8730 2970 500  150 
U 5BB25AED
F0 "External Flash 4" 50
F1 "External_Flash_4.sch" 50
$EndSheet
$Sheet
S 8730 3310 500  150 
U 5BB25AF0
F0 "External Flash 5" 50
F1 "External_Flash_5.sch" 50
$EndSheet
$Sheet
S 8730 3650 500  150 
U 5BB53D61
F0 "External Flash 6" 50
F1 "External_Flash_6.sch" 50
$EndSheet
$Sheet
S 8730 3990 500  150 
U 5BB53D64
F0 "External Flash 7" 50
F1 "External_Flash_7.sch" 50
$EndSheet
$Sheet
S 8730 4330 500  150 
U 5BB53D67
F0 "External Flash 8" 50
F1 "External_Flash_8.sch" 50
$EndSheet
$Sheet
S 8730 4670 500  150 
U 5BBE424C
F0 "Panel Data Level Shifters 1" 50
F1 "Panel_Data_Level_Shifters_1.sch" 50
$EndSheet
$Sheet
S 8730 5010 500  150 
U 5BBE424F
F0 "Panel Data Level Shifters 2" 50
F1 "Panel_Data_Level_Shifters_2.sch" 50
$EndSheet
$Sheet
S 8730 5350 500  150 
U 5BBE4252
F0 "Panel Data Level Shifters 3" 50
F1 "Panel_Data_Level_Shifters_3.sch" 50
$EndSheet
$Sheet
S 8730 5690 500  150 
U 5BAAE2CE
F0 "Panel Data Connectors" 50
F1 "Panel_Data_Connectors.sch" 50
$EndSheet
Text Notes 650  7530 0    50   ~ 0
To Do List:\n* Add othe rerror LED\n* Copy custom power footprints to local library\n* Draw custom footprints (SRAM, power supply ICs, etc)\n* Assign footprints\n* Assign Digi-Key Partnumbers\n* Run ERC, resolve errors\n* Generate netlist\n* Generate BOM\n* Layout PCB
$Sheet
S 8730 6030 500  150 
U 5BBF5233
F0 "Test Points" 50
F1 "Test_Points.sch" 50
$EndSheet
$Sheet
S 8730 6370 500  150 
U 5BE724F0
F0 "Mechanical" 50
F1 "Mechanical.sch" 50
$EndSheet
Text Notes 750  1750 0    100  ~ 20
02. Power Input
Text Notes 750  2090 0    100  ~ 20
03. +3.3V Power Supply
Text Notes 750  2440 0    100  ~ 20
04. +5V Power Supply
Text Notes 750  2780 0    100  ~ 20
05. Microcontroller Programming
Text Notes 750  3120 0    100  ~ 20
06. Microcontroller Power
Text Notes 750  3460 0    100  ~ 20
07. Microcontroller IO Bank 1
Text Notes 750  3800 0    100  ~ 20
08. Microcontroller IO Bank 2
Text Notes 750  4140 0    100  ~ 20
09. WiFi Module
Text Notes 750  4480 0    100  ~ 20
10. USB UART Digital Isolation
Text Notes 750  4820 0    100  ~ 20
11. USB UART Bridge
Text Notes 750  5160 0    100  ~ 20
12. Status LEDs Bank 1
Text Notes 750  5500 0    100  ~ 20
13. Status LEDs Bank 2
Text Notes 750  5840 0    100  ~ 20
14. Pushbuttons
Text Notes 750  6180 0    100  ~ 20
15. Internal Rail Monitoring
Text Notes 750  6520 0    100  ~ 20
16. LED Power Supply Monitoring
Text Notes 5780 1750 0    100  ~ 20
17. External SRAM
Text Notes 5780 2090 0    100  ~ 20
18. External FLASH 1
Text Notes 5780 2440 0    100  ~ 20
19. External FLASH 2
Text Notes 5780 2780 0    100  ~ 20
20. External FLASH 3
Text Notes 5780 3120 0    100  ~ 20
21. External FLASH 4
Text Notes 5780 3460 0    100  ~ 20
22. External FLASH 5
Text Notes 5780 3800 0    100  ~ 20
23. External FLASH 6
Text Notes 5780 4140 0    100  ~ 20
24. External FLASH 7
Text Notes 5780 4480 0    100  ~ 20
25. External FLASH 8
Text Notes 5780 4820 0    100  ~ 20
26. Panel Data Level Shifters 1
Text Notes 5780 5160 0    100  ~ 20
27. Panel Data Level Shifters 2
Text Notes 5780 5500 0    100  ~ 20
28. Panel Data Level Shifters 3
Text Notes 5780 5840 0    100  ~ 20
29. Panel Data Connectors
Text Notes 5780 6180 0    100  ~ 20
30. Test Points
Text Notes 5780 6520 0    100  ~ 20
31. Mechanical
Text Notes 4070 730  0    120  ~ 24
Electronic Display Logic Board
Text Notes 3240 990  0    100  ~ 0
Marquette Universiy Senior Design 2018, Group E44 
Text Notes 2600 1200 0    100  ~ 0
Drew Maatman, Kevin Etta, Logan Wedel, Caroline Gilger, Tuoxuan Ren
Text Notes 550  700  0    100  ~ 20
01. Table of Contents
$Comp
L LED_Display_Local_Library:MU_Logo #G101
U 1 1 5BFF0BEF
P 9900 1100
F 0 "#G101" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
Text Notes 720  7920 0    50   ~ 0
Note: If component footprints, tolerances, and power ratings are hidden, components are:\n0603 case size, 1% tolerance, 1/10W power rating
$EndSCHEMATC
