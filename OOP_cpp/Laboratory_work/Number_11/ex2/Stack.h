#pragma once
#include<iostream>

template<typename T>
class Stack
{
	T *stack;
	size_t size;
	size_t capacity;
public:

	Stack();
	Stack(const Stack &obj);
	Stack(Stack &&obj);
	~Stack();
	
	Stack& operator=(const Stack &obj);
	Stack& operator=(Stack &&obj);
	
	bool empty() const;	
	size_t getSize() const;	
	void push(const T value);
	void pop();
	T top() const;	
	
	bool operator==(const Stack obj);
	bool operator!=(const Stack obj);

};


template<typename T>
T Stack<T>::top() const
{
	//std::cout << stack[size-1];
	return stack[size - 1];
}

template<typename T>
size_t Stack<T>:: getSize() const
{
	return size;
}

template<typename T>
bool Stack<T>:: empty() const
{
	return size == 0;
}

template<typename T>
Stack<T>::~Stack()
{
	delete[]stack;
}

template<typename T>
Stack<T>::Stack() :size(0), capacity(32)
{
	stack = new T[capacity];
}

template<typename T>
Stack<T>::Stack(const Stack &obj): size(obj.size), capacity(obj.capacity)
{
	stack = new T[capacity];
	for (size_t i = 0; i < size; ++i)
		stack[i] = obj.stack[i];
}

template<typename T>
Stack<T>::Stack(Stack &&obj) : size(obj.size), capacity(obj.capacity)
{
	stack = obj.stack;
	obj.size = 0;
	obj.capacity = 0;
	obj.stack = nullptr;
}


template<typename T>
void Stack<T>::push(const T value)
{
	if (size < capacity)
	{
		stack[size] = value;
		++size;
	}

	else
	{
		T *arr = new T[capacity * 2];
		capacity *= 2;

		for (size_t i = 0; i < size; ++i)
			arr[i] = stack[i];

		delete[]stack;
		stack = arr;
		stack[size] = value;
		++size;

	}
}

template<typename T>
void Stack<T>::pop()
{
	stack[size] = 0;
	--size;
}


template<typename T>
Stack<T>& Stack<T>::operator=(const Stack &obj)
{
	if (&obj == this)
		return *this;

	size = obj.size;
	capacity = obj.capacity;
	stack = new T[obj.capacity];
	for (size_t i = 0; i < size; ++i)
		stack[i] = obj.stack[i];

	return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack &&obj)
{
	if (&obj == this)
		return *this;
	size = obj.size;
	capacity = obj.capacity;
	stack = obj.stack;
	obj.size = 0;
	obj.capacity = 0;
	obj.stack = nullptr;
	return *this;
}

template<typename T>
bool Stack<T>::operator==(const Stack obj)
{
	if (size != obj.size)
		return false;

	for (size_t i = 0; i < size; ++i)
		if (stack[i] != obj.stack[i])
			return false;
	return true;

}

template<typename T>
bool Stack<T>::operator!=(const Stack obj)
{
	if (!operator==(obj))
		return true;
	return false;
}
