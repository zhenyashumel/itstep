#pragma once

#include "MyVector.h"

class Test {
public:
	void test() const;
private:
	const char* status_ok = "OK";
	const char* status_error = "Error";

	bool check_error(MyVector&, const int, const int) const;
	bool test_ctor_1() const;
	bool test_ctor_2() const;
	bool test_copy_ctor_1() const;
	bool test_copy_ctor_2() const;
	bool test_at() const;
	bool test_push_back() const;
	bool test_pop_back() const;

	void getVector(MyVector) const;
	MyVector createVector(const size_t) const;
};
