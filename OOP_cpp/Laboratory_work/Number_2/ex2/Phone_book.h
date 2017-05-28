#pragma once
#include<iostream>
#include<string>
struct  Caller
{
	std::string FIO;
	int mob_number;
	int home_number;
};
class Phone_book
{
	Caller list[10];
public:
	int index=-1;

	void addCaller();
	void searchCaller();
	void printCaller();
	void deleteCaller();
	
};
