#include<iostream>
#include<list>

void work()
{
	std::list<int> lt;

	for (int i = 13, j = 0; j < 20; ++j, i += 13)
		lt.push_back(i);
	std::cout << "Size: " << lt.size() << std::endl;

	for (auto el : lt)
		std::cout << el << " ";
	std:: cout << std::endl;

	int sum = 0;
	for (auto el : lt)
		sum += el;
	sum /= lt.size();

	lt.push_front(sum);
	lt.remove(130);

	auto it = lt.begin();
	for (int i = 0; i < 9; ++i)
		++it;
	*it *= 3;
	
	lt.pop_back();
	

	auto it1 = --(lt.end());
	int i = *it1;
	--(--it1);	
	i += *it1;

	std::cout << i << std::endl;
	*(++it1) = i;

	
	// Ошибку искать здесь. Не все в конце удаляется
	auto it2 = lt.begin();
	++(++it2);
	for (int i = 3; i < lt.size(); ++i)
	{
		if (i % 3 == 0)
			lt.erase(it2++);
		else
			++it2;
	}


	for (auto el : lt)
		std::cout << el << " ";
	std::cout << std::endl;

	lt.push_back(70);
	for (auto el : lt)
		std::cout << el << " ";
	std::cout << std::endl;
	int sum1 = 0;
	for (auto el : lt)
		sum1 += el;
	std::cout << sum1;
	
}

int main()
{
	setlocale(0,"");
	work();

	return 0;
}
