#include"Printer.h"

size_t Printer::maxCounter = 0;
void Printer::printCopy()
{
	std::ifstream in("Input.txt");
	std::ofstream out("Output.txt");

	if (!in.is_open() || !out.is_open())
	{
		std::cout << "Error!!!" << std::endl;
		return;
	}
	char temp[256];
	while (in.getline(temp, 256))
	{

		out << temp;
		out << "\n";
	}
	++counter;
	++maxCounter;
	in.close();
	out.close();


}

void Printer::printCharsWithStep(int n)
{
	std::ifstream in("Input.txt");
	std::ofstream out("Output.txt");

	if (!in.is_open() || !out.is_open())
	{
		std::cout << "Error!!!" << std::endl;
		return;
	}

	char temp[1];
	int count = n - 1;
	while (in.seekg(count))
	{
		in.read(temp, 1);
		char tmp = temp[0];
		out.put(tmp);
		out << " ";

		count += n;

	}
	++counter;
	++maxCounter;

	in.close();
	out.close();


}

void Printer::printWordsWithStep(int n)
{
	std::ifstream in("Input.txt");
	std::ofstream out("Output.txt");

	if (!in.is_open() || !out.is_open())
	{
		std::cout << "Error!!!" << std::endl;
		return;
	}
	std::string temp;
	int count = 0;
	while (in >> temp)
		++count;
	in.clear();
	in.seekg(0);

	str = new std::string[count];
	for (int i = 0; i < count; ++i)
		in >> str[i];

	for (int i = 0; i < count; ++i)
	{
		if (i%n == 0)
		{
			out << str[i];
			out << " ";
		}
	}
	in.close();
	out.close();

}

void Printer::printReverse()
{
	std::ifstream in("Input.txt");
	std::ofstream out("Text.txt");

	if (!in.is_open() || !out.is_open())
	{
		std::cout << "Error!!!" << std::endl;
		return;
	}
	int count = -1;
	char temp[1];
	while (in.seekg(count, std::ios_base::end))
	{
		in.read(temp, 1);
		char tmp = temp[0];
		out.put(tmp);
		--count;
	}

}

void Printer::printСoncordance(std::string word)
{
	std::ifstream in("Input.txt");
	std::ofstream out("Text.txt");

	if (!in.is_open() || !out.is_open())
	{
		std::cout << "Error!!!" << std::endl;
		return;
	}
	std::string temp;
	int count = 0;
	while (in >> temp)
		++count;
	in.clear();
	in.seekg(0);

	str = new std::string[count];
	for (int i = 0; i < count; ++i)
		in >> str[i];
	
	int search_index;
	bool search = false;
	for (int i = 0; i < count; ++i)
	{
		if (str[i] == word)
		{
			search = true;
			search_index = i;
		}
	}

	if (!search)//если слово не найдено
	{
		std::cout << "Word not found!!!" << std::endl;
		return;
	}
	if (count < 7)//если предложение маленькое
	{
		for (int i = 0; i < count; ++i)
			out << str[i]<<" ";
	}


	else if (search_index<4)//если слово где-то вначале
	{
		for (int i = 0; i < search_index+4; ++i)
			out << str[i]<<" ";

		
			
		
	}
	else if (count - search_index<3)//если слово где-то в конце
	{
		int index = count - search_index;//сколько слов мы можем вывести справа
		out << str[search_index - 3] << " " << str[search_index - 2] << " " << str[search_index - 1] << " ";
		for (int i = 0,j=search_index; i <= index; ++i,j++)
		{
			out << str[j]<<" ";
		}

	}
	else 
	{
		out << str[search_index - 3] << " " << str[search_index - 2] << " " << str[search_index - 1] << " ";
		out << str[search_index] << " ";
		out << str[search_index + 1] << " " << str[search_index + 2] << " " << str[search_index + 3];
	}

	


}

void Printer::getInfo()
{
	std::cout << "Some information about your printer: \n";
	std::cout << "Model:         " << model << std::endl;
	std::cout << "Date:          " << date << std::endl;
	std::cout << "Manufacturer:  " << manufacturer << std::endl;
}

