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
		return_List = app->GetStore().SearchName(ans);
		SearchResultsMenu("Results", app, return_List);
		break;
	}

	case'P':
	{
		string ans = Question("Enter a price range to search for (e.g 5-10)");
		std::istringstream ss(ans);
		int to, from;
		char a;
		ss >> from >> a >> to;
		return_List = app->GetStore().SearchPrice(to, from);
		SearchResultsMenu("Results", app, return_List);
		break;
	}

	case'R':
	{
		string ans = Question("Search by age rating");
		std::istringstream ss(ans);
		int to, from;
		char a;
		ss >> to >> a >> from;
		return_List = app->GetStore().SearchageRating(to, from);
		SearchResultsMenu("Results", app, return_List);
		break;
	}


	}

	return false;
}

