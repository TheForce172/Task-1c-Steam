#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created, const int& credits) : User(username, password, created, credits)
{
}

Player::~Player()
{
	for (int i = 0; i < 2; ++i)
	{
		delete library[i];
	}
}

std::vector<LibraryItem*> Player::getLibary() const
{
	return library;
}

List<Game*> Player::getlikes() const
{
	return likes;
}

List<Game*> Player::getdislikes() const
{
	return dislikes;
}

void Player::addToLibrary(LibraryItem* l) {
	//library.addAtEnd(l);
	library.push_back(l);
}