#include"RecordBook.h"
#include<iostream>




RecordBook::RecordBook(): book{ { "Algebra", 10 }, { "Literature", 10 }, { "Physics", 8 }, { "Biology", 9 }, 
{ "History", 6 }, { "Chemistry", 10 }, { "Computer science", 10 },{ "Geography", 7 }, { "Geometry", 9 }, { "Mathematics", 3 } }

{
	
}


void RecordBook::print() const
{
	for (auto el : book)
		std::cout << el.first << ": " << el.second<<std::endl;
}



void RecordBook::setPair(std::string name , int mark)
{
	book.insert({ name, mark });
}


void RecordBook::init()
{
	for (auto &el : book)
	{
		std::cout << el.first << ": ";
		std::cin >> el.second;
	}
}


double RecordBook::getAverage() const
{
	double summ = 0;
	for (auto el : book)
		summ += el.second;

	return summ / book.size();
}


std::pair <std::string, int> RecordBook::getMin() const
{
	std::pair<std::string, int> temp;

	temp = *book.begin();
	for (auto el : book)
	{
		if (el.second < temp.second)
			temp = el;
	}

	return temp;
}


std::pair <std::string, int> RecordBook::getMax() const
{
	std::pair<std::string, int> temp;

	temp = *book.begin();
	for (auto el : book)
	{
		if (el.second > temp.second)
			temp = el;
	}

	return temp;
}
