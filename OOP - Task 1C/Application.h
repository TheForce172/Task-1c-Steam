#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"
#include "ListT.h"
#include <iostream>
#include <sstream>
#include <fstream>
class Application
{
	public:
		Application();
		~Application();

		bool IsAccountLoggedIn() const;
		bool IsUserLoggedIn() const;
		Account* GetCurrentAccount() const;
		User* GetCurrentUser() const;

		Store& GetStore();

		bool LoginAccount(const std::string& email, const std::string& password);
		bool LoginUser(const std::string& username, const std::string& password);
		void LogoutUser();
		void addAccount(Account*);
		void Save();
		void Load(); 
		void addUser(const std::string&, User*);
	private:
		List<Account*>  accounts;
		Store store;
		Account* currentAccount;
		User* currentUser;
		
};