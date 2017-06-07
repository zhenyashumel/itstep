#pragma once
#include<iostream>

class Complex
{
	float real;
	float img;
public:
	Complex() :real(0), img(0) {};
	Complex(const float a,const float b) :real(a), img(b) {};
	Complex(const Complex &m1) :real(m1.real), img(m1.img) {};
	Complex& operator=(const Complex& m1);	
	~Complex() = default;
	friend Complex operator+(const Complex& m1, const Complex& m2);
	friend Complex operator-(const Complex& m1, const Complex& m2);
	friend Complex operator/(const Complex& m1,const Complex& m2);
	friend Complex operator*(const Complex& m1, const Complex& m2);
	friend std::ostream& operator<<(std::ostream&, const Complex&);



};
