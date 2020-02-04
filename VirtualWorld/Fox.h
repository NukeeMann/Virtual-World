#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Fox : public Animal {

protected:
	void makeTheBaby(Position tmpPoint) override;
public:
	// Podstawowe funkcje
	Fox(World & world, const int &x, const int &y, const int &strength = 3, const int &initiative = 7, const int &age = 0, const char &symbol = 'F', const string &name = "Fox");
	
	~Fox();

	void action() override;
};