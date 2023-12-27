/*
 * main.c
 *
 *  Created on: Dec 26, 2023
 *      Author: islam
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "TIMER_interface.h"

/*intializations */
LED_Type LED1 = {LED_PORTA ,LED_PIN0 ,ACTIVE_HIGH};
LED_Type LED2 = {LED_PORTA ,LED_PIN1 ,ACTIVE_HIGH};

u8 Copy_u8PreLoad1 = 192 ;
u8 Copy_u8PreLoad2 = 400 ;

u8 counter1 = 0 ;
u8 counter2 = 0 ;

void LED1_ON ();
void LED2_ON();

void main (void)
{
	LED_voidInit(LED1);
	LED_voidInit(LED2);
	TIMER0_voidInit();
	TIMER2_voidInit();

	TIMER_u8SetCallBack(LED1_ON,TIMER0_CTC_VECTOR_ID);
	TIMER_u8SetCallBack(LED2_ON,TIMER2_CTC_VECTOR_ID);
	GIE_VoidEnable();

	while (1)
	{

	}


}

void LED1_ON ()
{
	counter1++;
	if(counter1 ==4883)
	{
		TIMER0_voidSetPreload(Copy_u8PreLoad1);
		LED_voidToggle(LED1);
		counter1 =0;
	}

}

void LED2_ON()
{
	TIMER2_voidSetPreload(Copy_u8PreLoad2);
	LED_voidToggle(LED2);
	counter2 =0;
}

