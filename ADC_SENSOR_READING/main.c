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
LED_Type LM = {ADC_CHANNEL0, AVCC,ADC_RESOLUTION_8_BIT};
static void APP_Init ()
{
	ADC_voidInit();
	LED_voidInit(LED1);
	CLCD_voidInit();
	LED_voidOff(LED1);


}

void main (void)
{
	u8 LM_V;
	APP_Init();
	CLCD_voidSendString((u8 *)"islam mohamed");

	while (1)
	{

CLCD_voidSendString((u8 *)"Temp=");
LM35_u8GetTemp(&LM,&LM_V);
CLCD_voidSendNumber(LM_V);

CLCD_voidSendString((u8 *)"  C");

if (LM_V >=20)
{
	LED_voidOn(LED1);
}
else {
	LED_voidOff(LED1);
}

	}

}

