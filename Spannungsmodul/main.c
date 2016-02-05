/*
* Spannungsmodul.c
*
* Created: 16.01.2016 22:09:29
* Author : Oliver
*/

#include <avr/io.h>
#include <avr/sleep.h>

#include <avr/wdt.h>

#include "VoltageCheck.h"
#include "StartupTimer.h"
#include "PowerSwitch.h"
#include "Stopwatch.h"

#define F_CPU 1000000UL //1 MHz

#define TRUE 1
#define FALSE 0

#define ADC_TRESHOLD 1 //670

#include <util/delay.h>
#include <stdint.h>
#include <avr/interrupt.h>

int main(void)
{
	//out:
	//PB1,PB2 -> Relais
	//PB4 LED
	//PB0 MOSFET
	//in:
	//PB3 ADC for voltage measurement
	DDRB |= ((1 << PB1) |(1 << PB2) |(0 << PB3) |(1 << PB4) | (1 << PB0));
	
	initADC(ADC_TRESHOLD); 
	PORTB &= ~(1 << PB4);
	PORTB &= ~(1 << PB0); 
	
	start();
	sei();
	startStopwatch();

	while( 1 ) {
	   // blink();
		//check if minimum shutdown voltage reached and pwr down.
		checkForShutdown ();
	
		checkForButton();
		
		//_delay_ms(10);
		
		if ( isOn() == FALSE && getStopwatchMillis() > 1000){
			
			//No new input since 10 sec. Start timer
			switchOn ();
			
			} else if (isOn() == FALSE){
			
			checkIfTimeIsOver();
			} else {
			sleep ();
		}
		
		
	}
}

void sleep (){
	int8_t i;
	for (i = 0; i < 250; i++){
		checkForButton();
		_delay_ms(20); //20 = 5 sec
		// an interrupt would be more useful here... But anyway, it works.
	}
	
	//Short flash every half minute
	visualizeVoltage(PB4);	 
}

/*
* Check if voltage divider is bridged by switch.
* If longer than 1 sec. pushed, call longButtonPush method, shortButtonPush otherwise.
*/
void checkForButton (void){
	if (readADCsamples(3) > 1000){
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
		add1Hour ();
		visualizeTimer(PB4);
		startStopwatch();
	}
}

void shortButtonPush (){
	
	if (isOn()){
		//shutdown
		for (uint8_t i = 0; i< 100 ; i++ ){
			_delay_ms(100);
			PINB |= (1<<PB4); //Invert PB4
		}
		turnMeOff ();
		} else {
		
		add5Minutes ();
		visualizeTimer(PB4);
		startStopwatch();
	}
}

void checkForShutdown (void){
	if (shutdownVoltageReached()){
		
		// wait 10 sec and then turn off.
		for (uint8_t i = 0; i< 100 ; i++ ){
			_delay_ms(100);
			PINB |= (1<<PB4); //Invert PB4
		}
		
		turnMeOff();
		
	}
}

void turnMeOff(){
	switchOff();
	// Go to sleep and only wake up on reset/power switch.
	cli(); //disable interrupts
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

uint8_t blinkC = 0;
void blink(){
	blinkC += 1;
	if (blinkC == 2){
		blinkC = 0;
	    //PORTB |= (1<<PB0); 
		PORTB |= (1 << PB0); 
	    _delay_ms(300);
	} else {PORTB &= ~(1 << PB0); 
		
	}
	 
}