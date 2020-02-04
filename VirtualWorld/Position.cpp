#include <iostream>
#include "Position.h"


enum DIRECTION {
	NORTH,
	NORTH_EAST,
	EAST,
	EAST_SOUTH,
	SOUTH,
	SOUTH_WEST,
	WEST,
	WEST_NORTH,
	NORTH_NORTH_WEST,
	NORTH_NORTH_EAST,
	NORTH_EAST_EAST,
	SOUTH_EAST_EAST,
	SOUTH_SOUTH_EAST,
	SOUTH_SOUTH_WEST,
	SOUTH_WEST_WEST,
	NORTH_WEST_WEST,
};

Position::Position(World & world, const int &Y, const int &X) 
	: world(world), x(X), y(Y) 
{}

const bool Position::safeMove(Organism * org, const int &MAX_SIZEH, const int &MAX_SIZEV) {
	bool canMove = false;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if(i != 0 || j!= 0)
				if (this->world.compareStrength(org, this->getY() + i, this->getX() + j))
				return true;	// Jezeli jest takie miejsce gdzie nie ma silniejszego zwierzecia to zwraca true
		}
	}

	if (canMove == false)
		return false;	// Jezeli nie ma gdzie sie ruszyc by nie zginac to zwraca false
	else
		return true;
}

const void Position::findFreeSpot(const int &MAX_SIZEH, const int &MAX_SIZEV) {
	while (true) {
		int direction = rand() % 8;
		switch (direction) {
		case NORTH:
			if (this->getY() + 1 < MAX_SIZEH)	//^
			{
				this->setX(this->getX());
				this->setY(this->getY() + 1);
				return;
			}
			else
				break;
		case NORTH_EAST:
			if (this->getY() + 1 < MAX_SIZEH && this->getX() + 1 < MAX_SIZEV)	//^>
			{
				this->setX(this->getX() + 1);
				this->setY(this->getY() + 1);
				return;
			}
			else
				break;
		case EAST:
			if (this->getX() + 1 < MAX_SIZEV)	// >
			{
				this->setX(this->getX() + 1);
				this->setY(this->getY());
				return;
			}
			else
				break;
		case EAST_SOUTH:
			if (this->getY() - 1 >= 0 && this->getX() + 1 < MAX_SIZEV)	//>v
			{
				this->setX(this->getX() + 1);
				this->setY(this->getY() - 1);
				return;
			}
			else
				break;
		case SOUTH:
			if (this->getY() - 1 >= 0)	//v
			{
				this->setX(this->getX());
				this->setY(this->getY() - 1);
				return;
			}
			else
				break;
		case SOUTH_WEST:
			if (this->getY() - 1 >= 0 && this->getX() - 1 >= 0)	//v<
			{
				this->setX(this->getX() - 1);
				this->setY(this->getY() - 1);
				return;
			}
			else
				break;
		case WEST:
			if (this->getX() - 1 >= 0)	//<
			{
				this->setX(this->getX() - 1);
				this->setY(this->getY());
				return;
			}
			break;
		case WEST_NORTH:
			if (this->getX() - 1 >= 0 && this->getY() + 1 < MAX_SIZEH)	//<^
			{
				this->setX(this->getX() - 1);
				this->setY(this->getY() + 1);
				return;
			}
			else
				break;
		}
	}
}

const void Position::findFreeSpot2(const int &MAX_SIZEH, const int &MAX_SIZEV) {
	while (true) {
		int direction = rand() % 16;
		switch (direction) {
		case NORTH:
			if (this->getY() + 2 < MAX_SIZEH)	//^
			{
				this->setX(this->getX());
				this->setY(this->getY() + 2);
				return;
			}
			else
				break;
		case NORTH_EAST:
			if (this->getY() + 2 < MAX_SIZEH && this->getX() + 2 < MAX_SIZEV)	//^>
			{
				this->setX(this->getX() + 2);
				this->setY(this->getY() + 2);
				return;
			}
			else
				break;
		case EAST:
			if (this->getX() + 2 < MAX_SIZEV)	// >
			{
				this->setX(this->getX() + 2);
				this->setY(this->getY());
				return;
			}
			else
				break;
		case EAST_SOUTH:
			if (this->getY() - 2 >= 0 && this->getX() + 2 < MAX_SIZEV)	//>v
			{
				this->setX(this->getX() + 2);
				this->setY(this->getY() - 2);
				return;
			}
			else
				break;
		case SOUTH:
			if (this->getY() - 2 >= 0)	//v
			{
				this->setX(this->getX());
				this->setY(this->getY() - 2);
				return;
			}
			else
				break;
		case SOUTH_WEST:
			if (this->getY() - 2 >= 0 && this->getX() - 2 >= 0)	//v<
			{
				this->setX(this->getX() - 2);
				this->setY(this->getY() - 2);
				return;
			}
			else
				break;
		case WEST:
			if (this->getX() - 2 >= 0)	//<
			{
				this->setX(this->getX() - 2);
				this->setY(this->getY());
				return;
			}
			break;
		case WEST_NORTH:
			if (this->getX() - 2 >= 0 && this->getY() + 2 < MAX_SIZEH)	//<^
			{
				this->setX(this->getX() - 2);
				this->setY(this->getY() + 2);
				return;
			}
			else
				break;
		case NORTH_NORTH_WEST:
			if (this->getX() - 1 >= 0 && this->getY() - 2 >= 0)	//<^
			{
				this->setX(this->getX() - 1);
				this->setY(this->getY() - 2);
				return;
			}
			else
				break;
		case NORTH_NORTH_EAST:
			if (this->getX() + 1 < MAX_SIZEV && this->getY() - 2 >= 0)	//<^
			{
				this->setX(this->getX() + 1);
				this->setY(this->getY() - 2);
				return;
			}
			else
				break;
		case NORTH_EAST_EAST:
			if (this->getX() + 2 < MAX_SIZEV && this->getY() - 1 >= 0)	//<^
			{
				this->setX(this->getX() + 2);
				this->setY(this->getY() - 1);
				return;
			}
			else
				break;
		case SOUTH_EAST_EAST:
			if (this->getX() + 2 < MAX_SIZEV && this->getY() + 1 < MAX_SIZEH)	//<^
			{
				this->setX(this->getX() + 2);
				this->setY(this->getY() + 1);
				return;
			}
			else
				break;
		case SOUTH_SOUTH_EAST:
			if (this->getX() + 1 >= 0 && this->getY() + 2 < MAX_SIZEH)	//<^
			{
				this->setX(this->getX() + 1);
				this->setY(this->getY() + 2);
				return;
			}
			else
				break;
		case SOUTH_SOUTH_WEST:
			if (this->getX() - 1 >= 0 && this->getY() + 2 < MAX_SIZEH)	//<^
			{
				this->setX(this->getX() - 1);
				this->setY(this->getY() + 2);
				return;
			}
			else
				break;
		case SOUTH_WEST_WEST:
			if (this->getX() - 2 >= 0 && this->getY() + 1 < MAX_SIZEH)	//<^
			{
				this->setX(this->getX() - 2);
				this->setY(this->getY() + 1);
				return;
			}
			else
				break;
		case NORTH_WEST_WEST:
		default:
			if (this->getX() - 2 >= 0 && this->getY() - 1 >= 0)	//<^
			{
				this->setX(this->getX() - 2);
				this->setY(this->getY() - 1);
				return;
			}
			else
				break;
		}
	}
}

const void Position::setX(const int &X) {
	this->x = X;
}

const void Position::setY(const int &Y) {
	this->y = Y;
}

const int Position::getX() {
	return this->x;
}

const int Position::getY() {
	return this->y;
}