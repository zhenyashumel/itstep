#include"PrettyPrint.h"
int main()
{
	std::string a = "abcdefghijklmnopqrstuvwxyz",b="abc";
	PrettyPrint x;
	std::cout << "Join two lines"<<std::endl;
	std::cout << x.concatenation(a, b);	
	std::cout << "We replace all the symbols a on o" << std::endl;
	std::cout << x.substitution(a);
	a = x.coup(a);
	std::cout << "Flip the line" << std::endl;
	std::cout << a;
	
	return 0;
}
