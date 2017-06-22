#include<iostream>
#include<set>
#include<fstream>

void work()
{
	std::ifstream in("input.txt");
	if (!in.is_open())
	{
		std::cout << "Error!!!";
		return;
	}
	std::set<int> input;

	int temp;
	while (in >> temp)
		input.insert(temp);

	in.close();
	in.clear();
	in.open("test.txt");
	if (!in.is_open())
	{
		std::cout << "Error!!!";
		return;
	}

	while (in >> temp)
	{
		std::cout << temp << ": ";
		if (input.count(temp))
			std::cout << "Yes" << std::endl;
		else
			std::cout << "No" << std::endl;
			
	}
	in.close();
	
}

int main()
{
	setlocale(0,"");
	work();

	return 0;
}
