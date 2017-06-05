#pragma once
#include<iostream>

class Digit
{
	int digit;
	static size_t counter;
public:
	Digit() :digit(0)
	{
		++counter;
	}
	explicit Digit(int x) :digit(x)
	{
		++counter;
	}
	Digit(double x) :digit((int)x)
	{
		++counter;
	}
	Digit(const Digit &m1) :digit(m1.digit) { ++counter; }
	Digit(Digit &&m1) :digit(m1.digit)
	{
		m1.digit = 0;
		++counter;

	}
	~Digit()
	{
		--counter;
	}

	int getDigit()
	{
		return digit;
	}
	void setDigit(int value)
	{
		digit = value;
	}
	static size_t getCounter()
	{
		return counter;
	}
	Digit operator-()
	{
		return -digit;
	}
	Digit operator+(const Digit newDigit);
	Digit operator+(int value);
	Digit operator-(const Digit newDigit);
	Digit operator-(int value);
	Digit operator*(const Digit newDigit);
	Digit operator*(int value);
	Digit operator/(const Digit newDigit);
	Digit operator/(int value);
	Digit operator%(const Digit newDigit);
	Digit operator%(int value);

	bool operator >(const Digit newDigit);
	bool operator <(const Digit newDigit);
	bool operator ==(const Digit newDigit);
	bool operator !=(const Digit newDigit);
	bool operator >=(const Digit newDigit);
	bool operator <=(const Digit newDigit);

	Digit operator++(int);
	Digit operator--(int);
	Digit& operator++();
	Digit& operator--();

	Digit &operator=(const Digit &newDigit);
	Digit &operator=(Digit &&newDigit);







};
