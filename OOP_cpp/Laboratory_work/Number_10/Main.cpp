#include "Source.cpp"

void test()
{
	if (getMin(2.5, 10) == 2.5)
		std::cout << "Test 1: OK!\n";
	else
		std::cout << "Test 1: Error!\n";


	double array1[] = { 2,2.5,7 };
	if (getMax<3>(array1) == 7)
		std::cout << "Test 2: OK!\n";
	else
		std::cout << "Test 2: Error!\n";

	int arr[] = { 5,1,5,3,9,5,2 };
	sort(arr, 7);
	bool flag = true;
	for (int i = 0; i < 6; ++i)
	{
		if (arr[i] > arr[i + 1])
			flag = false;
	}
	if (flag)
		std::cout << "Test 3: OK!\n";
	else
		std::cout << "Test 3: Error!\n";

	if (find(arr, 7, 5) == 3)
		std::cout << "Test 4: OK!\n";
	else
		std::cout << "Test 4: Error!\n";

	auto *arr2= solve(0, 5);	
		
	if (arr2[0]==0)
		std::cout << "Test 5: OK!\n";
	else
		std::cout << "Test 5: Error!\n";

	arr2 = solve(5, 5);

	if (arr2[1] == -1)
		std::cout << "Test 6: OK!\n";
	else
		std::cout << "Test 6: Error!\n";


	auto *arr3 = solve(3,-5,23);
	if(arr3[0]==0)
		std::cout << "Test 7: OK!\n";
	else
		std::cout << "Test 7: Error!\n";

	arr3 = solve(1, -4, 4);
	if(arr3[0]==1 && arr3[1]==2)
		std::cout << "Test 8: OK!\n";
	else
		std::cout << "Test 8: Error!\n";

	arr3 = solve(1, 2,-48);
	if(arr3[0]==2 && (arr3[1]==6||arr3[1]==-8) && (arr3[2] == 6 || arr3[2]==-8))
		std::cout << "Test 9: OK!\n";
	else
		std::cout << "Test 9: Error!\n";
	



}
int main()
{
	std::cout << "Hello!!!" << std::endl;
	std::cout << "Press Enter to continue...";
	std::cin.get();
	test();
	
}
