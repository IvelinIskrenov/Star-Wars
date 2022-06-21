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
	//джедаите които населяват тази планета
	std::vector<Jedi> jedi;
	void copy(const Planet& other);
public:
	Planet();
	Planet(const Planet& other);
	Planet& operator=(const Planet& other);
	std::vector<Jedi>& getJedi() { return jedi; };
	std::string getPlanetName() { return planetName; };
	void setPlanetName(std::string _planetName);
	//добавя джедай на планетата
	void addJedi(const Jedi& jediToAdd);
	//премахва джедай от планетата
	void removeJedi(size_t removeIndex);
	friend std::ostream& operator<<(std::ostream&, const Planet& planet);
};

