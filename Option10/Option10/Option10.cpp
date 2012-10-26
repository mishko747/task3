/**
* @file option10.h
* @brief The source file project 
*/

#include "Option10.h"

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

// This function provides the correct input numbers within [-127..127]
char InputChar ( void )
{
	int tmp = 128;
	fflush(stdin);
	scanf_s("%d", &tmp, LENGTH_OF_CHAR);
	
	while( tmp < CHAR_MIN || tmp > CHAR_MAX)
	{
		printf("Incorrectly entered data!\n");
		printf("Press any key to repeat intput of press ESC to exit...");
		if(_getch() == KODE_ESC)
		{
			tmp = -128;
			continue;
		}
		printf("\nEnter number [-127..127] or enter -128 to exit :> ");
		fflush(stdin);
		scanf_s("%d", &tmp, LENGTH_OF_CHAR);
	}
	printf("InputChar complete\n");
	return tmp;
}

// This function provides input data
Point3D* InputData ( unsigned char &count )
{
	Point3D *tmpPoint = new Point3D;
	if(tmpPoint == NULL)
	{
		printf("Memory allocation error\n");
		return 0U;
	}
	Point3D *pPoints = NULL;
	Point3D *tmpPtr = NULL;
	unsigned char exit = 0U;
	count = 0U;
	
	do
	{
		printf("-------------------------------------------------------\n");
		printf("Enter coordinates of point ([-127..127], -128 to exit):\n");
		printf("x :> ");
		;
		if( ( tmpPoint->x = InputChar() ) == CHAR_MIN)
		{
			printf("Input x incomplete\n");
			exit = 1;
			continue;
		}
		printf("y :> ");
		if( ( tmpPoint->y = InputChar() ) == CHAR_MIN)
		{
			exit = 1U;
			continue;
		}
		printf("z :> ");
		if( ( tmpPoint->z = InputChar() ) == CHAR_MIN)
		{
			exit = 1U;
			continue;
		}
		printf("Enter the color (max 8 characters) :> ");
		scanf_s("%s", tmpPoint->color, LENGTH_OF_COLOR + 1U);
		
		tmpPtr = new Point3D[count + 1U];

		if(tmpPtr == NULL)
		{
			printf("Memory allocation error\n");
			exit = 2U;
			continue;
		}

		memmove(tmpPtr, pPoints, sizeof(Point3D) * count );
		delete pPoints;
		memmove( tmpPtr + count, tmpPoint, sizeof(Point3D) );
		pPoints = tmpPtr;
		count++;
		printf("while complete\n");
	}	
	while(exit == 0U);
	printf("InputData complete\n");
	//delete tmpPoint;   Erorr!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	printf("delete tmpPoint;\n");
	return pPoints;
}

// This function determines the distance between two spatial points
unsigned short Distance3D(Point3D *a, Point3D *b)
{
	

	return 0U;
}

void main ( void )
{
	Point3D *points;
	unsigned char countP;
	unsigned char exit = 0;
	do
	{
		points = NULL;

		printf("Please enter the coordinates and color spatial points.\n");
		printf("Coordinates of the points must be in the range from -127 to 127.\n");
		printf("Color name length must not exceed 8 characters.\n");
		printf("\nYou read the instructions?\n");
		printf("if yes then press any key to continue or press ESC to exit...");

		if( _getch() == KODE_ESC )
		{
			exit = 1U;
			continue;
		}
		system("cls");

		points = InputData( countP );
		if(countP == 0U)
		{
			exit = 1;
			printf("Not created any point");
			continue;
		}
		printf("Count of points: %u\n", countP);
		getch();
	}
	while(exit == 0U);	// while will not pressed key ESC
	getch();
	return;
}