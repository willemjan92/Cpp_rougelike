#include "Dungeon.h"

Dungeon::Dungeon()
{

}

Dungeon::Dungeon(int lagen, int lengte, int breedte, string naam)
{
	this->lengte = lengte;
	this->breedte = breedte;
	kamerFactory = new KamerFactory();
	Kamer* startKamer = kamerFactory->maakKamers(lagen, lengte, breedte);
	this->kamers = ((lengte * breedte) * lagen);
	speler = new Speler(naam, 1, 100, 0, 55, 25, items);
	speler->ZetHuidigeKamer(startKamer);
}

int Dungeon::getLengte() {
	return this->lengte;
}

int Dungeon::getBreedte()
{
	return this->breedte;
}

Speler* Dungeon::GetSpeler() {
	return speler;
}

KamerFactory* Dungeon::getKamerFactory() {
	return kamerFactory;
}

Dungeon::~Dungeon() 
{
	kamerFactory = nullptr;
}