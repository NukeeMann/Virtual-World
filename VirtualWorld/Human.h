#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Human : public Animal {
	bool specialSkillActivity;
	int specialSkillCooldown;
protected:
	void makeTheBaby(Position tmpPoint);
	bool activateSpecialSkill();
	bool cooldownSpecialSkill();
	int canUseSpecialSkill();
	void holocaust(Position tmpPoint);
public:
	// Podstawowe funkcje
	Human(World & world, const int &x, const int &y, const int &strength = 4, const int &initiative = 4, const int &age = 0, const bool &specialSkillActivity = false, const int &specialSkillCooldown = 0, const char &symbol = 'H', const string &name = "Human");
	~Human();

	void action() override;
};