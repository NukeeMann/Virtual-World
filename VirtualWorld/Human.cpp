#include <iostream>
#include <conio.h>
#include "Human.h"

using namespace std;

Human::Human(World & world, const int &x, const int &y, const int &strength, const int &initiative, const int &age, const bool &specialSkillActivity,const int &specialSkillCooldown,  const char &symbol, const string &name)
	:Animal(world, x, y, strength, initiative, age, symbol, name), specialSkillActivity(specialSkillActivity), specialSkillCooldown(specialSkillCooldown)
{}

Human::~Human() {}

void Human::makeTheBaby(Position tmpPoint) {
	this->world.addOrganism(new Human(this->world, tmpPoint.getX(), tmpPoint.getY(), this->getStrength(), this->getInitiative(), this->getSymbol()));
}

bool Human::cooldownSpecialSkill() {
	if (this->specialSkillCooldown > 0) {
		this->specialSkillCooldown -= 1;
		return false;
	}
	if (this->specialSkillCooldown == 0) {
		this->specialSkillActivity = false;
		return true;
	}
	return true;
}

int Human::canUseSpecialSkill() {
	return this->specialSkillCooldown > 5;
}

bool Human::activateSpecialSkill() {
	if (this->specialSkillCooldown == 0)
	{
		// AKTYWACJA
		this->specialSkillActivity = true;
		this->specialSkillCooldown = 10;
		return true;
	}
	else {
		return false;
	}
}

void Human::holocaust(Position tmpPoint) {
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i != 0 || j != 0) {
				if (this->world.findOrganismToKill(tmpPoint.getY() + i, tmpPoint.getX() + j, this->getSymbol())) {
					this->world.KillOrganismAround(this, tmpPoint.getY() + i, tmpPoint.getX() + j, 'X');
				}
			}
		}
	}
}

void Human::action() {
	if (this->getInitiative() < 0)
		return;
	bool didMove = false;

	this->world.drawWorld();
	this->addAge();
	while (!didMove) {
		int direction = _getch();
		// Ruch strzalkami
		if (direction == 107 || direction == 75) {
			if (this->activateSpecialSkill())
				didMove = true;	
		}
		if (direction == 83 || direction == 115) {
			this->world.saveGame(specialSkillActivity, specialSkillCooldown);
			this->world.drawWorld();
			system("cls");
			this->world.drawWorldFirstTime();
		}
		if (direction == 27) {
			exit(0);
		}
		if (direction == 224) {
			direction = 0;
			direction = _getch();
			switch (direction)
			{
			case 72:
				if (this->getY() - 1 < 0)
					break;
				this->setY(this->getY() - 1);
				didMove = true;
				break;
			case 80:
				if (this->getY() + 1 >= this->world.getSizeH())
					break;
				this->setY(this->getY() + 1);
				didMove = true;
				break;
			case 77:
				if (this->getX() + 1 >= this->world.getSizeV())
					break;
				this->setX(this->getX() + 1);
				didMove = true;
				break;
			case 75:
			default:
				if (this->getX() - 1 < 0)
					break;
				this->setX(this->getX() - 1);
				didMove = true;
				break;
			}

			direction = 0;
		}
	}

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

	if (this->canUseSpecialSkill()) {
		this->holocaust(this->point);
	}
	this->cooldownSpecialSkill();

}
