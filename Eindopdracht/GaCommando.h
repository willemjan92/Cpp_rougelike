#pragma once
#include <string>
#include "Dungeon.h"


using namespace std;


class GaCommando
{
public:
	GaCommando();
	GaCommando(string, Dungeon*);
	bool CheckDirection(string);
	~GaCommando();

private:
	unordered_map<string, Richting> richtingMap;
};
