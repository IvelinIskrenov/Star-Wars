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

void Jedi::setPower(double multiplier)
{
	if (multiplier > 0)
	{
		power *= multiplier;
	}
	else
	{
		std::cout << "Multiplier must be positive\n";
	}
}

std::string Jedi::getJediRank()
{
	return rank;
}

void Jedi::setJediRank(std::string newRank)
{
		if (isRankValid(newRank) == true)
		{
			rank = newRank;
		}
		else
		{
			std::cout << "There is no rank with that name!";
		}
}

std::ostream& operator<<(std::ostream& out,const Jedi& jedi)
{
	out << "Name:" << jedi.name << ",  rank:" << jedi.rank << ",  age:" << jedi.age
		<< ",  lightsaberColor:" << jedi.lightsaberColor << ",  power:" << jedi.power
		<< ", lived on planet:" << jedi.planetName << '\n';
	return out;
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
