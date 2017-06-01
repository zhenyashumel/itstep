#include "Test.h"
#include "MyVector.h"


int main(int argc, char* argv[])
{
	double arr1[50];
	for (int i = 0; i < 50; ++i)
	{
		arr1[i] = rand() % 11;
	}
	MyVector a(arr1,10);
	MyVector b;
	a.print();
	std::cout << std::endl;
	a.sort();
	std::cout << std::endl;
	a.print();
	Test t;
	t.test();
	
	return 0;
}
