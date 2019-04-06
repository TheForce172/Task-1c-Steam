#pragma once

#include <string>
#include <vector>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date &, const int&);
		~Player();
		std::vector<LibraryItem*> getLibary() const;
		void addToLibrary(LibraryItem*);
	private:
		std::vector<LibraryItem*> library;
};