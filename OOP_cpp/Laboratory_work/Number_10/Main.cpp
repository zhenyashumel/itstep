#include "Source.cpp"

void test()
{
	if (getMin(2.5, 10) == 2.5)
		std::cout << "Test 1: OK!\n";
	else 
		std::cout << "Test 1: Error!\n";


	double array1[] = { 2,2.5,7 };
	if(getMax<3>(array1)==7)
		std::cout << "Test 2: OK!\n";
	else
		std::cout << "Test 2: Error!\n";

	int arr[] = { 5,1,5,3,9,5,2 };
	sort(arr,7);
	bool flag = true;
	for (int i = 0; i < 6; ++i)
	{
		if (arr[i] > arr[i + 1])
			flag = false;
	}
	if(flag)
		std::cout << "Test 3: OK!\n";
	else
		std::cout << "Test 3: Error!\n";

	if(find(arr,7,9)==4)
		std::cout << "Test 4: OK!\n";
	else
		std::cout << "Test 4: Error!\n";



}
int main()
{
	test();
	std::cout<<solve(0, 5);
}
