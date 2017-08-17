#include"Dictionary.h"

void work()
{
	std::cout << "Hello. Please enter a filename: ";
	std::string fname;
	std::cin >> fname;
	Dictionary obj(fname);

	int choise;
	bool done = true;
	while (done)
	{
		std::cout << "What will we do next ?\n"
			"1. Output the contents of the dictionary\n"
			"2. The most common word\n"
			"3. Write the result to a file\n"
			"4. Exit\n";
		std::cout << "Your choise: ";
		std::cin >> choise;

		switch (choise)
		{
		
		break;
		case 1: obj.print(); break;
		case 2: obj.bestWord(); break;
		case 3:obj.write(); break;
		case 4: done = false; break;
		default:std::cout << "Enter the correct menu item!!!\n";
		}
		std::cout << "Press Enter to continue...";
		std::cin.get();
		std::cin.get();
	}

}
int main()
{
	setlocale(0, "");
	//rang , word, frequency
	work();
	




	return 0;

}
