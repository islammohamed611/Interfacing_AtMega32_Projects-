#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SW_interface.h"
#include "util/delay.h"



SSD_Type SSD ={SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN7};
SW_Type  SW  ={DIO_PORTA,DIO_PIN7, SW_Ext_PULL_UP};

void main()
{

	//u8 Loc_u8_State;
	SSD_voidInitialDataPort(SSD);
	SW_voidInit(SW);
	u8 i=0;// always make u8 variable outside while and do not make int never
	while (1)
	{

		//u8 Loc_u8_State = SW_u8GetPressed(SW);
		if ( SW_u8GetPressed(SW))
		{

			SSD_voidSendNumber(SSD,i);
			_delay_ms(500); // cause my press may make him count more than one (pooling)so we made dely that is bad best case  is interrrupt

			i++;
		}
		if (i==10)
		{
			i=0;
		}
	}





}


