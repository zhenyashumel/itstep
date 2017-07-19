#pragma once
#include<vector>
#include<string>
#include<map>

class Recipes
{
public:
	std::map < std::string, std::map < std::string, int>> book;
	std::vector<std::string> last_recipe;

public:

	Recipes();
	~Recipes() = default;

	void recipe_generation();
	void print_recipe() const;
	void finput_recipe() const;

	void menu();
};
