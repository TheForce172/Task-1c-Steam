#pragma once
#include "Menu.h"
class ProfileMenu :
	public Menu
{
public:
	ProfileMenu(const std::string& title, Application * app, User* );
	void OutputOptions() final;
	bool HandleChoice(char choice) final;

private:
	User* account;
	List<Game*> games;

};

