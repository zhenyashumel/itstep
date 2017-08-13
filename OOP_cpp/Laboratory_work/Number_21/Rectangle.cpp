#include "Rectangle.h"



Rectangle::Rectangle(const double a, const double b): Parallelogram(a, b, 90)
{
}


double Rectangle::getArea()
{
	return getSide1() * getSide2();
}

