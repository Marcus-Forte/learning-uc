// #include "stm32f1xx_hal.h"
// #include "stm32f1xx_hal_gpio.h"
// #include "core_cm3.h"

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"



void HAL_Delay(uint32_t Delay) {
  for (int i = 0; i < Delay; i++) {
    __NOP();
  }
}
void main() {
  HAL_Init();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  GPIO_InitTypeDef GPIO_InitStruct = {
      .Pin = GPIO_PIN_13,
      .Mode = GPIO_PULLUP,
      .Speed = GPIO_SPEED_FREQ_LOW,
  };

  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  while (1) {
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    // delay();
    HAL_Delay(20000);
  }
}
