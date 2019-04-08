#include "StoreMenu.h"
#include"SearchMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application * app) : Menu(title, app)
{
	games = app->GetStore().getGames();
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	if (isSearching() == true) {

	}
	else {
		for (int i = 0; i < games.length(); i++)
		{
			// adding 1 so the display is nicer for the user
			Option(i + 1, games[i]->GetName());
		}

		Option('S', "Search");
	}

}


bool StoreMenu::HandleChoice(char choice)
{
	if (choice == 'S') {
		SearchMenu("SEARCH MENU", app, app->GetStore().getGames());
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

bool StoreMenu::isSearching()
{
	return false;
}
