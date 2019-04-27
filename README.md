# Electronic_Display
320x256 LED Display, Marquette Senior Design Project2018-2019, Team E44

20 64x64 HUB75E LED Panels strung together in a 5x4 arrangement, controlled by a PIC32MZ MCU on a host board, alongside an android app

Microconctroller U601 on logic PCB is programmed with firmware in sfw/embedded_firmware/U601_Firmware with PICKIT 3

Two PCBs reside in hdw, designed in KiCad v5.1.0. Both projects require schematic symbols and footprint libraries located in hdw/lib

Embedded firmware resides in sfw/embedded_firmware, built with XC32 v21.0 w/ Pro license (-O2 omptimization level) with MPLabX v5.15

Android app resides in sfw/app/LED_Display, built with Android Studio API level 26

