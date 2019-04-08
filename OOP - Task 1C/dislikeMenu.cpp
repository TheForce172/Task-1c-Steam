#include "dislikeMenu.h"








dislikeMenu::dislikeMenu(const std::string & title, Application * app, List<Game*> games):Menu(title,app), games(games)
{
	Paint();
}

void dislikeMenu::OutputOptions()
{
	for (int i = 0; i < games.length(); i++) {

		Option(i + 1, games[i]->GetName());
	}

}

bool dislikeMenu::HandleChoice(char choice)
{
		int index = choice - '1';
		if (index >= 0 && index < games.length())
		{
			dynamic_cast<Player*>(app->GetCurrentUser())->adddisLike(games[index]);
			return true;

		}
		return false;
}
