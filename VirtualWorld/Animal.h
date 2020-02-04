#pragma once
#include <iostream>
#include "Organism.h"

using namespace std;

class Animal : public Organism {
protected:
	bool newBabyBorn(Organism * mother);
	virtual void makeTheBaby(Position tmpPoint);
	void killedComment(Organism * attacker, Organism * dying);
public:
	// Podstawowe funkcje
	Animal(World & world, const int &x, const int &y, const int &strength = 2, const int &initiative = 1, const int &age = 0, const char &symbol = 'V', const string &name = "Animal");
	virtual ~Animal();

	virtual void action() override;
	virtual bool collision(Organism * attacker) override;

};