/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys' in SOPC Builder design 'DE0_NANO_QSYS'
 * SOPC Builder design path: E:/DE0_NANO_SDRAM_Nios_Test/DE0_NANO_QSYS.sopcinfo
 *
 * Generated: Fri Jul 30 14:36:50 CST 2021
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x02001820
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1a
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x00000020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1a
#define ALT_CPU_NAME "nios2_qsys"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_RESET_ADDR 0x02001000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x02001820
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1a
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x00000020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1a
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_RESET_ADDR 0x02001000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_EPCS_FLASH_CONTROLLER
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_UART
#define __ALTERA_NIOS2_QSYS
#define __ALTPLL


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x2002100
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x2002100
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x2002100
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "DE0_NANO_QSYS"


/*
 * altpll configuration
 *
 */

#define ALTPLL_BASE 0x20020e0
#define ALTPLL_IRQ -1
#define ALTPLL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ALTPLL_NAME "/dev/altpll"
#define ALTPLL_SPAN 16
#define ALTPLL_TYPE "altpll"
#define ALT_MODULE_CLASS_altpll altpll


/*
 * epcs_flash configuration
 *
 */

#define ALT_MODULE_CLASS_epcs_flash altera_avalon_epcs_flash_controller
#define EPCS_FLASH_BASE 0x2001000
#define EPCS_FLASH_IRQ 1
#define EPCS_FLASH_IRQ_INTERRUPT_CONTROLLER_ID 0
#define EPCS_FLASH_NAME "/dev/epcs_flash"
#define EPCS_FLASH_REGISTER_OFFSET 1024
#define EPCS_FLASH_SPAN 2048
#define EPCS_FLASH_TYPE "altera_avalon_epcs_flash_controller"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x2002100
#define JTAG_UART_IRQ 0
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * key configuration
 *
 */

#define ALT_MODULE_CLASS_key altera_avalon_pio
#define KEY_BASE 0x20020f0
#define KEY_BIT_CLEARING_EDGE_REGISTER 0
#define KEY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEY_CAPTURE 1
#define KEY_DATA_WIDTH 1
#define KEY_DO_TEST_BENCH_WIRING 0
#define KEY_DRIVEN_SIM_VALUE 0
#define KEY_EDGE_TYPE "FALLING"
#define KEY_FREQ 100000000
#define KEY_HAS_IN 1
#define KEY_HAS_OUT 0
#define KEY_HAS_TRI 0
#define KEY_IRQ 8
#define KEY_IRQ_INTERRUPT_CONTROLLER_ID 0
#define KEY_IRQ_TYPE "EDGE"
#define KEY_NAME "/dev/key"
#define KEY_RESET_VALUE 0
#define KEY_SPAN 16
#define KEY_TYPE "altera_avalon_pio"


/*
 * scl configuration
 *
 */

#define ALT_MODULE_CLASS_scl altera_avalon_pio
#define SCL_BASE 0x20020c0
#define SCL_BIT_CLEARING_EDGE_REGISTER 0
#define SCL_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SCL_CAPTURE 0
#define SCL_DATA_WIDTH 1
#define SCL_DO_TEST_BENCH_WIRING 0
#define SCL_DRIVEN_SIM_VALUE 0
#define SCL_EDGE_TYPE "NONE"
#define SCL_FREQ 50000000
#define SCL_HAS_IN 0
#define SCL_HAS_OUT 1
#define SCL_HAS_TRI 0
#define SCL_IRQ -1
#define SCL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SCL_IRQ_TYPE "NONE"
#define SCL_NAME "/dev/scl"
#define SCL_RESET_VALUE 0
#define SCL_SPAN 16
#define SCL_TYPE "altera_avalon_pio"


/*
 * sda configuration
 *
 */

#define ALT_MODULE_CLASS_sda altera_avalon_pio
#define SDA_BASE 0x20020d0
#define SDA_BIT_CLEARING_EDGE_REGISTER 0
#define SDA_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SDA_CAPTURE 0
#define SDA_DATA_WIDTH 1
#define SDA_DO_TEST_BENCH_WIRING 0
#define SDA_DRIVEN_SIM_VALUE 0
#define SDA_EDGE_TYPE "NONE"
#define SDA_FREQ 50000000
#define SDA_HAS_IN 0
#define SDA_HAS_OUT 0
#define SDA_HAS_TRI 1
#define SDA_IRQ -1
#define SDA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDA_IRQ_TYPE "NONE"
#define SDA_NAME "/dev/sda"
#define SDA_RESET_VALUE 0
#define SDA_SPAN 16
#define SDA_TYPE "altera_avalon_pio"


/*
 * sdram configuration
 *
 */

#define ALT_MODULE_CLASS_sdram altera_avalon_new_sdram_controller
#define SDRAM_BASE 0x0
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_NAME "/dev/sdram"
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_REFRESH_PERIOD 15.625
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 0x18
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 9
#define SDRAM_SDRAM_DATA_WIDTH 16
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 13
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 1
#define SDRAM_SPAN 33554432
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_T_AC 5.5
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 20.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 20.0
#define SDRAM_T_WR 14.0


/*
 * sysid_qsys configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys altera_avalon_sysid_qsys
#define SYSID_QSYS_BASE 0x2002108
#define SYSID_QSYS_ID 0
#define SYSID_QSYS_IRQ -1
#define SYSID_QSYS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_NAME "/dev/sysid_qsys"
#define SYSID_QSYS_SPAN 8
#define SYSID_QSYS_TIMESTAMP 1627626887
#define SYSID_QSYS_TYPE "altera_avalon_sysid_qsys"


/*
 * uart_co configuration
 *
 */

#define ALT_MODULE_CLASS_uart_co altera_avalon_uart
#define UART_CO_BASE 0x2002080
#define UART_CO_BAUD 9600
#define UART_CO_DATA_BITS 8
#define UART_CO_FIXED_BAUD 1
#define UART_CO_FREQ 50000000
#define UART_CO_IRQ 3
#define UART_CO_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_CO_NAME "/dev/uart_co"
#define UART_CO_PARITY 'N'
#define UART_CO_SIM_CHAR_STREAM ""
#define UART_CO_SIM_TRUE_BAUD 0
#define UART_CO_SPAN 32
#define UART_CO_STOP_BITS 1
#define UART_CO_SYNC_REG_DEPTH 2
#define UART_CO_TYPE "altera_avalon_uart"
#define UART_CO_USE_CTS_RTS 0
#define UART_CO_USE_EOP_REGISTER 0


/*
 * uart_hmi configuration
 *
 */

#define ALT_MODULE_CLASS_uart_hmi altera_avalon_uart
#define UART_HMI_BASE 0x2002000
#define UART_HMI_BAUD 115200
#define UART_HMI_DATA_BITS 8
#define UART_HMI_FIXED_BAUD 1
#define UART_HMI_FREQ 50000000
#define UART_HMI_IRQ 7
#define UART_HMI_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_HMI_NAME "/dev/uart_hmi"
#define UART_HMI_PARITY 'N'
#define UART_HMI_SIM_CHAR_STREAM ""
#define UART_HMI_SIM_TRUE_BAUD 0
#define UART_HMI_SPAN 32
#define UART_HMI_STOP_BITS 1
#define UART_HMI_SYNC_REG_DEPTH 2
#define UART_HMI_TYPE "altera_avalon_uart"
#define UART_HMI_USE_CTS_RTS 0
#define UART_HMI_USE_EOP_REGISTER 0


/*
 * uart_no2 configuration
 *
 */

#define ALT_MODULE_CLASS_uart_no2 altera_avalon_uart
#define UART_NO2_BASE 0x20020a0
#define UART_NO2_BAUD 9600
#define UART_NO2_DATA_BITS 8
#define UART_NO2_FIXED_BAUD 1
#define UART_NO2_FREQ 50000000
#define UART_NO2_IRQ 2
#define UART_NO2_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_NO2_NAME "/dev/uart_no2"
#define UART_NO2_PARITY 'N'
#define UART_NO2_SIM_CHAR_STREAM ""
#define UART_NO2_SIM_TRUE_BAUD 0
#define UART_NO2_SPAN 32
#define UART_NO2_STOP_BITS 1
#define UART_NO2_SYNC_REG_DEPTH 2
#define UART_NO2_TYPE "altera_avalon_uart"
#define UART_NO2_USE_CTS_RTS 0
#define UART_NO2_USE_EOP_REGISTER 0


/*
 * uart_o3 configuration
 *
 */

#define ALT_MODULE_CLASS_uart_o3 altera_avalon_uart
#define UART_O3_BASE 0x2002020
#define UART_O3_BAUD 9600
#define UART_O3_DATA_BITS 8
#define UART_O3_FIXED_BAUD 1
#define UART_O3_FREQ 50000000
#define UART_O3_IRQ 6
#define UART_O3_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_O3_NAME "/dev/uart_o3"
#define UART_O3_PARITY 'N'
#define UART_O3_SIM_CHAR_STREAM ""
#define UART_O3_SIM_TRUE_BAUD 0
#define UART_O3_SPAN 32
#define UART_O3_STOP_BITS 1
#define UART_O3_SYNC_REG_DEPTH 2
#define UART_O3_TYPE "altera_avalon_uart"
#define UART_O3_USE_CTS_RTS 0
#define UART_O3_USE_EOP_REGISTER 0


/*
 * uart_sds011 configuration
 *
 */

#define ALT_MODULE_CLASS_uart_sds011 altera_avalon_uart
#define UART_SDS011_BASE 0x2002060
#define UART_SDS011_BAUD 9600
#define UART_SDS011_DATA_BITS 8
#define UART_SDS011_FIXED_BAUD 1
#define UART_SDS011_FREQ 50000000
#define UART_SDS011_IRQ 4
#define UART_SDS011_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_SDS011_NAME "/dev/uart_sds011"
#define UART_SDS011_PARITY 'N'
#define UART_SDS011_SIM_CHAR_STREAM ""
#define UART_SDS011_SIM_TRUE_BAUD 0
#define UART_SDS011_SPAN 32
#define UART_SDS011_STOP_BITS 1
#define UART_SDS011_SYNC_REG_DEPTH 2
#define UART_SDS011_TYPE "altera_avalon_uart"
#define UART_SDS011_USE_CTS_RTS 0
#define UART_SDS011_USE_EOP_REGISTER 0


/*
 * uart_so2 configuration
 *
 */

#define ALT_MODULE_CLASS_uart_so2 altera_avalon_uart
#define UART_SO2_BASE 0x2002040
#define UART_SO2_BAUD 9600
#define UART_SO2_DATA_BITS 8
#define UART_SO2_FIXED_BAUD 1
#define UART_SO2_FREQ 50000000
#define UART_SO2_IRQ 5
#define UART_SO2_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_SO2_NAME "/dev/uart_so2"
#define UART_SO2_PARITY 'N'
#define UART_SO2_SIM_CHAR_STREAM ""
#define UART_SO2_SIM_TRUE_BAUD 0
#define UART_SO2_SPAN 32
#define UART_SO2_STOP_BITS 1
#define UART_SO2_SYNC_REG_DEPTH 2
#define UART_SO2_TYPE "altera_avalon_uart"
#define UART_SO2_USE_CTS_RTS 0
#define UART_SO2_USE_EOP_REGISTER 0

#endif /* __SYSTEM_H_ */
