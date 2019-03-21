#include "Application.h"


Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
}

bool Application::IsUserLoggedIn() const
{
	return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
	return currentAccount;
}

User* Application::GetCurrentUser() const
{
	return currentUser;
}

Store& Application::GetStore()
{
	return store;
}

bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	for (int i = 0; i < accounts.length(); i++) {
		if (email == accounts[i]->getEmail() && password == accounts[i]->getPassword()) {
			currentAccount = accounts[i];
			return true;
		}
	}
	return false;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	for (int i = 0; i < currentAccount->getUsers().length(); i++) {
		if (username == currentAccount->getUsers()[i]->GetUsername() && password == currentAccount->getUsers()[i]->GetPassword()) {
			currentUser = currentAccount->getUsers()[i];
			return true;
		}
	}
	return false;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::addAccount(Account* a) {
	accounts.addAtEnd(a);
}

List<Account*> Application::getAccounts() {
	return accounts;
}

void Application::Load() {


	std::ifstream Load;
	Load.open("Game.txt", std::ios::in);
	if (Load.fail()) std::cout << "\n Error Loading.";
	else {
		std::string line;
		Account* currentload = nullptr;
		Player* currentUser = nullptr;
		bool hasAdmin;
		while (Load >> line) {
			if (line == "GAME") {
				std::string name;
				std::string description;
				int cost;
				int ageRating;
				int ID;
				Load >> ID;
				Load >> name;
				Load >> description;
				Load >> cost;
				Load >> ageRating;
				store.addGame(new Game(name, description, cost, ageRating));
			}
			else if (line == "ACCOUNT") {
				std::string email;
				std::string password;
				std::string created;
				Load >> created;
				Load >> email;
				Load >> password;
				currentload = new Account(email, password, created);
				addAccount(currentload);
				hasAdmin = false;
				currentUser = nullptr;
			}
			else if (line == "ACCOUNT-USER") {
				std::string username;
				std::string password;
				std::string created;
				int credit;
				Load >> created;
				Load >> username;
				Load >> password;
				Load >> credit;
				if (hasAdmin = false) {

					currentUser = new Admin(username, password, created, credit);

				}
				else {
					currentUser = new Player(username, password, created, credit);
				}

				currentload->addUser(currentUser);
			}
			else if (line == "ACCOUNT-USER-GAME") {
				int gameID;
				std::string date;
				int time;
				Load >> gameID;
				Load >> date;
				Load >> time;
				currentUser->getLibary().addAtEnd(new LibraryItem(date, store.getGames()[gameID], time));

			}
		}

	}
}
void Application::Save() {

	std::ofstream Save;
	Save.open("Game.txt", std::ios::out);
	if (Save.fail())std::cout << "\n Error saving.";
	else {
		for (int i = 0; i < store.getGames().length(); i++) {
			Save << "GAME";
			Save << i;
			Save << store.getGames()[i]->GetName();
			Save << store.getGames()[i]->GetDescription();
			Save << store.getGames()[i]->GetCost();
			Save << store.getGames()[i]->GetageRating();

		}for (int i = 0; i < accounts.length(); i++) {
			Save << "ACCOUNT";
			Save << accounts[i]->getCreated();
			Save << accounts[i]->getEmail();
			Save << accounts[i]->getPassword();

			for (int j = 0; j < accounts[i]->getUsers().length(); j++) {
				Save << "ACCOUNT-USER";
				Save << accounts[i]->getUsers()[j]->GetUsername();
				Save << accounts[i]->getUsers()[j]->GetPassword();
				Save << accounts[i]->getUsers()[j]->GetCredits();
				Player* user = dynamic_cast<Player *>(accounts[i]->getUsers()[j]);
				for (int k = 0; k < user->getLibary().length(); k++) {
					Save << "ACCOUNT-USER-GAME";
					List<Game*> temp = store.getGames();
					for (int l = 0; l < temp.length(); l++) {
						if (temp[i]->GetName() == user->getLibary()[k]->getGame()->GetName()) {
							Save << l;
						}
					}
					Save << user->getLibary()[k]->getCreated();
					Save << user->getLibary()[k]->getTime();
				}
			}
		}
	}

	Save.close();

}