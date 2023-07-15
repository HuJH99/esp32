#ifndef SERIAL_DEV_H__
#define SERIAL_DEV_H__

/**
 * @brief ESP32 和其他 UART 设备之间建立通信。基本编程流程分为以下几个步骤：
 * 1、设置通信参数 - 设置波特率、数据位、停止位等
 * 2、设置通信管脚 - 分配连接设备的管脚
 * 3、安装驱动程序 - 为 UART 驱动程序分配 ESP32 资源
 * 4、运行 UART 通信 - 发送/接收数据
 * 5、使用中断 - 触发特定通信事件的中断
 * 6、删除驱动程序 - 如无需 UART 通信，则释放已分配的资源
 * 步骤 1 到 3 为配置阶段，步骤 4 为 UART 运行阶段，步骤 5 和 6 为可选步骤。
*/

#include "driver/uart.h"
#include "driver/gpio.h"

#define UART_PIN_TXD        17
#define UART_PIN_RXD        16
#define UART_PIN_RTS        UART_PIN_NO_CHANGE
#define UART_PIN_CTS        UART_PIN_NO_CHANGE

/* ESP32 DEVKITV1 串口0用来与CP2102通信，串口1未引出 */
#define UART_PORT_NUM       UART_NUM_2  
#define UART_BAUD_RATE      115200
#define UART_DATA_BITS      UART_DATA_8_BITS
#define UART_PARITY         UART_PARITY_DISABLE
#define UART_STOP_BITS      UART_STOP_BITS_1
#define UART_FLOW_CTRL      UART_HW_FLOWCTRL_DISABLE
#define UART_SOURCE_CLK     UART_SCLK_DEFAULT

#define BUF_SIZE            1024
#define INTR_ALLOC_FLAGS    0

void init_uart(void);
void del_uart(void);

// uart_read_bytes(uart_port_t uart_num, void *buf, uint32_t length, TickType_t ticks_to_wait)
// uart_write_bytes(uart_port_t uart_num, const void *src, size_t size)

#endif