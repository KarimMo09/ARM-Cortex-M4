#include "LIB/STD_TYPES.h"
#include "LIB/Bit_math.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/STK/STK_int.h"
#include "HAL/LED_MATRIX/LEDMTX_int.h"

int main()
{
	 MRCC_vInit();
	 MRCC_vEnableClock( RCC_AHB1  ,RCC_GPIOA_EN);
	 MRCC_vEnableClock( RCC_AHB1  ,RCC_GPIOB_EN);
	 HLEDMTX_vInit();
	 u8 Smile[]={16,32,76,64,64,74,32,16};
	 HLEDMTX_vDispalyFrame(Smile,1000*MS);

      while (1)
     {
    	  HLEDMTX_vDispalyFrame(Smile,1000*MS);
     }

}

