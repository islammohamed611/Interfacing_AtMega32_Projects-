#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SSD_interface.h"
#include "LED_interface.h"
#include "SW_interface.h"
#include "DIO_interface.h"
#include "util/delay.h"


u8 i;
void LEDS_voidOn();
void LEDS_voidFlashing();
void LEDS_voidShiftingL();
void LEDS_voidShiftingR();
void SSD_voidCount();
void LEDS_Converging();


SSD_Type SSD = {SSD_COMMON_CATHODE,SSD_PORTD,SSD_PORTD,SSD_PIN7};
LED_Type Led_arr[8] ={ {LED_PORTC,LED_PIN0,ACTIVE_HIGH},
		{LED_PORTC,LED_PIN1,ACTIVE_HIGH},
		{LED_PORTC,LED_PIN2,ACTIVE_HIGH},
		{LED_PORTC,LED_PIN3,ACTIVE_HIGH},
		{LED_PORTC,LED_PIN4,ACTIVE_HIGH},
		{LED_PORTC,LED_PIN5,ACTIVE_HIGH},
		{LED_PORTC,LED_PIN6,ACTIVE_HIGH},
		{LED_PORTC,LED_PIN7,ACTIVE_HIGH}
};
SW_Type SW1  = {SW_PORTA,SW_PIN0,SW_Ext_PULL_UP};
SW_Type SW2  = {SW_PORTA,SW_PIN1,SW_Ext_PULL_UP};
SW_Type SW3  = {SW_PORTA,SW_PIN2,SW_Ext_PULL_UP};
SW_Type SW4  = {SW_PORTA,SW_PIN3,SW_Ext_PULL_UP};
SW_Type SW5  = {SW_PORTA,SW_PIN4,SW_Ext_PULL_UP};
SW_Type SW6  = {SW_PORTA,SW_PIN5,SW_Ext_PULL_UP};
SW_Type SW7  = {SW_PORTA,SW_PIN6,SW_Ext_PULL_UP};


void main ()
{
	SSD_voidInitialDataPort(SSD);
	SSD_voidEnable(SSD);
	s8 i;
	for (i=0;i<8;i++)
	{
		LED_voidInit(Led_arr[i]);
	}
	SW_voidInit(SW1);
	SW_voidInit(SW2);
	SW_voidInit(SW3);
	SW_voidInit(SW4);
	SW_voidInit(SW5);
	SW_voidInit(SW6);
	SW_voidInit(SW7);
	SSD_voidInitialDataPort(SSD);
	SSD_voidEnable(SSD);


	while (1)
	{

		if(SW_u8GetPressed(SW1))
		{
			LEDS_voidOn();
		}
		if (SW_u8GetPressed(SW2))
		{
			LEDS_voidFlashing();
		}
		if (SW_u8GetPressed(SW3))
		{
			LEDS_voidFlashing();
		}
		if (SW_u8GetPressed(SW4))
		{
			LEDS_voidShiftingL();
		}
		if (SW_u8GetPressed(SW5))
		{
			LEDS_voidShiftingR();
		}
		if (SW_u8GetPressed(SW7))
		{
			SSD_voidCount();
		}
		if (SW_u8GetPressed(SW6))
		{
			LEDS_Converging();
		}
	}
}

void LEDS_voidOn()
{
	for(i=0;i<8;i++)
	{
		LED_voidToggle(Led_arr[i]);
	}
	_delay_ms(250);
}


void LEDS_voidFlashing()
{
	for (i=0;i<8;i++)
	{
		LED_voidOn(Led_arr[i]);
		_delay_ms(250);
	}
	for (i=0;i<8;i++)
	{
		LED_voidOff(Led_arr[i]);

	}
}

void LEDS_voidShiftingL()
{
	for ( i=0;i<8;i++)
	{
		LED_voidOn(Led_arr[7-i]);
		_delay_ms(250);
	}
	_delay_ms(250);
	for ( i=0;i<8;i++)
	{
		LED_voidOff(Led_arr[7-i]);
	}
}

void LEDS_voidShiftingR()
{
	for (i=0;i<8;i++)
	{
		LED_voidOn(Led_arr[i]);
		LED_voidOn(Led_arr[7-i]);
		_delay_ms(250);

	}
	for (i=0;i<8;i++)
	{
		LED_voidOff(Led_arr[i]);
		LED_voidOff(Led_arr[7-i]);


	}
}
void SSD_voidCount()
{
	for (i=0;i<10;i++)
	{
		SSD_voidSendNumber(SSD,i);
		_delay_ms(500);
	}
	for (i=9;i>=0;i--)
	{
		SSD_voidSendNumber(SSD,i);
		_delay_ms(500);
	}

}
void LEDS_Converging()
{
	for (i=0;i<4;i++)
	{
		LED_voidOn(Led_arr[3-i]);
		LED_voidOn(Led_arr[4+i]);
		_delay_ms(500);
	}

	for (i=0;i<8;i++)
	{
		LED_voidOff(Led_arr[i]);
	}
}
