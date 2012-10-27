/**
* @file option11.h
* @brief The header file project 
*/


#ifndef OPTION11_H_
#define OPTION11_H_

#define MAX_SYMBOLS 30U	// maximum number characters in a string

/**
* @brief	This function converts the string in binary to decimal number
* @param	[in]	pStr The pointer to the first character string
* @post		return decimal number > 0 or 0 (in case of errors)
* @return	int
*/
unsigned int StrToDec ( unsigned char *pStr);



#endif /* OPTION11_H_ */