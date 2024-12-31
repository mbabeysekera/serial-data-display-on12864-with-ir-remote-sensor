/*
* debug_led.h
*
* Created: 12/8/2024 4:04:06 PM
*  Author: Buddhika
*/


#ifndef DEBUG_LED_H_
#define DEBUG_LED_H_

#ifndef DEBUG_LED
#define DEBUG_LED	PIND7
#endif
#pragma once
#include <util/delay.h>

void initDebugLED() {
	PORTD |= (1 << DEBUG_LED);
	DDRD |= (1 << DEBUG_LED);
}

void heartbeat() {
	PORTD ^= (1 << DEBUG_LED);
}
#endif /* DEBUG_LED_H_ */