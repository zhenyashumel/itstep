#pragma once
#include<iostream>


template<typename T, typename U>
class Pair
{
	T first;
	U second;
public:
	Pair() = default;
	Pair(const T a, const U b);

	~Pair() = default;

	T getFirst() const;

	U getSecond() const;

	void  make_pair(T x, U y);

};

template<typename T, typename U>
T Pair<T, U>::getFirst() const
{
	return first;
}

template<typename T, typename U>
U Pair<T, U>::getSecond() const
{
	return second;
}

template<typename T, typename U>
Pair<T, U>::Pair(const T a, const U b) : first(a), second(b) {};


template<typename T, typename U>
void Pair<T, U>::make_pair(T x, U y)
{
	first = x;
	second = y;
}







template<>
class Pair<bool,bool>
{
	bool first;
	bool second;
public:
	Pair() = default;
	Pair(const bool a);

	~Pair() = default;

	bool getFirst() const;

	bool getSecond() const;

	void  make_pair(const bool x);

};


bool Pair<bool, bool>::getFirst() const
{
	return first;
}


bool Pair<bool, bool>::getSecond() const
{
	return second;
}


Pair<bool, bool>::Pair(const bool a) : first(a), second(a) {};


void Pair<bool, bool>::make_pair(const bool x)
{
	first = x;
	second = x;
}


