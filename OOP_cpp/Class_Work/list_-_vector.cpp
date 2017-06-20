#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<fstream>

void work()
{
	std::vector<std::string> turgenev;
	std::ifstream in("turgenev.txt");
	if (!in.is_open())
	{
		std::cout << "Error!!!";
		return ;
	}


	std::string temp;
	while (in >> temp)
		turgenev.push_back(temp);

	in.close();

	std::ofstream out("turgenev_output.txt");
	out << turgenev.size()<<std::endl;

	std::list<std::string> uniques;	
	for (int i = 0; i < turgenev.size(); ++i)
	{
		if (turgenev[i].size() == 7)
			uniques.push_back(turgenev[i]);
	}
	uniques.sort();
	uniques.unique();
	out<<uniques.size()<<std::endl;



	std::list<std::string> Inf;

	for (auto word:uniques)
	{
		std::string tmp = word.substr(5, 2);
		if (tmp == "ти" || tmp == "ть" || tmp == "чь")
			Inf.push_back(word);
	}

	out << Inf.size()<<std::endl;
	for (auto i : Inf)
		out << i << " ";
	out << std::endl;

	Inf.pop_front();
	Inf.pop_front();
	int index = 0;
	
	for (auto it = Inf.begin(); it != Inf.end(); ++it, ++index)
	{
		if (index == 8 || index == 15 || index == 32 ||
			index == 36 || index == 37 || index == 41 ||
			index == 39 || index == 4)
			it = Inf.erase(it);
		
	}
	out << Inf.size() << std::endl;


	Inf.remove("полночь");
	Inf.remove("прихоть");
	Inf.remove("страсть");

	for (auto word : uniques)
	{
		std::string tmp = word.substr(0, 3);
		if (tmp == "раб" || tmp == "роб" || tmp == "сов" || tmp == "тяг" || tmp == "тяж") 
			Inf.remove(word);
	}

	Inf.push_front("акать");
	Inf.push_back("якать");
	auto it1 = Inf.begin();
	while (it1 != Inf.end())
	{
		if (*it1 == "обедать")
		{
			break;
		}
		++it1;
	}
	Inf.insert(it1, "начать");


	for (auto i : Inf)
		out << i << " ";
	
	out.close();



}


int main()
{
	setlocale(0,"");
	work();

	return 0;
}
