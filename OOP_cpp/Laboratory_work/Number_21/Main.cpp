#include <iostream>
#include "Shape.h"
#include "Triangle.h"
#include "Parallelogram.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"

int main()
{
	Triangle t1(5, 5, 5);
	Triangle t2({ 5, 5 }, 60);
	Triangle t3(5, { 60,60 });
	t1.getInfo();
	t2.getInfo();
	t3.getInfo();

	std::cout << t1.getArea() << std::endl;

	Parallelogram p1(10, 20, 30);
	std::cout << p1.getArea() << std::endl;

	Rectangle r1(5, 5);
	std::cout << r1.getArea() << std::endl;

	Square s1(5);
	std::cout << s1.getArea() << std::endl;

	Circle c1(5, 5, 10);
	std::cout << c1.getArea() << std::endl;

	return 0;
}
