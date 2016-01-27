#ifndef STARTUPTIMER_H_INCLUDED
#define STARTUPTIMER_H_INCLUDED



/*
 * Start time measurement
 * param port: If not null, output will provided by a high/low frequenz of 2Hz for 3 sec when starting
 */
void start (int8_t port);

/*
 * Increase timer by 5 minutes
 */
void add5Minutes (void);

/*
 * Increase timer by an hour
 */
void add1Hour (void);

/*
 * Send signal code to port showing current timer
 * param port: Will show combination of long and short HIGH signals to show current timer state.
 */
void visualizeTimer (int8_t port);
#endif