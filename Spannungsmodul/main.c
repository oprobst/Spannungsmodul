/*
 * Spannungsmodul.c
 *
 * Created: 16.01.2016 22:09:29
 * Author : Oliver
 */ 

#include <avr/io.h> 
#define F_CPU 1000000UL //1 MHz

#include <util/delay.h>
#include <stdint.h>

	//uint8_t bPortD;
	//bPortD = PINB5;

int main(void)
{
    
	DDRB = 0b00010110;
	//DDRB &= ~(1 << DDB3);
	int minus = 1;
    while (1) 
    {
		PORTB=(0x00);		  
		
		_delay_ms(2000);
	
	    PORTB |= (1<<PB4);
		if (minus == 0){
			minus = 1;
			PORTB &= ~(1<<PB1);
			PORTB |= (1<<PB2);
		} else {
			minus = 0;
			PORTB |= (1<<PB1);
			PORTB &= ~(1<<PB2);
		}			
		 _delay_ms(3000); 
		 
		 
    }
}

