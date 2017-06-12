#pragma once
#include<iostream>
#include<fstream>
#include<string>

class Printer
{
	std::string model;
	size_t date;
	std::string manufacturer;
	std::string *str;
	size_t counter = 0;
	static size_t maxCounter;

public:
	Printer(std::string mod, size_t dat, std::string man) :model(mod), date(dat), manufacturer(man)
	{
		++counter;
		++maxCounter;
	}

	void printCopy();
	void printCharsWithStep(int n);
	void printWordsWithStep(int n);
	void printReverse();
	void printСoncordance(std::string);

	void getInfo();

	size_t getCounter()
	{
		return counter;
	}
	static size_t getMaxCounter()
	{
		return maxCounter;
	}

};
