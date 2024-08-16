cmake_minimum_required(VERSION 3.20)
project(learning-stm32 C CXX)

set(ELF_OUT main.elf)
set(BIN_OUT main.bin)

add_executable(${ELF_OUT}
  # third_party/CMSIS_5/Device/ARM/ARMCM3/Source/startup_ARMCM3.c
  # third_party/CMSIS_5/Device/ARM/ARMCM3/Source/system_ARMCM3.c
  src/system_stm32f10x.c
  src/main.cc)
target_include_directories(${ELF_OUT} PRIVATE
  third_party/CMSIS_5/Device/ARM/ARMCM3/Include
  third_party/CMSIS_5/CMSIS/Core/Include)
target_link_options(${ELF_OUT} PRIVATE -T${CMAKE_SOURCE_DIR}/third_party/CMSIS_5/Device/ARM/ARMCM3/Source/GCC/gcc_arm.ld -lc -lnosys --specs=rdimon.specs -Wl,--gc-sections)
target_compile_definitions(${ELF_OUT} PRIVATE -DARMCM3 -DSTM32F10X_MD)

add_custom_target(${BIN_OUT} ALL
  COMMAND ${ARM_OBJCOPY} -Obinary ${ELF_OUT} ${BIN_OUT}
  DEPENDS ${ELF_OUT})