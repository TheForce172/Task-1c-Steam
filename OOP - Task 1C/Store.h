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
		void SearchByName(string);
		void SearchByRating(int);
		void SearchByPrice(int);

	private:
		List<Game*> games; 
};