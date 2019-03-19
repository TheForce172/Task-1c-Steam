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

bool LoginUserMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	return false;
}