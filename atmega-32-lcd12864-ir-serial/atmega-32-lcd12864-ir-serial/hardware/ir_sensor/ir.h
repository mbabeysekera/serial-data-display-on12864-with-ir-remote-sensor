/*
* ir.h
*
* Created: 12/19/2024 9:33:15 AM
*  Author: Buddhika
*/


#ifndef IR_H_
#define IR_H_

#define ICP1			PIND6

#include <avr/interrupt.h>

volatile uint32_t irReceiveData = 0; // 32 bit value
volatile uint8_t counter = 0;
volatile uint8_t isIRAvailable = 0;

ISR(TIMER1_CAPT_vect) {
	if (counter)
	{
		if (ICR1 > 120)
		{
			irReceiveData |= 0x00000001;
		}
		irReceiveData = (irReceiveData << 1);
		if (counter == 29)
		{
			isIRAvailable = 1;
			counter = 0;
		} else {
			counter++;
		}
	} else {
		irReceiveData = 0;
		counter++;
	}
	TCNT1 = 0;
}

uint32_t getIRReceiveData() {
	isIRAvailable = 0;
	return irReceiveData;
}

void initIRSensor() {
	cli();
	PORTD |= (1 << ICP1);
	DDRD &= ~(1 << ICP1);
	
	TCCR1A = 0; // Normal mode counting
	TCCR1B = 0b00000100; // Falling edge trigger the event
	TIMSK |= (1 << TICIE1);
	
	sei();
}



#endif /* IR_H_ */