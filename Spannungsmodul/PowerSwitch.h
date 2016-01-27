#ifndef POWERSWITCH_H_INCLUDED
#define VOLTAGECHECK_H_INCLUDED


/* 
 * Turn on power by setting MOSFET high and send impulse to relais
 *
 */
void switchOn (void);

/*
 * Turn off power by setting MOSFET low and send impulse to relais
 *
 */
 void switchOff (void);
 
 /*
  * return 1 if power is on, 0 if power is off
  */
 uint8_t isOn (void);
 #endif