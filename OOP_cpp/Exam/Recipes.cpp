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
		str = temp + " ";
		while (temp[temp.length() - 1] != '.')
		{
			in >> temp;
			str += temp + " ";
		}
		
		book.push_back(str);
	}
	in.close();
}


void Recipes::recipe_generation()
{
	last_recipe.clear();
	srand((unsigned)time(0));
	std::string temp;
	std::string str="";
	last_recipe.push_back(book[rand() % 15]);
	
	for (int i = 0; i < 10; ++i)
	{
		last_recipe.push_back(book[rand() % book.size()]);		
	}
	last_recipe.push_back("Приятного аппетита!!!");	
}

void Recipes::print_recipe() const
{
	for (int i = 0; i < last_recipe.size(); ++i)
		std::cout << last_recipe[i] << " ";
}


void Recipes::finput_recipe() const
{
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
