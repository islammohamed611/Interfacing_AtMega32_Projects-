/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: islam
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "SW_interface.h"
#include "EXTI_interface.h"

#include "GIE_interface.h"
#include "avr/delay.h"

LED_Type LED1 = {LED_PORTA ,LED_PIN0 ,ACTIVE_HIGH};
SW_Type  SW1  = {DIO_PORTD ,DIO_PIN2 ,SW_Int_PULL_UP};


LED_Type LED2 = {LED_PORTA ,LED_PIN1 ,ACTIVE_HIGH};
SW_Type  SW2  = {DIO_PORTD ,DIO_PIN3 ,SW_Int_PULL_UP};

void Func_SW1()
{
	LED_voidToggle(LED1);
}
void Func_SW2()
{
	LED_voidOn(LED2);
}


void main (void)
{


			LED_voidInit(LED1);
			LED_voidInit(LED2);
			SW_voidInit(SW1);
			SW_voidInit(SW2);

			/*these two funcltions instead of EXTI_void_Init*/
			EXTI_voidSetSignalLatch(EXTI_FALLING_EDGE,EXTI_LINE0);
			EXTI_voidSetSignalLatch(EXTI_FALLING_EDGE,EXTI_LINE1);

			EXTI_voidSetCallBack(Func_SW1,EXTI_LINE0);
			EXTI_voidSetCallBack(Func_SW2,EXTI_LINE1);

			EXTI_voidEnableInterrupt(EXTI_LINE0);
			EXTI_voidEnableInterrupt(EXTI_LINE1);

			GIE_VoidEnable();
	while (1)
	{
		/*using interrupt*/

	}
}
