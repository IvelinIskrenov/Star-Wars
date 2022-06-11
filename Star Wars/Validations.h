#pragma once
#include <iostream>
#include "Planet.h"
#include "Jedi.h"

bool jediExists(std::vector<Planet>& planets, std::string passedJediName);
bool planetExists(std::vector<Planet>& planets, std::string passedPlanetName);
bool isRankValid(std::string passedRank);
bool ageValid(unsigned passedAge);