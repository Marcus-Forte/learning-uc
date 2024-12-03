#pragma once

#include "ILED.hh"
#include "ITiming.hh"
#include "IUART.hh"

#include <memory>

class Module {
public:
  Module(const std::shared_ptr<ILED> &led, const std::shared_ptr<IUART> &uart,
         const std::shared_ptr<ITiming> &timing);

  void blink(uint32_t ms);

  void send(const std::string &msg);

private:
  std::shared_ptr<ILED> led_;
  std::shared_ptr<IUART> uart_;
  std::shared_ptr<ITiming> timing_;
};