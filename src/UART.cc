#include "UART.hh"
#include "stm32f103xb.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_uart.h"


static void init_gpio(const USART_TypeDef* instance) {
    uint32_t tx_pin = 0;
    GPIO_TypeDef* gpiox;
    if(instance == USART1) {
        tx_pin = GPIO_PIN_9;
        gpiox = GPIOA;
    } else if (instance == USART2) {
         tx_pin = GPIO_PIN_2;
         gpiox = GPIOA;
    } else if (instance == USART3) {
        tx_pin = GPIO_PIN_10;
        gpiox = GPIOB;
    } else {
        return;
    }

    GPIO_InitTypeDef gpio_config;
        gpio_config.Pin = tx_pin;
    gpio_config.Mode = GPIO_MODE_AF_PP;
    gpio_config.Speed = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(gpiox, &gpio_config);
}

UART::UART(USART_TypeDef* instance) {
    
    init_gpio(instance);
    
    uart_.Instance = instance;
    uart_.Init.BaudRate = 115200;
    uart_.Init.WordLength = UART_WORDLENGTH_8B;
    uart_.Init.StopBits = UART_STOPBITS_1;
    uart_.Init.Parity = UART_PARITY_NONE;
    uart_.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart_.Init.Mode = UART_MODE_TX_RX;
    HAL_UART_Init(&uart_);
}

void UART::write(const std::string& msg) {
    const uint8_t newline[] = "\r\n";
    HAL_UART_Transmit(&uart_, reinterpret_cast<const uint8_t*>(msg.c_str()), msg.size(), 100);
    HAL_UART_Transmit(&uart_, newline, 2, 100);
}