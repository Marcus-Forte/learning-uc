FROM ubuntu:latest

RUN apt-get update && apt-get install -y build-essential \
    git \
    gcc-arm-none-eabi \
    gdb-arm-none-eabi \
    cmake \
    bash-completion \
    clangd \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*