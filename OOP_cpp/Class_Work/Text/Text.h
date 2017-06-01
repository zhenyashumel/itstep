#pragma once

#include <iostream>
#include <string>
#include<fstream>


class Text
{
	std::string *str;
	size_t size;
	void function(int a, std::string name= "test_text.txt");
public:
	Text();
	Text(int);
	Text(std::string);
	Text(std::string name, int);
	Text(const Text&);
	Text(Text&&);
	~Text();
	size_t get_max_len()const;
	std::string get_max_word() const;
	
	
};
