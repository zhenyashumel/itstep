#include <iostream>

template<typename T>
void show(double x, T& fp)
{
	std::cout << x << " -> " << fp(x) << std::endl;
}


int main()
{
	show(10.1, [](double x) { return 1.8 * x + 32; });
	return 0;
}
