#include "User.h"

User::User(const std::string& username, const std::string& password, const std::string& created, const int& credits) : username(username), password(password), created(created), credits(credits)
{
}

User::~User()
{
}

const std::string& User::GetUsername() const
{
	return username;
}