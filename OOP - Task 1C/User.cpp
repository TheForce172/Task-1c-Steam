#include "User.h"

User::User(const std::string& username, const std::string& password, const Date& created, const int& credits) : username(username), password(password), created_(created), credits(credits)
{
}

User::~User()
{
}

const std::string& User::GetUsername() const
{
	return username;
}

const std::string& User::GetPassword() const {
	return password;
}
const int User:: GetCredits() const {
	return credits;

}

List<LibraryItem*> User::getLibary() const{
	return NULL;
}

const Date& User::getCreated() const {
	return created_;
}