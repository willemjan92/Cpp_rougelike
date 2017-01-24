#include <iostream>
#include "main.h"
#include "stdafx.h"

using namespace std;

Main::Main() {
	correct = false;
	startGame = false;
	runGame = true;
	while (!startGame)
	{
		cout << "Welkom bij deze roguelike!" << endl;
		//cout << "Wil je een [nieuw] spel beginnen, of een spel [laden]" << endl;

		//getline(cin, keuze);

		//if (keuze == "nieuw") {
			while (!correct)
			{
				cout << "Hoeveel lagen moet de kerker worden?" << endl;
				cin >> lagen;
				cin.get();
				cout << "Hoe breedt moet de kerker worden?" << endl;
				cin >> breedte;
				cin.get();
				cout << "Hoe lang moet de kerker worden?" << endl;
				cin >> lengte;
				cin.get();
				cout << "Er zal een kerker gemaakt worden die " << lagen << " lagen is, ";
				cout << breedte << " breed is & " << lengte << " lang is." << endl;
				cout << "Is dit correct? [ja] of [nee]" << endl;

				getline(cin, correctKeuze);
				if (correctKeuze == "ja") {
					cout << "Hoe moet de held heten?" << endl;
					getline(cin, naam);

					dungeon = new Dungeon(lagen, lengte, breedte, naam);
					system("cls");
					run();
					correct = true;
				}
				else
				{
					system("cls");
				}
			}
			startGame = true;

		/*}
		else if (keuze == "laden") {
			cout << "Geef de naam van het bestand in: (opgeslagen in C:\RoguelikeCPP\)" << endl;
		}
		else {
			cout << "geen correcte keuze ingetypt. probeer opnieuw.";
			cin.get();
			system("cls");
		}*/
	}

	//cin.get();
}

void Main::run() 
{
	while (runGame) {
		system("cls");
		string commando;
		string tekst = "Kies een van de volgende commandos: \n";
		tekst += "[ga] {noord, oost, zuid, west, omhoog, omlaag} \n";
		tekst += "[vecht] \n";
		tekst += "[vlucht] \n";
		//tekst += "[pak] item \n";
		tekst += "[bekijk] {kaart, held} \n";
		//tekst += "[gebruik] {item in je rugzak} \n";
		tekst += "[quit] \n";
		tekst += " ------------------------------------------------------------------- \n";
		tekst += "\n";
		cout << tekst;

		cout << dungeon->GetSpeler()->GetHuidigeKamer()->getOmschrijving() << endl;
		if (dungeon->GetSpeler()->GetHuidigeKamer()->heeftVijand() != nullptr) {
			//system("cls");
			cout << "Een " << dungeon->GetSpeler()->GetHuidigeKamer()->heeftVijand()->getOmschrijving() << " blokkeerd de uitgang.." << endl;
		}

		getline(cin, commando);
		if (!commando.empty()) {
			CommandHandler(commando);
		}
	}
}

void Main::CommandHandler(string commando)
{
	istringstream stringStream(commando);
	istream_iterator<string> streamIterator(stringStream), end;
	vector<string> commandArray(streamIterator, end);
	if (commandArray.size() == 1)
	{
		if (commandArray[0] == "ga") {
			cout << "type ook een richting" << endl;
			//cin.get();
		}
		if (commandArray[0] == "vecht") {
			dungeon->GetSpeler()->valAan();
		}
		if (commandArray[0] == "vlucht") {
			if (dungeon->GetSpeler()->GetVorigeKamer() != nullptr)
			{
				dungeon->GetSpeler()->ZetHuidigeKamer(dungeon->GetSpeler()->GetVorigeKamer());
				cout << "Je bent naar de vorige kamer gevlucht!" << endl;
				cin.get();
			}
			else
			{
				cout << "Dit is de aller eerste kamer, je kan niet vluchten!" << endl;
				cin.get();
			}
		}
		/*if (commandArray[0] == "pak") {

		}*/
		if (commandArray[0] == "bekijk") {
			cout << "type ook wat je wilt bekijken" << endl;
			cin.get();
		}
		/*if (commandArray[0] == "gebruik") {
			cout << "type ook wat je wilt gebruiken" << endl;
			cin.get();
		}*/
		if (commandArray[0] == "quit") {
			cout << "weet u het zeker? [ja]/[nee]" << endl;
			string temp;
			getline(cin, temp);
			if (temp == "ja") {
				runGame = false;
			}
		}
		else {
			cout << "commando niet herkend, probeer opnieuw";
		}
	}
	else {
		//cout << commandArray[1];
		if (commandArray[0] == "ga") {
			ga = new GaCommando(commandArray[1], dungeon);
		}
		if (commandArray[0] == "bekijk") {
			if (commandArray[1] == "kaart") {
				zieCommando = new ZieCommando(dungeon);
			}
			/*if (commandArray[1] == "rugzak") {

			}*/
			if (commandArray[1] == "held") {
				zieCommando = new ZieCommando(dungeon->GetSpeler());
			}
		}
	}
}

Main::~Main()
{
	zieCommando = nullptr;
	ga = nullptr;
	dungeon = nullptr;
}
