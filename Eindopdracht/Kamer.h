#pragma once
#include "Level.h"
#include "Vijand.h"
#include "richting.h"
#include <array>

using namespace std;

class Kamer
{
public:
	Kamer(Level* lvl, int x, int y, string omschrijving, Vijand* vijand);
	Level * GetLevel();
	int GetPositieX();
	int GetPositieY();
	Vijand * heeftVijand();
	string GetMapIcon();
	Kamer * GetBuurKamer(Richting);
	void ZetBuurKamer(Kamer *, Richting);
	Kamer();
	~Kamer();

	string getOmschrijving();

	bool valVijandAan(int);

	void vijandVerslagen();

	Kamer* Noord;
	Kamer* Oost;
	Kamer* Zuid;
	Kamer* West;
	Level* level;
	array<bool, 4> uitgang;

protected:
	Vijand* vijand;
	int positieX;
	int positieY;
	string omschrijving;

};