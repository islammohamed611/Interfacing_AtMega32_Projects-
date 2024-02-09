/*
 * APP_program.c

 *
 *  Created on: 12 Oct 2022
 *      Author: Mahmoud Karem
 */

#include <util/delay.h>

/*LIB includes */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
/*MCAL includes */
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EEPROM/EEPROM_driver.h"
/*HAL includes */
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SW_interface.h"
#include "../HAL/SSD/SSD_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/KPD/KPD_interface.h"
/*APP includes */
#include "APP_interface.h"

/**************************************************************************/

/* SSD & KPD Variables */

/**************************************************************************/

/* EEPROM Locations */
#define EEPROM_STATUS_LOCATION    0x20
#define EEPROM_PASSWORD_LOCATION1 0x21
#define EEPROM_PASSWORD_LOCATION2 0x22
#define EEPROM_PASSWORD_LOCATION3 0x23
#define EEPROM_PASSWORD_LOCATION4 0x24

#define MAX_TRIES 3

/* Needed Global Variables */

/**************************************************************************/
/*********************    Helper Functions   ******************************/
/**************************************************************************/

static void APP_voidInitPW(void)
{

}
static void APP_voidSetPW(void)
{

}

/************/
static void APP_voidEnterPW(void)
{

}

/**************************************************************************/
/**************************************************************************/
/**************************************************************************/


/*All application logic*/
void APP_voidAppLoop (void)
{

}

/*all Initials I need */
void APP_voidInit(void)
{

}


/**************************************************************************/
