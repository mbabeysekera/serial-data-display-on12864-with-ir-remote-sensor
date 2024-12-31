/*
* lcd_12864.h
*
* Created: 12/8/2024 5:57:54 PM
*  Author: Buddhika
*/


#ifndef LCD_12864_H_
#define LCD_12864_H_

#include <util/delay.h>

#define TRUE										0x01
#define FALSE										0x00

// LCD Instruction Set
#define INSTRUCTION_MODE							0b00000000
#define DATA_MODE									0b00000001

#define INS_LCD12864_CLEAR							0b00000001
#define INS_LCD12864_HOME							0b00000010
#define INS_LCD12864_ENTRY_MODE						0b00000110
#define INS_LCD12864_DISPLAY						0b00001000
#define INS_LCD12864_DISPLAY_ON						0b00000100
#define INS_LCD12864_CURSOR_ON						0b00000010
#define INS_LCD12864_BLINK_ON						0b00000001
#define INS_LCD12864_DISPLAY_CTRL					0b00010000
#define INS_LCD12864_DISPLAY_CURSOR_MOVE_LEFT		0b00000000
#define INS_LCD12864_DISPLAY_CURSOR_MOVE_RIGHT		0b00000100
#define INS_LCD12864_DISPLAY_SHIFT_LEFT				0b00001000
#define INS_LCD12864_DISPLAY_SHIFT_RIGHT			0b00001100
#define INS_LCD12864_FUNCTION_SET					0b00100010
#define INS_LCD12864_SET_CG_RAM_ADDR				0b01000000 // Ex Ins SR = 0
#define INS_LCD12864_SET_DD_RAM_ADDR				0b10000000

#define INS_LCD12864_VERTICAL_SCROLL				0b00000011
#define INS_LCD12864_DISPLAY_REVERSE				0b00000100
#define INS_LCD12864_FUNCTION_SET_EX				0b00100100
#define INS_LCD12864_GRAPHICS_ENABLE				0b00100110
#define INS_LCD12864_GRAPHICS_INIT					0b00100000

#define INS_LCD12864_B0_0X0Y_POSITION				0x80
#define INS_LCD12864_B0_0X1Y_POSITION				0x90
#define INS_LCD12864_B1_0X0Y_POSITION				0xA0
#define INS_LCD12864_B1_0X1Y_POSITION				0xB0

#define INS_LCD12864_B0_0X2Y_POSITION				0x88
#define INS_LCD12864_B0_0X3Y_POSITION				0x98
#define INS_LCD12864_B1_0X2Y_POSITION				0xA8
#define INS_LCD12864_B1_0X3Y_POSITION				0xB8

#define MASK_4BIT									0b11110000

#ifndef LCD12864_BL
#define LCD12864_BL		PINC7
#endif
#define LCD12864_RS		PINA0
#define LCD12864_RW		PINA1
#define LCD12864_EN		PINA2
#define LCD12864_RST	PINC6

void lcdCommandEnablePulse() {
	PORTA |= (1 << LCD12864_EN);
	_delay_us(1);
	PORTA &= ~(1 << LCD12864_EN);
	_delay_us(1);
	PORTA = 0x00;
}

void lcdCommand(uint8_t mode, uint8_t data) {
	if (mode)
	{
		PORTA = (MASK_4BIT & data) | DATA_MODE;
		lcdCommandEnablePulse();
		PORTA = (MASK_4BIT & (data << 4)) | DATA_MODE;
		lcdCommandEnablePulse();
		} else {
		PORTA = (MASK_4BIT & data);
		lcdCommandEnablePulse();
		PORTA = (MASK_4BIT & (data << 4));
		lcdCommandEnablePulse();
	}
	_delay_ms(1);
}

void lcdCommandExtended(uint8_t mode, uint16_t data) {
	PORTA = 0x00;
	if (mode)
	{
		PORTA = (MASK_4BIT & (data >> 8)) | DATA_MODE;
		lcdCommandEnablePulse();
		PORTA = (MASK_4BIT & (data >> 4)) | DATA_MODE;
		lcdCommandEnablePulse();
		PORTA = (MASK_4BIT & data) | DATA_MODE;
		lcdCommandEnablePulse();
		PORTA = (MASK_4BIT & (data << 4)) | DATA_MODE;
		lcdCommandEnablePulse();
		} else {
		PORTA = (MASK_4BIT & data);
		lcdCommandEnablePulse();
		PORTA = (MASK_4BIT & (data << 4));
		lcdCommandEnablePulse();
	}
	_delay_ms(1);
}

void lcdGraphicDisplayClearAll() {
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_ENTRY_MODE);
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_FUNCTION_SET_EX); // No need to enable display for cleaning it.
	for (uint8_t i = INS_LCD12864_B0_0X0Y_POSITION; i < INS_LCD12864_B1_0X0Y_POSITION; i++)
	{
		lcdCommand(INSTRUCTION_MODE, i); // Vertical
		lcdCommand(INSTRUCTION_MODE, INS_LCD12864_B0_0X0Y_POSITION); // Horizontal
		for (uint8_t j = 0; j < 32; j++)
		{
			lcdCommand(DATA_MODE, 0x00);
		}
	}
}

void initLCD128X64() {
	// Enable back light of the LCD
	PORTC &= ~((1 << LCD12864_BL) | (1 << LCD12864_RST));
	DDRC |= (1 << LCD12864_BL) | (1 << LCD12864_RST);
	// Initialize the display control pins
	DDRA |= 0XFF; // All pins to output
	PORTA = 0X00; // Initially all pins set to 0
	_delay_ms(10);
	PORTC |= (1 << LCD12864_RST); // Enable Display
	_delay_us(150);
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_FUNCTION_SET);
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_FUNCTION_SET);
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_DISPLAY | INS_LCD12864_DISPLAY_ON);
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_CLEAR);
	_delay_ms(10);
	lcdGraphicDisplayClearAll();
}

void lcdCursorSet(uint8_t bank, uint8_t col, uint8_t row) {
	if (!bank)
	{
		switch (row)
		{
			case 0: col += INS_LCD12864_B0_0X0Y_POSITION;
			break;
			case 1: col += INS_LCD12864_B0_0X1Y_POSITION;
			break;
			case 2: col += INS_LCD12864_B0_0X2Y_POSITION;
			break;
			case 3: col += INS_LCD12864_B0_0X3Y_POSITION;
			break;
		}
	} else {
		switch (row)
		{
			case 0: col += INS_LCD12864_B1_0X0Y_POSITION;
			break;
			case 1: col += INS_LCD12864_B1_0X1Y_POSITION;
			break;
			case 2: col += INS_LCD12864_B1_0X2Y_POSITION;
			break;
			case 3: col += INS_LCD12864_B1_0X3Y_POSITION;
			break;
		}
	}
	lcdCommand(INSTRUCTION_MODE, col);
}

void lcdPrint(const char * text) {
	while (*text)
	{
		lcdCommand(DATA_MODE, *text);
		text++;
	}
}

void lcdNormalMode() {
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_FUNCTION_SET);
}

void lcdClear() {
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_FUNCTION_SET);
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_CLEAR);
}

void lcdGraphicsMode() {
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_FUNCTION_SET_EX); 
}

void lcdDrawGraphics() {
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_GRAPHICS_ENABLE);
}

void lcdPixelCordinate(uint8_t v, uint8_t h) {
	lcdCommand(INSTRUCTION_MODE, v); // Vertical
	lcdCommand(INSTRUCTION_MODE, h); // Horizontal
}

void lcdVerticalScroll(uint8_t value) {
	if (value > 0x20)
	{
		value = 0x20;
	}
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_FUNCTION_SET_EX);
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_VERTICAL_SCROLL);
	lcdCommand(INSTRUCTION_MODE, 0b01000000 | value);
}

#endif /* LCD_12864_H_ */