#include"Recipes.h"
#include<fstream>
#include<exception>
#include<ctime>
#include<iostream>

Recipes::Recipes()
{
	std::ifstream in("Recipes.txt");
	if (!in.is_open()) throw std::logic_error("File isn't open!!!\n");

	std::string temp;
	std::string str;
	while (in >> temp)
	{
		std::string next;
		auto it = book.find(temp);
		if (it == book.end())
		{
			std::map<std::string, int> cur = { { next, 1 } };
			book.insert({ temp, cur });
		}
		else
		{
			if (it->second.find(next) != it->second.end())
				it->second[next] = it->second[next] + 1;
			else
				it->second[next] = 1;
		}

		in.seekg(next.length() * -1, std::ios_base::cur);
	}
	in.close();
}


void Recipes::recipe_generation()
{
	last_recipe.clear();
	srand((unsigned)time(0));
	last_recipe.push_back(book.begin()->first);
	std::string last_word = book.begin()->first;
	for (int i = 0; i < 30; ++i)
	{
		last_recipe.push_back(book[last_word].begin()->first);
		last_word = book[last_word].begin()->first;

	}
}

void Recipes::print_recipe() const
{
	for (int i = 0; i < last_recipe.size(); ++i)
		std::cout << last_recipe[i] << " ";
	std::cout << std::endl;
}


void Recipes::finput_recipe() const
{
	setlocale(0, "");
	std::cout << "Введите имя файла: ";
	std::string name;
	std::cin >> name;
	name += ".txt";
	std::ofstream out(name);
	for (int i = 0; i < last_recipe.size(); ++i)
		out << last_recipe[i];
	std::cout << "Рецепт успешно записан в файл\n";
}


void Recipes::menu()
{
	setlocale(0, "");
	std::cout << "Я убеждал пользователей, что вовсе не собирался писать кулинарную книгу, но меня заставили сделать это.\nПоэтому, без лишних слов - моя книга!!!\n";
	std::cout << "Press Enter to continue...";
	std::cin.get();
	std::cout << "Первый рецепт сгенерирован!!!\n";
	recipe_generation();
	std::cout << "\n";
	bool done = true;

	while (done)
	{
		std::cout << "\nЧто будем делать ?\n";
		std::cout << "1.Сгенерировать новый рецепт\n"
			"2.Вывести рецепт на экран\n"
			"3.Сохранить рецепт в файл\n"
			"0.Выйти\n";
		std::cout << "Ваш выбор: ";
		int choice;
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
		case 1: recipe_generation();
			std::cout << "Рецепт сгенерирован!!!\n";
			break;
		case 2: print_recipe(); break;
		case 3: finput_recipe(); break;
		case 0: done = false; break;
		default: std::cout << "Введите корректный пункт меню!\n";
		}
	}

}
