#pragma once
#include<iostream>
template<typename T,typename U>
class Pair
{
	T first;
	U second;
public:
	Pair() = default;
	Pair(const T a, const U b);
	
	~Pair()=default;

	T getFirst() const;	

	U getSecond() const;
	
	
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
