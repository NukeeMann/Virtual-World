#include <iostream>
#include "Animal.h"

using namespace std;

Animal::Animal(World & world, const int &x, const int &y, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:Organism(world, x, y, strength, initiative, age, symbol, name)
{
}

Animal::~Animal(){}

void Animal::makeTheBaby(Position tmpPoint) {
	this->world.addOrganism(new Animal(this->world, tmpPoint.getX(), tmpPoint.getY(), this->getStrength(), this->getInitiative(), this->getSymbol()));
}

bool Animal::newBabyBorn(Organism * mother) {
	bool CimCiRimCim = false;
	Position tmpPoint(this->world, this->getY(), this->getX());
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (!world.findOrganism(tmpPoint.getY() + i, tmpPoint.getX() + j))
				CimCiRimCim = true;
		}
	}
	if (!CimCiRimCim)
		return false;

	while (world.findOrganism(tmpPoint.getY(), tmpPoint.getX())) {
		tmpPoint.setX(this->getX());
		tmpPoint.setY(this->getY());
		tmpPoint.findFreeSpot(this->world.getSizeH(), this->world.getSizeV());
	}

	makeTheBaby(tmpPoint);

	return true;
}

void Animal::action() {
	if (this->getInitiative() < 0)
		return;
	else
	{
		this->addAge();
		Position tmp(this->world, this->getY(), this->getX());
		tmp.findFreeSpot(this->world.getSizeH(), this->world.getSizeV());
		this->setX(tmp.getX());
		this->setY(tmp.getY());		
		if (this->world.moveAnimal(this))
		{
			this->point.setX(this->getX());
			this->point.setY(this->getY());
		}
		else
		{
			this->setX(this->point.getX());
			this->setY(this->point.getY());
		}

	}
}

bool Animal::collision(Organism *attacker) {
	char znak1 = attacker->getSymbol();
	char znak2 = this->getSymbol();
	if (znak1 == znak2) 
	{
		if (newBabyBorn(attacker))
			return false;
		else
			return false;
	}
	else 
	{
		if (this->getStrength() < attacker->getStrength())
		{
			this->die(this);						// ATTACKER zabija this
			this->killedComment(attacker, this);
			return true;
		}
		else
		{
			this->die(attacker);					// ATTACKER atakuje this i przegrywa ginac
			this->killedComment(this, attacker);
			return false;
		}
	}

}

void Animal::killedComment(Organism * attacker, Organism * dying) {
	string newComment = dying->getName() + " was killed by " + attacker->getName();
	this->world.addComment(newComment);
}
