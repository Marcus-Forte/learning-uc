FROM ubuntu:latest

RUN apt-get update && apt-get install -y build-essential \
    git \
    gcc-arm-none-eabi \
    gdb-arm-none-eabi \
    libnewlib-arm-none-eabi \
    libstdc++-arm-none-eabi-newlib \
    python3 \
    cmake \
    bash-completion \
    clangd \
    stlink-tools \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*