#include "ProfileMenu.h"



ProfileMenu::ProfileMenu(const std::string& title, Application * app, User* account) : Menu(title, app), account(account)
{
	if (!(account->getLibary().isEmpty())) {
		for (int i = 0; i < account->getLibary().length(); i++) {
			games.addAtEnd(account->getLibary()[i]->getGame());
		}
	}
	Paint(); 

}

void ProfileMenu::OutputOptions()
{
	Line("Credits:");
	Option('I',"Purches 1 Credit");
	Option('o', "Purches 10 Credits");
	Option('p', "Purches 1 00 Credits");
	Line();
	Line("GAMES");
	for (int i = 0; i < games.length(); i++) {

		Option(i, games[i]->GetName);

	
	
	}


}

bool ProfileMenu::HandleChoice(char choice)
{




	return false;
}
