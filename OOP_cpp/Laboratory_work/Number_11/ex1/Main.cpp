#include"Pair.h"

void test()
{
	Pair<int, char> obj (5, 'a');
	
	if (obj.getFirst() == 5)
		std::cout << "Test 1: OK!\n";
	else
		std::cout << "Test 1: Error!!!\n";



	if (obj.getSecond() == 'a')
		std::cout << "Test 2: OK!\n";
	else
		std::cout << "Test 2: Error!!!\n";



	obj.make_pair('a', 5);

	if (obj.getFirst() == 'a')
		std::cout << "Test 3: OK!\n";
	else
		std::cout << "Test 3: Error!!!\n";



	if (obj.getSecond() == 5)
		std::cout << "Test 4: OK!\n";
	else
		std::cout << "Test 4: Error!!!\n";



	Pair<bool, bool> obj1(true);

	if (obj1.getFirst() && obj1.getSecond())
		std::cout << "Test 5: OK!\n";
	else
		std::cout << "Test 5: Error!!!\n";




	obj1.make_pair(false);
	

	if (!obj1.getFirst() && !obj1.getSecond())
		std::cout << "Test 6: OK!\n"; 
	else
		std::cout << "Test 6: Error!!!\n";



}
int main()
{
	test();

	return 0;
}
