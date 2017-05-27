#include"Triangle.h"
#include"Square.h"
int main()
{
	std::cout << "Now we will calculate the area of the rectangle!!!" << std::endl << "Press Enter to continue!!!" << std::endl;
	std::cin.get();
	std::cout << "How will we calculate the area?\n"
		"1. By base and height.\n"
		"2. On two sides and the corner between them.\n"
		"3. On three sides.\n"
		"4.I do not want to calculate the area of a triangle.How to get out of here?" << std::endl;
	Triangle a;
	int choice;
	
	bool done = false;
	while (!done)
	{
		std::cout << std::endl;
		std::cout << "Your choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
				  int base, height;
				  bool x = false;
				  while (!x)
				  {
					  std::cout << "Enter the base: ";
					  std::cin >> base;
					  std::cout << "Enter the height: ";
					  std::cin >> height;
					  if (base > 0 || height > 0)
					  {
						  x = true;
						  std::cout << "Area of a triangle = " << a.getTriangleArea(base, height); 
					  }
					  else std::cout << "Enter the correct data!!!\n";
				  }
				  break;
		}
		case 2:
		{
				  int side1, side2;
				  float angle;
				  bool x = false;
				  while (!x)
				  {
					  std::cout << "Enter the first side: ";
					  std::cin >> side1;
					  std::cout << "Enter the second side: ";
					  std::cin >> side2;
					  std::cout << "Enter the angle: ";
					  std::cin >> angle;
					  if (side1>0||side2>0||angle>0||angle<180)
					  {
						  x = true;
						  std::cout << "Area of a triangle = " << a.getTriangleArea(side1,side2,angle);
					  }
					  else std::cout << "Enter the correct data!!!\n";
				  }
				  break;
		}
		case 3:
		{

				  int side1, side2, side3;
				  bool x = false;
				  while (!x)
				  {
					  std::cout << "Enter the first side: ";
					  std::cin >> side1;
					  std::cout << "Enter the second side: ";
					  std::cin >> side2;
					  std::cout << "Enter the third side: ";
					  std::cin >> side3;
					  if (side1 > 0 || side2 > 0 || side3 > 0)
					  {
						  x = true;
						  std::cout << "Area of a triangle = " << a.getTriangleArea(side1, side2, side3);
					  }
					  else std::cout << "Enter the correct data!!!\n";
				  }
				  break;
		}
		case 4:done = true; break;
		default: std::cout << "Enter the correct menu item!!!";
		}
		
	}
	std::cout << "\nGo ahead. Now calculate the square of the square!!!" << std::endl << "Press Enter to continue!!!" << std::endl;
	std::cin.get();
	std::cout << "Stupid question, but still: One side or two?\n"
		"1. One\n"
		"2. Two\n";
	std::cin >> choice;
	if (choice == 1)
	{
		int side;
		std::cout << "Enter the side of the square: ";
		std::cin >> side;
		if (side < 1)std::cout << "The side can not be less than 1!!!\n";
		else
		{
			Square object(side);
			std::cout << "Square of a square = " << object.getSquareArea(object.getSide1())<<std::endl;
		}
	}
	else if (choice == 2)
	{
		int side1,side2;
		std::cout << "Enter the first side of the square: ";
		std::cin >> side1;
		std::cout << "Enter the second side of the square: ";
		std::cin >> side2;
		if (side1 < 1 || side2<1 || side1 != side2)std::cout << "The side can not be less than 1 and the sides must be equal!!!\n";
		else
		{
			Square object(side1,side2);
			std::cout << "Square of a square = " << object.getSquareArea(object.getSide1(),object.getSide2()) << std::endl;
		}
	}

	return 0;
}
