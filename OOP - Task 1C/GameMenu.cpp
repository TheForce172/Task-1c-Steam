#include "GameMenu.h"



GameMenu::GameMenu(const std::string& title, Application * app, Game * game): game(game), Menu(title, app)
{
	Paint();
}

void GameMenu::OutputOptions()
{
	Line(game->GetDescription());
	if (app->IsUserLoggedIn()) {
		Option('P', "Purchase for " + std::to_string(game->GetCost() / 100.0f));
	}
}

bool GameMenu::HandleChoice(char choice)
{	
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	//int index = choice - '1';
	//if (index >= 0 && index < games.length())
	//{
	//	//----///Question("Not implemented, press return to continue (");
	//	// go to game detail page
	//	GameMenu(Utils::toUpperA(games[index]->GetName()), app, games[index]);
	//}

	return false;
}