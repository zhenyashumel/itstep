#include<iostream>
#include<ctime>
using namespace std;


int *giveMemory(int *a, int size);
int *init(int *a, int size);
int *simple(int *a, int *size);
int *three(int *a, int *size);
int *even(int *a, int *size);
void printArray(int *arr, int count);
int*(*getfunptr(int*(*[])(int*, int*)))(int*, int*);
int* returnArray(int*, int*, int*(*)(int*, int*));

int main()
{
	srand((unsigned)time(0));
	int *(*functions[])(int *, int *) = { simple, three, even };

	int *arr = nullptr;
	int size;

	cout << "Enter the size of array: ";
	cin >> size;

	arr = giveMemory(arr, size);
	arr = init(arr, size);

	cout << "Source array: " << endl;
	printArray(arr, size);

	
	arr = returnArray(arr, &size, getfunptr(functions));
	printArray(arr, size);

	return 0;
}

int *giveMemory(int *a, int size)
{
	a = (int*)malloc(size * sizeof(int));
	return a;
}
int *init(int *a, int size)
{
	int *arr = nullptr;
	arr = giveMemory(arr, size);
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 99 + 1;
	}
	return arr;
}
int *simple(int *a, int *size)
{
	int *arr = nullptr;
	arr = giveMemory(arr, *size);
	int counter = 0;
	for (int i = 0; i < *size; i++)
	{
		bool flag = true;
		for (int j = 2; j < a[i] / 2; j++)
		{
			if (a[i] % j == 0)
			{
				flag = false;
				continue;
			}
		}
		if (flag)
		{
			arr[counter] = a[i];
			counter++;
		}
	}
	*size = counter;
	return arr;
}
int *three(int *a, int *size)
{
	int *arr = nullptr;
	arr = giveMemory(arr, *size);
	int counter = 0;
	for (int i = 0; i < *size; i++)
	{
		if (a[i] % 3 == 0)
		{
			arr[counter] = a[i];
			counter++;
		}
	}
	*size = counter;
	return arr;
}
int *even(int *a, int *size)
{
	int *arr = nullptr;
	arr = giveMemory(arr, *size);
	int counter = 0;
	for (int i = 0; i < *size; i++)
	{
		if (a[i] % 2 == 0)
		{
			arr[counter] = a[i];
			counter++;
		}
	}
	*size = counter;
	return arr;
}
void printArray(int *arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << endl;
}

int*(*getfunptr(int*(*a[])(int*, int*)))(int*, int*)
{
	int choice;
	cout << "1.simple\n2.three\n3.Even" << endl;
	cin >> choice;
	return a[choice - 1];
}
int* returnArray(int *a, int *size, int*(*alg)(int*, int*))
{
	return alg(a, size);
}
