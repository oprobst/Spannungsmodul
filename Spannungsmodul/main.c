
#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

#include "VoltageCheck.h"
#include "StartupTimer.h"
#include "PowerSwitch.h"
#include "Stopwatch.h"

#define F_CPU 1000000UL //1 MHz

#define SEC_TILL_ON 10

#define ADC_TRESHOLD 660

#define TRUE 1
#define FALSE 0

int main(void)
{
	
	//out:
	//PB1,PB2 -> Relais
	//PB4 LED
	//PB0 MOSFET
	//in:
	//PB3 ADC for voltage measurement
	DDRB |= ((0 << PB1) |(1 << PB2) |(0 << PB3) |(1 << PB4) | (1 << PB0));
	
	initADC(ADC_TRESHOLD);
	PORTB &= ~(1 << PB2);
	PORTB &= ~(1 << PB0);
	
	PORTB |= (1<<PB4);
	_delay_ms(200);
	PORTB &= ~(1<<PB4);
	_delay_ms(200);
	PORTB |= (1<<PB4);
	_delay_ms(200);
	PORTB &= ~(1<<PB4);
	
	start();
	sei();
	startStopwatch();

	while( 1 ) {
		
		checkForShutdown ();
		
		checkForButton();
		
		if (getSecondsSinceStart() > SEC_TILL_ON){
			if (isOn() == FALSE ){
				checkIfTimeIsOver();
				if ((getSecondsSinceStart() % 15) == 0){
					visualizeTimer(PB4);
				}
			} else {
				sleep ();
			}
		}
		
	}
}

void sleep (){
	int8_t i;
	for (i = 0; i < 100; i++){
		checkForButton();
		_delay_ms(100); // 10 sec
		// an interrupt would be more useful here... But anyway, it works.
	}
	visualizeVoltage(PB4);
}

/*
* Check if voltage divider is bridged by switch.
* If longer than 1 sec. pushed, call longButtonPush method, shortButtonPush otherwise.
*/
void checkForButton (void){
	if (readADCsamples(1) > 1000){
		uint8_t i;
		for ( i = 0; i < 10; i++){
			_delay_ms(100);
			if (readADCsamples(3) <= 1000){
				shortButtonPush();
				return;
			}
		}
		longButtonPush();
	}
}

void longButtonPush (){
	
	if (isOn()){
		//reset
		wdt_enable(WDTO_15MS);
		for(;;) {}
		} else {
		addBigTimer ();
		visualizeTimer(PB4);
		startStopwatch();
	}
}

void shortButtonPush (){
	
	if (isOn()){
		//shutdown
		startStopwatch();
		resetTimer();
		switchOff();
		
		} else {
		
		addSmallTimer ();
		visualizeTimer(PB4);
		startStopwatch();
	}
}

// Shutdown
void checkForShutdown (void){
	
	if (shutdownVoltageReached()){
		cli(); //disable interrupts
		for (uint8_t i = 0; i< 100; i++){
			_delay_ms(35);
			PINB |= (1<<PB4); //Invert PB4
		}		
		switchOff();
		// Go to sleep and only wake up on reset/power switch.		
		PORTB &= ~(1<<PB4); // LED off
		set_sleep_mode(SLEEP_MODE_PWR_DOWN);
		sleep_enable();
		sleep_cpu();
		sleep_disable();
		//here everything should be silent. If we reach the next while loop, something is wrong.
		while (1){
			_delay_ms(1500);
			PINB |= (1<<PB4); //Invert PB4
		}
	}
}
	
