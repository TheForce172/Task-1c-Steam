#pragma once

#include <string>
#include "Player.h"
#include "ListT.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const std::string&);
		~Account();
		const List<User*> getUsers() const;
		void addUser(User*);
		std::string getEmail();
		std::string getPassword();
		std::string getCreated();
	private:
		List<User*> users;
		std::string email;
		std::string password;
		std::string created;    // TODO: replace with custom Date class, currently YYYY-MM-DD
};