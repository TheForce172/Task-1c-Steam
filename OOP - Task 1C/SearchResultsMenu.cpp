#include "SearchResultsMenu.h"
#include "StoreMenu.h"


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
	List<Game*> return_List;
	List<Game*> tempSearch = Store.getGames();
	switch (choice)
	{
	case 'N':
	{
		string ans = Question("Enter name to search for");
		for (int count = 0; count < Store.getGames().length(); count++)
		{
			if (Store.Search(tempSearch.first()->GetName(), ans))
			{
				return_List.addAtEnd(tempSearch.first());
			}
			tempSearch.deleteFirst();
		}
		StoreMenu("Results", app, return_List);
		break;
	}
	case'C':
	{
		string ans = Question("Enter a price range to search for (e.g 1-10)");
		for (int count = 0; count < Store.getGames().length(); count++)
		{
			if (Store.SearchPrice(tempSearch, first()->GetCost(), ans))
			{
				return_List.addAtEnd(tempSearch.first());
			}
			tempSearch.deleteFirst();
		}
		StoreMenu("Results", app, return_List);
		break;
	}
}
