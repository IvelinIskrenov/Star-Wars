#include "Planet.h"
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
	jedi.emplace_back();
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

void Planet::addJedi(const Jedi& jediToAdd)
{
	jedi.push_back(jediToAdd);
}

void Planet::removeJedi(size_t removeIndex)
{
	jedi.erase(jedi.begin() + removeIndex);
}
