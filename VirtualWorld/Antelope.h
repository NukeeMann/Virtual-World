#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Antelope : public Animal {

protected:
	void makeTheBaby(Position tmpPoint) override;
public:
	// Podstawowe funkcje
	Antelope(World & world, const int &x, const int &y, const int &strength = 4, const int &initiative = 4, const int &age = 0, const char &symbol = 'A', const string &name = "Antelope");
	
	~Antelope();

	void action() override;
	bool collision(Organism * attacker) override;
};