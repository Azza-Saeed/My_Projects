/*
 * multiplexing_using_7seg__0_to_20_.c
 *
 * Created: 9/26/2019 10:16:23 PM
 *  Author: Mohamed Zaghlol
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "seven segment.h"
#include "std_macros.h"

volatile unsigned char counter1=0;
unsigned char counter2=0;
volatile unsigned char counter3=0;

int main(void)
{
	seven_seg_vinit('D');
	timer_CTC_init_interrupt();
	CLR_BIT(DDRA,0);
	SET_BIT(DDRA,1);
	seven_seg_write('D',counter2%10);
	while( counter3==0 ) // switch between two 7seg every 10msec
	counter3=0;
	CLR_BIT(DDRA,1);
	SET_BIT(DDRA,0);
	seven_seg_write('D',counter2/10);
	while( counter3==0 )
	counter3=0;
	   if( counter1>=100 )
	   {
		   counter1=0;
		   counter2++;
		   if( counter2==21 )
		   {
			  counter2=0; 
	       }
	   }		   
	
	
	
}
ISR(TIMER0_COMP_vect)
{
	counter1++; // indication that sec left
	counter3=1; // indication that 10msec left
	
}