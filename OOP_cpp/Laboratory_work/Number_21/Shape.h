#pragma once


class Shape
{
public:
	Shape() {};
	virtual ~Shape() {};

	virtual double getArea() = 0;
};
