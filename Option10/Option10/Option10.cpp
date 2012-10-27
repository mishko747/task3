/**
* @file option10.h
* @brief The source file project 
*/

#include "Option10.h"

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

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
	//printf("InputChar complete\n");
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
			//printf("Input x incomplete\n");
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
		
		tmpPtr = new Point3D[count + 1U];	// allocated memory in a temporary array (main array size + 1)

		if(tmpPtr == NULL)
		{
			printf("Memory allocation error\n");
			exit = 2U;
			continue;
		}

		memcpy(tmpPtr, pPoints, sizeof(Point3D) * count );	// move the the main array in the temporary
		delete pPoints;		// released memory from a main array
		memcpy( tmpPtr + count, tmpPoint, sizeof(Point3D) );	//	move the input data in the end of the temporary array
		pPoints = tmpPtr;	// address of temporary array is assigned a pointer to the main array
		count++;
		//printf("while complete\n");
	}	
	while(exit == 0U);
	//delete tmpPoint;   //Erorr!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//printf("InputData complete\n");
	if(count == 0U)
	{
		pPoints = NULL;
	}
	return pPoints;
}

// This function displays information about points
void PrintData ( Point3D *pPoints, unsigned char count )
{
	printf("Created points:\n");
	char name = 'A';
	for(unsigned char i = 0; i < count; ++i)
	{
		printf("%c(%d, %d, %d) Color: %s\n",name, pPoints[i].x, pPoints[i].y, pPoints[i].z, pPoints[i].color);
		name++;
	}
}

// This function determines the distance between two spatial points
float Distance3D(Point3D *a, Point3D *b)
{
	if(a == NULL || b == NULL)
	{
		printf("Memory allocation error\n");
		return -1;
	}
	return sqrt((float)(SQR(b->x, a->x) + SQR(b->y, a->y) + SQR(b->z, a->z)));
}

void main ( void )
{
	printf("Please enter the coordinates and color spatial points.\n");
	printf("Coordinates of the points must be in the range from -127 to 127.\n");
	printf("Color name length must not exceed 8 characters.\n");
	printf("\nYou read the instructions?\n");
	printf("if yes then press any key to continue or press ESC to exit...");
	if( _getch() == KODE_ESC )
	{
		return;
	}
	system("cls");
	Point3D *points;	// array of points
	unsigned char countP;	// count points in array
	Point3D *pointA;	// max distant point
	Point3D *pointB;	// max distant point
	float max;	// maximum distance between points
	float tmp;

	do
	{
		system("cls");
		points = InputData( countP );

		if(points != NULL)
		{
			system("cls");
			PrintData(points, countP);

			max = -1;
			for(unsigned char i = 0; i < countP - 1; ++i)
			{
				for(unsigned char j = i + 1; j < countP; ++j)
				{
					// the color is the same...
					if(strcmp( (char*)( (points + i)->color ), (char*)( (points + j)->color) ) == 0)
					{
						tmp = Distance3D(points + i, points + j);
						if( tmp > max )	
						{
							max = tmp;
							pointA = points + i;
							pointB = points + j;
						}
					}
				}	// End of for j
			}	// End of for i
			if(max > 0)
			{
				printf("Maximum distant points of one color:\n");
				printf("\tPoint %c(%d, %d, %d) Color - %s\n", 'A' + (pointA-points), pointA->x, pointA->y, pointA->z, pointA->color);
				printf("\tPoint %c(%d, %d, %d) Color - %s\n", 'A' + (pointB-points), pointB->x, pointB->y, pointB->z, pointB->color);
			}
			else
			{
				printf("No distant points of one color.\n");
			}
			delete points;
		}
		else
		{
			printf("\nNot created any point.\n");
		}
		printf("Press any key to continue or press ESC to Exit...");
	}
	while(getch() != KODE_ESC);	// while will not pressed key ESC
	return;
}