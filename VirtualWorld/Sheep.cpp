#include <iostream>
#include "Sheep.h"

using namespace std;

Sheep::Sheep(World & world, const int &x, const int &y, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:Animal(world, x, y, strength, initiative, age, symbol, name)
{
}

Sheep::~Sheep() {}

void Sheep::makeTheBaby(Position tmpPoint) {
	this->world.addOrganism(new Sheep(this->world, tmpPoint.getX(), tmpPoint.getY(), 4, 4, this->getSymbol()));
}