#pragma once
#include "Menu.h"
class RemoveUserMenu :
	public Menu
{
public:
	RemoveUserMenu(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
};

