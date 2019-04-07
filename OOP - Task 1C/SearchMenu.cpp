#include "SearchMenu.h"



SearchMenu::SearchMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void SearchMenu::OutputOptions()
{
	Line("SEARCHING " + std::to_string(app->GetStore().getGames().length()) + " GAMES");
	Option('N', "Search By name");
	Option('P', "Search By price");
	Option('R', "Search By rating");
}
bool SearchMenu::HandleChoice(char choice)
{
	return false;
}

