#include<iostream>
#include<vector>
#include<map>
#include<utility>

void work()
{
	std::map<int, int> myMap = { {1, 1},{2, 4}, {3, 9}, { 4, 16 },
	{ 5, 25 },{ 6, 36 },{ 7, 49 },{ 8, 64 },{ 9, 81 } };

	for (auto pair : myMap)
		std::cout << pair.first << " => " << pair.second << std::endl;
	std::cout << std::endl;
	myMap[7] = 14;
	myMap.insert({ 10, 30 });
	myMap.erase(5);
	for (auto pair : myMap)
	{
		pair.second += pair.first;
	}

	for (auto it = myMap.begin(); it != myMap.end();)
	{
		if (it->second == 21 || it->second == 42)
			myMap.erase(it++);
		else ++it;
			
	}

	if (!myMap.count(7))
		myMap.insert({ 7, 5 });

	int counter = 0;
	for (auto pair : myMap)
	{
		if (pair.first % 2 == 1)
			counter += pair.second;
	}

	std::cout << counter;
	std::cout << std::endl;

	for (auto pair : myMap)
		std::cout << pair.first << " => " << pair.second << std::endl;
		
}

int main()
{
	setlocale(0,"");
	work();

	return 0;
}
