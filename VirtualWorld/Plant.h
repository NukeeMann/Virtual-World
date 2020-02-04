#pragma once
#include <iostream>
#include "Organism.h"

using namespace std;

class Plant : public Organism {
	double spreadChance;
protected:
	double getSpreadChance();
	virtual bool tryToSpread();
	virtual void giveBirth(Position tmpPoint);
	void eatenComment(Organism * attacker);
public:
	// Podstawowe funkcje
	Plant(World & world, const int &x, const int &y, const double &spreadChance = 0.10, const int &strength = 0, const int &initiative = 0, const int &age = 0, const char &symbol = 'V', const string &name = "Plant");
	virtual ~Plant();

	virtual void action() override;
	virtual bool collision(Organism * attacker) override;

};