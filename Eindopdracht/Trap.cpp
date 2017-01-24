#include "Trap.h"


Trap::Trap(Level * lvl, int x, int y, Vijand * vijand) : Kamer(lvl, x, y, "trap", vijand)
{
}

Trap::Trap()
{
}

string Trap::getMapIcon() {
	return "S";
}

Kamer* Trap::GetBuurKamer(Richting richting)
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
	case Richting::Omhoog:
		return Omhoog;
		break;
	case Richting::Omlaag:
		return Omlaag;
		break;
	default:
		break;
	}
}

void Trap::ZetBuurKamer(Kamer* kamer, Richting richting) {
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
		case Richting::Omhoog:
			Omhoog = kamer;
			break;
		case Richting::Omlaag:
			Omlaag = kamer;
			break;
		default:
			break;
		}
	}
}

Trap::~Trap()
{
}