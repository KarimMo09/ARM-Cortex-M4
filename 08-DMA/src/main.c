#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/NVIC/NVIC_int.h"
#include "MCAL/DMA/DMA_int.h"
void ISR()
{
	MGPIO_u8GetPinValue(0,0);
}

int main(void)
{
    MRCC_vInit();
    MRCC_vEnableClock( RCC_AHB1  ,RCC_DMA2_EN);
    MNVIC_vEnablePerihral(NVIC_DMA2_STREAM0_EN);

    u32 arr1[500],arr2[500],arr3[500],arr4[500];
    MDMA_vInit();
    MDMA_vSetStreamCallback(0,ISR);
    for(int i=0;i<500;i++)
    {
    	arr1[i]=i+1;
    	arr3[i]=499-i;
    }
    MDMA_vSetStream(0,arr1,arr2,32,500);
    MDMA_vEnableStream(0);
    for(int i=0;i<500;i++)
    {
    	arr4[i]=arr3[i];
    }

	while(1)
	{

	}
}
