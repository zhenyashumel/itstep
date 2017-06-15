#pragma once
#include<iostream>

template<typename T>
class MyVector
{
	T *arr;
	unsigned int size;
	unsigned int capacity = 32;
	static size_t counterVector;
	static size_t counterMaxVector;
public:
	MyVector() : capacity(32), size(0)
	{
		arr = new T[32];
		++counterVector;
		++counterMaxVector;

	}
	MyVector(T[], int);

	MyVector(const MyVector& myObj);

	MyVector(MyVector && myObj);


	~MyVector()
	{
		delete[] arr;
		counterVector -= 1;
	}
	bool empty();
	size_t get_size() const;
	unsigned int get_capacity() const;
	void push_back(T value);
	double pop_back();
	double& at(int index);
	void print();
	T get_min()const;
	T get_max()const;

	static size_t getCounterVector()
	{
		return counterVector;
	}

	static size_t getCounterMaxVector()
	{
		return counterMaxVector;
	}
	void sort();
	void insert(T value, size_t index);
	void resize(unsigned int value);

};


template<typename T>
size_t MyVector<T>::counterVector = 0;
template<typename T>
size_t MyVector<T>::counterMaxVector = 0;

template<typename T>
bool MyVector<T>::empty()
{
	return size == 0;

}

template<typename T>
MyVector<T>::MyVector(T arr1[], int size1) :size(size1)
{
	++counterVector;
	++counterMaxVector;
	int counter = size1 / 32;

	arr = new T[(counter + 1) * 32];
	capacity = 32 * (counter + 1);

	for (unsigned int i = 0; i < size; ++i)
		arr[i] = arr1[i];

}

template<typename T>
unsigned int MyVector<T>::get_size() const
{
	return size;
}

template<typename T>
unsigned int MyVector<T>::get_capacity() const
{
	return capacity;
}

template<typename T>
void MyVector<T>::push_back(T value)
{
	if (size < capacity) arr[size++] = value;
	else
	{
		T *arr1 = new T[capacity * 2];
		capacity *= 2;
		for (unsigned int i = 0; i < size; i++)
			arr1[i] = arr[i];
		delete[]arr;
		arr = arr1;
		arr[size] = value;
		size = size + 1;
	}

}

template<typename T>
double MyVector<T>::pop_back()
{
	if (!size)std::cout << "Vector is empty!!!";
	else --size;
	return arr[size];
}

template<typename T>
double& MyVector<T>::at(int index)
{
	return arr[index];

}

template<typename T>
void MyVector<T>::print()
{
	for (unsigned int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
MyVector<T>::MyVector(MyVector && myObj) :size(myObj.size), capacity(myObj.capacity), arr(myObj.arr)
{

	myObj.size = 0;
	myObj.capacity = 0;
	myObj.arr = nullptr;
	++counterVector;
	++counterMaxVector;


}

template<typename T>
MyVector<T>::MyVector(const MyVector & myObj) :size(myObj.size), capacity(myObj.capacity)
{
	arr = new T[myObj.capacity];
	for (unsigned int i = 0; i < size; ++i)
	{
		arr[i] = myObj.arr[i];
	}
	++counterVector;
	++counterMaxVector;

}

template<typename T>
T MyVector<T>::get_min()const
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

template<typename T>
T MyVector<T>::get_max()const
{

	if (!size)
	{
		std::cout << "Vector is empty!!!" << std::endl;
		return 0;
	}
	T max = arr[0];
	for (unsigned int i = 0; i < size; i++)
		if (arr[i]>max) max = arr[i];
	return max;
}

template<typename T>
void MyVector<T>::sort()
{
	for (int d = size / 2; d > 0; d /= 2)
	{
		for (unsigned int i = d, j; i < size; i++)
		{
			T temp = arr[i];
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

template<typename T>
void MyVector<T>::insert(T value, size_t index)
{
	if (index > size)
	{
		std::cout << "Oop... Error!!!\n";
		return;
	}
	if (size == capacity)
	{
		T *arr1 = new T[capacity * 2];
		capacity *= 2;
		for (unsigned int i = 0; i < size; i++)
			arr1[i] = arr[i];
		delete[]arr;
		arr = arr1;
		arr[size] = value;
		size = size + 1;
	}
	else if (index == size)
		push_back(value);

	else
	{
		T *arr1 = new T[capacity];
		for (unsigned int i = 0; i <=index; ++i)
			arr1[i] = arr[i];
		arr1[index + 1] = value;
		for (unsigned int i = index + 2; i < size; ++i)
			arr1[i] = arr[i - 1];
		arr = arr1;
		arr[size] = value;
		size = size + 1;
	}
	
}

template<typename T>
void MyVector<T>::resize(unsigned int value)
{
	if (value < size)
	{
		std::cout << "Oops... Error!!!\n";
		return;
	}

	if (value == capacity)
		return;


	T *arr1 = new T[value];
	capacity = value ;
	for (unsigned int i = 0; i < size; ++i)
		arr1[i] = arr[i];
	delete[]arr;
	arr = arr1;
	

}
