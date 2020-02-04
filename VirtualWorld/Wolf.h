#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Wolf : public Animal {

protected:
	void makeTheBaby(Position tmpPoint);
public:
	// Podstawowe funkcje
	Wolf(World & world, const int &x, const int &y, const int &strength = 9, const int &initiative = 5, const int &age = 0, const char &symbol = 'W', const string &name = "Wolf");
	
	~Wolf();
};