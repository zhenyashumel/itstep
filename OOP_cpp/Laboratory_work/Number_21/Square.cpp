#include "Square.h"



Square::Square(const double a): Rectangle(a, a)
{
}

double Square::getArea()
{
	return getSide1() * getSide1();
}


