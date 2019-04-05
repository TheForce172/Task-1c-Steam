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
	Load.open("data.txt", std::ios::in);
	if (Load.fail()) std::cout << "\n Error Loading.";
	else {
		Account* currentload = nullptr;
		Player* currentUser = nullptr;
		bool hasAdmin;
		for (std::string line; getline(Load, line); ){
			std::istringstream iss(line);
			if (line == "GAME") {
				std::string name;
				std::string description;
				std::string cost;
				std::string ageRating;
				std::string ID;
				getline(Load, ID);
				getline(Load, name);
				getline(Load, description);
				getline(Load, cost);
				getline(Load, ageRating);
				store.addGame(new Game(name, description, stoi(cost), stoi(ageRating)));
			}
			else if (line == "ACCOUNT") {
				std::string email;
				std::string password;
				std::string created;
				getline(Load, created);
				getline(Load, email);
				getline(Load, password);
				Date date;
				date = created;
				currentload = new Account(email, password, date);
				addAccount(currentload);
				hasAdmin = false;
				currentUser = nullptr;
			}
			else if (line == "ACCOUNT-USER") {
				std::string username;
				std::string password;
				std::string created;
				std::string credit;
				getline(Load, created);
				getline(Load, username);
				getline(Load, password);
				getline(Load, credit);
				Date date;
				date = created;
				if (hasAdmin == false) {

					currentUser = new Admin(username, password, date, stoi(credit));
					hasAdmin = true;

				}
				else {
					currentUser = new Player(username, password, date, stoi(credit));
				}

				currentload->addUser(currentUser);
			}
			else if (line == "ACCOUNT-USER-GAME") {
				std::string gameID;
				std::string date;
				std::string time;
				getline(Load, gameID);
				getline(Load, date);
				getline(Load, time);
				currentUser->addToLibrary(new LibraryItem(date, store.getGames()[stoi(gameID)], stoi(time)));

			}
		}

	}
}
void Application::Save() {

	std::ofstream Save;
	Save.open("data.txt", std::ios::out);
	if (Save.fail())std::cout << "\n Error saving.";
	else {
		for (int i = 0; i < store.getGames().length(); i++) {
			Save << "GAME" << "\n";
			Save << i << "\n";
			Save << store.getGames()[i]->GetName() << "\n";
			Save << store.getGames()[i]->GetDescription() << "\n";
			Save << store.getGames()[i]->GetCost() << "\n";
			Save << store.getGames()[i]->GetageRating() << "\n";

		}
		for (int i = 0; i < accounts.length(); i++) {
			Save << "ACCOUNT" << "\n";
			Save << accounts[i]->getCreated() << "\n";
			Save << accounts[i]->getEmail() << "\n";
			Save << accounts[i]->getPassword() << "\n";

			for (int j = 0; j < accounts[i]->getUsers().length(); j++) {
				Save << "ACCOUNT-USER" << "\n";
				Save << accounts[i]->getUsers()[j]->GetUsername() << "\n";
				Save << accounts[i]->getUsers()[j]->GetPassword() << "\n";
				Save << accounts[i]->getUsers()[j]->GetCredits() << "\n";
				Player* user = dynamic_cast<Player*>(accounts[i]->getUsers()[j]);
				if (user)
				for (int k = 0; k < user->getLibary().length(); k++) {
					Save << "ACCOUNT-USER-GAME" << "\n";
					List<Game*> temp = store.getGames();
					for (int l = 0; l < temp.length(); l++) {
						if (temp[l]->GetName() == user->getLibary()[k]->getGame()->GetName()) {
							Save << l << "\n";
						}
					}
					Save << user->getLibary()[k]->getCreated() << "\n";
					Save << user->getLibary()[k]->getTime()<< "\n";
				}
			}
		}
	}

	Save.close();

}