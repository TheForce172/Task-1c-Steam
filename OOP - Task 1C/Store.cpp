#include "Store.h"
#include "StoreMenu.h"

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

const List<Game*> Store::SearchName(std::string& s) const{
	List<Game*> searchList;

	for (int i = 0; i < games.length(); i++)
		if (Utils::StartsWith(games[i]->GetName(), s))
			searchList.addAtEnd(games[i]);
	return searchList;

}

const List<Game*> Store::SearchPrice(std::string& s) const{
	List<Game*> searchList;

	for (int i = 0; i < games.length(); i++)
		if (Utils::StartsWith(games[i]->GetCost(), s))
			searchList.addAtEnd(games[i]);
	return searchList;

}

const List<Game*> Store::SearchageRating(std::string& s) {
	List<Game*> searchList;

	for (int i = 0; i < games.length(); i++)
		if (Utils::StartsWith(games[i]->GetageRating(), s))
			searchList.addAtEnd(games[i]);
	return searchList;

}





