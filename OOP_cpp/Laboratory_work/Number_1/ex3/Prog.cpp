#include"PrettyPrint.h"
int main()
{
	std::string a = "abcdefghijklmnopqrstuvwxyz", b = "abc";
	PrettyPrint x;
	std::cout << "Join two lines" << std::endl;
	std::cout << x.concatenation(a, b) << std::endl;
	std::cout << "We replace all the symbols a on o" << std::endl;
	std::cout << x.substitution(a) << std::endl;
	std::cout << "Flip the line" << std::endl;
	x.coup(&a);
	std::cout << a;

	return 0;
}
