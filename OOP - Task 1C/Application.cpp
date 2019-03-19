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
	// TODO: This currently always logs you in as the first user
	currentUser = currentAccount->getUsers()[0];

	return true;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::addAccount(Account* a) {
	accounts.addAtEnd(a);
}

void Application::addUser(const std::string& accountname, User* u) {
	currentAccount->addUser(u);

}

void Application :: Load(){

}

void Application::Save() {

}