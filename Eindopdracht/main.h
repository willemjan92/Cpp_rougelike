#pragma once
#include <string>
#include "Dungeon.h"
#include "GaCommando.h"
#include "ZieCommando.h"
#include "vld.h"

class Main
{
public:
	Main();
	void run();
	void CommandHandler(string);
	~Main();


private:
	bool correct;
	bool startGame;
	bool runGame;
	std::string correctKeuze;
	int lagen;
	int breedte;
	int lengte;
	std::string keuze;
	//string bestandsnaam;
	Dungeon* dungeon;
	std::string naam;

	ZieCommando* zieCommando;
	GaCommando* ga;
};