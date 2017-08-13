#include"Circle.h"


Circle::Circle(const double r, const double a, const double b) :radius(r), x(a), y(b)
{

}


double Circle::getArea()
{
	return 3.14159 * (radius * radius);
}
