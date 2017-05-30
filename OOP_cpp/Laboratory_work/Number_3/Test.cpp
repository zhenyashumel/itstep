#include "Test.h"

#include <iostream>

void Test::test() const {
	test_ctor_1();
	test_push_back();
	test_copy_ctor_1();
	test_ctor_2();
	test_copy_ctor_2();
	test_at();
	test_pop_back();
}

void Test::getVector(MyVector v) const {

}

MyVector Test::createVector(const size_t s) const {
	MyVector v;
	for (size_t i = 0; i < s; ++i) {
		v.push_back(i);
	}
	return v;
}

bool Test::check_error(MyVector& v, const int v_size, const int v_capacity) const {
	if (v.get_size() != v_size || v.get_capacity() != v_capacity) {
		std::cout << status_error << std::endl;
		return false;
	}
	return true;
}

bool Test::test_ctor_1() const {
	std::cout << "Test 1: ";
	MyVector v;

	if (!v.empty()) {
		std::cout << status_error << std::endl;
		return false;
	}

	if (!check_error(v, 0, 32)) {
		return false;
	}

	std::cout << status_ok << std::endl;
	return true;
}

bool Test::test_push_back() const {
	std::cout << "Test 2: ";
	MyVector v;
	v.push_back(1);
	if (!check_error(v, 1, 32)) {
		return false;
	}

	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	if (!check_error(v, 4, 32)) {
		return false;
	}

	v.push_back(5);
	if (!check_error(v, 5, 32)) {
		return false;
	}

	std::cout << status_ok << std::endl;
	return true;
}

bool Test::test_copy_ctor_1() const {
	std::cout << "Test 3: ";
	MyVector v;
	v.push_back(11);
	v.push_back(3);
	v.push_back(7);

	MyVector v1 = v;
	if (!check_error(v1, 3, 32)) {
		return false;
	}

	if (v1.at(0) != v.at(0)) {
		std::cout << status_error << std::endl;
		return false;
	}

	std::cout << status_ok << std::endl;
	return true;
}

bool Test::test_ctor_2() const {
	std::cout << "Test 4: ";
	createVector(32);
	MyVector v = createVector(32);
	if (!check_error(v, 32, 32)) {
		return false;
	}

	v.push_back(100);
	if (!check_error(v, 33, 64)) {
		return false;
	}
	
	std::cout << status_ok << std::endl;
	return true;
}

bool Test::test_copy_ctor_2() const {
	std::cout << "Test 5: ";
	
	const size_t index = 100;
	MyVector v = createVector(index);
	getVector(v);
	
	if (v.pop_back() != index - 1) {
		std::cout << status_error << std::endl;
		return false;
	}
	

	std::cout << status_ok << std::endl;
	return true;
}


bool Test::test_at() const {
	std::cout << "Test 6: ";
	MyVector v = createVector(15);
	if (v.at(0) != 0 || v.at(10) != 10 || v.at(14) != 14)
	{
		std::cout << status_error << std::endl;
		return false;
	}

	v.at(1) = 99;
	if (v.at(1) != 99) {
		std::cout << status_error << std::endl;
		return false;
	}

	v.at(15);
	v.at(-10);

	std::cout << status_ok << std::endl;
	return true;
}

bool Test::test_pop_back() const {
	std::cout << "Test 7: ";
	const size_t vec_size = 1024;
	MyVector v = createVector(vec_size);

	for (size_t i = vec_size - 1; i > 5; --i) {
		v.pop_back();
	}

	if (!check_error(v, 6, 1024)) {
		return false;
	}

	std::cout << status_ok << std::endl;
	return true;
}
