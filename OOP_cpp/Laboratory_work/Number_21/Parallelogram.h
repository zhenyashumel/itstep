#pragma once
#include"Shape.h"

class Parallelogram : public Shape
{
	double side1;
	double side2;
	double angle;

public:

	Parallelogram(const double, const double, const double);
	virtual ~Parallelogram();

	virtual double getArea() override;
	double getSide1() const;
	double getSide2() const;
	double getAngle() const;
};

