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
	float img = (m1.img*m2.real) + (m1.real * m2.img);
	return Complex(real, img);
}
std::ostream& operator<<(std::ostream& os, const Complex&m1)
{
	if (m1.real == 0)
		os << m1.img << "i";
	else if (m1.img == 0)
		os << m1.real;
	else if(m1.img>0)
		os << m1.real<<"+"<< m1.img << "i";
	else 
		os << m1.real << m1.img << "i";
	return os;
}

std::istream& operator>>(std::istream& os,  Complex& m1)
{
	os >> m1.real;
	os >> m1.img;
	return os;
}


Complex operator/(const Complex& m1, const Complex& m2)
{
	float real = ((m1.real*m2.real) + (m1.img*m2.img)) / ((m2.real*m2.real) + (m2.img*m2.img));
	float img =((m1.img*m2.real) - (m1.real*m2.img))/ ((m2.real*m2.real) + (m2.img*m2.img));
	return Complex(real, img);
}

Complex& Complex::operator+=(const Complex& m1)
{
	real += m1.real;
	img += m1.img;
	return *this;
}

Complex& Complex::operator-=(const Complex& m1)
{
	real -= m1.real;
	img -= m1.img;
	return *this;
}

Complex& Complex::operator/=(const Complex& m1)
{
	*this = *this/m1;
	return *this;
}

Complex& Complex::operator*=(const Complex& m1)
{
	*this=*this*m1;
	return *this;
}

bool operator==(const Complex& m1, const Complex& m2)
{
	if (m1.real == m2.real && m1.img == m2.img)
		return true;
	return false;
}

bool operator!=(const Complex& m1, const Complex& m2)
{
	if (!operator==(m1, m2))
		return true;
	return false;
}

void Complex::operator()(float a, float b)
{
	real = a;
	img = b;
}

Complex operator+(float a, const Complex& m1)
{
	return Complex(m1.real + a, m1.img);
}

Complex operator-(float a, const Complex& m1)
{
	return Complex(m1.real - a, m1.img);
}

Complex operator/(float a, const Complex& m1)
{
	return Complex(m1.real / a, m1.img);
}

Complex operator*(float a, const Complex& m1)
{
	return Complex(m1.real * a, m1.img);
}

Complex operator+(const Complex& m1, float a)
{
	return Complex(m1.real + a, m1.img);
}

Complex operator-(const Complex& m1, float a)
{
	return Complex(m1.real - a, m1.img);
}

Complex operator/(const Complex& m1, float a)
{
	return Complex(m1.real / a, m1.img);
}

Complex operator*(const Complex& m1, float a)
{
	return Complex(m1.real * a, m1.img);
}

Complex& Complex::operator++()
{
	++real;
	++img;
	return *this;
}
Complex operator++(Complex &m1, int)
{
	Complex tmp=m1;
	++tmp.real;
	++tmp.img;
	return tmp;
}
Complex& Complex::operator--()
{
	--real;
	--img;
	return *this;

}
Complex operator--(Complex &m1, int)
{
	Complex tmp=m1;
	tmp.real--;
	tmp.img--;
	return tmp;
}

