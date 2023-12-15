/*
 * main.c
 *
 *  Created on: Dec 15, 2023
 *      Author: islam
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "CLCD_interface.h"
#include "LED_interface.h"
#include "LM35_interface.h"
#include "ADC_interface.h"

LED_Type LED1 = {LED_PORTA,LED_PIN0,ACTIVE_HIGH};
LED_Type LM = {ADC_CHANNEL0, AVCC,ADC_RESOLUTION_10_BIT};
void APP_Init ()
{
	LED_voidInit(LED1);
	CLCD_voidInit();
	ADC_voidInit();


}

void main (void)
{
	APP_Init();
	u8 Local_u8ADCReading;
	ADC_voidEnable();
	while (1)
	{

		Local_u8ADCReading=LM35_u8GetTemp(LM,Local_u8ADCReading);
		CLCD_voidSendData(Local_u8ADCReading);
		if (Local_u8ADCReading >=20)
		{
			LED_voidOn(LED1);


		}
		else
		{

			LED_voidOff(LED1);
		}
	}
}

