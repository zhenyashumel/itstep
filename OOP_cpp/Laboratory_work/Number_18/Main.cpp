#include"Classes.h"

template<typename T>
//здесь работа с питомцем
void actions(T obj)
{
	bool done = true;
	while (done)
	{
		std::cout << "what will we do next ?\n"
			"1.To talk\n"
			"2.Say a name\n"
			"3.Show\n"
			"4.Get info\n"
			"5.Nothing" << std::endl;
		int choice;
		std::cout << "Your choice: ";
		std::cin >> choice;
		switch (choice)
		{

		case 1:
		{
			obj.sound();

		}
		break;

		case 2:
			obj.show();
			break;

		case 3:
			obj.type();
			break;

		case 4:
			obj.info();
			break;
		case 5:
			std::cout << "Goodbye!!!\n";
			done = false;
			break;
		default: std::cout << "Enter the correct item of menu!!!\n";
		}
		std::cout << std::endl << std::endl;
	}
}

//эта функция создаёт питомца(имя , рост и т.д.)
void work(std::string pets)
{
	std::cout << "Enter the name of the little animal: ";
	std::string name;
	std::cin >> name;

	std::cout << "Enter the age of the little animal: ";
	size_t age;
	std::cin >> age;

	std::cout << "Enter the mass of the little animal: ";
	size_t mass;
	std::cin >> mass;

	std::cout << "Enter the sex of the little animal: ";
	std::string pol;
	std::cin >> pol;

	std::cout << "Enter the colour of the little animal: ";
	std::string colour;
	std::cin >> colour;

	if (pets == "Dog")
	{
		Dog obj(name, age, mass, pol, colour);
		actions<Dog>(obj);
	}

	else if (pets == "Cat")
	{
		Cat obj(name, age, mass, pol, colour);
		actions<Cat>(obj);
	}

	else if (pets == "Hamster")
	{
		Hamster obj(name, age, mass, pol, colour);
		actions<Hamster>(obj);
	}

	else if (pets == "Parrot")
	{
		std::cout << "Can a parrot fly?" << std::endl;
		bool answer;
		std::cout << "1.Yes\n0.No\n";

		bool truth = true;
		while (truth)
		{
			std::cin >> answer;

			if (answer != 1 && answer != 0)
				std::cout << "Enter the correct item of menu!!!\n";

			else
				truth = false;

		}
		if (answer)
		{
			std::cout << "At what speed does it fly? ";
			size_t speed;
			std::cin >> speed;
			Parrot obj(name, age, mass, pol, colour, answer, speed);
			actions<Parrot>(obj);
		}
		else
		{
			Parrot obj(name, age, mass, pol, colour, answer, 0);
			actions<Parrot>(obj);
		}
	}

}

//эта функция выбирает питомца(класс)
void animals()
{
	std::cout<< "Hello!!! Let's start!!!\n";
	std::cout << "Press Enter to continue...";
	std::cin.get();
	std::cout << "Choose a pet:\n";
	bool done = true;
	int choice;
	while (done)
	{
		std::cout << "1.Dog\n"
			"2.Cat\n"
			"3.Parrot\n"
			"4.Hamster\n";
		std::cout << "Your Choice: ";
		std::cin >> choice;
		switch (choice)
		{

		case 1:
			work("Dog");	
			done = false;
			break;

		case 2:
			work("Cat");
			done = false;
			break;

		case 3:
			work("Parrot");
			done = false;
			break;

		case 4:
			work("Hamster");
			done = false;
			break;

		default: std::cout << "Enter the correct item of menu!!!\n";
		}
	
	}
}


int main()
{
	animals();
	return 0;
	
}
