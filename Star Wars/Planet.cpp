#include "Planet.h"
#include <vector>
#include "Jedi.h"

void Planet::copy(const Planet& other)
{
	planetName = other.planetName;
	jedi.clear();
	for (size_t i = 0; i < other.jedi.size(); i++)
	{
		jedi.push_back(other.jedi[i]);
	}
}

Planet::Planet()
{
	planetName = "";
}

Planet::Planet(const Planet& other)
{
	copy(other);
}

Planet& Planet::operator=(const Planet& other)
{
	if (&other != this)
	{
		copy(other);
	}
	return *this;
}

void Planet::addJedi(Jedi& other)
{
	size_t length = jedi.size();
	bool jediExists = false;
	for (size_t i = 0; i < length; i++)
	{
		if (jedi[i].getName() == other.getName())
		{
			jediExists = true;
		}
	}
	if (jediExists = true)
	{
		jedi.push_back(other);
	}
	else
	{
		std::cout << "There";
	}
}

void Planet::removeJedi(Jedi& other)
{
	size_t length = jedi.size();
	bool jediExists = false;
	for (size_t i = 0; i < length; i++)
	{
		if (jedi[i].getName() == other.getName())
		{
			jediExists = true;
		}
	}

}
