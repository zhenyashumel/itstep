#include"FrequencyDictionary.h"

void work()
{
	FrequencyDictionary dictionary;
	std::cin.get();
	
	bool done = true;
	int choise;
	while (done)
	{
		std::cout << "Что будем делать дальше ?\n"
			"1.Получить самое частое слово в словаре\n"
			"2.Получить самое редкое слово в словаре\n"
			"3.Получить слово с заданным рангом\n"
			"4.Получить ранг и частоту заданного слова\n"
			"5.Получить все слова, ранг которых заключен в заданном диапазоне\n"
			"6.Получить информацию (ранг, частота, лемма) обо всех словах заданной части речи\n"
			"7.Получить все слова определенной части речи, частота которых не меньше заданного значения\n"
			"8.Получить статистику, сколько слов каждой части речи есть в словаре и какая их средняя частота на 1 миллион словоупотреблений\n\n"
			"9.Выход\n";
		std::cout << "Ваш выбор: ";
		std::cin >> choise;
		switch (choise)
		{

		case 1: dictionary.getMin(); break;

		case 2: dictionary.getMax(); break;

		case 3:
		{	
			int tmp;
			std::cout << "Введите ранг: ";
			std::cin >> tmp;
			if (tmp < 1 || tmp > 20004)
			{
				std::cout << "Такого ранга нет!!!\n";
				break;
			}
			dictionary.wordOfRank(tmp);
		}
		break;

		case 4:
		{
			std::cout << "Введите слово: ";
			std::string tmp;
			std::cin >> tmp;
			dictionary.rankOfWord(tmp);
		}
		break;

		case 5:
		{
			std::cout << "Введите диапазон: ";
			int a, b;
			std::cin >> a >> b;
			if (a > b ||a < 1 || b > 20004 )
			{
				std::cout << "Неверный диапазон\n";
				break;
			}
			dictionary.wordInRange(a, b);
		}
		break;

		case 6:
		{
			std::cout << "Части речи:"
				"Часть речи: a\n"
				"Часть речи : adv\n"
				"Часть речи : advpro\n"
				"Часть речи : anum\n"
				"Часть речи : apro\n"
				"Часть речи : conj\n"
				"Часть речи : intj\n"
				"Часть речи : num\n"
				"Часть речи : part\n"
				"Часть речи : pr\n"
				"Часть речи : s\n"
				"Часть речи : spro\n"
				"Часть речи : v\n";
			std::string part;
			std::cin >> part;
			dictionary.partOfSpeech(part);				
		}
		break;

		case 7:
		{
			std::cout << "Ввежите диапазон:";
			int range;
			std::cin >> range;
			if (range < 1 || range > 20004)
			{
				std::cout << "Неверный диапазон!!!\n";
				break;
			}
			std::string part;
			std::cout << "Введите часть речи!!!\n";
			std::cin >> part;
			dictionary.partInRange(part, range);
		}
		break;

		case 8: dictionary.statistics(); break;

		case 9: done = false;
		}

	}

}

int main()
{
	setlocale(0,"");
	work();

	return 0;
}
	
