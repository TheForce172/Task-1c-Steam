#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& date, Game* game) : purchased(date), game(game)
{
	playTime = 0;
}

LibraryItem::LibraryItem(const Date& date, Game* game, int playTime) : purchased(date), game(game), playTime(playTime)
{
}

LibraryItem::~LibraryItem()
{
}
Game* LibraryItem::getGame() {
	return game;
}

Date LibraryItem::getCreated() {
	return purchased;
}

double LibraryItem::getTime() const{
	return playTime;
}

void LibraryItem::addTime() {
	playTime = playTime + Utils::ramdonNum();
}