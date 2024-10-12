cmake_minimum_required(VERSION 3.20)
project(learning-uc C ASM CXX)
set(ELF_OUT main.elf)
set(BIN_OUT main.bin)

# HAL Layer
set(HAL_SRC
  hal/cmsis_device_f1/Source/Templates/system_stm32f1xx.c
  hal/cmsis_device_f1/Source/Templates/gcc/startup_stm32f103xb.s
  hal/stm32f1xx_hal_driver/Src/stm32f1xx_hal_adc_ex.c
  hal/stm32f1xx_hal_driver/Src/stm32f1xx_hal.c
  hal/stm32f1xx_hal_driver/Src/stm32f1xx_hal_cortex.c
  hal/stm32f1xx_hal_driver/Src/stm32f1xx_hal_gpio.c
  hal/stm32f1xx_hal_driver/Src/stm32f1xx_hal_uart.c
  hal/stm32f1xx_hal_driver/Src/stm32f1xx_hal_dma.c
  hal/stm32f1xx_hal_driver/Src/stm32f1xx_hal_rcc.c
)

add_library(stm32f1xx_hal ${HAL_SRC})
target_include_directories(stm32f1xx_hal PUBLIC
  hal/CMSIS_5/CMSIS/Core/Include # CMSIS: core_cm3.h  
  hal/cmsis_device_f1/Include # MCU: stm32f1xx.h
  hal/stm32f1xx_hal_driver/Inc # HAL
  include # HAL_conf.h
) 

target_compile_definitions(stm32f1xx_hal PUBLIC STM32F103xB)
target_compile_options(stm32f1xx_hal PUBLIC
  # -ffreestanding
  -nostdlib
  -mthumb
  -mcpu=cortex-m3
  -fdata-sections
  -Werror 
  -Warray-bounds 
  -fno-strict-aliasing 
  -specs=nano.specs 
  -specs=nosys.specs
)

target_link_options(stm32f1xx_hal PUBLIC -T${CMAKE_SOURCE_DIR}/hal/stm32f103.ld
-Wl,-gc-sections,--print-memory-usage -mthumb -specs=nosys.specs -specs=nano.specs
)

# Main app
add_executable(${ELF_OUT}
  src/stubs.c
  src/LED.cc
  src/main.cc
  src/UART.cc
)
target_link_libraries(${ELF_OUT} stm32f1xx_hal)
target_include_directories(${ELF_OUT} PUBLIC
  include
)

add_custom_target(${BIN_OUT} ALL
  COMMAND ${ARM_OBJCOPY} -Obinary ${ELF_OUT} ${BIN_OUT}
  DEPENDS ${ELF_OUT}
)