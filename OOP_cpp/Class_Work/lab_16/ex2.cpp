#include<iostream>
#include<set>
#include<fstream>
#include<string>

void work()
{
	std::ifstream in("input.txt");
	if (!in.is_open())
	{
		std::cout << "Error!!!";
		return;
	}
	std::multiset<int> input;

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
		out << temp << ":  "<< input.count(temp)<<std::endl;
			
	
	
	in.close();
	out.close();
	
}

int main()
{
	
	work();

	return 0;
}
