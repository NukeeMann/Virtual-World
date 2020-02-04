#include <iostream>
#include "Grass.h"


using namespace std;

Grass::Grass(World & world, const int &x, const int &y, const double &spreadChance, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:Plant(world, x, y, spreadChance, strength, initiative, age, symbol, name)
{
}

Grass::~Grass(){}

void Grass::giveBirth(Position tmpPoint) {
	this->world.addOrganism(new Grass(this->world, tmpPoint.getX(), tmpPoint.getY(), this->getSpreadChance(), this->getStrength(), this->getInitiative(), this->getSymbol()));
}