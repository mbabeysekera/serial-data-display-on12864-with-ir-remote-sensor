/*
* itoa.h
*
* Created: 12/18/2024 9:01:07 PM
*  Author: Buddhika
*/


#ifndef ITOA_H_
#define ITOA_H_

void reverseNumber(char * buffer, uint8_t length) {
	char temp = 0;
	if (length <= 2)
	{
		for (uint8_t i = 0; i < length / 2; i++)
		{
			temp = buffer[i];
			buffer[i] = buffer[(length - 1) - i];
			buffer[(length - 1) - i] = temp;
		}
	} else {
		for (uint8_t i = 0; i < (length - 1) / 2; i++)
		{
			temp = buffer[i];
			buffer[i] = buffer[(length - 1) - i];
			buffer[(length - 1) - i] = temp;
		}
	}
	
	
}

void itoa(long number, char * buffer) {
	int mod = 0;
	int i = 0;
	while (number != 0 && buffer)
	{
		mod = number % 10;
		number = number / 10;
		buffer[i] = mod + 48; // 48 is the ascii value for number 0
		i++;
	}
	buffer[i] = 0;
	reverseNumber(buffer, i);
}
#endif /* ITOA_H_ */