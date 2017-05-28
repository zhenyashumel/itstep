#include "Area.h"

int Area::getRectangleArea(int a, int b)
{
	counter++;
	return a*b;	
}

int Area::getRectangleArea(int a)
{
	counter++;
	return a*a;
}

int Area::getParallelogramArea(int a, int h)
{
	counter++;
	return a*h;
}
int Area::getParallelogramArea(int a, int b, int c)
{
	counter++;
	return (int)sin(c*PI / 180)*a*b;
}

int Area::getRhombusArea(int a, float b)
{
	counter++;
	return (int)sin(b*PI / 180)*a*a;
}
int Area::getRhombusArea(int a, int b)
{
	counter++;
	return (a*b) / 2;
}
int Area::counter = 0;
