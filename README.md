# Cmake Project for STM32F1
Minimal C++ project that builds for STM32F1xx devices. Works for [Blue Pill](https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html)

### Debug 
- Connect ST-Link V2 on your host machine. Make sure 
- install `stlink` tools. 
- On the host, start session with `st-util`. This serves as a gdb server. Check launch.json for the host address from within the docker container.
- Start Lauch Vscode target.
