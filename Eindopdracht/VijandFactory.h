#pragma once
#include "VijandType.h"
//#include "Vijand.h"
#include "Level.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <random>
#include <ctime>

using namespace std;
class Vijand;
class VijandFactory
{
public:
	VijandFactory();
	~VijandFactory();

	Vijand * maakVijand(VijandType v, int i);

	//Vijand* maakVijand(VijandType);

	Vijand * maakBaas(Level *);

	int getAttPunten(int, int);


private:
	string monster[14][6];

	unordered_map<VijandType,Vijand> vijanden;
};
