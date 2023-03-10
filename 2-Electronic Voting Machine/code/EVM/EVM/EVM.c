/**
* About: implement an electronic voting machine using lcd and buttons
* Author: Azza Saeed
* Created: 2/3/2023
**/
#include <avr/io.h>
#include "button.h"
#include "LCD.h"
#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>

unsigned char counterA=0; /* counter for button A */
unsigned char counterB=0; /* counter for button B */
unsigned char counterC=0; /* counter for button C */
unsigned char counterD=0; /* counter for button D */

int main(void)
{
	LCD_vInit(); /* initialize lcd */
	
	/* initialize button with port B pins */
	button_vInit('B',3);
	button_vInit('B',4);
	button_vInit('B',5);
	button_vInit('B',6);
	button_vInit('B',7);
	
   /* Display string with the value of each button on lcd */
    LCD_movecursor(1,1);
	LCD_vSend_string("A=0");
	LCD_movecursor(1,10);
	LCD_vSend_string("B=0");
	LCD_movecursor(2,1);
	LCD_vSend_string("C=0");
	LCD_movecursor(2,10);
	LCD_vSend_string("D=0");	
	
    while(1)
    {
		if(button_u8read('B',3)==1)
		{
			counterA++;
			if(counterA<10)
			{
				LCD_movecursor(1,3); /* move cursor to row 1 col 3 */
				LCD_vSend_char(counterA+48); /* send asci code of the counterA to lcd */
			}	
			else if(counterA<100)
			{
				LCD_movecursor(1,3); /* move cursor to row 1 col 3 */
				LCD_vSend_char((counterA/10)+48); /* send asci code of the counterA to lcd */
				LCD_movecursor(1,4);
				LCD_vSend_char((counterA%10)+48); 								
			}
			else if(counterA<1000)
			{
				LCD_movecursor(1,3); /* move cursor to row 1 col 3 */
				LCD_vSend_char((counterA/100)+48); /* send asci code of the counterA to lcd */
				LCD_movecursor(1,4);
				LCD_vSend_char(((counterA/10)%10)+48);
				LCD_movecursor(1,5); 
				LCD_vSend_char((counterA%10)+48);								
			}		
			
		}
		else if(button_u8read('B',4)==1)
		{
			counterB++;
			if(counterB<10)
			{
				LCD_movecursor(1,12); /* move cursor to row 1 col 12 */
				LCD_vSend_char(counterB+48); /* send asci code of the counterB to lcd */
			}
			else if(counterB<100)
			{
				LCD_movecursor(1,12); /* move cursor to row 1 col 12 */
				LCD_vSend_char((counterB/10)+48); /* send asci code of the counterB to lcd */
				LCD_movecursor(1,13);
				LCD_vSend_char((counterB%10)+48);
			}
			else if(counterB<1000)
			{
				LCD_movecursor(1,12); /* move cursor to row 1 col 12 */
				LCD_vSend_char((counterB/100)+48); /* send asci code of the counterB to lcd */
				LCD_movecursor(1,13);
				LCD_vSend_char(((counterB/10)%10)+48);
				LCD_movecursor(1,14);
				LCD_vSend_char((counterB%10)+48);
			}
						
			
		}
		else if(button_u8read('B',5)==1)
		{
			counterC++;
			if(counterC<10)
			{
				LCD_movecursor(2,3); /* move cursor to row 2 col 3 */
				LCD_vSend_char(counterC+48); /* send asci code of the counterC to lcd */
			}
			else if(counterC<100)
			{
				LCD_movecursor(2,3); /* move cursor to row 2 col 3 */
				LCD_vSend_char((counterC/10)+48); /* send asci code of the counterC to lcd */
				LCD_movecursor(2,4);
				LCD_vSend_char((counterC%10)+48);
			}
			else if(counterC<1000)
			{
				LCD_movecursor(2,3); /* move cursor to row 2 col 3 */
				LCD_vSend_char((counterC/100)+48); /* send asci code of the counterC to lcd */
				LCD_movecursor(2,4);
				LCD_vSend_char(((counterC/10)%10)+48);
				LCD_movecursor(2,5);
				LCD_vSend_char((counterC%10)+48);
			}
						
		}
		else if(button_u8read('B',6))
		{
			counterD++;
			if(counterD<10)
			{
				LCD_movecursor(2,12); /* move cursor to row 2 col 12 */
				LCD_vSend_char(counterD+48); /* send asci code of the counterC to lcd */
			}
			else if(counterD<100)
			{
				LCD_movecursor(2,12); /* move cursor to row 2 col 12 */
				LCD_vSend_char((counterD/10)+48); /* send asci code of the counterD to lcd */
				LCD_movecursor(2,13);
				LCD_vSend_char((counterD%10)+48);
			}
			else if(counterD<1000)
			{
				LCD_movecursor(2,12); /* move cursor to row 2 col 12 */
				LCD_vSend_char((counterD/100)+48); /* send asci code of the counterD to lcd */
				LCD_movecursor(2,13);
				LCD_vSend_char(((counterD/10)%10)+48);
				LCD_movecursor(2,14);
				LCD_vSend_char((counterD%10)+48);			
		}
		}		
		else if(button_u8read('B',7)==1)
		{
			counterA=counterB=counterC=counterD=0;
            LCD_movecursor(1,1);
            LCD_vSend_string("A=0");
            LCD_movecursor(1,10);
            LCD_vSend_string("B=0");
            LCD_movecursor(2,1);
            LCD_vSend_string("C=0");
            LCD_movecursor(2,10);
            LCD_vSend_string("D=0");
		}
		_delay_ms(250);
	}
	   
  }
		

