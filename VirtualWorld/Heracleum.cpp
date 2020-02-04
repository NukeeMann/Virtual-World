#include <iostream>
#include "Heracleum.h"


using namespace std;

Heracleum::Heracleum(World & world, const int &x, const int &y, const double &spreadChance, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:Plant(world, x, y, spreadChance, strength, initiative, age, symbol, name)
{
}

Heracleum::~Heracleum() {}

void Heracleum::giveBirth(Position tmpPoint) {
	this->world.addOrganism(new Heracleum(this->world, tmpPoint.getX(), tmpPoint.getY(), this->getSpreadChance(), this->getStrength(), this->getInitiative(), this->getSymbol()));
}

void Heracleum::killAround(Position tmpPoint) {

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i != 0 || j != 0) {
				if (this->world.findOrganismToKill(tmpPoint.getY() + i, tmpPoint.getX() + j, this->getSymbol())) {
					this->world.KillOrganismAround(this, tmpPoint.getY() + i, tmpPoint.getX() + j, 'A');
				}
			}
		}
	}
	
}

void Heracleum::action()	// 3 proby rozmnazania dla Mlecza
{
	if (this->getInitiative() >= 0) {
		this->tryToSpread();
		this->killAround(this->point);
		this->addAge();
	}
}