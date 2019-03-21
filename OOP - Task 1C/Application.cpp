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
	currentAccount = accounts.first();

	return true;
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

void Application::Load() {


	std::ifstream Load;
	Load.open("Game.txt", std::ios::in);
	if (Load.fail()) std::cout << "\n Error Loading .";
	else {
		std::string line;
		Account* currentload = nullptr;
		User* currentUser = nullptr;
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
			else if(line == "ACCOUNT") {
					std::string email;
					std::string password;
					std::string created;
					Load >> created; 
					Load >> email;
					Load >> password;
					currentload = new Account(email, password, created);
					addAccount(currentload);			
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
					currentUser = new User(username, password, created, credit);
					currentload->addUser(currentUser);
			}
		}

	}
}
void Application::Save(){

}