#include"Header.h"

void function()
{
	std::cout << "Hello,I'm glad to see you here" << std::endl;
	std::cout << "Press Enter to continue!!!" << std::endl;
	std::cin.get();
	std::cout << "Please,Enter your date of birth: ";
	std::string date;
	std::cin >> date;
	Student mc(date);
	mc.insert();
	mc.print();

}
int main()
{
	
	function();
	return 0;
}
