#include "KamerFactory.h"
#include "KamerFactory.h"

KamerFactory::KamerFactory()
{
	vijandFactory = VijandFactory();
	kamerTypes[0] = "opgeruimde";
	kamerTypes[1] = "stoffige";

	kamerGroote[0] = "groote";
	kamerGroote[1] = "een beetje groote";
	kamerGroote[2] = "kleine";

	kamerLicht[0] = "weinig licht";
	kamerLicht[1] = "veel licht";

	kamerObjecten[0] = "2 stoelen";
	kamerObjecten[1] = "een emmer";
	kamerObjecten[2] = "een tafel";
	kamerObjecten[3] = "een bed";
	kamerObjecten[4] = "enkele dozen";

		
}

KamerFactory::~KamerFactory()
{
}

Kamer* KamerFactory::maakKamers(int lagen, int lengte, int breedte) 
{
	aantalLagen = lagen;
	array3D = new Array3D(lengte, breedte, lagen);

	std::vector<Level*> laag(lagen);

	for (int i = 0; i < lagen; i++)
	{
		laag[i] = new Level(i);
		Kamer* trap = nullptr;
		Vijand* vijand = nullptr;

		int random = rand() % 3;

		if (random > 1) 
		{
			int monsterNr = rand() % 12;
			vijand = vijandFactory.maakVijand(VijandType::Vijand, monsterNr);
			monsterNr = NULL;
		}
		trap = new Trap(laag[i], 4, 4, vijand);
		array3D->voegKamerToeAanArray(trap, 4, 4,laag[i]->getLaag());
		RandomKamersRondom(trap, 4, 4, 4, 4);
	}


	for (int i = 0; i + 1 < lagen; ++i)
	{
		if (i != 0) {
			array3D->getKamer(4, 4, i)->ZetBuurKamer(array3D->getKamer(4, 4, i - 1), Richting::Omlaag);
		}
		if (i + 1 < lagen) {
			array3D->getKamer(4, 4, i)->ZetBuurKamer(array3D->getKamer(4, 4, i + 1), Richting::Omhoog);
		}
	}

	if (array3D->getKamer(4, 5, 0)) {
		return array3D->getKamer(4, 5, 0);
	}
	else if (array3D->getKamer(6, 5, 0)) {
		return array3D->getKamer(6, 5, 0);
	}
	else if (array3D->getKamer(5, 4, 0)) {
		return array3D->getKamer(5, 4, 0);
	}
	else if (array3D->getKamer(5, 6, 0)) {
		return array3D->getKamer(5, 6, 0);
	}
	else {
		return array3D->getKamer(4, 4, 0);
	}


}

Kamer* KamerFactory::maakKamer(Level* lvl, int x, int y)
{
	Kamer* kamer = nullptr;

	string omschrijving = "Je bent in een "+ kamerTypes[rand() %2]+ ", " + kamerGroote[rand() % 3] + " kamer. ";
	omschrijving += "Er is " + kamerLicht[rand() % 2] +" in de kamer. ";
	omschrijving += "Met in de hoek " + kamerObjecten[rand() % 5];
	Vijand* vijand = nullptr;
	if (lvl->getLaag() == aantalLagen)
	{
		kamer = new BossKamer(lvl, x, y, vijandFactory.maakBaas(lvl));
	}
	else
	{
		if (rand() % 3 > 1)
		{
			int monsterNr = rand() % 12;
			vijand = vijandFactory.maakVijand(VijandType::Vijand, monsterNr);
		}
		kamer = new Kamer(lvl, x, y, omschrijving, vijand);
	}
	array3D->voegKamerToeAanArray(kamer, x, y, lvl->getLaag());
	return kamer;
}

Array3D * KamerFactory::getArray3D()
{
	return array3D;
}


void KamerFactory::RandomKamersRondom(Kamer* kamer, int noord, int oost, int zuid, int west)
{
	Kamer* tempKamer = nullptr;
	if (noord > 0)
	{
		tempKamer = RandomKamerRichting(kamer, Richting::Noord);
		if (tempKamer != nullptr) {
			RandomKamersRondom(tempKamer, noord - 1, zuid, west, oost);
		}
	}
	if (oost > 0)
	{
		tempKamer = RandomKamerRichting(kamer, Richting::Oost);
		if (tempKamer != nullptr) {
			RandomKamersRondom(tempKamer, noord, oost - 1, zuid, west);
		}
	}
	if (zuid > 0)
	{
		tempKamer = RandomKamerRichting(kamer, Richting::Zuid);
		if (tempKamer != nullptr) {
			RandomKamersRondom(tempKamer, noord, oost, zuid - 1, west);
		}
	}
	if (west > 0)
	{
		tempKamer = RandomKamerRichting(kamer, Richting::West);
		if (tempKamer != nullptr) {
			RandomKamersRondom(tempKamer, noord, oost, zuid, west - 1);
		}
	}
}


Kamer* KamerFactory::RandomKamerRichting(Kamer* kamer, Richting richting)
{
	int x = kamer->GetPositieX();
	int y = kamer->GetPositieY();
	int z = kamer->GetLevel()->getLaag();

	switch (richting)
	{
	case Richting::Noord:
		x = x - 1;
		break;
	case Richting::Oost:
		y = y + 1;
		break;
	case Richting::Zuid:
		x = x + 1;
		break;
	case Richting::West:
		y = y - 1;
		break;

	}
	Kamer* tempKamer = nullptr;
	if (array3D->getKamer(x, y, z) == nullptr || array3D->getKamer(x, y, z) == NULL) {
			tempKamer = maakKamer(kamer->GetLevel(), x, y);
			kamer->ZetBuurKamer(tempKamer, richting);
	}
	/*else if (rand() % 4 > 1) {
		kamer->ZetBuurKamer(array3D->getKamer(x, y, z), richting);

	}*/
	return tempKamer;
}

