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
	jedi.clear();
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

void Planet::setPlanetName(std::string _planetName)
{
	planetName = _planetName;
}

void Planet::addJedi(const Jedi& jediToAdd)
{
	jedi.push_back(jediToAdd);
}

void Planet::removeJedi(size_t removeIndex)
{
	jedi.erase(jedi.begin() + removeIndex);
}

std::ostream& operator<<(std::ostream& out, const Planet& planet)
{
	size_t length = planet.jedi.size();
	for (size_t i = 0; i < length; i++)
	{
		out << planet.jedi[i];
	}
	return out;
}
