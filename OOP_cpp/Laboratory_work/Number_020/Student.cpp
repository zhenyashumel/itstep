#include "Student.h"
#include<iostream>


Student::Student(std::string nam, std::string surnam, std::string patronym, int d, int m, int y, int cur, std::string gr) : name(nam), surname(surnam), patronymic(patronym),
date(new Date(d, m, y)), course(cur), group(gr),recordBook(new RecordBook)
{
	recordBook->init();
}


void Student::getInfo() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Surname: " << surname << std::endl;
	std::cout << "Patronymic: " << patronymic << std::endl;
	std::cout << "Date of Birth: "; date->printDate(); std::cout << std::endl;
	std::cout << "Group: " << group << std::endl;
	std::cout << "Course: " << course << std::endl;
	std::cout << std::endl;
	
}


void Student::setMarks()
{
	recordBook->init();
}

void Student::printMarks() const
{
	recordBook->print();
}
