#include <iostream>
#include "Guarana.h"


using namespace std;

Guarana::Guarana(World & world, const int &x, const int &y, const double &spreadChance, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:Plant(world, x, y, spreadChance, strength, initiative, age, symbol, name)
{

}

Guarana::~Guarana()
{
}

void Guarana::giveBirth(Position tmpPoint) {
	this->world.addOrganism(new Guarana(this->world, tmpPoint.getX(), tmpPoint.getY(), this->getSpreadChance(), this->getStrength(), this->getInitiative(), this->getSymbol()));
}

bool Guarana::collision(Organism * attacker)		// Rosliny domyslnie gina
{
	attacker->addStrength(3);
	this->die(this);
	this->eatenComment(attacker);
	return true;
}