#include "Jedi.h"

void Jedi::copy(Jedi& other)
{
	if (other.name == "")
	{
		std::cout << "There isn't a jedi name !\n";
	}
	else
	{
		name = other.name;
	}
	if (checkRanks(other.rank))
	{
		rank = other.rank;
	}
	else
	{
		std::cout << "Invalid rank !\n";
	}
	if (other.age < 0 || other.age > 100)
	{
		std::cout << "Invalid age !";
	}
	else
	{
		age = other.age;
	}
	if (other.lightsaberColor == "")
	{
		std::cout << "There isn't a lightsaberColor !\n";
	}
	else
	{
		lightsaberColor = other.lightsaberColor;
	}
	if (other.power < 0)
	{
		std::cout << "Power can't be under 0 !\n";
	}
	else
	{
		power = other.power;
	}
}


Jedi& Jedi::operator=(Jedi& other)
{
	if (&other != this)
	{
		copy(other);
	}
	return *this;
}

//possible mistake
bool Jedi::checkRanks(myString currentRank)
{
	if (currentRank != "YOUNGLING" || "INITIATE" || "PADAWAN" || "KNIGHT-ASPIRANT" || "KNIGHT" || "MASTER" || "BATTLE_MASTER" || "GRAND_MASTER")
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
}
