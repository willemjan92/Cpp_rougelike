#include "Vijand.h"

#include "stdafx.h"
using namespace std;

Vijand::Vijand() {

}

Vijand::Vijand(string naam, int lvl, int hp, int att, int def, int exp)
{
	this->naam = naam;
	this->lvl = lvl;
	this->hp = hp;
	this->att = att;
	this->def = def;
	this->exp = exp;

}


Vijand::~Vijand()
{
}

Vijand * Vijand::maakVijand()
{
	return new Vijand();
}

void Vijand::InitialiseerVijand(string naam, int lvl, int hp, int att, int def, int exp)
{
	this->naam = naam;
	this->lvl = lvl;
	this->hp = hp;
	this->att = att;
	this->def = def;
	this->exp = exp;

	cout << this->naam << " : " << this->att << endl;
}

string Vijand::getOmschrijving()
{
	return naam;
}

bool Vijand::wordtAangevallen(int schade)
{
	int echteSchade = schade - def;
	if (echteSchade <= 0) {
		echteSchade = 0;
	}
	hp -= echteSchade;
	if (hp <= 0) {
		cout << "de vijand is voor " << echteSchade << " aangevallen, en is verslagen!";
		cin.get();
		return true;
	}
	else {
		cout << "de vijand is voor " << echteSchade << "aangevallen, en heeft " << hp << " levenspunten over.." ;
		cin.get();
	}
	return false;
}

int Vijand::getExp()
{
	return exp;
}
int Vijand::getAtt()
{
	return att;
}
