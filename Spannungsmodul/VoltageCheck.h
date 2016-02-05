#ifndef VOLTAGECHECK_H_INCLUDED
#define VOLTAGECHECK_H_INCLUDED
#include <avr/interrupt.h>
#include <stdint.h> 


/* 
 * Init the ADC by setting correct register
 *
 */
void initADC (uint16_t);


/*
 * Return Voltage as 10bit value 0-vcc
 */
uint16_t getVoltage (void);

/*
 * Return 1 if voltage is below shutdown voltage.
 */
uint8_t shutdownVoltageReached(void);

/*
 * Send signal code to port showing current voltage
 * param port: Will show combination of long and short HIGH signals to show current voltage state.
 */
void visualizeVoltage (int8_t port);

#endif
