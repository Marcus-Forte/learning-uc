#include <stdio.h>
#include "stm32f10x.h"

int main (){
    SystemInit();
    SystemCoreClockUpdate();
    printf("Hello!");
}