#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void LoginUserMenu::OutputOptions()
{
	for (int i = 0; i < app->GetCurrentAccount()->getUsers().length(); i++)
	{
		Option(i + 1, app->GetCurrentAccount()->getUsers()[i]->GetUsername());
	}
}