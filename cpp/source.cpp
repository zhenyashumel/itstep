#include<iostream>
#include<string>
bool checkStr(std::string string) {
	int index = 0;
	int open = 0, close = 0;
	bool exit = false;
	while (string[index] != '\0' && !exit) {

		switch (string[index])
		{
		case '(':
		{
			open++;
			break;
		}
		case ')':
		{
			close++;
			if (close > open) exit = true;
		}

		}
		index++;
	}
	return open == close ? true : false;
}

int main()
{
	std::string str;
	std::cout << "Input srting: ";
	std::cin >> str;	
	std::cout << (checkStr(str) ? "Yes" : "No") << std::endl;
	system("pause");
	return 0;
}

