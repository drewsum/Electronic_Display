EESchema Schematic File Version 4
LIBS:LED_Display_Controller-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 1 25
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3050 770  500  150 
U 5BAAE0FA
F0 "Power Input" 50
F1 "Power_Input.sch" 50
$EndSheet
$Sheet
S 3050 1110 500  150 
U 5BAAE10E
F0 "POS3P3 Power Supply" 50
F1 "POS3P3_Power_Supply.sch" 50
$EndSheet
$Sheet
S 3050 1780 500  150 
U 5BAAE16C
F0 "Microcontroller Programming" 50
F1 "Microcontroller_Programming.sch" 50
$EndSheet
$Sheet
S 3050 2160 500  150 
U 5BAAE1CB
F0 "WiFi Module" 50
F1 "Wi_Fi_Module.sch" 50
$EndSheet
$Sheet
S 3050 2550 500  150 
U 5BAAE1DC
F0 "USB UART Isolation" 50
F1 "USB_UART_Isolation.sch" 50
$EndSheet
$Sheet
S 3050 2910 500  150 
U 5BAAE1F3
F0 "USB UART Bridge" 50
F1 "USB_UART_Bridge.sch" 50
$EndSheet
$Sheet
S 3050 3570 500  150 
U 5BAAE2CE
F0 "Panel Data Connectors" 50
F1 "Panel_Data_Connectors.sch" 50
$EndSheet
$Sheet
S 3050 3890 500  150 
U 5BAAE2DF
F0 "Panel Power Connectors" 50
F1 "Panel_Power_Connectors.sch" 50
$EndSheet
$Sheet
S 3050 4280 500  150 
U 5BB181D8
F0 "Microcontroller Power" 50
F1 "Microcontroller_Power.sch" 50
$EndSheet
$Sheet
S 3050 4630 500  150 
U 5BB182B1
F0 "Microcontroller A" 50
F1 "Microcontroller_A.sch" 50
$EndSheet
$Sheet
S 3050 4970 500  150 
U 5BB1838A
F0 "Microcontroller B" 50
F1 "Microcontroller_B.sch" 50
$EndSheet
$Sheet
S 7170 770  500  150 
U 5BB2595B
F0 "External SRAM" 50
F1 "External_SRAM.sch" 50
$EndSheet
$Sheet
S 7170 1110 500  150 
U 5BB2595E
F0 "External Flash 1" 50
F1 "External_Flash_1.sch" 50
$EndSheet
$Sheet
S 7170 1450 500  150 
U 5BB25AE7
F0 "External Flash 2" 50
F1 "External_Flash_2.sch" 50
$EndSheet
$Sheet
S 7170 1780 500  150 
U 5BB25AEA
F0 "External Flash 3" 50
F1 "External_Flash_3.sch" 50
$EndSheet
$Sheet
S 7170 2160 500  150 
U 5BB25AED
F0 "External Flash 4" 50
F1 "External_Flash_4.sch" 50
$EndSheet
$Sheet
S 7170 2550 500  150 
U 5BB25AF0
F0 "External Flash 5" 50
F1 "External_Flash_5.sch" 50
$EndSheet
$Sheet
S 7170 2920 500  150 
U 5BB53D61
F0 "External Flash 6" 50
F1 "External_Flash_6.sch" 50
$EndSheet
$Sheet
S 7170 3260 500  150 
U 5BB53D64
F0 "External Flash 7" 50
F1 "External_Flash_7.sch" 50
$EndSheet
$Sheet
S 7170 3610 500  150 
U 5BB53D67
F0 "External Flash 8" 50
F1 "External_Flash_8.sch" 50
$EndSheet
$Sheet
S 7170 3990 500  150 
U 5BB844FD
F0 "Status LEDs 1" 50
F1 "Status_LEDs_1.sch" 50
$EndSheet
$Sheet
S 7170 4340 500  150 
U 5BBE424C
F0 "Panel Data Level Shifters 1" 50
F1 "Panel_Data_Level_Shifters_1.sch" 50
$EndSheet
$Sheet
S 7170 4680 500  150 
U 5BBE424F
F0 "Panel Data Level Shifters 2" 50
F1 "Panel_Data_Level_Shifters_2.sch" 50
$EndSheet
$Sheet
S 7170 4990 500  150 
U 5BBE4252
F0 "Panel Data Level Shifters 3" 50
F1 "Panel_Data_Level_Shifters_3.sch" 50
$EndSheet
Text Notes 710  7660 0    50   ~ 0
To Do List:\n* Add +5V LED Power Supply (~~80 to 90A)\n* External oscillator for Micro?\n* Mechanical sheet\n* Design Power Input Circuit, add fusing\n* Decide on input power supply (AC/DC)\n* Add more power input connectors, match to AC/DC output connectors. Might need beefy Weurth shanks\n* Add status LEDs, PGOOD stuff\n* +3.3V Power Supply (~~2A)\n* +5V Monitoring/+3.3V Monitoring/Input Monitoring? Temperature sensors?\n* Add AUX +5V input if we mess up +5V supply\n* Wi-Fi Module\n* Select panel connector bulk caps, match with other tantalums on board for BOM scrubbing?\n* Power pushbutton? vs set on app?\n* Brightness encoder? vs set on app?\n* Time of flight IC?\n* Add graphical items to certain sheets (ESD warning, heat, etc)\n* Add MU Logo to each sheet\n* Add Titles to each sheet\n* Add relevant design notes/routing notes to sheets\n* Add test points sheet\n* Re-order sheets\n* Wire everything to Micro\n* Assign Refdes's\n* Draw custom footprints\n* Assign footprints\n* Run ERC, resolve errors\n* Add firmware notes sheet\n* Add COM port settings to USB sheet\n* Generate netlist\n* Generate BOM
$EndSCHEMATC
