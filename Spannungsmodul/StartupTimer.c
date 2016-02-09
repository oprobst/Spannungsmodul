
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <util/delay.h>

#define SMALL_TIMER_VALUE 10
#define BIG_TIMER_VALUE 60
#define BIG_TIMER_MAX_VALUE 24

uint16_t milliseconds= 0;
uint8_t seconds= 0;
uint8_t minutes= 0;
uint8_t hours= 0;

uint32_t secondsSinceStart = 0;

uint8_t smallTimerCount = 0;
uint8_t bigTimerCount = 0;

void start (){
	
	TCCR0A = (1<<WGM01); // CTC Modus
	TCCR0B |= (1<<CS01); // Prescaler 8
	// ((1000000/8)/1000) = 125
	OCR0A = 125-1;
	// Compare Interrupt
	TIMSK |= (1<<OCIE0A);
}



ISR (TIMER0_COMPA_vect)
{
	milliseconds++;
	
	if(milliseconds == 1000)
	{
		secondsSinceStart++;
		seconds++;
		milliseconds = 0;
		if(seconds == 60)
		{
			minutes++;
			seconds = 0;
		}
		if(minutes == 60)
		{
			hours++;
			minutes = 0;
		}
		if(hours == 24)
		{
			hours = 0;
		}
	}
	
}


void checkIfTimeIsOver(){
	if (hours * 60 + minutes >= bigTimerCount * BIG_TIMER_VALUE + smallTimerCount * SMALL_TIMER_VALUE ){
		switchOn();
	}
}

void addSmallTimer (void){
	smallTimerCount++;
	if (smallTimerCount * SMALL_TIMER_VALUE >= BIG_TIMER_VALUE){
		smallTimerCount = 0;
		addBigTimer();
	}
}

void addBigTimer (void){
	bigTimerCount++;
	if (bigTimerCount > BIG_TIMER_MAX_VALUE){
		bigTimerCount = 0;
	}
}

uint32_t getSecondsSinceStart (){
	return secondsSinceStart;
}

void visualizeTimer (int8_t port){
	PORTB |= (0<<PB4); //Set PB4 off
	
	// remaining minutes = (configured Minutes) - time since startup
	uint16_t remainingMinutes =  (bigTimerCount * BIG_TIMER_VALUE + smallTimerCount * SMALL_TIMER_VALUE) - (hours * 60 + minutes) ;
	uint8_t remBigs = remainingMinutes / BIG_TIMER_VALUE;
	uint8_t remSmalls = remainingMinutes % BIG_TIMER_VALUE;
	
	for (uint8_t i = 0; i< remBigs *2; i++){
		_delay_ms(1000);
		PINB |= (1<<PB4); //Invert PB4
		
	}
	for (uint8_t i = 0; i < (remSmalls / SMALL_TIMER_VALUE) *2 ; i++){
		_delay_ms(300);
		PINB |= (1<<PB4); //Invert PB4		
	}
	_delay_ms(300);
	PINB |= (1<<PB4); 
	_delay_ms(50);
	PINB |= (1<<PB4); 
	if (remainingMinutes <= 0){
		_delay_ms(650);
	}
}
