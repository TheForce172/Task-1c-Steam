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
	bool login(false);
	do {
		if (index >= 0 && index < app->GetCurrentAccount()->getUsers().length()) // TODO: Hardcoded, change when using List<T>
		{
			std::string username = app->GetCurrentAccount()->getUsers()[index]->GetUsername();
			//std::cout << "  Enter password for " << username << ": ";
			if (app->LoginUser(username, Question("Enter password for " + username + ": ")))
			{
				login = true;
			}
			else {

				Line("Incorrect Password");
				return false;
			}
		}
	} while (!login);

	return true;
}