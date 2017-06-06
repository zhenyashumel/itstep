#include"MyVector.h"
size_t MyVector::counterVector = 0;
size_t MyVector:: counterMaxVector = 0;
bool MyVector::empty()
{
	return size == 0;

}

MyVector::MyVector(double arr1[], int size1) :size(size1)
{
	++counterVector;
	++counterMaxVector;
	int counter = size1 / 32;

	arr = new double[(counter + 1) * 32];
	capacity = 32 * (counter+1);

	for (unsigned int i = 0; i < size; ++i)
		arr[i] = arr1[i];

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
	if (size < capacity) arr[size++] = value;
	else
	{
		double *arr1 = new double[capacity * 2];
		capacity *= 2;
		for (unsigned int i = 0; i < size; i++)
			arr1[i] = arr[i];
		delete[]arr;
		arr = arr1;
		arr[size] = value;
		size = size + 1;
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
	for (unsigned int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

MyVector::MyVector(MyVector && myObj) :size(myObj.size), capacity(myObj.capacity), arr(myObj.arr)
{

	myObj.size = 0;
	myObj.capacity = 0;
	myObj.arr = nullptr;
	++counterVector;
	++counterMaxVector;


}
MyVector::MyVector(const MyVector & myObj) :size(myObj.size), capacity(myObj.capacity)
{
	arr = new double[myObj.capacity];
	for (unsigned int i = 0; i < size; ++i)
	{
		arr[i] = myObj.arr[i];
	}
	++counterVector;
	++counterMaxVector;

}

double MyVector::get_min()const
{
	if (!size)
	{
		std::cout << "Vector is empty!!!" << std::endl;
		return 0;
	}
	double min = arr[0];
	for (unsigned int i = 0; i < size; i++)
		if (arr[i] < min) min = arr[i];
	return min;
}

double MyVector::get_max()const
{

	if (!size)
	{
		std::cout << "Vector is empty!!!" << std::endl;
		return 0;
	}
	double max = arr[0];
	for (unsigned int i = 0; i < size; i++)
		if (arr[i]>max) max = arr[i];
	return max;
}

void MyVector::sort()
{
	for (int d = size / 2; d > 0; d /= 2)
	{
		for (unsigned int i = d, j; i < size; i++)
		{
			double temp = arr[i];
			for (j = i; j >= d; j -= d)
			{
				if (temp < arr[j - d])
					arr[j] = arr[j - d];
				else break;
			}
			arr[j] = temp;
		}
	}
}
