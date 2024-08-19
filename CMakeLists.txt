cmake_minimum_required(VERSION 3.20)

# STM32F103C8T6 #
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(ARM_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR arm)

project(learning-uc C ASM CXX)
set(ELF_OUT main.elf)
set(BIN_OUT main.bin)
file(GLOB HAL_SRC
hal/stm32f1xx_hal_driver/Src/*.c)
# message(STATUS ${HAL_SRC})
add_library(stm32f1xx_hal ${HAL_SRC})
target_include_directories(stm32f1xx_hal PUBLIC
  hal/stm32f1xx_hal_driver/Inc # HAL
  hal/cmsis_device_f1/Include
  hal/CMSIS_5/CMSIS/Core/Include # MCU
  include) # HAL CONF
target_compile_definitions(stm32f1xx_hal PUBLIC STM32F103xB)
target_compile_options(stm32f1xx_hal PUBLIC
  -ffreestanding
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
-Wl,-gc-sections,--print-memory-usage -mcpu=cortex-m3 -mthumb
)
# Main app
add_executable(${ELF_OUT}
  hal/cmsis_device_f1/Source/Templates/system_stm32f1xx.c
  hal/cmsis_device_f1/Source/Templates/gcc/startup_stm32f103xb.s
  src/main.cc)
target_link_libraries(${ELF_OUT} stm32f1xx_hal)
target_include_directories(${ELF_OUT} PUBLIC
  include
  hal/cmsis_device_f1/Include
  hal/stm32f1xx_hal_driver/Inc
  hal/CMSIS_5/CMSIS/Core/Include)

add_custom_target(${BIN_OUT} ALL
  COMMAND ${ARM_OBJCOPY} -Obinary ${ELF_OUT} ${BIN_OUT}
  DEPENDS ${ELF_OUT})
#

# RPI Pico #
# set(PICO_SDK_PATH ${CMAKE_SOURCE_DIR}/third_party/pico-sdk)
# include(third_party/pico-sdk/external/pico_sdk_import.cmake)
# project(learning-pico C CXX)
# pico_sdk_init()

# add_executable(hello_world
#     src_pi/hello.cc
# )

# # Add pico_stdlib library which aggregates commonly used features
# target_link_libraries(hello_world pico_stdlib)
# pico_enable_stdio_usb(hello_world 1)
# pico_enable_stdio_uart(hello_world 0)
# # create map/bin/hex/uf2 file in addition to ELF.
# pico_add_extra_outputs(hello_world)

# #