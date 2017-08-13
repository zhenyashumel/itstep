#pragma once
#include "Shape.h"



class Circle : public Shape
{

	double radius;	
	double x;
	double y;

public:

	Circle(const double r, const double a, const double b);
	~Circle() {};

	double getArea() override;
};

