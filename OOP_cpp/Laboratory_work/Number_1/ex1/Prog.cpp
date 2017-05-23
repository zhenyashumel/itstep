#include"Header.h"

int main()
{
	
	
	std::cout << "Hello,I'm glad to see you here" << std::endl;
	std::cout << "Press Enter to continue!!!"<<std::endl;
	std::cin.get();
	std::cout << "Please,Enter your date of birth: ";
	std::string date;
	std::cin >> date;
	Student mc(date);
	std::string name, surname, patronymic, school, phone, group, city;

	std::cout << "Enter your Name: ";
	std::cin>>name;
	mc.setName(name);
	
	std::cout << "Enter your Surname: ";
	std::cin>>surname;
	mc.setSurname(surname);

	std::cout << "Enter your Patronymic ";
	std::cin>> patronymic;
	mc.setPatronymic(patronymic);

	std::cout << "Enter your phone number ";
	std::cin>>phone;
	mc.setPhone(phone);

	std::cout << "Enter your school ";
	std::cin>>school;
	mc.setSchool(school);

	std::cout << "Enter your group ";
	std::cin>>group;
	mc.setGroup(group);

	std::cout << "Enter your city" << std::endl;
	std::cin >> city;
	mc.setCity(city);
	std::cout << std::endl;
		
	mc.print();
	return 0;
}
