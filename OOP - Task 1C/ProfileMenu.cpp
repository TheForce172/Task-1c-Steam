#include "ProfileMenu.h"



ProfileMenu::ProfileMenu(const std::string& title, Application * app, User* account) : Menu(title, app), account(account)
{
	if (!(typeid(*account) == typeid(User))) {
		for (int i = 0; i < dynamic_cast<Player*>(account)->getLibary().size(); i++) {
			games.addAtEnd(dynamic_cast<Player*>(account)->getLibary()[i]->getGame());
		}
	}
	Paint(); 

}

void ProfileMenu::OutputOptions()
{
	Line("Credits:");
	Option('I',"Purches 1 Credit");
	Option('O', "Purches 10 Credits");
	Option('P', "Purches 1 00 Credits");
	Line();
	Line("GAMES");
	for (int i = 0; i < games.length(); i++) {

		Option(i, games[i]->GetName());
	}
	Line();
	if (typeid(*account) == typeid(Admin)) {

		Line("ADMINISTAOR");
		Option('A', "Add New User");
		Option('R', "Remove User");

	}

}

bool ProfileMenu::HandleChoice(char choice)
{
	switch (choice) {
	
	
	case 'A': {

		
		std::string user = Question(" Enter User Name ");
		std::string password = Question("Enter Password");
		Date date;
		app->GetCurrentAccount()->addUser( new Player(user,password,date,0));
		
	} break;

	case 'R': {

		RemoveUserMenu("REMOVE USER",app);
		
	
	}

	}



	return false;
}
