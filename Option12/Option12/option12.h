/**
* @file option12.h
* @brief The header file project 
*/

#ifndef OPTION12_H_
#define OPTION12_H_

#include "rowList.h"

#define CONTINUE printf("\nPress any key to continue of press ESC to exit...")
#define CODE_ESC 27U
#define MIN_SIZE 2U
#define MAX_SIZE 255U

/**
* @brief	This function provides the correct input integer in the given range
* @param	[out]	value The correct value
* @param	[in]	minValue The minimum value
* @param	[in]	maxValue The maximum value
* @return	bool
*/
bool ProtectionInput (unsigned char &value, unsigned char minValue, unsigned char maxValue );

#endif /* OPTION12_H_ */