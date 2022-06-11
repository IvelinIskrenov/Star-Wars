#include "GeneralFunctions.h"
#include <iostream>
#include "Validations.h"

void testProgram()
{
	std::string command;
	std::cin >> command;
	
	std::cout << "Commands:\n";
	std::cout << "create_jedi : Create jedi\n";
	std::cout << "removeJedi : Remove jedi\n";
	std::cout << "promote_jedi : Promote jedi \n";
	std::cout << "demote_jedi : Demote jedi\n";
	std::cout << "get_strongest_jedi : Print information about the strongest jedi on a given planet \n";
	std::cout << "get_youngest_jedi : Print information about the youngest jedi on a given planet\n";
	std::cout << "demote_jedi : Demote jedi\n";
	std::cout << "demote_jedi : Demote jedi\n";
	std::cout << "demote_jedi : Demote jedi\n";
	std::cout << "demote_jedi : Demote jedi\n";

	while (command != "exit")
	{
		if (command == "create_jedi")
		{

		}
		else if (command == "removeJedi")
		{

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
		else if (command == "get_most_used_saber_colorG")
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

void createJedi()
{
	std::string jediName;
	std::cin >> jediName;
	std::string jediRank;
	std::cin >> jediRank;
	unsigned age;
	std::cin >> age;
	std::string lightsaberColor;
	std::cin >> lightsaberColor;
	double power;
	std::cin >> power;

}