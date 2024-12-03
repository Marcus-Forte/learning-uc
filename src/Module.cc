#include "Module.hh"

Module::Module(const std::shared_ptr<ILED> &led,
               const std::shared_ptr<IUART> &uart,
               const std::shared_ptr<ITiming> &timing)
    : led_(led), uart_(uart), timing_(timing) {}

void Module::blink(uint32_t ms) {
  led_->on();
  timing_->delay(ms);
  led_->off();
  timing_->delay(ms);
}

void Module::send(const std::string &msg) { uart_->write(msg); }