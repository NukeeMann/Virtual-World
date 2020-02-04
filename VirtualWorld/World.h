#pragma once
#include <iostream>
#include <string>
#include "Organism.h"
#include <unordered_map>

using namespace std;

class Organism;

class World {
	char **box;
	char **OLDbox;
	int round;
	size_t SIZE_V, SIZE_H;
	vector<Organism*> organismMap;
	vector<string> comments;
	vector<Organism*> toKill;

	const void deleteOrganisms();	// Po turze usuwa organizmy
	void sortOrganism(); // Sortuje organizmy w hasmpaie wzgledem inicjatywy i wieku
public:
	// Podstawowe funkcje
	World(int map_sizeH, int map_sizeV);
	const void doRound();	// Wykonuje runde

	// Getery
	const size_t getSizeH();
	const size_t getSizeV();

	// Funkcje dla organizmow
	const void addOrganism(Organism *org);	// Dodaje organizm do gry
	const bool findOrganism(const int &yf,const int &xf);	// Znajduje organizm na danej pozycji
	const bool findOrganismToKill(const int &yf, const int &xf, const char &znak);	// Znajduje organizm na danej pozycji
	const void KillOrganismAround(Organism *org, const int &yf, const int &xf, const char &whatToKill = 'X');	// Zabija wszystko w sasiedztwie w zaleznosci o wytycznych
	const bool compareStrength(Organism *org, const int &yf, const int &xf);	// Porownuje sile dwoch organizmow
	const void killOrganism(Organism *org); // Zabija organizm ( Usuwa z hashmapy i ustawia inicjatywe na -1)
	const bool moveAnimal(Organism *org);	// Zmienia pozycje zwierzecia
	const void fillTheMap();	// Losuje i wypelnia mape organizmami
	
	// Funkcje do zapisu i wczytania
	const void saveGame(const bool &skillActivity, const int &skillCooldown);	// Zapisuje stan gry

	// Komentator
	const void addComment(string &newComment);	// Dodaje komentarz do wyswietlenia po turze

	// Inne
	const void drawWorld();		// Rysuje zmieniony swiat co ture
	const void drawWorldFirstTime();	// Rysuje cala plansze pierwszy raz
};