/*
 * temperature_sensor_using_lcd.c
 *
 * Created: 8/3/2023
 *  Author: Azza Saeed
 */  


#include <avr/io.h>
#include "ADC_driver.h"
#include "LCD.h"
char read_val;
unsigned short temperature;
int main(void)
{
	LCD_vInit();
	ADC_vinit();
	 LCD_vSend_string("temperature=");
    while(1)
    {
		temperature= (ADC_u16Read()*0.25);
		if( temperature<10 )
		{
			LCD_movecursor(1,13);
			LCD_vSend_char(0x30);
			LCD_vSend_char((temperature%10)+48);
			LCD_vSend_char(0xDF);
			LCD_vSend_char('c');
		}
		else if( temperature<100)
		{
			LCD_movecursor(1,13);
			LCD_vSend_char((temperature/10)+48);
			LCD_vSend_char((temperature%10)+48);
			LCD_vSend_char(0xDF);
			LCD_vSend_char('c');
		}
		else
		{
			
		}
		
       
    }
}