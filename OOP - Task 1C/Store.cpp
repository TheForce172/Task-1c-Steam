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

/*void Store::SearchGames() const {
	StoreMenu.showSearchMenu();
	int option = StoreMenu.readInSearchOption();
	switch (option)
	{
	case 0:
		showSearchForName();
		break;
	case 1:
		showSearchForageRating();
		break;
	case 2:
		showSearchForCost();
	case 3:
		return;
	default:
		break;
	}
}*/

void Store::showSearchForName() const {


}
void Store::showSearchForageRating() const {

}
void Store::showSearchForCost() const {

}
