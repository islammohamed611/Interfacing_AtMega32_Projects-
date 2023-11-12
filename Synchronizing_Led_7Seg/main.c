#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "SSD_interface.h"
#include "BUZ_interface.h"
#include "DIO_interface.h"
#include "util/delay.h"

LED_Type LED[8] = {{LED_PORTA,LED_PIN0,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN1,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN2,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN3,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN4,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN5,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN6,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN7,ACTIVE_HIGH}};

SSD_Type SSD = {SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN0};
BUZ_Type BUZ = {BUZ_PORTD,BUZ_PIN0,ACTIVE_HIGH};

void main ()
{
	u8 i,j;
	for (i=0 ;i<8;i++)
	{
		LED_voidInit(LED[i]);
	}
	SSD_voidInitialDataPort(SSD);
	SSD_voidEnable(SSD);

	while (1)

	{
		for (i=0; i<9 ;i++)
		{
			if (i==0)
			{
				for(j=0;j<8;j++)
				{
					LED_voidOff(LED[j]);
					BUZ_voidOff(BUZ);
				}
				SSD_voidSendNumber(SSD,i);
				_delay_ms(1000);
				continue;
			}
			LED_voidOn(LED[i-1]);
			SSD_voidSendNumber(SSD,i);
			if (i==8)
			{
				BUZ_voidOn(BUZ);
			}
			_delay_ms(1000);
		}

	}



}
