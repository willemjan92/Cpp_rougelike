#include "GaCommando.h"

GaCommando::GaCommando()
{
}
GaCommando::GaCommando(string richting, Dungeon* dungeon)
{
	richtingMap = unordered_map<string, Richting>({ { "noord", Richting::Noord },{ "oost", Richting::Oost },{ "zuid", Richting::Zuid },{ "west", Richting::West },{ "omhoog", Richting::Omhoog },{ "omlaag", Richting::Omlaag } });

	Kamer* huidigeKamer = dungeon->GetSpeler()->GetHuidigeKamer();
	if (CheckDirection(richting)) {
		if (huidigeKamer->GetBuurKamer(richtingMap.at(richting)) != nullptr)
		{
			if (huidigeKamer->heeftVijand() == nullptr) {
				dungeon->GetSpeler()->ZetHuidigeKamer(huidigeKamer->GetBuurKamer(richtingMap.at(richting)));
			}
			else {
				cout << "een vijand blokeerd de uitgang, versla deze eerst voordat je verder kan!";
				cin.get();
			}
		}
		else {
			cout << "Je kan deze kant niet op..." << endl;
			cin.get();
		}
	}
	else {
		cout << "Geen geldige richting gegeven... " << endl;
		cin.get();
	}

}

bool GaCommando::CheckDirection(string richting) {
	for (const auto& tempRichting : richtingMap) {
		if (tempRichting.first == richting) {
			return true;
		}
	}
	return false;
}
GaCommando::~GaCommando()
{
}