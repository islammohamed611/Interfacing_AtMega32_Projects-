/*
 * main.c

 *
 *  Created on: Oct 13, 2022
 *      Author: Mahmoud Karem
 */

#include "APP/APP_interface.h"

int main ()
{
	APP_voidInit();
	APP_voidAppLoop();
	while(1);
	return 0;
}
