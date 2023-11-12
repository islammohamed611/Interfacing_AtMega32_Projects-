

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "SSD_interface.h"
#include "DIO_interface.h"


SSD_Type SSD1 ={SSD_COMMON_CATHODE,SSD_PORTD,SSD_PORTD,SSD_PIN7};
SSD_Type SSD2 ={SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN7};

void main()
{
	SSD_voidInitialDataPort(SSD1);
	SSD_voidInitialDataPort(SSD2);

	SSD_voidEnable(SSD1);
	SSD_voidEnable(SSD2);

	u8 i ,j;
	while (1)

	{

		/*for(i=0;i<10;i++)
		{
			SSD_voidSendNumber(SSD1,i);
			_delay_ms(250);
		}*/
		for(i=0;i<10;i++)
		{
			SSD_voidSendNumber(SSD1,i);
			_delay_ms(250);
			for (j=0;j<10;j++)
			{
				SSD_voidSendNumber(SSD2,j);
				_delay_ms(250);
				if(j==9)
				{
					SSD_voidSendNumber(SSD2,0);
				}
				//SSD_voidDisable(SSD2);
			}


		}


	}

}
