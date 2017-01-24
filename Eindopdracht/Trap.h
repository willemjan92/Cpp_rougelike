#pragma once
#include "Kamer.h"



class Trap : public Kamer
{
public:
	Trap(Level*, int, int, Vijand*);
	Trap();
	string GetMapIcon();
	Kamer * GetBuurKamer(Richting richting);
	void ZetBuurKamer(Kamer * kamer, Richting richting);
	~Trap();

private:
	Kamer* Omhoog;
	Kamer* Omlaag;

};
