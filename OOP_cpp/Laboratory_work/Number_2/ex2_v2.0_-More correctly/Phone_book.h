#pragma once
#include<iostream>
#include<string>
class Phone_book
{
public:
	std::string FIO;
	int mob_number;
	int home_number;

	static int index;
};


void addCaller(Phone_book list[]);
void searchCaller(Phone_book list[]);
void printCaller(Phone_book list[]);
void  deleteCaller(Phone_book list[]);
