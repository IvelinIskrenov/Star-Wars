#pragma once
#include <iostream>
#include "myString.h"
#include "Jedi.h"

class Planet
{
private :
	myString planetName;
	Jedi* jedi;
	void copy(Planet& other);
	void clear();
public:
	Planet();
	Planet(Planet& other);
	Planet& operator=(Planet& other);
	~Planet();

	void addJedi();
	void removeJedi();
};

