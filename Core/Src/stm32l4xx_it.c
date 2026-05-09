
#include "stm32l4xx_it.h"
#include "stm32l4xx.h"
#include "stm32l4xx_ll_usart.h"
#include "uart_dispatcher.h"

extern void ForwardToOutput(uint8_t byte);

void NMI_Handler(void)
{
    while (1)
    {
    }
}

void HardFault_Handler(void)
{
    while (1)
    {
    }
}

void MemManage_Handler(void)
{
    while (1)
    {
    }
}

void BusFault_Handler(void)
{
    while (1)
    {
    }
}

void UsageFault_Handler(void)
{
    while (1)
    {
    }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

void SysTick_Handler(void)
{
}

void UART4_IRQHandler(void)
{
    if (LL_USART_IsActiveFlag_RXNE(UART4))
    {
        uint8_t data = LL_USART_ReceiveData8(UART4);
        ProcessReceivedByte(0, data);
    }
}

void UART5_IRQHandler(void)
{
    if (LL_USART_IsActiveFlag_RXNE(UART5))
    {
        uint8_t data = LL_USART_ReceiveData8(UART5);
        ProcessReceivedByte(1, data);
    }
}

void USART1_IRQHandler(void)
{
    if (LL_USART_IsActiveFlag_RXNE(USART1))
    {
        uint8_t data = LL_USART_ReceiveData8(USART1);
        ProcessReceivedByte(2, data);
    }
}

void USART3_IRQHandler(void)
{
    if (LL_USART_IsActiveFlag_RXNE(USART3))
    {
        uint8_t data = LL_USART_ReceiveData8(USART3);
        ProcessReceivedByte(3, data);
    }
}
