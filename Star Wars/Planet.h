#pragma once
#include <iostream>
#include "Jedi.h"
#include <vector>
#include <string>

const size_t JEDI_START_COUNT = 2;

class Planet
{
private :
	std::string planetName;
	std::vector<Jedi> jedi;
	void copy(const Planet& other);
public:
	Planet();
	Planet(const Planet& other);
	Planet& operator=(const Planet& other);
	std::vector<Jedi> getJedi() { return jedi; };
	std::string getPlanetName() { return planetName; };
	void addJedi(Jedi& other);
	void removeJedi(Jedi& other);
};

