#include "SearchResultsMenu.h"



SearchResultsMenu::SearchResultsMenu(const std::string& title, Application * app, List<Game*> games) : Menu(title, app)
{
	Paint();
}

void SearchResultsMenu::OutputOptions()
{
	for (int i = 0; i < games.length(); i++)
		Option(i + 1, games[i]->GetName());
}

bool SearchResultsMenu::HandleChoice(char choice)
{
	return false;
}
