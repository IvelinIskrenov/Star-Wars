#pragma once
#include <iostream>
#include <string>
#include "Jedi.h"
#include "Validations.h"

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
	std::vector<Jedi>& getJedi() { return jedi; };
	std::string getPlanetName() { return planetName; };
	void addJedi(const Jedi& jediToAdd);
	void removeJedi(size_t removeIndex);
	friend std::ostream& operator<<(std::ostream&, const Planet& planet);
};

