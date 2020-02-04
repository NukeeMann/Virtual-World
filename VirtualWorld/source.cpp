#include <iostream>
#include <string>
#include "Windows.h"
#include "World.h"
#include "Organism.h"
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
#include <conio.h>
#include <fstream>

#define ESC 27
using namespace std;


void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x + 1;
	pos.Y = y + 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
};

void MainScreen() {
	//cout << "\n\n\n\n\n\n                    ";

	gotoxy(50, 15);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << char(201);
	for (size_t fence = 1; fence < 15 + 1; fence++) {
		if (fence == 6) {
			cout << "WORLD";
			fence += 5;
		}
		cout << char(205);
	}
	cout << char(187) << endl;


	SetConsoleTextAttribute(hConsole, 15);
	for (size_t yR = 0; yR < 10; yR++) {
		//cout <<"                    "<< char(186);
		gotoxy(50, 16 + yR);
		cout << char(186);
		for (size_t xR = 0; xR < 15; xR++) {
			//color(box[yR][xR]);
			SetConsoleTextAttribute(hConsole, 95);
			if (yR == 1 && xR == 1) {
				SetConsoleTextAttribute(hConsole, 86);
				cout << "WIRTUAL WORLD";
				xR += 12;
			}
			else if (yR == 2 && xR > 0 && xR < 14) {
				SetConsoleTextAttribute(hConsole, 94);
				cout << char(220);
			}
			else if (yR == 5 && xR == 2) {
				cout << "New Game -n";
				xR += 10;
			}
			else if (yR == 7 && xR == 1) {
				cout << "Load Game -l";
				xR += 11;
			}
			else {
				cout << ' ';
			}
			SetConsoleTextAttribute(hConsole, 15);
			//color(NULL);
		}
		cout << char(186);
	}
	gotoxy(50, 26);
	//cout << "                    " << char(200);
	cout << char(200);
	for (size_t fence = 1; fence < 15 + 1; fence++)
		cout << char(205);
	cout << char(188) << endl;
	SetConsoleTextAttribute(hConsole, 15);
	gotoxy(50, 28);
	//cout << "\n\n";
}

bool loadGame(string name) {

	fstream plik;

	plik.open(name, fstream::in);
	if (!plik.good()) {
		gotoxy(40, 10);
		cout << "                                        ";
		gotoxy(50, 12);
		cout << "                                        ";
		gotoxy(50, 10);
		cout << "Plik nie istnieje!";
		gotoxy(45, 11);
		system("pause");
		system("cls");
		return false;
	}
	// Podstawowe dane
	int round, height, width, NumberOfOrganisms;
	plik >> round >> height >> width >> NumberOfOrganisms;
	// Tworzenie swiata
	World swiat(height, width);

	// Dane organizmow
	for (int i = 0; i < NumberOfOrganisms; i++) {
		char symbol;
		int x, y, pointX, pointY, strength, initiative, age, id;
		plik >> symbol >> x >> y >> pointX >> pointY >> strength >> initiative >> age >> id;
		switch (symbol) {
		case 't':
			swiat.addOrganism(new Grass(swiat, x, y, 0.03, strength, initiative, age));
			break;
		case 'm':
			swiat.addOrganism(new Dandelion(swiat, x, y, 0.03, strength, initiative, age));
			break;
		case 'g':
			swiat.addOrganism(new Guarana(swiat, x, y, 0.03, strength, initiative, age));
			break;
		case 'h':
			swiat.addOrganism(new Heracleum(swiat, x, y, 0.03, strength, initiative, age));
			break;
		case 'b':
			swiat.addOrganism(new Wolfberry(swiat, x, y, 0.03, strength, initiative, age));
			break;
		case 'A':
			swiat.addOrganism(new Antelope(swiat, x, y, strength, initiative, age));
			break;
		case 'F':
			swiat.addOrganism(new Fox(swiat, x, y, strength, initiative, age));
			break;
		case 'S':
			swiat.addOrganism(new Sheep(swiat, x, y, strength, initiative, age));
			break;
		case 'T':
			swiat.addOrganism(new Turtle(swiat, x, y, strength, initiative, age));
			break;
		case 'W':
			swiat.addOrganism(new Wolf(swiat, x, y, strength, initiative, age));
			break;
		case 'H':
			int specialSkillCooldown;
			bool specialSkillActivity;
			plik >> specialSkillActivity >> specialSkillCooldown;
			swiat.addOrganism(new Human(swiat, x, y, strength, initiative, specialSkillActivity, specialSkillCooldown));
			break;
		}
	}

	plik.close();

	swiat.drawWorldFirstTime();
	while (true) {
		swiat.doRound();
	}
	return true;

}

int main() {
	SetConsoleTitle(TEXT("Michal Wnuczynski 175739"));

	unsigned char znak = ' ';
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int height = 0;
	int width = 0;

	do {
		gotoxy(49, 28);
		cout << "                                          ";
		gotoxy(49, 29);
		cout << "                                          ";
		MainScreen();
		znak = _getch();
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
		}
		if (znak == 'l' || znak == 'L') {
			string plik;
			//cout << "                   Podaj nazwe pliku : \n                         ";
			cout << "Podaj nazwe pliku";
			gotoxy(55, 29);
			SetConsoleTextAttribute(hConsole, 12);
			cin >> plik;
			SetConsoleTextAttribute(hConsole, 15);
			loadGame(plik);
		}
		else if (znak == 'N' || znak == 'n') {
			// Czyszczenie danych

			gotoxy(49, 28);
			cout << "Podaj  wysokosc: ";
			SetConsoleTextAttribute(hConsole, 12);
			cin >> height;
			SetConsoleTextAttribute(hConsole, 15);

			gotoxy(49, 29);
			cout << "Podaj szerokosc: ";
			SetConsoleTextAttribute(hConsole, 12);
			cin >> width;
			SetConsoleTextAttribute(hConsole, 15);
			if (height == 0 || width == 0)
			{
				gotoxy(40, 10);
				cout << "     Rozmiar musi byc wiekszy od 0!   ";
				znak = 'x';
			}
			else if (height > 36) {
				gotoxy(40, 10);
				cout << " Wysokosc nie moze byc wieksza niz 36!";
				znak = 'x';
			}
			else if (width > 118) {
				gotoxy(40, 10);
				cout << "Szerokosc nie moze byc wieksza niz 118!";
				znak = 'x';
			}
			gotoxy(50, 12);
			cout << "Sprobuj ponownie.";
		}
		else if (znak == ESC)
			return 0;

	} while (znak != 'n' && znak != 'N' );
	
	if (znak == 'n' || znak == 'N') {
		
		if(height>27 || width > 55)		// Jezeli rozmiar jest wiekszy od optymalnego, ustawia pelny ekran
			::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

		World swiat(height, width);

		if(height == 27 && width == 55){
			//swiat.addOrganism(new CyberSheep(swiat, 0, 0));
			swiat.addOrganism(new Wolf(swiat, 3, 0));
			swiat.addOrganism(new Wolf(swiat, 50, 6));
			swiat.addOrganism(new Wolf(swiat, 42, 6));
			//swiat.addOrganism(new Wolf(swiat, height * 2 - 3, height - 2));
			swiat.addOrganism(new Sheep(swiat, 5, 4));
			swiat.addOrganism(new Sheep(swiat, 14, 4));
			//swiat.addOrganism(new Sheep(swiat, 9, 1));
			swiat.addOrganism(new Sheep(swiat, 50, 17));
			swiat.addOrganism(new Fox(swiat, 24, 1));
			swiat.addOrganism(new Human(swiat, 20, 3));
			swiat.addOrganism(new Antelope(swiat, 10, 10));
			swiat.addOrganism(new Antelope(swiat, 1, 2));
			swiat.addOrganism(new Turtle(swiat, 1, 3));
			swiat.addOrganism(new Turtle(swiat, 1, 6));
			//swiat.addOrganism(new Human(swiat, 0, 0));

			swiat.addOrganism(new Grass(swiat, 4, height / 2, 0.05));
			swiat.addOrganism(new Guarana(swiat, 15, height / 2, 0.1));
			swiat.addOrganism(new Guarana(swiat, 12, height / 2, 0.05));
			swiat.addOrganism(new Wolfberry(swiat, 30, 13, 0.06));
			//swiat.addOrganism(new Guarana(swiat, 1, 3, 0.05));
			swiat.addOrganism(new Grass(swiat, 0, 2, 0.05));
			swiat.addOrganism(new Grass(swiat, 0, 0, 0.05));
			swiat.addOrganism(new Grass(swiat, 1, 0, 0.05));
			//swiat.addOrganism(new Grass(swiat, 1, 2, 0.05));
			swiat.addOrganism(new Grass(swiat, 2, 0, 0.05));
			swiat.addOrganism(new Grass(swiat, 2, 1, 0.05));
			swiat.addOrganism(new Grass(swiat, 0, 1, 0.05));
			//swiat.addOrganism(new Grass(swiat, 52, 25, 0.05));
			//swiat.addOrganism(new Grass(swiat, 53, 25, 0.05));
			//swiat.addOrganism(new Grass(swiat, 52, 24, 0.05));
			//swiat.addOrganism(new Grass(swiat, 52, 23, 0.05));
			swiat.addOrganism(new Heracleum(swiat, 20, 20, 0.01));
		}
		else {
			swiat.fillTheMap();
		}

		swiat.drawWorldFirstTime();

		while (true) {
			swiat.doRound();
		}
	}

	return 0;
}