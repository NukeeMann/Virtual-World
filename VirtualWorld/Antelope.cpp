#include <iostream>
#include "Antelope.h"

using namespace std;

Antelope::Antelope(World & world, const int &x, const int &y, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:Animal(world, x, y, strength, initiative, age, symbol, name)
{
}

Antelope::~Antelope() {}

void Antelope::makeTheBaby(Position tmpPoint) {
	this->world.addOrganism(new Antelope(this->world, tmpPoint.getX(), tmpPoint.getY(), 4, 4, this->getSymbol()));
}

void Antelope::action() {
	if (this->getInitiative() < 0)
		return;
	else
	{
		this->addAge();
		/*Position ruch1(this->world, this->getY(), this->getX());
		ruch1.findFreeSpot(this->world.getSizeH(), this->world.getSizeV());
		this->setX(ruch1.getX());
		this->setY(ruch1.getY());*/

		Position ruch2(this->world, this->getY(), this->getX());
		ruch2.findFreeSpot2(this->world.getSizeH(), this->world.getSizeV());
		this->setX(ruch2.getX());
		this->setY(ruch2.getY());

		// Poczatkowe pole
		int tmpX = this->point.getX();
		int tmpY = this->point.getY();


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

bool Antelope::collision(Organism *attacker) {
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
		int tryToEscape = rand() % 2;
		if (tryToEscape == 0) {

			// Poczatkowe pole
			int tmpX = this->point.getX();
			int tmpY = this->point.getY();
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					if(i != 0 || j != 0)
						if (!world.findOrganism(tmpY + i, tmpX + j)) {
							this->world.moveAnimal(this);
							this->point.setX(this->getX() + j);
							this->point.setY(this->getY() + i);
							this->setX(this->getX() + j);
							this->setY(this->getY() + i);
							return false;
						}
				}
			}
		}


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