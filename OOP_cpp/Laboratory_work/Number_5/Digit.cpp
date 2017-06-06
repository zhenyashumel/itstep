#include"Digit.h"
size_t Digit::counter = 0;
Digit Digit::operator+(const Digit newDigit)
{
	Digit temp;
	temp.digit = digit + newDigit.digit;
	return temp;
}

Digit Digit::operator+(int value)
{
	Digit temp;
	temp.digit = digit + value;
	return temp;
}

Digit Digit:: operator-(const Digit newDigit)
{
	Digit temp;
	temp.digit = digit - newDigit.digit;
	return temp;
}

Digit Digit::operator-(int value)
{
	Digit temp;
	temp.digit = digit - value;
	return temp;
}

Digit Digit::operator*(const Digit newDigit)
{
	Digit temp;
	temp.digit = digit * newDigit.digit;
	return temp;
}

Digit Digit::operator*(int value)
{
	Digit temp;
	temp.digit = digit * value;
	return temp;
}

Digit Digit::operator/(const Digit newDigit)
{
	Digit temp;
	temp.digit = digit / newDigit.digit;
	return temp;
}

Digit Digit::operator/(int value)
{
	Digit temp;
	temp.digit = digit / value;
	return temp;
}

Digit Digit::operator%(const Digit newDigit)
{
	Digit temp;
	temp.digit = digit % newDigit.digit;
	return temp;
}

Digit Digit::operator%(int value)
{
	Digit temp;
	temp.digit = digit % value;
	return temp;
}


bool Digit:: operator >(const Digit newDigit)
{
	return digit > newDigit.digit;
}

bool Digit:: operator <(const Digit newDigit)
{
	return digit < newDigit.digit;
}

bool Digit::operator ==(const Digit newDigit)
{
	return digit == newDigit.digit;
}

bool Digit::operator !=(const Digit newDigit)
{
	return digit != newDigit.digit;
}

bool Digit:: operator >=(const Digit newDigit)
{
	return digit >= newDigit.digit;
}

bool Digit::operator <=(const Digit newDigit)
{
	return digit <= newDigit.digit;
}



Digit Digit::operator++(int)
{
	Digit tmp = *this;
	digit++;
	return tmp;

}

Digit Digit::operator--(int)
{
	Digit tmp = *this;
	digit--;
	return tmp;
}

Digit& Digit::operator++()
{
	++digit;
	return *this;

}

Digit& Digit::operator--()
{
	--digit;
	return *this;
}


Digit& Digit::operator=(const Digit& newDigit)
{
	if (this == &newDigit)
		return *this;
	digit = newDigit.digit;
	return *this;
}

Digit& Digit::operator=(Digit&& newDigit)
{
	if (this == &newDigit)
		return *this;
	digit = newDigit.digit;
	newDigit.digit = 0;
	return *this;
}
