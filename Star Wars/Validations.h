#pragma once
#include <iostream>
#include "Planet.h"
#include "Jedi.h"

//проверява дали съществува джедай с такова име
bool jediExists(std::vector<Planet>& planets, std::string passedJediName);
//проверява дали съществува планета с такова име
bool planetExists(std::vector<Planet>& planets, std::string passedPlanetName);
//проверява дали подадения ранк е валиден
bool isRankValid(std::string passedRank);
//проверява дали годините са > от 0
bool ageValid(unsigned passedAge);