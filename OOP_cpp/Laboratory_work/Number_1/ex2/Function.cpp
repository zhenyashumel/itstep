#include"Triangle.h"
#include"Square.h"

int Triangle::getTriangleArea(const int a, const int b)const
{
	return a*b*0.5;
}

int Triangle::getTriangleArea(const int a, const int b,const int c)const
{
	float p = (a + b + c) / 2;
	int S = sqrt(p*(p - a)*(p - b)*(p - c));
	return (int)S;
}
int Triangle::getTriangleArea(const int a, const int b,float c)const
{
	return (int)sin(c*PI / 180)*a*b*0.5;
}

int Square::getSquareArea(const int a)const
{
	return (int)a*a;
}
int Square::getSquareArea(const int a,const int b)const
{
	return (int)a*b;
}
