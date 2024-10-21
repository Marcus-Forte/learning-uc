#include "UART.hh"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_conf.h"
#include "stm32f1xx_hal_gpio.h"

extern "C" {
void USART1_IRQHandler(void) {
  USART1->SR = ~(USART_FLAG_RXNE);
  // TODO how to route interrupt to object?
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {}
}
static void init_gpio(const USART_TypeDef *instance) {
  uint32_t tx_pin = 0;
  uint32_t rx_pin = 0;
  GPIO_TypeDef *gpiox;
  if (instance == USART1) {
    tx_pin = GPIO_PIN_9;
    rx_pin = GPIO_PIN_10;
    gpiox = GPIOA;
  } else if (instance == USART2) {
    tx_pin = GPIO_PIN_2;
    rx_pin = GPIO_PIN_3;
    gpiox = GPIOA;
  } else if (instance == USART3) {
    tx_pin = GPIO_PIN_10;
    rx_pin = GPIO_PIN_11;
    gpiox = GPIOB;
  } else {
    return;
  }

  GPIO_InitTypeDef gpio_config;
  gpio_config.Pin = tx_pin;
  gpio_config.Mode = GPIO_MODE_AF_PP;
  gpio_config.Speed = GPIO_SPEED_FREQ_HIGH;

  HAL_GPIO_Init(gpiox, &gpio_config);

  gpio_config.Pin = rx_pin;
  gpio_config.Mode = GPIO_MODE_INPUT;
  HAL_GPIO_Init(gpiox, &gpio_config);
  HAL_NVIC_EnableIRQ(USART1_IRQn);
}

UART::UART(USART_TypeDef *instance) {

  init_gpio(instance);

  uart_.Instance = instance;
  uart_.Init.BaudRate = 115200;
  uart_.Init.WordLength = UART_WORDLENGTH_8B;
  uart_.Init.StopBits = UART_STOPBITS_1;
  uart_.Init.Parity = UART_PARITY_NONE;
  uart_.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  uart_.Init.Mode = UART_MODE_TX_RX;
  HAL_UART_Init(&uart_);
  HAL_UART_Receive_IT(&uart_, &received_byte_, 1);
}

void UART::write(const char *msg, uint16_t size) {
  const uint8_t newline[] = "\r\n";
  HAL_UART_Transmit(&uart_, reinterpret_cast<const uint8_t *>(msg), size, 100);
  HAL_UART_Transmit(&uart_, newline, 2, 100);
}
void UART::write(const std::string &msg) {
  const uint8_t newline[] = "\r\n";
  HAL_UART_Transmit(&uart_, reinterpret_cast<const uint8_t *>(msg.c_str()),
                    msg.size(), 100);
  HAL_UART_Transmit(&uart_, newline, 2, 100);
}

std::string UART::read() { return ""; }