#pragma once

#include "Menu.h"


class likeMenu : public Menu
{
public:

	likeMenu(const std::string & title, Application * app, List<Game*> games);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;

private:
	List<Game*> games;

};
