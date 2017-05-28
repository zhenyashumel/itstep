#include"Phone_book.h"
void Phone_book::addCaller()
{
	if (index == 9) std::cout << "The book is overflowing" << std::endl;
	else
	{
		Phone_book::index++;
		Caller temp;
		std::cout << "Enter the FIO: ";
		std::cin >> temp.FIO;
		std::cout << "Enter mobile number: ";
		std::cin >> temp.mob_number;
		std::cout << "Enter the home number ";
		std::cin >> temp.home_number;
		Phone_book::list[index] = temp;
	}
	
}
void Phone_book::searchCaller()
{
	if (index ==-1) std::cout << "The book empty" << std::endl;
	else
	{
		std::string temp;
		std::cout << "Enter the FIO of caller: ";
		std::cin >> temp;
		bool flag = false;
		for (int i = 0; i <= Phone_book::index; i++)
		{
			if (Phone_book::list[i].FIO == temp)
			{
				std::cout << "FIO             " << Phone_book::list[i].FIO << std::endl;
				std::cout << "Mobile number   " << Phone_book::list[i].mob_number << std::endl;
				std::cout << "Home number     " << Phone_book::list[i].home_number << std::endl;
				flag = true;
			}
		}
		if (!flag)std::cout << "Caller not found";
	}
}
void Phone_book::printCaller()
{
	if (index == -1) std::cout << "The book empty" << std::endl;
	else
	{
		for (int i = 0; i <= Phone_book::index; i++)
		{
			
				std::cout << "FIO             " << Phone_book::list[i].FIO << std::endl;
				std::cout << "Mobile number   " << Phone_book::list[i].mob_number << std::endl;
				std::cout << "Home number     " << Phone_book::list[i].home_number << std::endl;
				std::cout << std::endl << std::endl;			
			
		}
	}
}
void Phone_book:: deleteCaller()
{
	if (index == -1) std::cout << "The book empty" << std::endl;
	else
	{
		std::string temp;
		std::cout << "Enter the FIO of caller: ";
		std::cin >> temp;
		int dindex;
		bool flag = false;
		for (int i = 0; i <= Phone_book::index; i++)
		{
			if (Phone_book::list[i].FIO == temp)
			{
				dindex = i;
				flag = true;
			}
		}
		if (!flag)std::cout << "Caller not found";
		else
		{
			for (int i = dindex; i <= Phone_book::index; i++)
				Phone_book::list[i] = list[i + 1];
			index--;

		}
		

	}

}
