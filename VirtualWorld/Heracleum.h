#pragma once
#include <iostream>
#include "Plant.h"

using namespace std;

class Heracleum : public Plant {

protected:
	void giveBirth(Position tmpPoint) override;
	void killAround(Position tmpPoint);
public:
	Heracleum(World & world, const int &x, const int &y, const double &spreadChance = 0.03, const int &strength = 10, const int &initiative = 0, const int &age = 0, const char &symbol = 'h', const string &name = "Heracleum");

	~Heracleum();

	void action() override;
};