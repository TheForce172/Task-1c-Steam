#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
}

List<Game*> Store::getGames() const
{
	return games;
}

void Store::addGame(Game* g) {
	games.addAtEnd(g);
}

void Store::SearchByName(string) {
	
}

void Store::SearchByRating(int) {

}

void Store::SearchByPrice(int) {

}
