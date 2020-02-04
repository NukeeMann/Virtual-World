#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Turtle : public Animal {

protected:
	void makeTheBaby(Position tmpPoint) override;
public:
	// Podstawowe funkcje
	Turtle(World & world, const int &x, const int &y, const int &strength = 2, const int &initiative = 1, const int &age = 0, const char &symbol = 'T', const string &name = "Turtle");
	~Turtle();

	void action() override;
	bool collision(Organism * attacker) override;
};