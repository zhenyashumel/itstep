#include<fstream>
#include<string>
#include<iostream>

int function();


int main()
{
	std::cout << function();
	return 0;
}
int function()
{
	std::ifstream in("input.txt");
	int k, n;
	in >> k;
	in >> n;
	int sum = 0;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		in >> temp;

		if (temp%k == 0)
			sum += temp;
	}

	return sum;
}
