#pragma once

#include "Menu.h"
#include "Store.h"
#include"GameMenu.h"
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "ListT.h"

class StoreMenu : public Menu
{
public:
	StoreMenu(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
	bool isSearching();
private:
	List<Game*> games;
	bool Searching;
};