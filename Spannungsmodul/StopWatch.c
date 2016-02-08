
#include <stdint.h>
#include <avr/interrupt.h>
uint32_t millisRef = 0;

/*
* Start stopwatch
*/
void startStopwatch (){
	millisRef = getSecondsSinceStart();
}


/*
* get milliseconds since calling start();
*/
uint32_t getStopwatchSeconds (void){
	return getSecondsSinceStart() - millisRef;
}