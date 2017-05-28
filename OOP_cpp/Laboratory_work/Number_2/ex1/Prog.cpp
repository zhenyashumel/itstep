#include"Area.h"

int main()
{
	std::cout << "Now we will calculate the area of several figures!!" << std::endl << "Press Enter to continue!!!" << std::endl;
	std::cin.get();
	int choice;
	bool done = false;
	while (!done)
	{
		std::cout << std::endl;
		std::cout << "Area what figure you want to count ?\n"
			"1. Rectangle\n"
			"2. Parallelogram\n"
			"3. Rhombus\n"
			"4.No!!! Leave me alone\n";

		std::cout << "Your choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			std::cout << "Rectangle? OK!!\nHow do we calculate?\n"
				"1. One side\n"
				"2. Two sides\n";
			int choice1; std::cin >> choice1;
			if (choice == 2)
			{
				int side1, side2;
				std::cout << "Enter the first side: ";
				std::cin >> side1;
				std::cout << "Enter the second side: ";
				std::cin >> side2;
				if (side1 < 1 || side2 < 1)std::cout << "The sides may not be less than 1!!!" << std::endl;
				else std::cout << "Area of the Rectangle = " << Area::getRectangleArea(side1, side2);


			}
			else if (choice == 1)
			{
				int side;
				std::cout << "Enter the  side: ";
				std::cin >> side;
				if (side < 1)std::cout << "The side may not be less than 1!!!" << std::endl;
				else std::cout << "Area of the Rectangle = " << Area::getRectangleArea(side);
			}
			else std::cout << "Enter the correct menu item!!!";
			break;
		}
		case 2:
		{
			std::cout << "Parallelogram? OK!!\nHow do we calculate?\n"
				"1. For side and height\n"
				"2. Two sides and angle\n";
			int choice1; std::cin >> choice1;
			if (choice1 == 1)
			{
				int side, height;
				std::cout << "Enter the side: ";
				std::cin >> side;
				std::cout << "Enter the height: ";
				std::cin >> height;
				if(side<1||height<1) std::cout << "The side and height may not be less than 1!!!" << std::endl;
				else std::cout << "Area of the parallelogram = " << Area::getParallelogramArea(side, height);
			}
			else if (choice1 == 2)
			{
				int side1, side2,angle;
				std::cout << "Enter the first side: ";
				std::cin >> side1;
				std::cout << "Enter the second side: ";
				std::cin >> side2;
				std::cout << "Enter the angle: ";
				std::cin >> angle;
				if (side1<1 || side2<1||angle<1||angle>360) std::cout << "The sides or angle may not be less than 1!!!" << std::endl;
				else std::cout << "Area of the parallelogram = " << Area::getParallelogramArea(side1, side2,angle);
			}
			else std::cout << "Enter the correct menu item!!!";
			break;
			

		}
		case 3:
		{
			std::cout << "Rhombus? OK!!\nHow do we calculate?\n"
				"1. One side and angle\n"
				"2. Two diagonals\n";
			int choice1; std::cin >> choice1;
			if (choice1 == 1)
			{
				int side;
				float angle;	
				std::cout << "Enter the  side: ";
				std::cin >> side;
				std::cout << "Enter the angle: ";
				std::cin >> angle;
				if(side<1||angle<1)std::cout << "The side or angle may not be less than 1!!!" << std::endl;
				else std::cout << "Area of the rhombus = " << Area::getRhombusArea(side, angle);

			}
			else if (choice1 == 2)
			{

				int side1,side2;
				
				std::cout << "Enter the first diagonal: ";
				std::cin >> side1;
				std::cout << "Enter the second diagonal: ";
				std::cin >> side2;
				if (side1<1 || side2<1)std::cout << "The diagonals may not be less than 1!!!" << std::endl;
				else std::cout << "Area of the rhombus = " << Area::getRhombusArea(side1, side2);
			}
			else std::cout << "Enter the correct menu item!!!";
			break;

		}
		case 4:done = true; break;
		default: std::cout << "Enter the correct menu item!!!";
		}


	}
	std::cout << "You calculated the area " << Area::getCounter() << " times";
	return 0;
}
	
