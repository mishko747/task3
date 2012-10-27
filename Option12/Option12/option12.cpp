/**
* @file option12.h
* @brief The source file project 
*/

#include "option12.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// This function provides the correct input integer in the given range
template< typename T > 
T ProtectionInput ( T minValue, T maxValue )
{
	long long x;
	fflush(stdin);
	while ( !scanf_s("%lld", &x) || (x < minValue || x > maxValue) )
	{
		fflush(stdin);
		printf("Error! Incorrectly input data!\n");
		printf("Please enter the number once again: ");
	}
	return (T)x;
}


// This function provides the creation of matrix real numbers given size
unsigned int* CreateMatr ( UCHAR rows, UCHAR colls )
{
	printf("Created matr...\n");
	return NULL;
}

// This function displays a matrix
void PrintMatr ( const unsigned int* pMatr, const UCHAR rows, const UCHAR colls )
{
	float *tmpPtr;
	printf("-------------------------------------------------------\n");
	printf("Matrix of float numbers: %hhu x %hhu\n", rows, colls);
	for(UCHAR i = 0U; i < rows; ++i)
	{
		tmpPtr = (float*)(pMatr + i);
		for(UCHAR j = 0U; j < colls; ++j)
		{
			printf("%.2f ", *(tmpPtr + j));
		}
		printf("\n");
	}
	return;
}

// This function removes of the matrix rows where the first element is minimal
short int DelRows ( unsigned int *pMatr, const UCHAR rows, const UCHAR colls )
{

	return 0U;
}


void main ( void )
{
	unsigned int *pMatr;	// a pointer to the first element of the first row of of the matrix
	UCHAR rows;		// count of the rows of the matrix
	UCHAR colls;	// count of the rows of the matrix
	float *tmpPtr;

	
	do
	{
		system("cls");
		printf("The maximum size of of the matrix: %hhu x %hhu.\n\n", MAX_SIZE, MAX_SIZE);
		
		//	input size of the matrix 
		printf("Enter count of rows (0 - continue): "); 
		rows = ProtectionInput<UCHAR>(0, 255);
		if(rows == 0U)
		{
			printf("Input data terminated by user.\n");
			continue;
		}
		printf("Enter count of colls (0 - continue): ");
		colls = ProtectionInput<UCHAR>(0, 255);
		if(colls == 0U)
		{
			printf("Input data terminated by user.\n");
			continue;
		}

		system("cls");

		printf("Size of matrix: %hhu x %hhu\n", rows, colls);

		// enter of the matrix
		pMatr = CreateMatr(rows, colls);
		if(pMatr == NULL)
		{
			printf("Matrix is not created.\n");
			continue;
		}
		// displays a matrix
		PrintMatr(pMatr, rows, colls);

		// delete rows
		short int countDel = DelRows(pMatr, rows, colls);
		if(countDel == -1)
		{
			if(pMatr != NULL)
			{
				for(UCHAR i = 0U; i < rows; ++i)
				{
					tmpPtr = (float *)*(pMatr + i);
					if(tmpPtr != NULL)
					{
						delete tmpPtr;
					}
				}
				delete pMatr;
			}
			printf("An error occurred while deleting rows.");
			continue;
		}
		printf("%u rows removed from the matrix.\n", DelRows(pMatr, rows, colls));

		// displays a matrix
		PrintMatr(pMatr, rows, colls);
		for(UCHAR i = 0U; i < rows; ++i)
		{
			tmpPtr = (float *)*(pMatr + i);
			if(tmpPtr != NULL)
			{
				delete tmpPtr;
			}
		}
		delete pMatr;
	}
	while(CONTINUE, _getch() != CODE_ESC);	// while not pressed key ESC...
	return;
}