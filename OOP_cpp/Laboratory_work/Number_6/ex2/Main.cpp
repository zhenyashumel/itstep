#include "MyVector.h"

void test()
{
	double arr1[] = { 1,2,3 };
	double arr2[] = { 2,3,4 };
	double arr3[] = { 1,2,3 };
	MyVector a(arr1, 3);
	MyVector b(arr2, 3);
	if (a < b)
		std::cout << "Test 1: OK\n";
	else
		std::cout << "Test 1: Error!!!\n";

	if (a != b)
		std::cout << "Test 2: OK\n";
	else
		std::cout << "Test 2: Error!!!\n";

	MyVector c(arr3, 3);
	if (a == c)
		std::cout << "Test 3: OK\n";
	else
		std::cout << "Test 3: Error!!!\n";

	if (b>a)
		std::cout << "Test 4: OK\n";
	else
		std::cout << "Test 4: Error!!!\n";
	b = a;
	if (a == b)
		std::cout << "Test 5: OK\n";
	else
		std::cout << "Test 5: Error!!!\n";

}
int main(int argc, char* argv[])
{
	
	test();

	return 0;
}
