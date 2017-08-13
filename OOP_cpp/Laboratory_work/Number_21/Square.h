#pragma once
#include"Rectangle.h"


class Square : public Rectangle
{

public:
	Square(const double);
	~Square() {};

	double getArea() override;
};

