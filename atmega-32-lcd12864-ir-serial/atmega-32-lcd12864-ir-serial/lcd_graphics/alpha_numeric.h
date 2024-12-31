/*
* alpha_numeric.h
*
* Created: 12/30/2024 12:28:17 PM
*  Author: Buddhika
*/


#ifndef ALPHA_NUMERIC_H_
#define ALPHA_NUMERIC_H_

#include <avr/pgmspace.h>
#include "../hardware/lcd_12864/lcd_12864.h"
#include "../utility/string_util.h"

#define TRUE		0x01
#define FALSE		0x00

#define ALPHA_NUMERIC_CHAR_INDEX	0
#define INDEX_ADVANCED_BY			1 

const uint8_t number_5x8[] PROGMEM = {
	// 0			1			2			3		4			5			6		7			8			9			.			:		%			-			+
	0b01110000,0b00100000,0b01110000,0b11111000,0b00010000,0b11111000,0b00110000,0b11111000,0b01110000,0b01110000,0b00000000,0b00000000,0b11000000,0b00000000,0b00000000,
	0b10001000,0b01100000,0b10001000,0b00010000,0b00110000,0b10000000,0b01000000,0b00001000,0b10001000,0b10001000,0b00000000,0b00110000,0b11001000,0b00000000,0b00100000,
	0b10011000,0b00100000,0b00001000,0b00100000,0b01010000,0b11110000,0b10000000,0b00010000,0b10001000,0b10001000,0b00000000,0b00110000,0b00010000,0b00000000,0b00100000,
	0b10101000,0b00100000,0b00010000,0b00010000,0b10010000,0b00001000,0b11110000,0b00100000,0b01110000,0b01111000,0b00000000,0b00000000,0b00100000,0b11111000,0b11111000,
	0b11001000,0b00100000,0b00100000,0b00001000,0b11111000,0b00001000,0b10001000,0b01000000,0b10001000,0b00001000,0b00000000,0b00110000,0b01000000,0b00000000,0b00100000,
	0b10001000,0b00100000,0b01000000,0b10001000,0b00010000,0b10001000,0b10001000,0b01000000,0b10001000,0b00010000,0b00110000,0b00110000,0b10011000,0b00000000,0b00100000,
	0b01110000,0b01110000,0b11111000,0b01110000,0b00010000,0b01110000,0b01110000,0b01000000,0b01110000,0b01100000,0b00110000,0b00000000,0b00011000,0b00000000,0b00000000,
	0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
};

const uint8_t capitalLetters_5x8[] PROGMEM = {
	0b01110000,0b11110000,0b01110000,0b11110000,0b11111000,0b11111000,0b01110000,0b10001000,0b11111000,0b00011000,0b10001000,0b10000000,0b10001000,0b10001000,0b01110000,0b11110000,0b01110000,0b11110000,0b01110000,0b11111000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000,0b11111000,
	0b10001000,0b10001000,0b10001000,0b01001000,0b10000000,0b10000000,0b10001000,0b10001000,0b00100000,0b00001000,0b10010000,0b10000000,0b11011000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000,0b00100000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000,0b00001000,
	0b10001000,0b10001000,0b10000000,0b01001000,0b10000000,0b10000000,0b10000000,0b10001000,0b00100000,0b00001000,0b10100000,0b10000000,0b10101000,0b11001000,0b10001000,0b10001000,0b10001000,0b10001000,0b10000000,0b00100000,0b10001000,0b10001000,0b10001000,0b01010000,0b01010000,0b00010000,
	0b11111000,0b11110000,0b10000000,0b01001000,0b11110000,0b11110000,0b10110000,0b11111000,0b00100000,0b00001000,0b11000000,0b10000000,0b10001000,0b10101000,0b10001000,0b11110000,0b10001000,0b11110000,0b01110000,0b00100000,0b10001000,0b10001000,0b10001000,0b00100000,0b00100000,0b00100000,
	0b10001000,0b10001000,0b10000000,0b01001000,0b10000000,0b10000000,0b10001000,0b10001000,0b00100000,0b00001000,0b10100000,0b10000000,0b10001000,0b10011000,0b10001000,0b10000000,0b10101000,0b10100000,0b00001000,0b00100000,0b10001000,0b10001000,0b10101000,0b01010000,0b00100000,0b01000000,
	0b10001000,0b10001000,0b10001000,0b01001000,0b10000000,0b10000000,0b10001000,0b10001000,0b00100000,0b10001000,0b10010000,0b10000000,0b10001000,0b10001000,0b10001000,0b10000000,0b10010000,0b10010000,0b10001000,0b00100000,0b10001000,0b01010000,0b11011000,0b10001000,0b00100000,0b10000000,
	0b10001000,0b11110000,0b01110000,0b11110000,0b11111000,0b10000000,0b01110000,0b10001000,0b11111000,0b01111000,0b10001000,0b11111000,0b10001000,0b10001000,0b01110000,0b10000000,0b01101000,0b10001000,0b01110000,0b00100000,0b01110000,0b00100000,0b10001000,0b10001000,0b00100000,0b11111000,
	0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,
};

uint8_t getIndexerForProvidedNumericCharacter(char numericCharacter) {
	return (uint8_t) numericCharacter - 48; // 48 is the ascii value of '0'
}

uint8_t getIndexerForProvidedNumericSpecialCharacter(char numericSpecialCharacter) {
	uint8_t numericSpecialCharacterIndex = 0;
	switch (numericSpecialCharacter)
	{
		case '.': numericSpecialCharacterIndex = 10;
		break;
		case ':': numericSpecialCharacterIndex = 11;
		break;
		case '%': numericSpecialCharacterIndex = 12;
		break;
		case '-': numericSpecialCharacterIndex = 13;
		break;
		case '+': numericSpecialCharacterIndex = 14;
		break;
	}
	return numericSpecialCharacterIndex;
}

uint8_t getIndexerForProvidedCapitalAlphaCharacter(char capitalAlphaCharacter) {
	return (uint8_t) capitalAlphaCharacter - 65; // 65 is the ascii value of 'A'
}

uint8_t getIndexerForProvidedSimpleAlphaCharacter(char simpleAlphaCharacter) {
	return (uint8_t) simpleAlphaCharacter - 97; // 65 is the ascii value of 'a'
}

const uint8_t * getIndexerByCharacterType(char character, int * indexerBuffer) {
	uint8_t tempChar = (uint8_t) character;
	if ( tempChar < 48)
	{
		indexerBuffer[ALPHA_NUMERIC_CHAR_INDEX] = (int) getIndexerForProvidedNumericSpecialCharacter(character);
		indexerBuffer[INDEX_ADVANCED_BY] = 15;
		return number_5x8;
	}
	else if (47 < tempChar && tempChar < 58)
	{
		indexerBuffer[ALPHA_NUMERIC_CHAR_INDEX] = (int) getIndexerForProvidedNumericCharacter(character);
		indexerBuffer[INDEX_ADVANCED_BY] = 15;
		return number_5x8;
	}	
	else if (64 < tempChar && tempChar < 91)
	{
		indexerBuffer[ALPHA_NUMERIC_CHAR_INDEX] = (int) getIndexerForProvidedCapitalAlphaCharacter(character);
		indexerBuffer[INDEX_ADVANCED_BY] = 26;
		return capitalLetters_5x8;
	}	
	else if (96 < tempChar && tempChar < 124)
	{
		indexerBuffer[ALPHA_NUMERIC_CHAR_INDEX] = (int) getIndexerForProvidedSimpleAlphaCharacter(character);
		indexerBuffer[INDEX_ADVANCED_BY] = 26;
		return capitalLetters_5x8;
	}	
	return 0;
}

uint8_t numberGenerator5x8(const char * alphaNumericString, uint8_t * bitMapRef, const uint8_t bitMapHorizontalResolution) {
	if (bitMapHorizontalResolution  < strLength(alphaNumericString) * 6)
	{
		return FALSE; // if the string is not able to generate on the given bitmap, the function will skip the process
	}
	
	int shiftValues[4] = {0, 6, 4, 2}; // this is the shift pattern
	int shiftPatternIndexer = 0; // this will handle the shift for each character (incremented by 2)
	int bitMapByteResolution = bitMapHorizontalResolution / 8;
	int bitMapRefIndexers[3] = {0, 0, 1}; // 1st two element are for indexing and last element to track the next index before next digit processing
	int indexInfoHolder[2] = {0, 0}; // This bucket will hold the indexing related data 0: alphaNumericCharecterIndex, 1: howMuchIndexerSouldBeAdvanced for each iteration
	while(*alphaNumericString) {
		const uint8_t * alphaNumerics = getIndexerByCharacterType(*alphaNumericString, indexInfoHolder);
		int bitMapRefIndexer_0 = bitMapRefIndexers[0];
		int bitMapRefIndexer_1 = bitMapRefIndexers[1];
		for (int numberOfWrites = 0; numberOfWrites < 2; numberOfWrites++)
		{
			int _alphaNumeric_5x8Indexer = indexInfoHolder[ALPHA_NUMERIC_CHAR_INDEX];
			for (int index = 0; index < 8; index++)
			{
				if (numberOfWrites == 0)
				{
					bitMapRef[bitMapRefIndexer_0] |= (alphaNumerics[_alphaNumeric_5x8Indexer] >> shiftValues[shiftPatternIndexer]);
					bitMapRefIndexer_0 += bitMapByteResolution;
					} else {
					bitMapRef[bitMapRefIndexer_1] |= (alphaNumerics[_alphaNumeric_5x8Indexer] << (8 - shiftValues[shiftPatternIndexer]));
					bitMapRefIndexer_1 += bitMapByteResolution;
				}
				_alphaNumeric_5x8Indexer += indexInfoHolder[INDEX_ADVANCED_BY]; // Must be set the horizontal width of the number bitmap array above
			}
			if (shiftValues[shiftPatternIndexer] == 0)
			{
				break;
			}
		}
		alphaNumericString++;
		shiftPatternIndexer++;
		if (shiftPatternIndexer == 4)
		{
			shiftPatternIndexer = 0;
			bitMapRefIndexers[0] = bitMapRefIndexers[2];
			bitMapRefIndexers[1] = bitMapRefIndexers[2];
			bitMapRefIndexers[2] = bitMapRefIndexers[2] + 1;
			} else {
			bitMapRefIndexers[0] = bitMapRefIndexers[1];
			bitMapRefIndexers[1] = bitMapRefIndexers[2];
			bitMapRefIndexers[2] = bitMapRefIndexers[2] + 1;
		}
		if (shiftPatternIndexer == 3) {
			bitMapRefIndexers[1] = bitMapRefIndexers[0];
			bitMapRefIndexers[2] = bitMapRefIndexers[1] + 1;
		}
	}
	return TRUE;
}


#endif /* ALPHA_NUMERIC_H_ */