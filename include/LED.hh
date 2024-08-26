#pragma once

#include "ILED.hh"
#include "stm32f103xb.h"


// LED Implementation
class LED : public ILED {
public:
    LED(GPIO_TypeDef* port, uint16_t pin);
    virtual ~LED();

    void on() override;
    void off() override;
    void toggle() override;

    private:
        GPIO_TypeDef* port_;
        uint16_t pin_;
};