/*
 * GPIO_int.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Karim
 */

#ifndef MCAL_GPIO_GPIO_INT_H_
#define MCAL_GPIO_GPIO_INT_H_

typedef struct
{
	u8 Port;
	u8 Pin ;
	u8 Mode ;
	u8 OutputType;
	u8 OutputSpeed;
	u8 InputPull;
	u8 AltFun;
}MGPIO_Config_t;

#define ARM_DELAY(TIME_MS)  do{u32 i=TIME_MS*3600; while(i--){asm("nop");}}while(0)
#define GPIO_MODE_INPUT		 0b00
#define GPIO_MODE_OUTPUT	 0b01
#define GPIO_MODE_ALTFUN	 0b10
#define GPIO_MODE_ANALOG	 0b11

#define GPIO_PORTA			 0
#define GPIO_PORTB			 1
#define GPIO_PORTC			 2
enum
{
	GPIO_PIN0    ,
	GPIO_PIN1    ,
	GPIO_PIN2    ,
	GPIO_PIN3    ,
	GPIO_PIN4    ,
	GPIO_PIN5    ,
	GPIO_PIN6    ,
	GPIO_PIN7    ,
	GPIO_PIN8    ,
	GPIO_PIN9    ,
	GPIO_PIN10   ,
	GPIO_PIN11   ,
	GPIO_PIN12   ,
	GPIO_PIN13   ,
	GPIO_PIN14   ,
	GPIO_PIN15
};


#define PORT_INPUT   		 0x0000
#define PORT_OUTPUT  		 0xFFFF

#define GPIO_LOW             0
#define GPIO_HIGH            1
#define PORT_LOW             0x0000
#define PORT_HIGH            0xFFFF
#define CLR_LOW_NIBBLE       0xFF00
#define CLR_HIGH_NIBBLE      0x00FF

#define GPIO_OTYPE_PUSHPULL        0
#define GPIO_OTYPE_OPENDRAIN	   1

#define GPIO_SPEED_LOW	     0b00
#define GPIO_SPEED_MED		 0b01
#define GPIO_SPEED_HIGH	     0b10
#define GPIO_SPEED_VHIGH	 0b11

#define GPIO_INPUT_NO_PULL   0b00
#define GPIO_INPUT_PULL_UP   0b01
#define GPIO_INPUT_PULL_DOWN 0b10

void MGPIO_vSetPinMode(u8 A_u8PortId,
		               u8 A_u8PinNo ,
					   u8 A_u8Mode   );

void MGPIO_vSetPinOutputType(u8 A_u8PortId,
		                     u8 A_u8PinNo ,
					         u8 A_u8OutType   );

void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId,
							  u8 A_u8PinNo ,
							  u8 A_u8OutSpeed );

void MGPIO_vSetPinInputPull(u8 A_u8PortId,
							u8 A_u8PinNo ,
							u8 A_u8PullType );

u8   MGPIO_u8GetPinValue(u8 A_u8PortId,
						 u8 A_u8PinNo );

void MGPIO_vSetPinVal(u8 A_u8PortId,
					  u8 A_u8PinNo,
					  u8 A_u8PinVal);

void MGPIO_vSetPinVal_fast(u8 A_u8PortId,
					       u8 A_u8PinNo,
						   u8 A_u8PinVal);

void MGPIO_vSetAlternativeFunction(u8 A_u8PortId,
								   u8 A_u8PinNo,
							       u8 A_u8AltFun);
void MGPIO_vSetLowNibbleVal(u8 A_u8PortId, u8 A_u8Val);

void MGPIO_vInit(MGPIO_Config_t* A_xPinConfig);
#endif /* MCAL_GPIO_GPIO_INT_H_ */
