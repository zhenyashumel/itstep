#include"PrettyPrint.h"
std::string PrettyPrint::concatenation(std::string a, std::string b)const
{
	std::string str = a + '.' + b;
	return str;
}
std::string PrettyPrint::substitution(std::string a)
{
	return a.replace(a.begin(), a.end(), 'a', 'o');
	

}

std::string PrettyPrint::coup(std::string a)
{
	int a1 = a.size();	
	int a3 = a1;
	std::string temp;
	for (int a2 = 0; a2<a1; a2++, a3--)
		temp.at(a2) = a.at(a3 - 1);
	
	return temp;
}

	
