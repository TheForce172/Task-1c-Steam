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
	List<Game*> return_List;
	List<Game*> tempSearch = app->GetStore().getGames();
	switch (choice)
	{
	case 'N':
	{
		string ans = Question("Enter name to search for");
		for (int count = 0; count < app->GetStore().getGames().length(); count++)
		{
			if (app->GetStore().Search(tempSearch.first()->GetName(), ans))
			{
				return_List.addAtEnd(tempSearch.first());
			}
			tempSearch.deleteFirst();
		}
		SearchResultsMenu("Results", app, return_List);
		break;
	}
	case'C':
	{
		string ans = Question("Enter a price range to search for (e.g 1-10)");
		for (int count = 0; count < app->GetStore().getGames().length(); count++)
		{
			if (app->GetStore().SearchPrice(tempSearch.first()->GetCost(), ans))
			{
				return_List.addAtEnd(tempSearch.first());
			}
			tempSearch.deleteFirst();
		}
		SearchResultsMenu("Results", app, return_List);
		break;
	}
	}
}
