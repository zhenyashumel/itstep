#include"Automobile.h"

void test()
{
	Taxi obj("Audi", 2017, 150, 20);

	if (obj.getModel() == "Audi")
		std::cout << "Test 1: OK!\n";
	else
		std::cout << "Test 1: Error!!!\n";

	if (obj.getRate() == 20)
		std::cout << "Test 2: OK!\n";
	else
		std::cout << "Test 2: Error!!!\n";

	if (obj.computeDistance(2) == 300)
		std::cout << "Test 3: OK!\n";
	else
		std::cout << "Test 3: Error!!!\n";

	if (obj.pay(2) == 6000)
		std::cout << "Test 4: OK!\n";
	else
		std::cout << "Test 4: Error!!!\n";

	std::cout << obj.getRate();
	if (obj.getRate() == 50)
		std::cout << "Test 5: OK!\n";
	else
		std::cout << "Test 5: Error!!!\n";

}


int main()
{
	test();
	return 0;

}
