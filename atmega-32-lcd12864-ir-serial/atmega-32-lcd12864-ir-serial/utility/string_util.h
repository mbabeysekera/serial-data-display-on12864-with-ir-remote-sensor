/*
 * string_util.h
 *
 * Created: 12/30/2024 12:51:41 PM
 *  Author: Buddhika
 */ 


#ifndef STRING_UTIL_H_
#define STRING_UTIL_H_

unsigned int strLength(const char * stringlet) {
	unsigned int lenght = 0;
	while(*stringlet) {
		lenght++;
		stringlet++;
	}
	return lenght;
}



#endif /* STRING_UTIL_H_ */