
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h> 

uint16_t millisec = 0;

uint8_t measure = 0;


/*
 * Start stopwatch
 */
void startStopWatch (){

     TCCR1A = (1<<WGM01); // CTC Modus
     TCCR1B |= (1<<CS01); // Prescaler 8
     // ((1000000/8)/1000) = 125
     OCR1A = 125-1;
	 // Compare Interrupt
      TIMSK |= (1<<OCIE1A);
	  measure = 1;
	  
}

/*
 * stop stopwatch
 */
void stopStopwatch (){
    measure = 0;
}

/*
 * Reset millis to 0
 */
void resetStopwatch (){
  millisec = 0;
}

/*
 * get milliseconds since calling start();
 */
uint8_t getStopwatchMillis (void){
  return millisec;
}

ISR (TIMER1_COMPA_vect)
{
	if (measure){
        millisekunden++;   
	}
}