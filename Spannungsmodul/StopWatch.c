
#include <stdint.h>
#include <avr/interrupt.h>
uint32_t millisRef = 0;

/*
* Start stopwatch
*/
void startStopwatch (){
	millisRef = getMillisSinceStartup();
}


/*
* get milliseconds since calling start();
*/
uint32_t getStopwatchMillis (void){
	return getMillisSinceStartup() - millisRef;
}