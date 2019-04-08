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
	private:
		List<Game*> games; 
};