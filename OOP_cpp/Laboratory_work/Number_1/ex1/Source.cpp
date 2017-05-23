#include"Header.h"

void Student::setSurname(std::string value)
{
	Surname = value;
};
void Student::setName(std::string value)
{
	Name = value;
};
void Student::setPatronymic(std::string value)
{
	Patronymic = value;
};


void Student::setPhone(const std::string value)
{
	Phone = value;
}
void Student::setCity(const std::string value)
{
	City = value;
}
void Student::setSchool(const std::string value)
{
	School = value;
}
void Student::setGroup(const std::string value)
{
	Group = value;
}



std::string Student:: getSurname()const
{
	return Surname;
}
std::string Student::getName()const
{
	return Name;
}
std::string Student::getPatronymic()const
{
	return Patronymic;
}
std::string Student::getDate()const
{
	return Date;
}
std::string Student::getPhone()const
{
	return Phone;
}
std::string Student::getCity()const
{
	return City;
}
std::string Student::getSchool()const
{
	return School;
}
std::string Student::getGroup()const
{
	return Group;
}

Student::Student(std::string value) :Date(value), Surname("Ivanov"), Name("Ivan"),
Patronymic("Ivanovich") {};


void Student::print()
{
	std::cout <<"Name: "<<Name<<std::endl;
	std::cout <<"Surname: " << Surname << std::endl;
	std::cout << "Patronymic: " << Patronymic << std::endl;
	std::cout << "Date: " << Date << std::endl;
	std::cout << "Phone: " << Phone << std::endl;
	std::cout << "City: " << City << std::endl;
	std::cout << "School: " << School << std::endl;
	std::cout << "Group: " << Group << std::endl;
}
