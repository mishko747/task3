/**
* @file rowList.cpp
* @brief The source file with set of functions to work with a list of rows
*/

#include "rowList.h"

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <float.h>

// This function provides the correct input integer in the given range
bool ProtectionInput ( float &value, float minValue, float maxValue )
{
	long double x;
	bool flag = true; // flag interrupt input
	fflush(stdin);
	while ( flag == true && (!scanf_s("%Lf", &x) || ((float)x < minValue || (float)x > maxValue) ))
	{
		printf("Error! Incorrectly input data!\n");
		printf("Press any key to re-enter or ESC to termination...");
		fflush(stdin);	
		if(_getch() == CODE_ESC)	// if pressed key ESC...
		{
			flag = false;
			continue;
		}
		printf("\nPlease enter the number once again: ");
		fflush(stdin);
	}
	value = (float)x;
	return flag;
}

// This function creates the first row of the matrix
Row* CreateFirstRow(const unsigned char colls)
{
	Row *pRow;
	if( (pRow = new Row) == NULL )
	{
		return NULL;
	}
	if( ( pRow->data = new float[colls] ) == NULL )
	{
		delete pRow;
		return NULL;
	}
	bool flag = true;
	for(unsigned char j = 0U; j < colls && flag == true; ++j)
	{
			printf("Enter value Matrix[1][%u]: ", j + 1U);
			flag = ProtectionInput(*(pRow->data + j), FLT_MIN, FLT_MAX);
	}	// End for j*/
	if(flag == false)
	{
		delete pRow->data;
		delete pRow;
		return NULL;
	}
	pRow->next = NULL;
	return pRow;
}

// This function creates a set of rows (matrix)
Row* CreateMatrList( const unsigned char rows, const unsigned char colls )
{
	Row *pFirst;	// pointer to the first row of the matrix
	printf("Enter the float numbers in the range of %E to %E:\n", FLT_MIN, FLT_MAX);

	if( ( pFirst = CreateFirstRow(colls) ) == NULL)	// if not created the first row of the matrix...
	{
		return NULL;
	}

	Row *pCurrent = pFirst;	// pointer to the current row of the matrix	
	Row *tmpPtr;	// temporary pointer to a string matrix

	bool flag = true;	// flag interrupt input

	for(unsigned char i = 1U; i < rows && flag == true; ++i)
	{
		// memory allocation for the string
		if( (tmpPtr = new Row) == NULL )
		{
			flag = false;
			continue;
		}
		if( ( tmpPtr->data = new float[colls] ) == NULL )
		{
			flag = false;
			delete tmpPtr;
			continue;
		}
		// entering data
		for(unsigned char j = 0U; j < colls && flag == true; ++j)
		{
			printf("Enter value Matrix[%u][%u]: ", i + 1U, j + 1U);
			flag = ProtectionInput(*(tmpPtr->data + j), FLT_MIN, FLT_MAX);
		}	// End for j*/

		if(flag == false)	// if the user interrupted input...
		{
			delete tmpPtr->data;
			delete tmpPtr;
			continue;
		}
		tmpPtr->next = NULL;
		pCurrent->next = tmpPtr;
		pCurrent = tmpPtr;
	}	// End for i

	if(flag == false)
	{
		DeleteList(pFirst);
		return NULL;
	}
	return pFirst;
}

// This function displays a list of rows on the screen
void PrintMatrList ( Row *pFirst, const unsigned char colls )
{
	printf("-------------------------------------------------------\n");
	if(pFirst == NULL)
	{
		printf("No data for output.\n");
		return;
	}

	do
	{
		for(unsigned char j = 0U; j < colls; ++j)
		{
			printf("%.2f ", *(pFirst->data + j));
		}
		printf("\n");
		pFirst = pFirst->next;
	}
	while(pFirst != NULL);
	return;
}

// This function deletes rows from the matrix where the first element is minimal
unsigned char DelRows ( Row *&pFirst, const unsigned char colls )
{
	if(pFirst == NULL)
	{
		return 0;
	}
	bool flag;
	unsigned char count = 0U;
	Row *tmpFirst = new Row;
	tmpFirst->next = pFirst;
	Row *pPrey = tmpFirst;
	Row *pCurrent = pFirst;

	do
	{
		flag = true;
		for(unsigned char j = 1U; j < colls && flag == true; ++j)
		{
			if(*(pCurrent->data + j) <= *(pCurrent->data))
			{
				flag = false;
				continue;
			}
		}
		if(flag == true)
		{
			pPrey->next = pCurrent->next;
			delete pCurrent->data;
			delete pCurrent;
			pCurrent = pPrey->next;
			count++;
			continue;
		}
		pPrey = pCurrent;
		pCurrent = pCurrent->next;
	}
	while(pCurrent != NULL);
	pFirst = tmpFirst->next;
	delete tmpFirst;
	return count;
}

// This function frees the memory of the matrix
void DeleteList ( Row *pRow )
{
	if(pRow == NULL)
	{
		return;
	}
	Row *pCurrent;
	{
		pCurrent = pRow;
		pRow = pRow->next;
		delete pCurrent->data;
		delete pCurrent;
	}
	while(pRow != NULL);
}