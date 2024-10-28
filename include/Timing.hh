#pragma once

#include "ITiming.hh"

class Timing : public ITiming {
public:
  Timing();
  void delay(uint32_t ms) override;
};