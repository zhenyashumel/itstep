#include "Digit.h"

void test()
{
	Digit a;
	Digit b(13);
	if ((a + b).getDigit() == b.getDigit() + a.getDigit())
		std::cout << "The addition operator worked correctly !!!\n";
	else
	{
		std::cout << "Oops... Something went wrong :(";
		
	}
	a.setDigit(10);
	if ((b-a).getDigit() == b.getDigit()-a.getDigit())
		std::cout << "The subtraction operator worked correctly !!!\n";
	else
	{
		std::cout << "Oops... Something went wrong :(";
		
	}
	if(((a*b)/a).getDigit()==b.getDigit())
		std::cout << "The operators of division and multiplication worked correctly!!!\n";
	else
	{
		std::cout << "Oops... Something went wrong :(";
		
	}
	if((b%a).getDigit()== b.getDigit() % a.getDigit())
		std::cout << "The division operator modulo worked correctly!!!\n";
	else
	{
		std::cout << "Oops... Something went wrong :(";
		
	}
	if ((-a).getDigit() == a.getDigit()*-1)
		std::cout << "The unary minus operator works correctly!!!\n";
	else
	{
		std::cout << "Oops... Something went wrong :(";
		
	}
	if (a<b&&b>a&&a <= b&&b >= a&&a != b)
		std::cout << "Comparison operators work correctly!!!\n";
	else
	{
		std::cout << "Oops... Something went wrong :(";
		
	}
	a.setDigit(5);
	b.setDigit(100);
	if (a.getDigit()-5==1)
		std::cout << "Postfix increment and decrement work correctly!!!\n";
	else
	{
		std::cout << "Oops... Something went wrong :(";

	}
	int temp1=5, temp2=10;
	a.setDigit(temp1);
	b.setDigit(temp2);
	++a; --b;
	
	if(a.getDigit()-temp1==1&& temp2-b.getDigit())
		std::cout << "Prefix increment and decrement work correctly!!!\n";
	else
	{
		
		std::cout << "Oops... Something went wrong :(";

	}
	a = b;
	if (a.getDigit() == b.getDigit())std::cout << "Assignment operator is working correctly!!!";
	else
	{

		std::cout << "Oops... Something went wrong :(";

	}

}


int main()
{
	std::cout << "Here we will overload the operators. Probably" << std::endl;
	std::cout << "Press Enter to continue!!!";
	std::cin.get();
	test();

	return 0;
}
