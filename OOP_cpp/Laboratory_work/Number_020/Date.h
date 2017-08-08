#pragma once

class Date
{
	int day;
	int month;
	int year;

public:
	explicit Date(int, int, int);
	explicit Date(int, int);
	explicit Date(int);

	Date(const Date& obj);

	void defaultDate();
	
	void plusYear(int);
	void plusMonth(int);
	void plusDay(int);


	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	void getDate() const;
};
