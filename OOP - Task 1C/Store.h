#pragma once

#include "Game.h"

class Store
{
	public:
		Store();
		~Store();
		Game* games[9] = { 0 }; // TODO: should be a dynamic collection
	private:
};