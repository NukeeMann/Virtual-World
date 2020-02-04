#include <iostream>
#include "Turtle.h"

using namespace std;

Turtle::Turtle(World & world, const int &x, const int &y, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:Animal(world, x, y, strength, initiative, age, symbol, name)
{
}

Turtle::~Turtle() {}

void Turtle::makeTheBaby(Position tmpPoint) {
	this->world.addOrganism(new Turtle(this->world, tmpPoint.getX(), tmpPoint.getY(), 2, 1, this->getSymbol()));
}

void Turtle::action() {
	if (this->getInitiative() < 0)
		return;
	else
	{
		this->addAge();
		int shouldMove = rand() % 4;
		if (shouldMove == 3) {
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
		else {
			return;
		}

	}
}

bool Turtle::collision(Organism *attacker) {
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
		if (attacker->getStrength() < 5)
			return false;
		if (this->getStrength() < attacker->getStrength())
		{
			this->die(this);
			// THIS organizm ginie
			this->killedComment(attacker, this);
			return true;
		}
		else
		{
			this->die(attacker);
			// organizm atakujacy ginie
			this->killedComment(this, attacker);
			return false;
		}
	}

}