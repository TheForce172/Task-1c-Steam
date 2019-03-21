#pragma once

#include "Menu.h"
#include "StoreMenu.h"
#include "LoginUserMenu.h"
#include "LoginAccountMenu.h"

class MainMenu : public Menu
{
public:
	MainMenu(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
};