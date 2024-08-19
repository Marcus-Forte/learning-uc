#include "stm32f103xb.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include <memory>

class MyObj {
    public:
    private:
    int attr_;
};
 GPIO_InitTypeDef LedGPIO {
    .Pin = GPIO_PIN_13,
    .Mode = GPIO_MODE_OUTPUT_PP,
    .Pull = GPIO_NOPULL,
    .Speed = GPIO_SPEED_FREQ_LOW
};

int main (){
    std::shared_ptr<MyObj> heap_obj;
    // heap_obj = std::make_shared<MyObj>();
    HAL_Init();
    HAL_GPIO_Init(GPIOC, &LedGPIO);

    while(true) {
        HAL_Delay(1000);
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
         HAL_Delay(1000);
         HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    }
    
}