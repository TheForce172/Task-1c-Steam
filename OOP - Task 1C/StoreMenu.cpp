#include "StoreMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application * app) : Menu(title, app)
{
	games = app->GetStore().getGames();
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	for (int i = 0; i < games.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, games[i]->GetName());
	}
}

void StoreMenu::showSearchMenu() const
{
	cout << "Search Menu";
	cout << " 0           Search By Name /n";
	cout << " 1           Search By Cost /n";
	cout << " 2           Search By AgeRating/n";
	cout << " 3           Exit search menu";

}
/*
int StoreMenu::readInSearchOption() const
{
	return Option();
}*/
 
bool StoreMenu::HandleChoice(char choice)
{
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