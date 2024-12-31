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
#include "lcd_graphics/graphics.h"
#include "utility/itoa.h"
#include "hardware/timers/timer_zero.h"
#include "hardware/ir_sensor/ir.h"

void displayRefresh();
void notificationIconFormatter(uint8_t * iconStripRef,  const uint8_t * icon, uint8_t startingIndex, uint8_t initialShift);
void notificationIconsProcessor(uint8_t iconsToEnable);
void numberDisplayTest();

int main(void)
{
	initDebugLED();
	initLCD128X64();
	lcdClear();
	lcdGraphicsMode(); // cannot enable and disable graphic mode every time. This cause an glitches on the display
	allFrame();
	renderGraphics(citronLogo, 33, 48, 4, 2);
	lcdDrawGraphics();

	lcdNormalMode();
	lcdCursorSet(0, 0, 2);
	lcdPrint(" www.citron.inc");
	_delay_ms(1000);
	lcdClear();

	lcdGraphicDisplayClearAll();
	
	//renderGraphics(batteryFull, 8, 16, 7, 56);
	
	//lcdCursorSet(0, 0, 0);
	//lcdPrint("Test B00");
	//lcdCursorSet(0, 0, 1);
	//lcdPrint("Test B01");
	//lcdCursorSet(0, 0, 2);
	//lcdPrint("Test B02");
	//lcdCursorSet(0, 0, 3);
	//lcdPrint("Test B03");
	//lcdCursorSet(1, 0, 0);
	//lcdPrint("Test B10");
	//lcdCursorSet(1, 0, 1);
	//lcdPrint("Test B11");
	//lcdCursorSet(1, 0, 2);
	//lcdPrint("Test B12");
	//lcdCursorSet(1, 0, 3);
	//lcdPrint("Test B13");
	//_delay_ms(1000);
	//lcdVerticalScroll(32);
	
	//char buffer[6] = {};
	//itoa(12345, buffer);
	//
	//lcdNormalMode();
	//lcdCursorSet(0, 0, 2);
	//lcdPrint(buffer);
	
	//lcdGraphicsMode();
	//irSensorReceiveIcon(TRUE, 0x80, 0x80);
	//_delay_ms(500);
	//irSensorReceiveIcon(FALSE, 0x80, 0x80);
	//_delay_ms(500);
	
	//initTimerZero();
	//startTimerZero();
	//initIRSensor();
	//heartbeat();
	//_delay_ms(500);
	//heartbeat();
	//char iRbuffer[20] = {};
	//uint8_t irReceiveData[28] = {};
	
	lcdGraphicsMode();
	//renderGraphics(alertAllIcons, 8, 32, 4, 0);
	//renderGraphics(messageReceivedIcon, 8, 16, 6, 0);
	notificationIconsProcessor(0);
	numberDisplayTest();
	renderGraphics(batteryFull, 8, 16, 7, 0);
	//renderGraphics(number_5x8, 8, 80, 0, 9);
	lcdDrawGraphics();
	while(1)
	{
		//if (isIRAvailable)
		//{
		//lcdClear();
		//uint32_t ir = getIRReceiveData(irReceiveData);
		//lcdNormalMode();
		//lcdCursorSet(0, 0, 1);
		//itoa(ir, iRbuffer);
		//lcdPrint(iRbuffer);
		//}
		renderGraphics(irSensorReceiveEnable, 8, 8, 0, 0);
		_delay_ms(500);
		renderGraphics(smallIconReset, 8, 8, 0, 0);
		_delay_ms(500);
	}
}

void displayRefresh() {
	
}

void notificationIconFormatter(uint8_t * iconStripRef,  const uint8_t * icon, uint8_t startingIndex, uint8_t initialShift) {
	uint8_t initialStartingIndex = startingIndex;
	for (uint8_t n = 0; n < 2; n++)
	{
		if (n == 1)
		{
			startingIndex = initialStartingIndex + 1;
		}
		for (uint8_t raw = 0; raw < 8; raw++)
		{
			if (n == 0)
			{
				iconStripRef[startingIndex] |= (icon[raw] >> initialShift);
				} else {
				iconStripRef[startingIndex] |= (icon[raw] << (8 - initialShift));
			}
			startingIndex += 6;
		}
		if (!initialShift)
		{
			break;
		}
	}
}

void notificationIconsProcessor(uint8_t iconsToEnable) {
	uint8_t iconStrip[] = {
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
	};
	notificationIconFormatter(iconStrip, clockIcon, 5, 0);
	notificationIconFormatter(iconStrip, bellIcon, 3, 6);
	notificationIconFormatter(iconStrip, connectedIcon, 2, 4);
	notificationIconFormatter(iconStrip, alertIcon, 1, 2);
	notificationIconFormatter(iconStrip, messageIcon, 0, 0);
	renderGraphics(iconStrip, 8, 48, 4, 0);
}

void numberDisplayTest() {
	uint8_t numberStrip[] = {
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
		0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
	};
	numberGenerator5x8("12.3A", numberStrip, 64);
	renderGraphics(numberStrip, 8, 64, 0, 9);
}