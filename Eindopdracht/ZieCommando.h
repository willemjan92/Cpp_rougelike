#pragma once
#include "Dungeon.h"

class ZieCommando
{
public:
	ZieCommando();
	ZieCommando(Speler* speler);
	ZieCommando(Dungeon * dungeon);
	void printMap();
	void PrintHorizontaleHalEnHuidigeKamer(Kamer * kamer);
	void PrintVerticaleHal(Kamer * kamer);
	~ZieCommando();

private:
	Dungeon* dungeon;
};