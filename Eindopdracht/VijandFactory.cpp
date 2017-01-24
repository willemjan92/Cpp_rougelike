#include "VijandFactory.h"
#include "Vijand.h"

VijandFactory::VijandFactory()
{
	ifstream file;
	int x = 0;
	string path = "D:\\2. Avans\\C++ 1\\Eindopdracht\\monsters.txt";
	file.open(path);
	string temp = "";
	while (getline(file, temp))
	{
		//monster.clear();
		stringstream tempStream;
		tempStream << temp;
		//cout << temp << endl;
		string temp2 = "";
		int i = 0;
		while (getline(tempStream, temp2, ';'))
		{
			monster[x][i] = temp2;
			i++;
			//monster[x].push_back(temp2);
		}
		x++;
		//cout << monster[0] << endl;
		//Vijand* vijand = new Vijand();

	}


	vijanden = std::unordered_map<VijandType, Vijand>{
		{ VijandType::Vijand, Vijand() }
	};
}


VijandFactory::~VijandFactory()
{
}

Vijand* VijandFactory::maakVijand(VijandType v, int i)
{
	Vijand* vijand = vijanden.at(v).maakVijand();
	/*for (int i = 0; i < 10; i++)
	{*/
		if (monster[i][1] != "BAAS") {
			string naam = monster[i][0];
			int lvl;
			lvl = stoi(monster[i][1]);

			int hp = stoi(monster[i][2]);
			stringstream tempStream;
			tempStream << monster[i][3];
			string attack = "";
			int attPoints[2];
			int j = 0;
			while (getline(tempStream, attack, '-'))
			{
				attPoints[j] = stoi(attack);
				j++;
			}
			int att = getAttPunten(attPoints[0], attPoints[1]);
			int def = stoi(monster[i][4]);
			int exp = stoi(monster[i][5]);
			vijand->InitialiseerVijand(naam, lvl, hp, att, def, exp);

			return vijand;
		}
		return vijand;
	//}
	//if (monster[1] != "BAAS") {
	
	//}
//		return vijand;
}

Vijand* VijandFactory::maakBaas(Level* level) {

	Vijand* vijand = new Vijand();
	for (int i = 0; i < 10; i++)
	{
		if (monster[i][1] == "BAAS") {
			string naam = monster[i][0];
			int lvl;
			lvl = stoi(monster[i][1]);

			int hp = stoi(monster[i][2]);
			stringstream tempStream;
			tempStream << monster[i][3];
			string attack = "";
			int attPoints[2];
			int j = 0;
			while (getline(tempStream, attack, '-'))
			{
				attPoints[j] = stoi(attack);
			}
			int att = getAttPunten(attPoints[0], attPoints[1]);
			int def = stoi(monster[i][4]);
			int exp = stoi(monster[i][5]);
			vijand->InitialiseerVijand(naam, lvl, hp, att, def, exp);

			return vijand;
		}
		return vijand;
	}
	
	
	/*Vijand* vijand = new Vijand();
	for (int i = 0; i < monster.size(); i++)
	{
		if (monster[1] == "BAAS") {
			string naam = monster[0];
			int lvl;
			lvl = stoi(monster[1]);

			int hp = stoi(monster[2]);
			stringstream tempStream;
			tempStream << monster[3];
			string attack = "";
			int attPoints[2];
			int i = 0;
			while (getline(tempStream, attack, '-'))
			{
				attPoints[i] = stoi(attack);
			}
			int att = getAttPunten(attPoints[0], attPoints[1]);
			int def = stoi(monster[4]);
			int exp = stoi(monster[5]);
			vijand->InitialiseerVijand(naam, lvl, hp, att, def, exp);
		}
	}
	
	return vijand;*/

}

int VijandFactory::getAttPunten(int min, int max)
{
	std::default_random_engine generator;
	generator.seed(time(0));

	std::uniform_int_distribution<int> distribution1(min, max);
	return distribution1(generator);
	//return 0;
}
