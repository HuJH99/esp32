#include "esp_log.h"

#include "serial_dev.h"

static const char *TAG = "HUJH UART2 SET";

/**
 * @brief 执行步骤1到3，配置阶段
 */
void init_uart(void)
{
    /* Configure parameters of an UART driver,
     * communication pins and install the driver */
    /* 1、设置通信参数 */
    uart_config_t uart_config = {
        .baud_rate = UART_BAUD_RATE,
        .data_bits = UART_DATA_BITS,
        .parity    = UART_PARITY,
        .stop_bits = UART_STOP_BITS,
        .flow_ctrl = UART_FLOW_CTRL,
        .source_clk = UART_SOURCE_CLK,
    };
    ESP_ERROR_CHECK(uart_param_config(UART_PORT_NUM, &uart_config));

    /* 2、设置通信管脚 */
    ESP_ERROR_CHECK(uart_set_pin(UART_PORT_NUM, UART_PIN_TXD, UART_PIN_RXD, UART_PIN_RTS, UART_PIN_CTS));

    /* 3、安装驱动程序 */
    ESP_ERROR_CHECK(uart_driver_install(UART_PORT_NUM, BUF_SIZE * 2, 0, 0, NULL, INTR_ALLOC_FLAGS));
    ESP_LOGI(TAG, "Initialized successfully!");
}

/**
 * @brief 步骤6，删除驱动程序
*/
void del_uart(void)
{
    ESP_ERROR_CHECK(uart_driver_delete(UART_PORT_NUM));
    ESP_LOGI(TAG, "Delete successfully!");
}