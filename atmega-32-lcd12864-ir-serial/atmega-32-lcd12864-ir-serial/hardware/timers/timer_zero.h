/*
 * timer_zero.h
 *
 * Created: 12/19/2024 9:36:40 AM
 *  Author: Buddhika
 */ 


#ifndef TIMER_ZERO_H_
#define TIMER_ZERO_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/interrupt.h>

volatile unsigned long ticks = 0L;

ISR(TIMER0_COMP_vect) {
	ticks++; // tick must be incremented every 4us. so 1 tick = 4us
}

void initTimerZero() {
	cli();
	TCCR0 = 0;
	TCCR0 |= (1 << WGM01); // No prescaler and enable CTC
	TCNT0 = 0;
	OCR0 = 31;
	TIMSK |= (1 << OCIE0);
	TIFR |= (1 << OCF0);
	sei();
}

void startTimerZero() {
	TCCR0 |= (1 << CS00);
	TCNT0 = 0;
}

void stopTimerZero() {
	TCCR0 &= ~(1 << CS00);
}

unsigned long micros() {
	return ticks * 4L;
}

void delayMicroseconds(unsigned long delay) {
	unsigned long initTime = micros();
	unsigned long diff = 0;
	while(!(diff > delay)) {
		diff = micros() - initTime;
		if (diff < 0)
		{
			diff = (4294967295 - initTime) + diff;
		}
	}
}


#endif /* TIMER_ZERO_H_ */