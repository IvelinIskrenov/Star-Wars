#include "Validations.h"
#include <iostream>

bool jediExists(std::vector<Planet> planets, std::string passedJediName)
{
	size_t length = planets.size();
	for (size_t i = 0; i < length; i++)
	{
		size_t jediCount = planets[i].getJedi().size();
		for (size_t i = 0; i < jediCount; i++)
		{
			if (planets[i].getJedi()[i].getName() == passedJediName)
			{
				return true;
			}
		}
	}
	return false;
}

bool planetExists(std::vector<Planet> planets, std::string passedPlanetName)
{
	size_t length = planets.size();
	for (size_t i = 0; i < length; i++)
	{
		if (planets[i].getPlanetName() == passedPlanetName)
		{
			return true;
		}
	}
	return false;
}

bool isRankValid(std::string passedRank)
{
	if ((passedRank == "YOUNGLING") || (passedRank == "INITIATE") || (passedRank == "PADAWAN")
		|| (passedRank == "KNIGHT-ASPIRANT") || (passedRank == "KNIGHT") || (passedRank == "MASTER")
		|| (passedRank == "BATTLE_MASTER") || (passedRank == "GRAND_MASTER"))
	{
		return true;
	}
	return false;
}

bool ageValid(unsigned passedAge)
{
	if (passedAge > 0)
	{
		return true;
	}
	return false;
}
