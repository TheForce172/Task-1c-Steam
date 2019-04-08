#pragma once
#include "Menu.h"
#include <vector>
#include <algorithm>
#include "RemoveUserMenu.h"
#include "dislikeMenu.h"
#include "likesMenu.h"

class ProfileMenu :
	public Menu
{
public:
	ProfileMenu(const std::string& title, Application * app, User* );
	void OutputOptions() final;
	bool HandleChoice(char choice) final;

private:
	User* account;
	std::vector<LibraryItem*> games;
	bool sortName;
};

