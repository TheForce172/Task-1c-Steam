#include "RemoveUserMenu.h"



RemoveUserMenu::RemoveUserMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void RemoveUserMenu::OutputOptions()
{
}

bool RemoveUserMenu::HandleChoice(char choice)
{
	return false;
}



