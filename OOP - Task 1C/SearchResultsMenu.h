#pragma once
#include "Menu.h"
#include "GameMenu.h"
class SearchResultsMenu :
	public Menu
{
public:
	SearchResultsMenu(const std::string& title, Application * app, List<Game*> games);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;

private:
	List<Game*> games;
};

