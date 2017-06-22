#include<iostream>
#include<set>
#include<map>
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
	std::multimap<int, int> mp;
	while (in >> temp)
		mp.insert({ input.count(temp), temp });

	std::set<int> temp1;
	std::ofstream out("output.txt");
	for (auto it = --mp.end(); it != --mp.begin(); --it)
	{
		if (!temp1.count(it->second))
		{
			out << it->second << "\t\t" << it->first << std::endl;
			temp1.insert(it->second);
		}
	}


	in.close();
	out.close();

}

int main()
{

	work();

	return 0;
}
