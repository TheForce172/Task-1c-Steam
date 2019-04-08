#pragma once

#include "Game.h"
#include "Date.h"
#include "Utils.h"
class LibraryItem
{
	public:
		LibraryItem(const Date&, Game*);
		LibraryItem(const Date&, Game*, int);
		~LibraryItem();
		Game *getGame();
		Date getCreated();
		double getTime() const;
		void addTime();
	private:
		Game* game;
		const Date purchased;  // TODO: replace with custom Date class, currently YYYY-MM-DD
		double playTime;
};