#include<iostream>
#pragma once
class MyVector
{
	double *arr;
	unsigned int size;
	unsigned int capacity = 32;
	static size_t counterVector;
	static size_t counterMaxVector ;
public:
	MyVector() : capacity(32), size(0)
	{
		arr = new double[32];
		++counterVector;
		++counterMaxVector;

	}
	MyVector(double[], int);

	MyVector(const MyVector& myObj);

	MyVector(MyVector && myObj);


	~MyVector()
	{
		delete[] arr;
		counterVector-=1;
	}
	bool empty();
	size_t get_size() const;
	unsigned int get_capacity() const;
	void push_back(double value);
	double pop_back();
	double& at(int index);
	void print();
	double get_min()const ;
	double get_max()const ;
	size_t getCounterVector()
	{
		return counterVector;
	}

	size_t getCounterMaxVector()
	{
		return counterMaxVector;
	}
	void sort();

}; 
size_t MyVector counterVector=0;
size_t MyVector counterMaxVector=0 ;
