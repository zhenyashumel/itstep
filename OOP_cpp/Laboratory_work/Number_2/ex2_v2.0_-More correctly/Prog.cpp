#include"Phone_book.h"

int main()
{
	
	Phone_book list[10];
	Phone_book x;
	bool done = true;
	std::cout << "Welcome to the phonebook!!!\nThe maximum number of callers - 10" << std::endl;

	std::cout << "Press Enter to continue ";
	std::cin.get();
	int choice;
	
	while (done)
	{
		
		
		std::cout << std::endl;
		std::cout << "What you want to do ?\n"
			"1. Add caller\n"
			"2. Search caller\n"
			"3. Print callers\n"
			"4. Delete caller\n"
			"5.Please, let me go\n";
		std::cout << "Your choice: "; 
		std::cin >> choice;
		switch (choice)
		{
		case 1: addCaller(list); break;
		case 2: searchCaller(list); break;
		case 3: printCaller(list); break;
		case 4: deleteCaller(list); break;
		case 5: done = false; break;
		default: std::cout << "Enter the correct item of menu!!!\n"; 
		}


	}

	return 0;

}
