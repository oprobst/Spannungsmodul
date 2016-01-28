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

#include <util/delay.h>
#include <stdint.h> 
#include <avr/interrupt.h>

uint8_t isRunning = FALSE;

int main(void)
{
    //out:
	//PB1,PB2 -> Relais
    //PB4 LED
	//PB0 MOSFET
	 //in: 
	//PB3 ADC for voltage measurement
    DDRB |= ((1 << PB1) |(1 << PB2) |(0 << PB3) |(1 << PB4) | (1 << PB0));
   
    initADC(670);
	PORTB |= (1<<PB4);
	sei();	
	
	resetStopwatch();
	startStopwatch();
    	
 while( 1 ) {
	 
	 //check if minimum shutdown voltage reached and pwr down.
	 checkForShutdown ();
	 
	 checkForButton();	 	

	  if (! isRunning && getStopwatchMillis()>10000)){
		  //No new input since 10 sec. Start timer
		  start ();
		  isRunning = true;
		  stopStopwatch();
	  } else if (!isRunning){
		 _delay_ms(100); 
	  }
	  else {
		sleep ();  
	  }	    
    }
}

void sleep (){
	for (int8_t = 0; i < 250; i++){
	  checkForButton();
	  _delay_ms(120);
	  // an interrupt would be more useful here... But anyway, it works.
	}
	
	//Short flash every half minute
	PORTB |= (1<<PB4);      
	_delay_ms(120);
	PORTB |= (0<<PB4);     
}

/*
 * Check if voltage divider is bridged by switch.
 * If longer than 1 sec. pushed, call longButtonPush method, shortButtonPush otherwise.
 */
void checkForButton (void){
	if (readADCsamples(3) > 1000){
     	for (uint8_t i = 0; i < 10; i++){
			_delay_ms(100);
 		     if (readADCsamples(3) < 1000){
				 shortButtonPush();
				 return;
			 }
	    } 
		longButtonPush();
	}
}

void longButtonPush (){
	
	if (isRunning){
		//reset
		 wdt_enable(WDTO_15MS);  
        for(;;) {}    
	} else {
		add1Hour ();
		visualizeTimer(PB3);
		resetStopWatch();
	}
}

void shortButtonPush (){
	
	if (isRunning){
		//shutdown
		for (uint8_t i = 0; i< 100 ; i++ ){
			 _delay_ms(100);
			 PINB |= (1<<PB4); //Invert PB4           
		 }
		turnMeOff ();
	} else {
		add5Minutes ();
		visualizeTimer(PB3);
		resetStopWatch();
	}
}

void checkForShutdown (void){
	 if (shutdownVoltageReached()){  	 	   
	   while (1){	     
	      isRunning = FALSE;
		 // wait 10 sec and then turn off.
		 for (uint8_t i = 0; i< 100 ; i++ ){
			 _delay_ms(100);
			 PINB |= (1<<PB4); //Invert PB4           
		 }
		  
	     turnMeOff();
	   }
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
		    _delay_ms(1000); 
		    PINB |= (1<<PB4); //Invert PB4          
	     }
}
