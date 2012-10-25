/**
* @file option9.h
* @brief The source file project 
*/

#include "option9.h"

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>


// This function converts the string in hexadecimal to decimal number
int StrToHex ( unsigned char *pStr )
{
	if(pStr == NULL)
	{
		return -1;
	}

	char i = strlen((char *)pStr);

	if( (i == 8) && (*pStr > '7') )	//	whether the number exceeds the upper limit
	{
		return -1;
	}

	int sum = 0;
	int k = 1;

	for (i = i - 1; i >= 0; k *= 16, --i)
	{ 
		switch ( *(pStr + i) )
		{
			case '0': 
				break;
			case '1': 
				sum += k; 
				break;
			case '2': 
				sum += 2 * k; 
				break;
			case '3': 
				sum += 3 * k; 
				break;
			case '4': 
				sum += 4 * k; 
				break;
			case '5': 
				sum += 5 * k; 
				break;
			case '6': 
				sum += 6 * k; 
				break;
			case '7': 
				sum += 7 * k; 
				break;
			case '8': 
				sum += 8 * k; 
				break;
			case '9': 
				sum += 9 * k; 
				break;
			case 'a':
			case 'A': 
				sum += 0xA * k; 
				break;
			case 'b':
			case 'B': 
				sum += 0xB * k; 
				break;
			case 'c':
			case 'C': 
				sum += 0xC * k; 
				break;
			case 'd':
			case 'D': 
				sum += 0xD * k; 
				break;
			case 'e':
			case 'E': 
				sum += 0xE * k; 
				break;
			case 'f':
			case 'F': 
				sum += 0xF * k; 
				break;		
			default:  
				i = -1;
		}	// End of switch
	}	// End of for i
	if(i == -2)	// symbol is not correct
	{
		return -1;
	}
	return sum;
}

void main ( void )
{
	unsigned char amountStr;	// amount entered strings
	unsigned int *pStrings;		// pointer to the first element of the array of pointers to rows
	unsigned char *pInputStr;	// a pointer to the first character entered string
	unsigned char exit = 0U;	// 0 - no error, no brake
								// 1 - brake
								// 2 - eror
	do
	{
		amountStr = 0U;
		pStrings = NULL;
		system("cls");
		printf("Enter the hexadecimal numbers in the range [0 .. 7FFFFFFF].\n");
		printf("Maximum number of characters - 8 (other characters will be ignored).\n");
		printf("To complete input the N.\n\n");
		do
		{
			pInputStr = new unsigned char[MAX_SYMBOLS + 1];
			if(pInputStr == NULL)
			{
				printf("Memory allocation failed!\n");
				exit = 2U;
				continue;
			}
			printf(":> ");
			fflush(stdin);
			scanf_s("%8s", pInputStr, MAX_SYMBOLS + 1);

			if(*pInputStr == 'N')	// if input a symbol 'N' than the end
			{
				exit = 1U;
				continue;
			}

			pStrings = (unsigned int*) realloc( pStrings, sizeof(unsigned int) * (amountStr + 1U) );

			if(pStrings == NULL)
			{
				printf("Memory allocation failed!\n");
				exit = 2U;
				delete pInputStr;
				continue;
			}

			*(pStrings + (amountStr) ) = (unsigned int) pInputStr;
			amountStr++;
		}
		while(exit == 0U);

		if(exit != 2U)	// if input correctly completed...
		{
			printf("Numbers:\n----------------------------------\n");
			if(amountStr == 0)	// if do not input a single string
			{
				printf("No data for output.\n");
			}
			else
			{
				printf("HEX\tDEC\t\t(-1 - incorrectly entered number)\n\n");
				for(unsigned char i = 0; i < amountStr; ++i)
				{
					printf("%s\t%d\n", *(pStrings + i), StrToHex( (unsigned char*)*(pStrings + i) ) );
				}
			}
		}
	
		if(pStrings != NULL)
		{
			for(unsigned char i = 0U; i < amountStr; ++i)
			{
				delete (unsigned int *)*(pStrings + i);
			}
			delete pStrings;
		}
		delete pInputStr;

		printf("\nPress Esc to exit or other key to continue...");
		fflush(stdin);
	}
	while(getch() != 27);	// while not pressed the Esc
}