#pragma once

#include "IUART.hh"
#include "stm32f1xx_hal_dma.h"
#include "stm32f1xx_hal_uart.h"

class UART : public IUART {
    public:
    UART(USART_TypeDef* instance);

    /** newline transmitted automatically **/
    
    void write(const std::string& msg) override;
    private:
    UART_HandleTypeDef uart_;
};