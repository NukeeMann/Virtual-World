#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Sheep : public Animal {

protected:
	void makeTheBaby(Position tmpPoint) override;
public:
	// Podstawowe funkcje
	Sheep(World & world, const int &x, const int &y, const int &strength = 4, const int &initiative = 4, const int &age = 0, const char &symbol = 'S', const string &name =  "Sheep");
	
	~Sheep();
};