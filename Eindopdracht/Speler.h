#include <iostream>
#include "stdafx.h"
#include "Items.h"
#include <unordered_map>
#include "Kamer.h"

class Speler
{
public:
	Speler ();
	Speler (string Naam, int lvl, int hp, int exp, int att,int def, vector<Items*> rugzak); 
	~Speler ();

	void levelUp();
	void expUp(int);
	void heal(int);
	void attUp(int);
	void defUp(int);
	void nieuwItem(Items*);

	int getAtt();
	int getHp();
	int getDef();
	string getNaam();
	int getLVL();

	void ZetHuidigeKamer(Kamer * kamer);

	Kamer * GetHuidigeKamer();

	Kamer * GetVorigeKamer();

	void valAan();

	bool ontvangSchade(int schade);

protected:
	string naam;
	int level;
	int hp;
	int experience;
	int attack;
	int defence;
	vector<Items*> rugzak;
	Kamer* huidigeKamer;
	Kamer* vorigeKamer;
};