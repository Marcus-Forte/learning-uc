

#include "LED.hh"
#include "Module.hh"
#include "Timing.hh"
#include "UART.hh"
#include "stm32f1xx_hal.h"

#include <vector>

extern "C" {
// HAL needs the SysTick handler for timing.
void SysTick_Handler(void) { HAL_IncTick(); }
}

int main() {

  HAL_Init();
  __GPIOC_CLK_ENABLE();
  __GPIOA_CLK_ENABLE();
  __USART1_CLK_ENABLE();

  auto led = std::make_shared<LED>(GPIOC, GPIO_PIN_13);
  auto uart = std::make_shared<UART>(USART1);
  auto timing = std::make_shared<Timing>();
  // auto *led = new LED(GPIOC, GPIO_PIN_13);
  // auto *uart = new UART(USART1);
  // std::vector<int> myvec;
  uint32_t count = 0;
  char buff[50];
  Module module(led, uart, timing);
  while (1) {
    HAL_Delay(50);
    module.blink(1000);
    module.send();
  }
}
