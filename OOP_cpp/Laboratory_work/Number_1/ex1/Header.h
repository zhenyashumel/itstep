#pragma once
#include<iostream>
#include<string>

class Student
{
	std::string Surname;
	std::string Name;
	std::string Patronymic;		
	const std::string Date;
	std::string Phone;
	std::string City;
	std::string School;
	std::string Group;
public:
	Student(std::string value);
	~Student() = default;

	void setSurname(const std::string value);
	void setName(const std::string value);
	void setPatronymic(const std::string value);
	void setDate(const std::string value);
	void setPhone(const std::string value);
	void setCity(const std::string value);
	void setSchool(const std::string value);
	void setGroup(const std::string value);

	std::string getSurname()const;
	std::string getName()const;
	std::string getPatronymic()const;
	std::string getDate()const;
	std::string getPhone()const;
	std::string getCity()const;
	std::string getSchool()const;
	std::string getGroup()const;
	

	void print();
	void insert();

};
