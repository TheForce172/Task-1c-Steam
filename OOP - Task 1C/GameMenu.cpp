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
	//TOM HERE YOU NEED TO IMLEMENT THE Purchase OPTIO
	switch (choice)
	{
	case 'P':
	{		
		//check the credits at the same time
		if (app->GetCurrentUser.getCredits >= game->GetCost)		
		{
		//add new library item to current user
			Date date;
			dynamic_cast<Player*>(app->GetCurrentUser).addToLibrary(new LibraryItem(date, game));		
		}                                                                                          
	} break;

	return false;
}