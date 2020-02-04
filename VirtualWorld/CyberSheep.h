#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class CyberSheep : public Animal {

protected:
	void makeTheBaby(Position tmpPoint);
public:
	// Podstawowe funkcje
	CyberSheep(World & world, const int &x, const int &y, const int &strength = 11, const int &initiative = 4, const int &age = 0, const char &symbol = 'C', const string &name = "Cyber Sheep");

	~CyberSheep();

	void action() override;
};