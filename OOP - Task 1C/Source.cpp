#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"

// TODO: Remove from global scope once menu system is integrated
Application app;

void createHardcodedTestData()
{
	// Setup store with some games
	app.GetStore().getGames().addAtEnd(new Game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5));
	app.GetStore().getGames().addAtEnd(new Game("Braid", "A time twisting puzzle game.", 499, 15));
	app.GetStore().getGames().addAtEnd(new Game("Factorio", "Build a complicated factory in space.", 1599, 12));
	app.GetStore().getGames().addAtEnd(new Game("LIMBO", "Watch out for that spider.", 299, 12));
	app.GetStore().getGames().addAtEnd(new Game("INSIDE", "What are those scientists even doing?!", 1299, 15));
	app.GetStore().getGames().addAtEnd(new Game("Portal 2", "Play around with physics. Shoot the moon.", 1999, 15));
	app.GetStore().getGames().addAtEnd(new Game("Half Life 3", "It's never coming out.", 5999, 18));
	app.GetStore().getGames().addAtEnd(new Game("Castle Crashers", "A small giraffe follows you around.", 999, 18));
	app.GetStore().getGames().addAtEnd(new Game("Brothers", "Split your brain into two thumbs.", 799, 15));

	// Create some users
	Player* u1 = new Admin("Alice", "password", "2018-06-16");
	Player* u2 = new Player("Bob", "password", "2018-09-19");
	Player* u3 = new Player("Charlie", "password", "2018-09-24");

	// With some games in their library
	u1->getLibary().addAtEnd(new LibraryItem("2018-06-17", app.GetStore().getGames()[0]));
	u1->getLibary().addAtEnd(new LibraryItem("2018-06-18", app.GetStore().getGames()[1]));
	u2->getLibary().addAtEnd(new LibraryItem("2018-09-19", app.GetStore().getGames()[2]));
	u2->getLibary().addAtEnd(new LibraryItem("2018-09-19", app.GetStore().getGames()[3]));
	u3->getLibary().addAtEnd(new LibraryItem("2018-09-24", app.GetStore().getGames()[3]));
	u3->getLibary().addAtEnd(new LibraryItem("2018-09-30", app.GetStore().getGames()[6]));

	// Make an account and attach the users
	Account* a = new Account("alice@shu.com", "password", "2018-06-16");
	app.addAccount(a);
	app.addUser("alice@shu.com", u1);
	app.addUser("alice@shu.com", u2);
	app.addUser("alice@shu.com", u3);

	// TODO: We need a login menu for accounts, for now we log in the only account
	app.LoginAccount("alice@shu.ac.uk", "password");
}

char showMainMenuAndGetUserChoice()
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= GAME LIBRARY =-\n";
	std::cout << "                    \n";
	std::cout << "  S) Browse Store   \n";

	if (app.IsUserLoggedIn())
	{
		std::cout << "  L) Logout of " << app.GetCurrentUser()->GetUsername() << "\n";
		// TODO: User profile option
	}
	else
	{
		std::cout << "  L) Login      \n";
	}

	std::cout << "                    \n";
	std::cout << "  B) Exit           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return Utils::getCharFromUser();
}

char showStoreMenuAndGetUserChoice()
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= STORE =-       \n";
	std::cout << "                    \n";

	// Output game list
	for (int i = 0; i < 9; i++) // TODO: Hardcoded, change when using List<T>
	{
		std::cout << "  " << (i + 1) << ") " << app.GetStore().getGames()[i]->GetName() << "\n";
	}

	// TODO: Implement search store option

	// Output rest of menu
	std::cout << "                    \n";
	std::cout << "  B) Back           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return Utils::getCharFromUser();
}

char showLoginUserMenuAndGetUserChoice(Account *account)
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= LOGIN =-       \n";
	std::cout << "                    \n";

	// Output user list
	for (int i = 0; i < 3; i++) // TODO: Hardcoded, change when using List<T>
	{
		std::cout << "  " << (i + 1) << ") " << account->getUsers()[i]->GetUsername() << "\n";
	}

	// Output rest of menu
	std::cout << "                    \n";
	std::cout << "  B) Back           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return Utils::getCharFromUser();
}

char showGameMenuAndGetUserChoice(Game* game)
{
	system("CLS");
	std::cout << "                                  \n";
	std::cout << "  -= " << game->GetName() << " =- \n";
	std::cout << "                                  \n";
	std::cout << "  " << game->GetDescription() << "\n";
	std::cout << "                                  \n";

	if (app.IsUserLoggedIn())
	{
		std::cout << "  P) Purchase for " << (game->GetCost() / 100.0f) << "\n";
		std::cout << "                                                      \n";
	}

	std::cout << "  B) Back                   \n";
	std::cout << "                            \n";
	std::cout << "                            \n";
	std::cout << "  >>> ";

	return Utils::getCharFromUser();
}

void gameMenu(Game* game)
{
	bool readyToGoBack = false;

	while (readyToGoBack == false)
	{
		int choice = showGameMenuAndGetUserChoice(game);

		switch (choice)
		{
			case 'P': {
				if (app.IsUserLoggedIn())
				{
					// TODO: Implement buying from the store
				}
			} break;
			case 'B': {
				readyToGoBack = true;
			} break;
		}
	}
}

void storeMenu()
{
	bool readyToGoBack = false;

	while (readyToGoBack == false)
	{
		int choice = showStoreMenuAndGetUserChoice();

		switch (choice)
		{
			case 'B': {
				readyToGoBack = true;
			} break;
			default: {
				int index = choice - '1';

				if (index >= 0 && index < 9) // TODO: Hardcoded, change when using List<T>
				{
					gameMenu(app.GetStore().getGames()[index]);
				}
			} break;
		}
	}
}

void loginUserMenu()
{
	bool readyToGoBack = false;

	while (readyToGoBack == false)
	{
		int choice = showLoginUserMenuAndGetUserChoice(app.GetCurrentAccount());

		switch (choice)
		{
			case 'B': {
				readyToGoBack = true;
			} break;
			default: {
				int index = choice - '1';

				if (index >= 0 && index < 3) // TODO: Hardcoded, change when using List<T>
				{
					std::string username = app.GetCurrentAccount()->getUsers()[index]->GetUsername();

					std::cout << "  Enter password for " << username << ": ";
					if (app.LoginUser(username, Utils::getLineFromUser()))
					{
						readyToGoBack = true;
					}
				}
			} break;
		}
	}
}

void mainMenu()
{
	bool wantsToExit = false;

	while (wantsToExit == false)
	{
		int choice = showMainMenuAndGetUserChoice();

		switch (choice)
		{
			case 'S': {
				storeMenu();
			} break;
			case 'L': {
				if (app.IsUserLoggedIn())
				{
					app.LogoutUser();
				}
				else
				{
					loginUserMenu();
				}
			} break;
			case 'B': {
				wantsToExit = true;
			} break;
		}
	}
}

void main()
{
	// TODO: Remove call to dummy data, instead use Load and Save
	createHardcodedTestData();

	// TODO: app.Load();
	mainMenu();
	// TODO: app.Save();
}