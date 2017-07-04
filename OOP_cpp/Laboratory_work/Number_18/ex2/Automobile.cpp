#include "Automobile.h"



Automobile::Automobile(const std::string mod, const size_t yr, const size_t v):
	model(mod), year(yr), speed(v)
{
}


Automobile:: ~Automobile()
{
}


std::string Automobile::getModel() const
{
	return model;
}


size_t Automobile::getYear() const
{
	return year;
}


size_t Automobile::getSpeed() const
{
	return speed;
}

void Automobile::setModel(const std::string val)
{
	model = val;
}


void Automobile::setSpeed(const size_t val)
{
	speed = val;
}


size_t Automobile::computeDistance(const size_t time) const
{
	return speed * time;
}


void Automobile::getInfo() const
{
	std::cout << "Model: " << model << std::endl
		<< "Year of issue: " << year << std::endl
		<< "Average speed: " << speed << std::endl;
}

std::string Automobile:: move()
{
	return "Terrestrial...";
}




int Taxi::counter = 0;

Taxi::Taxi(const std::string mod, const size_t yr, const size_t v, const size_t rat): 
	Automobile(mod, yr, v), rate(rat), money(0)
{
	++counter;
}


size_t Taxi::getRate() const
{
	return rate;
}


size_t Taxi::getMoney() const
{
	return money;
}


void Taxi::setRate(const size_t val) 
{
	rate = val;
}


size_t Taxi::pay(const size_t time) const
{
	return computeDistance(time) * rate;
}


int Taxi::getCounter() 
{
	return counter;
}


void Taxi::getInfo() const
{
	std::cout << "Model: " << model << std::endl
		<< "Year of issue: " << year << std::endl
		<< "Average speed: " << speed << std::endl
		<< "Rate: " << rate << std::endl;
}

