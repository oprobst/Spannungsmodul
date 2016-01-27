#include <stdint.h> 
#define TRUE 1
#define FALSE 0

uint8_t isStarted = FALSE;

void switchOn (void){
  isStarted = TRUE;	
}

 void switchOff (void){
	 isStarted = FALSE;
 }
 
uint8_t isOn (void){
	return isStarted;
	
}