#include<iostream>

template<typename T, typename U>
auto getMin(const T first, const U second)->decltype(first + second)
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
T find(T *arr, int size, T value)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == value)
			return i;
		
	}
	std::cout << "Number not found!!" << std::endl;
	return 0;
}

template<typename T, typename U>
T* solve(T a, U b)
{
	T answer[2];
	if (a == 0)
	{
		answer[0] = 0;
		return answer;
	}

	answer[0] = 1;
	answer[1] = ((b*-1) / a);
	return answer;
	
}
template<typename T,typename U,typename X>
T* solve(T a,  U b, X c)
{
	T answer[3];
	auto d = (b*b) - 4 * a * c;
	if (d < 0)
	{
		answer[0] = 0;
		return answer;
	}
	if (d == 0)
	{
		answer[0] = 1;
		answer[1] = (-b / (2 * a));
		return answer;
	}
		
	answer[0] = 2;
	answer[1]= (-b + sqrt(d)) / (2 * a);
	answer[2]= (-b - sqrt(d)) / (2 * a);
	return answer;
}
