#pragma once
#include <iostream>
#include "Plant.h"

using namespace std;

class Wolfberry: public Plant {

protected:
	void giveBirth(Position tmpPoint) override;
public:
	Wolfberry(World & world, const int &x, const int &y, const double &spreadChance = 0.03, const int &strength = 99, const int &initiative = 0, const int &age = 0, const char &symbol = 'b', const string &name = "Wolfberry");

	~Wolfberry();
};