#include "MainMenu.h"
#include "ProfileMenu.h"

MainMenu::MainMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); 
}

void MainMenu::OutputOptions()
{
	Option('S', "Browse Store");

	if (app->IsUserLoggedIn())
	{
		Option('P', "View Profile");
		Option('L', "Logout of " + app->GetCurrentUser()->GetUsername());
	}
	else if (app->IsAccountLoggedIn()) {
		Option('L', "Login User");
	}
	else
	{
		Option('L', "Login Account");
	}
}

bool MainMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'S':
	{
		StoreMenu("STORE", app);
	} break;
	case 'L':
	{
		if (app->IsUserLoggedIn())
		{
			std::string answer = Question("Are you sure?");
			if (answer == "y" || answer == "Y")
			{
				app->LogoutUser();
			}
		}
		else if(app->IsAccountLoggedIn())
		{
			// this would need to go to a LoginMenu - similar to StoreMenu
			// instead we just set logged in to true on the main app object
			LoginUserMenu("LOGIN", app);
		}
		else {
			LoginAccountMenu("LOGIN", app);
		}
	} break;
	case 'P':
	{
		if (app->IsUserLoggedIn())
		{
			ProfileMenu(app->GetCurrentUser()->GetUsername()+"'S PFOFILE",app,app->GetCurrentUser());



			// this needs to go to a profile page - similar to StoreMenu
			// notice the if - this only works if somebody is logged in
		}
	} break;
	}

	return false;
}