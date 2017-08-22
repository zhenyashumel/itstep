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
	 int counterMax = 0;
	out << "Самые длинные слова: длина " << max << std::endl;
	for (auto el : text)
	{
		if (el.size() == max)
		{
			out << el << std::endl;
			++counterMax;
		}
	}
	out << "Их количество: " << counterMax;

	out << std::endl << std::endl;


	int min = text.front().size();
	for (auto el : text)
	{
		if (el.size() < min)
			min = el.size();
	}

	int counterMin = 0;
	out << "Самые короткие слова: длина " << min << std::endl;
	for (auto el : text)
	{
		if (el.size() == min)
		{
			out << el << std::endl;
			++counterMin;
		}
	}
	out << "Их количество: " << counterMin << std::endl;


	int size = 0;
	int del = 0;
	for (auto el : text)
	{
		size += el.size();
		++del;
	}
	out << "Средняя длина слов: " << size / del;
}


int main()
{
	work();
}
