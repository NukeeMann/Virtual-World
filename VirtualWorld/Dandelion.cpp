#include <iostream>
#include "Dandelion.h"


using namespace std;

Dandelion::Dandelion(World & world, const int &x, const int &y, const double &spreadChance, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:Plant(world, x, y, spreadChance, strength, initiative, age, symbol, name)
{
}

Dandelion::~Dandelion() {}

void Dandelion::giveBirth(Position tmpPoint) {
	this->world.addOrganism(new Dandelion(this->world, tmpPoint.getX(), tmpPoint.getY(), this->getSpreadChance(), this->getStrength(), this->getInitiative(), this->getSymbol()));
}

void Dandelion::action()	// 3 proby rozmnazania dla Mlecza
{
	for (int i = 0; i < 3; i++) {
		if (this->getInitiative() >= 0) {
			if (this->tryToSpread()) {
				this->addAge();
				break;
			}
		}
	}

	this->addAge();
}