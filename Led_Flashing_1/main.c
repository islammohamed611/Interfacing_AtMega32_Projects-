#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "DIO_interface.h"
#include "LED_interface.h"



LED_Type arr[8]= { {LED_PORTA,LED_PIN0,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN1,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN2,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN3,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN4,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN5,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN6,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN7,ACTIVE_HIGH}};


void main()
{
	int i;
	for (i=0;i<8;i++)
	{
		LED_voidInit(arr[i]);
	}
	while (1)
	{
		for(i=0;i<8;i++)
		{
			LED_voidToggle(arr[i]);
		}
		_delay_ms(250);

	}
}



