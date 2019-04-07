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

void Store::showSearchForName() const {


}
void Store::showSearchForageRating() const {

}
void Store::showSearchForCost() const {

}
