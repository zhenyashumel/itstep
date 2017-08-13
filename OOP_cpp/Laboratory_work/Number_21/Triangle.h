#pragma once
#include"Shape.h"
#include<iostream>



class Triangle : public Shape
{
	double side1;
	double side2;
	double side3;

	double angle1;
	double angle2;
	double angle3;

public:
	Triangle(const double, const double, const double);
	Triangle(const std::pair<double, double>, const double);
	Triangle(const double, const std::pair<double, double>);

	virtual ~Triangle() {};

	double getArea() override;
	void getInfo() const;


};
