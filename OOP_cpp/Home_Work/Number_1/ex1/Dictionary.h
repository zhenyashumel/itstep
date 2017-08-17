#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include<vector>
#include<string>


class Dictionary
{

	std::map<std::string, int > dict;
	std::string out = ""; //здесь хранятся результаты всех операций , которые(при желании) будем записывать в файл 

public:
	Dictionary() = delete;
	Dictionary(std::string);
	~Dictionary() = default;

	void print();
	void bestWord();
	void input(std::string);
	void write();

};
