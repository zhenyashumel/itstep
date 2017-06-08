#pragma once
#include<iostream>

class Complex
{
	float real;
	float img;
public:
	Complex() :real(0), img(0) {};

	Complex(const float a, const float b) :real(a), img(b) {};

	Complex(const Complex &m1) :real(m1.real), img(m1.img) {};

	Complex& operator=(const Complex& m1);

	~Complex() = default;


	friend Complex operator+(const Complex& m1, const Complex& m2);
	friend Complex operator-(const Complex& m1, const Complex& m2);
	friend Complex operator/(const Complex& m1, const Complex& m2);
	friend Complex operator*(const Complex& m1, const Complex& m2);
	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);

	Complex& operator+=(const Complex& m1);
	Complex& operator-=(const Complex& m1);
	Complex& operator/=(const Complex& m1);
	Complex& operator*=(const Complex& m1);

	void operator()(float a, float b);

	friend bool operator==(const Complex& m1, const Complex& m2);
	friend bool operator!=(const Complex& m1, const Complex& m2);
	
	friend Complex operator+(float a, const Complex& m1);
	friend Complex operator-(float a, const Complex& m1);
	friend Complex operator/(float a, const Complex& m1);
	friend Complex operator*(float a, const Complex& m1);

	friend Complex operator+(const Complex& m1, float a);
	friend Complex operator-(const Complex& m1, float a);
	friend Complex operator/(const Complex& m1, float a);
	friend Complex operator*(const Complex& m1, float a);

	Complex& operator++();
	friend Complex operator++(Complex &m1, int);
	Complex& operator--();
	friend Complex operator--(Complex &m1, int);
	
	float getReal()
	{
		return real;
	}

	float getImg()
	{
		return img;
	}
};
