#pragma once

#include "Game.h"

class LibraryItem
{
	public:
		LibraryItem(const std::string&, Game*);
		LibraryItem(const std::string&, Game*, int);
		~LibraryItem();
		Game *getGame();
		std::string getCreated();
		int getTime();
	private:
		const Game *game;
		const std::string purchased;  // TODO: replace with custom Date class, currently YYYY-MM-DD
		int playTime;
};