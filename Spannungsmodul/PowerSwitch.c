#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#define TRUE 1
#define FALSE 0

uint8_t isStarted = FALSE;

void switchOn (void){
	// blink 2 seconds
	for (uint8_t i = 0; i< 5 ; i++ ){
		PORTB |= (1<<PB4); //Invert PB4
		_delay_ms(100);
		PORTB &= ~(1 << PB4);
		_delay_ms(100);
		PORTB |= (1<<PB4); 
		_delay_ms(400);
		PORTB &= ~(1 << PB4);
		_delay_ms(100);
	}
	isStarted = TRUE;
	PORTB |= (1<<PB1);
	PORTB |= (1<<PB0);
	_delay_ms(500);
	PORTB &= ~(1<<PB1);
}

void switchOff (void){
	isStarted = FALSE;
	PORTB |= (1<<PB2);
	PORTB &= ~(1<<PB0);
	_delay_ms(500);
	PORTB &= ~(1<<PB2);
	
}

uint8_t isOn (void){
	return isStarted;
}