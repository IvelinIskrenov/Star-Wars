#pragma once
#include<iostream>
#include <vector>
#include "Validations.h"

class Jedi
{
private:
	std::string name;
	std::string rank;
	unsigned age;
	std::string lightsaberColor;
	double power;
	void copy(const Jedi& other);
public:
	Jedi();
	Jedi(const std::string _name, const std::string _rank, unsigned _age, const  std::string _lightsaberColor, double _power);
	Jedi(const Jedi& other);
	Jedi& operator=(const Jedi& other);
	bool operator==(const Jedi& other);
	//Проверява дали ранга е правилен
	std::string getName() { return name; };
};

