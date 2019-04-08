#include "dislikeMenu.h"








dislikeMenu::dislikeMenu(const std::string & title, Application * app):Menu(title,app)
{
	Paint();
}

void dislikeMenu::OutputOptions()
{
	for (int i = 0; i < games.length(); i++) {
		double time;

		Option(i + 1, games[i]->GetName());
	}

}

bool dislikeMenu::HandleChoice(char choice)
{
	int index = choice - '1';
	if (index >= 0 && index < games.length())
	{
		app->GetCurrentUser()
	}
	return false;
}
