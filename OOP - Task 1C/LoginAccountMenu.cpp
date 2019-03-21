#include "LoginAccountMenu.h"



LoginAccountMenu::LoginAccountMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void LoginAccountMenu::OutputOptions()
{
	for (int i = 0; i < app->getAccounts().length(); i++)
	{
		Option(i + 1, app->getAccounts()[i]->getEmail());
	}
}

bool LoginAccountMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';
	bool login(false);
	do {
		if (index >= 0 && index < app->getAccounts().length()) // TODO: Hardcoded, change when using List<T>
		{
			std::string email = app->getAccounts()[index]->getEmail();
			//std::cout << "  Enter password for " << username << ": ";
			if (app->LoginAccount(email, Question("Enter password for " + email + ": ")))
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
