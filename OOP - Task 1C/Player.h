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
		List<Game*> getlikes() const;
		List<Game*> getdislikes() const;
		void addLike(Game *g);
		void adddisLike(Game *g);
		void addToLibrary(LibraryItem*);
	private:
		std::vector<LibraryItem*> library;
		List<Game*> likes;
		List<Game*> dislikes;
};