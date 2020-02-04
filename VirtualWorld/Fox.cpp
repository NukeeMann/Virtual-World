#include <iostream>
#include "Fox.h"

using namespace std;

Fox::Fox(World & world, const int &x, const int &y, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:Animal(world, x, y, strength, initiative, age, symbol, name)
{
}

Fox::~Fox() {}

void Fox::makeTheBaby(Position tmpPoint) {
	this->world.addOrganism(new Fox(this->world, tmpPoint.getX(), tmpPoint.getY(), 3, 7, this->getSymbol()));
}

void Fox::action() {
	if (this->getInitiative() < 0)
		return;
	else
	{
		this->addAge();

		Position tmp(this->world, this->getY(), this->getX()); 
		if (!tmp.safeMove(this, this->world.getSizeH(), this->world.getSizeV()))
			return; //Jezeli sie nie udalo

		tmp.findFreeSpot(this->world.getSizeH(), this->world.getSizeV());
		int x = tmp.getX();
		int y = tmp.getY();
		tmp.setX(this->getX());
		tmp.setY(this->getY());

		while (!world.compareStrength(this, y, x)) {
			tmp.setX(this->getX());		// TUTAJ EDYTOWALEM O 1 W NOCY
			tmp.setY(this->getY());
			tmp.findFreeSpot(this->world.getSizeH(), this->world.getSizeV());
			x = tmp.getX();
			y = tmp.getY();
			tmp.setX(this->getX());
			tmp.setY(this->getY());
		}

		this->setX(x);
		this->setY(y);
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