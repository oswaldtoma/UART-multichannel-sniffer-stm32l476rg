#include "uart_dispatcher.h"

extern void ForwardToOutput(uint8_t byte);

void ProcessReceivedByte(uint8_t channel, uint8_t byte)
{    
    ForwardToOutput(byte);
}