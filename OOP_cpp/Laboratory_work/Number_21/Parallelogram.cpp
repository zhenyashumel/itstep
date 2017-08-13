#include "Parallelogram.h"
#include<cmath>



Parallelogram::Parallelogram(const double a, const double b, const double c): side1(a), side2(b), angle(c)
{
}


Parallelogram::~Parallelogram()
{
}


double Parallelogram::getArea()
{
	return side1 * side2 * (sin(angle / 180 * 3.14159));
}


double Parallelogram::getSide1() const
{
	return side1;
}


double Parallelogram::getSide2() const
{
	return side2;
}


double Parallelogram::getAngle() const
{
	return angle;
}
