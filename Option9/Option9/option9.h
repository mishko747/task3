/**
* @file option9.h
* @brief The header file project 
*/


#ifndef OPTION9_H_
#define OPTION9_H_

#define MAX_SYMBOLS 8U	// maximum number characters in a string

/**
* @brief	This function converts the string in hexadecimal to decimal number
* @param	[in]	pStr The pointer to the first character string
* @post		return decimal number >= 0 or -1 (in case of errors)
* @return	int
*/
int StrToHex ( unsigned char *pStr);



#endif /* OPTION9_H_ */