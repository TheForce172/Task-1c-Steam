#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const std::string& created, const int& credits) : User(username, password, created, credits)
{
}

Player::~Player()
{
	for (int i = 0; i < 2; ++i)
	{
		delete library[i];
	}
}

List<LibraryItem*> Player::getLibary() const
{
	return library;
}

void Player::addToLibrary(LibraryItem* l) {
	library.addAtEnd(l);
}