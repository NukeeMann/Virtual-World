#pragma once
#include <iostream>
#include "Plant.h"

using namespace std;

class Guarana : public Plant {

protected:
	void giveBirth(Position tmpPoint) override;
public:
	Guarana(World & world, const int &x, const int &y, const double &spreadChance = 0.03, const int &strength = 0, const int &initiative = 0, const int &age = 0, const char &symbol = 'g', const string &name = "Guarana");

	~Guarana();

	bool collision(Organism * attacker) override;
};