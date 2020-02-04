#pragma once
#include <iostream>
#include "World.h"
#include "Position.h"
#include <time.h>

using namespace std;

class Position;

class World;

class Organism {
	int strength;
	int initiative;
	int x, y;
	int age;
	char symbol;
	unsigned long long int ID;
	string name;
protected:
	Position & point;
	World & world;
	void setInitiative(int newInitiative);
	const void addAge();
public:
	Organism(World & world, const int &x, const int &y, const int &strength, const int &initiative, const int &age, const char &symbol, const string &name);
	~Organism();

	virtual void action() = 0;
	virtual bool collision(Organism * attacker) = 0;

	// Getery zmiennych
	const int getStrength();
	const int getInitiative();
	const int getAge();
	const char getSymbol();
	const int getX();
	const int getY();
	const int getPointX();
	const int getPointY();
	const long long int getID();
	const string getName();

	// Setery zmiennych
	const void addStrength(int addStrength);
	const void setX(const int &newX);
	const void setY(const int &newY);

	// Inne
	const bool die(Organism * attacker);
	const bool operator <(const Organism& s2) const;
	const bool operator ==(const Organism& s2) const;
};