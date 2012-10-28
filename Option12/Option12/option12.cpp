/**
* @file option12.cpp
* @brief The source file project 
*/

#include "option12.h"

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>

// This function provides the correct input integer in the given range
bool ProtectionInput ( unsigned char &value, unsigned char minValue, unsigned char maxValue )
{
	long long x;
	bool flag = true; // flag interrupt input
	fflush(stdin);
	while ( flag == true && (!scanf_s("%lld", &x) || ((unsigned char)x < minValue || (unsigned char)x > maxValue) ))
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
	value = (unsigned char)x;
	return flag;
}

void main ( void )
{
	Row *pMatr;	// a pointer to the first element of the first row of of the matrix
	unsigned char rows = 2U;		// count of the rows of the matrix
	unsigned char colls = 2U;	// count of the rows of the matrix
	
	do
	{
		system("cls");
		printf("The minimum size of of the matrix: %hhu x %hhu.\n", MIN_SIZE, MIN_SIZE);
		printf("The maximum size of of the matrix: %hhu x %hhu.\n\n", MAX_SIZE, MAX_SIZE);
		
		//	input size of the matrix 
		printf("Enter count of rows (0 - continue): "); 
		if(ProtectionInput(rows, MIN_SIZE, MAX_SIZE) == false)
		{
			printf("\nInput data terminated by user.\n");
			continue;
		}
		printf("Enter count of colls (0 - continue): ");
		if(ProtectionInput(colls, MIN_SIZE, MAX_SIZE) == false)
		{
			printf("\nInput data terminated by user.\n");
			continue;
		}
	
		system("cls");

		printf("Size of matrix: %hhu x %hhu\n", rows, colls);

		// enter of the matrix
		pMatr = CreateMatrList(rows, colls);
		if(pMatr == NULL)
		{
			printf("\nMatrix is not created.\n");
			continue;
		}
		// displays a matrix
		PrintMatrList(pMatr, colls);

		// delete rows
		unsigned char countDel = DelRows(pMatr, colls);
		printf("%u row(s) removed from the matrix.\n", countDel);

		// displays a matrix
		PrintMatrList(pMatr, colls);
		delete pMatr;
	}
	while(CONTINUE, _getch() != CODE_ESC);	// while not pressed key ESC...
	return;
}