#include "RemoveUserMenu.h"



RemoveUserMenu::RemoveUserMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void RemoveUserMenu::OutputOptions()
{
	for (int i = 1; i < app->GetCurrentAccount()->getUsers().length(); i++) {
	
		Option(i, app->GetCurrentAccount()->getUsers()[i]->GetUsername());

	
	}

}

bool RemoveUserMenu::HandleChoice(char choice)
{		
	
	int index = (choice - '1') + 1;
	if (index >= 0 && index < app->GetCurrentAccount()->getUsers().length()) {
	
		app->GetCurrentAccount()->removeUser(app->GetCurrentAccount()->getUsers()[index]);
		return true;
	}

	return false;
}



