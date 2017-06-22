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
	std::ofstream out("output.txt");
	while (in >> temp)
	{
		out << temp << ": ";
		if (input.count(temp))
			out << "Yes" << std::endl;
		else
			out << "No" << std::endl;
			
	}
	in.close();
	out.close();
	
}

int main()
{
	setlocale(0,"");
	work();

	return 0;
}
