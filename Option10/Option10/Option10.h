/**
* @file option10.h
* @brief The header file project 
*/

#ifndef OPTION10_H_
#define OPTION10_H_

#define KODE_ESC 27U
#define LENGTH_OF_CHAR 4U
#define LENGTH_OF_COLOR 8U



struct Point3D
{
	char x;	// coordinate on the axis x
	char y;	// coordinate on the axis y
	char z;	// coordinate on the axis z
	unsigned char color[LENGTH_OF_COLOR];	// color of the point
};

/**
* @brief	This function provides the correct input numbers within [-127..127]
* @post		returns -128 if the user interrupted input
* @return	char
*/
char InputChar ( void );

/**
* @brief	This function provides input data
* @param	[in, out]	pPoint The count of points
* @post		returns the pointer to the struct Point3D
* @return	Point3D
*/
Point3D* InputData ( unsigned char &count);

/**
* @brief	This function determines the distance between two spatial points
* @param	[in]	p1 The pointer to the struct Point3D
* @param	[in]	p2 The pointer to the struct Point3D
* @return	unsigned short
*/
unsigned short Distance3D ( Point3D *p1, Point3D *p2 );


#endif /* OPTION10_H_ */