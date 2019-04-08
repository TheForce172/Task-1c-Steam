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
		const List<Game*> SearchPrice(std::string&) const;
		void SearchageRating();
	private:
		List<Game*> games; 
};