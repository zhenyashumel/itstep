#include "Invoker1.h"


Invoker1::Invoker1()
{
}


Invoker1::~Invoker1()
{
}
Invoker1::Invoker1(int x, int y)
{
	Exort = x;
	Quas = y;
}
int Invoker1::getExort()const
{
	return Exort;
}

void Invoker1::setExort(int a)
{
	Exort = a;
}
