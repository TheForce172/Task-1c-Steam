#pragma once
#include "Date.h"
#include <string>
#include <vector>
#include "LibraryItem.h"
#include "ListT.h"
class User
{
	public:
		//User(const std::string&, const std::string&, const std::string&, const int&, const Date&);
		User(const std::string & username, const std::string & password, const Date & created, const int & credits);
		virtual ~User();
		const std::string& GetUsername() const;
		const std::string& GetPassword() const;
		const  int GetCredits() const;
		const Date& getCreated() const;
	private:
		std::string username;
		std::string password;
		Date created_;
		int credits;
};