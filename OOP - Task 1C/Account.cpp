#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const Date& created) : email(email), password(password), created_(created)
{
}

Account::~Account()
{
	for (int i = 0; i < 3; ++i)
	{
		delete users[i];
	}
}

List<User*> Account::getUsers() const
{
	return users;
}

void Account::addUser(User* u) {
	users.addAtEnd(u);
}

std::string Account::getEmail() {
	return email;
}

std::string Account::getPassword() {
	return password;
}
const Date& Account::getCreated() const {
	return created_;
}