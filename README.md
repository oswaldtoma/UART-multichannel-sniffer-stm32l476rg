# UART Multichannel Sniffer

Simple UART multichannel (multiRX) sniffer for stm32l476rg. Nothing interesting here. It's supposed to be merging data received on multiple UARTs and send it through output UART unified.

## Features

- Monitors UART4, UART5, USART1, and USART3
- RX-only inputs with pull-ups
- All sniffed data forwarded to USART2 TX
- **115200 Baud**

## Hardware Configuration

### RX Input Channels
- **UART4**: PA1 (Channel 0)
- **UART5**: PD2 (Channel 1)
- **USART1**: PA10 (Channel 2)
- **USART3**: PC5 (Channel 3)

### TX Output Channel
- **USART2**: PA2

## Building

- ARM GCC toolchain (arm-none-eabi-gcc)
- CMake 3.22+
- Compatible with VS Code (Cortex-Debug extension)

### Build Commands
```bash
# Configure
cmake --preset Debug

# Build
cmake --build build/Debug
```
