#pragma once
#include<vector>
#include<string>
#include<map>

class Recipes
{
public:
	std::map < std::string, std::map < std::string, int>> book;
	std::vector<std::string> last_recipe;
	std::string last_word;
	std::vector<std::string> often;

public:

	Recipes();
	~Recipes() = default;

	void recipe_generation(const int quantity);
	void print_recipe() const;
	void finput_recipe() const;
	void several_recipes(const int quantity, int count);

	void menu();
};
