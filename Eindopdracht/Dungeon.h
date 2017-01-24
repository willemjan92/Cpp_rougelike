#pragma once
#include <iostream>
#include "KamerFactory.h"
#include "Speler.h"

class Dungeon
{
public:
	Dungeon();
	Dungeon(int lagen, int lengte, int breedte, string naam);
	int getLengte();
	int getBreedte();
	Speler * GetSpeler();
	KamerFactory * getKamerFactory();
	~Dungeon();

private:
	int kamers;
	Speler* speler;
	vector<Items*> items;

	int lengte;
	int breedte;

	KamerFactory* kamerFactory;
	Kamer* startkamer;

};