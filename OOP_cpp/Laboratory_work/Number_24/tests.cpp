#include "List.h"
#include <iostream>

void test1(List<int>& obj) {
	std::cout << "TEST 1" << std::endl;
	obj.print();
	obj.push_front(1);
	obj.print();
	obj.push_front(2);
	obj.print();
	obj.push_front(3);
	obj.push_front(4);
	obj.print();
	obj.pop_front();
	obj.print();
	obj.pop_front();
	obj.print();
	obj.pop_front();
	obj.print();
	obj.pop_front();
	obj.print();
	std::cout << std::endl;
}

void test2(List<int>& obj) {
	std::cout << "TEST 2" << std::endl;
	obj.push_back(10);
	obj.print();
	obj.push_back(17);
	obj.push_back(37);
	obj.push_back(47);
	obj.print();
	obj.push_front(1);
	obj.push_front(0);
	obj.print();
	obj.pop_front();
	obj.print();
	std::cout << std::endl;
}

void test3(List<int>& obj) {
	std::cout << "TEST 3" << std::endl;
	obj.print();
	obj.push_front(1);
	obj.print();
	obj.push_front(2);
	obj.print();
	obj.push_front(3);
	obj.push_front(4);
	obj.print();
	obj.pop_back();
	obj.print();
	obj.pop_back();
	obj.print();
	obj.pop_back();
	obj.print();
	obj.pop_back();
	obj.print();
	obj.pop_back();
	obj.pop_front();
	obj.push_back(10);
	obj.print();
	std::cout << std::endl;
}

void test4(List<int>& obj)
{
	std::cout << "TEST 4" << std::endl;
	obj.print();
	node<int>* n = obj.find(19);
	if (n != nullptr) {
		std::cout << n->data << std::endl;
	}
	else { std::cout << "Element is not found" << std::endl; }

	node<int>* n1 = obj.find(2);
	if (n1 != nullptr) {
		std::cout << n1->data << std::endl;
	}
	else { std::cout << "Element is not found" << std::endl; }

	node<int>* n2 = obj.find(10);
	if (n2 != nullptr) {
		std::cout << n2->data << std::endl;
	}
	else { std::cout << "Element is not found" << std::endl; }

	obj.insert(8, 10);
	obj.print();
	obj.insert(9, 8);
	obj.print();
	obj.insert(11, 10);
	obj.print();
	obj.insert(10, 56);
	obj.print();
	obj.erase(99);
	obj.print();
	obj.erase(9);
	obj.print();
	obj.erase(3);
	obj.print();
	obj.erase(10);
	obj.print();
	obj.erase(1);
	obj.print();
}

void test5(List<int>& obj)
{
	std::cout << "TEST 5" << std::endl;
	obj.print();
	obj.printReverse();
	obj.replaceValue(11, 0);
	obj.print();
	List<int> obj1;
	for (int i = 0; i < 10; ++i)
	{
		obj1.push_back(rand() % 2);
	}
	obj1.print();
	obj1.eraseAll(1);
	obj1.print();
}

int main(int argc, char* argv[])
{
	List<int> obj;
	test1(obj);
	test2(obj);
	test3(obj);
	test4(obj);
	test5(obj);
	return 0;
}

