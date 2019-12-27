#include <iostream> 

int main()
{
	int vertex = 0;
	std::cout << "Count of vertex: ";
	std::cin >> vertex;
	int(*point)[2];
	point = new int[vertex][2];
	for (int i = 0; i < vertex; ++i)
	{
		std::cout << "Input X:"; std::cin >> point[i][0];
		std::cout << "Input Y:"; std::cin >> point[i][1];

	};
	double square = 0;
	for (int i = 0; i < vertex - 1; ++i)
	{
		square += (point[i][0] + point[i + 1][0])*(point[i + 1][1] - point[i][1]);

	}

	square += (point[0][0] + point[vertex - 1][0])*(point[0][1] - point[vertex - 1][1]);
	delete[]point;
	std::cout << "Square = " << abs(square)*0.5 << std::endl;
	system("pause");	
	return 0;
}
