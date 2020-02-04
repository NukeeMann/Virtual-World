#include <iostream>
#include "Plant.h"

using namespace std;

Plant::Plant(World & world, const int &x, const int &y, const double &spreadChance, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:Organism(world, x, y, strength, initiative, age, symbol, name), spreadChance(spreadChance)
{

}

Plant::~Plant(){}

// Podstawowe funkcje
void Plant::action()	// Rosliny domyslnie probuja sie rozmnozyc
{
	if (this->getInitiative() >= 0) {
		this->tryToSpread();
		this->addAge();
	}
}

bool Plant::collision(Organism * attacker)		// Rosliny domyslnie gina
{
	// Jak zwierze atakuje to zwraca true
	if (this->getStrength() > attacker->getStrength()) {
		this->die(attacker);
		this->die(this);
		this->eatenComment(attacker);
		return false;
	}
	this->eatenComment(attacker);
	this->die(this);
	return true;
}

// Prywatne funkcje
void Plant::giveBirth(Position tmpPoint) {
	this->world.addOrganism(new Plant(this->world, tmpPoint.getX(), tmpPoint.getY(), this->getSpreadChance(), this->getStrength(), this->getInitiative(), this->getSymbol()));
}

bool Plant::tryToSpread() {		// Proba rozmnozenia
	double chance = ((double)rand()) / (double)RAND_MAX;
	if ((double)chance > (double)this->getSpreadChance())
		return false;
	else {
		bool canSpread = false;
		Position tmpPoint(this->world, this->getY(), this->getX());
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
					if (!world.findOrganism(tmpPoint.getY() + i, tmpPoint.getX() + j)) {
						canSpread = true;
					}
			}
		}
		if (!canSpread)
			return false;



		while (world.findOrganism(tmpPoint.getY(), tmpPoint.getX())){
			tmpPoint.setX(this->getX());
			tmpPoint.setY(this->getY());
			tmpPoint.findFreeSpot(this->world.getSizeH(), this->world.getSizeV());
		}
		giveBirth(tmpPoint);														// ROSLINA SIE ROZRASTA
		return true;
	}
}

void Plant::eatenComment(Organism * attacker) {
	string newComment = attacker->getName() + " ate " + this->getName();
	this->world.addComment(newComment);
}

//Getery
double Plant::getSpreadChance() {
	return this->spreadChance;
}