#include "Kamer.h"


Kamer::Kamer(Level * lvl, int x, int y, string omschrijving, Vijand * vijand)
{
	level = lvl;
	positieX = x;
	positieY = y;
	this->omschrijving = omschrijving;
	this->vijand = vijand;
	Noord = nullptr;
	Oost = nullptr;
	Zuid = nullptr;
	West = nullptr;
}

Level* Kamer::GetLevel() {
	return level;
}
int Kamer::GetPositieX() {
	return positieX;
}
int Kamer::GetPositieY() {
	return positieY;
}
Vijand* Kamer::heeftVijand() {
	return vijand;
}


string Kamer::GetMapIcon() {
	if (vijand != nullptr) {
		return "M"; //
	}
	else {
		return " ";

	}
}

Kamer* Kamer::GetBuurKamer(Richting richting) 
{
	switch (richting)
	{
	case Richting::Noord:
		return Noord;
		break;
	case Richting::Oost:
		return Oost;
		break;
	case Richting::Zuid:
		return Zuid;
		break;
	case Richting::West:
		return West;
		break;
	default:
		break;
	}
}
void Kamer::ZetBuurKamer(Kamer* kamer, Richting richting) {
	if (kamer) {
		switch (richting)
		{
		case Richting::Noord:
			Noord = kamer;
			kamer->Zuid = this;
			uitgang[0] = true;
			break;
		case Richting::Oost:
			Oost = kamer;
			kamer->West = this;
			uitgang[1] = true;
			break;
		case Richting::Zuid:
			Zuid = kamer;
			kamer->Noord = this;
			uitgang[2] = true;
			break;
		case Richting::West:
			West = kamer;
			kamer->Oost = this;
			uitgang[3] = true;
			break;
		default:
			break;
		}
	}
}
Kamer::Kamer()
{
}

Kamer::~Kamer()
{
}

string Kamer::getOmschrijving(){
	return omschrijving;
}


bool Kamer::valVijandAan(int damage) {
	if (vijand->wordtAangevallen(damage)) {
		return true;
	}
	else {
		return false;
	}
}

void Kamer::vijandVerslagen()
{
	vijand = nullptr;
}
