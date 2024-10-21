#include "LED.hh"
#include "stm32f1xx_hal_gpio.h"

LED::LED(GPIO_TypeDef *port, uint16_t pin) : port_(port), pin_(pin) {
  GPIO_InitTypeDef GPIO_InitStruct = {
      .Pin = pin,
      .Mode = GPIO_PULLUP,
      .Speed = GPIO_SPEED_FREQ_LOW,
  };
  HAL_GPIO_Init(port_, &GPIO_InitStruct);
}

LED::~LED() { HAL_GPIO_DeInit(port_, pin_); }

void LED::on() { HAL_GPIO_WritePin(port_, pin_, GPIO_PIN_SET); }
void LED::off() { HAL_GPIO_WritePin(port_, pin_, GPIO_PIN_RESET); }
void LED::toggle() { HAL_GPIO_TogglePin(port_, pin_); }