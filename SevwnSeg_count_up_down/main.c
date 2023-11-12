#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "SSD_interface.h"
#include "DIO_interface.h"


SSD_Type SSD ={SSD_COMMON_CATHODE,SSD_PORTD,SSD_PORTD,SSD_PIN0};
void main ()
{
	SSD_voidInitialDataPort(SSD);
	SSD_voidEnable(SSD);
	while (1)
	{
		int i;
		for (i=0;i<10;i++)
		{
			SSD_voidSendNumber(SSD,i);
			_delay_ms(500);
		}
for (i=9;i>=0;i--)
{
	SSD_voidSendNumber(SSD,i);
	_delay_ms(500);
}

	}

}

