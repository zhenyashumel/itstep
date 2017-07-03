#include"Printer.h"

void work()
{
	std::string mod,man;
	size_t dat;
	std::cout << "Let's start with the model of your printer: ";
	std::cin >> mod;
	std::cout << "Okay. Year of issue: ";
	std::cin >> dat;
	std::cout << "Good. And the last is the producer: ";
	std::cin >> man;
	Printer a(mod, dat, man);

	std::cout << "What do you want to do ? \n";

	std::cout << "1. Copy one file to another\n"
		"2. Print each n-th character of the file\n"
		"3. Print each n-th word of the file\n"
		"4. Output the contents of the file in reverse order\n"
		"5. Find the word in the file and output the sentence with it\n"
		"6. Info about your printer\n"
		"0. Exit\n";
	int choice;
	
	bool done = true;
	while (done)
	{
		std::cout << "Your choice: ";
		std::cin >> choice;
		switch (choice)
		{


		case 1: a.printCopy();
			std::cout << "Done\n";
			break;

		case 2:
		{
			std::cout << "Enter a step: ";
			int step;
			std::cin >> step;
			a.printCharsWithStep(step);
			std::cout << "Done\n";
		}
		break;


		case 3:
		{
			std::cout << "Enter a step: ";
			int step;
			std::cin >> step;
			a.printWordsWithStep(step);
			std::cout << "Done\n";
		}
		break;

		case 4: a.printReverse();
			std::cout << "Done\n";
			break;

		case 5:
		{
			std::cout << "What word will we look for: ";
			std::string found;
			std::cin >> found;
			a.printСoncordance(found);
			std::cout << "Done\n";
		}
		break;

		case 6:a.getInfo(); break;


		case 0:
		{
			std::cout << "Goodbye!!!\n";
			done = false;
		}

		default: std::cout << "Enter the correct menu item!!!"; break;
		}

		
	}


}
int main()
{
	std::cout << "Welcome to... printer" << std::endl;
	std::cout << "Press Enter to continue...";
	std::cin.get();
	work();

	
	return 0;
}
