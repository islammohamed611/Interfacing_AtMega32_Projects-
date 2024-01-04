/*
 * APP_program.c

 *
 *  Created on: 1 january  2024
 *      Author: Islam Mohamed
 */

/*LIB includes */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
/*MCAL includes */
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/PORT/PORT_interface.h"
#include "../MCAL/TIMER0/TIMER_interface.h"
/*HAL includes */
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SW_interface.h"
#include "../HAL/SSD/SSD_interface.h"
/*APP includes */
#include "APP_interface.h"


/**************************************************************************/
/********************* Proj Objects *****************/
/* Car Leds */
LED_Type CAR_RED_LED = {LED_PORTA,LED_PIN0,ACTIVE_HIGH};
LED_Type CAR_YELLOW_LED = {LED_PORTA,LED_PIN1,ACTIVE_HIGH};
LED_Type CAR_GREEN_LED = {LED_PORTA,LED_PIN2,ACTIVE_HIGH};
/* Pedestrains Leds */
LED_Type Pedes_Red_Led ={LED_PORTC ,LED_PIN0,ACTIVE_HIGH};
LED_Type Pedes_Yellow_Led ={LED_PORTC ,LED_PIN1,ACTIVE_HIGH};
LED_Type Pedes_Green_Led ={LED_PORTC ,LED_PIN2,ACTIVE_HIGH};
/* Control SW */
SW_Type SW = {SW_PORTD ,SSD_PIN2,SW_Int_PULL_UP};
/* SSD */
SSD_Type SSD = {SSD_COMMON_CATHODE,SSD_PORTC,SSD_PIN7};
/**************************************************************************/
/********************* Proj Enums *****************/

/*Init Car LED States*/
LED_STATE_t CAR_Red_Led = LED_IDLE;
LED_STATE_t CAR_Yellow_Led = LED_IDLE;
LED_STATE_t CAR_Green_Led = LED_IDLE;
/*Init pedestrian LED States*/
LED_STATE_t PedesRed_Led =LED_IDLE;
LED_STATE_t PedesYellow_Led =LED_IDLE;
LED_STATE_t PedesGreen_Led =LED_IDLE;

/*initial mode state*/
MODE_t Mood_State = NORMAL_MODE;
/**************************************************************************/
/********************* For Timer (CTC Mode) *****************/
/* COV Value */
#define COV 1000
/* Preload Value */
#define Preload_Val 125
/* Any SW Counters / Global Variables*/
u16 Timer_SWCounter=0;
u16 Modes_Counter=0;

/**************************************************************************/

/*All application logic*/
void APP_voidPeriodicTask(void)
{
	// INC SW Counter
	Timer_SWCounter ++;
	if (Timer_SWCounter == COV)
	{
		// We want ---> Action Every One Sec
		SSD_voidSendNumber(SSD,(Modes_Counter%5));
		Modes_Counter++;
		switch(Mood_State)
		{
		case NORMAL_MODE :
			if(Modes_Counter <=5)
			{
				CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
				CLCD_voidSendString((u8*)"you Can Move Now");

				LED_voidOn(PedesGreen_Led);
				PedesGreen_Led  =LED_ACTIVE;
				LED_voidOff(PedesRed_Led);
				Pedes_Red_Led = LED_IDLE;
				LED_voidOff(Pedes_Yellow_Led);
				PedesYellow_Led= LED_IDLE;

				LED_voidOn(CAR_RED_LED);
				CAR_RED_LED = LED_ACTIVE;
				LED_voidOff(CAR_GREEN_LED);
				CAR_Green_Led = LED_IDLE;
				LED_voidOff(CAR_YELLOW_LED);
				CAR_Green_Led = LED_IDLE;



			}
			else if ((Modes_Counter > 5) && (Modes_Counter <=10))
			{
				CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
				CLCD_voidSendString((u8*)"Don Not Move");

				LED_voidOn(Pedes_Red_Led);
				Pedes_Red_Led LED_ACTIVE;
				LED_voidOff(PedesGreen_Led);
				PedesGreen_Led = LED_IDLE;
				LED_voidOff(Pedes_Yellow_Led);
				PedesYellow_Led= LED_IDLE;

				LED_voidOn(CAR_GREEN_LED);
				CAR_GREEN_LED = LED_ACTIVE;
				LED_voidOff(CAR_Red_Led);
				CAR_Red_Led = LED_IDLE;
				LED_voidOff(CAR_YELLOW_LED);
				CAR_YELLOW_LED = LED_IDLE;

			}
			else if ((Modes_Counter >10) && (Modes_Counter <=15))
			{
				CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
				CLCD_voidSendString((u8*)"Wait....");

				LED_voidOn(Pedes_Yellow_Led);
				Pedes_Yellow_Led LED_ACTIVE;
				LED_voidOff(PedesGreen_Led);
				PedesGreen_Led = LED_IDLE;
				LED_voidOff(Pedes_Red_Led);
				Pedes_Red_Led= LED_IDLE;

				LED_voidOn(CAR_YELLOW_LED);
				CAR_YELLOW_LED = LED_ACTIVE;
				LED_voidOff(CAR_Red_Led);
				CAR_Red_Led = LED_IDLE;
				LED_voidOff(CAR_GREEN_LED);
				CAR_GREEN_LED = LED_IDLE;

				//Reset Modes Counter
				if (Modes_Counter ==15)
				{
					Modes_Counter =0;
				}
			}
			else if ((Modes_Counter >15) && (Modes_Counter <=20))
			{
				CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
				CLCD_voidSendString((u8*)"Wait....");
				LED_voidOff(PedesRed_Led);
				PedesRed_Led = LED_IDLE;
				LED_voidOff( Pedes_Green_Led);
				PedesGreen_Led = LED_IDLE;

				LED_voidToggle(CAR_YELLOW_LED);
				LED_voidToggle(PedesYellow_Led);

				// reset Modes Counter
				if (Modes_Counter ==20)
				{
					Modes_Counter =0;
				}

			}
			break;
		case  PEDESTRIAN_MODE :
			if ((CAR_RED_LED == LED_ACTIVE) && (CAR_GREEN_LED ==LED_IDLE) && (CAR_YELLOW_LED == LED_IDLE))
			{
				Modes_Counter =0;
				Mood_State = NORMAL_MODE ;
			}
			break ;
		}
		Timer_SWCounter =0 ;
		TIMER0_voidSetPreload(Preload_Val);

	}



}

/*all Initials I need */
void APP_voidInit(void)
{
	// All Initializations 
	// PORT
	PORT_voidInit();
	// SSD
	SSD_voidInitialDataPort(SSD);
	SSD_voidEnable(SSD);
	// CLCD
	CLCD_voidInit();

	// EXTI
	EXTI_voidSetSignalLatch(EXTI_FALLING_EDGE,EXTI_LINE0);
	EXTI_voidSetCallBack(INT0_ISR,0);
	EXTI_voidEnableInterrupt(EXTI_LINE0);
	EXTI_voidInit();



	// SW
	SW_voidInit(SW);
	// Timer0
	TIMER_u8SetCallBack(APP_voidPeriodicTask,TIMER0_CTC_VECTOR_ID);
	TIMER0_voidInit();
	GIE_VoidEnable();
}

/* EXTI CallBack Func */
void INT0_ISR(void)
{
	/* Do not edit this section (ISR have to be very small) */
	Mood_State = PEDESTRIAN_MODE;
}
