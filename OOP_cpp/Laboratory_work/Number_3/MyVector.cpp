#include"MyVector.h"

bool MyVector::empty()
{
	return size == 0;

}

unsigned int MyVector::get_size() const
{
	return size;
}
unsigned int MyVector::get_capacity() const
{
	return capacity;
}

void MyVector::push_back(double value)
{
	if (size < capacity) arr[size++]=value;
	else
	{
		double *arr1 = new double[capacity *2];
		capacity *= 2;
		for (unsigned int i = 0; i < size; i++)
			arr1[i] = arr[i];
		delete[]arr;
		arr = arr1;
		arr[size] = value;
		size=size+1;
	}
	
}

double MyVector::pop_back()
{
	if (!size)std::cout << "Vector is empty!!!";
	else --size;
	return arr[size];
}

double& MyVector::at(int index)
{
	return arr[index];
	
}

void MyVector::print()
{
	for(unsigned int i = 0; i < size; ++i)
	{
		std::cout << arr[i]<<" ";
	}
}
