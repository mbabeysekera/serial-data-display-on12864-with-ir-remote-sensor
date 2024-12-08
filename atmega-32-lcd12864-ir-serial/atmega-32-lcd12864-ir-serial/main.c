/*
 * main.c
 *
 * Created: 12/8/2024 3:27:16 PM
 *  Author: Buddhika
 */ 
#define F_CPU			16000000UL
#define DEBUG_LED		PIND7

#include <xc.h>
#include <util/delay.h>
#include "hardware/debug/debug_led.h"
#include "hardware/lcd_12864/lcd_12864.h"

int main(void)
{
	initDebugLED();
	_delay_ms(100);
	initLCD128X64();
    while(1)
    {
		heartbeat();
    }
}