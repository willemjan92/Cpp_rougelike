#include "Level.h"

Level::Level(int level)
{
	levelNr = level;
	moeilijkheid = rand() % (levelNr+1 * 2) + levelNr;
}

Level::Level()
{
}

Level::~Level()
{
}

int Level::getLaag()
{
	return levelNr;
}
