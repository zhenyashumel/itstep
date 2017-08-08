#include"Date.h"
#include <time.h>
#include<iostream>
#include<map>

Date::Date(int d, int m, int y): day(d), month(m), year(y)
{
}


Date::Date(int d, int m) : day(d), month(m)
{
	time_t t;
	tm *tk;

	time(&t);
	tk = localtime(&t);
	year = 1900 + tk->tm_year;
}


Date::Date(int d) : day(d)
{
	time_t t;
	tm *tk;

	time(&t);
	tk = localtime(&t);
	year = 1900 + tk->tm_year;
	month = 1 + tk->tm_mon;
}


Date::Date(const Date& obj): day(obj.day), month(obj.month), year(obj.year)
{
}


void Date::defaultDate()
{
	year = 2000;
	month = 1;
	day = 1;
}


void Date::plusYear(int value)
{
	year += value;
}


void Date::plusMonth(int value)
{
	while(value)
	{
		if (month == 12)
		{
			++year;
			month = 1;
		}
		else
			++month;
		--value;
	}
}


std::map<int , int> months = { { 1, 31 },{ 2, 28 },{ 3, 31 },{ 4, 30 },{ 5, 31 },
	{ 6, 30 },{ 7, 31 },{ 8, 31 },{ 9, 30 },{ 10, 31 },{ 11, 30 },{ 12, 31 } }; 


void Date::plusDay(int value)
{
	while (value)
	{
		if (day == months.find(month)->second)
		{
			if (month == 12)
			{
				++year;
				month = 1;
				day = 1;
			}
			else
			{
				++month;
				day = 1;
			}
		}
		else
		{
			++day;
		}
		--value;
	}
}


Date& Date::operator++()
{
	plusDay(1);
	return *this;
}


Date Date::operator++(int)
{
	Date tmp = *this;
	tmp.plusDay(1);
	return tmp;
	
}

Date& Date::operator--()
{
	if (day == 1)
	{
		if (month == 1)
		{
			--year;
			month = 12;
			day = 31;
		}
		else
		{
			--month;
			day = months.find(month)->second;
		}
	}
	else
	{
		--day;
	}
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	if (day == 1)
	{
		if (month == 1)
		{
			--year;
			month = 12;
			day = 31;
		}
		else
		{
			--month;
			day = months.find(month)->second;
		}
	}
	else
	{
		--day;
	}
	return tmp;
}

void Date::getDate() const
{
	std::cout << day << "." << month << "." << year;
}

