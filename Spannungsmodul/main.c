/*
 * Spannungsmodul.c
 *
 * Created: 16.01.2016 22:09:29
 * Author : Oliver
 */ 

#include <avr/io.h> 
#define F_CPU 1000000UL //1 MHz

#include <util/delay.h>
#include <stdint.h>

	//uint8_t bPortD;
	//bPortD = PINB5;
  
  
  
/* ADC initialisieren */
void ADC_Init(void)
{
  
  ADMUX =
  (0 << ADLAR) |     // do not left shift result (for 10-bit values)  
  (0 << REFS1) |     // Sets ref. voltage to VCC, bit 1
  (0 << REFS0) |     // Sets ref. voltage to VCC, bit 0
  (0 << MUX3)  |     // use ADC1 for input (PB3), MUX bit 3
  (0 << MUX2)  |     // use ADC1 for input (PB3), MUX bit 2
  (1 << MUX1)  |     // use ADC1 for input (PB3), MUX bit 1
  (1 << MUX0);       // use ADC1 for input (PB3), MUX bit 0

  ADCSRA =
  (1 << ADEN)  |     // Enable ADC
  (1 << ADPS2) |     // set prescaler to 128, bit 2
  (1 << ADPS1) |     // set prescaler to 128, bit 1
  (1 << ADPS0);      // set prescaler to 128, bit 0
 
  ADCSRA |= (1<<ADSC);                  // eine ADC-Wandlung 
  while (ADCSRA & (1<<ADSC) ) {         // auf Abschluss der Konvertierung warten
  }
  /* ADCW muss einmal gelesen werden, sonst wird Ergebnis der nächsten
     Wandlung nicht übernommen. */
  (void) ADCW;
}

/* ADC Einzelmessung */
uint16_t ADC_Read()
{
	
	uint8_t adc_lobyte; // to hold the low byte of the ADC register (ADCL)
	uint16_t raw_adc;
	
	ADCSRA |= (1 << ADSC);         // start ADC measurement
	while (ADCSRA & (1 << ADSC) ); // wait till conversion complete

	// for 10-bit resolution:
	adc_lobyte = ADCL; // get the sample value from ADCL
	raw_adc = ADCH<<8 | adc_lobyte;   // add lobyte and hibyte

	return raw_adc;                    // ADC auslesen und zurückgeben
}

/* ADC Mehrfachmessung mit Mittelwertbbildung */
/* beachte: Wertebereich der Summenvariablen */
uint16_t ADC_Read_Avg( uint8_t nsamples )
{
	uint32_t sum = 0;
	
	for (uint8_t i = 0; i < nsamples; ++i ) {
		sum += ADC_Read( );
	}
	
	return (uint16_t)( sum / nsamples );
}


int main(void)
{
    
	DDRB = 0b00010110;
	//DDRB &= ~(1 << DDB3);
	int minus = 1;
 
    uint16_t adcval;
    ADC_Init();
 
 while( 1 ) {
	 //adcval = ADC_Read();  // Kanal 0
	 // mach was mit adcval
	 
	 adcval = ADC_Read_Avg(20);  // Mittelwert aus 4 Messungen
	 // mach was mit adcval
 		
	  for (int i = 0; i < (adcval / 100); i++){
		PORTB=(0x00);
		_delay_ms(300);
		   
	    PORTB |= (1<<PB4);
			
		   _delay_ms(300); 
	  }
		
		_delay_ms(3000); 
		PORTB=(0x00);
		 
		 if (minus == 0){
			 minus = 1;
			 PORTB &= ~(1<<PB1);
			 PORTB |= (1<<PB2);
			 } else {
			 minus = 0;
			 PORTB |= (1<<PB1);
			 PORTB &= ~(1<<PB2);
		 }
    }
}

