#include <iostream>
#include "CyberSheep.h"

using namespace std;

CyberSheep::CyberSheep(World & world, const int &x, const int &y, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:Animal(world, x, y, strength, initiative, age, symbol, name)
{
}

CyberSheep::~CyberSheep() {}

void CyberSheep::makeTheBaby(Position tmpPoint) {
	this->world.addOrganism(new CyberSheep(this->world, tmpPoint.getX(), tmpPoint.getY(), this->getStrength(), this->getInitiative(), this->getSymbol()));
}

void CyberSheep::action() {

}