#pragma once
#include "Date.h"
#include <string>
#include "LibraryItem.h"
#include "ListT.h"
class User
{
	public:
		User(const std::string&, const std::string&, const std::string&, const int&);
		virtual ~User();
		const std::string& GetUsername() const;
		const std::string& GetPassword() const;
		const  int GetCredits() const;
		virtual List<LibraryItem*> getLibary() const;
	private:
		std::string username;
		std::string password;
		std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD
		int credits;
};