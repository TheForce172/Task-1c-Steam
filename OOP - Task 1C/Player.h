#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const std::string&);
		~Player();
		LibraryItem* library[2] = { 0 }; // TODO: replace with custom List<T> class
	private:
};