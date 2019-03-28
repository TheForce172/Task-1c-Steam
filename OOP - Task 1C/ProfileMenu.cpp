#include "ProfileMenu.h"



ProfileMenu::ProfileMenu(const std::string& title, Application * app, User* account) : Menu(title, app), account(account)
{
	for (int i = 0; i < account->getLibary().length(); i++) {
		games.addAtEnd(account->getLibary()[i]->getGame());
	}
	Paint(); // required in constructor

}


ProfileMenu::~ProfileMenu()
{
}
