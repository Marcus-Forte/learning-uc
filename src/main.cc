#include "LED.hh"
#include "UART.hh"

#include "stm32f103xb.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"

#include <vector>
// #include <memory>

extern "C" {
// Define interrupt handlers. HAL needs the SysTick handler for timing.
void SysTick_Handler(void) { HAL_IncTick(); }
}

int main() {
  HAL_Init();
  __GPIOC_CLK_ENABLE();
  __GPIOA_CLK_ENABLE();
  __USART1_CLK_ENABLE();

  // auto led = std::make_unique<LED>(GPIOC, GPIO_PIN_13);
  // auto uart = std::make_unique<UART>(USART1);
  auto *led = new LED(GPIOC, GPIO_PIN_13);
  auto *uart = new UART(USART1);
  std::vector<int> myvec;

  uint32_t count = 0;
  while (1) {
    HAL_Delay(10);
    count++;
      led->toggle();
      myvec.push_back(count);
      uart->write("vec size: " + std::to_string(myvec.size()));
  }
  delete led;
  delete uart;
}
