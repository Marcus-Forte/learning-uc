#include "stm32f10x.h"
#include <memory>
class MyObj {

private:
int attr_;
};

int main (){
    SystemInit();
    SystemCoreClockUpdate();
    MyObj a;
    std::shared_ptr<MyObj> heap_obj = std::make_shared<MyObj>();
    
}