#pragma once
#include <cstdlib>
class Level
{
public:
	Level(int);
	Level();
	~Level();

	int getLaag();

private:
	int levelNr;
	int moeilijkheid;
};
