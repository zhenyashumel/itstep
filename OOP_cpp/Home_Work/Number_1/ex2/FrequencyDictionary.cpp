#include "FrequencyDictionary.h"
#include<vector>


FrequencyDictionary::FrequencyDictionary(std::string fname)
{
	std::ifstream in(fname);

	if (!in.is_open())
	{
		std::cout << "Error connecting to file!!!\n";
		exit(1);
	}

	std::cout << "Соеденение прошло успешно!!! Считываем словарь..." << std::endl;

	int rank;
	data tmp;

	while (in >> rank)
	{
		in >> tmp.word;
		in >> tmp.PartOfSpeech;
		in >> tmp.mill;
		in >> tmp.frequency1;
		in >> tmp.frequency2;
		in >> tmp.frequency3;
		in >> tmp.frequency4;
		in >> tmp.frequency5;
		in >> tmp.frequency6;

		dict[rank] = tmp;

	}
	std::cout << "Готово!!!" << std::endl;
}


void  FrequencyDictionary::getMin() const
{
	std::ofstream out("Min.txt");
	auto it = --dict.end();
	std::cout <<it->second.word<<std::endl;
	out << it->second.word;
}


void FrequencyDictionary::getMax() const
{
	std::ofstream out("Max.txt");
	auto it = dict.begin();
	std::cout << it->second.word << std::endl;
	out << it->second.word;
}
	

void FrequencyDictionary::wordOfRank(const int rank) const
{
	
	std::ofstream out("WordOfRank.txt");
	auto it = dict.find(rank);
	std::cout << it->second.word;
	out << it->second.word;
}


void FrequencyDictionary::rankOfWord(const std::string word) const
{
	std::ofstream out("rankOfWord.txt");
	for(auto el:dict)
		if (el.second.word == word)
		{
			out << "Ранг: " << el.first<<"Частота:  " << "  " << el.second.mill;
			return;
		}
	std::cout << "Такого слова нет!!!\n";

}


void FrequencyDictionary::wordInRange(const int begin, const int end) const
{
	std::ofstream out("wordInRange.txt");
	for (auto el : dict)
	{
		if (el.first >= begin && el.first <= end)
			out << el.second.word << std::endl;
		if (el.first > end)
			return;
	}
}


void FrequencyDictionary::partOfSpeech(const std::string part) const
{
	std::ofstream out("wordInRange.txt");
	for (auto el : dict)
	{
		if (el.second.PartOfSpeech == part)
			out << "Ранг: " << el.first << " Частота: " << el.second.mill << " Слово: " << el.second.word << std::endl;
	}
}


void FrequencyDictionary::partInRange(const std::string part, const int range) const
{
	std::ofstream out("partInRange.txt");
	for (auto el : dict)
	{
		if (el.second.PartOfSpeech == part && el.second.mill >= range)
			out << el.second.word << std::endl;
		if (el.second.mill <= range)
			return; 
	}
}


void FrequencyDictionary::statistics() const
{
	std::ofstream out("statistics.txt");
	std::map<std::string, std::vector<double>> tmp;
	std::vector<double> temp;
	temp.push_back(0);
	temp.push_back(0);

	for (auto el : dict)
	{
		if (!tmp.count(el.second.PartOfSpeech))
		{
			temp[0] = 1;
			temp[1] = el.second.mill;
			tmp.insert({ el.second.PartOfSpeech, temp });
		}
		else
		{
			temp[0] = tmp.find(el.second.PartOfSpeech)->second[0] + 1;
			temp[1] = tmp.find(el.second.PartOfSpeech)->second[1] + el.second.mill;
			tmp[el.second.PartOfSpeech] = temp;
		}
	}
	for (auto el : tmp)
	{
		el.second[1] = el.second[1] / el.second[0];
		out << "Часть речи: " << el.first << "\nКоличество: " << el.second[0] << "\nСредняя частота: " << el.second[1] << std::endl;
		out << std::endl;
	}
}
