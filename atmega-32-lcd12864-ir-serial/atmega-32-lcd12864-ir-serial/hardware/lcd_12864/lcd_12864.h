/*
* lcd_12864.h
*
* Created: 12/8/2024 5:57:54 PM
*  Author: Buddhika
*/


#ifndef LCD_12864_H_
#define LCD_12864_H_

#pragma once
#include <util/delay.h>

// LCD Instruction Set
#define INSTRUCTION_MODE							0B00000000
#define DATA_MODE									0B00000001
#define INS_LCD12864_CLEAR							0B00000001
#define INS_LCD12864_HOME							0B00000010
#define INS_LCD12864_ENTRY_MODE						0B00000110
#define INS_LCD12864_DISPLAY						0B00001000
#define INS_LCD12864_DISPLAY_ON						0B00000100
#define INS_LCD12864_CURSOR_ON						0B00000010
#define INS_LCD12864_BLINK_ON						0B00000001
#define INS_LCD12864_DISPLAY_CTRL					0B00010000
#define INS_LCD12864_DISPLAY_CURSOR_MOVE_LEFT		0B00000000
#define INS_LCD12864_DISPLAY_CURSOR_MOVE_RIGHT		0B00000100
#define INS_LCD12864_DISPLAY_SHIFT_LEFT				0B00001000
#define INS_LCD12864_DISPLAY_SHIFT_RIGHT			0B00001100
#define INS_LCD12864_FUNCTION_SET					0B00100010

#define MASK_4BIT									0B11110000

#ifndef LCD12864_BL
#define LCD12864_BL		PINC7
#endif
#define LCD12864_RS		PINA0
#define LCD12864_RW		PINA1
#define LCD12864_EN		PINA2
#define LCD12864_RST	PINC6

void lcdCommandEnablePulse() {
	PORTA |= (1 << LCD12864_EN);
	_delay_us(500);
	PORTA &= ~(1 << LCD12864_EN);
	_delay_us(500);
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
}

void initLCD128X64() {
	// Enable back light of the LCD
	PORTC &= ~((1 << LCD12864_BL) | (1 << LCD12864_RST));
	DDRC |= (1 << LCD12864_BL) | (1 << LCD12864_RST);
	// Initialize the display control pins
	DDRA |= 0XFF; // All pins to output
	PORTA = 0X00; // Initially all pins set to 0
	_delay_ms(50);
	PORTC |= (1 << LCD12864_RST); // Enable Display
	//PORTA = 0B00100000;
	//lcdCommandEnablePulse();
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_FUNCTION_SET);
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_DISPLAY | INS_LCD12864_DISPLAY_ON);
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_CLEAR);
	_delay_ms(50);
	lcdCommand(INSTRUCTION_MODE, INS_LCD12864_ENTRY_MODE);
	
	lcdCommand(DATA_MODE, 'H');
	lcdCommand(DATA_MODE, 'e');
	lcdCommand(DATA_MODE, 'l');
	lcdCommand(DATA_MODE, 'l');
	lcdCommand(DATA_MODE, 'o');
	lcdCommand(DATA_MODE, ' ');
	lcdCommand(DATA_MODE, 'W');
	lcdCommand(DATA_MODE, 'o');
	lcdCommand(DATA_MODE, 'r');
	lcdCommand(DATA_MODE, 'l');
	lcdCommand(DATA_MODE, 'd');
	//lcdCommand(DATA_MODE, '!');
}

#endif /* LCD_12864_H_ */