#pragma once
#include <iostream>
#include "World.h"
#include "Organism.h"

class Organism;

class World;

class Position {
	int x, y;
protected:
	World & world;
public:
	Position(World & world, const int &Y, const int &X);	// Tworzy punkt
	
	const bool safeMove(Organism * org, const int &MAX_SIZEH, const int &MAX_SIZEV);	// Bezpieczny ruch bez mozliwosci zginiecia
	const void findFreeSpot(const int &MAX_SIZEH, const int &MAX_SIZEV); // Szuka wolnego spota w sasiedztwie
	const void findFreeSpot2(const int &MAX_SIZEH, const int &MAX_SIZEV); // Szuka wolnego spota w sasiedztwie o 2

	const void setX(const int &X);
	const void setY(const int &Y);
	const int getX();
	const int getY();
};
