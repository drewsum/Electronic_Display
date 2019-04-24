#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LED_Display_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LED_Display_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=gpio_setup.c heartbeat_timer.c power_saving.c error_handler.c usb_uart.c panel_control.c spi_flash.c esp8266.c adc.c misc_board_control.c external_bus_interface.c terminal_control.c test_buffer_fills.c delay_timer.c standard_operation_sm.c device_control.c cause_of_reset.c 32mz_interrupt_control.c watchdog_timer.c prefetch.c test_image_1.c test_image_2.c splash_screen.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/gpio_setup.o ${OBJECTDIR}/heartbeat_timer.o ${OBJECTDIR}/power_saving.o ${OBJECTDIR}/error_handler.o ${OBJECTDIR}/usb_uart.o ${OBJECTDIR}/panel_control.o ${OBJECTDIR}/spi_flash.o ${OBJECTDIR}/esp8266.o ${OBJECTDIR}/adc.o ${OBJECTDIR}/misc_board_control.o ${OBJECTDIR}/external_bus_interface.o ${OBJECTDIR}/terminal_control.o ${OBJECTDIR}/test_buffer_fills.o ${OBJECTDIR}/delay_timer.o ${OBJECTDIR}/standard_operation_sm.o ${OBJECTDIR}/device_control.o ${OBJECTDIR}/cause_of_reset.o ${OBJECTDIR}/32mz_interrupt_control.o ${OBJECTDIR}/watchdog_timer.o ${OBJECTDIR}/prefetch.o ${OBJECTDIR}/test_image_1.o ${OBJECTDIR}/test_image_2.o ${OBJECTDIR}/splash_screen.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/gpio_setup.o.d ${OBJECTDIR}/heartbeat_timer.o.d ${OBJECTDIR}/power_saving.o.d ${OBJECTDIR}/error_handler.o.d ${OBJECTDIR}/usb_uart.o.d ${OBJECTDIR}/panel_control.o.d ${OBJECTDIR}/spi_flash.o.d ${OBJECTDIR}/esp8266.o.d ${OBJECTDIR}/adc.o.d ${OBJECTDIR}/misc_board_control.o.d ${OBJECTDIR}/external_bus_interface.o.d ${OBJECTDIR}/terminal_control.o.d ${OBJECTDIR}/test_buffer_fills.o.d ${OBJECTDIR}/delay_timer.o.d ${OBJECTDIR}/standard_operation_sm.o.d ${OBJECTDIR}/device_control.o.d ${OBJECTDIR}/cause_of_reset.o.d ${OBJECTDIR}/32mz_interrupt_control.o.d ${OBJECTDIR}/watchdog_timer.o.d ${OBJECTDIR}/prefetch.o.d ${OBJECTDIR}/test_image_1.o.d ${OBJECTDIR}/test_image_2.o.d ${OBJECTDIR}/splash_screen.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/gpio_setup.o ${OBJECTDIR}/heartbeat_timer.o ${OBJECTDIR}/power_saving.o ${OBJECTDIR}/error_handler.o ${OBJECTDIR}/usb_uart.o ${OBJECTDIR}/panel_control.o ${OBJECTDIR}/spi_flash.o ${OBJECTDIR}/esp8266.o ${OBJECTDIR}/adc.o ${OBJECTDIR}/misc_board_control.o ${OBJECTDIR}/external_bus_interface.o ${OBJECTDIR}/terminal_control.o ${OBJECTDIR}/test_buffer_fills.o ${OBJECTDIR}/delay_timer.o ${OBJECTDIR}/standard_operation_sm.o ${OBJECTDIR}/device_control.o ${OBJECTDIR}/cause_of_reset.o ${OBJECTDIR}/32mz_interrupt_control.o ${OBJECTDIR}/watchdog_timer.o ${OBJECTDIR}/prefetch.o ${OBJECTDIR}/test_image_1.o ${OBJECTDIR}/test_image_2.o ${OBJECTDIR}/splash_screen.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=gpio_setup.c heartbeat_timer.c power_saving.c error_handler.c usb_uart.c panel_control.c spi_flash.c esp8266.c adc.c misc_board_control.c external_bus_interface.c terminal_control.c test_buffer_fills.c delay_timer.c standard_operation_sm.c device_control.c cause_of_reset.c 32mz_interrupt_control.c watchdog_timer.c prefetch.c test_image_1.c test_image_2.c splash_screen.c main.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/LED_Display_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ2048EFH144
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/gpio_setup.o: gpio_setup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/gpio_setup.o.d 
	@${RM} ${OBJECTDIR}/gpio_setup.o 
	@${FIXDEPS} "${OBJECTDIR}/gpio_setup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/gpio_setup.o.d" -o ${OBJECTDIR}/gpio_setup.o gpio_setup.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/heartbeat_timer.o: heartbeat_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/heartbeat_timer.o.d 
	@${RM} ${OBJECTDIR}/heartbeat_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/heartbeat_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/heartbeat_timer.o.d" -o ${OBJECTDIR}/heartbeat_timer.o heartbeat_timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/power_saving.o: power_saving.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/power_saving.o.d 
	@${RM} ${OBJECTDIR}/power_saving.o 
	@${FIXDEPS} "${OBJECTDIR}/power_saving.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/power_saving.o.d" -o ${OBJECTDIR}/power_saving.o power_saving.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/error_handler.o: error_handler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/error_handler.o.d 
	@${RM} ${OBJECTDIR}/error_handler.o 
	@${FIXDEPS} "${OBJECTDIR}/error_handler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/error_handler.o.d" -o ${OBJECTDIR}/error_handler.o error_handler.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/usb_uart.o: usb_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usb_uart.o.d 
	@${RM} ${OBJECTDIR}/usb_uart.o 
	@${FIXDEPS} "${OBJECTDIR}/usb_uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/usb_uart.o.d" -o ${OBJECTDIR}/usb_uart.o usb_uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/panel_control.o: panel_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/panel_control.o.d 
	@${RM} ${OBJECTDIR}/panel_control.o 
	@${FIXDEPS} "${OBJECTDIR}/panel_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/panel_control.o.d" -o ${OBJECTDIR}/panel_control.o panel_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/spi_flash.o: spi_flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/spi_flash.o.d 
	@${RM} ${OBJECTDIR}/spi_flash.o 
	@${FIXDEPS} "${OBJECTDIR}/spi_flash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/spi_flash.o.d" -o ${OBJECTDIR}/spi_flash.o spi_flash.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/esp8266.o: esp8266.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/esp8266.o.d 
	@${RM} ${OBJECTDIR}/esp8266.o 
	@${FIXDEPS} "${OBJECTDIR}/esp8266.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/esp8266.o.d" -o ${OBJECTDIR}/esp8266.o esp8266.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/adc.o: adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/adc.o.d" -o ${OBJECTDIR}/adc.o adc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/misc_board_control.o: misc_board_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/misc_board_control.o.d 
	@${RM} ${OBJECTDIR}/misc_board_control.o 
	@${FIXDEPS} "${OBJECTDIR}/misc_board_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/misc_board_control.o.d" -o ${OBJECTDIR}/misc_board_control.o misc_board_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/external_bus_interface.o: external_bus_interface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/external_bus_interface.o.d 
	@${RM} ${OBJECTDIR}/external_bus_interface.o 
	@${FIXDEPS} "${OBJECTDIR}/external_bus_interface.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/external_bus_interface.o.d" -o ${OBJECTDIR}/external_bus_interface.o external_bus_interface.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/terminal_control.o: terminal_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/terminal_control.o.d 
	@${RM} ${OBJECTDIR}/terminal_control.o 
	@${FIXDEPS} "${OBJECTDIR}/terminal_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/terminal_control.o.d" -o ${OBJECTDIR}/terminal_control.o terminal_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/test_buffer_fills.o: test_buffer_fills.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/test_buffer_fills.o.d 
	@${RM} ${OBJECTDIR}/test_buffer_fills.o 
	@${FIXDEPS} "${OBJECTDIR}/test_buffer_fills.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/test_buffer_fills.o.d" -o ${OBJECTDIR}/test_buffer_fills.o test_buffer_fills.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/delay_timer.o: delay_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay_timer.o.d 
	@${RM} ${OBJECTDIR}/delay_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/delay_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/delay_timer.o.d" -o ${OBJECTDIR}/delay_timer.o delay_timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/standard_operation_sm.o: standard_operation_sm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/standard_operation_sm.o.d 
	@${RM} ${OBJECTDIR}/standard_operation_sm.o 
	@${FIXDEPS} "${OBJECTDIR}/standard_operation_sm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/standard_operation_sm.o.d" -o ${OBJECTDIR}/standard_operation_sm.o standard_operation_sm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/device_control.o: device_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/device_control.o.d 
	@${RM} ${OBJECTDIR}/device_control.o 
	@${FIXDEPS} "${OBJECTDIR}/device_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/device_control.o.d" -o ${OBJECTDIR}/device_control.o device_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/cause_of_reset.o: cause_of_reset.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/cause_of_reset.o.d 
	@${RM} ${OBJECTDIR}/cause_of_reset.o 
	@${FIXDEPS} "${OBJECTDIR}/cause_of_reset.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/cause_of_reset.o.d" -o ${OBJECTDIR}/cause_of_reset.o cause_of_reset.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/32mz_interrupt_control.o: 32mz_interrupt_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/32mz_interrupt_control.o.d 
	@${RM} ${OBJECTDIR}/32mz_interrupt_control.o 
	@${FIXDEPS} "${OBJECTDIR}/32mz_interrupt_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/32mz_interrupt_control.o.d" -o ${OBJECTDIR}/32mz_interrupt_control.o 32mz_interrupt_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/watchdog_timer.o: watchdog_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/watchdog_timer.o.d 
	@${RM} ${OBJECTDIR}/watchdog_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/watchdog_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/watchdog_timer.o.d" -o ${OBJECTDIR}/watchdog_timer.o watchdog_timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/prefetch.o: prefetch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/prefetch.o.d 
	@${RM} ${OBJECTDIR}/prefetch.o 
	@${FIXDEPS} "${OBJECTDIR}/prefetch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/prefetch.o.d" -o ${OBJECTDIR}/prefetch.o prefetch.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/test_image_1.o: test_image_1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/test_image_1.o.d 
	@${RM} ${OBJECTDIR}/test_image_1.o 
	@${FIXDEPS} "${OBJECTDIR}/test_image_1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/test_image_1.o.d" -o ${OBJECTDIR}/test_image_1.o test_image_1.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/test_image_2.o: test_image_2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/test_image_2.o.d 
	@${RM} ${OBJECTDIR}/test_image_2.o 
	@${FIXDEPS} "${OBJECTDIR}/test_image_2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/test_image_2.o.d" -o ${OBJECTDIR}/test_image_2.o test_image_2.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/splash_screen.o: splash_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/splash_screen.o.d 
	@${RM} ${OBJECTDIR}/splash_screen.o 
	@${FIXDEPS} "${OBJECTDIR}/splash_screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/splash_screen.o.d" -o ${OBJECTDIR}/splash_screen.o splash_screen.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
else
${OBJECTDIR}/gpio_setup.o: gpio_setup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/gpio_setup.o.d 
	@${RM} ${OBJECTDIR}/gpio_setup.o 
	@${FIXDEPS} "${OBJECTDIR}/gpio_setup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/gpio_setup.o.d" -o ${OBJECTDIR}/gpio_setup.o gpio_setup.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/heartbeat_timer.o: heartbeat_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/heartbeat_timer.o.d 
	@${RM} ${OBJECTDIR}/heartbeat_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/heartbeat_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/heartbeat_timer.o.d" -o ${OBJECTDIR}/heartbeat_timer.o heartbeat_timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/power_saving.o: power_saving.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/power_saving.o.d 
	@${RM} ${OBJECTDIR}/power_saving.o 
	@${FIXDEPS} "${OBJECTDIR}/power_saving.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/power_saving.o.d" -o ${OBJECTDIR}/power_saving.o power_saving.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/error_handler.o: error_handler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/error_handler.o.d 
	@${RM} ${OBJECTDIR}/error_handler.o 
	@${FIXDEPS} "${OBJECTDIR}/error_handler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/error_handler.o.d" -o ${OBJECTDIR}/error_handler.o error_handler.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/usb_uart.o: usb_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usb_uart.o.d 
	@${RM} ${OBJECTDIR}/usb_uart.o 
	@${FIXDEPS} "${OBJECTDIR}/usb_uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/usb_uart.o.d" -o ${OBJECTDIR}/usb_uart.o usb_uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/panel_control.o: panel_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/panel_control.o.d 
	@${RM} ${OBJECTDIR}/panel_control.o 
	@${FIXDEPS} "${OBJECTDIR}/panel_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/panel_control.o.d" -o ${OBJECTDIR}/panel_control.o panel_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/spi_flash.o: spi_flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/spi_flash.o.d 
	@${RM} ${OBJECTDIR}/spi_flash.o 
	@${FIXDEPS} "${OBJECTDIR}/spi_flash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/spi_flash.o.d" -o ${OBJECTDIR}/spi_flash.o spi_flash.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/esp8266.o: esp8266.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/esp8266.o.d 
	@${RM} ${OBJECTDIR}/esp8266.o 
	@${FIXDEPS} "${OBJECTDIR}/esp8266.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/esp8266.o.d" -o ${OBJECTDIR}/esp8266.o esp8266.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/adc.o: adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/adc.o.d" -o ${OBJECTDIR}/adc.o adc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/misc_board_control.o: misc_board_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/misc_board_control.o.d 
	@${RM} ${OBJECTDIR}/misc_board_control.o 
	@${FIXDEPS} "${OBJECTDIR}/misc_board_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/misc_board_control.o.d" -o ${OBJECTDIR}/misc_board_control.o misc_board_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/external_bus_interface.o: external_bus_interface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/external_bus_interface.o.d 
	@${RM} ${OBJECTDIR}/external_bus_interface.o 
	@${FIXDEPS} "${OBJECTDIR}/external_bus_interface.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/external_bus_interface.o.d" -o ${OBJECTDIR}/external_bus_interface.o external_bus_interface.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/terminal_control.o: terminal_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/terminal_control.o.d 
	@${RM} ${OBJECTDIR}/terminal_control.o 
	@${FIXDEPS} "${OBJECTDIR}/terminal_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/terminal_control.o.d" -o ${OBJECTDIR}/terminal_control.o terminal_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/test_buffer_fills.o: test_buffer_fills.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/test_buffer_fills.o.d 
	@${RM} ${OBJECTDIR}/test_buffer_fills.o 
	@${FIXDEPS} "${OBJECTDIR}/test_buffer_fills.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/test_buffer_fills.o.d" -o ${OBJECTDIR}/test_buffer_fills.o test_buffer_fills.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/delay_timer.o: delay_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay_timer.o.d 
	@${RM} ${OBJECTDIR}/delay_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/delay_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/delay_timer.o.d" -o ${OBJECTDIR}/delay_timer.o delay_timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/standard_operation_sm.o: standard_operation_sm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/standard_operation_sm.o.d 
	@${RM} ${OBJECTDIR}/standard_operation_sm.o 
	@${FIXDEPS} "${OBJECTDIR}/standard_operation_sm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/standard_operation_sm.o.d" -o ${OBJECTDIR}/standard_operation_sm.o standard_operation_sm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/device_control.o: device_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/device_control.o.d 
	@${RM} ${OBJECTDIR}/device_control.o 
	@${FIXDEPS} "${OBJECTDIR}/device_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/device_control.o.d" -o ${OBJECTDIR}/device_control.o device_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/cause_of_reset.o: cause_of_reset.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/cause_of_reset.o.d 
	@${RM} ${OBJECTDIR}/cause_of_reset.o 
	@${FIXDEPS} "${OBJECTDIR}/cause_of_reset.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/cause_of_reset.o.d" -o ${OBJECTDIR}/cause_of_reset.o cause_of_reset.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/32mz_interrupt_control.o: 32mz_interrupt_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/32mz_interrupt_control.o.d 
	@${RM} ${OBJECTDIR}/32mz_interrupt_control.o 
	@${FIXDEPS} "${OBJECTDIR}/32mz_interrupt_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/32mz_interrupt_control.o.d" -o ${OBJECTDIR}/32mz_interrupt_control.o 32mz_interrupt_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/watchdog_timer.o: watchdog_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/watchdog_timer.o.d 
	@${RM} ${OBJECTDIR}/watchdog_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/watchdog_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/watchdog_timer.o.d" -o ${OBJECTDIR}/watchdog_timer.o watchdog_timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/prefetch.o: prefetch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/prefetch.o.d 
	@${RM} ${OBJECTDIR}/prefetch.o 
	@${FIXDEPS} "${OBJECTDIR}/prefetch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/prefetch.o.d" -o ${OBJECTDIR}/prefetch.o prefetch.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/test_image_1.o: test_image_1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/test_image_1.o.d 
	@${RM} ${OBJECTDIR}/test_image_1.o 
	@${FIXDEPS} "${OBJECTDIR}/test_image_1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/test_image_1.o.d" -o ${OBJECTDIR}/test_image_1.o test_image_1.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/test_image_2.o: test_image_2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/test_image_2.o.d 
	@${RM} ${OBJECTDIR}/test_image_2.o 
	@${FIXDEPS} "${OBJECTDIR}/test_image_2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/test_image_2.o.d" -o ${OBJECTDIR}/test_image_2.o test_image_2.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/splash_screen.o: splash_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/splash_screen.o.d 
	@${RM} ${OBJECTDIR}/splash_screen.o 
	@${FIXDEPS} "${OBJECTDIR}/splash_screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/splash_screen.o.d" -o ${OBJECTDIR}/splash_screen.o splash_screen.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O2
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/LED_Display_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION) -mreserve=prog@0x1d1fc000:0x1d1fffff -o dist/${CND_CONF}/${IMAGE_TYPE}/LED_Display_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  -O2 $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=2048,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/LED_Display_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -mreserve=prog@0x1d1fc000:0x1d1fffff -o dist/${CND_CONF}/${IMAGE_TYPE}/LED_Display_Controller.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  -O2 $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=2048,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/LED_Display_Controller.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
