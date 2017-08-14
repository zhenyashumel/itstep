#include<iostream>
#include<algorithm>
#include <iterator>
#include<vector>

void print(std::vector<int> a)
{
	for (auto el : a)
		std::cout << el << " ";
	std::cout << std::endl;
}

int main()
{
	//0
	std::vector<int> vec;

	for (int i = 0; i < 20; ++i)
		vec.push_back(i);

	print(vec);

	//1

	std::replace_if(vec.begin(), vec.end(), [](const int& value) {return value % 10 == 0; }, 11);

	print(vec);

	//2
	std::sort(vec.begin(), vec.end(), [](int cur, int next) {return cur > next; });

	print(vec);

	//3
	const int v = 7;
	const int n = 2;
	std::vector<int> vec1;
	std::back_insert_iterator<std::vector<int>> it(vec1);
	std::copy_if(vec.begin(), vec.end(), it, [&v, &n](const int& val) { return v * n < val; });

	print(vec1);

	//4

	const int x = 3;

	std::vector<int> vec2;
	std::back_insert_iterator<std::vector<int>> it1(vec2);

	std::transform(vec1.begin(), vec1.end(), it1, [&x](int& val) { return val += x; });

	print(vec2);	
}
