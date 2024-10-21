#pragma once

#include "IUART.hh"
#include "stm32f1xx_hal_dma.h"
#include "stm32f1xx_hal_uart.h"

class UART : public IUART {
public:
  UART(USART_TypeDef *instance);

  /** newline transmitted automatically **/
  void write(const char *msg, uint16_t size);
  void write(const std::string &msg) override;
  std::string read() override;

private:
  UART_HandleTypeDef uart_;
  uint8_t received_byte_;
};