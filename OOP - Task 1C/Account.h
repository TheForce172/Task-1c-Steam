#pragma once

#include <string>
#include "Player.h"
#include "ListT.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const Date&);
		~Account();
		List<User*> getUsers() const;
		void addUser(User*);
		std::string getEmail();
		std::string getPassword();
		const Date& getCreated() const;
	private:
		List<User*> users;
		std::string email;
		std::string password;
		const Date created_; 
};