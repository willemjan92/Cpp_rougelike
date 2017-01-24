#include "ZieCommando.h"

ZieCommando::ZieCommando()
{
}

ZieCommando::ZieCommando(Speler * speler)
{
	system("cls");
	cout << "Naam: " << speler->getNaam() << endl;
	cout << "levenspunten: " << speler->getHp() << endl;
	cout << "Aanvalspunten: " << speler->getAtt() << endl;
	cout << "Verdedegingspunten: " << speler->getDef() << endl;
	cout << "level: " << speler->getLVL() << endl;
	cin.get();
}

ZieCommando::ZieCommando(Dungeon* dungeon) {

	this->dungeon = dungeon;
	printMap();
}

void ZieCommando::printMap() {
	cout << "[ ] = Lege kamer" << endl;
	cout << "[X] = Je bent hier" << endl;
	cout << "[T] = Kamer met trap" << endl;
	cout << "[V] = kamer met vijand" << endl;
	cout << "[B] = Kamer met baas" << endl;
	cout << "- = hal oost/west" << endl;
	cout << "| = hal noord/zuid" << endl;
	size_t z = dungeon->GetSpeler()->GetHuidigeKamer()->GetLevel()->getLaag();
	for (int x = 0; x < 10; x++) {// dungeon->getLengte(); x++) {
		for (int y = 0; y < dungeon->getBreedte() - 1; y++) {
			PrintHorizontaleHalEnHuidigeKamer(dungeon->getKamerFactory()->getArray3D()->getKamer(x, y, z));
		}
		cout << endl;
		for (int y2 = 0; y2 < dungeon->getBreedte() - 1; y2++) {
			PrintVerticaleHal(dungeon->getKamerFactory()->getArray3D()->getKamer(x, y2, z));
		}
		cout << endl;
	}
	cout << "druk op [enter] om door te gaan." << endl;
	cin.get();
}

void ZieCommando::PrintHorizontaleHalEnHuidigeKamer(Kamer* kamer) {
	if (kamer != nullptr) {
		if (dungeon->GetSpeler()->GetHuidigeKamer() == kamer) {
			cout << "[X]";
		}
		else {
			cout << "[" << kamer->GetMapIcon() << "]";
		}
		if (kamer->GetBuurKamer(Richting::Oost)) {
				cout << "-";
		}
		else
		{
			cout << " ";
		}
	}
	else {
		cout << "[ ] ";
	}
}

void ZieCommando::PrintVerticaleHal(Kamer* kamer) {
	if (kamer != nullptr) {
		if (kamer->GetBuurKamer(Richting::Zuid)) {
			cout << " |  ";
		}
		else {
			cout << "    ";
		}
	}
	else {
		cout << " ";
	}
}



ZieCommando::~ZieCommando()
{
}