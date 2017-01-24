#include "Speler.h"
Speler::Speler() {

}

Speler::Speler(string Naam, int lvl, int hp, int exp, int att, int def, vector<Items*> rugzak){ // TODO: rugzak met items: vector<item *> rugzak 
	this->naam = Naam;
	this->level = lvl;
	this->hp = hp;
	this->experience = exp;
	this->attack = att;
	this->defence = def;
	this->rugzak = rugzak;

}


void Speler::levelUp() {
	level++;
	cout << "Level up! Gefeliciteerd! Je bent nu level " << level << endl;
	hp = 100;
	attUp(5);
	defUp(6);
	experience = 0;
	cin.get();
}

void Speler::expUp(int val) {
	experience += val;
	if (experience > 100) {
		levelUp();
	}

}

void Speler::heal(int val) {
	hp += val;
	if (hp > 100) {
		hp = 100;
	}
	cout << "Je bent weer beter gemaakt! Je hp is: " << hp;

}

void Speler::attUp(int val) {
	attack += val;
	cout << "Je bent sterker geworden! Je aanvalspunten zijn: " << attack << endl;

}

void Speler::defUp(int val) {
	defence += val;
	cout << "Je bent beter bestand tegen aanvallen! Je verdedigingspunten zijn: " << defence << endl;
}

void Speler::nieuwItem(Items* item) {
	rugzak.push_back(item);
}

int Speler::getAtt(){
	return attack;
}

int Speler::getHp(){
	return hp;
}

int Speler::getDef(){
	return defence;
}

string Speler::getNaam(){
	return naam;
}

int Speler::getLVL()
{
	return level;
}

void Speler::ZetHuidigeKamer(Kamer* kamer) {
	vorigeKamer = huidigeKamer;
	huidigeKamer = kamer;
	//cin.get();
}

Kamer* Speler::GetHuidigeKamer() {
	return huidigeKamer;
}

Kamer* Speler::GetVorigeKamer() {
	return vorigeKamer;
}

void Speler::valAan() {
	if (huidigeKamer->valVijandAan(attack))
	{
		int expPunten = huidigeKamer->heeftVijand()->getExp();
		expUp(expPunten);
		huidigeKamer->vijandVerslagen();
	}
	else
	{
		if (ontvangSchade(huidigeKamer->heeftVijand()->getAtt())) {
			exit(0);
		}
	}
}

bool Speler::ontvangSchade(int schade) {
	int echteSchade = schade - defence;
	if (echteSchade <= 0) {
		echteSchade = 0;
	}
	hp -= echteSchade; if (hp <= 0) {
		cout << "de vijand heeft je verslagen :( GAME OVER..";
		return true;
	}
	else {
		cout << "Je hebt " << echteSchade << " schade gekregen.. Je hebt " << hp << " levenspunten over..";
		return false;
	}
}

Speler::~Speler() {

}
