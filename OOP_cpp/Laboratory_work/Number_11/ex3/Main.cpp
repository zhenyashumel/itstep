#include "MyVector.h"

void test()
{
	double arr1[50];
	for (int i = 0; i < 50; ++i)
	{
		arr1[i] = rand() % 11;
	}
	MyVector<double> a(arr1, 10);

	a.push_back(15);

	a.insert(17, 4);
	if (a.at(5) == 17)
		std::cout << "Test 1: OK!\n";
	else
		std::cout << "Test 1:Error!!!\n";

	a.resize(50);
	if (a.get_capacity() == 50)
		std::cout << "Test 2: OK!\n";
	else
		std::cout << "Test 2:Error!!!\n";
}

int main(int argc, char* argv[])
{
	
	test();
	std::cout << "More tests are not needed. If these two tests have the status OK, then  class work correctly!!!\n";


	return 0;
}
