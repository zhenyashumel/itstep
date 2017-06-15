#include"Stack.h"

void test()
{
	Stack <int> a;
	a.push(5);


	if (a.top() == 5)
		std::cout << "Test 1: OK!\n";
	else
		std::cout << "Test 1: Error!!!\n";


	Stack<int> b = a;

	if(b==a)
		std::cout << "Test 2: OK!\n";
	else
		std::cout << "Test 2: Error!!!\n";

	Stack <int> c;
	c = std::move(b);
	if (b != a)
		std::cout << "Test 3: OK!\n";
	else
		std::cout << "Test 3: Error!!!\n";

	if(b.empty())
		std::cout << "Test 4: OK!\n";
	else
		std::cout << "Test 4: Error!!!\n";

	if (!a.empty())
		std::cout << "Test 5: OK!\n";
	else
		std::cout << "Test 5: Error!!!\n";

	a.push(10);
	a.pop();

	if (a.top() == 5)
		std::cout << "Test 6: OK!\n";
	else
		std::cout << "Test 6: Error!!!\n";


	if(a.getSize()==1)
		std::cout << "Test 7: OK!\n";
	else
		std::cout << "Test 7: Error!!!\n";
	
}
int main()
{
	test();

	return 0;
}
