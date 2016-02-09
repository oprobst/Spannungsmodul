#ifndef STARTUPTIMER_H_INCLUDED
#define STARTUPTIMER_H_INCLUDED



/*
 * Start time measurement
 * param port: If not null, output will provided by a high/low frequenz of 2Hz for 3 sec when starting
 */
void start ();

/*
 * Increase timer by 5 minutes
 */
void addSmallTimer (void);

/*
 * Increase timer by an hour
 */
void addBigTimer (void);

/*
 * Send signal code to port showing current timer
 * param port: Will show combination of long and short HIGH signals to show current timer state.
 */
void visualizeTimer (int8_t port);

uint32_t getSecondsSinceStart (void);
#endif