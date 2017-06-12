#include<iostream>

template<typename T,typename U>
auto getMin(const T first, const U second)->decltype(first+second)
{
	return(first < second ? first : second);
}

template<typename T>
T getMax(const T arr[], int size)
{
	T max = arr[0];
	for (int i = 0; i < size; ++i)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

template<size_t size, typename T>
T getMax(const T *arr)
{
	T max = arr[0];
	for (size_t i = 0; i < size; ++i)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
template<typename T>
void sort(T *A, int size)
{
	for (int d = size / 2; d > 0; d /= 2)
	{
		for (int i = d, j; i < size; i++)
		{
			int temp = A[i];
			for (j = i; j >= d; j -= d)
			{
				if (temp < A[j - d])
					A[j] = A[j - d];
				else break;
			}
			A[j] = temp;
		}
	}
}


template<typename T>
T find(T *arr, int size,T value)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == value)
		{
			std::cout<<i;
			return i;
		}
	}
	std::cout << "Number not found!!" << std::endl;
	return 0;
}

template<typename T,typename U>
auto solve(T a, U b)->decltype(a + b)
{
	T arr2[2];
	if (a == 0)
	{
		arr2[0] = 0;
		return *arr2;
	}

		arr2[0] = 1;
		arr2[1] = (-b / a);
	return *arr2;
}
template<typename T>
auto solve(T a, T b, T c)->decltype(a+b+c)
{
	T d = (b*b) - 4 * a * c;
	if (d < 0)
		return 0;
	if (d == 0)
		return (-b / (2 * a))
	T x1 = (-b + sqrt(d)) / (2 * a);
	T x2 = (-b - sqrt(d)) / (2 * a);
}


