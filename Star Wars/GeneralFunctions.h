#pragma once
#include "Planet.h"
#include "Jedi.h"
#include "Validations.h"

size_t findPlanet(std::vector<Planet> cosmicPlanets,std::string planetName);
void createJedi(std::vector<Planet> cosmicPlanets);
void removeJedi(std::vector<Planet> cosmicPlanets);
void promoteJedi(std::vector<Planet> cosmicPlanets);
void demoteJedi(std::vector<Planet> cosmicPlanets);
void getStrongestJedi(std::vector<Planet> cosmicPlanets);
void getYongestJedi(std::vector<Planet> cosmicPlanets);
void getMostUsedSaberColor(std::vector<Planet> cosmicPlanets);
void getMostUsedSaberColorGM(std::vector<Planet> cosmicPlanets);
int getJediRankNumber(std::string jediRank);
void print(std::vector<Planet> cosmicPlanets);
void printJedi(std::vector<Planet> cosmicPlanets);
void concatPlanets(std::vector<Planet> cosmicPlanets);
void save(std::vector<Planet> cosmicPlanets);
void read(std::vector<Planet> cosmicPlanets);
void testProgram();