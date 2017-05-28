#include"Phone_book.h"
int Phone_book::index = -1;
void addCaller(Phone_book list[])
{
	if (Phone_book::index == 9) std::cout << "The book is overflowing" << std::endl;
	else
	{
		Phone_book::index++;
		Phone_book temp;
		std::cout << "Enter the FIO: ";
		std::cin >> temp.FIO;
		std::cout << "Enter mobile number: ";
		std::cin >> temp.mob_number;
		std::cout << "Enter the home number ";
		std::cin >> temp.home_number;
		list[Phone_book::index] = temp;
	}
	
}
void searchCaller(Phone_book list[])
{
	if (Phone_book::index ==-1) std::cout << "The book empty" << std::endl;
	else
	{
		std::string temp;
		std::cout << "Enter the FIO of caller: ";
		std::cin >> temp;
		bool flag = false;
		for (int i = 0; i <= Phone_book::index; i++)
		{
			if (list[i].FIO == temp)
			{
				std::cout << "FIO             " << list[i].FIO << std::endl;
				std::cout << "Mobile number   " << list[i].mob_number << std::endl;
				std::cout << "Home number     " << list[i].home_number << std::endl;
				flag = true;
			}
		}
		if (!flag)std::cout << "Caller not found";
	}
}
void printCaller(Phone_book list[])
{
	if (Phone_book::index == -1) std::cout << "The book empty" << std::endl;
	else
	{
		for (int i = 0; i <= Phone_book::index; i++)
		{
			
				std::cout << "FIO             " << list[i].FIO << std::endl;
				std::cout << "Mobile number   " << list[i].mob_number << std::endl;
				std::cout << "Home number     " << list[i].home_number << std::endl;
				std::cout << std::endl << std::endl;			
			
		}
	}
}
void  deleteCaller(Phone_book list[])
{
	if (Phone_book::index == -1) std::cout << "The book empty" << std::endl;
	else
	{
		std::string temp;
		std::cout << "Enter the FIO of caller: ";
		std::cin >> temp;
		int dindex;
		bool flag = false;
		for (int i = 0; i <= Phone_book::index; i++)
		{
			if (list[i].FIO == temp)
			{
				dindex = i;
				flag = true;
			}
		}
		if (!flag)std::cout << "Caller not found";
		else
		{
			for (int i = dindex; i <= Phone_book::index; i++)
				list[i] = list[i + 1];
			Phone_book::index--;
			std::cout << "Caller has been deleted!!!\n";

		}
		

	}

}
