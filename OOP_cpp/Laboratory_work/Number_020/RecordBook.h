#pragma once
#include"Date.h"
#include<map>
#include<string>


class RecordBook
{
	std::map<std::string, int> book;
	int min;
	int max;

public:
	RecordBook();
	
	void print() const;
	void setPair(std::string, int);
	void init();

	double getAverage() const;
	std::pair <std::string, int> getMin() const;
	std::pair <std::string, int> getMax() const;
};
