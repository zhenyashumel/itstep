#include"Queue.h"

void test()
{
	Queue <int> a;
	a.push(5);


	if (a.front() == 5)
		std::cout << "Test 1: OK!\n";
	else
		std::cout << "Test 1: Error!!!\n";
	a.push(10);
	a.push(16);

	if(a.back()==16)
		std::cout << "Test 2: OK!\n";
	else
		std::cout << "Test 2: Error!!!\n";
	
	a.pop();
	
	if(a.front()==10)
		std::cout << "Test 3: OK!\n";
	else
		std::cout << "Test 3: Error!!!\n";

	a.clear();
	if(a.empty())
		std::cout << "Test 4: OK!\n";
	else
		std::cout << "Test 4: Error!!!\n";

	a.push(5);
	a.push(10);
	a.push(15);

	Queue<int>b = a;
	if(b.front() == a.front())
		std::cout << "Test 5: OK!\n";
	else
		std::cout << "Test 5: Error!!!\n";

	Queue<int>c;
	c = a;

	if (c.front() == a.front())
		std::cout << "Test 6: OK!\n";
	else
		std::cout << "Test 6: Error!!!\n";
	


	

}
int main()
{
	test();

	return 0;
}
