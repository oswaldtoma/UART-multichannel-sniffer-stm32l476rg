
#include "stm32l4xx_it.h"
#include "stm32l4xx.h"
#include "stm32l4xx_ll_usart.h"
#include "uart_dispatcher.h"

extern void ForwardToOutput(uint8_t byte);

static inline void ClearUsartErrors(USART_TypeDef *USARTx)
{
    if (LL_USART_IsActiveFlag_FE(USARTx))
    {
        LL_USART_ClearFlag_FE(USARTx);
    }
    if (LL_USART_IsActiveFlag_NE(USARTx))
    {
        LL_USART_ClearFlag_NE(USARTx);
    }
    if (LL_USART_IsActiveFlag_ORE(USARTx))
    {
        (void)LL_USART_ReceiveData8(USARTx);
        LL_USART_ClearFlag_ORE(USARTx);
    }
}

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
    ClearUsartErrors(UART4);
    if (LL_USART_IsActiveFlag_RXNE(UART4))
    {
        uint8_t data = LL_USART_ReceiveData8(UART4);
        ProcessReceivedByte(0, data);
    }
}

void UART5_IRQHandler(void)
{
    ClearUsartErrors(UART5);
    if (LL_USART_IsActiveFlag_RXNE(UART5))
    {
        uint8_t data = LL_USART_ReceiveData8(UART5);
        ProcessReceivedByte(1, data);
    }
}

void USART1_IRQHandler(void)
{
    ClearUsartErrors(USART1);
    if (LL_USART_IsActiveFlag_RXNE(USART1))
    {
        uint8_t data = LL_USART_ReceiveData8(USART1);
        ProcessReceivedByte(2, data);
    }
}

void USART3_IRQHandler(void)
{
    ClearUsartErrors(USART3);
    if (LL_USART_IsActiveFlag_RXNE(USART3))
    {
        uint8_t data = LL_USART_ReceiveData8(USART3);
        ProcessReceivedByte(3, data);
    }
}
