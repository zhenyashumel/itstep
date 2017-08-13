#pragma once
#include"Parallelogram.h"
class Rectangle : public Parallelogram
{

public:
	Rectangle(const double, const double);
	virtual ~Rectangle() {};

	virtual double getArea() override;


};

