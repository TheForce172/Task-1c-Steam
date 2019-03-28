#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"
#include "Game.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const std::string&, const int&);
		~Player();
		List<LibraryItem*> getLibary() const;
		void addToLibrary(LibraryItem*);
	private:
		List<LibraryItem*> library;
};