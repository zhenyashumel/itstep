#pragma once
class Equal
{
	int value;
public:
	Equal(int tmp) : value(tmp) {};
	bool operator()(int val)
	{
		return val == value;
	}

};


class Multiple
{
	int value;
public:
	Multiple(int tmp) : value(tmp) {};
	bool operator()(int val)
	{
		return !(val % value);
	}
};


class Search
{
	int value;
public:
	Search(int tmp) : value(tmp) {};
	bool operator()(int val)
	{
		while (val > 10)
			val /= 10;

		return val == value;
	}
};

class Square
{
	int value;
public:
	Square(int tmp) : value(tmp) {};
	bool operator()(int val)
	{
		for (int i = 1; i <= value; ++i)
		{
			if (i * i == val)
				return true;
		}
		return false;
	}
};
