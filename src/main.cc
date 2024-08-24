#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"

extern "C" {
// Define interrupt handlers. HAL needs the SysTick handler for timing.
void SysTick_Handler(void) { HAL_IncTick(); }
}

void main() {
  HAL_Init();
  GPIO_InitTypeDef GPIO_InitStruct = {
      .Pin = GPIO_PIN_13,
      .Mode = GPIO_PULLUP,
      .Speed = GPIO_SPEED_FREQ_LOW,
  };

  __HAL_RCC_GPIOC_CLK_ENABLE();
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  while (1) {
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    HAL_Delay(200);
  }
}
