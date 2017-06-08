#include"Complex.h"

void test()
{
	Complex a(5, -5);
	Complex b(2, 2);


	if (a.getReal() == 5 && a.getImg() == -5)
		std::cout << "Test 1: OK!\n";
	else
		std::cout << "Test 1: Error!!!\n";


	++a;

	if(a.getReal()-5==1 && a.getImg()-(-5)==1)
		std::cout << "Test 2: OK!\n";
	else
		std::cout << "Test 2: Error!!!\n";


	--a;

	if (a.getReal() - 5 == 0 && a.getImg() - (-5) == 0)
		std::cout << "Test 3: OK!\n";
	else
		std::cout << "Test 3: Error!!!\n";



	Complex c(7, -3);	
	
	if((a+b)==c)
		std::cout << "Test 4: OK!\n";
	else
		std::cout << "Test 4: Error!!!\n";


	Complex d = a;

	if(a==d)
		std::cout << "Test 5: OK!\n";
	else
		std::cout << "Test 5: Error!!!\n";


	a *= b;

	if(a==(d*b))
		std::cout << "Test 6: OK!\n";
	else
		std::cout << "Test 6: Error!!!\n";


	if(a!=b)
		std::cout << "Test 7: OK!\n";
	else
		std::cout << "Test 7: Error!!!\n";



	std::cout << "Now you must enter the numbers 10 and -10: ";
	std::cin >> b;//ввести 10 и -10
	if(b.getReal()==10 && b.getImg()==-10 )
		std::cout << "Test 8: OK!\n";
	else
		std::cout << "Test 8: Error!!!\n";
	
}
int main()
{
	test();
	
	return 0;
}
