#include"function.h"


void Init(double mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() * 1.123;
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
	cout << endl << endl;
}
void Print(int mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl << endl;
}
void Print(char mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl << endl;
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
	char max = 0;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] > max)max = mass[i];
	}
	return max;
}






void Sort(double *A, int size)
{
	for (int d = size / 2; d > 0; d /= 2)
	{
		for (int i = d, j; i < size; i++)
		{
			double temp = A[i];
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
void Sort(int *A, int size)
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
void Sort(char *A, int size)
{
	for (int d = size / 2; d > 0; d /= 2)
	{
		for (int i = d, j; i < size; i++)
		{
			char temp = A[i];
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





void Red(double *mass, int size, int index, int value)
{
	if (index >= size)
	{
		cout << "Incorrect index";
		return;
	}
	mass[index] = value;

}
void Red(int *mass, int size, int index, int value)
{
	if (index >= size)
	{
		cout << "Incorrect index";
		return;
	}
	mass[index] = value;

}
void Red(char *mass, int size, int index, int value)
{
	if (index >= size)
	{
		cout << "Incorrect index";
		return;
	}
	mass[index] = value;

}

