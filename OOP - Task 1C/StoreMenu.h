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
	void showSearchMenu() const;
	int readInSearchOption() const;
private:
	List<Game*> games;
};