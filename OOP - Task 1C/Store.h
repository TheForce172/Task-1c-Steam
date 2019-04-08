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
		const List<Game*> SearchName(std::string&) const;
		const List<Game*> SearchPrice(int to, int from) const;
		const List<Game*> SearchageRating(int to, int from) const;
	private:
		List<Game*> games; 
};