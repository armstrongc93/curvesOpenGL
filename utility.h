#ifndef UTILITY_H
#define UTILITY_H

#include <GL/glut.h>

void DecodeCoords(int, int, int*, int*);
int fac(int);

/* 2D point class for mouse only, can make data members 
   public in it as they are not critical */

class TwoDPoint
{
public:
	double x;
	double y;

public:
	TwoDPoint() { x=0.0f; y=0.0f; }
	TwoDPoint( double xx, double yy)	{ x = xx; y = yy;}

};

#endif