#include "Jedi.h"

void Jedi::copy(const Jedi& other)
{
	name = other.name;
	if (isRankValid(other.rank))
	{
		rank = other.rank;
	}
	else
	{
		std::cout << "Invalid rank!\n";
	}
	if (ageValid(other.age))
	{
		age = other.age;
	}
	else
	{
		std::cout << "Invalid age!\n";
	}
	
	lightsaberColor = other.lightsaberColor;
	power = other.power;
	planetName = other.planetName;
}


Jedi::Jedi(const Jedi& other)
{
	copy(other);
}

Jedi& Jedi::operator=(const Jedi& other)
{
	if (&other != this)
	{
		copy(other);
	}
	return *this;
}

bool Jedi::operator==(const Jedi& other)
{
	if (name != other.name)
	{
		return false;
	}
	return true;
}

Jedi::Jedi()
{
	name = "no name";
	rank = "no rank";
	age = 0;
	lightsaberColor = "no lightsaber";
	power = 0;
	planetName = "no planet";
}

Jedi::Jedi(const std::string _name, const std::string _rank, unsigned _age, const std::string _lightsaberColor, double _power, const std::string _planetName)
{
	name = _name;
	if (isRankValid(_rank))
	{
		rank = _rank;
	}
	else
	{
		std::cout << "Invalid rank!\n";
	}
	if (ageValid(_age))
	{
		age = _age;
	}
	else
	{
		std::cout << "Invalid age!\n";
	}

	lightsaberColor = _lightsaberColor;
	power = _power;
	planetName = _planetName;
}
