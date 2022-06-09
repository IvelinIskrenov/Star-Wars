#pragma once
#include "myString.h"
#include<iostream>

class Jedi
{
private:
	myString name;
	myString rank;
	unsigned age;
	myString lightsaberColor;
	double power;
	void copy(Jedi& other);
public:
	bool checkRanks(myString currentRank);
	Jedi();
	Jedi(myString _name, myString _rank, unsigned _age, myString _lightsaberColor, double _power)
		: name(_name), rank(_rank), age(_age), lightsaberColor(_lightsaberColor), power(_power){};
	Jedi(Jedi& other)
		: name(other.name), rank(other.rank), age(other.age), lightsaberColor(other.lightsaberColor), power(other.power) {};
	Jedi& operator=(Jedi& other);
	//Проверява дали ранга е правилен
	bool checkRanks(myString currentRank);
};

