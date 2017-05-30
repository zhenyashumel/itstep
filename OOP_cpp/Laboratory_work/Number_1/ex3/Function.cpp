#include"PrettyPrint.h"
std::string PrettyPrint::concatenation(std::string a, std::string b)const
{
	std::string str = a + '.' + b;
	return str;
}
std::string PrettyPrint::substitution(std::string a)
{
	for (std::string::iterator it = a.begin(); it != a.end(); ++it) 
	
		if (*it == 'a')*it='o';
		return a;

}

void PrettyPrint::coup(std::string *a)
{
	int a1 = (*a).size();//size of a
	std::string temp=(*a);//copy a
	for (int a2 = 0; a2 < (*a).size() / 2; a2++, a1--)//пробегаемся до половины и меняем местами первый и последний элемент
	{
		
		
		(*a).at(a2)=(*a).at(a1 - 1);
		(*a).at(a1 - 1) = (temp).at(a2);
	}
}

