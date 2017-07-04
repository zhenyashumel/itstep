#pragma once
#include<iostream>
#include<string>

class Transport
{

public:
	Transport() {};
	virtual ~Transport() = default;

	virtual std::string move() = 0;
};


class Automobile: public Transport
{
protected:
	std::string model;
	size_t year;
	size_t speed;
	
public:
	Automobile(const std::string, const size_t, const size_t);
	virtual ~Automobile();


	std::string getModel() const;
	size_t getYear() const;
	size_t getSpeed() const;

	void setModel(const std::string);
	void setSpeed(const size_t);


	size_t computeDistance(const size_t time) const;
	virtual void getInfo() const;

	std::string move() override;

};


class Taxi : public Automobile
{
protected:

	size_t rate;
	size_t money;
	static int counter;
public:

	Taxi(const std::string, const size_t, const size_t, const size_t);	
	~Taxi() {}


	size_t getRate() const;
	size_t getMoney() const;
	void setRate(const size_t val);
	static int getCounter();


	size_t pay(const size_t time) const;
	void getInfo() const override;
	
};
