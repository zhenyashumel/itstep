#pragma once
#define PI 3.1415926535897932384626433832795
#include<iostream>
class Area
{
	static int counter;
public:
	Area() {};
	static int getRectangleArea(int, int);
	static int getRectangleArea(int);
	static int getParallelogramArea(int, int);
	static int getParallelogramArea(int, int,int);
	static int getRhombusArea(int, float);
	static int getRhombusArea(int,int);
	static int getCounter() {return counter;}
	


};
