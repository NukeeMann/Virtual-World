#include <iostream>
#include "Wolfberry.h"


using namespace std;

Wolfberry::Wolfberry(World & world, const int &x, const int &y, const double &spreadChance, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:Plant(world, x, y, spreadChance, strength, initiative, age, symbol, name)
{
}

Wolfberry::~Wolfberry() {}

void Wolfberry::giveBirth(Position tmpPoint) {
	this->world.addOrganism(new Wolfberry(this->world, tmpPoint.getX(), tmpPoint.getY(), this->getSpreadChance(), this->getStrength(), this->getInitiative(), this->getSymbol()));
}