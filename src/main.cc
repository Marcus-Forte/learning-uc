#include "LED.hh"
#include "stm32f103xb.h"
#include "stm32f1xx_hal.h"

extern "C" {
// Define interrupt handlers. HAL needs the SysTick handler for timing.
void SysTick_Handler(void) { HAL_IncTick(); }
}

void main() {
  HAL_Init();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  ILED *led = new LED(GPIOC, GPIO_PIN_13);
  while (1) {
    HAL_Delay(50);
    led->toggle();
  }

  delete led;
}
