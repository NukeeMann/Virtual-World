#include <iostream>
#include "Organism.h"

Organism::Organism(World & world, const int &x, const int &y, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name)
	:world(world), point(*(new Position(world, y, x))), strength(strength), initiative(initiative), age(age), name(name), symbol(symbol)
{
	this->x = point.getX();
	this->y = point.getY();
	this->ID = reinterpret_cast<uint64_t>(this);
}

Organism::~Organism(){}

// Getery
const int Organism::getStrength() {
	return this->strength;
}

const int Organism::getInitiative() {
	return this->initiative;
}

const int Organism::getAge() {
	return this->age;
}

const char Organism::getSymbol() {
	return this->symbol;
}

const int Organism::getX() {
	return this->x;
}

const int Organism::getY() {
	return this->y;
}

const int Organism::getPointY() {
	return this->point.getY();
}

const int Organism::getPointX() {
	return this->point.getX();
}

const void Organism::setX(const int &newX) {
	this->x = newX;
}

const void Organism::setY(const int &newY) {
	this->y = newY;
}

const string Organism::getName() {
	return this->name;
}

const long long int Organism::getID() {
	return this->ID;
}

// Setery
const void Organism::addStrength(int strength) {
	this->strength += strength;
}

void Organism::setInitiative(int initiative) {
	this->initiative = initiative;
}

const void Organism::addAge() {
	this->age += 1;
}

// Inne
const bool Organism::die(Organism * attacker) {
	attacker->setInitiative(-1);
	attacker->world.killOrganism(attacker);
	return true;
}

const bool Organism::operator<(const Organism &s2) const{
	if (this->initiative == s2.initiative)
		return this->age < s2.age;
	else
		return this->initiative < s2.initiative;
}

const bool Organism::operator==(const Organism &s2) const {
	if (this->initiative == s2.initiative)
		return this->age == s2.age;
	else
		return this->initiative == s2.initiative;
}
