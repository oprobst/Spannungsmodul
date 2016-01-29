#ifndef STOPWATCH_H_INCLUDED
#define STOPWATCH_H_INCLUDED
	


/*
 * Start stopwatch
 */
void startStopWatch ();

/*
 * stop stopwatch
 */
void stopStopwatch ();

/*
 * Reset millis to 0
 */
void resetStopwatch ();

/*
 * get milliseconds since calling start();
 */
uint8_t getStopwatchMillis (void);
 
#endif