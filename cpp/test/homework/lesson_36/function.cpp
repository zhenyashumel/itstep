#include"function.h"


void Init(double mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() * 0, 001;
	}
}
void Init(int mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		mass[i] = rand();
	}
}
void Init(char mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		mass[i] = (char)rand() % 256;
	}
}


void Print(double mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
}
void Print(int mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
}
void Print(char mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
}


double Min(double mass[], int size)
{
	double min = mass[0];
	for (int i = 0; i < size; i++)
	{
		if (mass[i] < min) min = mass[i];
	}
	return min;
}
int Min(int mass[], int size)
{
	int min = mass[0];
	for (int i = 0; i < size; i++)
	{
		if (mass[i] < min) min = mass[i];
	}
	return min;
}
char Min(char mass[], int size)
{
	char min = mass[0];
	for (int i = 0; i < size; i++)
	{
		if (mass[i] < min) min = mass[i];
	}
	return min;
}


double Max(double mass[], int size)
{
	double max = 0;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] > max)max = mass[i];
	}
	return max;
}
int Max(int mass[], int size)
{
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] > max)max = mass[i];
	}
	return max;
}
char Max(char mass[], int size)
{
	double max = 0;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] > max)max = mass[i];
	}
	return max;
}


void Sort(double mass[], int size);
void Sort(int mass[], int size);
void Sort(char mass[], int size);


void Red(double mass[], int size, int index);
void Red(int mass[], int size, int index);
void Red(char mass[], int size, int index);
