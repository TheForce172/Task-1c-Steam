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

const List<Game*> Store::SearchPrice(int to, int from) const{
	List<Game*> searchList;
	for (int i = 0; i < games.length(); i++)
		if (to > (double)(games[i]->GetCost())/100 && from < (double)(games[i]->GetCost())/100)
			searchList.addAtEnd(games[i]);
	return searchList;


}

const List<Game*> Store::SearchageRating(int to, int from) const {
	List<Game*> searchList;
	for (int i = 0; i < games.length(); i++)
		if (to > games[i]->GetageRating() && from < games[i]->GetCost())
			searchList.addAtEnd(games[i]);
	return searchList;

}





