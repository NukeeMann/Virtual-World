#include <iostream>
#include "Wolf.h"

using namespace std;

Wolf::Wolf(World & world, const int &x, const int &y, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:Animal(world, x, y, strength, initiative, age, symbol, name)
{
}

Wolf::~Wolf() {}

void Wolf::makeTheBaby(Position tmpPoint) {
	this->world.addOrganism(new Wolf(this->world, tmpPoint.getX(), tmpPoint.getY(), 9, 5, this->getSymbol()));
}