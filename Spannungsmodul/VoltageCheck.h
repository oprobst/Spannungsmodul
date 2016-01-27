#ifndef VOLTAGECHECK_H_INCLUDED
#define VOLTAGECHECK_H_INCLUDED

/* 
 * Init the ADC by setting correct register
 *
 */
void initADC (void);

/*
 * Return Voltage as 10bit value 0-vcc
 */
uint16_t getVoltage (void);

/*
 * Return 1 if voltage is below shutdown voltage.
 */
uint8_t shutdownVoltageReached(void);
#endif
