#pragma once
#include<iostream>
#include<string>


class Pet
{
protected:
	std::string name;
	std::string petType;
	size_t age;
	size_t mass;
	std::string who;//пол животного 

public:
	Pet(std::string, size_t, size_t, std::string, std::string);
	
	virtual ~Pet() {}
	virtual void sound() const = 0;
	void show() const;
	void type() const;
	virtual void info() const;
};



class Bird
{
protected:
	int speed;
	bool fly;
public:
	Bird() {};
	virtual int getSpeed() = 0;
	virtual ~Bird() {};

};

class Dog :public Pet
{
	std::string colour;
public:
	Dog(std::string nam, size_t ag, size_t mas, std::string pol, std::string color):
		Pet(nam, ag, mas, pol, color)
	{
		petType = "Dog";
	}
	void sound() const override;

	
};

class Cat :public Pet
{
	std::string colour;
public:
	Cat(std::string nam, size_t ag, size_t mas, std::string pol, std::string color) :
		Pet(nam, ag, mas, pol, color)
	{
		petType = "Cat";
	}
	void sound() const override;

};


class Hamster :public Pet
{
	std::string colour;
public:
	Hamster(std::string nam, size_t ag, size_t mas, std::string pol, std::string color) :
		Pet(nam, ag, mas, pol, color)
	{
		petType = "Hamster";
	}
	void sound() const override;
};


class Parrot :public Pet, public Bird
{
	std::string colour;
public:
	Parrot(std::string nam, size_t ag, size_t mas, std::string pol, std::string color,bool can, int sp) :
		Pet(nam, ag, mas, pol, color)
	{
		petType = "Parrot";
		fly = can;
		speed = sp;

	}
	void info() const override;
	int getSpeed()
	{
		return speed;
	}
	void sound() const override;
	
};


