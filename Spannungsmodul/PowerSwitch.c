#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#define TRUE 1
#define FALSE 0

uint8_t isStarted = FALSE;
#define TIME_TO_SIGNAL_START 2 // x2 sec
#define TIME_TO_SIGNAL_STOP 2 // x2 sec
#define RELAY_SWITCH_TIME 250 //ms
#define RELAY_SWITCH_RETRY 1 //times



void switchOn (void){
	// blink 2 seconds
	for (uint8_t i = 0; i< TIME_TO_SIGNAL_START ; i++ ){
		PORTB |= (1<<PB4); //Invert PB4
		_delay_ms(300);
		PORTB &= ~(1 << PB4);
		_delay_ms(300);
		PORTB |= (1<<PB4); 
		_delay_ms(800);
		PORTB &= ~(1 << PB4);
		_delay_ms(600);
	}
	isStarted = TRUE;
	PORTB |= (1<<PB0);
	for (int8_t i = 0; i< RELAY_SWITCH_RETRY;i++){
	PORTB |= (1<<PB1);
	_delay_ms(RELAY_SWITCH_TIME);
	PORTB &= ~(1<<PB1);
	_delay_ms(RELAY_SWITCH_TIME);
	}
}

void switchOff (void){
	// blink delay
	isStarted = FALSE;	
	for (uint8_t i = 0; i < TIME_TO_SIGNAL_STOP; i++ ){
			PORTB |= (1<<PB4); 
			_delay_ms(800);
			PORTB &= ~(1 << PB4);
			_delay_ms(300);
			PORTB |= (1<<PB4);
			_delay_ms(300);
			PORTB &= ~(1 << PB4);
			_delay_ms(600);
	}
	
	 
	PORTB &= ~(1<<PB0);
	for (int8_t i = 0; i < RELAY_SWITCH_RETRY; i++){
		PORTB |= (1<<PB2);
		_delay_ms(RELAY_SWITCH_TIME);
		PORTB &= ~(1<<PB2);
		_delay_ms(RELAY_SWITCH_TIME);
	}
}

uint8_t isOn (void){
	return isStarted;
}