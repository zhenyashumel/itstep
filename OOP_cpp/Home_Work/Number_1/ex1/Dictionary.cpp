#include"Dictionary.h"

Dictionary::Dictionary(std::string fname)
{
	std::ifstream in(fname);

	if (!in.is_open())
	{
		std::cout << "Error connecting to file!!!\n";
		exit(1);
	}

	std::cout << "Connect!!! Read the dictionary..." << std::endl;

	std::string word;
	while (in >> word)
	{
		
		if (word[word.length() - 1] == ',' || word[word.length() - 1] == '.' || word[word.length() - 1] == ':' || word[word.length() - 1] == ';')
			word.erase(word.length() - 1);
		
		if (isupper(word[0]))
			word[0] = tolower(word[0]);

		if (dict.count(word) == 0)
			dict.insert({ word, 1 });
		else
			dict[word] = dict[word] + 1;	

	}

}

void Dictionary::print()
{
	for (auto el : dict)
	{
		std::cout << el.first << "  " << el.second << std::endl;
		out += el.first + "  " + char(el.second) + '\n';
	}
	out += '\n';
}

void Dictionary::bestWord()
{
	std::pair<std::string, int> max = *dict.begin();

	for (auto el : dict)
	{
		if (el.second > max.second)
			max = el;
	}

	std::cout << max.first << " " << max.second;
}



void Dictionary::write()
{
	std::ofstream fout("output.txt");
	fout << out;

}
