#include "stm32l4xx.h"

#if !defined  (HSE_VALUE)
  #define HSE_VALUE    8000000U  
#endif 

#if !defined  (MSI_VALUE)
  #define MSI_VALUE    4000000U  
#endif 

#if !defined  (HSI_VALUE)
  #define HSI_VALUE    16000000U 
#endif 

#if defined(USER_VECT_TAB_ADDRESS)

#if defined(VECT_TAB_SRAM)
#define VECT_TAB_BASE_ADDRESS   SRAM1_BASE      
#else
#define VECT_TAB_BASE_ADDRESS   FLASH_BASE      
#endif 

#if !defined(VECT_TAB_OFFSET)
#define VECT_TAB_OFFSET         0x00000000U     
#endif 

#endif 

uint32_t SystemCoreClock = 4000000U;

const uint8_t  AHBPrescTable[16] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U, 6U, 7U, 8U, 9U};
const uint8_t  APBPrescTable[8] =  {0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U};
const uint32_t MSIRangeTable[12] = {100000U,   200000U,   400000U,   800000U,  1000000U,  2000000U, \
                                    4000000U, 8000000U, 16000000U, 24000000U, 32000000U, 48000000U};

void SystemInit(void)
{
#if defined(USER_VECT_TAB_ADDRESS)
  
  SCB->VTOR = VECT_TAB_BASE_ADDRESS | VECT_TAB_OFFSET;
#endif

#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
  SCB->CPACR |= ((3UL << 20U)|(3UL << 22U));  
#endif
}

void SystemCoreClockUpdate(void)
{
  uint32_t tmp, msirange, pllvco, pllsource, pllm, pllr;

  
  if ((RCC->CR & RCC_CR_MSIRGSEL) == 0U)
  { 
    msirange = (RCC->CSR & RCC_CSR_MSISRANGE) >> 8U;
  }
  else
  { 
    msirange = (RCC->CR & RCC_CR_MSIRANGE) >> 4U;
  }
  
  msirange = MSIRangeTable[msirange];

  switch (RCC->CFGR & RCC_CFGR_SWS)
  {
    case 0x00:  
      SystemCoreClock = msirange;
      break;

    case 0x04:  
      SystemCoreClock = HSI_VALUE;
      break;

    case 0x08:  
      SystemCoreClock = HSE_VALUE;
      break;

    case 0x0C:  
      
      pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC);
      pllm = ((RCC->PLLCFGR & RCC_PLLCFGR_PLLM) >> 4U) + 1U ;

      switch (pllsource)
      {
        case 0x02:  
          pllvco = (HSI_VALUE / pllm);
          break;

        case 0x03:  
          pllvco = (HSE_VALUE / pllm);
          break;

        default:    
          pllvco = (msirange / pllm);
          break;
      }
      pllvco = pllvco * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 8U);
      pllr = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLR) >> 25U) + 1U) * 2U;
      SystemCoreClock = pllvco/pllr;
      break;

    default:
      SystemCoreClock = msirange;
      break;
  }
  
  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4U)];
  
  SystemCoreClock >>= tmp;
}
