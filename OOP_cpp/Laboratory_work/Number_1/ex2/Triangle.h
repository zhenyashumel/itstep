#pragma once
#define PI 3.1415926535897932384626433832795
#include<iostream>
#include<string>



class Triangle
{
	
public:
	Triangle(){};
	int getTriangleArea(const int, const int)const;
	int getTriangleArea(const int, const int,const float)const;
	int getTriangleArea(const int, const int,const int)const;
};
