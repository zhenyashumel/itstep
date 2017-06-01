#include"Text.h"

void Text::function(int a, std::string name )
{
	std::ifstream filein(name);
	if (!filein.is_open())
		std::cout << "Error!!!" << std::endl;
	std::string temp;
	int counter = 0;
	while (filein >> temp)
	{
		++counter;
	}
	size = counter;
	str = new std::string[size];
	filein.clear();
	filein.seekg(0);
	int index = 0;
	
	
	if (a > counter || a < -1)
	{
		std::cout << "Oops... It seems you have entered too much value!!!" << std::endl;
		return;
	}
	else if(a==-1)
	{ 
		while (filein >> temp)
		{
			str[index] = temp;
			++index;
		}
	}
	else
	{
		for (int i = 0; i < a; ++i)
			filein >> str[i];
		
	}
	filein.close();
	
	
}

Text::Text()
{
	function(-1);

}

Text::Text(int a)
{
	function(a);
}

Text::Text(std::string name)
{
	function(-1,name);
}

Text::Text(std::string name, int a)
{
	function(a,name);
}

Text::Text(const Text& m1)
{
	size = m1.size;
	str = new std::string[m1.size];
	for (size_t i = 0; i < size; ++i)
		str[i] = m1.str[i];
}

Text::Text(Text&& m1)
{
	size = m1.size;
	str = m1.str;
	m1.str = nullptr;
	m1.size = 0;
	
}

Text::~Text()
{
	delete[]str;

}

size_t Text::get_max_len()const
{
	if (!size)
	{
		std::cout << "You did not connect to the file!!!" << std::endl;
		return 0;
	}
	size_t max = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (str[i].length() > max)
			max = str[i].length();
	}
	return max;


}

std::string Text::get_max_word()const
{
	
	if (!size)
	{
		std::cout << "You did not connect to the file!!!" << std::endl;
		return 0;
	}
	std::string max=str[0];
	for (size_t i = 0; i < size; i++)
	{
		
		if (str[i].length()>max.length())
			max = str[i];
	}

	return max;


}
