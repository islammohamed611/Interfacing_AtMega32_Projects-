/*
 *
 * main.c
 *
 *  Created on: Dec 2, 2023
 *      Author: Islam Mohamed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "LED_interface.h"

/************************************************/
LED_Type LED1 ={LED_PORTC,LED_PIN0,ACTIVE_HIGH};
LED_Type LED2 ={LED_PORTC,LED_PIN1,ACTIVE_HIGH};
LED_Type LED3 ={LED_PORTC,LED_PIN2,ACTIVE_HIGH};
LED_Type LED4 ={LED_PORTC,LED_PIN3,ACTIVE_HIGH};
LED_Type LED5 ={LED_PORTC,LED_PIN4,ACTIVE_HIGH};
LED_Type LED6 ={LED_PORTC,LED_PIN5,ACTIVE_HIGH};
LED_Type LED7 ={LED_PORTC,LED_PIN6,ACTIVE_HIGH};
LED_Type LED8 ={LED_PORTC,LED_PIN7,ACTIVE_HIGH};

u8 KPD_Value =0;

/*************************************************/
static void Leds_off ()
{
	LED_voidOff(LED1);
	LED_voidOff(LED2);
	LED_voidOff(LED3);
	LED_voidOff(LED4);
	LED_voidOff(LED5);
	LED_voidOff(LED6);
	LED_voidOff(LED7);
	LED_voidOff(LED8);
}
/*****************************************/
static void APP_Init()
{
	CLCD_voidInit();
	KPD_Init();
	LED_voidInit(LED1);
	LED_voidInit(LED2);
	LED_voidInit(LED3);
	LED_voidInit(LED4);
	LED_voidInit(LED5);
	LED_voidInit(LED6);
	LED_voidInit(LED7);
	LED_voidInit(LED8);

}

int main ()
{
	APP_Init();
	while (1)
	{
		KPD_Value =KPD_u8GetPressed();

		if (KPD_Value != 0xff)
		{
			CLCD_voidSendData(KPD_Value);
			switch (KPD_Value)
			case '1':
				Leds_off();
				LED_voidOn(LED1);
				break;
			case '2':
				Leds_off();
				LED_voidOn(LED2);
				break;
			case '3':
				Leds_off();
				LED_voidOn(LED3);
				break;
			case '4':
				Leds_off();
				LED_voidOn(LED4);
				break;
			case '5':
				Leds_off();
				LED_voidOn(LED5);
				break;
			case '6':
				Leds_off();
				LED_voidOn(LED6);
				break;
			case '7':
				Leds_off();
				LED_voidOn(LED7);
				break;
			case '8':
				Leds_off();
				LED_voidOn(LED8);
				break;
		}
	}
}
