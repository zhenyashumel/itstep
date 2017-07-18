#pragma once
#include<vector>
#include<string>

class Recipes
{
public:
	std::vector<std::string> book;
	std::vector<std::string> last_recipe;

public:

	Recipes();
	~Recipes() = default;

	void recipe_generation();
	void print_recipe() const;
	void finput_recipe() const;

	void menu();
};
