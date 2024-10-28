#pragma once

#include <cstdint>

class ITiming {
public:
  virtual void delay(uint32_t ms) = 0;
};