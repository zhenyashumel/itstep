#include"Recipes.h"
#include<fstream>
#include<exception>
#include<ctime>
#include<iostream>



Recipes::Recipes()
{
	std::ifstream in("Recipes.txt");
	if (!in.is_open()) throw std::logic_error("File isn't open!!!\n");

	std::string temp;//сюда считываем слово
	std::string next; //это следующее слово
	std::cout << "Загрузка...\n\n\n";
	in >> temp;
	while (in >> next )
	{
		if (next[0] != '(' && next[next.length() ] != ')') //убираем слова со скобочками
		{
			auto it = book.find(temp);
			if (it == book.end()) //если слова нет
			{
				std::map<std::string, int> cur = { { next, 1 } };
				book.insert({ temp, cur });
			}
			else //если есть
			{
				if (it->second.find(next) != it->second.end())
					it->second[next] = it->second[next] + 1;
				else
					it->second.insert({ next, 1 });
			}
			temp = next;
			
		}
		//in.seekg((next.length() - 1) , std::ios_base::cur);
		
	}
	in.close();
	
}

void Recipes::recipe_generation(const int quantity)
{
	
	last_recipe.clear();
	srand((unsigned)time(0));
	std::string maax;	
	auto it = book.begin();
	for (int i = 0; i < rand() % 900 + 100; ++it, ++i);// рандомное первое слово
	last_word = it->first;
	last_recipe.push_back(last_word);	

	for (int i = 0; i < quantity - 1; ++i)
	{
		int max = 0;
		int counter = 0;
		for (auto el : book[last_word])//ищем слово , которое чаще всего встречается после передедущего слова
		{
			max = el.second;
			maax = el.first;
			counter += el.second;					
		}
		
		book[last_word].erase(maax);//удаляем его, чтобы не повторялось
		last_word = maax; //сохраняем это слово
		if (last_recipe[last_recipe.size() - 1] != last_word) // проверяем , не повторяется ли это слово
			last_recipe.push_back(last_word);
		
	}
	std::string last = last_recipe.back();// здесь мы добавляем в конце рецепта 
	last_recipe.pop_back();
	if (last[last.length() - 1] == '.')
		last_recipe.push_back(last);
	else
	{
		if (last[last.length() - 1] == ',')
			last[last.length() - 1] = '.';
		else
		{
			last += '.';
			last_recipe.push_back(last);
		}
	}
	last_recipe.push_back("Приятного аппетита!!!");

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
		out << last_recipe[i] << " ";
	std::cout << "Рецепт успешно записан в файл\n";
}

void Recipes::several_recipes(const int quantity, int count)
{
	setlocale(0, "");
	std::cout << "Введите имя файла: ";
	std::string name;
	std::cin >> name;
	name += ".txt";
	std::ofstream out(name);
	for (int i = 1; i <= count; ++i)
	{
		out << "№" << i << std::endl;
		recipe_generation(quantity);
		for (int j = 0; j < last_recipe.size(); ++j)
			out << last_recipe[j] << " ";
		out << std::endl;
	}
	std::cout << "Рецепты успешно записаны в файл!!!\n";
}


void Recipes::menu()
{
	system("cls");
	setlocale(0, "");
	std::cout << "Я убеждал пользователей, что вовсе не собирался писать кулинарную книгу, но меня заставили сделать это.\nПоэтому, без лишних слов - моя книга!!!\n";
	std::cout << "Нажмите Enter чтобы продолжить...";
	std::cin.get();
	std::cout << "Первый рецепт сгенерирован!!!\n";
	recipe_generation(100);
	std::cout << "\n";
	bool done = true;

	while (done)
	{
		std::cout << "\nЧто будем делать ?\n";
		std::cout << "1.Сгенерировать новый рецепт.\n"
			"2.Вывести рецепт на экран.\n"
			"3.Сохранить рецепт в файл.\n"
			"4.Сгенерировать несколько рецептов.\n"
			"0.Выйти.\n";
		std::cout << "Ваш выбор: ";
		int choice;
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
		case 1:
			int quantity;
			std::cout << "Введте количество слов в рецепте: ";
			std::cin >> quantity;
			recipe_generation(quantity);
			std::cout << "Рецепт сгенерирован!!!\n";
			break;
		case 2: print_recipe(); break;
		case 3: finput_recipe(); break;
		case 4:
			int quantity1;
			std::cout << "Введте количество слов в рецепте: ";
			std::cin >> quantity1;
			int count;
			std::cout << "Сколько рецептов будем генерировать ? ";
			std::cin >> count;
			several_recipes(quantity1, count);
			break;
			
		case 0: done = false; break;
		default: std::cout << "Введите корректный пункт меню!\n";
		}
	}

}
