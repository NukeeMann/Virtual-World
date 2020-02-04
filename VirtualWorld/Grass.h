#pragma once
#include <iostream>
#include "Plant.h"

using namespace std;

class Grass : public Plant {

protected:
	void giveBirth(Position tmpPoint) override;
public:
	Grass(World & world, const int &x, const int &y, const double &spreadChance = 0.03, const int &strength = 0, const int &initiative = 0, const int &age = 0, const char &symbol = 't', const string &name = "Grass");

	~Grass();
};