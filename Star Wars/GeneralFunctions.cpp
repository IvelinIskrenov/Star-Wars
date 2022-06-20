#include "GeneralFunctions.h"
#include <iostream>
#include "Validations.h"

size_t findPlanet(std::vector<Planet> cosmicPlanets, std::string planetName)
{
	size_t length = cosmicPlanets.size();
	for (size_t i = 0; i < length; i++)
	{
		if (cosmicPlanets[i].getPlanetName() == planetName)
		{
			return i;
		}
	}
	return -1;
}

void createJedi(std::vector<Planet> cosmicPlanets)
{
	std::string jediName;
	std::cin >> jediName;
	std::string jediRank;
	std::cin >> jediRank;
	while (isRankValid(jediRank) == false)
	{
		std::cin >> jediRank;
	}
	unsigned age;
	std::cin >> age;
	std::string lightsaberColor;
	std::cin >> lightsaberColor;
	double power;
	std::cin >> power;
	std::string planetName;
	std::cin >> planetName;
	Jedi jedi(jediName,jediRank,age,lightsaberColor,power,planetName);
	if (jediExists(cosmicPlanets,jediName) == true)
	{
		std::cout << "Cant create new jedi,there is a jedi with same name!\n";
	}
	if (planetExists(cosmicPlanets,planetName) == true && jediExists(cosmicPlanets, jediName) == false)
	{
		size_t planetNumber = findPlanet(cosmicPlanets,planetName);
		if (planetNumber != -1)
		{
			cosmicPlanets[planetNumber].addJedi(jedi);
			std::cout << "Jedi added!\n";
		}
		else
		{
			std::cout << "Cant create new jedi,there is no planet with that name!\n";
		}
	}
	else
	{
		std::cout << "Cant create new jedi,there is no planet with that name!\n";
	}
}

void removeJedi(std::vector<Planet> cosmicPlanets)
{
	std::string jediName;
	std::cin >> jediName;
	std::string planetName;
	std::cin >> planetName;
	if (jediExists(cosmicPlanets, jediName) == false)
	{
		std::cout << "There isn't a jedi with that name!\n";
	}
	if (planetExists(cosmicPlanets, planetName) == true && jediExists(cosmicPlanets, jediName) == true)
	{
		size_t length = cosmicPlanets.size();
		for (size_t i = 0; i < length; i++)
		{
			if (cosmicPlanets[i].getPlanetName() == planetName)
			{
				cosmicPlanets[i].removeJedi(i);
				std::cout << "Jedi removed!\n";
				break;
			}
		}
	}
	else
	{
		std::cout << "Cant create new jedi,there is no planet with that name!\n";
	}
}

void promoteJedi(std::vector<Planet> cosmicPlanets)
{
	double multiplier;
	std::cin >> multiplier;
	std::string currentJedi;
	std::cin >> currentJedi;
	if (jediExists(cosmicPlanets,currentJedi))
	{
		if (multiplier > 0)
		{
			size_t length = cosmicPlanets.size();
			for (size_t i = 0; i < length; i++)
			{
				if (cosmicPlanets[i].getJedi()[i].getName() == currentJedi)
				{
					std::string tempRanks[8];
					tempRanks[0] = "YOUNGLING";
					tempRanks[1] = "INITIATE";
					tempRanks[2] = "PADAWAN";
					tempRanks[3] = "KNIGHT-ASPIRANT";
					tempRanks[4] = "KNIGHT";
					tempRanks[5] = "MASTER";
					tempRanks[6] = "BATTLE_MASTER";
					tempRanks[7] = "GRAND_MASTER";
					for (size_t j = 0; j < 7; j++)
					{
						if (cosmicPlanets[i].getJedi()[i].getJediRank() == tempRanks[j])
						{
							cosmicPlanets[i].getJedi()[i].setJediRank(tempRanks[j + 1]);
							break;
						}
						else
						{
							std::cout << "Jedi can't be promote more then GRAND_MASTER\n";
						}
					}
					double newPower = 1 + multiplier;
					cosmicPlanets[i].getJedi()[i].setPower(newPower);
					break;
				}
			}
		}
		else
		{
			std::cout << "Multiplier must be possitive!\n";
		}
	}
}

void demoteJedi(std::vector<Planet> cosmicPlanets)
{
	double multiplier;
	std::cin >> multiplier;
	std::string currentJedi;
	std::cin >> currentJedi;
	if (jediExists(cosmicPlanets, currentJedi))
	{
		if (multiplier > 0)
		{
			size_t length = cosmicPlanets.size();
			for (size_t i = 0; i < length; i++)
			{
				if (cosmicPlanets[i].getJedi()[i].getName() == currentJedi)
				{
					std::string tempRanks[8];
					tempRanks[0] = "YOUNGLING";
					tempRanks[1] = "INITIATE";
					tempRanks[2] = "PADAWAN";
					tempRanks[3] = "KNIGHT-ASPIRANT";
					tempRanks[4] = "KNIGHT";
					tempRanks[5] = "MASTER";
					tempRanks[6] = "BATTLE_MASTER";
					tempRanks[7] = "GRAND_MASTER";
					for (size_t j = 1; j < 8; j++)
					{
						if (cosmicPlanets[i].getJedi()[i].getJediRank() == tempRanks[j])
						{
							cosmicPlanets[i].getJedi()[i].setJediRank(tempRanks[j - 1]);
							break;
						}
						else
						{
							std::cout << "Jedi can't be demote more then YOUNGLING\n";
						}
					}
					double newPower = 1 - multiplier;
					cosmicPlanets[i].getJedi()[i].setPower(newPower);
					break;
				}
			}
		}
		else
		{
			std::cout << "Multiplier must be possitive!\n";
		}
	}
}

void getStrongestJedi(std::vector<Planet> cosmicPlanets)
{
	std::string planetName;
	std::cin >> planetName;
	size_t planetNumber = findPlanet(cosmicPlanets,planetName);
	Jedi strongestJedi;
	if (planetNumber != -1)
	{
		size_t jediCount = cosmicPlanets[planetNumber].getJedi().size();
		if (jediCount > 0)
		{
			strongestJedi = cosmicPlanets[planetNumber].getJedi()[0];
			for (size_t j = 0; j < jediCount; j++)
			{
				if (strongestJedi.getPower() < cosmicPlanets[planetNumber].getJedi()[j].getPower())
				{
					strongestJedi = cosmicPlanets[planetNumber].getJedi()[j];
				}
			}
			std::cout << "The strongest jedi " << strongestJedi.getName() << " with rank "
				<< strongestJedi.getJediRank() << ", light saber color " << strongestJedi.getLightsaberColor()
				<< ", age " << strongestJedi.getAge() << " have " << strongestJedi.getPower() << " power !\n";
		}
		else
		{
			std::cout << "There is no jedi on this planet!\n";
		}
	}
	else
	{
		std::cout << "There is no planet with that name!\n";
	}
}

void getYongestJedi(std::vector<Planet> cosmicPlanets)
{
	std::string planetName;
	std::cin >> planetName;
	std::string rankJedi;
	std::cin >> rankJedi;
	size_t planetNumber = findPlanet(cosmicPlanets,planetName);
	Jedi yongestJedi;

	//search the planet
	if (planetNumber != -1)
	{
		size_t jediCount = cosmicPlanets[planetNumber].getJedi().size();
		if (jediCount > 0)
		{
			bool yongestJediExists = false;
			//search the first jedi with rank YOUNGLING
			for (size_t j = 0; j < jediCount; j++)
			{
				if (cosmicPlanets[planetNumber].getJedi()[j].getJediRank() == "YOUNGLING")
				{
					yongestJedi = cosmicPlanets[planetNumber].getJedi()[j];
					yongestJediExists = true;
					//searching jedi with smallest name
					for (size_t k = j; k < jediCount; k++)
					{
						if (yongestJedi.getName() < cosmicPlanets[planetNumber].getJedi()[k].getName())
						{
							yongestJedi = cosmicPlanets[planetNumber].getJedi()[k];
						}
					}
					break;
				}
			}
			if (yongestJediExists == false)
			{
				std::cout << "There is no jedi with rank YOUNGLING!\n";
			}
			else
			{
				std::cout << "The yongest jedi " << yongestJedi.getName() << " with rank "
					<< yongestJedi.getJediRank() << ", light saber color " << yongestJedi.getLightsaberColor()
					<< ", age " << yongestJedi.getAge() << " have " << yongestJedi.getPower() << " power !\n";
			}
		}
		else
		{
			std::cout << "There is no jedi on this planet!\n";
		}
	}
	else
	{
		std::cout << "There is no planet with that name!\n";
	}
}

void getMostUsedSaberColor(std::vector<Planet> cosmicPlanets)
{
	std::string jediRank;
	std::cin >> jediRank;
	std::string planetName;
	std::cin >> planetName;
	size_t planetNumber = findPlanet(cosmicPlanets,planetName);
	if (planetNumber != -1)
	{
		Planet copyPlanet = cosmicPlanets[planetNumber];
		size_t length = copyPlanet.getJedi().size();
		//filter the planet -> only ranks we need
		for (size_t i = 0; i < length; i++)
		{
			if (copyPlanet.getJedi()[i].getJediRank() != jediRank)
			{
				copyPlanet.getJedi().erase(copyPlanet.getJedi().begin() + i);
				length--;
			}
		}
		//-> get the saberColor
		length = copyPlanet.getJedi().size();
		std::string mainColorSaber;
		int mainCSaberCount = 0;
		if (length > 0)
		{
			mainColorSaber = copyPlanet.getJedi()[0].getLightsaberColor();
			mainCSaberCount++;
		}
		for (size_t i = 1; i < length; i++)
		{
			if (copyPlanet.getJedi()[i].getLightsaberColor() == mainColorSaber)
			{
				copyPlanet.getJedi().erase(copyPlanet.getJedi().begin() + i);
				mainCSaberCount++;
				length--;
			}
		}
		while (length != 0)
		{
			std::string currentColorLightsaber;
			int currentCSaberCount = 0;
			currentColorLightsaber = copyPlanet.getJedi()[0].getLightsaberColor();
			currentCSaberCount++;
			for (size_t i = 1; i < length; i++)
			{
				if (copyPlanet.getJedi()[i].getLightsaberColor() == currentColorLightsaber)
				{
					copyPlanet.getJedi().erase(copyPlanet.getJedi().begin() + i);
					currentCSaberCount++;
					length--;
				}
			}
			if (mainCSaberCount < currentCSaberCount)
			{
				mainColorSaber = currentColorLightsaber;
			}
		}
		std::cout << "Main color saber which is used from jedis with rank " << jediRank << " on planet " << planetName
			<< " is a " << mainColorSaber << " !\n";
	}
	else
	{
		std::cout << "There is no planet with that name!\n";
	}
}

void testProgram()
{	
	std::cout << "Commands:\n";
	std::cout << "create_jedi : Create jedi\n";
	std::cout << "removeJedi : Remove jedi\n";
	std::cout << "promote_jedi : Promote jedi \n";
	std::cout << "demote_jedi : Demote jedi\n";

	std::cout << "get_strongest_jedi : Print information about the strongest jedi on a given planet \n";
	std::cout << "get_youngest_jedi : Print information about the youngest jedi on a given planet\n";
	std::cout << "get_most_used_saber_color : Returns the most common color of light sword in the given rank of the planet\n";
	std::cout << "get_most_used_saber_colorGM : Returns the most common color of light sword on a planet that enjoys at least one GRAND_MASTER\n";
	std::cout << "print_planet : Displays the name of the planet and the jedi inhabiting it,sort by rank\n";
	std::cout << "print_jedi : Print jedi information\n";

	std::string command;
	std::cin >> command;

	std::vector<Planet> cosmicPlanets;

	while (command != "exit")
	{
		if (command == "create_jedi")
		{
			createJedi(cosmicPlanets);
		}
		else if (command == "removeJedi")
		{
			removeJedi(cosmicPlanets);
		}
		else if (command == "promote_jedi")
		{

		}
		else if (command == "demote_jedi")
		{

		}
		else if (command == "get_strongest_jedi")
		{

		}
		else if (command == "get_youngest_jedi")
		{

		}
		else if (command == "get_most_used_saber_color")
		{

		}
		else if (command == "get_most_used_saber_colorGM")
		{

		}
		else if (command == "print_planet")
		{

		}
		else if (command == "print_jedi")
		{

		}
		else if (command == "print_planetsName")
		{

		}
		else
		{
			std::cout << "Invalid command ! Try again !\n";
		}
	}
}

//myString productName;
//
//std::cout << "Enter product name: ";
//std::cin >> productName;
//Product currentProduct;
//currentProduct.setNameProduct(productName);
