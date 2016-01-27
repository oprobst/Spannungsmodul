/*
 * Spannungsmodul.c
 *
 * Created: 16.01.2016 22:09:29
 * Author : Oliver
 */ 

#include <avr/io.h> 
#include <avr/sleep.h>

#include "VoltageCheck.h"
#include "StartupTimer.h"
#include "PowerSwitch.h"

#define F_CPU 1000000UL //1 MHz

#define TRUE 1
#define FALSE 0

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
   
    initADC(670);
	PORTB |= (1<<PB4);
	sei();
	
    //deleteme:
   //  int minus = 1;
    	
 while( 1 ) {
	 
	 //check if minimum shutdown voltage reached and pwr down.
	 checkForShutdown ();
	 
	 checkForButton();
	 	 
	/*	 
	  for (int i = 0; i < (adcval / 100); i++){
		PORTB=(0x00);
		_delay_ms(300);
		   
	    PORTB |= (1<<PB4);
			
		   _delay_ms(300); 
	  }
		
		_delay_ms(3000); 
		PORTB=(0x00);
		 
		 if (minus == 0){
			 minus = 1;
			 PORTB &= ~(1<<PB1);
			 PORTB |= (1<<PB2);
			 } else {
			 minus = 0;
			 PORTB |= (1<<PB1);
			 PORTB &= ~(1<<PB2);
		 }*/
    }
}

void checkForButton (void){
	
	
}

void checkForShutdown (void){
	 if (shutdownVoltageReached()){  	 	   
	   while (1){	     
		 // wait 10 sec and then turn off.
		 for (uint8_t i = 0; i< 100 ; i++ ){
			 _delay_ms(100);
			 PINB |= (1<<PB4); //Invert PB4           
		 }
		  
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
	 }
}

