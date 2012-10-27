/**
* @file option11.h
* @brief The source file project 
*/


#include "option11.h"

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

// This function converts the string in binary to decimal number
unsigned int StrToDec ( unsigned char *pStr )
{
	if(pStr == NULL)
	{
		return -1;
	}
	
	char i = strlen((char *)pStr);	// length of input string
	unsigned char j;	// variable to divide a number by tetrad
	unsigned char sumBin;	// sum of tetrads
	unsigned long int sumDec = 0U;	// total sum
	unsigned int kBin;	// coefficient for converting binary to decimal
	unsigned int kDec = 1U;	// coefficient for the creation of a decimal number

	for(i = i - 1; i >= 0; kDec *= 10U)	//cycle from the last character to first
	{
		sumBin = 0U;
		kBin = 1;
		j = 0;
		for ( ; j < 4U && i >= 0; --i)	// while not processed four characters or while end-of-line
		{ 
			switch ( *(pStr + i) )
			{
				case ' ':
					break;
				case '0': 
					kBin *= 2U;
					j++;
					break;
				case '1': 
					sumBin += kBin; 
					kBin *= 2U;
					j++;
					break;		
				default:  
					i = -1;
			}	// End of switch
		}	
		if(sumBin > 9U)	// if the number of tetrads over 9
		{
			i = -2;
			continue;
		}
		sumDec += kDec * sumBin;
	}	// End for i
	if(i == -2)	// symbol is not correct
	{
		return 0U;
	}
	return (unsigned int)sumDec;
}


void main ( void )
{
	unsigned char countStr;	// amount entered strings
	unsigned int *pStrings;		// pointer to the first element of the array of pointers to rows
	unsigned char *pInputStr;	// a pointer to the first character entered string
	unsigned char exit = 0U;	// 0 - no error, no brake
								// 1 - brake
								// 2 - eror
	do
	{
		countStr = 0U;
		pStrings = NULL;
		system("cls");
		printf("Enter the BCD numbers.\n");
		printf("Maximum number of characters - %u (other characters will be ignored).\n", MAX_SYMBOLS);
		printf("To complete input the N.\n\n");
		do
		{
			exit = 0U;
			pInputStr = new unsigned char[MAX_SYMBOLS + 1];
			if(pInputStr == NULL)
			{
				printf("Memory allocation failed!\n");
				exit = 2U;
				continue;
			}
			printf(":> ");
			fflush(stdin);
			gets_s((char *)pInputStr, MAX_SYMBOLS + 1);

			if(*pInputStr == 'N')	// if input a symbol 'N' than the end
			{
				exit = 1U;
				continue;
			}

			pStrings = (unsigned int*) realloc( pStrings, sizeof(unsigned int) * (countStr + 1U) );

			if(pStrings == NULL)
			{
				printf("Memory allocation failed!\n");
				exit = 2U;
				delete pInputStr;
				continue;
			}

			*(pStrings + (countStr) ) = (unsigned int)pInputStr;
			countStr++;
		}
		while(exit == 0U);

		if(exit != 2U)	// if input correctly completed...
		{
			printf("Numbers:\n----------------------------------\n");
			if(countStr == 0)	// if do not input a single string
			{
				printf("No data for output.\n");
			}
			else
			{
				printf("HEX\t\tDEC\t(0 - incorrectly entered number or 0)\n\n");
				for(unsigned char i = 0; i < countStr; ++i)
				{
					printf("%s  %u\n", *(pStrings + i), StrToDec( (unsigned char*)*(pStrings + i) ) );
				}
			}
		}
	
		if(pStrings != NULL)
		{
			for(unsigned char i = 0U; i < countStr; ++i)
			{
				delete (unsigned int *)*(pStrings + i);
			}
			delete pStrings;
		}

		printf("\nPress Esc to exit or other key to continue...");
		fflush(stdin);
	}
	while(getch() != 27);	// while not pressed the Esc
}