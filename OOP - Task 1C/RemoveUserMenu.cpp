#include "RemoveUserMenu.h"



RemoveUserMenu::RemoveUserMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void RemoveUserMenu::OutputOptions()
{
	for (int i = 1; i < app->GetCurrentAccount()->getUsers().length; i++) {
	
		Option(i, app->GetCurrentAccount()->getUsers()[i]->GetUsername);

	
	}

}

bool RemoveUserMenu::HandleChoice(char choice)
{
	return false;
}



