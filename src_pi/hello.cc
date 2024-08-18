#include "pico/stdlib.h"
#include <chrono>
#include <cstdio>
#include <hardware/gpio.h>
#include <pico/time.h>
#include <stdio.h>
#include <thread>
#include <unistd.h>

unsigned sleep(unsigned int time) {
  sleep_ms(time);
  return 0;
}

int usleep(unsigned long time) {
  sleep_us(time);
  return 0;
}
class MyObj {
public:
private:
  int attr_;
};

int main() {

  const uint8_t led_pin = 25;

  setup_default_uart();
  gpio_init(led_pin);
  gpio_set_dir(led_pin, true);

  while (true) {
    gpio_put(led_pin, true);
    sleep_ms(50);
    gpio_put(led_pin, false);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  return 0;
}