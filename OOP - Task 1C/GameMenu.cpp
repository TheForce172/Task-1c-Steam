#include "GameMenu.h"



GameMenu::GameMenu(const std::string& title, Application * app, Game * game): game(game), Menu(title, app)
{
	for (int i = 0; i < dynamic_cast<Player*>(app->GetCurrentUser())->getLibary().size(); i++) {
		if (dynamic_cast<Player*>(app->GetCurrentUser())->getLibary()[i]->getGame() == game) {
			owned = true;
		}
	}
	Paint();
}

void GameMenu::OutputOptions()
{
	Line(game->GetDescription());
	if (app->IsUserLoggedIn() && owned == false) {
		
		Option('P', "Purchase for " + std::to_string(game->GetCost() / 100.0f));
	}
	else {
		Line("GAME IS OWNED");
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
		if (app->GetCurrentUser()->GetCredits() >= game->GetCost())
		{
			//add new library item to current user
			Date date;
			dynamic_cast<Player*>(app->GetCurrentUser())->addToLibrary(new LibraryItem(date, game));
		}
	} break;
	}

	return false;
}