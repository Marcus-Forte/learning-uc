

#include "LED.hh"
#include "Module.hh"
#include "Timing.hh"
#include "UART.hh"
#include "stm32f1xx_hal.h"

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

  Module module(led, uart, timing);
  std::string msg;
  uint16_t count = 0;

  while (1) {

    module.blink(100);

    module.blink(200);

    module.blink(300);

    msg = "Hello " + std::to_string(count) + "!";

    module.send(msg.c_str());

    timing->delay(1000);

    count++;
  }
}
