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

		Option(i, games[i]->GetName());
	}
	if (typeid(account).name() == "Admin") {

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
		
	         }

	}



	return false;
}
