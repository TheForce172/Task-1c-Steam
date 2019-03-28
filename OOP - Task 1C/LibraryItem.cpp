#include "LibraryItem.h"

LibraryItem::LibraryItem(const std::string& date, Game* game) : purchased(date), game(game)
{
	playTime = 0;
}

LibraryItem::LibraryItem(const std::string& date, Game* game, int playTime) : purchased(date), game(game), playTime(playTime)
{
}

LibraryItem::~LibraryItem()
{
}

const Game* LibraryItem::getGame() {
	return game;
}

std::string LibraryItem::getCreated() {
	return purchased;
}

int LibraryItem::getTime() {
	return playTime;
}