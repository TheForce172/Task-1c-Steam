#include "ProfileMenu.h"



ProfileMenu::ProfileMenu(const std::string& title, Application * app, User* account) : Menu(title, app), account(account), sortName(true)
{
	if (!(typeid(*account) == typeid(User))) {
		for (int i = 0; i < dynamic_cast<Player*>(account)->getLibary().size(); i++) {
			games.push_back(dynamic_cast<Player*>(account)->getLibary()[i]);
		}
	}
	Paint();

}

bool dateSort(LibraryItem* a, LibraryItem* b) {
	return (a->getCreated() < b->getCreated());
}

bool nameSort(LibraryItem* a, LibraryItem* b) {
	return (a->getGame()->GetName() < b->getGame()->GetName());
}

void ProfileMenu::OutputOptions()
{
	Line("Credits:");
	Option('I', "Purches 1 Credit");
	Option('O', "Purches 10 Credits");
	Option('P', "Purches 1 00 Credits");
	Line();
	Line("GAMES");
	for (int i = 0; i < games.size(); i++) {

		Option(i, games[i]->getGame()->GetName());
	}
	Line();
	if (sortName == true) {
		Option('S', "Sort by date");
	}
	else {
		Option('S', "Sort by name");
	}
	Line();
	if (typeid(*account) == typeid(Admin)) {

		Line("ADMINISTRAOR");
		Option('A', "Add New User");
		Option('R', "Remove User");

	}

}

bool ProfileMenu::HandleChoice(char choice)
{
	switch (choice) {
		case 'A': {
			std::string user = Question("Enter User Name ");
			std::string password = Question("Enter Password");
			Date date;
			app->GetCurrentAccount()->addUser(new Player(user, password, date, 0));
		} break;
		case 'R': {
			RemoveUserMenu("REMOVE USER", app);
		}
		case 'S': {
			if (sortName == true) {
				std::sort(games.begin(), games.end(), dateSort);
				sortName = false;
			}
			else {
				std::sort(games.begin(), games.end(), nameSort);
				sortName = true;
			}
		}
	}
	//TOM YOU NEED TO ADD CREDITS OPTION HANLING HERE
	return false;
}