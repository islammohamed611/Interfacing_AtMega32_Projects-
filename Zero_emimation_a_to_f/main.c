#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "util/delay.h"



SSD_Type SSD ={SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN7};

void main ()
{
	SSD_voidInitialDataPort(SSD);
	SSD_voidEnable(SSD);

	u8 i;
	while(1)
	{
		for (i=0;i<6;i++)
		{

			SSD_voidSendPart(SSD,i);
			_delay_ms(50);

 		}


	}
}

