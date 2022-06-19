#pragma once
#include<iostream>
class Jedi;
class Planet;
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
	//Името на планетата която джедая населява
	std::string planetName;
	void copy(const Jedi& other);
public:
	Jedi();
	Jedi(const std::string _name, const std::string _rank, unsigned _age, const  std::string _lightsaberColor, double _power, const std::string _planetName);
	Jedi(const Jedi& other);
	Jedi& operator=(const Jedi& other);
	bool operator==(const Jedi& other);
	void setPower(double multiplier);
	std::string getJediRank();
	double getPower() { return power; };
	std::string getLightsaberColor() { return lightsaberColor; };
	unsigned getAge() { return age; };
	void setJediRank(std::string newRank);
	//Проверява дали ранга е правилен
	std::string getName() { return name; };
};

