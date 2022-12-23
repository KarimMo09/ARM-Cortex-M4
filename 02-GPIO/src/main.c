#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "HAL/SSD/SSD_int.h"

int main(void)
{
    MRCC_vInit();
    MRCC_vEnableClock( RCC_AHB1  ,RCC_GPIOA_EN);
    SSD_vInit();

	while(1)
	{
		for(u8 i=0; i<10;i++)
		{
			SSD_vDisplayNum(i);
			ARM_DELAY(500);
		}
		MGPIO_vSetPinVal(GPIO_PORTA,0,1);
		ARM_DELAY(5000);

	}
}
