#include<iostream>
#include<tchar.h>
#include<fstream>
#include<string>

void work()
{
	std::ifstream in("Text.txt");
	if (!in.is_open())
	{
		std::cout << "Error!!!";
		return;
	}
	char* tmp = new char[256];

	std::wofstream out("Output.txt");
	if (!out.is_open())
	{
		std::cout << "Error!!!";
		return;
	}

	while (in.getline(tmp, 256))
	{
		size_t len = mbstowcs(NULL, tmp, 0) + 1;
		wchar_t* str = new wchar_t[len];
		mbstowcs(str, tmp, len);
		out << str;
		out << std::endl;
		delete[] str;

	}
	delete[] tmp;
	
}


int main()
{
	work();
}
