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
		mass[i] = (char)rand() %256;
	}
}


void Print(double mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << mass[i]<<" ";
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


void Min(double mass[], int size);
void Min(int mass[], int size);
void Min(char mass[], int size);


void Max(double mass[], int size);
void Max(int mass[], int size);
void Max(char mass[], int size);


void Sort(double mass[], int size);
void Sort(int mass[], int size);
void Sort(char mass[], int size);


void Red(double mass[], int size, int index);
void Red(int mass[], int size, int index);
void Red(char mass[], int size, int index);
