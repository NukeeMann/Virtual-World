#include <iostream>
#include <Windows.h>
#include <unordered_map>
#include <fstream>
#include "World.h"
#include "Plant.h"
#include "Animal.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Wolfberry.h"
#include "Heracleum.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "CyberSheep.h"
#include "Human.h"
#include <algorithm>

#define N_OF_ANIMAL 5
#define N_OF_PLANTS 5

using namespace std;

static void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x + 1;
	pos.Y = y + 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
};

World::World(int map_sizeH, int map_sizeV)						// Konstrukotr swiata
: SIZE_V(map_sizeV), SIZE_H(map_sizeH), box( new char * [map_sizeH] ), OLDbox( new char *[map_sizeH]), round(0)
{
	for (size_t i = 0; i < SIZE_H; i++) {
		box[i] = new char [SIZE_V];
		OLDbox[i] = new char[SIZE_V];
	}

	for (size_t yR = 0; yR < SIZE_H; yR++) {
		for (size_t xR = 0; xR < SIZE_V; xR++) {
			box[yR][xR] = ' ';
			OLDbox[yR][xR] = ' ';
		}
	}
}

const void World::addOrganism(Organism *org) {
	organismMap.push_back(org);
	box[org->getY()][org->getX()] = org->getSymbol();
}

const void World::KillOrganismAround(Organism *org, const int &yf, const int &xf, const char &whatToKill) {
	if (whatToKill == 'A') {
		for (auto n : organismMap) {
			if (n->getX() == xf && n->getY() == yf && n->getInitiative() > 0 && org->getStrength() >= n->getStrength()) {
				n->die(n);
			}
		}
	}
	else {
		for (auto n : organismMap) {
			if (n->getX() == xf && n->getY() == yf && n->getInitiative() >= 0) {
				n->die(n);
			}
		}
	}

	return;
}

const bool World::findOrganismToKill(const int &yf, const int &xf, const char &znak) {
	if (yf < 0 || yf >= SIZE_H || xf < 0 || xf >= SIZE_V)
		return false;
	if (box[yf][xf] == ' ' || box[yf][xf] == znak)
		return false;
	else
		return true;
}

const bool World::compareStrength(Organism *org, const int &yf, const int &xf) {
	if (yf < 0 || yf >= SIZE_H || xf < 0 || xf >= SIZE_V)
		return false;
	if (!this->findOrganism(yf, xf))
		return true;
	for (auto n : organismMap) {
		if (n->getPointX() == xf && n->getPointY() == yf && n->getInitiative() >= 0 && org->getID() != n->getID() &&
			(org->getStrength() >= n->getStrength() || org->getSymbol() == n->getSymbol())) {
			return true;
		}
	}
	return false;
}

const bool World::findOrganism(const int &yf, const int &xf) {
	if (yf < 0 || yf >= SIZE_H || xf < 0 || xf >= SIZE_V)
		return true;
	if (box[yf][xf] == ' ')
		return false;
	else
		return true;
}

const bool World::moveAnimal(Organism *org) {
	if (box[org->getY()][org->getX()] != ' ')
	{
		for (auto n : organismMap) {
			if (n->getX() == org->getX() && n->getY() == org->getY()) {
				if (n->getSymbol() != org->getSymbol()) {
					if (!n->collision(org)) {	// Walka
						return false;
																						// n Odnilo atak organizmu ORG
					}
					int k = org->getY();
					int b = org->getX();
																						// n zostalo zabite/zjedzone przez ORG
					this->box[org->getPointY()][org->getPointX()] = ' ';
					box[org->getY()][org->getX()] = org->getSymbol();
					return true;
				}
				else if (n->getID() != org->getID())    // Rozmnazanie
				{
					if (n->collision(org)) {
						int tmp = 1;
																						// Komentator DZIECKO SIE URODZILO
					}
					
					return false;
				}
			}
		}
		return true;
	}
	else
	{
		int k = org->getY();
		int b = org->getX();
		box[org->getY()][org->getX()] = org->getSymbol();
		this->box[org->getPointY()][org->getPointX()] = ' ';
		return true;
	}
}

static void color(char znak) {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (znak) {
	case 't':	// Trawa
		SetConsoleTextAttribute(hOut, 138);
		break;
	case 'g':	// Guarana
		SetConsoleTextAttribute(hOut, 140);
		break;
	case 'm':	// Mlecz
		SetConsoleTextAttribute(hOut, 142);
		break;
	case 'b':	// Wilcze jagody
		SetConsoleTextAttribute(hOut, 133);
		break;
	case 'h':	// Barszcz sosnowskiego
		SetConsoleTextAttribute(hOut, 135);
		break;
	case 'F':	// Lis
		SetConsoleTextAttribute(hOut, 132);
		break;
	case 'S':	// Owca
		SetConsoleTextAttribute(hOut, 143);
		break;
	case 'W':	// Wilk
		SetConsoleTextAttribute(hOut, 129);
		break;
	case 'A':	// Antylopa
		SetConsoleTextAttribute(hOut, 134);
		break;
	case 'T':	// ¯ó³w
		SetConsoleTextAttribute(hOut, 139);
		break;
	case 'C':	// Cyber Owca
		SetConsoleTextAttribute(hOut, 139);
		break;
	case 'H':	// Cz³owiek
		SetConsoleTextAttribute(hOut, 128);
		break;
	case ' ':	// Puste pole
		SetConsoleTextAttribute(hOut, 136);
		break;
	default:	// Ramki
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		break;
	}
}

const void World::drawWorldFirstTime() {					// Rysowanie planszy na ekran
	system("cls");
	cout << char(201);
	for (size_t fence = 1; fence < SIZE_V + 1; fence++) {
		if (fence == (SIZE_V + 2) / 2 - 2) {
			cout << "WORLD";
			fence += 5;
		}
		cout << char(205);
	}
	cout << char(187) << endl;
	for (size_t yR = 0; yR < SIZE_H; yR++) {
		cout << char(186);
		for (size_t xR = 0; xR < SIZE_V; xR++) {
				color(box[yR][xR]);
				cout << box[yR][xR];
				OLDbox[yR][xR] = box[yR][xR];
				color(NULL);
		}
		cout << char(186);
		cout << endl;
	}
	cout << char(200);
	for (size_t fence = 1; fence < SIZE_V + 1; fence++)
		cout << char(205);
	cout << char(188) << endl;
}

const void World::drawWorld() {					// Rysowanie planszy na ekran
	for (size_t yR = 0; yR < SIZE_H; yR++) {
		for (size_t xR = 0; xR < SIZE_V; xR++) {
			if (box[yR][xR] != OLDbox[yR][xR]) {
				gotoxy(xR, yR);
				color(box[yR][xR]);
				cout << box[yR][xR];
				OLDbox[yR][xR] = box[yR][xR];
				color(NULL);
			}
		}
	}
	static int numOfCom;
	gotoxy(-1, this->getSizeH() + 1);
	for (int k = 1; k + this->getSizeH() < 39; k++) {
		gotoxy(-1, this->getSizeH() + k);
		//cout << "\n";
		cout << "                                                                                                                    ";
	}

	int BUFORSIZE = 0;

	if(this->getSizeH() > 36 || this->getSizeV() > 55)
		BUFORSIZE = 44;
	else
		BUFORSIZE = 39;
	int i = 0;
	int newLineH = 0;
	for (auto n : comments) {
		i++;
		if (i + this->getSizeH() == 39) {
			i =1;
			newLineH += 28;
		}
		if (newLineH == 112)
			break;
		gotoxy(-1 + newLineH, this->getSizeH() + i);
		cout << " | " << n;
	}
	numOfCom = i;
	this->comments.clear();
}

static bool compareTwoOrganism(Organism* a, Organism* b) {	// Warunek sortowania
	return (*a < *b);
}

void World::sortOrganism() {	// Sortuje wektor organizmow wedlug inicjatywy
	sort(organismMap.rbegin(), organismMap.rend(), compareTwoOrganism);
	return;
}

const void World::deleteOrganisms() {
	for (auto n : toKill) {
		if (n->getInitiative() == -1) {
			if (n->getSymbol() == 'H') {
				gotoxy(0, this->getSizeH() + 1);
				system("pause");				// DODAC OKIENKO GAME OVER
				exit(1);
			}
			else
				delete n;
		}
	}
	toKill.clear();
}

const void World::doRound() {					// Wykonuje runde
	this->round += 1;
	vector<Organism*> organismMapTMP = organismMap;
	for (auto n : organismMapTMP) {
		n->action();
	}
	this->deleteOrganisms();
	this->sortOrganism();

	for (auto m : organismMap) {
		if (box[m->getY()][m->getX()] != m->getSymbol())
			box[m->getY()][m->getX()] = m->getSymbol();
	}

	Sleep(50);
}

const size_t World::getSizeH() {		// Zwraca jakiej wielkosci jest swiat
	return this->SIZE_H;
}

const size_t World::getSizeV() {		// Zwraca jakiej wielkosci jest swiat
	return this->SIZE_V;
}

static bool findIDOrganism(Organism* a, Organism* b) {	// Warunek szukania
	return (*a < *b);
}

const void World::killOrganism(Organism * org) {		// Usuwa organizmy
	if (box[org->getPointY()][org->getPointX()] == org->getSymbol())
		box[org->getPointY()][org->getPointX()] = ' ';
	
	vector<Organism*> organismMapTMP = organismMap;

	auto it = find(begin(organismMap), end(organismMap), org);

	if (it != end(organismMap)) {
		toKill.push_back(*it);
		organismMap.erase(it);
	}

	return;
}

const void World::saveGame(const bool &skillActivity, const int &skillCooldown) {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int iks = this->getSizeH() / 4;
	int yrek = this->getSizeV() / 2 - 8;
	system("cls");
	string name;
	gotoxy(yrek, iks);
	cout << "Podaj nazwe pliku: ";
	gotoxy(yrek+5, iks+1);
	SetConsoleTextAttribute(hOut, 4); // Czerwony
	cin >> name;
	SetConsoleTextAttribute(hOut, 7);	// Bialy
	fstream file;
	file.open(name, fstream::out);
	if (!file.good()) {
		gotoxy(yrek+1, iks+3);
		SetConsoleTextAttribute(hOut, 4); // Czerwony
		cout << "ERROR" << endl;
		SetConsoleTextAttribute(hOut, 15);	// Bialy
		cout << endl;
		system("pause");
		return;
	}

	// Zapisywanie danych
	file << this->round << " " << this->getSizeH() << " " << this->getSizeV() << " " << this->organismMap.size() << endl;
	for (auto n : organismMap) {
		file << n->getSymbol() << " ";
		file << n->getX() << " " << n->getY() << " ";
		file << n->getPointX() << " " << n->getPointY() << " ";
		file << n->getStrength() << " ";
		file << n->getInitiative() << " ";
		file << n->getAge() << " ";
		file << n->getID() << " ";
		if (n->getSymbol() == 'H') {
			file << skillActivity << " ";
			file << skillCooldown << " ";
		}
		file << endl;
	}
	file.close();


	system("cls");
	gotoxy(yrek-1, iks);
	cout << "Gra zapisana w pliku: ";
	SetConsoleTextAttribute(hOut, 10);	// Czerwony
	gotoxy(yrek+5, iks+1);
	cout << name;
	SetConsoleTextAttribute(hOut, 7);	// Bialy
	gotoxy(yrek-6, iks+5);
	cout << endl;
	system("pause");
	system("cls");

	return;
}

const void World::fillTheMap() {
	int plantAmount = this->getSizeH() / 4 + 1;
	int animalAmount = this->getSizeV() / 4 + 1;
	srand(time(NULL));
	int newX = 0;
	int newY = 0;

	do {
		newX = rand() % this->getSizeV();
		newY = rand() % this->getSizeH();
	} while (this->findOrganism(newY, newX));

	this->addOrganism(new Human(*this, newX, newY));
	// Zwierzeta
	for (int i = 0; i < animalAmount; i++) {
		int animal = rand() % N_OF_ANIMAL;

		do {
			newX = rand() % this->getSizeV();
			newY = rand() % this->getSizeH();
		} while (this->findOrganism(newY, newX));

		switch (animal) {
			case 0: {
				this->addOrganism(new Sheep(*this, newX, newY));
				break;
			}
			case 1: {
				this->addOrganism(new Wolf(*this, newX, newY));
				break;
			}
			case 2: {
				this->addOrganism(new Turtle(*this, newX, newY));
				break;
			}
			case 3: {
				this->addOrganism(new Fox(*this, newX, newY));
				break;
			}
			case 4: 
			default:{
				this->addOrganism(new Antelope(*this, newX, newY));
				break;
			}
		}
	}

	// Rosliny
	for (int i = 0; i < plantAmount; i++) {
		int plant = rand() % N_OF_PLANTS;


		do {
			newX = rand() % this->getSizeV();
			newY = rand() % this->getSizeH();
		} while (this->findOrganism(newY, newX));

		switch (plant) {
		case 0: {
			this->addOrganism(new Dandelion(*this, newX, newY));
			break;
		}
		case 1: {
			this->addOrganism(new Grass(*this, newX, newY));
			break;
		}
		case 2: {
			this->addOrganism(new Guarana(*this, newX, newY));
			break;
		}
		case 3: {
			this->addOrganism(new Heracleum(*this, newX, newY));
			break;
		}
		case 4:
		default: {
			this->addOrganism(new Wolfberry(*this, newX, newY));
			break;
		}
		}
	}
}

const void World::addComment(string &newComment) {
	this->comments.push_back(newComment);
}