#pragma once
#include <string>
#include <iostream>
#include "VijandFactory.h"

using namespace std;
class Vijand
{
public:
	Vijand();
	Vijand(string naam, int lvl, int hp, int att, int def, int exp);
	//Vijand();
	~Vijand();
	Vijand* maakVijand();
	void InitialiseerVijand(string, int, int, int, int, int);

	string getOmschrijving();

	bool wordtAangevallen(int);

	int getExp();

	int getAtt();

private:
	string naam;
	int lvl;
	int hp;
	int att;
	int def;
	int exp;
};