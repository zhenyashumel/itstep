#pragma once
#include"Date.h"
#include"RecordBook.h"

class Student
{
	std::string name;
	std::string surname;
	std::string patronymic;
	Date* date;
	int course;
	std::string group;
	RecordBook* recordBook;

public:
	Student(std::string, std::string, std::string, int, int, int, int, std::string);

	void getInfo() const;
	void setMarks();
	void printMarks() const;
};

