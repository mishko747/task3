/**
* @file option12.h
* @brief The header file project 
*/

#ifndef OPTION12_H_
#define OPTION12_H_

typedef unsigned char UCHAR;

#define CONTINUE printf("\nPress any key to continue of press ESC to exit...")
#define CODE_ESC 27U
#define MAX_SIZE 255U

/**
* @brief	This function provides the correct input integer in the given range
* @param	[in]	minValue The minimum value
* @param	[in]	maxValue The maximum value
* @return	template type
*/
template< typename T > 
T ProtectionInput ( T minValue, T maxValue );

/**
* @brief	This function provides the creation of matrix real numbers given size
* @param	[in]	rows The number rows of the matrix
* @param	[in]	colls The number colls of the matrix
* @post		return the pointer to the first element of the first row of of the matrix
* @return	unsigned int
*/
unsigned int* CreateMatr ( const UCHAR rows, const UCHAR colls );

/**
* @brief	This function displays a matrix
* @param	[in]	pMatr Pointer to the first element of the first row of of the matrix
* @param	[in]	rows The number rows of the matrix
* @param	[in]	colls The number colls of the matrix
* @return	void
*/
void PrintMatr ( const unsigned int* pMatr, const UCHAR rows, const UCHAR colls );

/**
* @brief	This function removes of the matrix rows where the first element is minimal
* @param	[in]	pMatr The pointer to the first element of matrix
* @post		return number of deleted rows or -1 in case of error
* @return	short int
*/
short int DelRows ( unsigned int *pMatr, const UCHAR rows, const UCHAR colls );



#endif /* OPTION12_H_ */