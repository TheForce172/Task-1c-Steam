#include "ProfileMenu.h"



bool dateSort(LibraryItem* a, LibraryItem* b) {
	return (a->getCreated() < b->getCreated());
}

bool nameSort(LibraryItem* a, LibraryItem* b) {
	return (a->getGame()->GetName() < b->getGame()->GetName());
}
ProfileMenu::ProfileMenu(const std::string& title, Application * app, User* account) : Menu(title, app), account(account), sortName(true)
{
	if (!(typeid(*account) == typeid(User))) {
		for (int i = 0; i < dynamic_cast<Player*>(account)->getLibary().size(); i++) {
			games.push_back(dynamic_cast<Player*>(account)->getLibary()[i]);
		}
	}
	std::sort(games.begin(), games.end(), nameSort);
	Paint();
}


void ProfileMenu::OutputOptions()
{
	Line("Credits:" + to_string(app->GetCurrentUser()->GetCredits()));
	Option('I', "Purches 1 Credit");
	Option('O', "Purches 10 Credits");
	Option('P', "Purches 100 Credits");
	Line();
	Line("GAMES");
	for (int i = 0; i < games.size(); i++) {
		double time;

		string played;
		if (games[i]->getTime() < 60) {
			time = games[i]->getTime() / 1.0f;
			played = to_string(time) + "Mins";
		}
		else if (games[i]->getTime() > 60 && games[i]->getTime() < 300) {
			time = (games[i]->getTime() / 60) /1.0f;
			played = to_string(time) + "Hrs";
		}
		else {
			time = (games[i]->getTime() / 60) / 1.0f;
			round(time);
			played = to_string(time) + "Hrs";
		}
		Option(i + 1, games[i]->getGame()->GetName() + " (" + played + ") ");
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
		} break;
		case 'I': {
			app->GetCurrentUser()->AddCredits(1);
		}break;
		case 'O': {
			app->GetCurrentUser()->AddCredits(10);
		}	break;
		case 'P': {
			app->GetCurrentUser()->AddCredits(100);
		}break;
	}
	int index = choice - '1';
	if (index >= 0 && index < games.size())
	{
		//Question("Not implemented, press return to continue (");
		// go to game detail page
		games[index]->addTime();
	}
	return false;
}