/**
* @file rowList.h
* @brief The header file with set of functions to work with a list of rows
*/

#ifndef ROWLIST_H_
#define ROWLIST_H_

#define CODE_ESC 27U

struct Row
{
	float *data;	// a pointer to the first element of row
	Row *next;	// a pointer to the next row
};

/**
* @brief	This function provides the correct input integer in the given range
* @param	[out]	value The correct value
* @param	[in]	minValue The minimum value
* @param	[in]	maxValue The maximum value
* @return	bool
*/
bool ProtectionInput (float &value, float minValue, float maxValue );

/**
* @brief	This function creates the first row of the matrix
* @param	[in]	colls The count of the colls
* @return	*Row
*/
Row* CreateFirstRow(const unsigned char colls);

/**
* @brief	This function creates a set of rows (matrix)
* @param	[in]	rows The count of the rows
* @param	[in]	colls The count of the colls
* @return	*Row
*/
Row* CreateMatrList( const unsigned char rows, const unsigned char colls );

/**
* @brief	This function displays a list of rows on the screen
* @param	[in]	pFirst The pointer to the first row
* @param	[in]	colls The count of the colls
* @return	void
*/
void PrintMatrList ( Row *pFirst, const unsigned char colls );

/**
* @brief	This function deletes rows from the matrix where the first element is minimal
* @param	[in]	pFirst The pointer to the first row
* @param	[in]	colls The count of the colls
* @return	unsigned char
*/
unsigned char DelRows ( Row *&pFirst, const unsigned char colls );

/**
* @brief	This function frees the memory of the matrix
* @param	[in]	pFirst The pointer to the first row
* @return	void
*/
void DeleteList ( Row *pRow );

#endif /* ROWLIST_H_ */