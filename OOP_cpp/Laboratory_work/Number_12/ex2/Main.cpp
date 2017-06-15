#include"Queue.h"
#include<fstream>

void outPut(char str[],std::ofstream &out)
{
	Queue<char> words;
	Queue<char> numbers;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (!isdigit(str[i]))
			words.push(str[i]);
		else
			numbers.push(str[i]);
	}

	while (!words.empty())
	{
		out << words.front();
		words.pop();
	}

	while (!numbers.empty())
	{
		out << numbers.front();
		numbers.pop();
	}
	out << std::endl;
}

int main()
{
	std::ifstream in("Input.txt");
	std::ofstream out("Output.txt");
	char temp[265];
	int counter=0;
	char  tmp[256];
	while (in >> tmp)
		counter++;
	
	in.clear();
	in.seekg(0);
	for (int i = 0; i < counter; ++i)
	{
		in.getline(temp, 256);
		outPut(temp,out);
	}

	return 0;

	
	
}
