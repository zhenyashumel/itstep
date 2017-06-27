#include"Classes.h"
#include<iostream>
#include<algorithm>
#include<vector>

bool threeDigit(int value)
{
	return(value / 100 >= 1 && value / 100 < 10);
}


int main()
{
	std::vector<int> vec;

	for (int i = 0; i < 19; ++i)
		vec.push_back(rand() % 1000 - 100);
	vec.push_back(25);

	std::replace_if(vec.begin(), vec.end(), Equal(5), 10);
	auto it = std::remove_if(vec.begin(), vec.end(), Multiple(2));
	vec.erase(it, vec.end());
	std::cout << std::count_if(vec.begin(), vec.end(), Search(3))<<std::endl;
	

	it = std::remove_if(vec.begin(), vec.end(), threeDigit);
	vec.erase(it, vec.end());

	
	it = std::remove_if(vec.begin(), vec.end(), Square(6));
	vec.erase(it, vec.end());
	for (auto el : vec)
		std::cout << el << " ";
	
}
