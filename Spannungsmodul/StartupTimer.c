
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h> 
 
//Variablen für die Zeit
uint16_t millisekunden;
uint8_t sekunde;
uint8_t minute;
uint8_t stunde;

uint8_t minuteBlocks = 0;
uint8_t hours = 0;

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
 millisekunden++;
  if(millisekunden == 1000)
  {
    sekunde++;
    millisekunden = 0;
    if(sekunde == 60)
    {
      minute++;
      sekunde = 0;
    }
    if(minute == 60)
    {
      stunde++;
      minute = 0;
    }
    if(stunde == 24)
    {
      stunde = 0;
    }
  }
  checkIfTimeIsOver();
}


void checkIfTimeIsOver(){
	if (stunde*60+minute > hours*60+minuteBlocks*5){
		TCCR0B |= (1<<CS00);
		TCCR0B |= (1<<CS01);
		TCCR0B |= (1<<CS01);
		switchOn();
	}
}

void add5Minutes (void){
    minuteBlocks++;	
	if (minuteBlocks >=12){
		minuteBlocks -= 12;
		add1Hour();
	}
}
 
void add1Hour (void){
	hours++;
	if (hours > 24){
		hours = 0;
	}
}
 
void visualizeTimer (int8_t port){
	 PORTB |= (0<<PB4); //Set PB4 off
	 for (uint8_t i = 0; i< hours *2; i++]){
			 _delay_ms(1000);
			 PINB |= (1<<PB4); //Invert PB4           
		
	}
	for (uint8_t i = 0; i< minuteBlocks *2; i++]){
			 _delay_ms(300);
			 PINB |= (1<<PB4); //Invert PB4           
		
	}
}
