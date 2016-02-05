#ifndef STOPWATCH_H_INCLUDED
#define STOPWATCH_H_INCLUDED
	


/*
 * Start stopwatch
 */
void startStopwatch ();

/*
 * get milliseconds since calling start();
 */
uint8_t getStopwatchMillis (void);
 
#endif