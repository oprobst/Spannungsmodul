#include "VoltageCheck.h"

uint16_t shutdownTresholdVoltage = 0;

void initADC (uint16_t shutDownTreshold) { 

  shutdownTresholdVoltage = shutDownTreshold;
  // ADC Configuration: Mux only for PB3, RefVoltage = Vcc, no left shift for 10bit accuracy.
  ADMUX =
  (0 << ADLAR) |     
  (0 << REFS1) |    
  (0 << REFS0) |    
  (0 << MUX3)  |    
  (0 << MUX2)  |    
  (1 << MUX1)  |    
  (1 << MUX0);      

  //ADC enabled, prescaler to 128 bit
  ADCSRA =
  (1 << ADEN)  |   
  (1 << ADPS2) |   
  (1 << ADPS1) |  
  (1 << ADPS0);   
 
  //do one read
  ADCSRA |= (1<<ADSC);                  
  while (ADCSRA & (1<<ADSC) ) {         
  }
  (void) ADCW;
}

/* 
 * Do a single ADC read
 */
uint16_t readADC(void)
{
	
	uint8_t adc_lobyte; // to hold the low byte of the ADC register (ADCL)
	uint16_t raw_adc;
	
	ADCSRA |= (1 << ADSC);         // start ADC measurement
	while (ADCSRA & (1 << ADSC) ); // wait till conversion complete

	// for 10-bit resolution:
	adc_lobyte = ADCL; // get the sample value from ADCL
	raw_adc = ADCH<<8 | adc_lobyte;   // add lobyte and hibyte

	return raw_adc;                    
}


/*
 * Do a few samples and return average.
 *
 * param nsamples Sample count
 */
uint16_t readADCsamples( uint8_t nsamples )
{
	uint32_t sum = 0;
	
	for (uint8_t i = 0; i < nsamples; ++i ) {
		sum += readADC( );
	}
	
	return (uint16_t)( sum / nsamples );
}
 
uint16_t getVoltage (void){
	return readADCsamples (50);
}

uint8_t shutdownVoltageReached(void){
	return (getVoltage () < shutdownTresholdVoltage);
}




