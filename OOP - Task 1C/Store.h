#pragma once

#include "Game.h"
#include "ListT.h"

class Store
{
	public:
		Store();
		~Store();
		List<Game*> getGames() const;
		void addGame(Game*);
	private:
		List<Game*> games; // TODO: should be a dynamic collection
};