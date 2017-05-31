#pragma once
#include<iostream>

class MyVector
{
	double *arr;
	unsigned int size;
	unsigned int capacity=32;
public:
	MyVector(): capacity(32), size(0)
	{ 
		arr = new double[32];
	}

	MyVector(const MyVector& myObj);
	
	MyVector(MyVector && myObj);
	

	~MyVector()
	{
		delete[] arr;
	}
	bool empty();
	size_t get_size() const;
	unsigned int get_capacity() const;
	void push_back(double value);
	double pop_back();
	double& at(int index);
	void print();

};
