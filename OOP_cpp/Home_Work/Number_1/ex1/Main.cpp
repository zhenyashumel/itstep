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
			"1. Will we read the dictionary from another file\n"
			"2. Output the contents of the dictionary\n"
			"3. The most common word\n"
			"4. Write the result to a file\n"
			"5. Exit\n";
		std::cout << "Your choise: ";
		std::cin >> choise;

		switch (choise)
		{
		case 1: 
		{
			std::cout << "Hello. Please enter a filename: ";
			std::string name;
			std::cin >> name;
			obj.input(name);
		}
		break;
		case 2: obj.print(); break;
		case 3: obj.bestWord(); break;
		case 4:obj.write(); break;
		case 5: done = false; break;
		default:std::cout << "Enter the correct menu item!!!\n";
		}
		std::cout << "Press Enter to continue...";
		std::cin.get();
		std::cin.get();
	}
	
}
int main()
{
	//rang , word, frequency
	work();
	

	return 0;

}
