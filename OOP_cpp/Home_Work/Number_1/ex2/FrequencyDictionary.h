#pragma once
#include<iostream>
#include<map>
#include<string>
#include<fstream>

struct data
{
	std::string word;
	std::string PartOfSpeech;
	double mill; //частота на миллион употреблений
	double frequency1;
	double frequency2;
	double frequency3;
	double frequency4;
	double frequency5;
	double frequency6;
	
};


class FrequencyDictionary
{
public:
	std::map<int, data> dict;
	
public:

	FrequencyDictionary(std::string = "dictionary.txt");
	~FrequencyDictionary() = default;

	void getMin() const;
	void getMax() const;
	void wordOfRank(int) const;
	void rankOfWord(const std::string) const;
	void wordInRange(const int, const int) const;
	void partOfSpeech(const std::string) const;
	void partInRange(const std::string, int) const;
	void statistics() const;
};

