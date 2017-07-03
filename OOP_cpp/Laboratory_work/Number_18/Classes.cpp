#include"Classes.h"

Pet::Pet(std::string nam, size_t ag, size_t mas, std::string pol, std::string color)
{
	name = nam;
	age = ag;
	mass = mas;
	who = pol;	
}





void Pet::show() const
{
	std::cout << name << std::endl;
}

void Pet::type() const
{
	std::cout << petType << std::endl;
}

void Pet::info() const
{
	std::cout << "Name: " << name << std::endl
		<< "Age: " << age << std::endl
		<< "mass: " << mass << std::endl
		<< "Type: " << petType << std::endl
		<< who << std::endl;
		
		
}

void Parrot::info() const
{
	std::cout << "Name: " << name << std::endl
		<< "Age: " << age << std::endl
		<< "mass: " << mass << std::endl
		<< "Type: " << petType << std::endl
		<< who << std::endl;
	
	if (fly)
	{
		std::cout << "Fly: Can" << std::endl;
		std::cout << "Speed: " << speed << std::endl;
	}
	else
		std::cout << "Fly: Can't" << std::endl;

}

void Hamster::sound() const
{
	std::cout << "Phh phh" << std::endl;
}

void Dog::sound() const
{
	std::cout << "Woof Woof" << std::endl;
}

void Cat::sound() const
{
	std::cout << "Meow" << std::endl;
}

void Parrot::sound() const
{
	std::cout << "Ke ke ke" << std::endl;
}
