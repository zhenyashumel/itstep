#include<iostream>
#include<tchar.h>
#include<fstream>
#include<string>
#include<vector>

void work()
{
	std::wifstream in("Karatkevich.txt");
	if (!in.is_open())
	{
		std::cout << "Error!!!";
		return;
	}

	std::vector<std::wstring> text;

	std::wofstream out("Output.txt");
	if (!out.is_open())
	{
		std::cout << "Error!!!";
		return;
	}

	std::wstring tmp;
	while (in >> tmp)
	{
		text.push_back(tmp);
	}

	int max = 0;
	for (auto el : text)
	{
		if (el.size() > max)
			max = el.size();
	}

	out << "Самые длинные слова: длина " << max << std::endl;
	for (auto el : text)
	{
		if (el.size() == max)
			out << el << std::endl;
	}


}


int main()
{
	work();
}
