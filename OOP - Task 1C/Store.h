#pragma once

#include "Game.h"
#include "ListT.h"
#include "User.h"

class Store
{
	public:
		Store();
		~Store();
		List<Game*> getGames() const;
		void addGame(Game*);
		void showSearchForName() const;
		void showSearchForageRating() const;
		void showSearchForCost() const;

	private:
		List<Game*> games; 
};