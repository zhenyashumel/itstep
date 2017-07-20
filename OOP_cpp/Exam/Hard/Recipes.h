#pragma once
#include<vector>
#include<string>
#include<map>

class Recipes
{
public:
	std::map < std::string, std::map < std::string, int>> book;//здесь хранится список всех слов и слов , которые  повторяются после их
	std::vector<std::string> last_recipe; //сюда записывается рецепт
	std::string last_word; //последнее слово  (нужно для генерации)
	
public:

	Recipes();
	~Recipes() = default;

	void recipe_generation(const int quantity);
	void print_recipe() const;
	void finput_recipe() const;
	void several_recipes(const int quantity, int count);

	void menu();
};
