#include <stdint.h> 
#define TRUE 1
#define FALSE 0

uint8_t isStarted = FALSE;

void switchOn (void){
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