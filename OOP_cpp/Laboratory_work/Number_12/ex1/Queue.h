#ifndef __QUEUE_H__
#define __QUEUE_H__
#include<iostream>
template <class T>
class Queue
{
	T* data;
	size_t tail;
	size_t capacity;
public:
	Queue();
	Queue(const Queue<T>&);
	Queue(Queue<T>&&);
	Queue& operator=(const Queue<T>&);
	Queue& operator=(Queue<T>&&);
	~Queue();

	size_t size() const;
	bool empty() const;
	void clear();

	void push(const T&);
	void pop();
	T& back();
	T& front();

};




template<typename T>
Queue<T>::Queue() :tail(0), capacity(2)
{
	data = new T[capacity];
};

template<typename T>
Queue<T>::Queue(const Queue<T>&obj)
{
	tail = obj.tail;
	capacity = obj.capacity;
	data = new T[capacity];
	for (int i = 0; i < tail; ++i)
		data[i] = obj.data[i];
}

template<typename T>
Queue<T>::Queue(Queue<T> &&obj):tail(obj.tail),capacity(obj.capacity),data(obj.data)
{
	obj.data = nullptr;
	obj.tail = 0;
	obj.capacity = 0;
}

template<typename T>
Queue<T>& Queue<T>:: operator=(const Queue<T> &obj)
{
	tail = obj.tail;
	capacity = obj.capacity;
	data = new T[capacity];
	for (int i = 0; i < tail; ++i)
		data[i] = obj.data[i];
	return *this;
}

template<typename T>
Queue<T>& Queue<T>:: operator=(Queue<T> &&obj)
{
	tail = obj.tail;
	capacity = obj.capacity;
	data = obj.data;
	obj.data = nullptr;
	obj.tail = 0;
	obj.capacity = 0;
	return *this;
}

template<typename T>
Queue<T>::~Queue()
{
	delete[]data;
}

template<typename T>
size_t Queue<T>:: size() const
{
	return tail;
}

template<typename T>
bool Queue<T>::empty() const
{
	return tail == 0;
}

template<typename T>
void Queue<T>::clear()
{
	tail = 0;
}

template<typename T>
void Queue<T>::push(const T& value)
{
	if (tail < capacity)
	{
		data[tail] = value;
		++tail;
	}

	else
	{
		T *arr = new T[capacity * 2];
		capacity *= 2;

		for (size_t i = 0; i < tail; ++i)
			arr[i] = data[i];

		delete[]data;
		data = arr;
		data[tail] = value;
		++tail;

	}
}

template<typename T>
void Queue<T>::pop()
{
	for (size_t i = 0; i < tail - 1; ++i)
		data[i] = data[i + 1];
	--tail;	
}

template<typename T>
T& Queue<T>::back()
{
	return data[tail - 1];
}

template<typename T>
T& Queue<T>::front()
{
	return data[0];
}

#endif /* __QUEUE_H__ */
