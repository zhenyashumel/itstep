#include<iostream>
#include<vector>

void work()
{
	std::vector<int> myVec;
	for (int i = 0; i < 100; ++i)
	{
		if (i % 2 == 0)
			myVec.push_back(i);
	}
	std::cout << "Size: " << myVec.size() << "\nCapacity: " << myVec.capacity() << std::endl;
	myVec[0] = myVec.size();

	myVec.erase(myVec.begin() + 7);
	myVec.erase(myVec.begin() + 13);
	myVec.erase(myVec.begin() + 19);
	int counter = 0;
	for (auto elem: myVec)
	{
		if (elem % 4 == 0)
			++counter;
	}
	std::cout << "Fold to four: " << counter << std::endl;
	myVec[19] = 99;
	myVec.pop_back();
	myVec.back() = 101;
	std::cout << "Size: " << myVec.size() << std::endl;

	for (auto elem : myVec)
	{
		std::cout << elem << " ";
	}
	std::cout <<std::endl;
	std::cout << std::endl;


	for (int i = 0; i < myVec.size(); ++i)
	{
		if (*(myVec.begin() + i) % 2 == 0)
			myVec.erase(myVec.begin() + i);
	}
	for (auto elem : myVec)
	{
		std::cout << elem << " ";
	}
	
}
int main()
{
	setlocale(0,"");
	work();

	return 0;
}
