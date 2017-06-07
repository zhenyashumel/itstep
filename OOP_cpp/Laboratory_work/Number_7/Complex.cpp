#include"Complex.h"

Complex& Complex:: operator=(const Complex &m1)
{
	if (this == &m1)
		return *this;
	real = m1.real;
	img = m1.img;
	return *this;
		
}

Complex operator+(const Complex& m1, const Complex& m2)
{
	return Complex(m1.real + m2.real, m1.img + m2.img);
	
}

Complex operator-(const Complex& m1, const Complex& m2)
{
	return Complex(m1.real - m2.real, m1.img - m2.img);
}

Complex operator*(const Complex& m1, const Complex& m2)
{
	float real = (m1.real*m2.real) - (m1.img*m2.img);
	float img = (m1.img*m2.real) + (m1.real + m2.img);
	return Complex(real, img);
}
std::ostream& operator<<(std::ostream& os, const Complex&m1)
{
	char sign;
	m1.real > 0 ? os << m1.real << "+" << m1.img << "i": os << m1.real << m1.img << "i";	
	return os;
}

