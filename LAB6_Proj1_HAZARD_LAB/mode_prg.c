/******************************************************************************/
/*   Auther         :Islam Mohamed Abdullah                                   */
/* !Layer           : Application Abstraction Layer                           */

/*                                                                            */
/* !Component       : MODE                                                    */
/* !Description     : Hazzard Indicator Function module                       */
/*                                                                            */
/* !Module          : MODE                                                    */
/* !Description     : MODE Module interface                                   */
/*                                                                            */
/* !File            : mode_prg.c                                              */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Induction training exercise project                     */
/*                                                                            */
/* !Target          : ATMega32                                                */
/*                                                                            */
/* !Compiler        : AVR GCC Cross Compiler                                  */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Coded by        : Islam Mohamed Abdullah             !Date : NOV 25, 2023    */
/*                                                                            */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SW_interface.h"
#include "SSD_interface.h"
#include "CLCD_interface.h"


#include "mode_int.h"



/******************************************************************************/

/* Global Variables Definition */

MODE_enutModeState enum_Modes ,Previus_enumMode;



/*****************************************************************************************/
extern SSD_Type R_SSD ;
extern SSD_Type L_SSD ;

extern SW_Type R_SW ;
extern SW_Type L_SW ;
extern SW_Type H_SW ;
/*****************************************************************************************/

/******************************************************************************/
/*! \Description Helper Functions                                             */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void APP_vidSetMode(MODE_enutModeState enutSetMode)
{
	switch(enutSetMode)
	{
	/* Switch to the Mode  */
	case  IDLE :
		CLCD_voidSendString ("IDLE");
		SSD_voidDisable(R_SSD);
		SSD_voidDisable(L_SSD);
		break;
	case  RIGHT_BLINK :
		CLCD_voidSendString("Right");
		SSD_voidSendNumber(R_SSD,0);
		break ;
	case  LEFT_BLINK :

		CLCD_voidSendString("Left");
		SSD_voidSendNumber(L_SSD,0);
		break ;
	case HAZZARD_BLINK :
		SSD_voidEnable(L_SSD);
		SSD_voidEnable(R_SSD);
		CLCD_voidSendString("Hazard");
		SSD_voidSendNumber(L_SSD,0);
		SSD_voidSendNumber(R_SSD,0);

	}

}

/***************************************/
void MODE_vidIdle (void)
{
	/* Set Mode to IDLE */
	APP_vidSetMode(IDLE);
	/* Check the SWs */
	if (SW_u8GetPressed(R_SW))
	{
		enum_Modes = RIGHT_BLINK;
	}
	else if (SW_u8GetPressed(L_SW))
	{
		enum_Modes = LEFT_BLINK;
	}
	else if (SW_u8GetPressed(H_SW))
	{
		enum_Modes = HAZZARD_BLINK;
	}
}
void MODE_vidRightBlink (void)
{
	/* Set Mode to RIGHT_BLINK */
	APP_vidSetMode(RIGHT_BLINK);
	/* Check the SWs */


	 if (SW_u8GetPressed(L_SW))
		{
			enum_Modes = IDLE;
		}
	if (SW_u8GetPressed(H_SW))
		{
			Previus_enumMode =RIGHT_BLINK;
			enum_Modes =  HAZZARD_BLINK;
		}
}
void MODE_vidLeftBlink (void)
{
	/* Set Mode to LEFT_BLINK */
	APP_vidSetMode(LEFT_BLINK);
	/* Check the SWs */

	 if (SW_u8GetPressed(R_SW))
	{
		enum_Modes = IDLE;
	}
	if (SW_u8GetPressed(H_SW))
	{
		Previus_enumMode =LEFT_BLINK;
		enum_Modes =  HAZZARD_BLINK;
	}

}
void MODE_vidHazardBlink (void)
{
	/* Set Mode to HAZZARD_BLINK */
	APP_vidSetMode(HAZZARD_BLINK);
	/* Check the SWs */
	 if (SW_u8GetPressed(R_SW))
	{
		enum_Modes = HAZZARD_BLINK;
	}
	 if (SW_u8GetPressed(H_SW))
	 {
		 enum_Modes = Previus_enumMode;
	 }
	if (SW_u8GetPressed(L_SW))
	{

		enum_Modes =  HAZZARD_BLINK;
	}

}


/*****************************************************************************************/

/******************************************************************************/
/*! \Description Initialize the MODE driver variables                         */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void MODE_vidInit(void)
{
	/* Set Mode to Default (IDLE) */
	enum_Modes = IDLE;
}

/******************************************************************************/
/*! \Description The MODE driver task, should be called periodically.
				 This service update the state of all configured push
                 buttons.                                                     */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void MODE_vidTask(void)
{
	/* Check the global enum then call Mode API According to it */
	if ( enum_Modes== IDLE)
	{
		MODE_vidIdle();
	}
	else if (enum_Modes==RIGHT_BLINK)
	{
		MODE_vidRightBlink();
	}
	else if (enum_Modes==LEFT_BLINK)
	{
		MODE_vidLeftBlink();
	}
	else if(enum_Modes==HAZZARD_BLINK)
	{
		MODE_vidHazardBlink();
	}

};



/**********************************************************************************************/
