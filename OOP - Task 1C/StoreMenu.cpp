#include "StoreMenu.h"
#include"SearchMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application * app) : Menu(title, app)
{
	games = app->GetStore().getGames();
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	for (int i = 0; i < games.length(); i++)
		{
		double total = 0;
		double likes = 0;
		double dislikes = 0;
		for (int j = 0; j < app->getAccounts().length(); j++) {
			for (int k = 0; k < app->getAccounts()[j]->getUsers().length(); k++) {
				for (int l = 0; l < dynamic_cast<Player*>(app->getAccounts()[j]->getUsers()[k])->getlikes().length(); l++) {
					if (dynamic_cast<Player*>(app->getAccounts()[j]->getUsers()[k])->getlikes()[l] == games[i]) {
						total++;
						likes++;
					}
				}
				for (int l = 0; l < dynamic_cast<Player*>(app->getAccounts()[j]->getUsers()[k])->getdislikes().length(); l++) {
					if (dynamic_cast<Player*>(app->getAccounts()[j]->getUsers()[k])->getdislikes()[l] == games[i]) {
						total++;
						dislikes++;
					}
				}
			}
		}
		double averagel;
		if (likes != 0 && total != 0) {
			averagel = (likes / total) * 100;
		}else if(dislikes != 0 && total != 0) {
			averagel = -((dislikes/ total) * 100);
		}
		else {
			averagel = 0;
		}
			// adding 1 so the display is nicer for the user
			Option(i + 1, games[i]->GetName() + " - " + Utils::decimalLength(averagel, 6) + "%");
		}

		Option('S', "Search");
}




bool StoreMenu::HandleChoice(char choice)
{
	if (choice == 'S') {
		SearchMenu("SEARCH MENU", app);
	}
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';
	if (index >= 0 && index < games.length())
	{
		//Question("Not implemented, press return to continue (");
		// go to game detail page
		GameMenu(Utils::toUpperB(games[index]->GetName()), app,games[index]);
	}
	return false;

}

