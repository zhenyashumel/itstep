#include"function.h"
int main()
{
	setlocale(0, "");
	const int size = 5;
	char massch[size];
	double massd[size];
	int massi[size];

	
	Init(massch, size);
	Init(massd, size);
	Init(massi, size);
	cout << "Массивы инициализированны!!!\n";


	cout << "Press Enter to continue";
	cin.get();


	cout << "Выводим массивы:\n";
	Print(massch, size);
	Print(massd, size);
	Print(massi, size);

	cout << "Press Enter to continue";
	cin.get();

	cout << "Выводим минимальные значения:\n";
	cout << Min(massch, size)<<endl;
	cout << Min(massd, size) << endl;
	cout << Min(massi, size) << endl;

	cout << "Press Enter to continue";
	cin.get();


	cout << "Выводим максимальные значения:\n";
	cout << Max(massch, size) << endl;
	cout << Max(massd, size) << endl;
	cout << Max(massi, size) << endl;

	cout << "Press Enter to continue";
	cin.get();

	cout << "Сортируем массивы:\n";
	Sort(massch, size);
	Sort(massd, size);
	Sort(massi, size);

	Print(massch, size);
	Print(massd, size);
	Print(massi, size);

	cout << "Press Enter to continue";
	cin.get();

	cout << "Сейас будем редактировать массивы:\n";
	int indexch, indexi, indexd;
	int valuei;
	double valued;
	char valuech;
	cout << "Введите индекс изменяемого элемента для символьного массива: ";
	cin >> indexch;
	cout << "На что будем заменять: ";
	cin >> valuech;

	cout << "Введите индекс изменяемого элемента для целочисленного массива: ";
	cin >> indexi;
	cout << "На что будем заменять: ";
	cin >> valuei;

	cout << "Введите индекс изменяемого элемента для массива действительных чисел: ";
	cin >> indexd;
	cout << "На что будем заменять: ";
	cin >> valued;

    Red(massch, size,  indexch, valuech);
	Red(massd, size, indexd, valued);
	Red(massi, size, indexi, valuei);

	cout << "Выводим массивы:\n";
	Print(massch, size);
	Print(massd, size);
	Print(massi, size);



	return 0;
}
