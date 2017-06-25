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

	std::string rank;
	std::string word;
	std::string count;

	while (in >> rank)
	{
		in >> word;
		in >> count;
		
		std::vector<std::string> data;
		data.push_back(word);
		data.push_back(count);

		dict.insert({ rank, data });
			
	}

}

void Dictionary::print()
{
	for (auto el : dict)
	{
		std::cout << el.first << "  " << el.second[0] << "  " << el.second[1] << std::endl;
		out += el.first + "  " + el.second[0] + "  " + el.second[1] + '\n';
	}
	out += '\n';
}

void Dictionary::bestWord()
{
	auto it = dict.find("1");
	std::cout << "Word: " << it->second[0]<<std::endl
		<<"Frequency: "<<it->second[1];

	out += "Word: " + it->second[0] + '\n' + "Frequency: " + it->second[1] + '\n';
}

void Dictionary::input(std::string fname)
{
	std::ifstream in(fname);

	if (!in.is_open())
	{
		std::cout << "Error connecting to file!!!\n";
		exit(1);
	}

	std::cout << "Connect!!! Read the dictionary..." << std::endl;

	std::string rank;
	std::string word;
	std::string count;

	while (in >> rank)
	{
		in >> word;
		in >> count;

		std::vector<std::string> data;
		data.push_back(word);
		data.push_back(count);

		dict.insert({ rank, data });

	}
}

void Dictionary::write()
{
	std::ofstream fout("output.txt");
	fout << out;

}
