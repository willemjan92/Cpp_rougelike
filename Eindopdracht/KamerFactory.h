#pragma once
#include "Kamer.h"
#include "Trap.h"
#include "BossKamer.h"
#include "Array3D.h"
#include "Level.h"
#include "Vijand.h"
#include "VijandFactory.h"
#include <iostream>
#include <unordered_map>
#include <string>

class KamerFactory
{
public:
	KamerFactory();
	~KamerFactory();
	Kamer * maakKamers(int, int, int);

	Kamer* maakKamer(Level*, int, int);

	Array3D* getArray3D();

	void RandomKamersRondom(Kamer *, int, int, int, int);

	Kamer * RandomKamerRichting(Kamer *, Richting);


private:
	std::string kamerTypes[2];
	std::string kamerGroote[3];
	std::string kamerObjecten[5];
	std::string kamerLicht[2];
	int aantalLagen;

	VijandFactory vijandFactory;

	Array3D* array3D;
};