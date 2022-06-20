#include "GeneralFunctions.h"
#include <iostream>
#include "Validations.h"
#include <fstream>

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
	std::cout << "Enter jedi name which you want to add:\n";
	std::string jediName;
	std::cin >> jediName;

	std::cout << "Enter jedi rank:\n";
	std::string jediRank;
	do
	{
		std::cin >> jediRank;
		if (isRankValid(jediRank) == false)
		{
			std::cout << "Invalid rank, try again:\n";
		}
	} while (isRankValid(jediRank) == false);

	std::cout << "Enter jedi age:\n";
	unsigned age = 0;

	do
	{
		std::cin >> age;
		if (ageValid(age) == false)
		{
			std::cout << "Invalid age, try again:\n";
		}
	} while (ageValid(age) == false);

	std::cout << "Enter jedi light saber color:\n";
	std::string lightSaberColor;
	std::cin >> lightSaberColor;
	std::cout << "Enter jedi power:\n";
	double power;
	std::cin >> power;
	std::cout << "Enter jedi's planet name:\n";
	std::string planetName;
	std::cin >> planetName;
	Jedi jedi(jediName,jediRank,age,lightSaberColor,power,planetName);
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
	std::cout << "Enter jedi name which you want to remove:\n";
	std::string jediName;
	std::cin >> jediName;
	std::cout << "Enter jedi's planet name:\n";
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
	std::cout << "Enter multiplier index how much you want to increase jedi's power:\n";
	double multiplier;
	std::cin >> multiplier;
	std::cout << "Enter jedi name which you want to promote:\n";
	std::string currentJediName;
	std::cin >> currentJediName;
	if (jediExists(cosmicPlanets,currentJediName))
	{
		if (multiplier > 0)
		{
			size_t length = cosmicPlanets.size();
			for (size_t i = 0; i < length; i++)
			{
				if (cosmicPlanets[i].getJedi()[i].getName() == currentJediName)
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
	std::cout << "Enter multiplier index how much you want to decrease jedi's power:\n";
	double multiplier;
	std::cin >> multiplier;
	std::cout << "Enter jedi name which you want to demote:\n";
	std::string currentJediName;
	std::cin >> currentJediName;
	if (jediExists(cosmicPlanets, currentJediName))
	{
		if (multiplier > 0)
		{
			size_t length = cosmicPlanets.size();
			for (size_t i = 0; i < length; i++)
			{
				if (cosmicPlanets[i].getJedi()[i].getName() == currentJediName)
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
	std::cout << "Enter planet name:\n";
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
	std::cout << "Enter planet name:\n";
	std::string planetName;
	std::cin >> planetName;
	std::cout << "Enter jedi rank:\n";
	std::string jediRank;
	do
	{
		std::cin >> jediRank;
		if (isRankValid(jediRank) == false)
		{
			std::cout << "Invalid rank, try again:\n";
		}
	} while (isRankValid(jediRank) == false);

	size_t planetNumber = findPlanet(cosmicPlanets,planetName);
	Jedi yongestJedi;

	//search the planet
	if (planetNumber != -1)
	{
		size_t jediCount = cosmicPlanets[planetNumber].getJedi().size();
		if (jediCount > 0)
		{
			bool yongestJediExists = false;
			//search the first jedi with the given rank
			for (size_t j = 0; j < jediCount; j++)
			{
				if (cosmicPlanets[planetNumber].getJedi()[j].getJediRank() == jediRank)
				{
					yongestJedi = cosmicPlanets[planetNumber].getJedi()[j];
					yongestJediExists = true;
					//searching jedi with smallest name
					for (size_t k = j; k < jediCount; k++)
					{
						if (yongestJedi.getAge() < cosmicPlanets[planetNumber].getJedi()[k].getAge())
						{
							yongestJedi = cosmicPlanets[planetNumber].getJedi()[k];
						}
					}
					for (size_t i = j; i < jediCount; i++)
					{
						if (yongestJedi.getAge() == cosmicPlanets[planetNumber].getJedi()[i].getAge() &&
							yongestJedi.getName() < cosmicPlanets[planetNumber].getJedi()[i].getName())
						{
							yongestJedi = cosmicPlanets[planetNumber].getJedi()[i];
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
	std::cout << "Enter jedi rank which you want to get the most used saber color:\n";
	std::string jediRank;
	std::cin >> jediRank;
	std::cout << "Enter planet name:\n";
	std::string planetName;
	std::cin >> planetName;
	size_t planetNumber = findPlanet(cosmicPlanets,planetName);
	if (planetNumber != -1)
	{
		Planet copyPlanet;
		copyPlanet = cosmicPlanets[planetNumber];
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

void getMostUsedSaberColorGM(std::vector<Planet> cosmicPlanets)
{
	std::cout << "Enter planet name:\n";
	std::string planetName;
	std::cin >> planetName;
	size_t planetNumber = findPlanet(cosmicPlanets, planetName);
	if (planetNumber != -1)
	{
		Planet copyPlanet;
		copyPlanet = cosmicPlanets[planetNumber];
		size_t length = copyPlanet.getJedi().size();
		for (size_t i = 0; i < length; i++)
		{
			if (copyPlanet.getJedi()[i].getJediRank() != "GRAND_MASTER")
			{
				copyPlanet.getJedi().erase(copyPlanet.getJedi().begin() + i);
				length--;
			}
		}

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
		std::cout << "Main color saber which is used from jedis with rank GRAND_MASTER on planet " << planetName
			<< " is a " << mainColorSaber << " !\n";
	}
	else
	{
		std::cout << "There is no planet with that name!\n";
	}
}

int getJediRankNumber(std::string jediRank)
{
	if (jediRank == "YOUNGLING")
	{
		return 1;
	}
	else if (jediRank == "INITIATE")
	{
		return 2;
	}
	else if (jediRank == "PADAWAN")
	{
		return 3;
	}
	else if (jediRank == "KNIGHT-ASPIRANT")
	{
		return 4;
	}
	else if (jediRank == "KNIGHT")
	{
		return 5;
	}
	else if (jediRank == "MASTER")
	{
		return 6;
	}
	else if (jediRank == "BATTLE_MASTER")
	{
		return 7;
	}
	else if (jediRank == "GRAND_MASTER")
	{
		return 8;
	}
	else
	{
		return 0;
	}
}

void print(std::vector<Planet> cosmicPlanets)
{
	std::string planetName;
	std::cin >> planetName;
	size_t planetNumber = findPlanet(cosmicPlanets, planetName);
	if (planetNumber != -1)
	{
		Jedi temp;
		size_t length = cosmicPlanets[planetNumber].getJedi().size();
		//bubble sort 
		//possible mistake
		for (size_t i = 0; i < length; i++)
		{
			for (size_t j = i + 1; j < length; j++)
			{
				if (getJediRankNumber(cosmicPlanets[planetNumber].getJedi()[j].getJediRank()) 
					< getJediRankNumber(cosmicPlanets[planetNumber].getJedi()[i].getJediRank()))
				{
					temp = cosmicPlanets[planetNumber].getJedi()[i];
					cosmicPlanets[planetNumber].getJedi()[i] = cosmicPlanets[planetNumber].getJedi()[j];
					cosmicPlanets[planetNumber].getJedi()[j] = temp;
				}
				else if (getJediRankNumber(cosmicPlanets[planetNumber].getJedi()[j].getJediRank())
					== getJediRankNumber(cosmicPlanets[planetNumber].getJedi()[i].getJediRank()) 
					&& (cosmicPlanets[planetNumber].getJedi()[j].getName() 
						< cosmicPlanets[planetNumber].getJedi()[i].getName()))
				{
					temp = cosmicPlanets[planetNumber].getJedi()[i];
					cosmicPlanets[planetNumber].getJedi()[i] = cosmicPlanets[planetNumber].getJedi()[j];
					cosmicPlanets[planetNumber].getJedi()[j] = temp;
				}
			}
		}
		for (size_t i = 0; i < length; i++)
		{
			std::cout << "Jedi " << cosmicPlanets[planetNumber].getJedi()[i].getName() << " with rank "
				<< cosmicPlanets[planetNumber].getJedi()[i].getJediRank() << ", light saber color " 
				<< cosmicPlanets[planetNumber].getJedi()[i].getLightsaberColor()
				<< " and power " << cosmicPlanets[planetNumber].getJedi()[i].getPower() << "!\n";
		}
	}
	else
	{
		std::cout << "There is no planet with that name!\n";
	}
}

void printJedi(std::vector<Planet> cosmicPlanets)
{
	std::string jediName;
	std::cin >> jediName;

	bool jediFound = false;
	size_t length = cosmicPlanets.size();
	for (size_t i = 0; i < length; i++)
	{
		size_t jediCount = cosmicPlanets[i].getJedi().size();
		for (size_t j = 0; j < jediCount; j++)
		{
			if (cosmicPlanets[i].getJedi()[j].getName() == jediName)
			{
				std::cout << "The jedi " << cosmicPlanets[i].getJedi()[j].getName() << " with rank "
					<< cosmicPlanets[i].getJedi()[j].getJediRank() << ", light saber color " << cosmicPlanets[i].getJedi()[j].getLightsaberColor()
					<< ", age " << cosmicPlanets[i].getJedi()[j].getAge() << " have " << cosmicPlanets[i].getJedi()[j].getPower() << " power live on planet "
					<< cosmicPlanets[i].getPlanetName() << "!\n";
				jediFound = true;
				break;
			}
		}
		if (jediFound == true)
		{
			break;
		}
	}
}

void concatPlanets(std::vector<Planet> cosmicPlanets)
{
	std::string firstPlanetName, secondPlanetName;
	std::cin >> firstPlanetName;
	std::cin >> secondPlanetName;
	std::vector <Jedi> concatPlanet;
	size_t planetNumber = findPlanet(cosmicPlanets, firstPlanetName);
	size_t length = cosmicPlanets[planetNumber].getJedi().size();

	for (size_t i = 0; i < length; i++)
	{
		concatPlanet.push_back(cosmicPlanets[planetNumber].getJedi()[i]);
	}

	planetNumber = findPlanet(cosmicPlanets, secondPlanetName);
	length = cosmicPlanets[planetNumber].getJedi().size();
	for (size_t i = 0; i < length; i++)
	{
		concatPlanet.push_back(cosmicPlanets[planetNumber].getJedi()[i]);
	}

	Jedi temp;
	length = concatPlanet.size();
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i + 1; j < length; j++)
		{
			if (concatPlanet[j].getName() < concatPlanet[i].getName())
			{
				temp = concatPlanet[i];
				concatPlanet[i] = concatPlanet[j];
				concatPlanet[j] = temp;
			}
		}
	}
	std::cout << "Jedi names from the given planets sort by name: ";
	for (size_t i = 0; i < length; i++)
	{
		std::cout << concatPlanet[i].getName() << "\n";
	}
}

void save(std::vector<Planet> cosmicPlanets)
{
	std::ofstream out;
	//ofs.open("test.txt", ios::out | ios::trunc);
	out.open("test.txt", std::ios::out | std::ios::trunc);
	//out.open("StarWarsUni.txt", std::ios::app);
	if (out)
	{
		size_t planetCount = cosmicPlanets.size();
		for (size_t i = 0; i < planetCount; i++)
		{
			out << cosmicPlanets[i];
		}
	}
	out << '~';
	out.close();
}

void read(std::vector<Planet> cosmicPlanets)
{
	std::ifstream in;
	in.open("StarWarsUni.txt");
	in.close();
}

void testProgram()
{	
	std::cout << "Commands:\n";
	std::cout << "create_jedi : Create jedi\n";
	std::cout << "remove_jedi : Remove jedi\n";
	std::cout << "promote_jedi : Promote jedi \n";
	std::cout << "demote_jedi : Demote jedi\n";
	std::cout << "get_strongest_jedi : Print information about the strongest jedi on a given planet \n";
	std::cout << "get_youngest_jedi : Print information about the youngest jedi on a given planet\n";
	std::cout << "get_most_used_saber_color : Returns the most common color of light sword in the given rank of the planet\n";
	std::cout << "get_most_used_saber_colorGM : Returns the most common color of light sword on a planet that enjoys at least one GRAND_MASTER\n";
	std::cout << "print_planet : Displays the name of the planet and the jedi inhabiting it,sort by rank\n";
	std::cout << "print_jedi : Print jedi information\n";
	std::cout << "cat_two_planets : Concatenate two planetsand  print jedi's information\n\n";
	std::cout << "Ranks:\n";
	std::cout << "YOUNGLING\n";
	std::cout << "INITIATE\n";
	std::cout << "PADAWAN\n";
	std::cout << "KNIGHT-ASPIRANT\n";
	std::cout << "KNIGHT\n";
	std::cout << "MASTER\n";
	std::cout << "BATTLE_MASTER\n";
	std::cout << "GRAND_MASTER\n";

	std::cout << "Enter command:\n";
	std::string command;
	std::cin >> command;

	std::vector<Planet> cosmicPlanets;

	while (command != "exit")
	{
		if (command == "create_jedi")
		{
			createJedi(cosmicPlanets);
		}
		else if (command == "remove_jedi")
		{
			removeJedi(cosmicPlanets);
		}
		else if (command == "promote_jedi")
		{
			promoteJedi(cosmicPlanets);
		}
		else if (command == "demote_jedi")
		{
			demoteJedi(cosmicPlanets);
		}
		else if (command == "get_strongest_jedi")
		{
			getStrongestJedi(cosmicPlanets);
		}
		else if (command == "get_youngest_jedi")
		{
			getYongestJedi(cosmicPlanets);
		}
		else if (command == "get_most_used_saber_color")
		{
			getMostUsedSaberColor(cosmicPlanets);
		}
		else if (command == "get_most_used_saber_colorGM")
		{
			getMostUsedSaberColorGM(cosmicPlanets);
		}
		else if (command == "print_planet")
		{
			print(cosmicPlanets);
		}
		else if (command == "print_jedi")
		{
			printJedi(cosmicPlanets);
		}
		else if (command == "print_planetsName")
		{
			concatPlanets(cosmicPlanets);
		}
		else
		{
			std::cout << "Invalid command ! Try again !\n";
		}
		std::cout << "Enter command:\n";
		std::cin >> command;
	}
}

//myString productName;
//
//std::cout << "Enter product name: ";
//std::cin >> productName;
//Product currentProduct;
//currentProduct.setNameProduct(productName);
