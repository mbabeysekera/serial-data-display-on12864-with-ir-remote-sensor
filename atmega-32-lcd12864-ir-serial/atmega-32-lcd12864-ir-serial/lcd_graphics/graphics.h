/*
* graphics.h
*
* Created: 12/13/2024 9:12:16 PM
*  Author: Buddhika
*/


#ifndef GRAPHICS_H_
#define GRAPHICS_H_
#include <avr/pgmspace.h>
#include "../hardware/lcd_12864/lcd_12864.h"
#include "alpha_numeric.h"

const uint8_t smallIconReset[] PROGMEM = {
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
};

const uint8_t irSensorReceiveEnable[] PROGMEM = {
	0b11011110,
	0b11011111,
	0b11011011,
	0b11011011,
	0b11011110,
	0b11011111,
	0b11011011,
	0b11011011,
};

const uint8_t alertIcon[] PROGMEM = {
	0b00111100,
	0b01000010,
	0b10011001,
	0b10000001,
	0b10011001,
	0b10011001,
	0b01000010,
	0b00111100,
};

const uint8_t clockIcon[] PROGMEM = {
	0b00111100,
	0b01000010,
	0b10010001,
	0b10010001,
	0b10011001,
	0b10000001,
	0b01000010,
	0b00111100,
};

const uint8_t connectedIcon[] PROGMEM = {
	0b01000010,
	0b01000010,
	0b11111111,
	0b10000001,
	0b10000001,
	0b01000010,
	0b00111100,
	0b00011000,
};

const uint8_t bellIcon[] PROGMEM = {
	0b00011000,
	0b00111100,
	0b01000010,
	0b01000010,
	0b01000010,
	0b01000010,
	0b11111111,
	0b00111100,
};

const uint8_t messageIcon[] PROGMEM = {
	0b01111110,
	0b10000001,
	0b10000001,
	0b10000001,
	0b10000001,
	0b10000010,
	0b01011100,
	0b00100000,
};

const uint8_t alertAllIcons[] PROGMEM = {
	0b00111100,0b00000111,0b10000001,0b00001000,
	0b01000010,0b00001000,0b01000001,0b00001000,
	0b10011001,0b00010010,0b00100011,0b11111100,
	0b10000001,0b00010010,0b00100010,0b00000100,
	0b10011001,0b00010011,0b00100010,0b00000100,
	0b10011001,0b00010000,0b00100001,0b11111000,
	0b01000010,0b00001000,0b01000000,0b01100000,
	0b00111100,0b00000111,0b10000000,0b01100000,
};

const uint8_t alertClockAndDataIcons[] PROGMEM = {
	0b00000000,0b00000111,0b10000001,0b00001000,
	0b00000000,0b00001000,0b01000001,0b00001000,
	0b00000000,0b00010010,0b00100011,0b11111100,
	0b00000000,0b00010010,0b00100010,0b00000100,
	0b00000000,0b00010011,0b00100010,0b00000100,
	0b00000000,0b00010000,0b00100001,0b11111000,
	0b00000000,0b00001000,0b01000000,0b01100000,
	0b00000000,0b00000111,0b10000000,0b01100000,
};

const uint8_t messageReceivedIcon[] PROGMEM = {
	0b00111110,0b00000000,
	0b01000001,0b00000000,
	0b10000000,0b10000000,
	0b10101010,0b10000000,
	0b10000000,0b10000000,
	0b01000000,0b10000000,
	0b00111101,0b00000000,
	0b00000010,0b00000000,
};

const uint8_t batteryFull[] PROGMEM = {
	0b00011111,0b11111110,
	0b00010000,0b00000010,
	0b00010110,0b11011011,
	0b00010110,0b11011011,
	0b00010110,0b11011011,
	0b00010110,0b11011011,
	0b00010000,0b00000010,
	0b00011111,0b11111110,
};

const uint8_t alphebetTest[] PROGMEM = {
	0b01110011,0b11000111,0b00111100,
	0b10001010,0b00101000,0b10010010,
	0b10001010,0b00101000,0b00010010,
	0b11111011,0b11001000,0b00010010,
	0b10001010,0b00101000,0b00010010,
	0b10001010,0b00101000,0b10010010,
	0b10001011,0b11000111,0b00111100,
	0b00000000,0b00000000,0b00000000,
};

const uint8_t citronLogo[] PROGMEM = {
	0b00000000,0b00000000,0b00000100,0b00000000,0b10000000,0b00000000,
	0b00000000,0b00000000,0b00001100,0b00000001,0b10000000,0b00000000,
	0b00000000,0b00000000,0b00011100,0b00000011,0b10000000,0b00000000,
	0b00000000,0b00000000,0b00110100,0b00000101,0b10000000,0b00000000,
	0b00000000,0b00000000,0b01100100,0b00001111,0b10000000,0b00000000,
	0b00000000,0b00000000,0b11001100,0b00011100,0b10000000,0b00000000,
	0b00000000,0b00000001,0b10000100,0b00111111,0b10000000,0b00000000,
	0b00000000,0b00000011,0b00001100,0b01101101,0b10000000,0b00000000,
	0b00000000,0b00000110,0b00000100,0b11110110,0b10000000,0b00000000,
	0b00000000,0b00001100,0b00001101,0b10111111,0b10000000,0b00000000,
	0b00000000,0b00011000,0b00001111,0b11101011,0b10000000,0b00000000,
	0b00000000,0b00110000,0b00011011,0b01111111,0b01111111,0b11110000,
	0b00000000,0b01101000,0b00110001,0b11011110,0b01111111,0b11100000,
	0b00000000,0b11101100,0b01100001,0b01111100,0b01111111,0b11000000,
	0b00000001,0b10100110,0b11000000,0b11111000,0b01111111,0b10000000,
	0b00000011,0b00100011,0b10000000,0b01110000,0b01111111,0b00000000,
	0b00000110,0b01100001,0b00000000,0b00100000,0b01111110,0b00000000,
	0b00001100,0b00100000,0b00000000,0b00000000,0b01111100,0b00000000,
	0b00011000,0b01100000,0b00000000,0b00000000,0b01111000,0b00000000,
	0b00110000,0b00100000,0b00000000,0b00000000,0b01110000,0b00000000,
	0b01100101,0b01100000,0b00000000,0b00000000,0b01100000,0b00000000,
	0b11111111,0b11100000,0b00000000,0b00000000,0b01000000,0b00000000,
	0b00000000,0b00011111,0b11111111,0b11111111,0b10000000,0b00000000,
	0b00000000,0b00011010,0b11011011,0b11111111,0b00000000,0b00000000,
	0b00000000,0b00010101,0b01110011,0b11111110,0b00000000,0b00000000,
	0b00000000,0b00011110,0b11100011,0b11111100,0b00000000,0b00000000,
	0b00000000,0b00010101,0b11000011,0b11111000,0b00000000,0b00000000,
	0b00000000,0b00011011,0b10000011,0b11110000,0b00000000,0b00000000,
	0b00000000,0b00011111,0b00000011,0b11100000,0b00000000,0b00000000,
	0b00000000,0b00010110,0b00000011,0b11000000,0b00000000,0b00000000,
	0b00000000,0b00011100,0b00000011,0b10000000,0b00000000,0b00000000,
	0b00000000,0b00011000,0b00000011,0b00000000,0b00000000,0b00000000,
	0b00000000,0b00010000,0b00000010,0b00000000,0b00000000,0b00000000,
};


void invertDisplayColor() {
	lcdGraphicsMode();
	for (uint8_t i = 0x80; i < 0xA0; i++)
	{
		lcdPixelCordinate(i, 0x80);
		for (uint8_t j = 0; j < 32; j++)
		{
			lcdCommand(DATA_MODE, 0xFF);
		}
	}
	lcdDrawGraphics();
}

void irSensorReceiveIcon(uint8_t isEnabled, uint8_t verticalStartPoint, uint8_t horizontalStartPoint) {
	lcdGraphicsMode();
	uint8_t indexer = 0;
	uint8_t display = 0;
	for (uint8_t v = 0; v < 8; v++)
	{
		lcdPixelCordinate(v + verticalStartPoint, horizontalStartPoint);
		if (isEnabled)
		{
			display = irSensorReceiveEnable[indexer];
			} else {
			display = smallIconReset[indexer];
		}
		lcdCommand(DATA_MODE, display);
		indexer++;
	}
	lcdDrawGraphics();
}

void renderGraphics(const uint8_t * bitMapRef, uint8_t resVertical, uint8_t resHorizontal, uint8_t x, uint8_t y) {
	if (resHorizontal % 8)
	{
		resHorizontal = resHorizontal + (8 - (resHorizontal % 8));
	}
	resHorizontal = resHorizontal / 8; // Prepare the resolution to match lCD
	uint8_t resVerticalL1 = 0;
	uint8_t resVerticalL2 = 0;
	uint8_t yL2 = 0;
	if ((y + resVertical) > 31)
	{
		if (y >= 32)
		{
			resVerticalL1 = 0;
			resVerticalL2 = resVertical;
			yL2 = y - 32;
			} else {
			resVerticalL2 = (y + resVertical) - 32;
			resVerticalL1 = resVertical - resVerticalL2;
		}
		} else {
		resVerticalL1 = resVertical;
	}
	int indexer = 0;
	for (uint8_t vertical = (0x80 + y); vertical < (0x80 + y + resVerticalL1); vertical ++)
	{
		lcdPixelCordinate(vertical, (x + 0x80));
		for (uint8_t horizontal = (x + 0x80); horizontal < (0x80 + resHorizontal + x); horizontal++)
		{
			lcdCommand(DATA_MODE, bitMapRef[indexer]);
			indexer++;
		}
	}
	if (resVerticalL2)
	{
		for (uint8_t vertical = (0x80 + yL2); vertical < (0x80 + yL2 + resVerticalL2); vertical ++)
		{
			lcdPixelCordinate(vertical, (x + 0x88));
			for (uint8_t horizontal = (x + 0x88); horizontal < (0x88 + resHorizontal + x); horizontal++)
			{
				lcdCommand(DATA_MODE, bitMapRef[indexer]);
				indexer++;
			}
		}
	}
}

void allFrame() {
	lcdPixelCordinate(0x80, 0x80);
	for (uint8_t i = 0; i < 16; i++)
	{
		lcdCommand(DATA_MODE, 0xFF);
	}
	lcdPixelCordinate(0x9F, 0x98);
	for (uint8_t i = 0; i < 16; i++)
	{
		lcdCommand(DATA_MODE, 0xFF);
	}
	for (uint8_t i = 0; i < 33; i++)
	{
		lcdPixelCordinate(0x81 + i, 0x80);
		lcdCommand(DATA_MODE, 0x80);
		lcdPixelCordinate(0x81 + i, 0x87);
		lcdCommand(DATA_MODE, 0x00);
		lcdCommand(DATA_MODE, 0x01);
	}
	for (uint8_t i = 0; i < 31; i++)
	{
		lcdPixelCordinate(0x80 + i, 0x88);
		lcdCommand(DATA_MODE, 0x80);
		lcdPixelCordinate(0x80 + i, 0x8F);
		lcdCommand(DATA_MODE, 0x00);
		lcdCommand(DATA_MODE, 0x01);
	}
}

#endif /* GRAPHICS_H_ */