#include"Triangle.h"
#include<cmath>



Triangle::Triangle(const double a, const double b, const double c)
{
	side1 = a;
	side2 = b;
	side3 = c;


	angle1 = acos(((side2 * side2) + (side3 * side3) - (side1 * side1)) / (2 * side2 * side3)) * 180.0 / 3.141592;
	angle2 = acos(((side1 * side1) + (side2 * side2) - (side3 * side3)) / (2 * side1 * side2)) * 180.0 / 3.141592;
	angle3 = acos(((side3 * side3) + (side1 * side1) - (side2 * side2)) / (2 * side3 * side1)) * 180.0 / 3.141592;
}


Triangle::Triangle(const std::pair<double, double> par, const double c)
{
	side1 = par.first;
	side2 = par.second;
	side3 = sqrt((side1 * side1) + (side2 * side2) - (2 * side1 * side2 * (cos(angle1 * 3.141592 / 180))));

	angle1 = c;
	angle2 = acos(((side2 * side2) + (side3 * side3) - (side1 * side1)) / (2 * side2 * side3)) * 180.0 / 3.141592;
	angle3 = acos(((side3 * side3) + (side1 * side1) - (side2 * side2)) / (2 * side3 * side1)) * 180.0 / 3.141592;	
	
}


Triangle::Triangle(const double a, const std::pair<double, double> par)
{
	angle1 = par.first;
	angle2 = par.second;
	angle3 = 180 - angle1 - angle2;

	side1 = a;
	side2 = side1 * (sin(angle1) / sin(angle3));
	side3 = side1 * (sin(angle2) / sin(angle3));


}


double Triangle::getArea()
{
	double p = (side1 + side2 + side3) / 2;
	return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

void Triangle::getInfo() const
{
	std::cout << "Side 1: " << side1 << std::endl;
	std::cout << "Side 2: " << side2 << std::endl;
	std::cout << "Side 3: " << side3 << std::endl;

	std::cout << "Angle 1: " << angle1 << std::endl;
	std::cout << "Angle 2: " << angle2 << std::endl;
	std::cout << "Angle 3: " << angle3 << std::endl;
	std::cout << std::endl;
}

